#ifndef EBIKECONFIG_HPP_
#define EBIKECONFIG_HPP_
#pragma once

#include <cstdint>
#include "Gpio.hpp"
#include "Timer.hpp"
#include "Pin.hpp"

/* Peripheral usage:
 *
 * *** TIMERS ***
 * --- Advanced motor control ---
 * TIM1 - 3phase bridge PWM output
 * TIM8 -
 * TIM20 -
 * --- General purpose, 32bit ---
 * TIM2 -
 * TIM5 - Pedal Assist (PAS) timer for Thr
 * --- General purpose, 16bit ---
 * TIM3 -
 * TIM4 - Hall sensors
 * TIM15 -
 * TIM16 -
 * TIM17 -
 * --- Basic ---
 * TIM6 - Basic timer for application scheduling
 * TIM7 -
 * --- Other ---
 * LPTIM1 -
 * IDWG - Safety reset
 * WWDG -
 * SysTick - FreeRTOS Scheduler
 * RTC - Temporary save variables into BKPSRAM to command bootloader resets
 *
 * *** ANALOG ***
 * ADC1,2,3,4 - Measure motor current, battery voltage, and throttle
 * ADC5 -
 * DAC1 - Debugging analog outputs for viewing with an oscilloscope
 * DAC2 -
 * COMP -
 * OPAMP -
 *
 * *** COMMUNICATION INTERFACES ***
 * USART1 -
 * USART2 - Handle bar display (HBD)
 * USART3 - Battery management system (BMS)
 * LPUART1 -
 * SPI1 - Communication with 3-phase bridge driver (DRV8353RS)
 * SPI2/I2S2 -
 * SPI3/I2S3 -
 * I2C1,2,3,4 -
 * FDCAN1,2,3 -
 * SAI -
 * USB Device - Debugging communications
 * UCPD -
 *
 * *** OTHER STUFF ***
 * CRS - Correct USB clock source to host SOF
 * FSMC -
 * QUADSPI -
 * DMA1 -
 * DMA2 -
 * CRC - Generate CRC-32 for packet data interface
 * RNG -
 * HASH -
 * CRYP -
 * CORDIC - sin/cos calculations in FOC
 * FMAC - biquad filter calculations
 */

namespace EbikeLib {

// Pin Definitions
// Port A
constexpr Pin ADC_IC_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 0}; // Current on phase C
constexpr Pin ADC_IB_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 1}; // Current on phase B
constexpr Pin HBD_TX_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 2}; // UART Transmit to HBD
constexpr Pin HBD_RX_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 3}; // UART Receive from HBD
constexpr Pin DAC1_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 4}; // DAC output channel 1 (debug)
constexpr Pin DAC2_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 5}; // DAC output channel 2 (debug)
constexpr Pin ADC_VA_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 6}; // Voltage on phase A
constexpr Pin ADC_VB_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 7}; // Voltage on phase B
constexpr Pin PWM_C_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 8}; // PWM output for phase C (high side)
constexpr Pin PWM_B_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 9}; // PWM output for phase B (high side)
constexpr Pin PWM_A_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 10}; // PWM output for phase A (high side)
constexpr Pin USB_DM_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 11}; // USB
constexpr Pin USB_DP_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 12}; // USB
constexpr Pin SWDIO_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 13}; // Programming
constexpr Pin SWCLK_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 14}; // Programming
constexpr Pin PWM_OC_Pin =	{.Port = Gpio_Port::GPIO_A, .Num = 15}; // Overcurrent (Brake) input for PWM

// Port B
constexpr Pin ADC_IA_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 0}; // Current on phase A
constexpr Pin ADC_VC_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 1}; // Voltage on phase C
constexpr Pin ADC_Thr_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 2}; // Throttle analog input
constexpr Pin DRV_SCK_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 3}; // Clock for DRV8353
constexpr Pin DRV_MISO_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 4}; // Data receive from DRV8353
constexpr Pin DRV_MOSI_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 5}; // Data transmit to DRV8353
constexpr Pin HALL_A_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 6}; // Motor hall sensor phase A
constexpr Pin HALL_B_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 7}; // Motor hall sensor phase B
constexpr Pin HALL_C_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 8}; // Motor hall sensor phase C
constexpr Pin DRV_CS_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 9}; // Chip select for DRV8353
constexpr Pin BMS_TX_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 10}; // UART Transmit to BMS
constexpr Pin BMS_RX_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 11}; // UART Receive from BMS
constexpr Pin ADC_Vbus_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 12};
constexpr Pin PWM_Cn_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 13}; // PWM output for phase C (low side)
constexpr Pin PWM_Bn_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 14}; // PWM output for phase B (low side)
constexpr Pin PWM_An_Pin =	{.Port = Gpio_Port::GPIO_B, .Num = 15}; // PWM output for phase A (low side)

// Port C
constexpr Pin DRV_EN_Pin =	{.Port = Gpio_Port::GPIO_C, .Num = 13}; // Enable for DRV8353
constexpr Pin GLED_Pin =	{.Port = Gpio_Port::GPIO_C, .Num = 14}; // Green LED (active high)
constexpr Pin RLED_Pin =	{.Port = Gpio_Port::GPIO_C, .Num = 15}; // Red LED (active high)

// Port F
constexpr Pin ADC_Motor_Temp_Pin =	{.Port = Gpio_Port::GPIO_F, .Num = 0}; // Motor temperature sensor thermistor
constexpr Pin ADC_FET_Temp_Pin =	{.Port = Gpio_Port::GPIO_F, .Num = 1}; // Driver MOSFET temperature sensor thermistor

// Port G
constexpr Pin Reset_Pin =	{.Port = Gpio_Port::GPIO_G, .Num = 10}; // MCU reset

// ADC Channel Assignments
const uint16_t ADC_IA_Channel = 12; // ADC3
const uint16_t ADC_IB_Channel = 2; // ADC2
const uint16_t ADC_IC_Channel = 1; // ADC1
const uint16_t ADC_VA_Channel = 3; // ADC2
const uint16_t ADC_VB_Channel = 4; // ADC2
const uint16_t ADC_VC_Channel = 1; // ADC3
const uint16_t ADC_Thr_Channel = 12; // ADC2
const uint16_t ADC_Vbus_Channel = 11; // ADC1
const uint16_t ADC_Motor_Temp_Channel = 10; // ADC1
const uint16_t ADC_FET_Temp_Channel = 10; // ADC2

// Timer Assignments
constexpr Timer_Periph PWM_Timer = Timer_Periph::Timer8;
constexpr Timer_Periph PAS_Timer = Timer_Periph::Timer5;
constexpr Timer_Periph Hall_Timer = Timer_Periph::Timer4;

// Alternate function assignments
// PWM
const uint32_t Pwm_A_Af_Num = 6;
const uint32_t Pwm_B_Af_Num = 6;
const uint32_t Pwm_C_Af_Num = 6;
const uint32_t Pwm_An_Af_Num = 4;
const uint32_t Pwm_Bn_Af_Num = 6;
const uint32_t Pwm_Cn_Af_Num = 6;
const uint32_t Pwm_OC_Af_Num = 9;
// SPI
const uint32_t Spi_SCK_Af_Num = 5;
const uint32_t Spi_MISO_Af_Num = 5;
const uint32_t Spi_MOSI_Af_Num = 5;


} // namespace EbikeLib

#endif // EBIKECONFIG_HPP_
