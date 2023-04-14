#ifndef TIMER_HPP_
#define TIMER_HPP_
#pragma once

#include <cstdint>
#include <array>
#include "STM32G473xx.hpp"
#include "TimerPeriph.hpp"
#include "Rcc.hpp"

namespace EbikeLib {

constexpr std::array<uint32_t, 12> timer_addresses = {
		STM32LIB::TIM1_Base_Address,
		STM32LIB::TIM2_Base_Address,
		STM32LIB::TIM3_Base_Address,
		STM32LIB::TIM4_Base_Address,
		STM32LIB::TIM5_Base_Address,
		STM32LIB::TIM6_Base_Address,
		STM32LIB::TIM7_Base_Address,
		STM32LIB::TIM8_Base_Address,
		STM32LIB::TIM15_Base_Address,
		STM32LIB::TIM16_Base_Address,
		STM32LIB::TIM17_Base_Address,
		STM32LIB::TIM20_Base_Address
};

template<Timer_Periph tim>
constexpr uint32_t get_timer_base_address() {
	return timer_addresses[static_cast<uint32_t>(tim)];
}

template<Timer_Periph tim>
auto get_timer() {

	return STM32LIB::TIM<get_timer_base_address<tim>()>();
}
template<Timer_Periph tim>
uint32_t get_timer_clock() {
	if constexpr ((tim == Timer_Periph::Timer1) || (tim == Timer_Periph::Timer8) ||
			(tim == Timer_Periph::Timer15) || (tim == Timer_Periph::Timer16) || (tim == Timer_Periph::Timer17) ||
			(tim == Timer_Periph::Timer20)) {
		// APB2 timers

		return RCC_Funcs::get_apb2_timers_clock_speed();
	} else {
		return RCC_Funcs::get_apb1_timers_clock_speed();
	}
}

} // namespace EbikeLib
#endif // TIMER_HPP_
