#ifndef RAMPGEN_HPP_
#define RAMPGEN_HPP_

#pragma once

#include <cstdint>

namespace EbikeLib {

/**
 * The frequency of the ramp is set in "per-unit" or pu. This means
 * the ramp frequency is normalized to 1. The frequency is then
 * independent of the sampling loop rate.
 *
 * Assume the sampling loop is 1Hz. Then the pu frequency is actually in
 * Hz. But in a normal use, like sampling loop = 20kHz, then the ramp
 * frequency in pu must be multiplied by the sampling loop rate to get
 * the real frequency of the output.
 *
 * Example: Freq = 0.05f (pu), Sampling Loop Rate Fs = 20000Hz
 * This Rampgen will then output a ramp with frequency = 20000*0.05 = 1000Hz
 *
 */
class Rampgen {
public:
	Rampgen(float Freq = 0.0f, float Offset = 0.0f, float Gain = 1.0f):
		Freq(Freq), Gain(Gain), Offset(Offset) {}

	void calc() {
        Angle += Freq;

        if (Angle>1.0f)
          Angle -= 2.0f;
        else if (Angle<-1.0f)
          Angle += 2.0f;

       Out = Angle*Gain + Offset;

       if (Out>1.0f)
          Out -= 2.0f;
        else if (Out<-1.0f)
          Out += 2.0f;
	}
	float get_output() {return Out;}
	void set_freq(float NewFreq) {Freq = NewFreq;}
	void set_offset(float NewOffset) {Offset = NewOffset;}
	void set_gain(float NewGain) {Gain = NewGain;}

private:
	float  Freq = 0.0f; 		// Input: Ramp frequency (pu)
	float  Angle = 0.0f;		// Variable: Step angle (pu)
	float  Gain = 1.0f;			// Input: Ramp gain (pu)
	float  Out = 0.0f;			// Output: Ramp signal (pu)
	float  Offset = 0.0f;		// Input: Ramp offset (pu)
};

} // namespace EbikeLib



#endif /* RAMPGEN_HPP_ */
