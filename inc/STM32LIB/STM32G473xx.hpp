#ifndef STM32G473XX_HPP_
#define STM32G473XX_HPP_
#pragma once

#include <cstdint>

namespace STM32LIB {

const uint32_t TIM2_Base_Address = 0x40000000;
const uint32_t TIM3_Base_Address = 0x40000400;
const uint32_t TIM4_Base_Address = 0x40000800;
const uint32_t TIM5_Base_Address = 0x40000C00;
const uint32_t TIM6_Base_Address = 0x40001000;
const uint32_t TIM7_Base_Address = 0x40001400;
const uint32_t CRS_Base_Address = 0x40002000;
const uint32_t TAMP_Base_Address = 0x40002400;
const uint32_t RTC_Base_Address = 0x40002800;
const uint32_t WWDG_Base_Address = 0x40002C00;
const uint32_t IWDG_Base_Address = 0x40003000;
const uint32_t SPI2_Base_Address = 0x40003800;
const uint32_t SPI3_Base_Address = 0x40003C00;
const uint32_t USART2_Base_Address = 0x40004400;
const uint32_t USART3_Base_Address = 0x40004800;
const uint32_t UART4_Base_Address = 0x40004C00;
const uint32_t UART5_Base_Address = 0x40005000;
const uint32_t I2C1_Base_Address = 0x40005400;
const uint32_t I2C2_Base_Address = 0x40005800;
const uint32_t USB_FS_device_Base_Address = 0x40005C00;
const uint32_t FDCAN1_Base_Address = 0x40006400;
const uint32_t FDCAN2_Base_Address = 0x40006800;
const uint32_t FDCAN3_Base_Address = 0x40006C00;
const uint32_t PWR_Base_Address = 0x40007000;
const uint32_t I2C3_Base_Address = 0x40007800;
const uint32_t LPTIMER1_Base_Address = 0x40007C00;
const uint32_t LPUART1_Base_Address = 0x40008000;
const uint32_t I2C4_Base_Address = 0x40008400;
const uint32_t UCPD1_Base_Address = 0x4000A000;
const uint32_t FDCANs_Message_RAM_Base_Address = 0x4000A400;
const uint32_t SYSCFG_Base_Address = 0x40010000;
const uint32_t VREFBUF_Base_Address = 0x40010030;
const uint32_t COMP_Base_Address = 0x40010200;
const uint32_t OPAMP_Base_Address = 0x40010300;
const uint32_t EXTI_Base_Address = 0x40010400;
const uint32_t TIM1_Base_Address = 0x40012C00;
const uint32_t SPI1_Base_Address = 0x40013000;
const uint32_t TIM8_Base_Address = 0x40013400;
const uint32_t USART1_Base_Address = 0x40013800;
const uint32_t SPI4_Base_Address = 0x40013C00;
const uint32_t TIM15_Base_Address = 0x40014000;
const uint32_t TIM16_Base_Address = 0x40014400;
const uint32_t TIM17_Base_Address = 0x40014800;
const uint32_t TIM20_Base_Address = 0x40015000;
const uint32_t SAI_Base_Address = 0x40015400;
const uint32_t DMA1_Base_Address = 0x40020000;
const uint32_t DMA2_Base_Address = 0x40020400;
const uint32_t DMAMUX_Base_Address = 0x40020800;
const uint32_t CORDIC_Base_Address = 0x40020C00;
const uint32_t RCC_Base_Address = 0x40021000;
const uint32_t FMAC_Base_Address = 0x40021400;
const uint32_t FLASH_Base_Address = 0x40022000;
const uint32_t CRC_Base_Address = 0x40023000;
const uint32_t GPIOA_Base_Address = 0x48000000;
const uint32_t GPIOB_Base_Address = 0x48000400;
const uint32_t GPIOC_Base_Address = 0x48000800;
const uint32_t GPIOD_Base_Address = 0x48000C00;
const uint32_t GPIOE_Base_Address = 0x48001000;
const uint32_t GPIOF_Base_Address = 0x48001400;
const uint32_t GPIOG_Base_Address = 0x48001800;
const uint32_t ADC1_Base_Address = 0x50000000;
const uint32_t ADC2_Base_Address = 0x50000100;
const uint32_t ADC12_Common_Base_Address = 0x50000300;
const uint32_t ADC3_Base_Address = 0x50000400;
const uint32_t ADC4_Base_Address = 0x50000500;
const uint32_t ADC5_Base_Address = 0x50000600;
const uint32_t ADC345_Common_Base_Address = 0x50000700;
const uint32_t DAC1_Base_Address = 0x50000800;
const uint32_t DAC2_Base_Address = 0x50000C00;
const uint32_t DAC3_Base_Address = 0x50001000;
const uint32_t DAC4_Base_Address = 0x50001400;
const uint32_t AES_Base_Address = 0x50060000;
const uint32_t RNG_Base_Address = 0x50060800;
const uint32_t FMC_Base_Address = 0xA0000000;
const uint32_t QUADSPI_Base_Address = 0xA0001000;
const uint32_t SCB_ACTLR_Base_Address = 0xE000E008;
const uint32_t STK_Base_Address = 0xE000E010;
const uint32_t MPU_Base_Address = 0xE000E084;
const uint32_t NVIC_Base_Address = 0xE000E100;
const uint32_t SCB_Base_Address = 0xE000ED00;
const uint32_t FPU_CPACR_Base_Address = 0xE000ED88;
const uint32_t NVIC_STIR_Base_Address = 0xE000EF00;
const uint32_t FPU_Base_Address = 0xE000EF34;
const uint32_t DBGMCU_Base_Address = 0xE0042000;

// Interrupt IRQn's
/******  Cortex-M4 Processor Exceptions Numbers *********************************************************************************/
const uint32_t NonMaskableInt_IRQ_Num         = -14;    /*!< 2 Cortex-M4 Non Maskable Interrupt                                                 */
const uint32_t HardFault_IRQ_Num              = -13;    /*!< 3 Cortex-M4 Hard Fault Interrupt                                                   */
const uint32_t MemoryManagement_IRQ_Num       = -12;    /*!< 4 Cortex-M4 Memory Management Interrupt                                            */
const uint32_t BusFault_IRQ_Num               = -11;    /*!< 5 Cortex-M4 Bus Fault Interrupt                                                    */
const uint32_t UsageFault_IRQ_Num             = -10;    /*!< 6 Cortex-M4 Usage Fault Interrupt                                                  */
const uint32_t SVCall_IRQ_Num                 = -5;     /*!< 11 Cortex-M4 SV Call Interrupt                                                     */
const uint32_t DebugMonitor_IRQ_Num           = -4;     /*!< 12 Cortex-M4 Debug Monitor Interrupt                                               */
const uint32_t PendSV_IRQ_Num                 = -2;     /*!< 14 Cortex-M4 Pend SV Interrupt                                                     */
const uint32_t SysTick_IRQ_Num                = -1;     /*!< 15 Cortex-M4 System Tick Interrupt                                                 */
/******  STM32 specific Interrupt Numbers ***************************************************************************************/
const uint32_t WWDG_IRQ_Num                   = 0;      /*!< Window WatchDog Interrupt                                                          */
const uint32_t PVD_PVM_IRQ_Num                = 1;      /*!< PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection Interrupts                     */
const uint32_t RTC_TAMP_LSECSS_IRQ_Num        = 2;      /*!< RTC Tamper and TimeStamp and RCC LSE CSS interrupts through the EXTI               */
const uint32_t RTC_WKUP_IRQ_Num               = 3;      /*!< RTC Wakeup interrupt through the EXTI line                                         */
const uint32_t FLASH_IRQ_Num                  = 4;      /*!< FLASH global Interrupt                                                             */
const uint32_t RCC_IRQ_Num                    = 5;      /*!< RCC global Interrupt                                                               */
const uint32_t EXTI0_IRQ_Num                  = 6;      /*!< EXTI Line0 Interrupt                                                               */
const uint32_t EXTI1_IRQ_Num                  = 7;      /*!< EXTI Line1 Interrupt                                                               */
const uint32_t EXTI2_IRQ_Num                  = 8;      /*!< EXTI Line2 Interrupt                                                               */
const uint32_t EXTI3_IRQ_Num                  = 9;      /*!< EXTI Line3 Interrupt                                                               */
const uint32_t EXTI4_IRQ_Num                  = 10;     /*!< EXTI Line4 Interrupt                                                               */
const uint32_t DMA1_Channel1_IRQ_Num          = 11;     /*!< DMA1 Channel 1 global Interrupt                                                    */
const uint32_t DMA1_Channel2_IRQ_Num          = 12;     /*!< DMA1 Channel 2 global Interrupt                                                    */
const uint32_t DMA1_Channel3_IRQ_Num          = 13;     /*!< DMA1 Channel 3 global Interrupt                                                    */
const uint32_t DMA1_Channel4_IRQ_Num          = 14;     /*!< DMA1 Channel 4 global Interrupt                                                    */
const uint32_t DMA1_Channel5_IRQ_Num          = 15;     /*!< DMA1 Channel 5 global Interrupt                                                    */
const uint32_t DMA1_Channel6_IRQ_Num          = 16;     /*!< DMA1 Channel 6 global Interrupt                                                    */
const uint32_t DMA1_Channel7_IRQ_Num          = 17;     /*!< DMA1 Channel 7 global Interrupt                                                    */
const uint32_t ADC1_2_IRQ_Num                 = 18;     /*!< ADC1 and ADC2 global Interrupt                                                     */
const uint32_t USB_HP_IRQ_Num                 = 19;     /*!< USB HP Interrupt                                                                   */
const uint32_t USB_LP_IRQ_Num                 = 20;     /*!< USB LP  Interrupt                                                                  */
const uint32_t FDCAN1_IT0_IRQ_Num             = 21;     /*!< FDCAN1 IT0 Interrupt                                                               */
const uint32_t FDCAN1_IT1_IRQ_Num             = 22;     /*!< FDCAN1 IT1 Interrupt                                                               */
const uint32_t EXTI9_5_IRQ_Num                = 23;     /*!< External Line[9:5] Interrupts                                                      */
const uint32_t TIM1_BRK_TIM15_IRQ_Num         = 24;     /*!< TIM1 Break; Transition error; Index error and TIM15 global interrupt               */
const uint32_t TIM1_UP_TIM16_IRQ_Num          = 25;     /*!< TIM1 Update Interrupt and TIM16 global interrupt                                   */
const uint32_t TIM1_TRG_COM_TIM17_IRQ_Num     = 26;     /*!< TIM1 TIM1 Trigger; Commutation; Direction change; Index and TIM17 global interrupt */
const uint32_t TIM1_CC_IRQ_Num                = 27;     /*!< TIM1 Capture Compare Interrupt                                                     */
const uint32_t TIM2_IRQ_Num                   = 28;     /*!< TIM2 global Interrupt                                                              */
const uint32_t TIM3_IRQ_Num                   = 29;     /*!< TIM3 global Interrupt                                                              */
const uint32_t TIM4_IRQ_Num                   = 30;     /*!< TIM4 global Interrupt                                                              */
const uint32_t I2C1_EV_IRQ_Num                = 31;     /*!< I2C1 Event Interrupt                                                               */
const uint32_t I2C1_ER_IRQ_Num                = 32;     /*!< I2C1 Error Interrupt                                                               */
const uint32_t I2C2_EV_IRQ_Num                = 33;     /*!< I2C2 Event Interrupt                                                               */
const uint32_t I2C2_ER_IRQ_Num                = 34;     /*!< I2C2 Error Interrupt                                                               */
const uint32_t SPI1_IRQ_Num                   = 35;     /*!< SPI1 global Interrupt                                                              */
const uint32_t SPI2_IRQ_Num                   = 36;     /*!< SPI2 global Interrupt                                                              */
const uint32_t USART1_IRQ_Num                 = 37;     /*!< USART1 global Interrupt                                                            */
const uint32_t USART2_IRQ_Num                 = 38;     /*!< USART2 global Interrupt                                                            */
const uint32_t USART3_IRQ_Num                 = 39;     /*!< USART3 global Interrupt                                                            */
const uint32_t EXTI15_10_IRQ_Num              = 40;     /*!< External Line[15:10] Interrupts                                                    */
const uint32_t RTC_Alarm_IRQ_Num              = 41;     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                                    */
const uint32_t USBWakeUp_IRQ_Num              = 42;     /*!< USB Wakeup through EXTI line Interrupt                                             */
const uint32_t TIM8_BRK_IRQ_Num               = 43;     /*!< TIM8 Break; Transition error and Index error Interrupt                             */
const uint32_t TIM8_UP_IRQ_Num                = 44;     /*!< TIM8 Update Interrupt                                                              */
const uint32_t TIM8_TRG_COM_IRQ_Num           = 45;     /*!< TIM8 Trigger; Commutation; Direction change and Index Interrupt                    */
const uint32_t TIM8_CC_IRQ_Num                = 46;     /*!< TIM8 Capture Compare Interrupt                                                     */
const uint32_t ADC3_IRQ_Num                   = 47;     /*!< ADC3 global  Interrupt                                                             */
const uint32_t FMC_IRQ_Num                    = 48;     /*!< FMC global Interrupt                                                               */
const uint32_t LPTIM1_IRQ_Num                 = 49;     /*!< LP TIM1 Interrupt                                                                  */
const uint32_t TIM5_IRQ_Num                   = 50;     /*!< TIM5 global Interrupt                                                              */
const uint32_t SPI3_IRQ_Num                   = 51;     /*!< SPI3 global Interrupt                                                              */
const uint32_t UART4_IRQ_Num                  = 52;     /*!< UART4 global Interrupt                                                             */
const uint32_t UART5_IRQ_Num                  = 53;     /*!< UART5 global Interrupt                                                             */
const uint32_t TIM6_DAC_IRQ_Num               = 54;     /*!< TIM6 global and DAC1&3 underrun error  interrupts                                  */
const uint32_t TIM7_DAC_IRQ_Num               = 55;     /*!< TIM7 global and DAC2&4 underrun error  interrupts                                  */
const uint32_t DMA2_Channel1_IRQ_Num          = 56;     /*!< DMA2 Channel 1 global Interrupt                                                    */
const uint32_t DMA2_Channel2_IRQ_Num          = 57;     /*!< DMA2 Channel 2 global Interrupt                                                    */
const uint32_t DMA2_Channel3_IRQ_Num          = 58;     /*!< DMA2 Channel 3 global Interrupt                                                    */
const uint32_t DMA2_Channel4_IRQ_Num          = 59;     /*!< DMA2 Channel 4 global Interrupt                                                    */
const uint32_t DMA2_Channel5_IRQ_Num          = 60;     /*!< DMA2 Channel 5 global Interrupt                                                    */
const uint32_t ADC4_IRQ_Num                   = 61;     /*!< ADC4 global Interrupt                                                              */
const uint32_t ADC5_IRQ_Num                   = 62;     /*!< ADC5 global Interrupt                                                              */
const uint32_t UCPD1_IRQ_Num                  = 63;     /*!< UCPD global Interrupt                                                              */
const uint32_t COMP1_2_3_IRQ_Num              = 64;     /*!< COMP1; COMP2 and COMP3 Interrupts                                                  */
const uint32_t COMP4_5_6_IRQ_Num              = 65;     /*!< COMP4; COMP5 and COMP6                                                             */
const uint32_t COMP7_IRQ_Num                  = 66;     /*!< COMP7 Interrupt                                                                    */
const uint32_t CRS_IRQ_Num                    = 75;     /*!< CRS global interrupt                                                               */
const uint32_t SAI1_IRQ_Num                   = 76;     /*!< Serial Audio Interface global interrupt                                            */
const uint32_t TIM20_BRK_IRQ_Num              = 77;     /*!< TIM20 Break; Transition error and Index error Interrupt                            */
const uint32_t TIM20_UP_IRQ_Num               = 78;     /*!< TIM20 Update interrupt                                                             */
const uint32_t TIM20_TRG_COM_IRQ_Num          = 79;     /*!< TIM20 Trigger; Commutation; Direction change and Index Interrupt                   */
const uint32_t TIM20_CC_IRQ_Num               = 80;     /*!< TIM20 Capture Compare interrupt                                                    */
const uint32_t FPU_IRQ_Num                    = 81;     /*!< FPU global interrupt                                                               */
const uint32_t I2C4_EV_IRQ_Num                = 82;     /*!< I2C4 Event interrupt                                                               */
const uint32_t I2C4_ER_IRQ_Num                = 83;     /*!< I2C4 Error interrupt                                                               */
const uint32_t SPI4_IRQ_Num                   = 84;     /*!< SPI4 Event interrupt                                                               */
const uint32_t FDCAN2_IT0_IRQ_Num             = 86;     /*!< FDCAN2 interrupt line 0 interrupt                                                  */
const uint32_t FDCAN2_IT1_IRQ_Num             = 87;     /*!< FDCAN2 interrupt line 1 interrupt                                                  */
const uint32_t FDCAN3_IT0_IRQ_Num             = 88;     /*!< FDCAN3 interrupt line 0 interrupt                                                  */
const uint32_t FDCAN3_IT1_IRQ_Num             = 89;     /*!< FDCAN3 interrupt line 1 interrupt                                                  */
const uint32_t RNG_IRQ_Num                    = 90;     /*!< RNG global interrupt                                                               */
const uint32_t LPUART1_IRQ_Num                = 91;     /*!< LP UART 1 Interrupt                                                                */
const uint32_t I2C3_EV_IRQ_Num                = 92;     /*!< I2C3 Event Interrupt                                                               */
const uint32_t I2C3_ER_IRQ_Num                = 93;     /*!< I2C3 Error interrupt                                                               */
const uint32_t DMAMUX_OVR_IRQ_Num             = 94;     /*!< DMAMUX overrun global interrupt                                                    */
const uint32_t QUADSPI_IRQ_Num                = 95;     /*!< QUADSPI interrupt                                                                  */
const uint32_t DMA1_Channel8_IRQ_Num          = 96;     /*!< DMA1 Channel 8 interrupt                                                           */
const uint32_t DMA2_Channel6_IRQ_Num          = 97;     /*!< DMA2 Channel 6 interrupt                                                           */
const uint32_t DMA2_Channel7_IRQ_Num          = 98;     /*!< DMA2 Channel 7 interrupt                                                           */
const uint32_t DMA2_Channel8_IRQ_Num          = 99;     /*!< DMA2 Channel 8 interrupt                                                           */
const uint32_t CORDIC_IRQ_Num                 = 100;    /*!< CORDIC global Interrupt                                                            */
const uint32_t FMAC_IRQ_Num                   = 101;    /*!< FMAC global Interrupt                                                              */


} // namespace STM32LIB

#include "STM32G473xx_RCC.hpp"
#include "STM32G473xx_TIM.hpp"
#include "STM32G473xx_GPIO.hpp"
#include "STM32G473xx_NVIC.hpp"
#include "STM32G473xx_DAC.hpp"
#include "STM32G473xx_CORDIC.hpp"
#include "STM32G473xx_SPI.hpp"
#include "STM32G473xx_ADC.hpp"
#include "STM32G473xx_ADC_Common.hpp"
#include "STM32G473xx_DMA.hpp"
#include "STM32G473xx_DMAMUX.hpp"


#endif // STM32G473XX_HPP_

