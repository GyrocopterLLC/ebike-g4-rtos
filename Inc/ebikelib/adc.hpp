#ifndef ADC_HPP_
#define ADC_HPP_

typedef struct _ADC_Current_T {
	float iA;
	float iB;
	float iC;

} ADC_Current_T;

void adc_init();
void adc_get_currents(ADC_Current_T* currents);


#endif /* ADC_HPP_ */
