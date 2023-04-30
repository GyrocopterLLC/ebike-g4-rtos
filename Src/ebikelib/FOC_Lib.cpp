#include "FOC_Lib.hpp"

#include <cstdint>

using namespace EbikeLib;

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

