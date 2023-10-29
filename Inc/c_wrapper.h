/*
 * c_wrapper.h
 *
 *  Created on: Sep 21, 2023
 *      Author: david
 */

#ifndef C_WRAPPER_H_
#define C_WRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

uint32_t sysclock();
uint32_t abp1_timer_clock();


#ifdef __cplusplus
}
#endif


#endif /* C_WRAPPER_H_ */
