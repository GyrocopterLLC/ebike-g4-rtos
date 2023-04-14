#include <type_traits>

#include "Timer.hpp"
#include "Gpio.hpp"
#include "Pwm.hpp"
#include "STM32G473xx.hpp"
#include "EbikeConfig.hpp"
#include "mc_startup.h"
#include "FOC_Lib.hpp"
#include "RampControl.hpp"
#include "Rampgen.hpp"
#include "NvicHelpers.hpp"
#include "CORDIC_Trig.hpp"
#include "DRV8353.hpp"

#include "FreeRTOS.h"
#include "task.h"

#include "adc.hpp"

TaskHandle_t Dac_Task_Handle = NULL;
TaskHandle_t Drv_Fault_Task_Handle = NULL;
EbikeLib::DRV8353* drv_handle = nullptr;
uint8_t drv_static_placement_buf[sizeof(EbikeLib::DRV8353)];
EbikeLib::Pwm<EbikeLib::Timer_Periph::Timer1>* pwm_handle = nullptr;
uint8_t pwm_static_placement_buf[sizeof(EbikeLib::Pwm<EbikeLib::Timer_Periph::Timer1>)];


uint32_t fault_status;

enum class DacChoice {
	RampControl = 0,
	RampAngle = 1,
	Sine = 2,
	Cosine = 3,
	Ipark_Alpha = 4,
	Ipark_Beta = 5,
	SVM_TA = 6,
	SVM_TB = 7,
	SVM_TC = 8

};

volatile DacChoice dac1sel = DacChoice::RampAngle, dac2sel = DacChoice::SVM_TA;

bool dac_task_is_running = false;

#if 0
__attribute__((noinline))
uint32_t cordic_get() {
	auto cordic = STM32LIB::CORDIC<STM32LIB::CORDIC_Base_Address>();

	return cordic.RDATA.get();
}

__attribute__((noinline))
void cordic_get2(uint32_t* arg1, uint32_t* arg2) {

	*arg1 = cordic_get();
	*arg2 = cordic_get();
}

void cordic_set(uint32_t newval) {
	auto cordic = STM32LIB::CORDIC<STM32LIB::CORDIC_Base_Address>();

	cordic.WDATA.set(newval);
}

#endif

int32_t float_to_q31(float input) {
    int32_t retval;
    retval = static_cast<int32_t>(input*2147483648.0f); // 2^31
    /**
    asm(	"VCVT.S32.F32 s0, %1, #31\n\t"
    		"VMOV %0, s0"
            :"=r" (retval)
            :"t" (input)
            :"s0");
    **/
    return retval;
}

float q31_to_float(int32_t input) {
    float retval;
    //retval = static_cast<float>(input)/2147483648.0f; // 2^31

    asm(    "VMOV %0, %1\n\t"
            "VCVT.F32.S32 %0, %0, #31"
            :"=t"(retval)
            :"r"(input)
            :);

    return retval;
}

extern "C" {

// This is everything that can happen before the RTOS scheduler is launched
// Anything that calls FreeRTOS functions cannot be used here
void mc_startup_pre_rtos() {

	// Enable all of the GPIO ports
	EbikeLib::RCC_Funcs::start_gpio_clock<EbikeLib::Gpio_Port::GPIO_A>();
	EbikeLib::RCC_Funcs::start_gpio_clock<EbikeLib::Gpio_Port::GPIO_B>();
	EbikeLib::RCC_Funcs::start_gpio_clock<EbikeLib::Gpio_Port::GPIO_C>();
	EbikeLib::RCC_Funcs::start_gpio_clock<EbikeLib::Gpio_Port::GPIO_F>();
	EbikeLib::RCC_Funcs::start_gpio_clock<EbikeLib::Gpio_Port::GPIO_G>();

#if 0
	auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
	// Enable the timer
	rcc.APB2ENR.TIM1EN.set(true);


	// Configure PWM mode
	auto rtim = EbikeLib::get_timer<EbikeLib::Timer_Periph::Timer1>();

	rtim.CR1.apply<	STM32LIB::TIM_CR1::CEN<false>,
					STM32LIB::TIM_CR1::UDIS<false>,
					STM32LIB::TIM_CR1::OPM<false>,
					STM32LIB::TIM_CR1::CMS<STM32LIB::CR1_Alignment_Mode::Center_Mode_1>>();

	rtim.CR1.CMS.set(STM32LIB::CR1_Alignment_Mode::Center_Mode_1);
	rtim.CCMR1_Output.OC1M.set(STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1);
	rtim.CCMR1_Output.OC2M.set(STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1);
	rtim.CCMR2_Output.OC3M.set(STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1);

	rtim.DIER.apply<	STM32LIB::TIM_DIER::UIE<true>>();

	enable_interrupt<STM32LIB::TIM1_UP_TIM16_IRQ_Num>();
	set_interrupt_priority<STM32LIB::TIM1_UP_TIM16_IRQ_Num>(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);

	// Start the timer
	rtim.CR1.CEN.set(true);
#endif

	// Let's do a little GPIO setup for the LEDs blinkenlights
	auto gport_c = STM32LIB::GPIO<STM32LIB::GPIOC_Base_Address>();

	gport_c.MODER.apply<STM32LIB::GPIO_MODER::MODER14<STM32LIB::GPIO_Mode::Output>,
						STM32LIB::GPIO_MODER::MODER14<STM32LIB::GPIO_Mode::Output>>();

	gport_c.MODER.MODER14.set(STM32LIB::GPIO_Mode::Output);
	gport_c.MODER.MODER15.set(STM32LIB::GPIO_Mode::Output);


	pwm_handle = new(pwm_static_placement_buf) EbikeLib::Pwm<EbikeLib::Timer_Periph::Timer1>();
	// Initialize GPIO for this PWM timer
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_C_Pin, EbikeLib::Pwm_C_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_B_Pin, EbikeLib::Pwm_B_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_A_Pin, EbikeLib::Pwm_A_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_Cn_Pin, EbikeLib::Pwm_Cn_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_Bn_Pin, EbikeLib::Pwm_Bn_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_An_Pin, EbikeLib::Pwm_An_Af_Num>();
	// Need a weak pullup on the fault pin
	EbikeLib::pwm_gpio_config_pullup<EbikeLib::PWM_OC_Pin, EbikeLib::Pwm_OC_Af_Num>();



}

void mc_startup_post_rtos() {
	adc_init(); // Can't do this outside of a RTOS task!! Uses vTaskDelay
	drv_handle = new(drv_static_placement_buf) EbikeLib::DRV8353(); // same here

	// now that the drv8353 is enabled, let's turn on the PWM interrupts
	// be sure to clear the break flag if it was set
	// if there's a break input active, the flag will come right back and that's okay
	pwm_handle->clear_break();
	pwm_handle->enable_break_irq();
	pwm_handle->enable_update_irq();
	// and the motor outputs
	pwm_handle->motor_on_off(true);
}

const float VdTesting = 0.0f;            // Vd testing (pu)
const float VqTesting = 0.25f;         // Vq testing (pu)

void Drv_Fault_Task(void* pvParameters) {
	(void)(pvParameters);
	Drv_Fault_Task_Handle = xTaskGetCurrentTaskHandle();

	while(true) {
		// just waits until it is woken by a fault flag
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		// What was the fault?
		fault_status = drv_handle->get_fault_status();

	}

}

uint32_t get_fault_status() {
	return fault_status;
}

void DAC_Task(void* pvParameters) {
	(void)(pvParameters); // unused

	Dac_Task_Handle = xTaskGetCurrentTaskHandle();

	// Initialize the DAC
	// Configure GPIO
	auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
	if(!rcc.AHB2ENR.GPIOAEN.get())
		rcc.AHB2ENR.GPIOAEN.set(true);
	EbikeLib::gpio_mode<EbikeLib::DAC1_Pin.Port, EbikeLib::DAC1_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	EbikeLib::gpio_mode<EbikeLib::DAC2_Pin.Port, EbikeLib::DAC2_Pin.Num, STM32LIB::GPIO_Mode::Analog>();

	// Start clock to DAC
	rcc.AHB2ENR.DAC1EN.set(true);

	auto dac = STM32LIB::DAC<STM32LIB::DAC1_Base_Address>();
	// Enable both channels
	dac.CR.apply<
		STM32LIB::DAC_CR::EN1<true>,
		STM32LIB::DAC_CR::EN2<true>
	>();
	dac.MCR.HFSEL.set(STM32LIB::DAC_High_Frequency_Mode::Enabled_Over_160MHz);

	// Enable the CORDIC
	auto cordic = EbikeLib::Cordic();
	uint32_t cordic_sine, cordic_cosine;
	uint16_t DAC1val=0, DAC2val=0;
	//float angle = 0.5f;
	int32_t angle_int = 0x80000000u;
	float sinef, cosinef;

	auto svm = EbikeLib::SVM();
	auto ipark = EbikeLib::Inverse_Park();

	// Sampling is now 20kHz
	// So rampcont target of 1Hz is value of 0.00005 (1/20000)
	// Ramp rate of 10 second: Ramp Control Rate = 1/(10*20000) = 0.000005
	auto rampcont = EbikeLib::RampControl(0.00005f, 0.000005f);
	auto rampgen = EbikeLib::Rampgen();

	mc_startup_post_rtos();

	// Now we're ready!
	dac_task_is_running = true;

	while(true) {
		//vTaskDelay(10); // Now triggered by Timer IRQ
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		rampcont.calc();
		rampgen.set_freq(rampcont.get_output());
		rampgen.calc();
		angle_int = float_to_q31(rampgen.get_output());

		//angle_int = static_cast<int32_t>(rampgen.get_output() * 2147483648.0f);

		cordic.set(angle_int);
		cordic.sine_cosine(&cordic_sine, &cordic_cosine);

		sinef = 2.0f*q31_to_float(cordic_sine);
		//sinef = 2.0f*static_cast<float>(cordic_sine)/2147483648.0f;

		cosinef = 2.0f*q31_to_float(cordic_cosine);
		//cosinef = 2.0f*static_cast<float>(cordic_cosine)/2147483648.0f;

		ipark.calc(VdTesting,  VqTesting,  sinef,  cosinef);

		svm.calc(ipark.Alpha, ipark.Beta);
		pwm_handle->set_duty(svm.tA, svm.tB,  svm.tC);


		//	DAC1val = static_cast<uint16_t>(rampgen.get_output()*4094.5f);
		switch(dac1sel) {
		case DacChoice::RampControl:
			DAC1val = static_cast<uint16_t>(float_to_q31(rampcont.get_output()) >> (16));
			break;
		case DacChoice::RampAngle:
			DAC1val = static_cast<uint16_t>(float_to_q31(rampgen.get_output()) >> (16));
			break;
		case DacChoice::Sine:
			DAC1val = static_cast<uint16_t>(float_to_q31(sinef/2.0f + 0.5f) >> (16));
			break;
		case DacChoice::Cosine:
			DAC1val = static_cast<uint16_t>(float_to_q31(cosinef/2.0f + 0.5f) >> (16));
			break;
		case DacChoice::Ipark_Alpha:
			DAC1val = static_cast<uint16_t>(float_to_q31(ipark.Alpha/2.0f + 0.5f) >> (16));
			break;
		case DacChoice::Ipark_Beta:
			DAC1val = static_cast<uint16_t>(float_to_q31(ipark.Beta/2.0f + 0.5f) >> (16));
			break;
		// tA, tB, tC only go 0.0 to 1.0, so it's only half the full range of Q31 (it's like a 31 bit unsigned int)
		// so we shift by 15 to allow for full range of 16-bit value
		case DacChoice::SVM_TA:
			DAC1val = static_cast<uint16_t>(float_to_q31(svm.tA) >> (15));
			break;
		case DacChoice::SVM_TB:
			DAC1val = static_cast<uint16_t>(float_to_q31(svm.tB) >> (15));
			break;
		case DacChoice::SVM_TC:
			DAC1val = static_cast<uint16_t>(float_to_q31(svm.tC) >> (15));
			break;
		}

		switch(dac2sel) {
		case DacChoice::RampControl:
			DAC2val = static_cast<uint16_t>(float_to_q31(rampcont.get_output()) >> (16));
			break;
		case DacChoice::RampAngle:
			DAC2val = static_cast<uint16_t>(float_to_q31(rampgen.get_output()) >> (16));
			break;
		case DacChoice::Sine:
			DAC2val = static_cast<uint16_t>(float_to_q31(sinef/2.0f + 0.5f) >> (16));
			break;
		case DacChoice::Cosine:
			DAC2val = static_cast<uint16_t>(float_to_q31(cosinef/2.0f + 0.5f) >> (16));
			break;
		case DacChoice::Ipark_Alpha:
			DAC2val = static_cast<uint16_t>(float_to_q31(ipark.Alpha/2.0f + 0.5f) >> (16));
			break;
		case DacChoice::Ipark_Beta:
			DAC2val = static_cast<uint16_t>(float_to_q31(ipark.Beta/2.0f + 0.5f) >> (16));
			break;
		case DacChoice::SVM_TA:
			DAC2val = static_cast<uint16_t>(float_to_q31(svm.tA) >> (15));
			break;
		case DacChoice::SVM_TB:
			DAC2val = static_cast<uint16_t>(float_to_q31(svm.tB) >> (15));
			break;
		case DacChoice::SVM_TC:
			DAC2val = static_cast<uint16_t>(float_to_q31(svm.tC) >> (15));
			break;

		}


		dac.DHR12L1.set(static_cast<uint32_t>(DAC1val)); // NOTE THE L! Left aligned. Makes it like a 16-bit number
		dac.DHR12L2.set(static_cast<uint32_t>(DAC2val));


	}
}

// Timer update interrupt
void TIM1_UP_TIM16_IRQHandler() {
	auto tim = EbikeLib::get_timer<EbikeLib::Timer_Periph::Timer1>();
	tim.SR.UIF.set(false); // write 0 to reset the bit
	auto rp = EbikeLib::get_gpio<EbikeLib::Gpio_Port::GPIO_C>();
	if(rp.ODR.ODR14.get()) {
		rp.ODR.ODR14.set(false);
	} else {
		rp.ODR.ODR14.set(true);
	}

	// tell our ramp generating test function to go do something
	BaseType_t higher_priority_woken = pdFALSE;
	if(dac_task_is_running) {

		vTaskNotifyGiveFromISR(Dac_Task_Handle, &higher_priority_woken);
		portYIELD_FROM_ISR(higher_priority_woken);
	}

}

// Timer break (fault / overcurrent) interrupt
void TIM1_BRK_TIM15_IRQHandler() {
	auto tim = EbikeLib::get_timer<EbikeLib::Timer_Periph::Timer1>();
	// If a break has occurred, and the break pin is still active, we could get stuck
	// in this interrupt.
	// Disable the break input, will be re-enabled by the handling RTOS task
	tim.BDTR.BKE.set(false);
	// Also clear the interrupt. Could be break, break2, or system break
	if(tim.SR.BIF.get()) {
		tim.SR.BIF.set(false);
	}
	if(tim.SR.B2IF.get()) {
		tim.SR.B2IF.set(false);
	}
	if(tim.SR.SBIF.get()) {
		tim.SR.SBIF.set(false);
	}


	BaseType_t higher_priority_woken = pdFALSE;
	vTaskNotifyGiveFromISR(Drv_Fault_Task_Handle, &higher_priority_woken);
	portYIELD_FROM_ISR(higher_priority_woken);
}


} // extern "C"
