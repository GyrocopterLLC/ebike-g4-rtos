#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "stm32g4xx.h"
#include "stm32g4xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "tusb_config.h"
#include "tusb.h"

#include "board.h"

#include "mc.h"


#if !defined  (HSE_VALUE)
  #define HSE_VALUE     8000000U /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    16000000U /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

#define __SYSTEM_CLOCK	(168000000ul)
uint32_t SystemCoreClock = HSI_VALUE;

/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x00UL /*!< Vector Table base offset field.
                                   This value must be a multiple of 0x200. */
/******************************************************************************/

void SystemInit(void)
{
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << (10*2))|(3UL << (11*2)));  /* set CP10 and CP11 Full Access */
  #endif

  /* Configure the Vector Table location add offset address ------------------*/
#ifdef VECT_TAB_SRAM
  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif
}

const uint8_t AHBPrescTable[16] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
const uint8_t APBPrescTable[8] =  {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};

static void MAIN_InitializeClocks(void);
void SystemCoreClockUpdate(void);

static void MAIN_InitializeClocks(void) {
    uint32_t tempreg;

    RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN; // Enable access to power control
    PWR->CR3 |= PWR_CR3_UCPD_DBDIS; // Disable USB-PD dead battery pull-downs
    // If already in range 1, don't change it
    if((PWR->CR1 & PWR_CR1_VOS) != PWR_CR1_VOS_0) { // if VOS != b01, not in Range 1
        tempreg = PWR->CR1;
        tempreg &= ~(PWR_CR1_VOS);
        tempreg |= PWR_CR1_VOS_0;
        PWR->CR1 = tempreg;
        // Make sure it takes effect by waiting for checking VOSF
        while((PWR->SR2 & PWR_SR2_VOSF) != 0) { } // wait for the bit
    }
    // Change Flash latency to the required amount
    RCC->AHB1ENR |= RCC_AHB1ENR_FLASHEN;
    // Instruction and data caches enabled, prefetch enabled, 8 wait states
    FLASH->ACR &= ~(FLASH_ACR_LATENCY);
    FLASH->ACR |= FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_8WS;
    // Make sure it has taken effect by re-reading the register
    while((FLASH->ACR & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_8WS) { } // wait for latency to take effect

    // Check if we need to change the boost mode.
    // When switching to boost mode, the AHB prescaler must be divide by 2.
    // After 1us, it can be reconfigured to the needed prescaler.
    if((PWR->CR5 & PWR_CR5_R1MODE) != 0) { // zero is enabled, one is disabled. go figure.
        // Set the AHB prescaler to divide by 2
        tempreg = RCC->CFGR;
        tempreg &= ~(RCC_CFGR_HPRE);
        tempreg |= RCC_CFGR_HPRE_3; // HPRE = b1000, sysclock divided by 2
        RCC->CFGR = tempreg;

        // Clear R1MODE to enable the Range 1 boost voltage
        PWR->CR5 &= ~(PWR_CR5_R1MODE);
    }

    // Configure the PLL to 170MHz
    RCC->CR &= ~(RCC_CR_PLLON); // turn off PLL first
    while((RCC->CR & RCC_CR_PLLRDY) != 0) { }// wait for PLLRDY to clear
    RCC->PLLCFGR =  RCC_PLLCFGR_PLLSRC_1 | // HSI16 is the PLL source
                    (3u << RCC_PLLCFGR_PLLM_Pos) | // M divider is /4
                    (85u << RCC_PLLCFGR_PLLN_Pos) | // N multiplier is x85
                    RCC_PLLCFGR_PLLREN | // PLLR output enabled
                    RCC_PLLCFGR_PLLPEN | // PLLP output enabled
                    (8u << RCC_PLLCFGR_PLLPDIV_Pos); // PLLP divider is /8
    // Not shown: PLLR divider is /2, PLLQ divider is /2 (but PLLQ output is off)
    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while((RCC->CR & RCC_CR_PLLRDY) == 0) { }// wait for PLLRDY to set
    // Switch clock sources
    RCC->CFGR |= (RCC_CFGR_SW); // Set SW[1:0] to b11 to use PLL as system clock
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS) { } // wait for the switch to take effect

    // Set prescalers. HCLK, APB1, and APB2 are all divide by 1 (170MHz in, 170MHz out)
    RCC->CFGR &= ~(RCC_CFGR_PPRE2 | RCC_CFGR_PPRE1 | RCC_CFGR_HPRE);

    // Enable HSI48 for the USB
    RCC->CRRCR |= RCC_CRRCR_HSI48ON;

    // Set output clocks to the peripherals that have a selection available
    RCC->CCIPR = RCC_CCIPR_ADC12SEL_0 | RCC_CCIPR_ADC345SEL_0; // ADC12 and ADC345 sourced from PLL"P" clock

    SystemCoreClockUpdate(); // Sets some internal variables to the actual clock settings.
}

void SystemCoreClockUpdate(void)
{
  uint32_t tmp, pllvco, pllr, pllsource, pllm;

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (RCC->CFGR & RCC_CFGR_SWS)
  {
    case 0x04:  /* HSI used as system clock source */
      SystemCoreClock = HSI_VALUE;
      break;

    case 0x08:  /* HSE used as system clock source */
      SystemCoreClock = HSE_VALUE;
      break;

    case 0x0C:  /* PLL used as system clock  source */
      /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLLM) * PLLN
         SYSCLK = PLL_VCO / PLLR
         */
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
      pllm = ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> 4) + 1U ;
      if (pllsource == 0x02UL) /* HSI used as PLL clock source */
      {
        pllvco = (HSI_VALUE / pllm);
      }
      else                   /* HSE used as PLL clock source */
      {
        pllvco = (HSE_VALUE / pllm);
      }
      pllvco = pllvco * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 8);
      pllr = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLR) >> 25) + 1U) * 2U;
      SystemCoreClock = pllvco/pllr;
      break;

    default:
      break;
  }
  /* Compute HCLK clock frequency --------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
  /* HCLK clock frequency */
  SystemCoreClock >>= tmp;
}



static void tusb_task(void* pvParameters) {
	(void)(pvParameters);

	//__HAL_RCC_USB_CLK_ENABLE();
	tud_init(BOARD_TUD_RHPORT);

	for(;;) {
		tud_task();

		vTaskDelay(1);
	}
}

char buf[64];

static void loopback_task(void* pvParameters) {
	// Simple read and loop back the read data

	for(;;) {
		while ( tud_cdc_available()) {
			// read and echo back
			uint32_t count = tud_cdc_read(buf, sizeof(buf));

			if(buf[0] == 'D') { // start debug info
				start_debug_usb_info();
			}
			if(buf[0] == 'd') { // stop debug info
				stop_debug_usb_info();
			}

			// Echo back
			// Note: Skip echo by commenting out write() and write_flush()
			// for throughput test e.g
			//    $ dd if=/dev/zero of=/dev/ttyACM0 count=10000
			//tud_cdc_write(buf, count);

//			tud_cdc_write(" yay\r\n", 6);
			// append whatever the fault status current is
			sprintf(&(buf[count]), " %04lX\r\n",get_fault_status());
			tud_cdc_write(buf, strlen(buf));

		}

		tud_cdc_write_flush();
	}

	vTaskDelay(1);
}

int main(void)
{
	// Initialize hardware, clocks, all that jazz
	MAIN_InitializeClocks();
	board_init();

	xTaskCreate( tusb_task, "TinyUSB Task", configMINIMAL_STACK_SIZE*4, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( loopback_task, "Loopback Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( DAC_Task, "DAC Task", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
	xTaskCreate( Drv_Fault_Task, "DRV Fault Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	mc_startup_pre_rtos();

	vTaskStartScheduler();
	for(;;);
}

void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

/**
 * \brief This function is called by FreeRTOS each tick
 */
void vApplicationTickHook(void)
{
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	for( ;; );
}
