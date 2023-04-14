#ifndef NVICHELPERS_HPP_
#define NVICHELPERS_HPP_

#pragma once

#include <cstdint>
#include <array>
#include "STM32G473xx.hpp"

const uint32_t nvic_prio_bits = 4; // Set for STM32G473

template<uint32_t IRQn>
void set_interrupt_priority(uint8_t prio) {
	//NVIC->IP[((uint32_t)(int32_t)IRQn)] = (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
	static_assert(IRQn < 102); // FMAC_IRQn is #101, which is the last interrupt number
	auto nvic = STM32LIB::NVIC<STM32LIB::NVIC_Base_Address>();
	constexpr uint32_t offset_of_IPR_byte = nvic.IPR0_Offset + IRQn;
	uint8_t* ipr_reg = reinterpret_cast<uint8_t*>(STM32LIB::NVIC_Base_Address + offset_of_IPR_byte);

	*ipr_reg = prio << (8 - nvic_prio_bits);
}

template<uint32_t IRQn>
uint8_t get_interrupt_priority() {
	static_assert(IRQn < 102); // FMAC_IRQn is #101, which is the last interrupt number

	auto nvic = STM32LIB::NVIC<STM32LIB::NVIC_Base_Address>();
	constexpr uint32_t slot_in_IPR = IRQn % 4;

	constexpr uint32_t offset_of_IPR_byte = nvic.IPR0_Offset + IRQn;
	uint8_t* ipr_reg = reinterpret_cast<uint8_t*>(STM32LIB::NVIC_Base_Address + offset_of_IPR_byte);

	return *ipr_reg;
}

template<uint32_t IRQn>
void enable_interrupt() {
	static_assert(IRQn < 102); // FMAC_IRQn is #101, which is the last interrupt number

	auto nvic = STM32LIB::NVIC<STM32LIB::NVIC_Base_Address>();
	constexpr uint32_t bit_in_ISER = IRQn % 32;
	constexpr uint32_t which_ISER_reg = IRQn / 32;

	constexpr uint32_t base_address_of_ISER = nvic.ISER0_Offset + (which_ISER_reg);
	auto iser = reinterpret_cast<volatile uint32_t*>(STM32LIB::NVIC_Base_Address + base_address_of_ISER);

	*iser = (1ul << bit_in_ISER);
}

template<uint32_t IRQn>
void disable_interrupt() {
	static_assert(IRQn < 102); // FMAC_IRQn is #101, which is the last interrupt number

	auto nvic = STM32LIB::NVIC<STM32LIB::NVIC_Base_Address>();
	constexpr uint32_t bit_in_ICER = IRQn % 32;
	constexpr uint32_t which_ICER_reg = IRQn / 32;

	constexpr uint32_t base_address_of_ICER = nvic.ICER0_Offset + (which_ICER_reg);
	auto icer = reinterpret_cast<uint32_t*>(STM32LIB::NVIC_Base_Address + base_address_of_ICER);

	*icer = (1ul << bit_in_ICER);
}

#endif /* NVICHELPERS_HPP_ */
