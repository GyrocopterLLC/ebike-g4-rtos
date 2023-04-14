#ifndef GPIO_TYPES_HPP_
#define GPIO_TYPES_HPP_
#pragma once

namespace STM32LIB {

enum class GPIO_Mode {
	Input = 0b00,
	Output = 0b01,
	Alternate_Function = 0b10,
	Analog = 0b11
};

enum class GPIO_Speed {
	Low = 0b00,
	Medium = 0b01,
	High = 0b10,
	Very_High = 0b11
};

enum class GPIO_Pull {
	None = 0b00,
	Up = 0b01,
	Down = 0b10
};

} // namespace STM32LIB

#endif // GPIO_TYPES_HPP_
