#ifndef CORDIC_TYPES_HPP_
#define CORDIC_TYPES_HPP_
#pragma once

namespace STM32LIB {

enum class Cordic_Function {
	Cosine = 	0b0000,
	Sine = 		0b0001,
	Phase = 	0b0010,
	Modulus = 	0b0011,
	Arctan = 	0b0100,
	CosineH = 	0b0101,
	SineH = 	0b0110,
	ArctanH = 	0b0111,
	LogN = 		0b1000,
	Sqrt = 		0b1001
};


} // namespace STM32LIB


#endif // CORDIC_TYPES_HPP_
