#ifndef HALLSENSOR_HPP_
#define HALLSENSOR_HPP_

#pragma once

#include <cstdint>
#include <array>
#include "EbikeConfig.hpp"
#include "Timer.hpp"
#include "TimerPeriph.hpp"
#include "Rcc.hpp"
#include "FreeRTOS.h"

using namespace STM32LIB;

namespace EbikeLib {

const uint8_t NumAccelSamples = 4; // Number of speed samples for rolling average
const float DefaultHallTick = 1.0f; // Requested tick in microseconds
// at 1us, the minimum motor speed (before rollovers) is 152 eRPM
// for a 700C wheel with 23 pole pairs, this is 0.5mph
//

enum class HallState {
	Stopped = 0,
	Rotation_Unknown = 1,
	Rotation_Forward = 2,
	Rotation_Reverse = 3
};

enum class HallAngleValid {
	Invalid,
	Valid
};

template <Timer_Periph hall_tim>
class HallSensor {
public:
	HallSensor(uint32_t calling_frequency = 20000u) :
		CallingFrequency(calling_frequency)
		{
		// Determine prescaler
		Prescaler = static_cast<uint16_t>(static_cast<float>(get_timer_clock<hall_tim>())*DefaultHallTick/(1000000.0f));

		// Initialize the timer for the Hall Sensor function
		RCC_Funcs::start_timer_clock<hall_tim>();

		auto htim = get_timer<hall_tim>();
		// General settings - Dead time and sampling filter set to input clock / 4 (170MHz / 4 = 42.5MHz)
		// Update request source set, which means that slave mode controller reset does NOT generate
		// an update interrupt. This is important, since we use the update interrupt to determine if the
		// Hall sensors have timed out.
		htim.CR1.template apply<
			TIM_CR1::URS<true>,
			TIM_CR1::CKD<STM32LIB::CR1_Clock_Division::Kernel_Clock_x4>>();
		// Auto-reload value should be the maximum allowable. Reloads will normally happen
		// when the Hall sensor signal changes
		htim.ARR.set(0xFFFFu);
		// Set the prescaler. Prescaler register value is prescaler divider minus 1 (PSC of 0 is a /1 divider)
		htim.PSC.set(Prescaler-1);
		// Input settings for the Hall timer
		// Capture compare units 1-3 are used, but inputs are all XOR'd together into channel 1
		// CC1 channel is input with input 1 mapped to it, no prescaler so every change
		// counts, and input filter set to 8 samples at Fdts / 16 (42.5 / 16 = 2.65625 MHz) ... fastest response is 3 us
		htim.CCMR1_Input.template apply<
			TIM_CCMR1_Input::CC1S<CCMR1_Input_CC1S_T::Input_IC_Match>,
			TIM_CCMR1_Input::IC1F<Timer_Filter::Sampling_DTS_Div16_N8>>();

		// Reset mode, input is TI1F_ED (Channel 1 input, filtered, edge detector)
		htim.SMCR.template apply<
			TIM_SMCR::TS<4>, // 00100: tim_ti1 Edge Detector (tim_ti1f_ed)
			TIM_SMCR::SMS<SMCR_Secondary_Mode_Selection::Reset>>();

		// Input 1 enabled, both edges captured
		htim.CCER.template apply<
			TIM_CCER::CC1E<true>,
			TIM_CCER::CC1P<true>,
			TIM_CCER::CC1NP<true>>();

		// Channels 1, 2, and 3 are XOR'd together into channel 1
		htim.CR2.TI1S.set(true);

		// Generate an update event to latch in any of the preloaded registers
		htim.EGR.UG.set(true);

		// Enabling interrupts is done later

		// Start the timer
		htim.CR1.CEN.set(true);

	}

	void enable_update_irq() const {
		constexpr uint32_t irqn = timer_update_irqs[static_cast<uint32_t>(hall_tim)];
		set_interrupt_priority<irqn>(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
		enable_interrupt<irqn>();
		auto htim = get_timer<hall_tim>();
		// Set both update and capture channel 1 interrupt enables
		htim.DIER.template apply<TIM_DIER::UIE<true>,TIM_DIER::CC1IE<true>>();
	}

	void capture_irq_callback() {
		auto htim = get_timer<hall_tim>();

		CaptureValue = htim.CCR1.get();
		CurrentState = get_hall_gpio_state(); // TODO: This function



	}

	void overflow_irq_callback() {
		// Overflow means it's been too long between Hall state changes
		// Set speed to zero immediately
		Speed = 0.0f;
		AngleIncrement = 0.0f;
		Status = HallState::Stopped;
		Valid = HallAngleValid::Invalid;
		SteadyRotationCount = 0;
	}

private:
    float Speed = 0.0f;
    float PreviousSpeed = 0.0f;
    float Accel = 0.0f;
    std::array<float, NumAccelSamples> AccelSamples{0.0f, 0.0f, 0.0f, 0.0f};
    uint32_t CallingFrequency;
    float AngleIncrement = 0.0f;
    float Angle = 0.0f;
    uint32_t CaptureValue = 0;
    std::array<uint32_t,8> CaptureForState{0,0,0,0,0,0,0,0};
    uint16_t Prescaler = 169; // Default for 1us with 170MHz clock
    std::array<uint16_t,8> PrescalerForState{0,0,0,0,0,0,0,0};
    uint8_t CurrentAccelSample = 0;
    HallState Status = HallState::Stopped;
    uint8_t OverflowCount = 0;
    uint8_t SteadyRotationCount = 0;
    uint8_t RotationDirection = 0;
    uint8_t PreviousRotationDirection = 0;
    uint8_t CurrentState = 0;
    uint8_t PreviousState = 0;
    HallAngleValid Valid = HallAngleValid::Invalid;
};

// Helper function to set GPIOs in timer input
template<Pin hall_pin, uint32_t af_num, STM32LIB::GPIO_Pull pull = STM32LIB::GPIO_Pull::None>
void hall_gpio_config() {
	gpio_mode<hall_pin.Port,  hall_pin.Num, STM32LIB::GPIO_Mode::Alternate_Function>();
	gpio_speed<hall_pin.Port,  hall_pin.Num, STM32LIB::GPIO_Speed::Very_High>();
	gpio_pull<hall_pin.Port,  hall_pin.Num, pull>();
	gpio_af<hall_pin.Port,  hall_pin.Num, af_num>();
}

} // namespace EbikeLib



#endif /* HALLSENSOR_HPP_ */
