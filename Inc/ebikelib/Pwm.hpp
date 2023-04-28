#ifndef PWM_HPP_
#define PWM_HPP_
#pragma once

#include <cstdint>
#include "Timer.hpp"
#include "NvicHelpers.hpp"
#include "Rcc.hpp"
#include "EbikeConfig.hpp"
#include "Pin.hpp"
#include "FreeRTOS.h"

namespace EbikeLib {

/* Dead time settings
 *
 * "Dead time" is the time when both high and low side PWM outputs are off. This
 * prevents shoot through of the phase, as there's some delay between turning off
 * the PWM output and the MOSFET actually turning off.
 *
 * The dead time settings for the STM32G4 are defined in the datasheet as:
 *** DTG[7:5]=0xx => DT=DTG[7:0]x Tdtg with Tdtg=tDTS.
 *** DTG[7:5]=10x => DT=(64+DTG[5:0])x Tdtg with Tdtg=2x tDTS.
 *** DTG[7:5]=110 => DT=(32+DTG[4:0])x Tdtg with Tdtg=8x tDTS.
 *** DTG[7:5]=111 => DT=(32+DTG[4:0])x Tdtg with Tdtg=16x tDTS.
 *** Example if TDTS=125ns (8MHz), dead-time possible values are:
 *** 0 to 15875 ns by 125 ns steps,
 *** 16 us to 31750 ns by 250 ns steps,
 *** 32 us to 63us by 1 us steps,
 *** 64 us to 126 us by 2 us steps
 *
 * Note that tDTS is the "dead-time and sampling clock", set in the CKD field of timer register CR1.
 * tDTS can be the timer input clock divided by 1, 2, or 4
 * Since I'm using divide-by-1 (so tDTS = the timer clock of 170MHz, tDTS = 5.88ns)
 * That means the ranges for DTG are (all in nanoseconds):
 ***			Min		Max
 *** Range1: 	0.0		747.1
 *** Range2: 	752.9	1494.1
 *** Range3: 	1505.9	2964.7
 *** Range4: 	3011.8	5929.4
 *
 */

const float tDTS = (1.0f / 0.170f); // Ends up in units of ns
// Ranges are in units of tDTS.
const std::pair<uint32_t, uint32_t> DTG_Range1{0,	127};
const std::pair<uint32_t, uint32_t> DTG_Range2{128,	254};
const std::pair<uint32_t, uint32_t> DTG_Range3{256,	504};
const std::pair<uint32_t, uint32_t> DTG_Range4{512,	1008};

// Default setting is 500ns ... 170MHz / 85 = 2MHz -> 0.5us
// Setting is therefore 85 -> DTG[7:0] = '01010101' (bits 6, 4, 2, and 0)
const uint32_t default_dtg = 0b01010101;

// Inputs:
// deadtime_ns - requested dead-time setting in nanoseconds
// fDTS - dead-time and sampling clock in Hz (timer input clock divided by CKD divider in register CR1)
uint32_t convert_dt_ns_to_reg(float deadtime_ns, float fDTS) {
	// Get the integer version of the dead time
	// math simplification:
	// tDTS_ns = (1.0f / fDTS) * 1.0E9f;
	// deadtime_tDTS = deadtime_ns / tDTS_ns;
	// deadtime_tDTS = deadtime_ns / ((1.0f / fDTS) * 1e9)
	// deadtime_tDTS = deadtime_ns * fDTS / 1e9 (or more simply *1e-9)

	uint32_t deadtime_tDTS = static_cast<uint32_t>(deadtime_ns * fDTS * 1E-9f);

	if(deadtime_tDTS < DTG_Range1.second) {
		return deadtime_tDTS; // conversion is simple in this case
	} else if(deadtime_tDTS < DTG_Range2.second) {
		return ((deadtime_tDTS - DTG_Range2.first) / 2) | 0x80;
	} else if(deadtime_tDTS < DTG_Range3.second) {
		return ((deadtime_tDTS - DTG_Range3.first) / 8) | 0xC0;
	} else if(deadtime_tDTS < DTG_Range4.second){
		return ((deadtime_tDTS - DTG_Range4.first) / 16) | 0xE0;
	} else {
		// Maxes out at DTG_Range4.second
		// So just return the maximum dead time
		return 0xFF;
	}
}

float convert_dt_reg_to_ns(uint32_t dtreg, float fDTS) {
	float tDTS_ns = (1.0f / fDTS)*1E9f;
	uint32_t deadtime_tDTS;

	// Figure out what range we are in
	if((dtreg & 0x80) == 0) {
		// Range1
		deadtime_tDTS = dtreg;
	} else if((dtreg & 0x40) == 0x00) {
		// Range2
		deadtime_tDTS = ((dtreg & 0x3F) * 2) + DTG_Range2.first;
	} else if((dtreg & 0x20) == 0x00) {
		// Range3
		deadtime_tDTS = ((dtreg & 0x1F) * 8) + DTG_Range3.first;
	} else {
		// Range4
		deadtime_tDTS = ((dtreg & 0x1F) * 16) + DTG_Range4.first;
	}
	return tDTS_ns * static_cast<float>(deadtime_tDTS);
}



template <Timer_Periph pwm_tim>
class Pwm {
public:

	Pwm() {
		RCC_Funcs::start_timer_clock<pwm_tim>();
		auto rtim = STM32LIB::TIM<get_timer_base_address<pwm_tim>()>();

		// Configure PWM mode
		// Up-down counting mode (center aligned)
		// Channels 1,2,3,4,5 are PWM mode 1 (output high near zero, low near reload value)

		rtim.CR1.CMS.set(STM32LIB::CR1_Alignment_Mode::Center_Mode_1);
		// Use of "template" keyword is necessary below due to dependent name ambiguity
		// See https://en.cppreference.com/w/cpp/language/dependent_name
		// Without it, the '<' beginning of the template arguments after 'apply' is assumed
		// to be a less-than operator.
		rtim.CCMR1_Output.template apply<STM32LIB::TIM_CCMR1_Output::OC1M<STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1>,
			STM32LIB::TIM_CCMR1_Output::OC2M<STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1>,
			STM32LIB::TIM_CCMR1_Output::OC1PE<true>,
			STM32LIB::TIM_CCMR1_Output::OC2PE<true>>();

		rtim.CCMR2_Output.template apply<STM32LIB::TIM_CCMR2_Output::OC3M<STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1>,
			STM32LIB::TIM_CCMR2_Output::OC4M<STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1>,
			STM32LIB::TIM_CCMR2_Output::OC3PE<true>,
			STM32LIB::TIM_CCMR2_Output::OC4PE<true>>();
		rtim.CCMR3_Output.OC5M.set(STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1);
		rtim.CCMR3_Output.OC5PE.set(true);

		rtim.CR2.MMS.set(STM32LIB::CR2_Main_Mode::Compare_oc4refc); // Trigger1 out is OC4
		rtim.CR2.MMS2.set(STM32LIB::CR2_Main_Mode_2::Compare_oc5refc); // Trigger2 out is OC5

		rtim.CCER.template apply<STM32LIB::TIM_CCER::CC1E<true>,
			STM32LIB::TIM_CCER::CC1NE<true>,
			STM32LIB::TIM_CCER::CC2E<true>,
			STM32LIB::TIM_CCER::CC2NE<true>,
			STM32LIB::TIM_CCER::CC3E<true>,
			STM32LIB::TIM_CCER::CC3NE<true>>();

		rtim.BDTR.template apply<STM32LIB::TIM_BDTR::DTG<default_dtg>,
			STM32LIB::TIM_BDTR::OSSI<true>, // motor outputs low side on when MOE (motor enable) bit is false
			STM32LIB::TIM_BDTR::BKE<true>, // break input enabled
			STM32LIB::TIM_BDTR::BKP<true>>(); // polarity inverted (combined with bit in AF1, below)

		rtim.AF1.template apply<STM32LIB::TIM_AF1::BKINE<true>, // break pin enabled
			STM32LIB::TIM_AF1::BKINP<true>>(); // polarity inverted. with both BKP and BKINP set, brake is active-low (brakes when pin goes low)

		set_frequency(20000);

		uint32_t pwm_period = rtim.ARR.ARR.get();
		rtim.CCR1.CCR1.set(pwm_period / 2);
		rtim.CCR2.CCR2.set(pwm_period / 2);
		rtim.CCR3.CCR3.set(pwm_period / 2);
		rtim.CCR4.CCR4.set(pwm_period - 1); // Triggers during downcounting, just after reload
		rtim.CCR5.CCR5.set(1); // Triggers during downcounting, just before hitting zero

		// Configure update interrupt
//		rtim.DIER.UIE.set(true);
//		enable_update_irq();
		// And break interrupt
//		rtim.DIER.BIE.set(true);
//		enable_break_irq();

		// Start the timer
		rtim.CR1.CEN.set(true);
	}

	void set_frequency(uint32_t freq) {
		// Grab the timer frequency
		// const uint32_t Tim_Freq = 170000000;
		uint32_t Tim_Freq = get_timer_clock<pwm_tim>();

		// Timer_frequency / desired_frequency = 2*(pwm_period+1)
		// note the x2 comes from up/down counting
		// Example:
		// want 20kHz, timer clock is 170MHz
		// 170_000_000 / 20_000 = 8500
		// 8500 / 2 = 4250
		// period should be 4249

		uint32_t pwm_period = Tim_Freq / freq / 2 - 1;
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();

		// Disable motor if it was on
		bool timer_was_enabled = false;
		bool motor_outputs_were_enabled = false;
		if(rtim.BDTR.MOE.get()) {
			motor_outputs_were_enabled = true;
			rtim.BDTR.MOE.set(false);
		}
		if(rtim.CR1.CEN.get()) {
			timer_was_enabled = true;
			rtim.CR1.CEN.set(false);
		}

		// Set the new frequency
		rtim.ARR.ARR.set(pwm_period);

		if(timer_was_enabled) {
			rtim.CR1.CEN.set(true);
		}
		if(motor_outputs_were_enabled) {
			rtim.BDTR.MOE.set(true);
		}
	}


	void set_deadtime(float ns) {
		// Grab the timer frequency
		uint32_t Tim_Freq_Int = get_timer_clock<pwm_tim>();
		float Tim_Freq = static_cast<float>(Tim_Freq_Int);
		// Figure out the divider
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		STM32LIB::CR1_Clock_Division tim_ckd = rtim.CR1.CKD.get();
		switch(tim_ckd) {
		case STM32LIB::CR1_Clock_Division::Kernel_Clock:
			// No change to Tim_Freq
			break;
		case STM32LIB::CR1_Clock_Division::Kernel_Clock_x2:
			Tim_Freq = Tim_Freq / 2.0f;
			break;
		case STM32LIB::CR1_Clock_Division::Kernel_Clock_x4:
			Tim_Freq = Tim_Freq / 4.0f;
			break;
		}
		uint32_t new_dt_reg = convert_dt_ns_to_reg(ns, Tim_Freq);
		rtim.BDTR.DTG.set(new_dt_reg);
	}

	// Note: for this PCB layout, channel assignments are:
	// Ch1 = Phase C
	// Ch2 = Phase B
	// Ch3 = Phase A
	void set_duty(uint16_t dc_a, uint16_t dc_b, uint16_t dc_c) {
		// scale from 65536 to the maximum counter value, PWM_PERIOD

		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		uint32_t temp, pwm_arr;

		pwm_arr = rtim.ARR.ARR.get();
		temp = (pwm_arr * dc_a) / 65536u;
		rtim.CCR3.CCR3.set(temp);
		temp = (pwm_arr * dc_b) / 65536u;
		rtim.CCR2.CCR2.set(temp);
		temp = (pwm_arr * dc_c) / 65536u;
		rtim.CCR1.CCR1.set(temp);
	}

	void set_duty(float dc_a, float dc_b, float dc_c) {
		// Floats should be scaled 0.0 to 1.0
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		float pwm_arr_f = static_cast<float>(rtim.ARR.ARR.get());
		rtim.CCR3.CCR3.set(static_cast<uint32_t>(dc_a*pwm_arr_f));
		rtim.CCR2.CCR2.set(static_cast<uint32_t>(dc_b*pwm_arr_f));
		rtim.CCR1.CCR1.set(static_cast<uint32_t>(dc_c*pwm_arr_f));
	}

	void enable_update_irq() {
		constexpr uint32_t irqn = timer_update_irqs[static_cast<uint32_t>(pwm_tim)];
		set_interrupt_priority<irqn>(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
		enable_interrupt<irqn>();
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		rtim.DIER.UIE.set(true);
	}

	void clear_break() {
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		if(rtim.SR.BIF.get()) {
			rtim.SR.BIF.set(false);
		}
	}

	void clear_break2() {
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		if(rtim.SR.B2IF.get()) {
			rtim.SR.B2IF.set(false);
		}
	}

	void clear_system_break() {
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		if(rtim.SR.SBIF.get()) {
			rtim.SR.SBIF.set(false);
		}
	}

	void enable_break_irq() {
		constexpr uint32_t irqn = timer_break_irqs[static_cast<uint32_t>(pwm_tim)];
		set_interrupt_priority<irqn>(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
		enable_interrupt<irqn>();
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		rtim.DIER.BIE.set(true);
	}

	inline void motor_on_off(bool on_off) {
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		rtim.BDTR.MOE.set(on_off);
	}

	enum class PWM_Output_Mode {
		Low, // Channel is "Force inactive level", low side FET will be high and high side will be low
		Pwm, // Channel is in PWM mode 1, normal PWM output
		Off // Channel is "Force inactive level" but high side output disabled. Both high and low side outputs will be low
	};

	inline void set_mode_phase_a(PWM_Output_Mode mode) {
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		switch(mode) {
		case PWM_Output_Mode::Low:
			rtim.CCMR2_Output.OC3M.set(STM32LIB::CCMR_Output_Compare_Mode::Force_Inactive);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC3E<true>,
				STM32LIB::TIM_CCER::CC3NE<true>
			>();
			break;
		case PWM_Output_Mode::Pwm:
			rtim.CCMR2_Output.OC3M.set(STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC3E<true>,
				STM32LIB::TIM_CCER::CC3NE<true>
			>();
			break;
		case PWM_Output_Mode::Off:
			rtim.CCMR2_Output.OC3M.set(STM32LIB::CCMR_Output_Compare_Mode::Force_Inactive);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC3E<false>,
				STM32LIB::TIM_CCER::CC3NE<true>
			>();
			break;
		}
	}

	inline void set_mode_phase_b(PWM_Output_Mode mode) {
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		switch(mode) {
		case PWM_Output_Mode::Low:
			rtim.CCMR1_Output.OC2M.set(STM32LIB::CCMR_Output_Compare_Mode::Force_Inactive);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC2E<true>,
				STM32LIB::TIM_CCER::CC2NE<true>
			>();
			break;
		case PWM_Output_Mode::Pwm:
			rtim.CCMR1_Output.OC2M.set(STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC2E<true>,
				STM32LIB::TIM_CCER::CC2NE<true>
			>();
			break;
		case PWM_Output_Mode::Off:
			rtim.CCMR1_Output.OC2M.set(STM32LIB::CCMR_Output_Compare_Mode::Force_Inactive);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC2E<false>,
				STM32LIB::TIM_CCER::CC2NE<true>
			>();
			break;
		}
	}

	inline void set_mode_phase_c(PWM_Output_Mode mode) {
		auto rtim = STM32LIB::TIM<EbikeLib::get_timer_base_address<pwm_tim>()>();
		switch(mode) {
		case PWM_Output_Mode::Low:
			rtim.CCMR1_Output.OC1M.set(STM32LIB::CCMR_Output_Compare_Mode::Force_Inactive);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC1E<true>,
				STM32LIB::TIM_CCER::CC1NE<true>
			>();
			break;
		case PWM_Output_Mode::Pwm:
			rtim.CCMR1_Output.OC1M.set(STM32LIB::CCMR_Output_Compare_Mode::PWM_Mode_1);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC1E<true>,
				STM32LIB::TIM_CCER::CC1NE<true>
			>();
			break;
		case PWM_Output_Mode::Off:
			rtim.CCMR1_Output.OC1M.set(STM32LIB::CCMR_Output_Compare_Mode::Force_Inactive);
			rtim.CCER.template apply<
				STM32LIB::TIM_CCER::CC1E<false>,
				STM32LIB::TIM_CCER::CC1NE<true>
			>();
			break;
		}
	}
};

// Helper function to set GPIOs in PWM output
template<Pin pwm_pin, uint32_t af_num, STM32LIB::GPIO_Pull pull = STM32LIB::GPIO_Pull::None>
void pwm_gpio_config() {
	gpio_mode<pwm_pin.Port,  pwm_pin.Num, STM32LIB::GPIO_Mode::Alternate_Function>();
	gpio_speed<pwm_pin.Port,  pwm_pin.Num, STM32LIB::GPIO_Speed::Very_High>();
	gpio_pull<pwm_pin.Port,  pwm_pin.Num, pull>();
	gpio_af<pwm_pin.Port,  pwm_pin.Num, af_num>();
}

} // namespace EbikeLib

#endif // PWM_HPP_
