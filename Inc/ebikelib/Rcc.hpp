#ifndef RCC_HPP_
#define RCC_HPP_
#pragma once

#include <cstdint>
#include "STM32G473xx.hpp"
#include "TimerPeriph.hpp"
#include "Gpio.hpp"

#if !defined  (HSE_VALUE)
  #define HSE_VALUE     8000000U /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    16000000U /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

namespace EbikeLib {

class RCC_Funcs {
public:

	template<EbikeLib::Timer_Periph tim>
	static void start_timer_clock() {
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
		if constexpr (tim == Timer_Periph::Timer1) {
			rcc.APB2ENR.TIM1EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer2) {
			rcc.APB1ENR1.TIM2EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer3) {
			rcc.APB1ENR1.TIM3EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer4) {
			rcc.APB1ENR1.TIM4EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer5) {
			rcc.APB1ENR1.TIM5EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer6) {
			rcc.APB1ENR1.TIM6EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer7) {
			rcc.APB1ENR1.TIM7EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer8) {
			rcc.APB2ENR.TIM8EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer15) {
			rcc.APB2ENR.TIM15EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer16) {
			rcc.APB2ENR.TIM16EN.set(true);
		} else if constexpr (tim == Timer_Periph::Timer17) {
			rcc.APB2ENR.TIM17EN.set(true);
		} else {
			rcc.APB2ENR.TIM20EN.set(true);
		}
	}

	template<Gpio_Port gport>
	static void start_gpio_clock() {
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
		if constexpr (gport == Gpio_Port::GPIO_A) {
			rcc.AHB2ENR.GPIOAEN.set(true);
		}
		if constexpr (gport == Gpio_Port::GPIO_B) {
			rcc.AHB2ENR.GPIOBEN.set(true);
		}
		if constexpr (gport == Gpio_Port::GPIO_C) {
			rcc.AHB2ENR.GPIOCEN.set(true);
		}
		if constexpr (gport == Gpio_Port::GPIO_D) {
			rcc.AHB2ENR.GPIODEN.set(true);
		}
		if constexpr (gport == Gpio_Port::GPIO_E) {
			rcc.AHB2ENR.GPIOEEN.set(true);
		}
		if constexpr (gport == Gpio_Port::GPIO_F) {
			rcc.AHB2ENR.GPIOFEN.set(true);
		}
		if constexpr (gport == Gpio_Port::GPIO_G) {
			rcc.AHB2ENR.GPIOGEN.set(true);
		}
	}
	static uint32_t get_sysclk_speed() {
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();

		uint32_t sysclk = 0, pllsrc = 0;
		// Determine clock source (SYSCLK)
		switch (rcc.CFGR.SWS.get()) {

		case STM32LIB::RCC_System_Clock::HSI16:
			sysclk = HSI_VALUE;
			break;
		case STM32LIB::RCC_System_Clock::HSE:
			sysclk = HSE_VALUE;
			break;
		case STM32LIB::RCC_System_Clock::PLL:
			// Now it's a little more complicated
			// What's the PLL source?
			switch (rcc.PLLCFGR.PLLSRC.get()) {
			case STM32LIB::RCC_PLL_Source::HSE:
				pllsrc = HSE_VALUE;
				break;
			case STM32LIB::RCC_PLL_Source::HSI16:
				pllsrc = HSI_VALUE;
				break;
			case STM32LIB::RCC_PLL_Source::None:
				pllsrc = 0; // This really shouldn't happen
				break;
			}

			// Get the multipliers from PLL
			// PLL output 'R', which goes to sysclk, is calculated by:
			// R = input * Nmult / (Mdiv * Rdiv)
			// Mdiv is the input divider, before the PLL
			// Nmult is the PLL multiplier
			// and Rdiv is the output divider

			sysclk = pllsrc * rcc.PLLCFGR.PLLN.get()
					/ (rcc.PLLCFGR.PLLM.get() + 1);
			switch (rcc.PLLCFGR.PLLR.get()) {
			case 0:
				sysclk = sysclk / 2;
				break;
			case 1:
				sysclk = sysclk / 4;
				break;
			case 2:
				sysclk = sysclk / 6;
				break;
			case 3:
				sysclk = sysclk / 8;
				break;
			}

			break;

		}

		return sysclk;
	}

	static uint32_t get_ahb_clock_speed() {
		uint32_t sysclk = get_sysclk_speed();
		uint32_t hclk = 0;
		// Division factor for AHB: divides from 1 to 512
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
		switch(rcc.CFGR.HPRE.get()) {
		case STM32LIB::RCC_AHB_Prescaler::Div1:
			hclk = sysclk;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div2:
			hclk = sysclk / 2u;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div4:
			hclk = sysclk / 4u;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div8:
			hclk = sysclk / 8u;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div16:
			hclk = sysclk / 16u;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div64:
			hclk = sysclk / 64u;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div128:
			hclk = sysclk / 128u;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div256:
			hclk = sysclk / 256u;
			break;
		case STM32LIB::RCC_AHB_Prescaler::Div512:
			hclk = sysclk / 512u;
			break;
		}

		return hclk;
	}

	static uint32_t get_apb2_clock_speed() {
		uint32_t sysclk = get_sysclk_speed();
		uint32_t apb2clk = 0;

		// Division factor for APB: divides from 1 to 16
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
		switch(rcc.CFGR.PPRE2.get()) {
		case STM32LIB::RCC_APB_Prescaler::Div1:
			apb2clk = sysclk;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div2:
			apb2clk = sysclk / 2u;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div4:
			apb2clk = sysclk / 4u;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div8:
			apb2clk = sysclk / 8u;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div16:
			apb2clk = sysclk / 16u;
			break;
		}

		return apb2clk;
	}

	static uint32_t get_apb1_clock_speed() {
		uint32_t sysclk = get_sysclk_speed();
		uint32_t apb1clk = 0;

		// Division factor for APB: divides from 1 to 16
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
		switch(rcc.CFGR.PPRE1.get()) {
		case STM32LIB::RCC_APB_Prescaler::Div1:
			apb1clk = sysclk;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div2:
			apb1clk = sysclk / 2u;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div4:
			apb1clk = sysclk / 4u;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div8:
			apb1clk = sysclk / 8u;
			break;
		case STM32LIB::RCC_APB_Prescaler::Div16:
			apb1clk = sysclk / 16u;
			break;
		}

		return apb1clk;
	}

	static uint32_t get_apb2_timers_clock_speed() {
		// If APB2 divider is /2 or more, then the timer is x2 the APB2 clock
		// Otherwise, it is the same as the clock
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
		if(rcc.CFGR.PPRE2.get() == STM32LIB::RCC_APB_Prescaler::Div1) {
			return get_apb2_clock_speed();
		} else {
			return 2*get_apb2_clock_speed();
		}
	}

	static uint32_t get_apb1_timers_clock_speed() {
		auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
		if(rcc.CFGR.PPRE1.get() == STM32LIB::RCC_APB_Prescaler::Div1) {
			return get_apb1_clock_speed();
		} else {
			return 2*get_apb1_clock_speed();
		}
	}


}; // class RCC_Funcs
} // namespace EbikeLib

#endif // RCC_HPP_
