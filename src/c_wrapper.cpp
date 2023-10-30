#include "Rcc.hpp"
#include "c_wrapper.h"

uint32_t sysclock() {
	return EbikeLib::RCC_Funcs::get_sysclk_speed();
}


uint32_t abp1_timer_clock() {
	return EbikeLib::RCC_Funcs::get_apb1_timers_clock_speed();
}
