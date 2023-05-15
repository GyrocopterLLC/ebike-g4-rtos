#include "FOC_Lib.hpp"

#include <cstdint>

using namespace EbikeLib;

void PID::calc(float error) {
	float OutPreSat, Up, Ud, Out;
	Up = _Kp*error; // Proportional effort
	Ui = Ui + Up*_Ki + SatErr*_Kc; // Integral effort with anti-windup
	Ud = _Kd * (Up - Up1); // Derivative effort
	OutPreSat = Up + Ui + Ud;
	// Clamp to min / max
	if(OutPreSat > OutMax) {
		Out = OutMax;
	}
	else if(OutPreSat < OutMin) {
		Out = OutMin;
	}
	else {
		Out = OutPreSat;
	}
	SatErr = Out - OutPreSat;
	Up1 = Up;
}

void PID::reset() {
	Ui = 0.0f;
	SatErr = 0.0f;
	Up1 = 0.0f;
}

void SVM::calc(float alpha, float beta) {

	// Sector determination
	uint8_t sector = 0;
	float X, Y, Z, T1, T2;
	X = beta;
	Y = (-ONE_HALF) * beta - SQRT3_OVER_2 * alpha;
	Z = (-ONE_HALF) * beta + SQRT3_OVER_2 * alpha;

	if (X > 0)
		sector += 1;
	if (Y > 0)
		sector += 2;
	if (Z > 0)
		sector += 4;

	// Timing assignments
	switch (sector) {
	case 5: // Sector 1
		T1 = Z;
		T2 = X;
		tC = (ONE_HALF * (1 - T1 - T2));
		tB = tC + T2;
		tA = tB + T1;
		break;
	case 1: // Sector 2
		T1 = -Y;
		T2 = -Z;
		tC = (ONE_HALF * (1 - T1 - T2));
		tA = tC + T1;
		tB = tA + T2;
		break;
	case 3: // Sector 3
		T1 = X;
		T2 = Y;
		tA = (ONE_HALF * (1 - T1 - T2));
		tC = tA + T2;
		tB = tC + T1;
		break;
	case 2: // Sector 4
		T1 = -Z;
		T2 = -X;
		tA = (ONE_HALF * (1 - T1 - T2));
		tB = tA + T1;
		tC = tB + T2;
		break;
	case 6: // Sector 5
		T1 = Y;
		T2 = Z;
		tB = (ONE_HALF * (1 - T1 - T2));
		tA = tB + T2;
		tC = tA + T1;
		break;
	case 4: // Sector 6
		T1 = -X;
		T2 = -Y;
		tB = (ONE_HALF * (1 - T1 - T2));
		tC = tB + T1;
		tA = tC + T2;
		break;
	default:
		tA = ONE_HALF;
		tB = ONE_HALF;
		tC = ONE_HALF;
		break;
	}

	// Clamp our outputs to [0, +1]
	if(tA < 0.0f) tA = 0.0f;
	if(tB < 0.0f) tB = 0.0f;
	if(tC < 0.0f) tC = 0.0f;
	if(tA >= 1.0f) tA = 1.0f;
	if(tB >= 1.0f) tB = 1.0f;
	if(tC >= 1.0f) tC = 1.0f;
}

void Inverse_Park::calc(float d, float q, float sine, float cosine) {
	Alpha = d*cosine - q*sine;
	Beta = q*cosine + d*sine;
}

const float ONE_OVER_SQRT3 = 0.5773502691896f;
void Clarke::calc(float As, float Bs) {
	Alpha = As;
	Beta = (As + 2.0f*Bs)*ONE_OVER_SQRT3;
}

void Park::calc(float Alpha, float Beta, float sine, float cosine) {
	Ds = Alpha*cosine + Beta*sine;
	Qs = Beta*cosine - Alpha*sine;
}

void Biquad_Filter::calc(float input) {
    // Calculate intermediate value
    float intermed = (input) - (_U1 * _A1) - (_U2 * _A2);
    // Calculate output value
    float output = (intermed * _B0) + (_U1 * _B1) + (_U2 * _B2);
    // Update stored values
    _U2 = _U1;
    _U1 = intermed;

    _Y = output;
}

float Biquad_Filter::get() {
	return _Y;
}

/*
Biquad_Filter::Biquad_Filter(float Fs, float f0, float Q) {
    // Intermediate values
    float w0, sinw0, cosw0, alpha;
    // Cancel operation if inputs are invalid
    if ((Fs == 0.0f) || (f0 == 0.0f) || (Q == 0.0f)) {
        B2 = B1 = B0 = A2 = A1 = 0.0f;
    } else {
    	// Calculate the intermediates
    	w0 = 2.0f * (f0 / Fs); // Leaving out PI, the CORDIC input is scaled by 1/PI anyway
    	// Convert angle from 0->2pi to -pi->+pi
    	if(w0 > 1.0f) w0 = w0 - 2.0f;

		//CORDIC_CalcSinCosDeferred_Def(w0);
		//CORDIC_GetResults_Def(sinw0, cosw0);
	//    CORDIC_CalcSinCos(w0, &sinw0, &cosw0);

	 // Need to use slower arm_math sin/cos function

		arm_sin_cos_f32(w0, &sinw0, &cosw0);
		alpha = sinw0 / (2.0f * Q);

		// Calculate the filter constants
		B0 = (1.0f - cosw0) / (2.0f) / (1.0f + alpha);
		B1 = (1.0f - cosw0) / (1.0f + alpha);
		B2 = biq->B0;
		A1 = ((-2.0f) * cosw0) / (1.0f + alpha);
		A2 = (1.0f - alpha) / (1.0f + alpha);
    }
}
*/
