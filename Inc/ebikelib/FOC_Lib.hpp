#ifndef FOC_LIB_HPP_
#define FOC_LIB_HPP_

#pragma once

namespace EbikeLib {

class PID {
public:
	static constexpr float DefaultKp = 0.1f;
	static constexpr float DefaultKi = 0.001f;
	static constexpr float DefaultKd = 0.0f;
	static constexpr float DefaultKc = 0.05f;
	static constexpr float DefaultPIDMin = -0.99f;
	static constexpr float DefaultPIDMax = 0.99f;

	PID() {}
	PID(float Kp, float Ki, float Kd, float Kc):
		_Kp(Kp), _Ki(Ki), _Kd(Kd), _Kc(Kc) {}

	void calc(float error);
	void reset();
	void setMin(float min) {OutMin = min;}
	void setMax(float max) {OutMax = max;}
	void setKp(float new_Kp) {_Kp = new_Kp;}
	void setKi(float new_Ki) {_Ki = new_Ki;}
	void setKd(float new_Kd) {_Kd = new_Kd;}
	void setKc(float new_Kc) {_Kc = new_Kc;}
	float getMin() {return OutMin;}
	float getMax() {return OutMax;}
	float getKp() {return _Kp;}
	float getKi() {return _Ki;}
	float getKd() {return _Kd;}
	float getKc() {return _Kc;}
	float getOutput() {return Out;}

private:
	float _Kp = DefaultKp;
	float _Ki = DefaultKi;
	float _Kd = DefaultKd;
	float _Kc = DefaultKc;
	float Ui = 0.0f;
	float Up1 = 0.0f;
	float OutMin = DefaultPIDMin;
	float OutMax = DefaultPIDMax;
	float SatErr = 0.0f;
	float Out = 0.0f;

};

class SVM {

public:

    const float ONE_HALF = 0.5f;
    const float SQRT3_OVER_2 = 0.86602650378444f;

    float tA;
    float tB;
    float tC;

    SVM():tA(0.0f), tB(0.0f), tC(0.0f) { }

    void calc(float alpha, float beta);
};

class Inverse_Park {
public:
	float Alpha;
	float Beta;

	Inverse_Park(): Alpha(0.0f), Beta(0.0f) {}

	void calc(float Ds, float Qs, float sine, float cosine);
};

class Clarke {
public:
	float Alpha;
	float Beta;

	Clarke(): Alpha(0.0f), Beta(0.0f) {}

	void calc(float As, float Bs);
};

class Park {
public:
	float Ds;
	float Qs;

	Park(): Ds(0.0f), Qs(0.0f) {}

	void calc(float Alpha, float Beta, float sine, float cosine);
};

class Biquad_Filter {
public:
	// Default constructor - explicitly assign coefficients
	Biquad_Filter(float A1, float A2, float B0, float B1, float B2) :
		_A1(A1), _A2(A2), _B0(B0), _B1(B1), _B2(B2),
		_U1(0.0f), _U2(0.0f), _Y(0.0f) {}
	// Low pass filter constructor - calculate coefficients
	// Biquad_Filter(float Fs, float f0, float Q);

	void calc(float input);
	float get();
private:
    float _A1; // Param: A1 gain (output at one delay)
    float _A2; // Param: A2 gain (output at two delays)
    float _B0; // Param: B0 gain (input, no delay)
    float _B1; // Param: B1 gain (input, one delay)
    float _B2; // Param: B2 gain (input, two delays)
    float _U1; // State: First delay register
    float _U2; // State: Second delay register
    float _Y; // Output value
};

} // namespace EbikeLib


#endif /* FOC_LIB_HPP_ */
