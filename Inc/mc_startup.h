#ifndef SOME_CPP_H_
#define SOME_CPP_H_

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif


void mc_startup_pre_rtos();


void DAC_Task(void* pvParameters);
void Drv_Fault_Task(void* pvParameters);
uint32_t get_fault_status();


#if defined(__cplusplus)
} // extern "C"
#endif


#endif // SOME_CPP_H_
