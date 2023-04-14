#ifndef RCC_TYPES_HPP_
#define RCC_TYPES_HPP_
#pragma once

namespace STM32LIB {

enum class RCC_System_Clock {
	HSI16 = 0b01,
	HSE = 0b10,
	PLL = 0b11
};

enum class RCC_MCO_Prescaler {
	Div1 = 0b000,
	Div2 = 0b001,
	Div4 = 0b010,
	Div8 = 0b011,
	Div16 = 0b100
};

enum class RCC_MCO_Select {
	Disabled = 0b0000,
	Sysclk = 0b0001,
	HSI16 = 0b0011,
	HSE = 0b0100,
	MainPLL = 0b0101,
	LSI = 0b0110,
	LSE = 0b0111,
	HSI48 = 0b1000
};

enum class RCC_APB_Prescaler {
	Div1 = 0b000,
	Div2 = 0b100,
	Div4 = 0b101,
	Div8 = 0b110,
	Div16 = 0b111
};

enum class RCC_AHB_Prescaler {
	Div1 = 0b0000,
	Div2 = 0b1000,
	Div4 = 0b1001,
	Div8 = 0b1010,
	Div16 = 0b1011,
	Div64 = 0b1100,
	Div128 = 0b1101,
	Div256 = 0b1110,
	Div512 = 0b1111
};


enum class RCC_PLL_Source {
	None = 0b00,
	HSI16 = 0b10,
	HSE = 0b11
};

} // namespace STM32LIB

#endif // RCC_TYPES_HPP_
