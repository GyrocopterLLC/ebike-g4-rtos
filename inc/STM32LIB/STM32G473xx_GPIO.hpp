#ifndef STM32G473XX_GPIO_HPP_
#define STM32G473XX_GPIO_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"
#include "GPIO_Types.hpp"

/* General-purpose I/Os */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using MODER_MODER15_T = GPIO_Mode;
using MODER_MODER14_T = GPIO_Mode;
using MODER_MODER13_T = GPIO_Mode;
using MODER_MODER12_T = GPIO_Mode;
using MODER_MODER11_T = GPIO_Mode;
using MODER_MODER10_T = GPIO_Mode;
using MODER_MODER9_T = GPIO_Mode;
using MODER_MODER8_T = GPIO_Mode;
using MODER_MODER7_T = GPIO_Mode;
using MODER_MODER6_T = GPIO_Mode;
using MODER_MODER5_T = GPIO_Mode;
using MODER_MODER4_T = GPIO_Mode;
using MODER_MODER3_T = GPIO_Mode;
using MODER_MODER2_T = GPIO_Mode;
using MODER_MODER1_T = GPIO_Mode;
using MODER_MODER0_T = GPIO_Mode;
using OSPEEDR_OSPEEDR15_T = GPIO_Speed;
using OSPEEDR_OSPEEDR14_T = GPIO_Speed;
using OSPEEDR_OSPEEDR13_T = GPIO_Speed;
using OSPEEDR_OSPEEDR12_T = GPIO_Speed;
using OSPEEDR_OSPEEDR11_T = GPIO_Speed;
using OSPEEDR_OSPEEDR10_T = GPIO_Speed;
using OSPEEDR_OSPEEDR9_T = GPIO_Speed;
using OSPEEDR_OSPEEDR8_T = GPIO_Speed;
using OSPEEDR_OSPEEDR7_T = GPIO_Speed;
using OSPEEDR_OSPEEDR6_T = GPIO_Speed;
using OSPEEDR_OSPEEDR5_T = GPIO_Speed;
using OSPEEDR_OSPEEDR4_T = GPIO_Speed;
using OSPEEDR_OSPEEDR3_T = GPIO_Speed;
using OSPEEDR_OSPEEDR2_T = GPIO_Speed;
using OSPEEDR_OSPEEDR1_T = GPIO_Speed;
using OSPEEDR_OSPEEDR0_T = GPIO_Speed;
using PUPDR_PUPDR15_T = GPIO_Pull;
using PUPDR_PUPDR14_T = GPIO_Pull;
using PUPDR_PUPDR13_T = GPIO_Pull;
using PUPDR_PUPDR12_T = GPIO_Pull;
using PUPDR_PUPDR11_T = GPIO_Pull;
using PUPDR_PUPDR10_T = GPIO_Pull;
using PUPDR_PUPDR9_T = GPIO_Pull;
using PUPDR_PUPDR8_T = GPIO_Pull;
using PUPDR_PUPDR7_T = GPIO_Pull;
using PUPDR_PUPDR6_T = GPIO_Pull;
using PUPDR_PUPDR5_T = GPIO_Pull;
using PUPDR_PUPDR4_T = GPIO_Pull;
using PUPDR_PUPDR3_T = GPIO_Pull;
using PUPDR_PUPDR2_T = GPIO_Pull;
using PUPDR_PUPDR1_T = GPIO_Pull;
using PUPDR_PUPDR0_T = GPIO_Pull;
using AFRL_AFRL7_T = uint32_t;
using AFRL_AFRL6_T = uint32_t;
using AFRL_AFRL5_T = uint32_t;
using AFRL_AFRL4_T = uint32_t;
using AFRL_AFRL3_T = uint32_t;
using AFRL_AFRL2_T = uint32_t;
using AFRL_AFRL1_T = uint32_t;
using AFRL_AFRL0_T = uint32_t;
using AFRH_AFRH15_T = uint32_t;
using AFRH_AFRH14_T = uint32_t;
using AFRH_AFRH13_T = uint32_t;
using AFRH_AFRH12_T = uint32_t;
using AFRH_AFRH11_T = uint32_t;
using AFRH_AFRH10_T = uint32_t;
using AFRH_AFRH9_T = uint32_t;
using AFRH_AFRH8_T = uint32_t;

namespace GPIO_MODER {

    enum class moder_reg_type {};

    template<MODER_MODER15_T val>
    using MODER15 = Register::Combo_Bitfield<moder_reg_type, 30, 2, MODER_MODER15_T, val>;

    template<MODER_MODER14_T val>
    using MODER14 = Register::Combo_Bitfield<moder_reg_type, 28, 2, MODER_MODER14_T, val>;

    template<MODER_MODER13_T val>
    using MODER13 = Register::Combo_Bitfield<moder_reg_type, 26, 2, MODER_MODER13_T, val>;

    template<MODER_MODER12_T val>
    using MODER12 = Register::Combo_Bitfield<moder_reg_type, 24, 2, MODER_MODER12_T, val>;

    template<MODER_MODER11_T val>
    using MODER11 = Register::Combo_Bitfield<moder_reg_type, 22, 2, MODER_MODER11_T, val>;

    template<MODER_MODER10_T val>
    using MODER10 = Register::Combo_Bitfield<moder_reg_type, 20, 2, MODER_MODER10_T, val>;

    template<MODER_MODER9_T val>
    using MODER9 = Register::Combo_Bitfield<moder_reg_type, 18, 2, MODER_MODER9_T, val>;

    template<MODER_MODER8_T val>
    using MODER8 = Register::Combo_Bitfield<moder_reg_type, 16, 2, MODER_MODER8_T, val>;

    template<MODER_MODER7_T val>
    using MODER7 = Register::Combo_Bitfield<moder_reg_type, 14, 2, MODER_MODER7_T, val>;

    template<MODER_MODER6_T val>
    using MODER6 = Register::Combo_Bitfield<moder_reg_type, 12, 2, MODER_MODER6_T, val>;

    template<MODER_MODER5_T val>
    using MODER5 = Register::Combo_Bitfield<moder_reg_type, 10, 2, MODER_MODER5_T, val>;

    template<MODER_MODER4_T val>
    using MODER4 = Register::Combo_Bitfield<moder_reg_type, 8, 2, MODER_MODER4_T, val>;

    template<MODER_MODER3_T val>
    using MODER3 = Register::Combo_Bitfield<moder_reg_type, 6, 2, MODER_MODER3_T, val>;

    template<MODER_MODER2_T val>
    using MODER2 = Register::Combo_Bitfield<moder_reg_type, 4, 2, MODER_MODER2_T, val>;

    template<MODER_MODER1_T val>
    using MODER1 = Register::Combo_Bitfield<moder_reg_type, 2, 2, MODER_MODER1_T, val>;

    template<MODER_MODER0_T val>
    using MODER0 = Register::Combo_Bitfield<moder_reg_type, 0, 2, MODER_MODER0_T, val>;

} // GPIO_MODER
namespace GPIO_OTYPER {

    enum class otyper_reg_type {};

    template<bool tf>
    using OT15 = Register::Combo_Bit<otyper_reg_type, 15, tf>;

    template<bool tf>
    using OT14 = Register::Combo_Bit<otyper_reg_type, 14, tf>;

    template<bool tf>
    using OT13 = Register::Combo_Bit<otyper_reg_type, 13, tf>;

    template<bool tf>
    using OT12 = Register::Combo_Bit<otyper_reg_type, 12, tf>;

    template<bool tf>
    using OT11 = Register::Combo_Bit<otyper_reg_type, 11, tf>;

    template<bool tf>
    using OT10 = Register::Combo_Bit<otyper_reg_type, 10, tf>;

    template<bool tf>
    using OT9 = Register::Combo_Bit<otyper_reg_type, 9, tf>;

    template<bool tf>
    using OT8 = Register::Combo_Bit<otyper_reg_type, 8, tf>;

    template<bool tf>
    using OT7 = Register::Combo_Bit<otyper_reg_type, 7, tf>;

    template<bool tf>
    using OT6 = Register::Combo_Bit<otyper_reg_type, 6, tf>;

    template<bool tf>
    using OT5 = Register::Combo_Bit<otyper_reg_type, 5, tf>;

    template<bool tf>
    using OT4 = Register::Combo_Bit<otyper_reg_type, 4, tf>;

    template<bool tf>
    using OT3 = Register::Combo_Bit<otyper_reg_type, 3, tf>;

    template<bool tf>
    using OT2 = Register::Combo_Bit<otyper_reg_type, 2, tf>;

    template<bool tf>
    using OT1 = Register::Combo_Bit<otyper_reg_type, 1, tf>;

    template<bool tf>
    using OT0 = Register::Combo_Bit<otyper_reg_type, 0, tf>;

} // GPIO_OTYPER
namespace GPIO_OSPEEDR {

    enum class ospeedr_reg_type {};

    template<OSPEEDR_OSPEEDR15_T val>
    using OSPEEDR15 = Register::Combo_Bitfield<ospeedr_reg_type, 30, 2, OSPEEDR_OSPEEDR15_T, val>;

    template<OSPEEDR_OSPEEDR14_T val>
    using OSPEEDR14 = Register::Combo_Bitfield<ospeedr_reg_type, 28, 2, OSPEEDR_OSPEEDR14_T, val>;

    template<OSPEEDR_OSPEEDR13_T val>
    using OSPEEDR13 = Register::Combo_Bitfield<ospeedr_reg_type, 26, 2, OSPEEDR_OSPEEDR13_T, val>;

    template<OSPEEDR_OSPEEDR12_T val>
    using OSPEEDR12 = Register::Combo_Bitfield<ospeedr_reg_type, 24, 2, OSPEEDR_OSPEEDR12_T, val>;

    template<OSPEEDR_OSPEEDR11_T val>
    using OSPEEDR11 = Register::Combo_Bitfield<ospeedr_reg_type, 22, 2, OSPEEDR_OSPEEDR11_T, val>;

    template<OSPEEDR_OSPEEDR10_T val>
    using OSPEEDR10 = Register::Combo_Bitfield<ospeedr_reg_type, 20, 2, OSPEEDR_OSPEEDR10_T, val>;

    template<OSPEEDR_OSPEEDR9_T val>
    using OSPEEDR9 = Register::Combo_Bitfield<ospeedr_reg_type, 18, 2, OSPEEDR_OSPEEDR9_T, val>;

    template<OSPEEDR_OSPEEDR8_T val>
    using OSPEEDR8 = Register::Combo_Bitfield<ospeedr_reg_type, 16, 2, OSPEEDR_OSPEEDR8_T, val>;

    template<OSPEEDR_OSPEEDR7_T val>
    using OSPEEDR7 = Register::Combo_Bitfield<ospeedr_reg_type, 14, 2, OSPEEDR_OSPEEDR7_T, val>;

    template<OSPEEDR_OSPEEDR6_T val>
    using OSPEEDR6 = Register::Combo_Bitfield<ospeedr_reg_type, 12, 2, OSPEEDR_OSPEEDR6_T, val>;

    template<OSPEEDR_OSPEEDR5_T val>
    using OSPEEDR5 = Register::Combo_Bitfield<ospeedr_reg_type, 10, 2, OSPEEDR_OSPEEDR5_T, val>;

    template<OSPEEDR_OSPEEDR4_T val>
    using OSPEEDR4 = Register::Combo_Bitfield<ospeedr_reg_type, 8, 2, OSPEEDR_OSPEEDR4_T, val>;

    template<OSPEEDR_OSPEEDR3_T val>
    using OSPEEDR3 = Register::Combo_Bitfield<ospeedr_reg_type, 6, 2, OSPEEDR_OSPEEDR3_T, val>;

    template<OSPEEDR_OSPEEDR2_T val>
    using OSPEEDR2 = Register::Combo_Bitfield<ospeedr_reg_type, 4, 2, OSPEEDR_OSPEEDR2_T, val>;

    template<OSPEEDR_OSPEEDR1_T val>
    using OSPEEDR1 = Register::Combo_Bitfield<ospeedr_reg_type, 2, 2, OSPEEDR_OSPEEDR1_T, val>;

    template<OSPEEDR_OSPEEDR0_T val>
    using OSPEEDR0 = Register::Combo_Bitfield<ospeedr_reg_type, 0, 2, OSPEEDR_OSPEEDR0_T, val>;

} // GPIO_OSPEEDR
namespace GPIO_PUPDR {

    enum class pupdr_reg_type {};

    template<PUPDR_PUPDR15_T val>
    using PUPDR15 = Register::Combo_Bitfield<pupdr_reg_type, 30, 2, PUPDR_PUPDR15_T, val>;

    template<PUPDR_PUPDR14_T val>
    using PUPDR14 = Register::Combo_Bitfield<pupdr_reg_type, 28, 2, PUPDR_PUPDR14_T, val>;

    template<PUPDR_PUPDR13_T val>
    using PUPDR13 = Register::Combo_Bitfield<pupdr_reg_type, 26, 2, PUPDR_PUPDR13_T, val>;

    template<PUPDR_PUPDR12_T val>
    using PUPDR12 = Register::Combo_Bitfield<pupdr_reg_type, 24, 2, PUPDR_PUPDR12_T, val>;

    template<PUPDR_PUPDR11_T val>
    using PUPDR11 = Register::Combo_Bitfield<pupdr_reg_type, 22, 2, PUPDR_PUPDR11_T, val>;

    template<PUPDR_PUPDR10_T val>
    using PUPDR10 = Register::Combo_Bitfield<pupdr_reg_type, 20, 2, PUPDR_PUPDR10_T, val>;

    template<PUPDR_PUPDR9_T val>
    using PUPDR9 = Register::Combo_Bitfield<pupdr_reg_type, 18, 2, PUPDR_PUPDR9_T, val>;

    template<PUPDR_PUPDR8_T val>
    using PUPDR8 = Register::Combo_Bitfield<pupdr_reg_type, 16, 2, PUPDR_PUPDR8_T, val>;

    template<PUPDR_PUPDR7_T val>
    using PUPDR7 = Register::Combo_Bitfield<pupdr_reg_type, 14, 2, PUPDR_PUPDR7_T, val>;

    template<PUPDR_PUPDR6_T val>
    using PUPDR6 = Register::Combo_Bitfield<pupdr_reg_type, 12, 2, PUPDR_PUPDR6_T, val>;

    template<PUPDR_PUPDR5_T val>
    using PUPDR5 = Register::Combo_Bitfield<pupdr_reg_type, 10, 2, PUPDR_PUPDR5_T, val>;

    template<PUPDR_PUPDR4_T val>
    using PUPDR4 = Register::Combo_Bitfield<pupdr_reg_type, 8, 2, PUPDR_PUPDR4_T, val>;

    template<PUPDR_PUPDR3_T val>
    using PUPDR3 = Register::Combo_Bitfield<pupdr_reg_type, 6, 2, PUPDR_PUPDR3_T, val>;

    template<PUPDR_PUPDR2_T val>
    using PUPDR2 = Register::Combo_Bitfield<pupdr_reg_type, 4, 2, PUPDR_PUPDR2_T, val>;

    template<PUPDR_PUPDR1_T val>
    using PUPDR1 = Register::Combo_Bitfield<pupdr_reg_type, 2, 2, PUPDR_PUPDR1_T, val>;

    template<PUPDR_PUPDR0_T val>
    using PUPDR0 = Register::Combo_Bitfield<pupdr_reg_type, 0, 2, PUPDR_PUPDR0_T, val>;

} // GPIO_PUPDR
namespace GPIO_IDR {

    enum class idr_reg_type {};

    template<bool tf>
    using IDR15 = Register::Combo_Bit<idr_reg_type, 15, tf>;

    template<bool tf>
    using IDR14 = Register::Combo_Bit<idr_reg_type, 14, tf>;

    template<bool tf>
    using IDR13 = Register::Combo_Bit<idr_reg_type, 13, tf>;

    template<bool tf>
    using IDR12 = Register::Combo_Bit<idr_reg_type, 12, tf>;

    template<bool tf>
    using IDR11 = Register::Combo_Bit<idr_reg_type, 11, tf>;

    template<bool tf>
    using IDR10 = Register::Combo_Bit<idr_reg_type, 10, tf>;

    template<bool tf>
    using IDR9 = Register::Combo_Bit<idr_reg_type, 9, tf>;

    template<bool tf>
    using IDR8 = Register::Combo_Bit<idr_reg_type, 8, tf>;

    template<bool tf>
    using IDR7 = Register::Combo_Bit<idr_reg_type, 7, tf>;

    template<bool tf>
    using IDR6 = Register::Combo_Bit<idr_reg_type, 6, tf>;

    template<bool tf>
    using IDR5 = Register::Combo_Bit<idr_reg_type, 5, tf>;

    template<bool tf>
    using IDR4 = Register::Combo_Bit<idr_reg_type, 4, tf>;

    template<bool tf>
    using IDR3 = Register::Combo_Bit<idr_reg_type, 3, tf>;

    template<bool tf>
    using IDR2 = Register::Combo_Bit<idr_reg_type, 2, tf>;

    template<bool tf>
    using IDR1 = Register::Combo_Bit<idr_reg_type, 1, tf>;

    template<bool tf>
    using IDR0 = Register::Combo_Bit<idr_reg_type, 0, tf>;

} // GPIO_IDR
namespace GPIO_ODR {

    enum class odr_reg_type {};

    template<bool tf>
    using ODR15 = Register::Combo_Bit<odr_reg_type, 15, tf>;

    template<bool tf>
    using ODR14 = Register::Combo_Bit<odr_reg_type, 14, tf>;

    template<bool tf>
    using ODR13 = Register::Combo_Bit<odr_reg_type, 13, tf>;

    template<bool tf>
    using ODR12 = Register::Combo_Bit<odr_reg_type, 12, tf>;

    template<bool tf>
    using ODR11 = Register::Combo_Bit<odr_reg_type, 11, tf>;

    template<bool tf>
    using ODR10 = Register::Combo_Bit<odr_reg_type, 10, tf>;

    template<bool tf>
    using ODR9 = Register::Combo_Bit<odr_reg_type, 9, tf>;

    template<bool tf>
    using ODR8 = Register::Combo_Bit<odr_reg_type, 8, tf>;

    template<bool tf>
    using ODR7 = Register::Combo_Bit<odr_reg_type, 7, tf>;

    template<bool tf>
    using ODR6 = Register::Combo_Bit<odr_reg_type, 6, tf>;

    template<bool tf>
    using ODR5 = Register::Combo_Bit<odr_reg_type, 5, tf>;

    template<bool tf>
    using ODR4 = Register::Combo_Bit<odr_reg_type, 4, tf>;

    template<bool tf>
    using ODR3 = Register::Combo_Bit<odr_reg_type, 3, tf>;

    template<bool tf>
    using ODR2 = Register::Combo_Bit<odr_reg_type, 2, tf>;

    template<bool tf>
    using ODR1 = Register::Combo_Bit<odr_reg_type, 1, tf>;

    template<bool tf>
    using ODR0 = Register::Combo_Bit<odr_reg_type, 0, tf>;

} // GPIO_ODR
namespace GPIO_BSRR {

    enum class bsrr_reg_type {};

    template<bool tf>
    using BR15 = Register::Combo_Bit<bsrr_reg_type, 31, tf>;

    template<bool tf>
    using BR14 = Register::Combo_Bit<bsrr_reg_type, 30, tf>;

    template<bool tf>
    using BR13 = Register::Combo_Bit<bsrr_reg_type, 29, tf>;

    template<bool tf>
    using BR12 = Register::Combo_Bit<bsrr_reg_type, 28, tf>;

    template<bool tf>
    using BR11 = Register::Combo_Bit<bsrr_reg_type, 27, tf>;

    template<bool tf>
    using BR10 = Register::Combo_Bit<bsrr_reg_type, 26, tf>;

    template<bool tf>
    using BR9 = Register::Combo_Bit<bsrr_reg_type, 25, tf>;

    template<bool tf>
    using BR8 = Register::Combo_Bit<bsrr_reg_type, 24, tf>;

    template<bool tf>
    using BR7 = Register::Combo_Bit<bsrr_reg_type, 23, tf>;

    template<bool tf>
    using BR6 = Register::Combo_Bit<bsrr_reg_type, 22, tf>;

    template<bool tf>
    using BR5 = Register::Combo_Bit<bsrr_reg_type, 21, tf>;

    template<bool tf>
    using BR4 = Register::Combo_Bit<bsrr_reg_type, 20, tf>;

    template<bool tf>
    using BR3 = Register::Combo_Bit<bsrr_reg_type, 19, tf>;

    template<bool tf>
    using BR2 = Register::Combo_Bit<bsrr_reg_type, 18, tf>;

    template<bool tf>
    using BR1 = Register::Combo_Bit<bsrr_reg_type, 17, tf>;

    template<bool tf>
    using BR0 = Register::Combo_Bit<bsrr_reg_type, 16, tf>;

    template<bool tf>
    using BS15 = Register::Combo_Bit<bsrr_reg_type, 15, tf>;

    template<bool tf>
    using BS14 = Register::Combo_Bit<bsrr_reg_type, 14, tf>;

    template<bool tf>
    using BS13 = Register::Combo_Bit<bsrr_reg_type, 13, tf>;

    template<bool tf>
    using BS12 = Register::Combo_Bit<bsrr_reg_type, 12, tf>;

    template<bool tf>
    using BS11 = Register::Combo_Bit<bsrr_reg_type, 11, tf>;

    template<bool tf>
    using BS10 = Register::Combo_Bit<bsrr_reg_type, 10, tf>;

    template<bool tf>
    using BS9 = Register::Combo_Bit<bsrr_reg_type, 9, tf>;

    template<bool tf>
    using BS8 = Register::Combo_Bit<bsrr_reg_type, 8, tf>;

    template<bool tf>
    using BS7 = Register::Combo_Bit<bsrr_reg_type, 7, tf>;

    template<bool tf>
    using BS6 = Register::Combo_Bit<bsrr_reg_type, 6, tf>;

    template<bool tf>
    using BS5 = Register::Combo_Bit<bsrr_reg_type, 5, tf>;

    template<bool tf>
    using BS4 = Register::Combo_Bit<bsrr_reg_type, 4, tf>;

    template<bool tf>
    using BS3 = Register::Combo_Bit<bsrr_reg_type, 3, tf>;

    template<bool tf>
    using BS2 = Register::Combo_Bit<bsrr_reg_type, 2, tf>;

    template<bool tf>
    using BS1 = Register::Combo_Bit<bsrr_reg_type, 1, tf>;

    template<bool tf>
    using BS0 = Register::Combo_Bit<bsrr_reg_type, 0, tf>;

} // GPIO_BSRR
namespace GPIO_LCKR {

    enum class lckr_reg_type {};

    template<bool tf>
    using LCKK = Register::Combo_Bit<lckr_reg_type, 16, tf>;

    template<bool tf>
    using LCK15 = Register::Combo_Bit<lckr_reg_type, 15, tf>;

    template<bool tf>
    using LCK14 = Register::Combo_Bit<lckr_reg_type, 14, tf>;

    template<bool tf>
    using LCK13 = Register::Combo_Bit<lckr_reg_type, 13, tf>;

    template<bool tf>
    using LCK12 = Register::Combo_Bit<lckr_reg_type, 12, tf>;

    template<bool tf>
    using LCK11 = Register::Combo_Bit<lckr_reg_type, 11, tf>;

    template<bool tf>
    using LCK10 = Register::Combo_Bit<lckr_reg_type, 10, tf>;

    template<bool tf>
    using LCK9 = Register::Combo_Bit<lckr_reg_type, 9, tf>;

    template<bool tf>
    using LCK8 = Register::Combo_Bit<lckr_reg_type, 8, tf>;

    template<bool tf>
    using LCK7 = Register::Combo_Bit<lckr_reg_type, 7, tf>;

    template<bool tf>
    using LCK6 = Register::Combo_Bit<lckr_reg_type, 6, tf>;

    template<bool tf>
    using LCK5 = Register::Combo_Bit<lckr_reg_type, 5, tf>;

    template<bool tf>
    using LCK4 = Register::Combo_Bit<lckr_reg_type, 4, tf>;

    template<bool tf>
    using LCK3 = Register::Combo_Bit<lckr_reg_type, 3, tf>;

    template<bool tf>
    using LCK2 = Register::Combo_Bit<lckr_reg_type, 2, tf>;

    template<bool tf>
    using LCK1 = Register::Combo_Bit<lckr_reg_type, 1, tf>;

    template<bool tf>
    using LCK0 = Register::Combo_Bit<lckr_reg_type, 0, tf>;

} // GPIO_LCKR
namespace GPIO_AFRL {

    enum class afrl_reg_type {};

    template<AFRL_AFRL7_T val>
    using AFRL7 = Register::Combo_Bitfield<afrl_reg_type, 28, 4, AFRL_AFRL7_T, val>;

    template<AFRL_AFRL6_T val>
    using AFRL6 = Register::Combo_Bitfield<afrl_reg_type, 24, 4, AFRL_AFRL6_T, val>;

    template<AFRL_AFRL5_T val>
    using AFRL5 = Register::Combo_Bitfield<afrl_reg_type, 20, 4, AFRL_AFRL5_T, val>;

    template<AFRL_AFRL4_T val>
    using AFRL4 = Register::Combo_Bitfield<afrl_reg_type, 16, 4, AFRL_AFRL4_T, val>;

    template<AFRL_AFRL3_T val>
    using AFRL3 = Register::Combo_Bitfield<afrl_reg_type, 12, 4, AFRL_AFRL3_T, val>;

    template<AFRL_AFRL2_T val>
    using AFRL2 = Register::Combo_Bitfield<afrl_reg_type, 8, 4, AFRL_AFRL2_T, val>;

    template<AFRL_AFRL1_T val>
    using AFRL1 = Register::Combo_Bitfield<afrl_reg_type, 4, 4, AFRL_AFRL1_T, val>;

    template<AFRL_AFRL0_T val>
    using AFRL0 = Register::Combo_Bitfield<afrl_reg_type, 0, 4, AFRL_AFRL0_T, val>;

} // GPIO_AFRL
namespace GPIO_AFRH {

    enum class afrh_reg_type {};

    template<AFRH_AFRH15_T val>
    using AFRH15 = Register::Combo_Bitfield<afrh_reg_type, 28, 4, AFRH_AFRH15_T, val>;

    template<AFRH_AFRH14_T val>
    using AFRH14 = Register::Combo_Bitfield<afrh_reg_type, 24, 4, AFRH_AFRH14_T, val>;

    template<AFRH_AFRH13_T val>
    using AFRH13 = Register::Combo_Bitfield<afrh_reg_type, 20, 4, AFRH_AFRH13_T, val>;

    template<AFRH_AFRH12_T val>
    using AFRH12 = Register::Combo_Bitfield<afrh_reg_type, 16, 4, AFRH_AFRH12_T, val>;

    template<AFRH_AFRH11_T val>
    using AFRH11 = Register::Combo_Bitfield<afrh_reg_type, 12, 4, AFRH_AFRH11_T, val>;

    template<AFRH_AFRH10_T val>
    using AFRH10 = Register::Combo_Bitfield<afrh_reg_type, 8, 4, AFRH_AFRH10_T, val>;

    template<AFRH_AFRH9_T val>
    using AFRH9 = Register::Combo_Bitfield<afrh_reg_type, 4, 4, AFRH_AFRH9_T, val>;

    template<AFRH_AFRH8_T val>
    using AFRH8 = Register::Combo_Bitfield<afrh_reg_type, 0, 4, AFRH_AFRH8_T, val>;

} // GPIO_AFRH
namespace GPIO_BRR {

    enum class brr_reg_type {};

    template<bool tf>
    using BR0 = Register::Combo_Bit<brr_reg_type, 0, tf>;

    template<bool tf>
    using BR1 = Register::Combo_Bit<brr_reg_type, 1, tf>;

    template<bool tf>
    using BR2 = Register::Combo_Bit<brr_reg_type, 2, tf>;

    template<bool tf>
    using BR3 = Register::Combo_Bit<brr_reg_type, 3, tf>;

    template<bool tf>
    using BR4 = Register::Combo_Bit<brr_reg_type, 4, tf>;

    template<bool tf>
    using BR5 = Register::Combo_Bit<brr_reg_type, 5, tf>;

    template<bool tf>
    using BR6 = Register::Combo_Bit<brr_reg_type, 6, tf>;

    template<bool tf>
    using BR7 = Register::Combo_Bit<brr_reg_type, 7, tf>;

    template<bool tf>
    using BR8 = Register::Combo_Bit<brr_reg_type, 8, tf>;

    template<bool tf>
    using BR9 = Register::Combo_Bit<brr_reg_type, 9, tf>;

    template<bool tf>
    using BR10 = Register::Combo_Bit<brr_reg_type, 10, tf>;

    template<bool tf>
    using BR11 = Register::Combo_Bit<brr_reg_type, 11, tf>;

    template<bool tf>
    using BR12 = Register::Combo_Bit<brr_reg_type, 12, tf>;

    template<bool tf>
    using BR13 = Register::Combo_Bit<brr_reg_type, 13, tf>;

    template<bool tf>
    using BR14 = Register::Combo_Bit<brr_reg_type, 14, tf>;

    template<bool tf>
    using BR15 = Register::Combo_Bit<brr_reg_type, 15, tf>;

} // GPIO_BRR
template<uint32_t BASE_ADDRESS>
class GPIO {
public:
    static const uint32_t MODER_Offset = 0x0000;
    static const uint32_t OTYPER_Offset = 0x0004;
    static const uint32_t OSPEEDR_Offset = 0x0008;
    static const uint32_t PUPDR_Offset = 0x000C;
    static const uint32_t IDR_Offset = 0x0010;
    static const uint32_t ODR_Offset = 0x0014;
    static const uint32_t BSRR_Offset = 0x0018;
    static const uint32_t LCKR_Offset = 0x001C;
    static const uint32_t AFRL_Offset = 0x0020;
    static const uint32_t AFRH_Offset = 0x0024;
    static const uint32_t BRR_Offset = 0x0028;

    GPIO() = default;
    GPIO( const GPIO& ) = delete;
    const GPIO& operator=( const GPIO& ) = delete;

    class MODER_T : public Register::Register<GPIO_MODER::moder_reg_type, BASE_ADDRESS + MODER_Offset> {
    // GPIO port mode register
    public:
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 30, 2, MODER_MODER15_T> MODER15; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 28, 2, MODER_MODER14_T> MODER14; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 26, 2, MODER_MODER13_T> MODER13; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 24, 2, MODER_MODER12_T> MODER12; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 22, 2, MODER_MODER11_T> MODER11; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 20, 2, MODER_MODER10_T> MODER10; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 18, 2, MODER_MODER9_T> MODER9; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 16, 2, MODER_MODER8_T> MODER8; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 14, 2, MODER_MODER7_T> MODER7; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 12, 2, MODER_MODER6_T> MODER6; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 10, 2, MODER_MODER5_T> MODER5; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 8, 2, MODER_MODER4_T> MODER4; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 6, 2, MODER_MODER3_T> MODER3; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 4, 2, MODER_MODER2_T> MODER2; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 2, 2, MODER_MODER1_T> MODER1; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + MODER_Offset, 0, 2, MODER_MODER0_T> MODER0; /* Port x configuration bits (y = 0..15) */
    };

    class OTYPER_T : public Register::Register<GPIO_OTYPER::otyper_reg_type, BASE_ADDRESS + OTYPER_Offset>{
    // GPIO port output type register
    public:
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 15> OT15; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 14> OT14; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 13> OT13; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 12> OT12; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 11> OT11; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 10> OT10; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 9> OT9; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 8> OT8; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 7> OT7; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 6> OT6; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 5> OT5; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 4> OT4; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 3> OT3; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 2> OT2; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 1> OT1; /* Port x configuration bits (y = 0..15) */
        Register::Bit<BASE_ADDRESS + OTYPER_Offset, 0> OT0; /* Port x configuration bits (y = 0..15) */
    };

    class OSPEEDR_T : public Register::Register<GPIO_OSPEEDR::ospeedr_reg_type, BASE_ADDRESS + OSPEEDR_Offset> {
    // GPIO port output speed register
    public:
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 30, 2, OSPEEDR_OSPEEDR15_T> OSPEEDR15; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 28, 2, OSPEEDR_OSPEEDR14_T> OSPEEDR14; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 26, 2, OSPEEDR_OSPEEDR13_T> OSPEEDR13; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 24, 2, OSPEEDR_OSPEEDR12_T> OSPEEDR12; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 22, 2, OSPEEDR_OSPEEDR11_T> OSPEEDR11; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 20, 2, OSPEEDR_OSPEEDR10_T> OSPEEDR10; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 18, 2, OSPEEDR_OSPEEDR9_T> OSPEEDR9; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 16, 2, OSPEEDR_OSPEEDR8_T> OSPEEDR8; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 14, 2, OSPEEDR_OSPEEDR7_T> OSPEEDR7; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 12, 2, OSPEEDR_OSPEEDR6_T> OSPEEDR6; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 10, 2, OSPEEDR_OSPEEDR5_T> OSPEEDR5; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 8, 2, OSPEEDR_OSPEEDR4_T> OSPEEDR4; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 6, 2, OSPEEDR_OSPEEDR3_T> OSPEEDR3; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 4, 2, OSPEEDR_OSPEEDR2_T> OSPEEDR2; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 2, 2, OSPEEDR_OSPEEDR1_T> OSPEEDR1; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + OSPEEDR_Offset, 0, 2, OSPEEDR_OSPEEDR0_T> OSPEEDR0; /* Port x configuration bits (y = 0..15) */
    };

    class PUPDR_T : public Register::Register<GPIO_PUPDR::pupdr_reg_type, BASE_ADDRESS + PUPDR_Offset> {
    // GPIO port pull-up/pull-down register
    public:
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 30, 2, PUPDR_PUPDR15_T> PUPDR15; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 28, 2, PUPDR_PUPDR14_T> PUPDR14; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 26, 2, PUPDR_PUPDR13_T> PUPDR13; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 24, 2, PUPDR_PUPDR12_T> PUPDR12; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 22, 2, PUPDR_PUPDR11_T> PUPDR11; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 20, 2, PUPDR_PUPDR10_T> PUPDR10; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 18, 2, PUPDR_PUPDR9_T> PUPDR9; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 16, 2, PUPDR_PUPDR8_T> PUPDR8; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 14, 2, PUPDR_PUPDR7_T> PUPDR7; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 12, 2, PUPDR_PUPDR6_T> PUPDR6; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 10, 2, PUPDR_PUPDR5_T> PUPDR5; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 8, 2, PUPDR_PUPDR4_T> PUPDR4; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 6, 2, PUPDR_PUPDR3_T> PUPDR3; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 4, 2, PUPDR_PUPDR2_T> PUPDR2; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 2, 2, PUPDR_PUPDR1_T> PUPDR1; /* Port x configuration bits (y = 0..15) */
        Register::Bitfield<BASE_ADDRESS + PUPDR_Offset, 0, 2, PUPDR_PUPDR0_T> PUPDR0; /* Port x configuration bits (y = 0..15) */
    };

    class IDR_T : public Register::Register<GPIO_IDR::idr_reg_type, BASE_ADDRESS + IDR_Offset> {
    // GPIO port input data register
    public:
        Register::Bit<BASE_ADDRESS + IDR_Offset, 15> IDR15; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 14> IDR14; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 13> IDR13; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 12> IDR12; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 11> IDR11; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 10> IDR10; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 9> IDR9; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 8> IDR8; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 7> IDR7; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 6> IDR6; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 5> IDR5; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 4> IDR4; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 3> IDR3; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 2> IDR2; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 1> IDR1; /* Port input data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + IDR_Offset, 0> IDR0; /* Port input data (y = 0..15) */
    };

    class ODR_T : public Register::Register<GPIO_ODR::odr_reg_type, BASE_ADDRESS + ODR_Offset> {
    // GPIO port output data register
    public:
        Register::Bit<BASE_ADDRESS + ODR_Offset, 15> ODR15; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 14> ODR14; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 13> ODR13; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 12> ODR12; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 11> ODR11; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 10> ODR10; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 9> ODR9; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 8> ODR8; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 7> ODR7; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 6> ODR6; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 5> ODR5; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 4> ODR4; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 3> ODR3; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 2> ODR2; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 1> ODR1; /* Port output data (y = 0..15) */
        Register::Bit<BASE_ADDRESS + ODR_Offset, 0> ODR0; /* Port output data (y = 0..15) */
    };

    class BSRR_T : public Register::Register<GPIO_BSRR::bsrr_reg_type, BASE_ADDRESS + BSRR_Offset> {
    // GPIO port bit set/reset register
    public:
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 31> BR15; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 30> BR14; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 29> BR13; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 28> BR12; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 27> BR11; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 26> BR10; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 25> BR9; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 24> BR8; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 23> BR7; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 22> BR6; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 21> BR5; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 20> BR4; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 19> BR3; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 18> BR2; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 17> BR1; /* Port x reset bit y (y = 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 16> BR0; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 15> BS15; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 14> BS14; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 13> BS13; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 12> BS12; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 11> BS11; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 10> BS10; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 9> BS9; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 8> BS8; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 7> BS7; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 6> BS6; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 5> BS5; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 4> BS4; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 3> BS3; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 2> BS2; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 1> BS1; /* Port x set bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + BSRR_Offset, 0> BS0; /* Port x set bit y (y= 0..15) */
    };

    class LCKR_T : public Register::Register<GPIO_LCKR::lckr_reg_type, BASE_ADDRESS + LCKR_Offset> {
    // GPIO port configuration lock register
    public:
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 16> LCKK; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 15> LCK15; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 14> LCK14; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 13> LCK13; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 12> LCK12; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 11> LCK11; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 10> LCK10; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 9> LCK9; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 8> LCK8; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 7> LCK7; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 6> LCK6; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 5> LCK5; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 4> LCK4; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 3> LCK3; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 2> LCK2; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 1> LCK1; /* Port x lock bit y (y= 0..15) */
        Register::Bit<BASE_ADDRESS + LCKR_Offset, 0> LCK0; /* Port x lock bit y (y= 0..15) */
    };

    class AFRL_T : public Register::Register<GPIO_AFRL::afrl_reg_type, BASE_ADDRESS + AFRL_Offset> {
    // GPIO alternate function low register
    public:
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 28, 4, AFRL_AFRL7_T> AFRL7; /* Alternate function selection for port x bit y (y = 0..7) */
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 24, 4, AFRL_AFRL6_T> AFRL6; /* Alternate function selection for port x bit y (y = 0..7) */
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 20, 4, AFRL_AFRL5_T> AFRL5; /* Alternate function selection for port x bit y (y = 0..7) */
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 16, 4, AFRL_AFRL4_T> AFRL4; /* Alternate function selection for port x bit y (y = 0..7) */
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 12, 4, AFRL_AFRL3_T> AFRL3; /* Alternate function selection for port x bit y (y = 0..7) */
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 8, 4, AFRL_AFRL2_T> AFRL2; /* Alternate function selection for port x bit y (y = 0..7) */
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 4, 4, AFRL_AFRL1_T> AFRL1; /* Alternate function selection for port x bit y (y = 0..7) */
        Register::Bitfield<BASE_ADDRESS + AFRL_Offset, 0, 4, AFRL_AFRL0_T> AFRL0; /* Alternate function selection for port x bit y (y = 0..7) */
    };

    class AFRH_T : public Register::Register<GPIO_AFRH::afrh_reg_type, BASE_ADDRESS + AFRH_Offset> {
    // GPIO alternate function high register
    public:
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 28, 4, AFRH_AFRH15_T> AFRH15; /* Alternate function selection for port x bit y (y = 8..15) */
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 24, 4, AFRH_AFRH14_T> AFRH14; /* Alternate function selection for port x bit y (y = 8..15) */
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 20, 4, AFRH_AFRH13_T> AFRH13; /* Alternate function selection for port x bit y (y = 8..15) */
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 16, 4, AFRH_AFRH12_T> AFRH12; /* Alternate function selection for port x bit y (y = 8..15) */
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 12, 4, AFRH_AFRH11_T> AFRH11; /* Alternate function selection for port x bit y (y = 8..15) */
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 8, 4, AFRH_AFRH10_T> AFRH10; /* Alternate function selection for port x bit y (y = 8..15) */
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 4, 4, AFRH_AFRH9_T> AFRH9; /* Alternate function selection for port x bit y (y = 8..15) */
        Register::Bitfield<BASE_ADDRESS + AFRH_Offset, 0, 4, AFRH_AFRH8_T> AFRH8; /* Alternate function selection for port x bit y (y = 8..15) */
    };

    class BRR_T : public Register::Register<GPIO_BRR::brr_reg_type, BASE_ADDRESS + BRR_Offset> {
    // GPIO port bit reset register
    public:
        Register::Bit<BASE_ADDRESS + BRR_Offset, 0> BR0; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 1> BR1; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 2> BR2; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 3> BR3; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 4> BR4; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 5> BR5; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 6> BR6; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 7> BR7; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 8> BR8; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 9> BR9; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 10> BR10; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 11> BR11; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 12> BR12; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 13> BR13; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 14> BR14; /* Port Reset bit */
        Register::Bit<BASE_ADDRESS + BRR_Offset, 15> BR15; /* Port Reset bit */
    };

    MODER_T MODER;
    OTYPER_T OTYPER;
    OSPEEDR_T OSPEEDR;
    PUPDR_T PUPDR;
    IDR_T IDR;
    ODR_T ODR;
    BSRR_T BSRR;
    LCKR_T LCKR;
    AFRL_T AFRL;
    AFRH_T AFRH;
    BRR_T BRR;
};

} // namespace STM32LIB

#endif // STM32G473XX_GPIO_HPP_

