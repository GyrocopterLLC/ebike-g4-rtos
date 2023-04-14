#ifndef CORDIC_TRIG_HPP_
#define CORDIC_TRIG_HPP_

#pragma once

#include <cstdint>

namespace EbikeLib{



class Cordic {
public:
	Cordic();

	void set(uint32_t angle);

	__attribute__((noinline))
	uint32_t get();

	__attribute__((noinline))
	void sine_cosine(uint32_t* sine, uint32_t* cosine);
};


} // namespace EbikeLib

#endif /* CORDIC_TRIG_HPP_ */
