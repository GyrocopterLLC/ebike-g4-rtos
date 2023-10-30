#include <cstdint>
#include "Throttle.hpp"
#include "FOC_Lib.hpp"

using namespace EbikeLib;

bool Throttle::detectStuck(float raw_voltage) {
	// Check if we have already completed startup.
	if(!StartupDone) {
		// Check if throttle is below minimum for a required
		// number of counts
		if(raw_voltage > (RawMin + (Hysteresis / 2.0f))) {
			StartupCount = 0;
		} else {
			StartupCount++;
			if(StartupCount > ThrottleStartupDuration) {
				StartupDone = true;
			}
		}
	}
	return StartupDone;
}

void Throttle::process(float raw_voltage){
	raw_voltage = raw_voltage * ResistorRatio;
	// Clamp to maximum, don't want over 100% throttle. Who knows what demons that would summon.
	if(raw_voltage > RawMax) {
		raw_voltage = RawMax;
	}
	if(!detectStuck(raw_voltage)) {
		Output = 0.0f;
	} else {
		// Calculate filtered output
		ThrottleFilter.calc(raw_voltage);
		// Hysteresis - check if we need to change state
		if(ThrottleHysteresisState) {
			if(ThrottleFilter.get() <= RawMin) {
				ThrottleHysteresisState = false;
			}
		} else {
			if(ThrottleFilter.get() >= (RawMin + Hysteresis)) {
				ThrottleHysteresisState = true;
			}
		}
		if(!ThrottleHysteresisState) {
			Output = 0.0f;
		} else {
			// Scaling between min and max
			Output = (ThrottleFilter.get() - RawMin) / (RawMax - RawMin);
		}
	}
}

float Throttle::getOutput() {
	return Output;
}

