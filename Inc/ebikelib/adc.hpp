#ifndef ADC_HPP_
#define ADC_HPP_

#pragma once

#include "DRV8353.hpp"

typedef struct _ADC_Current_T {
	float iA;
	float iB;
	float iC;

} ADC_Current_T;

void adc_init();
void adc_get_currents(ADC_Current_T* currents);
void adc_calibrate_currents(EbikeLib::DRV8353* drv);

#endif /* ADC_HPP_ */
