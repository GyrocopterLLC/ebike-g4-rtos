# ebike-g4-rtos
A brushless DC motor controller based on the STM32G4 microcontroller. Designed for electric bicycles. Uses FreeRTOS.
Hardware design files at: https://github.com/GyrocopterLLC/flatmcu/

***
#### License: MIT
***

### Build instructions

Dependencies:
- Cmake (version 3.15 or later)
- arm toolchain (arm-none-eabi-\* version 12.3 or later)
- make (I used chocolatey to install it on Windows)
- Visual Studio Code with extensions:
 - C/C++
 - Cortex-Debug
 - CMake
 - CMake Tools
 - (optional) GNU Linker Map files highlighting
 - (optional) Intel HEX format
 
Open the directory in VS Code
Create a folder called "build"
`>mkdir build`
Navigate into that folder
`>cd build`
Run cmake to create the build files
`>cmake -DCMAKE_MAKE_PROGRAM="make.exe" -G "Unix Makefiles" ..
Run the build using cmake
`>cmake --build .`

Or just use this excellent guide:
https://mcuoneclipse.com/2021/05/01/visual-studio-code-for-c-c-with-arm-cortex-m-part-1/