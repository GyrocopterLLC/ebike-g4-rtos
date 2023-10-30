#ifndef PIN_HPP_
#define PIN_HPP_
#pragma once

#include "Gpio.hpp"

namespace EbikeLib {

struct Pin {
	Gpio_Port Port;
	uint16_t Num;
};


} // namespace EbikeLib

#endif // PIN_HPP_
