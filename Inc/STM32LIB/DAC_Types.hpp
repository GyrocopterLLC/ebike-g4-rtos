#ifndef DAC_TYPES_HPP_
#define DAC_TYPES_HPP_
#pragma once

namespace STM32LIB {

enum class DAC_Wave_Select {
	Disabled = 0b00,
	Noise = 0b01,
	Triangle = 0b10,
	Sawtooth = 0b11
};

enum class DAC_Mode {
	Normal_Buffer_Enabled_External_Pin = 0b000,
	Normal_Buffer_Enabled_External_Pin_and_Peripherals = 0b001,
	Normal_Buffer_Disabled_External_Pin = 0b010,
	Normal_Buffer_Disabled_Peripherals = 0b011,
	SampleHold_Buffer_Enabled_External_Pin = 0b100,
	SampleHold_Buffer_Enabled_External_Pin_and_Peripherals = 0b101,
	SampleHold_Buffer_Disabled_External_Pin_and_Peripherals = 0b110,
	SampleHold_Buffer_Disabled_Peripherals = 0b111
};

enum class DAC_High_Frequency_Mode {
	Disabled = 0b00,
	Enabled_Over_80MHz = 0b01,
	Enabled_Over_160MHz = 0b10
};

} // namespace STM32LIB


#endif // DAC_TYPES_HPP_
