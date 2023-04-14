#ifndef TIMER_TYPES_HPP_
#define TIMER_TYPES_HPP_
#pragma once

namespace STM32LIB {

enum class CR1_Alignment_Mode {
	Edge_Aligned = 0,
	Center_Mode_1 = 1,
	Center_Mode_2 = 2,
	Center_Mode_3 = 3
};

enum class CR1_Clock_Division {
	Kernel_Clock = 0,
	Kernel_Clock_x2 = 1,
	Kernel_Clock_x4 = 2
};

enum class CR2_Main_Mode {
	Reset = 0b000,
	Enable = 0b001,
	Update = 0b010,
	Compare_Pulse = 0b011,
	Compare_oc1refc = 0b100,
	Compare_oc2refc = 0b101,
	Compare_oc3refc = 0b110,
	Compare_oc4refc = 0b111
};

enum class CR2_Main_Mode_2 {
	Reset = 0b0000,
	Enable = 0b0001,
	Update = 0b0010,
	Compare_Pulse = 0b0011,
	Compare_oc1refc = 0b0100,
	Compare_oc2refc = 0b0101,
	Compare_oc3refc = 0b0110,
	Compare_oc4refc = 0b0111,
	Compare_oc5refc = 0b1000,
	Compare_oc6refc = 0b1001,
	Compare_Pulse_oc4 = 0b1010,
	Compare_Pulse_oc6 = 0b1011,
	Compare_Pulse_oc4_or_oc6_rising = 0b1100,
	Compare_Pulse_oc4_rising_or_oc6_falling = 0b1101,
	Compare_Pulse_oc5_or_oc6_rising = 0b1110,
	Compare_Pulse_oc5_rising_or_oc6_falling = 0b1111
};

enum class Timer_Filter { // Re-used in multiple registers
	None = 0b0000,
	Sampling_Ker_N2 = 0b0001,
	Sampling_Ker_N4 = 0b0010,
	Sampling_Ker_N8 = 0b0011,
	Sampling_DTS_Div2_N6 = 0b0100,
	Sampling_DTS_Div2_N8 = 0b0101,
	Sampling_DTS_Div4_N6 = 0b0110,
	Sampling_DTS_Div4_N8 = 0b0111,
	Sampling_DTS_Div8_N6 = 0b1000,
	Sampling_DTS_Div8_N8 = 0b1001,
	Sampling_DTS_Div16_N5 = 0b1010,
	Sampling_DTS_Div16_N6 = 0b1011,
	Sampling_DTS_Div16_N8 = 0b1100,
	Sampling_DTS_Div32_N5 = 0b1101,
	Sampling_DTS_Div32_N6 = 0b1110,
	Sampling_DTS_Div32_N8 = 0b1111
};

// Used when SMCR SMS[3] = 0
enum class SMCR_Secondary_Mode_Selection {
	Disabled = 0b000,
	Quadrature_Encoder_Mode_1 = 0b001,
	Quadrature_Encoder_Mode_2 = 0b010,
	Quadrature_Encoder_Mode_3 = 0b011,
	Reset = 0b100,
	Gated = 0b101,
	Trigger = 0b110,
	External_Clock = 0b111
};

// Used when SMCR SMS[3] = 1
enum class SMCR_Secondary_Mode_Selection_Alt {
	Reset_And_Trigger = 0b000,
	Gated_And_Reset = 0b001,
	Encoder_Mode_1 = 0b010,
	Encoder_Mode_2 = 0b011,
	Encoder_Mode_3 = 0b100,
	Encoder_Mode_4 = 0b101,
	Quadrature_Encoder_Mode_4 = 0b110,
	Quadrature_Encoder_Mode_5 = 0b111
};

enum class SMCR_External_Trigger_Prescaler {
	Off = 0b00,
	Div2 = 0b01,
	Div4 = 0b10,
	Div8 = 0b11
};

enum class CCMR_Capture_Compare_Selection {
	Output = 0b00,
	Input_IC_Match = 0b01, // IC1 = TI1, IC2 = TI2, etc
	Input_IC_Cross = 0b10, // IC1 and IC2 cross over, IC3 and IC4 cross over
	Input_TRC = 0b11
};

enum class CCMR_Input_Prescaler {
	Capture_Every_Event = 0b00,
	Capture_Every_2nd_Event = 0b01,
	Capture_Every_4th_Event = 0b10,
	Capture_Every_8th_Event = 0b11
};

// The output compare mode has 2 bit regions, one is the lower 3 bits and the
// final 4th bit is placed much higher
// Due to this, it is difficult to combine the OCxM into a 4 bit field
// Instead, the lower 3 bits are a bitfield and the upper bit is just a single bit
// Two enum classes are provided. The default is for OCxM[3] = 0. The secondary
// is for OCxM[3] = 1
// Use static_cast<> to convert the secondary mode to the primary, or vice versa
enum class CCMR_Output_Compare_Mode {
	Frozen = 0b000,
	Active_On_Match = 0b001,
	Inactive_On_Match = 0b010,
	Toggle_On_Match = 0b011,
	Force_Inactive = 0b100,
	Force_Active = 0b101,
	PWM_Mode_1 = 0b110, // Mode1 is when the output is high near count=0 (output goes low when
						// counting up past match, and goes high when counting down past match)
	PWM_Mode_2 = 0b111  // Opposite of Mode1, output is high when count is nearer the reload value
};

enum class CCMR_Output_Compare_Mode_Alt {
	Retriggerable_OPM_Mode_1 = 0b000,
	Retriggerable_OPM_Mode_2 = 0b001,
	Reserved_1 = 0b010,
	Reserved_2 = 0b011,
	Combined_PWM_Mode_1 = 0b100,
	Combined_PWM_Mode_2 = 0b101,
	Asymmetric_PWM_Mode_1 = 0b110,
	Asymmetric_PWM_Mode_2 = 0b111
};

enum class BDTR_Lock_Configuration {
	Off = 0b00,
	Level_1 = 0b01,
	Level_2 = 0b10,
	Level_3 = 0b11
};

enum class ECR_Index_Direction {
	Reset_Any = 0b00,
	Reset_Only_Up = 0b01,
	Reset_Only_Down = 0b10,
};

enum class ECR_Index_Positioning {
	Reset_On_A0_B0 = 0b00,
	Reset_On_A0_B1 = 0b01,
	Reset_On_A1_B0 = 0b10,
	Reset_On_A1_B1 = 0b11
};

} // namespace STM32LIB

#endif // TIMER_TYPES_HPP_
