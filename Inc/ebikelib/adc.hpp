#ifndef ADC_HPP_
#define ADC_HPP_

#pragma once

#include "DRV8353.hpp"

struct ADC_Current_T {
	float iA;
	float iB;
	float iC;

};

struct ADC_Voltage_T {
	float vA;
	float vB;
	float vC;
};

void adc_init();
void adc_get_currents(ADC_Current_T* currents);
void adc_get_scaled_currents(ADC_Current_T* currents);
void adc_get_voltages(ADC_Voltage_T* voltages);
void adc_get_scaled_voltages(ADC_Voltage_T* voltages);
float adc_get_throttle();
float adc_get_scaled_throttle();
void adc_calibrate_currents(EbikeLib::DRV8353* drv);

#endif /* ADC_HPP_ */
