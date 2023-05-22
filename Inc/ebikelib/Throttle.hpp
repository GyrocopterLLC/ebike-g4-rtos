#ifndef THROTTLE_HPP_
#define THROTTLE_HPP_

#include "FOC_Lib.hpp"
#include <cstdint>

namespace EbikeLib {

// Filter:
// Low pass biquad
// Sampling: 20kHz
// Center: 40Hz
// Q: 0.707 (1/sqrt(2))
const float ThrottleFiltA1 = -1.98222629f;
const float ThrottleFiltA2 = 0.98238281;
const float ThrottleFiltB0 = 3.91301533e-5f;
const float ThrottleFiltB1 = 7.82603067e-5f;
const float ThrottleFiltB2 = 3.91301533e-5f;

const uint32_t ThrottleStartupDuration = 6000u; // 300ms at 20kHz

class Throttle {
public:
	Throttle() {}

	bool detectStuck(float raw_voltage);
	void process(float raw_voltage);
	float getOutput();

private:
	bool StartupDone = false;
	uint32_t StartupCount = 0;
	float RawMin = 0.9f; // Minimum raw throttle voltage - this voltage = 0%
	float RawMax = 4.0f; // Maximum raw throttle voltage - this voltage = 100%
	float ResistorRatio = 1.499f; // Multiplication factor due to resistor voltage divider
	float Hysteresis = 0.025f; // Raw throttle value needed to exceed minimum to turn on
	bool ThrottleHysteresisState = false;

	float Output; // Processed throttle value (0 to 1.0)
	Biquad_Filter ThrottleFilter{ThrottleFiltA1, ThrottleFiltA2, ThrottleFiltB0, ThrottleFiltB1, ThrottleFiltB2};

};

} // namespace EbikeLib

#endif /* THROTTLE_HPP_ */
