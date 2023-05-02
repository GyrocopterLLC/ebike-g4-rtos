#ifndef HALLSENSOR_HPP_
#define HALLSENSOR_HPP_

#pragma once

#include <cstdint>
#include <numeric>
#include <array>
#include <cmath>
#include <algorithm>
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
	Stopped,
	First_Capture,
	Rotation_Unknown,
	Rotation_Forward,
	Rotation_Reverse
};

enum class HallAngleValid {
	Invalid,
	Valid
};

template <Timer_Periph hall_tim, Pin HallA, Pin HallB, Pin HallC>
class HallSensor {
public:
	HallSensor(uint32_t calling_frequency = 20000u) :
		CallingFrequency(calling_frequency)
		{
		// Determine prescaler based on the desired timer tick period
		Prescaler = static_cast<uint16_t>(static_cast<float>(get_timer_clock<hall_tim>())*DefaultHallTick/(1000000.0f));
		ActualTimerTick_us = 1.0f/(static_cast<float>(get_timer_clock<hall_tim>())/static_cast<float>(Prescaler)/1000000.0f);

		generate_reverse_table(); // Precaculate the reverse direction table so we don't waste time each cycle doing it over again

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

		// Determine the Hall state right now
		CurrentState = determine_hall_gpio_state();

		// Start the timer
		htim.CR1.CEN.set(true);

	}

	void enable_interrupts() const {
		constexpr uint32_t irqn = timer_update_irqs[static_cast<uint32_t>(hall_tim)];
		set_interrupt_priority<irqn>(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
		enable_interrupt<irqn>();
		auto htim = get_timer<hall_tim>();
		// Set both update and capture channel 1 interrupt enables
		htim.DIER.template apply<TIM_DIER::UIE<true>,TIM_DIER::CC1IE<true>>();
	}

	inline bool state_valid(uint8_t state) const {
		if(state < 1 || state > 6)
			return false;
		else
			return true;
	}

	void increment_angle() {
		Angle += AngleIncrement;
		Angle = clip_to_one(Angle);
		// In case of jerky steps due to Hall sensor changes,
		// smooth the angle using the difference between the
		// before and after step change angles
		FilteredAngle = clip_to_one(Angle - AngleStepDiff);
		// Decrease angle step difference towards zero
		if(AngleStepDiff != 0.0f) {
			AngleStepDiff = AngleStepDiff * 0.9f;
			// And clip it when it is too small
			if(std::abs(AngleStepDiff) <= 0.000001f) {
				AngleStepDiff = 0.0f;
			}
		}
	}

	float get_angle() {
		return FilteredAngle;
	}

	void capture_irq_callback() {
		auto htim = get_timer<hall_tim>();

		CaptureValue = htim.CCR1.get();
		PreviousState = CurrentState;
		CurrentState = determine_hall_gpio_state();
		if(state_valid(CurrentState)) {
			CaptureForState[CurrentState-1] = CaptureValue;
		}

		// Determine the rotation speed from this latest capture value
		// TODO: Ensure we've had at least all states captured since last overflow
		// before doing a speed calculation otherwise it won't be accurate.
		auto all_states_capture = std::accumulate(CaptureForState.begin(), CaptureForState.end(), 0);

		float captime_us = static_cast<float>(all_states_capture)*ActualTimerTick_us;
		Speed = (1000000.0f/(captime_us));

		// Create the per-update angle increment
		AngleIncrement = Speed / static_cast<float>(CallingFrequency);

		// Determine rotation direction
		if(Status == HallState::Stopped) {
			// This is the first capture since stopping, so we can't determine the speed
			// or direction accurately. We need one more capture after this.
			Status = HallState::First_Capture;
		} else {
			if(state_valid(PreviousState) && state_valid(CurrentState)) {
				if(HallStateRotation[PreviousState-1] == CurrentState) {
					Status = HallState::Rotation_Forward;
				} else if(HallStateRotation[CurrentState-1] == PreviousState) {
					Status = HallState::Rotation_Reverse;
					// Negate the AngleIncrement, as it should be decreasing in reverse
					AngleIncrement = -AngleIncrement;
				} else {
					Status = HallState::Rotation_Unknown;
				}
			} else {
				Status = HallState::Rotation_Unknown;
			}
		}

		// Determine new angle from the Hall state
		float new_angle;
		switch(Status) {
		case HallState::Rotation_Forward:
			new_angle = HallAngleForState[CurrentState-1];
			AngleStepDiff = new_angle - Angle;
			Angle = new_angle;
			break;
		case HallState::Rotation_Reverse:
			// Entered this state going reverse, which means we are now at the
			// ending angle of the state. We should get the beginning angle of the
			// next state going forward (ending angle of this state going forward).
			// Since we only have the angles of going forward, not reverse, this
			// is the easiest way to accomplish it.
			new_angle = HallAngleForState[HallStateRotation[CurrentState-1]-1];
			AngleStepDiff = new_angle - Angle;
			Angle = new_angle;
			break;
		default:
			// Don't know which way we are going, just return the midpoint
			// of the state we are in (if it's valid)
			Angle = get_state_midpoint_angle(CurrentState);
			FilteredAngle = Angle;
			AngleStepDiff = 0.0f;
			break;
		}

		// TODO:
		// Implement the called-every-so-often function
		// - tracks a filtered and unfiltered angle, filtering to prevent jumps at Hall state changes
		// Implement the get-angle-now function
		// - chooses angle based on rotation status, if not rotating must use hall state angle
	}

	void overflow_irq_callback() {
		// Overflow means it's been too long between Hall state changes
		// Set speed to zero immediately
		Speed = 0.0f;
		AngleIncrement = 0.0f;
		AngleStepDiff = 0.0f;
		Status = HallState::Stopped;
		Valid = HallAngleValid::Invalid;
		SteadyRotationCount = 0;

		// Angle will now be fixed on the current state.
		// Set to the middle of the state.
		// Interpolate between previous state and this state,
		// which puts us smack in the middle of the state
		Angle = get_state_midpoint_angle(CurrentState);
		FilteredAngle = Angle;
	}

private:
    float Speed = 0.0f;
    float PreviousSpeed = 0.0f;
    float Accel = 0.0f;
    // Values for HallAngleForState and HallStateRotation are in EbikeConfig.hpp
    std::array<float, 6> HallAngleForState = Hall_Angles;
    std::array<uint8_t, 6> HallStateRotation = Hall_Rotation_Table;
    std::array<uint8_t, 6> HallStateReverseRotation{0, 0, 0, 0, 0, 0};
    std::array<float, NumAccelSamples> AccelSamples{0.0f, 0.0f, 0.0f, 0.0f};
    uint32_t CallingFrequency;
    float AngleIncrement = 0.0f;
    float Angle = 0.0f;
    float AngleStepDiff = 0.0f;
    float FilteredAngle = 0.0f;
    uint32_t CaptureValue = 0;
    std::array<uint32_t,6> CaptureForState{0,0,0,0,0,0};
    uint16_t Prescaler = 169; // Default for 1us with 170MHz clock
    float ActualTimerTick_us = 1.0f;
    uint8_t CurrentAccelSample = 0;
    HallState Status = HallState::Stopped;
    uint8_t OverflowCount = 0;
    uint8_t SteadyRotationCount = 0;
    uint8_t RotationDirection = 0;
    uint8_t PreviousRotationDirection = 0;
    uint8_t CurrentState = 0;
    uint8_t PreviousState = 0;
    HallAngleValid Valid = HallAngleValid::Invalid;

    uint8_t determine_hall_gpio_state() {
    	// Check the three Hall pins and determine the Hall sensor state
    	bool hallAval = gpio_get<HallA.Port, HallA.Num>();
    	bool hallBval = gpio_get<HallB.Port, HallB.Num>();
    	bool hallCval = gpio_get<HallC.Port, HallC.Num>();
    	uint8_t state = 0;
    	state += (hallAval ? 1 : 0);
    	state += (hallBval ? 2 : 0);
    	state += (hallCval ? 4 : 0);
    	return state;
    }

    void generate_reverse_table() {
    	// Creates the HallStateReverseRotation table by inverting (values become indices,
    	// indices become values) the HallStateRotation table

    	for(uint_fast8_t i = 0; i < 6; i++) {
    		uint8_t reverse_index = HallStateRotation[i];
    		HallStateReverseRotation[reverse_index - 1] = i + 1;
    	}
    }

    float get_state_midpoint_angle(uint8_t state) {
		if(state_valid(state)) {
			// Since angles in the HallAngleForState table are all the transitions to the new
			// state when rotating forward, it's giving us the angle of the beginning of the
			// state. We need the midpoint, so we need to average with the angle of the beginning
			// of the next state (end of current state).
			// Get the next state (as if rotating forward) from the state table
			uint8_t next_state = HallStateRotation[state - 1];

			// Average the beginning and ending angles for this state
			float end_state_angle = HallAngleForState[next_state - 1];
			float begin_state_angle = HallAngleForState[state - 1];
			return (end_state_angle + begin_state_angle) / 2.0f;
		} else {
			// Invalid state, so we can't know the angle
			return 0.0f;
		}
    }

    float clip_to_one(float input) {
    	while(input > 1.0f) {
    		input -= 1.0f;
    	}
    	while(input < 0.0f) {
    		input += 1.0f;
    	}
    	return input;
    }
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
