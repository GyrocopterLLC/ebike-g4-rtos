#include "STM32G473xx.hpp"
#include "EbikeConfig.hpp"
#include "Util.hpp"

using namespace EbikeLib;

DelayTimer::DelayTimer() {
	// initializes a spare timer as a free running counter
	auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
	rcc.APB1ENR1.TIM6EN.set(true);

	auto tim6 = STM32LIB::TIM<STM32LIB::TIM6_Base_Address>();
	// Set timer for 1us period
	uint32_t tim6_presc = RCC_Funcs::get_apb1_timers_clock_speed() / 1000000u;
	tim6.PSC.set(tim6_presc - 1);
	tim6.CR1.CEN.set(true);
}

void DelayTimer::delay_us(uint16_t us) {
	auto tim6 = STM32LIB::TIM<STM32LIB::TIM6_Base_Address>();
	uint16_t start_val = static_cast<uint16_t>(tim6.CNT.CNT.get());

	// exploiting wraparound of 16-bit math to handle cases where start_val is
	// bigger than the final value (timer goes from 65535 -> 0 during delay)
	while((static_cast<uint16_t>(tim6.CNT.CNT.get()) - start_val) < us);
}

DelayTimer & DelayTimer::instance() {
	static DelayTimer my_delay;
	return my_delay;
}
