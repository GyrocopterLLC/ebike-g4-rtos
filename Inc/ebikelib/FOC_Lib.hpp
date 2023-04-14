#ifndef FOC_LIB_HPP_
#define FOC_LIB_HPP_

#pragma once

namespace EbikeLib {

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


} // namespace EbikeLib


#endif /* FOC_LIB_HPP_ */
