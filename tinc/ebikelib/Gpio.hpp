#ifndef GPIO_HPP_
#define GPIO_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"
#include "STM32G473xx.hpp"
#include <array>

namespace EbikeLib {

enum class Gpio_Port {
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F,
	GPIO_G
};

template<Gpio_Port gp>
void enable_gpio_clock() {
	auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
	if constexpr (gp == Gpio_Port::GPIO_A) {
		rcc.AHB2ENR.GPIOAEN.set(true);
	} else if constexpr (gp == Gpio_Port::GPIO_B) {
		rcc.AHB2ENR.GPIOBEN.set(true);
	} else if constexpr (gp == Gpio_Port::GPIO_C) {
		rcc.AHB2ENR.GPIOCEN.set(true);
	} else if constexpr (gp == Gpio_Port::GPIO_D) {
		rcc.AHB2ENR.GPIODEN.set(true);
	} else if constexpr (gp == Gpio_Port::GPIO_E) {
		rcc.AHB2ENR.GPIOEEN.set(true);
	} else if constexpr (gp == Gpio_Port::GPIO_F) {
		rcc.AHB2ENR.GPIOFEN.set(true);
	} else {
		rcc.AHB2ENR.GPIOGEN.set(true);
	}
}


template<Gpio_Port gp>
constexpr uint32_t get_gpio_base_address() {
	if constexpr (gp == Gpio_Port::GPIO_A) {
		return STM32LIB::GPIOA_Base_Address;
	} else if constexpr (gp == Gpio_Port::GPIO_B) {
		return STM32LIB::GPIOB_Base_Address;
	} else if constexpr (gp == Gpio_Port::GPIO_C) {
		return STM32LIB::GPIOC_Base_Address;
	} else if constexpr (gp == Gpio_Port::GPIO_D) {
		return STM32LIB::GPIOD_Base_Address;
	} else if constexpr (gp == Gpio_Port::GPIO_E) {
		return STM32LIB::GPIOE_Base_Address;
	} else if constexpr (gp == Gpio_Port::GPIO_F) {
		return STM32LIB::GPIOF_Base_Address;
	} else {
		return STM32LIB::GPIOG_Base_Address;
	}
}

template<Gpio_Port gp>
auto get_gpio() {

	return STM32LIB::GPIO<get_gpio_base_address<gp>()>();
}

template<Gpio_Port gport, uint16_t gpin, STM32LIB::GPIO_Mode mode>
void gpio_mode() {
	static_assert(gpin <= 15);

	auto gperiph = get_gpio<gport>();
	if constexpr(gpin == 0) {
		gperiph.MODER.MODER0.set(mode);
	} else if constexpr(gpin == 1) {
		gperiph.MODER.MODER1.set(mode);
	} else if constexpr(gpin == 2) {
		gperiph.MODER.MODER2.set(mode);
	} else if constexpr(gpin == 3) {
		gperiph.MODER.MODER3.set(mode);
	} else if constexpr(gpin == 4) {
		gperiph.MODER.MODER4.set(mode);
	} else if constexpr(gpin == 5) {
		gperiph.MODER.MODER5.set(mode);
	} else if constexpr(gpin == 6) {
		gperiph.MODER.MODER6.set(mode);
	} else if constexpr(gpin == 7) {
		gperiph.MODER.MODER7.set(mode);
	} else if constexpr(gpin == 8) {
		gperiph.MODER.MODER8.set(mode);
	} else if constexpr(gpin == 9) {
		gperiph.MODER.MODER9.set(mode);
	} else if constexpr(gpin == 10) {
		gperiph.MODER.MODER10.set(mode);
	} else if constexpr(gpin == 11) {
		gperiph.MODER.MODER11.set(mode);
	} else if constexpr(gpin == 12) {
		gperiph.MODER.MODER12.set(mode);
	} else if constexpr(gpin == 13) {
		gperiph.MODER.MODER13.set(mode);
	} else if constexpr(gpin == 14) {
		gperiph.MODER.MODER14.set(mode);
	} else if constexpr(gpin == 15) {
		gperiph.MODER.MODER15.set(mode);
	}
}

template<Gpio_Port gport, uint16_t gpin, STM32LIB::GPIO_Pull pull>
void gpio_pull() {
	static_assert(gpin <= 15);

	auto gperiph = get_gpio<gport>();
	if constexpr(gpin == 0) {
		gperiph.PUPDR.PUPDR0.set(pull);
	} else if constexpr(gpin == 1) {
		gperiph.PUPDR.PUPDR1.set(pull);
	} else if constexpr(gpin == 2) {
		gperiph.PUPDR.PUPDR2.set(pull);
	} else if constexpr(gpin == 3) {
		gperiph.PUPDR.PUPDR3.set(pull);
	} else if constexpr(gpin == 4) {
		gperiph.PUPDR.PUPDR4.set(pull);
	} else if constexpr(gpin == 5) {
		gperiph.PUPDR.PUPDR5.set(pull);
	} else if constexpr(gpin == 6) {
		gperiph.PUPDR.PUPDR6.set(pull);
	} else if constexpr(gpin == 7) {
		gperiph.PUPDR.PUPDR7.set(pull);
	} else if constexpr(gpin == 8) {
		gperiph.PUPDR.PUPDR8.set(pull);
	} else if constexpr(gpin == 9) {
		gperiph.PUPDR.PUPDR9.set(pull);
	} else if constexpr(gpin == 10) {
		gperiph.PUPDR.PUPDR10.set(pull);
	} else if constexpr(gpin == 11) {
		gperiph.PUPDR.PUPDR11.set(pull);
	} else if constexpr(gpin == 12) {
		gperiph.PUPDR.PUPDR12.set(pull);
	} else if constexpr(gpin == 13) {
		gperiph.PUPDR.PUPDR13.set(pull);
	} else if constexpr(gpin == 14) {
		gperiph.PUPDR.PUPDR14.set(pull);
	} else if constexpr(gpin == 15) {
		gperiph.PUPDR.PUPDR15.set(pull);
	}
}

template<Gpio_Port gport, uint16_t gpin, STM32LIB::GPIO_Speed speed>
void gpio_speed() {
	static_assert(gpin <= 15);

	auto gperiph = get_gpio<gport>();
	if constexpr(gpin == 0) {
		gperiph.OSPEEDR.OSPEEDR0.set(speed);
	} else if constexpr(gpin == 1) {
		gperiph.OSPEEDR.OSPEEDR1.set(speed);
	} else if constexpr(gpin == 2) {
		gperiph.OSPEEDR.OSPEEDR2.set(speed);
	} else if constexpr(gpin == 3) {
		gperiph.OSPEEDR.OSPEEDR3.set(speed);
	} else if constexpr(gpin == 4) {
		gperiph.OSPEEDR.OSPEEDR4.set(speed);
	} else if constexpr(gpin == 5) {
		gperiph.OSPEEDR.OSPEEDR5.set(speed);
	} else if constexpr(gpin == 6) {
		gperiph.OSPEEDR.OSPEEDR6.set(speed);
	} else if constexpr(gpin == 7) {
		gperiph.OSPEEDR.OSPEEDR7.set(speed);
	} else if constexpr(gpin == 8) {
		gperiph.OSPEEDR.OSPEEDR8.set(speed);
	} else if constexpr(gpin == 9) {
		gperiph.OSPEEDR.OSPEEDR9.set(speed);
	} else if constexpr(gpin == 10) {
		gperiph.OSPEEDR.OSPEEDR10.set(speed);
	} else if constexpr(gpin == 11) {
		gperiph.OSPEEDR.OSPEEDR11.set(speed);
	} else if constexpr(gpin == 12) {
		gperiph.OSPEEDR.OSPEEDR12.set(speed);
	} else if constexpr(gpin == 13) {
		gperiph.OSPEEDR.OSPEEDR13.set(speed);
	} else if constexpr(gpin == 14) {
		gperiph.OSPEEDR.OSPEEDR14.set(speed);
	} else if constexpr(gpin == 15) {
		gperiph.OSPEEDR.OSPEEDR15.set(speed);
	}
}

template<Gpio_Port gport, uint16_t gpin, uint16_t alt_func>
void gpio_af() {
	static_assert(gpin <= 15);
	static_assert(alt_func <= 15);

	auto gperiph = get_gpio<gport>();
	if constexpr(gpin == 0) {
			gperiph.AFRL.AFRL0.set(alt_func);
		} else if constexpr(gpin == 1) {
			gperiph.AFRL.AFRL1.set(alt_func);
		} else if constexpr(gpin == 2) {
			gperiph.AFRL.AFRL2.set(alt_func);
		} else if constexpr(gpin == 3) {
			gperiph.AFRL.AFRL3.set(alt_func);
		} else if constexpr(gpin == 4) {
			gperiph.AFRL.AFRL4.set(alt_func);
		} else if constexpr(gpin == 5) {
			gperiph.AFRL.AFRL5.set(alt_func);
		} else if constexpr(gpin == 6) {
			gperiph.AFRL.AFRL6.set(alt_func);
		} else if constexpr(gpin == 7) {
			gperiph.AFRL.AFRL7.set(alt_func);
		} else if constexpr(gpin == 8) {
			gperiph.AFRH.AFRH8.set(alt_func);
		} else if constexpr(gpin == 9) {
			gperiph.AFRH.AFRH9.set(alt_func);
		} else if constexpr(gpin == 10) {
			gperiph.AFRH.AFRH10.set(alt_func);
		} else if constexpr(gpin == 11) {
			gperiph.AFRH.AFRH11.set(alt_func);
		} else if constexpr(gpin == 12) {
			gperiph.AFRH.AFRH12.set(alt_func);
		} else if constexpr(gpin == 13) {
			gperiph.AFRH.AFRH13.set(alt_func);
		} else if constexpr(gpin == 14) {
			gperiph.AFRH.AFRH14.set(alt_func);
		} else if constexpr(gpin == 15) {
			gperiph.AFRH.AFRH15.set(alt_func);
		}
}

template<Gpio_Port gport, uint16_t gpin>
void gpio_set(bool true_is_high) {
	static_assert(gpin <= 15);

	auto gperiph = get_gpio<gport>();
	if(true_is_high) {
		gperiph.BSRR.set(1 << gpin);
	} else {
		gperiph.BRR.set(1 << gpin);
	}
}

template<Gpio_Port gport, uint16_t gpin>
bool gpio_get() {
	static_assert(gpin <= 15);

	auto gperiph = get_gpio<gport>();
	uint32_t idr = gperiph.IDR.get();
	return ((idr & (1 << gpin)) != 0);
}

} // namespace EbikeLib

#endif // GPIO_HPP_
