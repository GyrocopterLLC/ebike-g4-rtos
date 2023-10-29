cmake_minimum_required(VERSION 3.15.3)

# Optional: print out extra messages to see what is going on. Comment it to have less verbose messages
set(CMAKE_VERBOSE_MAKEFILE ON)

# Path to toolchain file. This one has to be before 'project()' below
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake)

# Setup project, output and linker file
project(ebike-g4-rtos)
set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/device/STM32G473CETX_FLASH.ld)

enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Optional: issue a message to be sure it uses the correct toolchain file.
message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")

# List of source files
set(SRC_FILES
        src/main.c
        src/c_wrapper.cpp
        src/delay.c
        src/mc.cpp
        src/usb_cdc.c
        src/usb.c
        src/ebikelib/Adc.cpp
        src/ebikelib/CORDIC_Trig.cpp
        src/ebikelib/DRV8353.cpp
        src/ebikelib/FOC_Lib.cpp
        src/ebikelib/Throttle.cpp
        src/ebikelib/Util.cpp
        cobs/cobs.cpp
        freertos/croutine.c
        freertos/event_groups.c
        freertos/list.c
        freertos/queue.c
        freertos/stream_buffer.c
        freertos/tasks.c
        freertos/timers.c
        freertos/portable/GCC/ARM_CM4F/port.c
        freertos/portable/MemMang/heap_3.c
        device/startup_stm32g473cetx.s
        #device/system_stm32g4xx.c
        device/sysmem.c
        device/syscalls.c
        )

# Build the executable based on the source files
add_executable(${EXECUTABLE} ${SRC_FILES})

# List of compiler defines, prefix with -D compiler option
target_compile_definitions(${EXECUTABLE} PRIVATE
        -DSTM32
        -DSTM32G4
        -DSTM32G473xx
        -DSTM32G473CETx
        -DARM_MATH_CM4
        -D__FPU_PRESENT=1
        -D__PROGRAM_START
        )

# List of include directories
target_include_directories(${EXECUTABLE} PRIVATE
        src 
        device
        CMSIS
        cobs
        inc
        inc/ebikelib
        inc/STM32LIB
        freertos/include
        freertos/portable/GCC/ARM_CM4F
        )

# Compiler options

target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
        $<$<COMPILE_LANGUAGE:CXX>:-std=gnu++20>
        $<$<COMPILE_LANGUAGE:C>:-std=gnu11>
        $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>
        -fdata-sections
        -ffunction-sections
        --specs=nano.specs
        -fstack-usage
        -Wall
        -O2
        -g3
        )

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m4 
        -T${LINKER_FILE}
        --specs=nosys.specs
        -Wl,-Map=${PROJECT_NAME}.map
        -Wl,--gc-sections
        -nostartfiles
        #-nostdlib
        -static
        --specs=nano.specs
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
        -mthumb
        -Wl,--start-group
        -lc 
        -lm 
        -lstdc++ 
        -lsupc++
        -Wl,--end-group
        )

# Optional: Print executable size as part of the post build process
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_SIZE_UTIL} ${EXECUTABLE})

# Optional: Create hex, bin and S-Record files after the build
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O srec --srec-len=64 ${EXECUTABLE} ${PROJECT_NAME}.s19
        COMMAND ${CMAKE_OBJCOPY} -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)

# Optional: create list file after the build
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_OBJDUMP} -h -S ${PROJECT_NAME}.elf > "${PROJECT_NAME}.list")