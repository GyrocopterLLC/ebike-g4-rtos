#ifndef ADCHELPERS_HPP_
#define ADCHELPERS_HPP_

#pragma once

#include <cstdint>
#include <array>
#include "STM32G473xx.hpp"
#include "AdcPeriph.hpp"
#include "Rcc.hpp"


namespace EbikeLib {

constexpr std::array<uint32_t, 5> adc_addresses = {
		STM32LIB::ADC1_Base_Address,
		STM32LIB::ADC2_Base_Address,
		STM32LIB::ADC3_Base_Address,
		STM32LIB::ADC4_Base_Address,
		STM32LIB::ADC5_Base_Address
};

template<ADC_Periph adc>
constexpr uint32_t get_adc_base_address() {
	return adc_addresses[static_cast<uint32_t>(adc)];
}

template<ADC_Periph adc, uint32_t channel>
void set_sampling_time(uint32_t new_samp) {
	auto adc_periph = STM32LIB::ADC<get_adc_base_address<adc>()>();

	static_assert(channel <= 18);

	if constexpr (channel == 0) {
		adc_periph.SMPR1.SMP0.set(new_samp);
	} else if constexpr (channel == 1) {
		adc_periph.SMPR1.SMP1.set(new_samp);
	} else if constexpr (channel == 2) {
		adc_periph.SMPR1.SMP2.set(new_samp);
	} else if constexpr (channel == 3) {
		adc_periph.SMPR1.SMP3.set(new_samp);
	} else if constexpr (channel == 4) {
		adc_periph.SMPR1.SMP4.set(new_samp);
	} else if constexpr (channel == 5) {
		adc_periph.SMPR1.SMP5.set(new_samp);
	} else if constexpr (channel == 6) {
		adc_periph.SMPR1.SMP6.set(new_samp);
	} else if constexpr (channel == 7) {
		adc_periph.SMPR1.SMP7.set(new_samp);
	} else if constexpr (channel == 8) {
		adc_periph.SMPR1.SMP8.set(new_samp);
	} else if constexpr (channel == 9) {
		adc_periph.SMPR1.SMP9.set(new_samp);
	} else if constexpr (channel == 10) {
		adc_periph.SMPR2.SMP10.set(new_samp);
	} else if constexpr (channel == 11) {
		adc_periph.SMPR2.SMP11.set(new_samp);
	} else if constexpr (channel == 12) {
		adc_periph.SMPR2.SMP12.set(new_samp);
	} else if constexpr (channel == 13) {
		adc_periph.SMPR2.SMP13.set(new_samp);
	} else if constexpr (channel == 14) {
		adc_periph.SMPR2.SMP14.set(new_samp);
	} else if constexpr (channel == 15) {
		adc_periph.SMPR2.SMP15.set(new_samp);
	} else if constexpr (channel == 16) {
		adc_periph.SMPR2.SMP16.set(new_samp);
	} else if constexpr (channel == 17) {
		adc_periph.SMPR2.SMP17.set(new_samp);
	} else if constexpr (channel == 18) {
		adc_periph.SMPR2.SMP18.set(new_samp);
	}
}


} // namespace EbikeLib

#endif /* ADC_HPP_ */
