#ifndef RAMPCONTROL_HPP_
#define RAMPCONTROL_HPP_

#include <cstdint>
#include <cmath>

namespace EbikeLib {

/**
 * Target output is in per-unit, so make sure to scale it later to units of your choosing.
 * Generally it should be scaled from a maximum of +/- 1.0.
 * Rate is also per-unit. Will be based on the rate at which this function is called.
 * Rate means "1 divided by the number of calls of this function until Target is reached"
 *
 * Example: you want to reach the target in 10 seconds, and the calling frequency is 20kHz
 * In per-unit, the period is 10*20,000. The rate is 1/(10*20,000) = 0.000005.
 * E.g. it will take 200,000 calls to hit the target value (1 / 0.000005 = 200,000).
 */
class RampControl {
public:
	RampControl(float Target = 0.0f, float Rate = 0.0000305f, float LowLim = -1.0f, float HighLim = 1.0f) :
		TargetValue(Target), RampRate(Rate*Target), RampLowLimit(LowLim), RampHighLimit(HighLim) {}

	void calc() {
		if(!EqualFlag) {
			if(TargetValue > SetpointValue) {
				SetpointValue += RampRate;
				if(SetpointValue > RampHighLimit) {
					SetpointValue = RampHighLimit;
				}
				if(SetpointValue >= TargetValue) {
					// If we hit or passed the target, clamp the output
					// and set the EqualFlag to show we are done ramping
					SetpointValue = TargetValue;
					EqualFlag = true;
				}

			} else {
				SetpointValue -= RampRate;
				if(SetpointValue < RampLowLimit) {
					SetpointValue = RampLowLimit;
				}
				if(SetpointValue <= TargetValue) {
					SetpointValue = TargetValue;
					EqualFlag = true;
				}
			}
		}
	}

	float get_output() { return SetpointValue; }

	void set_target(float NewTarget) {
		if(NewTarget != TargetValue) {
			TargetValue = NewTarget;
			EqualFlag = false;
		}
	}

private:
	float  TargetValue = 0.0f; 		// Input: Target input (pu)
	float  RampRate = 0.0000305f;	// Parameter: Rate / slope of the change in Setpoint (pu)
	float  RampLowLimit = -1.0f;	// Parameter: Minimum limit (pu)
	float  RampHighLimit = 1.0f;	// Parameter: Maximum limit (pu)
	float  SetpointValue = 0.0f;	// Output: Target output (pu)
	bool   EqualFlag = false;		// Output: Flag output (bool)
};

} // namespace EbikeLib



#endif /* RAMPCONTROL_HPP_ */
