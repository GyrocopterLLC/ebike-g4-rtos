#include "STM32G473xx.hpp"
#include "CORDIC_Trig.hpp"
#include "FreeRTOS.h"
#include "semphr.h"

using namespace EbikeLib;

Cordic::Cordic() {
	// Enable the CORDIC
	auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
	rcc.AHB1ENR.CORDICEN.set(true);

	// Set for sine/cosine calculations
	auto cordic = STM32LIB::CORDIC<STM32LIB::CORDIC_Base_Address>();
	cordic.CSR.apply<
		STM32LIB::CORDIC_CSR::PRECISION<6>, // 6 cycles = 24 iterations, precision better than 2^-19
		STM32LIB::CORDIC_CSR::NARGS<true>,
		STM32LIB::CORDIC_CSR::NRES<true>,
		STM32LIB::CORDIC_CSR::FUNC<STM32LIB::Cordic_Function::Sine>
	>();

	// Start a dummy transfer
	set(0x80000000u); // Write DATA1 (angle = 0.5, or pi/2)
	set(0x40000000u); // Write DATA2 (scale = 0.5. after NARGS set to 1, never need to write this again)

	// Scaling by 1/2 is used. Scaling by 1 seemed to have very large error.

	// And a dummy read
	uint32_t cordic_sine, cordic_cosine;

	sine_cosine(&cordic_sine, &cordic_cosine);

	// Set NARGS to 1, so we only need to write the angle to start a conversion
	cordic.CSR.NARGS.set(false);

	// create the mutex
	mutex_h = xSemaphoreCreateMutex();
}

void Cordic::set(uint32_t angle) {
	auto cordic = STM32LIB::CORDIC<STM32LIB::CORDIC_Base_Address>();

	cordic.WDATA.set(angle);
}

__attribute__((noinline))
uint32_t Cordic::get() {
	auto cordic = STM32LIB::CORDIC<STM32LIB::CORDIC_Base_Address>();

	return cordic.RDATA.get();
}

__attribute__((noinline))
void Cordic::sine_cosine(uint32_t* sine, uint32_t* cosine) {
	*sine = get();
	*cosine = get();
}

void Cordic::calc(uint32_t angle, uint32_t* sine, uint32_t* cosine) {
	xSemaphoreTake(mutex_h, portMAX_DELAY);
	set(angle);
	sine_cosine(sine, cosine);
	xSemaphoreGive(mutex_h);
}
