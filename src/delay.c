#include "delay.h"
#include "c_wrapper.h"
#include "stm32g4xx.h"

static volatile uint32_t g_tim6_tick;

void init_delay_timer(void) {
	g_tim6_tick = 0;

    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM6EN;
    uint32_t timer_clock = abp1_timer_clock();

    TIM6->PSC = (timer_clock / 1000000u) - 1; // Clocked at 1MHz, 170MHz is too fast for a 1kHz update with a 16-bit register
    TIM6->ARR = (1000000u / APP_TIM_RATE) - 1;
    TIM6->DIER = TIM_DIER_UIE; // Enable update interrupt

    NVIC_SetPriority(TIM6_DAC_IRQn, PRIO_APPTIMER);
    NVIC_EnableIRQ(TIM6_DAC_IRQn);

    TIM6->CR1 = TIM_CR1_CEN; // Enable counting
}

void TIM6_DACUNDER_IRQHandler(void) {
    if((TIM6->SR & TIM_SR_UIF) != 0) {
        // Update (timer rollover)
        TIM6->SR &= ~(TIM_SR_UIF); // Clear by writing 0
        // Increment global tick
        g_tim6_tick++;
    }
}

void Delay(uint32_t delay_ms) {
    volatile uint32_t tickstart = g_tim6_tick;
    while ((g_tim6_tick - tickstart) < delay_ms) {
    }
}
