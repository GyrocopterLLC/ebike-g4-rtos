/*
 * delay.h
 *
 *  Created on: Sep 21, 2023
 *      Author: david
 */

#ifndef DELAY_H_
#define DELAY_H_

#include <stdint.h>

#define PRIO_APPTIMER	7
#define APP_TIM_RATE	1000

void init_delay_timer(void);

void TIM6_DAC_IRQHandler(void);

void Delay(uint32_t delay_ms);



#endif /* DELAY_H_ */
