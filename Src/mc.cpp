
#include <type_traits>
#include <cstring>

#include "Timer.hpp"
#include "Gpio.hpp"
#include "Pwm.hpp"
#include "HallSensor.hpp"
#include "STM32G473xx.hpp"
#include "EbikeConfig.hpp"
#include "Adc.hpp"
#include "mc.h"
#include "FOC_Lib.hpp"
#include "RampControl.hpp"
#include "Rampgen.hpp"
#include "NvicHelpers.hpp"
#include "CORDIC_Trig.hpp"
#include "DRV8353.hpp"
#include "Throttle.hpp"
//#include "usb_info.h"
#include "cobs.h"

#include "FreeRTOS.h"
#include "task.h"
#include "tusb.h"


TaskHandle_t Dac_Task_Handle = NULL;
TaskHandle_t Drv_Fault_Task_Handle = NULL;

/**** Static placement buffers for classes ****/
EbikeLib::DRV8353* drv_handle = nullptr;
uint8_t drv_static_placement_buf[sizeof(EbikeLib::DRV8353)];

using PwmT = EbikeLib::Pwm<EbikeLib::Timer_Periph::Timer1>;
PwmT* pwm_handle = nullptr;
uint8_t pwm_static_placement_buf[sizeof(PwmT)];

using HallT = EbikeLib::HallSensor<EbikeLib::Hall_Timer, EbikeLib::HALL_A_Pin, EbikeLib::HALL_B_Pin, EbikeLib::HALL_C_Pin>;
HallT* hall_handle = nullptr;
uint8_t hall_static_placement_buf[sizeof(HallT)];

EbikeLib::Throttle* thr_handle = nullptr;
uint8_t thr_static_placement_buf[sizeof(EbikeLib::Throttle)];

//EbikeLib::USB_Info* usb_info_handle = nullptr;
//uint8_t usb_info_static_placement_buf[sizeof(EbikeLib::USB_Info)];
// And this one also needs a packet buffer
uint8_t usb_packet_buffer[64];
uint8_t cobs_output_packet_buffer[64];
// Simple packet starting array. Has a byte each for the type of data and number of data bytes
uint8_t packet_start[2];
bool debug_usb_send = false;

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


	pwm_handle = new(pwm_static_placement_buf) PwmT();
	// Initialize GPIO for this PWM timer
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_C_Pin, EbikeLib::Pwm_C_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_B_Pin, EbikeLib::Pwm_B_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_A_Pin, EbikeLib::Pwm_A_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_Cn_Pin, EbikeLib::Pwm_Cn_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_Bn_Pin, EbikeLib::Pwm_Bn_Af_Num>();
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_An_Pin, EbikeLib::Pwm_An_Af_Num>();
	// Need a weak pullup on the fault pin
	EbikeLib::pwm_gpio_config<EbikeLib::PWM_OC_Pin, EbikeLib::Pwm_OC_Af_Num, STM32LIB::GPIO_Pull::Up>();

//	usb_info_handle = new(usb_info_static_placement_buf) EbikeLib::USB_Info(usb_packet_buffer, 128);

	// Start the Hall Sensor timer
	EbikeLib::hall_gpio_config<EbikeLib::HALL_A_Pin, EbikeLib::Hall_A_Af_Num>();
	EbikeLib::hall_gpio_config<EbikeLib::HALL_B_Pin, EbikeLib::Hall_B_Af_Num>();
	EbikeLib::hall_gpio_config<EbikeLib::HALL_C_Pin, EbikeLib::Hall_C_Af_Num>();
	hall_handle = new(hall_static_placement_buf) HallT();

	// Create the throttle processor
	thr_handle = new(thr_static_placement_buf) EbikeLib::Throttle();
}

void mc_startup_post_rtos() {
	adc_init(); // Can't do this outside of a RTOS task!! Uses vTaskDelay
	drv_handle = new(drv_static_placement_buf) EbikeLib::DRV8353(); // same here

	// now that both ADC and DRV8353 are up and running, calibrate the current sensors
	// best to do this without motor running, too.
	// Let's wait about 25ms for power to stabilize first
	vTaskDelay(pdMS_TO_TICKS(25));
	adc_calibrate_currents(drv_handle);

	// and now that the drv8353 is enabled, let's turn on the PWM interrupts
	// be sure to clear the break flag if it was set
	// if there's a break input active, the flag will come right back and that's okay
	pwm_handle->clear_break();
	pwm_handle->enable_break_irq();
	pwm_handle->enable_update_irq();
	// and the motor outputs
	pwm_handle->motor_on_off(true);

	// Enable interrupts on the Hall sensor
	hall_handle->enable_interrupts();
}

const float VdTesting = 0.0f;            // Vd testing (pu)
const float VqTesting = 0.15f;         // Vq testing (pu)

const float IdTesting = 0.0f;
const float IqTesting = 0.5f;

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
	ADC_Current_T currents;

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
	float sinef, cosinef, anglef;
	uint8_t hall_state;
	float throttle_angle;

	auto svm = EbikeLib::SVM();
	auto ipark = EbikeLib::Inverse_Park();
	auto park = EbikeLib::Park();
	auto clarke = EbikeLib::Clarke();
	auto pid_d = EbikeLib::PID();
	auto pid_q = EbikeLib::PID();

	// Sampling is now 20kHz
	// So rampcont target of 1Hz is value of 0.00005 (1/20000)
	// Ramp rate of 10 second: Ramp Control Rate = 1/(10*20000) = 0.000005
	auto rampcont = EbikeLib::RampControl(0.00005f, 0.000005f);
	auto rampgen = EbikeLib::Rampgen();

	mc_startup_post_rtos();

	// Now we're ready!
	dac_task_is_running = true;
	uint32_t dac_task_counter = 0;

	while(true) {
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // triggered by ADC completion
		// Get phase currents
		adc_get_scaled_currents(&currents);

		// perform Hall sensor math
		hall_handle->increment_angle();

		// Throttle processing
		thr_handle->process(adc_get_scaled_throttle());
		throttle_angle = thr_handle->getOutput();

		rampcont.calc();
		rampgen.set_freq(rampcont.get_output());
		rampgen.calc();
#if 0
		anglef = rampgen.get_output();
#else
		anglef = hall_handle->get_angle();
#endif
		angle_int = float_to_q31(anglef);
		hall_state = hall_handle->get_state();

		//angle_int = static_cast<int32_t>(rampgen.get_output() * 2147483648.0f);
		cordic.calc(angle_int, &cordic_sine, &cordic_cosine);

		sinef = 2.0f*q31_to_float(cordic_sine);
		//sinef = 2.0f*static_cast<float>(cordic_sine)/2147483648.0f;

		cosinef = 2.0f*q31_to_float(cordic_cosine);
		//cosinef = 2.0f*static_cast<float>(cordic_cosine)/2147483648.0f;


		clarke.calc(currents.iA, currents.iB); // convert 3-phase to 2-phase (both stationary)
		park.calc(clarke.Alpha, clarke.Beta, sinef, cosinef); // convert to rotating

		pid_d.calc(IdTesting - park.Ds);
		pid_q.calc(IqTesting - park.Qs);

		ipark.calc(pid_d.getOutput(),  pid_q.getOutput(),  sinef,  cosinef);

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


		// Try sending info by USB as well
		// Just send a few values right now:
		// - counter (uint32_t)
		// - angle (ramp) (float)
		// - SVM Ta (float)
		// - SVM Tb (float)
		// - SVM Tc (float)
		if(debug_usb_send) {
			uint32_t cobs_length;
			uint32_t packet_pointer;
			if(dac_task_counter % 40 == 0) { // once per 2 milliseconds
				usb_packet_buffer[0] = 0x01; // Data packet tag
				usb_packet_buffer[1] =
						sizeof(dac_task_counter) + sizeof(anglef) + sizeof(hall_state)
						+ sizeof(throttle_angle)
						+ sizeof(svm.tA) + sizeof(svm.tB) + sizeof(svm.tC)
						+ sizeof(currents.iA) + sizeof(currents.iB) + sizeof(currents.iC);
				packet_pointer = 2;
				memcpy(&(usb_packet_buffer[packet_pointer]), &dac_task_counter, sizeof(dac_task_counter));
				packet_pointer += sizeof(dac_task_counter);
				memcpy(&(usb_packet_buffer[packet_pointer]), &anglef, sizeof(anglef));
				packet_pointer += sizeof(anglef);
				memcpy(&(usb_packet_buffer[packet_pointer]), &hall_state, sizeof(hall_state));
				packet_pointer += sizeof(hall_state);
				memcpy(&(usb_packet_buffer[packet_pointer]), &throttle_angle, sizeof(throttle_angle));
				packet_pointer += sizeof(throttle_angle);
				memcpy(&(usb_packet_buffer[packet_pointer]), &svm.tA, sizeof(svm.tA));
				packet_pointer += sizeof(svm.tA);
				memcpy(&(usb_packet_buffer[packet_pointer]), &svm.tB, sizeof(svm.tB));
				packet_pointer += sizeof(svm.tB);
				memcpy(&(usb_packet_buffer[packet_pointer]), &svm.tC, sizeof(svm.tC));
				packet_pointer += sizeof(svm.tC);
				memcpy(&(usb_packet_buffer[packet_pointer]), &currents.iA, sizeof(currents.iA));
				packet_pointer += sizeof(currents.iA);
				memcpy(&(usb_packet_buffer[packet_pointer]), &currents.iB, sizeof(currents.iB));
				packet_pointer += sizeof(currents.iB);
				memcpy(&(usb_packet_buffer[packet_pointer]), &currents.iC, sizeof(currents.iC));
				packet_pointer += sizeof(currents.iC);
				cobs_length = encodeCOBS(usb_packet_buffer, packet_pointer, cobs_output_packet_buffer, sizeof(cobs_output_packet_buffer));
				tud_cdc_write(cobs_output_packet_buffer, cobs_length);
			}
		}
		dac_task_counter++;
	}
}

void start_debug_usb_info() {
	debug_usb_send = true;
}

void stop_debug_usb_info() {
	debug_usb_send = false;
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
}

void wake_dac_task() {
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

void TIM4_IRQHandler() {
	// Which interrupt was it?
	// auto tim4 = EbikeLib::get_timer<EbikeLib::Timer_Periph::Timer4>();
	auto tim4 = STM32LIB::TIM<STM32LIB::TIM4_Base_Address>();

	if(tim4.SR.UIF.get()) {
		// Update interrupt, overflow occurred
		tim4.SR.UIF.set(false); // reset the interrupt by writing 0
		hall_handle->overflow_irq_callback();
	}
	if(tim4.SR.CC1IF.get()) {
		tim4.SR.CC1IF.set(false);
		hall_handle->capture_irq_callback();
	}

}


} // extern "C"
