#ifndef SOME_CPP_H_
#define SOME_CPP_H_

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#define DAC_TASK_STACK_SIZE		(512u)

void mc_startup_pre_rtos();


void DAC_Task(void* pvParameters);
void Drv_Fault_Task(void* pvParameters);
uint32_t get_fault_status();

void start_debug_usb_info();
void stop_debug_usb_info();
void wake_dac_task();

#if defined(__cplusplus)
} // extern "C"
#endif


#endif // SOME_CPP_H_
