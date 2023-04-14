#ifndef STM32G473XX_NVIC_HPP_
#define STM32G473XX_NVIC_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"

/* Nested Vectored Interrupt Controller */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using ISER0_SETENA_T = uint32_t;
using ISER1_SETENA_T = uint32_t;
using ISER2_SETENA_T = uint32_t;
using ISER3_SETENA_T = uint32_t;
using ICER0_CLRENA_T = uint32_t;
using ICER1_CLRENA_T = uint32_t;
using ICER2_CLRENA_T = uint32_t;
using ICER3_CLRENA_T = uint32_t;
using ISPR0_SETPEND_T = uint32_t;
using ISPR1_SETPEND_T = uint32_t;
using ISPR2_SETPEND_T = uint32_t;
using ISPR3_SETPEND_T = uint32_t;
using ICPR0_CLRPEND_T = uint32_t;
using ICPR1_CLRPEND_T = uint32_t;
using ICPR2_CLRPEND_T = uint32_t;
using ICPR3_CLRPEND_T = uint32_t;
using IABR0_ACTIVE_T = uint32_t;
using IABR1_ACTIVE_T = uint32_t;
using IABR2_ACTIVE_T = uint32_t;
using IABR3_ACTIVE_T = uint32_t;
using IPR0_IPR_N0_T = uint32_t;
using IPR0_IPR_N1_T = uint32_t;
using IPR0_IPR_N2_T = uint32_t;
using IPR0_IPR_N3_T = uint32_t;
using IPR1_IPR_N0_T = uint32_t;
using IPR1_IPR_N1_T = uint32_t;
using IPR1_IPR_N2_T = uint32_t;
using IPR1_IPR_N3_T = uint32_t;
using IPR2_IPR_N0_T = uint32_t;
using IPR2_IPR_N1_T = uint32_t;
using IPR2_IPR_N2_T = uint32_t;
using IPR2_IPR_N3_T = uint32_t;
using IPR3_IPR_N0_T = uint32_t;
using IPR3_IPR_N1_T = uint32_t;
using IPR3_IPR_N2_T = uint32_t;
using IPR3_IPR_N3_T = uint32_t;
using IPR4_IPR_N0_T = uint32_t;
using IPR4_IPR_N1_T = uint32_t;
using IPR4_IPR_N2_T = uint32_t;
using IPR4_IPR_N3_T = uint32_t;
using IPR5_IPR_N0_T = uint32_t;
using IPR5_IPR_N1_T = uint32_t;
using IPR5_IPR_N2_T = uint32_t;
using IPR5_IPR_N3_T = uint32_t;
using IPR6_IPR_N0_T = uint32_t;
using IPR6_IPR_N1_T = uint32_t;
using IPR6_IPR_N2_T = uint32_t;
using IPR6_IPR_N3_T = uint32_t;
using IPR7_IPR_N0_T = uint32_t;
using IPR7_IPR_N1_T = uint32_t;
using IPR7_IPR_N2_T = uint32_t;
using IPR7_IPR_N3_T = uint32_t;
using IPR8_IPR_N0_T = uint32_t;
using IPR8_IPR_N1_T = uint32_t;
using IPR8_IPR_N2_T = uint32_t;
using IPR8_IPR_N3_T = uint32_t;
using IPR9_IPR_N0_T = uint32_t;
using IPR9_IPR_N1_T = uint32_t;
using IPR9_IPR_N2_T = uint32_t;
using IPR9_IPR_N3_T = uint32_t;
using IPR10_IPR_N0_T = uint32_t;
using IPR10_IPR_N1_T = uint32_t;
using IPR10_IPR_N2_T = uint32_t;
using IPR10_IPR_N3_T = uint32_t;
using IPR11_IPR_N0_T = uint32_t;
using IPR11_IPR_N1_T = uint32_t;
using IPR11_IPR_N2_T = uint32_t;
using IPR11_IPR_N3_T = uint32_t;
using IPR12_IPR_N0_T = uint32_t;
using IPR12_IPR_N1_T = uint32_t;
using IPR12_IPR_N2_T = uint32_t;
using IPR12_IPR_N3_T = uint32_t;
using IPR13_IPR_N0_T = uint32_t;
using IPR13_IPR_N1_T = uint32_t;
using IPR13_IPR_N2_T = uint32_t;
using IPR13_IPR_N3_T = uint32_t;
using IPR14_IPR_N0_T = uint32_t;
using IPR14_IPR_N1_T = uint32_t;
using IPR14_IPR_N2_T = uint32_t;
using IPR14_IPR_N3_T = uint32_t;
using IPR15_IPR_N0_T = uint32_t;
using IPR15_IPR_N1_T = uint32_t;
using IPR15_IPR_N2_T = uint32_t;
using IPR15_IPR_N3_T = uint32_t;
using IPR16_IPR_N0_T = uint32_t;
using IPR16_IPR_N1_T = uint32_t;
using IPR16_IPR_N2_T = uint32_t;
using IPR16_IPR_N3_T = uint32_t;
using IPR17_IPR_N0_T = uint32_t;
using IPR17_IPR_N1_T = uint32_t;
using IPR17_IPR_N2_T = uint32_t;
using IPR17_IPR_N3_T = uint32_t;
using IPR18_IPR_N0_T = uint32_t;
using IPR18_IPR_N1_T = uint32_t;
using IPR18_IPR_N2_T = uint32_t;
using IPR18_IPR_N3_T = uint32_t;
using IPR19_IPR_N0_T = uint32_t;
using IPR19_IPR_N1_T = uint32_t;
using IPR19_IPR_N2_T = uint32_t;
using IPR19_IPR_N3_T = uint32_t;
using IPR20_IPR_N0_T = uint32_t;
using IPR20_IPR_N1_T = uint32_t;
using IPR20_IPR_N2_T = uint32_t;
using IPR20_IPR_N3_T = uint32_t;

namespace NVIC_ISER0 {

    enum class iser0_reg_type {};

    template<ISER0_SETENA_T val>
    using SETENA = Register::Combo_Bitfield<iser0_reg_type, 0, 32, ISER0_SETENA_T, val>;

} // NVIC_ISER0
namespace NVIC_ISER1 {

    enum class iser1_reg_type {};

    template<ISER1_SETENA_T val>
    using SETENA = Register::Combo_Bitfield<iser1_reg_type, 0, 32, ISER1_SETENA_T, val>;

} // NVIC_ISER1
namespace NVIC_ISER2 {

    enum class iser2_reg_type {};

    template<ISER2_SETENA_T val>
    using SETENA = Register::Combo_Bitfield<iser2_reg_type, 0, 32, ISER2_SETENA_T, val>;

} // NVIC_ISER2
namespace NVIC_ISER3 {

    enum class iser3_reg_type {};

    template<ISER3_SETENA_T val>
    using SETENA = Register::Combo_Bitfield<iser3_reg_type, 0, 32, ISER3_SETENA_T, val>;

} // NVIC_ISER3
namespace NVIC_ICER0 {

    enum class icer0_reg_type {};

    template<ICER0_CLRENA_T val>
    using CLRENA = Register::Combo_Bitfield<icer0_reg_type, 0, 32, ICER0_CLRENA_T, val>;

} // NVIC_ICER0
namespace NVIC_ICER1 {

    enum class icer1_reg_type {};

    template<ICER1_CLRENA_T val>
    using CLRENA = Register::Combo_Bitfield<icer1_reg_type, 0, 32, ICER1_CLRENA_T, val>;

} // NVIC_ICER1
namespace NVIC_ICER2 {

    enum class icer2_reg_type {};

    template<ICER2_CLRENA_T val>
    using CLRENA = Register::Combo_Bitfield<icer2_reg_type, 0, 32, ICER2_CLRENA_T, val>;

} // NVIC_ICER2
namespace NVIC_ICER3 {

    enum class icer3_reg_type {};

    template<ICER3_CLRENA_T val>
    using CLRENA = Register::Combo_Bitfield<icer3_reg_type, 0, 32, ICER3_CLRENA_T, val>;

} // NVIC_ICER3
namespace NVIC_ISPR0 {

    enum class ispr0_reg_type {};

    template<ISPR0_SETPEND_T val>
    using SETPEND = Register::Combo_Bitfield<ispr0_reg_type, 0, 32, ISPR0_SETPEND_T, val>;

} // NVIC_ISPR0
namespace NVIC_ISPR1 {

    enum class ispr1_reg_type {};

    template<ISPR1_SETPEND_T val>
    using SETPEND = Register::Combo_Bitfield<ispr1_reg_type, 0, 32, ISPR1_SETPEND_T, val>;

} // NVIC_ISPR1
namespace NVIC_ISPR2 {

    enum class ispr2_reg_type {};

    template<ISPR2_SETPEND_T val>
    using SETPEND = Register::Combo_Bitfield<ispr2_reg_type, 0, 32, ISPR2_SETPEND_T, val>;

} // NVIC_ISPR2
namespace NVIC_ISPR3 {

    enum class ispr3_reg_type {};

    template<ISPR3_SETPEND_T val>
    using SETPEND = Register::Combo_Bitfield<ispr3_reg_type, 0, 32, ISPR3_SETPEND_T, val>;

} // NVIC_ISPR3
namespace NVIC_ICPR0 {

    enum class icpr0_reg_type {};

    template<ICPR0_CLRPEND_T val>
    using CLRPEND = Register::Combo_Bitfield<icpr0_reg_type, 0, 32, ICPR0_CLRPEND_T, val>;

} // NVIC_ICPR0
namespace NVIC_ICPR1 {

    enum class icpr1_reg_type {};

    template<ICPR1_CLRPEND_T val>
    using CLRPEND = Register::Combo_Bitfield<icpr1_reg_type, 0, 32, ICPR1_CLRPEND_T, val>;

} // NVIC_ICPR1
namespace NVIC_ICPR2 {

    enum class icpr2_reg_type {};

    template<ICPR2_CLRPEND_T val>
    using CLRPEND = Register::Combo_Bitfield<icpr2_reg_type, 0, 32, ICPR2_CLRPEND_T, val>;

} // NVIC_ICPR2
namespace NVIC_ICPR3 {

    enum class icpr3_reg_type {};

    template<ICPR3_CLRPEND_T val>
    using CLRPEND = Register::Combo_Bitfield<icpr3_reg_type, 0, 32, ICPR3_CLRPEND_T, val>;

} // NVIC_ICPR3
namespace NVIC_IABR0 {

    enum class iabr0_reg_type {};

    template<IABR0_ACTIVE_T val>
    using ACTIVE = Register::Combo_Bitfield<iabr0_reg_type, 0, 32, IABR0_ACTIVE_T, val>;

} // NVIC_IABR0
namespace NVIC_IABR1 {

    enum class iabr1_reg_type {};

    template<IABR1_ACTIVE_T val>
    using ACTIVE = Register::Combo_Bitfield<iabr1_reg_type, 0, 32, IABR1_ACTIVE_T, val>;

} // NVIC_IABR1
namespace NVIC_IABR2 {

    enum class iabr2_reg_type {};

    template<IABR2_ACTIVE_T val>
    using ACTIVE = Register::Combo_Bitfield<iabr2_reg_type, 0, 32, IABR2_ACTIVE_T, val>;

} // NVIC_IABR2
namespace NVIC_IABR3 {

    enum class iabr3_reg_type {};

    template<IABR3_ACTIVE_T val>
    using ACTIVE = Register::Combo_Bitfield<iabr3_reg_type, 0, 32, IABR3_ACTIVE_T, val>;

} // NVIC_IABR3
namespace NVIC_IPR0 {

    enum class ipr0_reg_type {};

    template<IPR0_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr0_reg_type, 0, 8, IPR0_IPR_N0_T, val>;

    template<IPR0_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr0_reg_type, 8, 8, IPR0_IPR_N1_T, val>;

    template<IPR0_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr0_reg_type, 16, 8, IPR0_IPR_N2_T, val>;

    template<IPR0_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr0_reg_type, 24, 8, IPR0_IPR_N3_T, val>;

} // NVIC_IPR0
namespace NVIC_IPR1 {

    enum class ipr1_reg_type {};

    template<IPR1_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr1_reg_type, 0, 8, IPR1_IPR_N0_T, val>;

    template<IPR1_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr1_reg_type, 8, 8, IPR1_IPR_N1_T, val>;

    template<IPR1_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr1_reg_type, 16, 8, IPR1_IPR_N2_T, val>;

    template<IPR1_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr1_reg_type, 24, 8, IPR1_IPR_N3_T, val>;

} // NVIC_IPR1
namespace NVIC_IPR2 {

    enum class ipr2_reg_type {};

    template<IPR2_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr2_reg_type, 0, 8, IPR2_IPR_N0_T, val>;

    template<IPR2_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr2_reg_type, 8, 8, IPR2_IPR_N1_T, val>;

    template<IPR2_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr2_reg_type, 16, 8, IPR2_IPR_N2_T, val>;

    template<IPR2_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr2_reg_type, 24, 8, IPR2_IPR_N3_T, val>;

} // NVIC_IPR2
namespace NVIC_IPR3 {

    enum class ipr3_reg_type {};

    template<IPR3_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr3_reg_type, 0, 8, IPR3_IPR_N0_T, val>;

    template<IPR3_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr3_reg_type, 8, 8, IPR3_IPR_N1_T, val>;

    template<IPR3_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr3_reg_type, 16, 8, IPR3_IPR_N2_T, val>;

    template<IPR3_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr3_reg_type, 24, 8, IPR3_IPR_N3_T, val>;

} // NVIC_IPR3
namespace NVIC_IPR4 {

    enum class ipr4_reg_type {};

    template<IPR4_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr4_reg_type, 0, 8, IPR4_IPR_N0_T, val>;

    template<IPR4_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr4_reg_type, 8, 8, IPR4_IPR_N1_T, val>;

    template<IPR4_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr4_reg_type, 16, 8, IPR4_IPR_N2_T, val>;

    template<IPR4_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr4_reg_type, 24, 8, IPR4_IPR_N3_T, val>;

} // NVIC_IPR4
namespace NVIC_IPR5 {

    enum class ipr5_reg_type {};

    template<IPR5_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr5_reg_type, 0, 8, IPR5_IPR_N0_T, val>;

    template<IPR5_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr5_reg_type, 8, 8, IPR5_IPR_N1_T, val>;

    template<IPR5_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr5_reg_type, 16, 8, IPR5_IPR_N2_T, val>;

    template<IPR5_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr5_reg_type, 24, 8, IPR5_IPR_N3_T, val>;

} // NVIC_IPR5
namespace NVIC_IPR6 {

    enum class ipr6_reg_type {};

    template<IPR6_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr6_reg_type, 0, 8, IPR6_IPR_N0_T, val>;

    template<IPR6_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr6_reg_type, 8, 8, IPR6_IPR_N1_T, val>;

    template<IPR6_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr6_reg_type, 16, 8, IPR6_IPR_N2_T, val>;

    template<IPR6_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr6_reg_type, 24, 8, IPR6_IPR_N3_T, val>;

} // NVIC_IPR6
namespace NVIC_IPR7 {

    enum class ipr7_reg_type {};

    template<IPR7_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr7_reg_type, 0, 8, IPR7_IPR_N0_T, val>;

    template<IPR7_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr7_reg_type, 8, 8, IPR7_IPR_N1_T, val>;

    template<IPR7_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr7_reg_type, 16, 8, IPR7_IPR_N2_T, val>;

    template<IPR7_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr7_reg_type, 24, 8, IPR7_IPR_N3_T, val>;

} // NVIC_IPR7
namespace NVIC_IPR8 {

    enum class ipr8_reg_type {};

    template<IPR8_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr8_reg_type, 0, 8, IPR8_IPR_N0_T, val>;

    template<IPR8_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr8_reg_type, 8, 8, IPR8_IPR_N1_T, val>;

    template<IPR8_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr8_reg_type, 16, 8, IPR8_IPR_N2_T, val>;

    template<IPR8_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr8_reg_type, 24, 8, IPR8_IPR_N3_T, val>;

} // NVIC_IPR8
namespace NVIC_IPR9 {

    enum class ipr9_reg_type {};

    template<IPR9_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr9_reg_type, 0, 8, IPR9_IPR_N0_T, val>;

    template<IPR9_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr9_reg_type, 8, 8, IPR9_IPR_N1_T, val>;

    template<IPR9_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr9_reg_type, 16, 8, IPR9_IPR_N2_T, val>;

    template<IPR9_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr9_reg_type, 24, 8, IPR9_IPR_N3_T, val>;

} // NVIC_IPR9
namespace NVIC_IPR10 {

    enum class ipr10_reg_type {};

    template<IPR10_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr10_reg_type, 0, 8, IPR10_IPR_N0_T, val>;

    template<IPR10_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr10_reg_type, 8, 8, IPR10_IPR_N1_T, val>;

    template<IPR10_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr10_reg_type, 16, 8, IPR10_IPR_N2_T, val>;

    template<IPR10_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr10_reg_type, 24, 8, IPR10_IPR_N3_T, val>;

} // NVIC_IPR10
namespace NVIC_IPR11 {

    enum class ipr11_reg_type {};

    template<IPR11_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr11_reg_type, 0, 8, IPR11_IPR_N0_T, val>;

    template<IPR11_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr11_reg_type, 8, 8, IPR11_IPR_N1_T, val>;

    template<IPR11_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr11_reg_type, 16, 8, IPR11_IPR_N2_T, val>;

    template<IPR11_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr11_reg_type, 24, 8, IPR11_IPR_N3_T, val>;

} // NVIC_IPR11
namespace NVIC_IPR12 {

    enum class ipr12_reg_type {};

    template<IPR12_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr12_reg_type, 0, 8, IPR12_IPR_N0_T, val>;

    template<IPR12_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr12_reg_type, 8, 8, IPR12_IPR_N1_T, val>;

    template<IPR12_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr12_reg_type, 16, 8, IPR12_IPR_N2_T, val>;

    template<IPR12_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr12_reg_type, 24, 8, IPR12_IPR_N3_T, val>;

} // NVIC_IPR12
namespace NVIC_IPR13 {

    enum class ipr13_reg_type {};

    template<IPR13_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr13_reg_type, 0, 8, IPR13_IPR_N0_T, val>;

    template<IPR13_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr13_reg_type, 8, 8, IPR13_IPR_N1_T, val>;

    template<IPR13_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr13_reg_type, 16, 8, IPR13_IPR_N2_T, val>;

    template<IPR13_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr13_reg_type, 24, 8, IPR13_IPR_N3_T, val>;

} // NVIC_IPR13
namespace NVIC_IPR14 {

    enum class ipr14_reg_type {};

    template<IPR14_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr14_reg_type, 0, 8, IPR14_IPR_N0_T, val>;

    template<IPR14_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr14_reg_type, 8, 8, IPR14_IPR_N1_T, val>;

    template<IPR14_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr14_reg_type, 16, 8, IPR14_IPR_N2_T, val>;

    template<IPR14_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr14_reg_type, 24, 8, IPR14_IPR_N3_T, val>;

} // NVIC_IPR14
namespace NVIC_IPR15 {

    enum class ipr15_reg_type {};

    template<IPR15_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr15_reg_type, 0, 8, IPR15_IPR_N0_T, val>;

    template<IPR15_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr15_reg_type, 8, 8, IPR15_IPR_N1_T, val>;

    template<IPR15_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr15_reg_type, 16, 8, IPR15_IPR_N2_T, val>;

    template<IPR15_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr15_reg_type, 24, 8, IPR15_IPR_N3_T, val>;

} // NVIC_IPR15
namespace NVIC_IPR16 {

    enum class ipr16_reg_type {};

    template<IPR16_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr16_reg_type, 0, 8, IPR16_IPR_N0_T, val>;

    template<IPR16_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr16_reg_type, 8, 8, IPR16_IPR_N1_T, val>;

    template<IPR16_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr16_reg_type, 16, 8, IPR16_IPR_N2_T, val>;

    template<IPR16_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr16_reg_type, 24, 8, IPR16_IPR_N3_T, val>;

} // NVIC_IPR16
namespace NVIC_IPR17 {

    enum class ipr17_reg_type {};

    template<IPR17_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr17_reg_type, 0, 8, IPR17_IPR_N0_T, val>;

    template<IPR17_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr17_reg_type, 8, 8, IPR17_IPR_N1_T, val>;

    template<IPR17_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr17_reg_type, 16, 8, IPR17_IPR_N2_T, val>;

    template<IPR17_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr17_reg_type, 24, 8, IPR17_IPR_N3_T, val>;

} // NVIC_IPR17
namespace NVIC_IPR18 {

    enum class ipr18_reg_type {};

    template<IPR18_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr18_reg_type, 0, 8, IPR18_IPR_N0_T, val>;

    template<IPR18_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr18_reg_type, 8, 8, IPR18_IPR_N1_T, val>;

    template<IPR18_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr18_reg_type, 16, 8, IPR18_IPR_N2_T, val>;

    template<IPR18_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr18_reg_type, 24, 8, IPR18_IPR_N3_T, val>;

} // NVIC_IPR18
namespace NVIC_IPR19 {

    enum class ipr19_reg_type {};

    template<IPR19_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr19_reg_type, 0, 8, IPR19_IPR_N0_T, val>;

    template<IPR19_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr19_reg_type, 8, 8, IPR19_IPR_N1_T, val>;

    template<IPR19_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr19_reg_type, 16, 8, IPR19_IPR_N2_T, val>;

    template<IPR19_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr19_reg_type, 24, 8, IPR19_IPR_N3_T, val>;

} // NVIC_IPR19
namespace NVIC_IPR20 {

    enum class ipr20_reg_type {};

    template<IPR20_IPR_N0_T val>
    using IPR_N0 = Register::Combo_Bitfield<ipr20_reg_type, 0, 8, IPR20_IPR_N0_T, val>;

    template<IPR20_IPR_N1_T val>
    using IPR_N1 = Register::Combo_Bitfield<ipr20_reg_type, 8, 8, IPR20_IPR_N1_T, val>;

    template<IPR20_IPR_N2_T val>
    using IPR_N2 = Register::Combo_Bitfield<ipr20_reg_type, 16, 8, IPR20_IPR_N2_T, val>;

    template<IPR20_IPR_N3_T val>
    using IPR_N3 = Register::Combo_Bitfield<ipr20_reg_type, 24, 8, IPR20_IPR_N3_T, val>;

} // NVIC_IPR20
namespace NVIC_IPR21 {

    enum class ipr21_reg_type {};

} // NVIC_IPR21
namespace NVIC_IPR22 {

    enum class ipr22_reg_type {};

} // NVIC_IPR22
namespace NVIC_IPR23 {

    enum class ipr23_reg_type {};

} // NVIC_IPR23
namespace NVIC_IPR24 {

    enum class ipr24_reg_type {};

} // NVIC_IPR24
namespace NVIC_IPR25 {

    enum class ipr25_reg_type {};

} // NVIC_IPR25
template<uint32_t BASE_ADDRESS>
class NVIC {
public:
    static const uint32_t ISER0_Offset = 0x0000;
    static const uint32_t ISER1_Offset = 0x0004;
    static const uint32_t ISER2_Offset = 0x0008;
    static const uint32_t ISER3_Offset = 0x000C;
    static const uint32_t ICER0_Offset = 0x0080;
    static const uint32_t ICER1_Offset = 0x0084;
    static const uint32_t ICER2_Offset = 0x0088;
    static const uint32_t ICER3_Offset = 0x008C;
    static const uint32_t ISPR0_Offset = 0x0100;
    static const uint32_t ISPR1_Offset = 0x0104;
    static const uint32_t ISPR2_Offset = 0x0108;
    static const uint32_t ISPR3_Offset = 0x010C;
    static const uint32_t ICPR0_Offset = 0x0180;
    static const uint32_t ICPR1_Offset = 0x0184;
    static const uint32_t ICPR2_Offset = 0x0188;
    static const uint32_t ICPR3_Offset = 0x018C;
    static const uint32_t IABR0_Offset = 0x0200;
    static const uint32_t IABR1_Offset = 0x0204;
    static const uint32_t IABR2_Offset = 0x0208;
    static const uint32_t IABR3_Offset = 0x020C;
    static const uint32_t IPR0_Offset = 0x0300;
    static const uint32_t IPR1_Offset = 0x0304;
    static const uint32_t IPR2_Offset = 0x0308;
    static const uint32_t IPR3_Offset = 0x030C;
    static const uint32_t IPR4_Offset = 0x0310;
    static const uint32_t IPR5_Offset = 0x0314;
    static const uint32_t IPR6_Offset = 0x0318;
    static const uint32_t IPR7_Offset = 0x031C;
    static const uint32_t IPR8_Offset = 0x0320;
    static const uint32_t IPR9_Offset = 0x0324;
    static const uint32_t IPR10_Offset = 0x0328;
    static const uint32_t IPR11_Offset = 0x032C;
    static const uint32_t IPR12_Offset = 0x0330;
    static const uint32_t IPR13_Offset = 0x0334;
    static const uint32_t IPR14_Offset = 0x0338;
    static const uint32_t IPR15_Offset = 0x033C;
    static const uint32_t IPR16_Offset = 0x0340;
    static const uint32_t IPR17_Offset = 0x0344;
    static const uint32_t IPR18_Offset = 0x0348;
    static const uint32_t IPR19_Offset = 0x034C;
    static const uint32_t IPR20_Offset = 0x0350;
    static const uint32_t IPR21_Offset = 0x0354;
    static const uint32_t IPR22_Offset = 0x0358;
    static const uint32_t IPR23_Offset = 0x035C;
    static const uint32_t IPR24_Offset = 0x0360;
    static const uint32_t IPR25_Offset = 0x0364;

    NVIC() = default;
    NVIC( const NVIC& ) = delete;
    const NVIC& operator=( const NVIC& ) = delete;

    class ISER0_T : public Register::Register<NVIC_ISER0::iser0_reg_type, BASE_ADDRESS + ISER0_Offset> {
    // Interrupt Set-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISER0_Offset, 0, 32, ISER0_SETENA_T> SETENA; /* SETENA */
    };

    class ISER1_T : public Register::Register<NVIC_ISER1::iser1_reg_type, BASE_ADDRESS + ISER1_Offset> {
    // Interrupt Set-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISER1_Offset, 0, 32, ISER1_SETENA_T> SETENA; /* SETENA */
    };

    class ISER2_T : public Register::Register<NVIC_ISER2::iser2_reg_type, BASE_ADDRESS + ISER2_Offset> {
    // Interrupt Set-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISER2_Offset, 0, 32, ISER2_SETENA_T> SETENA; /* SETENA */
    };

    class ISER3_T : public Register::Register<NVIC_ISER3::iser3_reg_type, BASE_ADDRESS + ISER3_Offset> {
    // Interrupt Set-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISER3_Offset, 0, 32, ISER3_SETENA_T> SETENA; /* SETENA */
    };

    class ICER0_T : public Register::Register<NVIC_ICER0::icer0_reg_type, BASE_ADDRESS + ICER0_Offset> {
    // Interrupt Clear-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICER0_Offset, 0, 32, ICER0_CLRENA_T> CLRENA; /* CLRENA */
    };

    class ICER1_T : public Register::Register<NVIC_ICER1::icer1_reg_type, BASE_ADDRESS + ICER1_Offset> {
    // Interrupt Clear-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICER1_Offset, 0, 32, ICER1_CLRENA_T> CLRENA; /* CLRENA */
    };

    class ICER2_T : public Register::Register<NVIC_ICER2::icer2_reg_type, BASE_ADDRESS + ICER2_Offset> {
    // Interrupt Clear-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICER2_Offset, 0, 32, ICER2_CLRENA_T> CLRENA; /* CLRENA */
    };

    class ICER3_T : public Register::Register<NVIC_ICER3::icer3_reg_type, BASE_ADDRESS + ICER3_Offset> {
    // Interrupt Clear-Enable Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICER3_Offset, 0, 32, ICER3_CLRENA_T> CLRENA; /* CLRENA */
    };

    class ISPR0_T : public Register::Register<NVIC_ISPR0::ispr0_reg_type, BASE_ADDRESS + ISPR0_Offset> {
    // Interrupt Set-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISPR0_Offset, 0, 32, ISPR0_SETPEND_T> SETPEND; /* SETPEND */
    };

    class ISPR1_T : public Register::Register<NVIC_ISPR1::ispr1_reg_type, BASE_ADDRESS + ISPR1_Offset> {
    // Interrupt Set-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISPR1_Offset, 0, 32, ISPR1_SETPEND_T> SETPEND; /* SETPEND */
    };

    class ISPR2_T : public Register::Register<NVIC_ISPR2::ispr2_reg_type, BASE_ADDRESS + ISPR2_Offset> {
    // Interrupt Set-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISPR2_Offset, 0, 32, ISPR2_SETPEND_T> SETPEND; /* SETPEND */
    };

    class ISPR3_T : public Register::Register<NVIC_ISPR3::ispr3_reg_type, BASE_ADDRESS + ISPR3_Offset> {
    // Interrupt Set-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ISPR3_Offset, 0, 32, ISPR3_SETPEND_T> SETPEND; /* SETPEND */
    };

    class ICPR0_T : public Register::Register<NVIC_ICPR0::icpr0_reg_type, BASE_ADDRESS + ICPR0_Offset> {
    // Interrupt Clear-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICPR0_Offset, 0, 32, ICPR0_CLRPEND_T> CLRPEND; /* CLRPEND */
    };

    class ICPR1_T : public Register::Register<NVIC_ICPR1::icpr1_reg_type, BASE_ADDRESS + ICPR1_Offset> {
    // Interrupt Clear-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICPR1_Offset, 0, 32, ICPR1_CLRPEND_T> CLRPEND; /* CLRPEND */
    };

    class ICPR2_T : public Register::Register<NVIC_ICPR2::icpr2_reg_type, BASE_ADDRESS + ICPR2_Offset> {
    // Interrupt Clear-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICPR2_Offset, 0, 32, ICPR2_CLRPEND_T> CLRPEND; /* CLRPEND */
    };

    class ICPR3_T : public Register::Register<NVIC_ICPR3::icpr3_reg_type, BASE_ADDRESS + ICPR3_Offset> {
    // Interrupt Clear-Pending Register
    public:
        Register::Bitfield<BASE_ADDRESS + ICPR3_Offset, 0, 32, ICPR3_CLRPEND_T> CLRPEND; /* CLRPEND */
    };

    class IABR0_T : public Register::Register<NVIC_IABR0::iabr0_reg_type, BASE_ADDRESS + IABR0_Offset> {
    // Interrupt Active Bit Register
    public:
        Register::Bitfield<BASE_ADDRESS + IABR0_Offset, 0, 32, IABR0_ACTIVE_T> ACTIVE; /* ACTIVE */
    };

    class IABR1_T : public Register::Register<NVIC_IABR1::iabr1_reg_type, BASE_ADDRESS + IABR1_Offset> {
    // Interrupt Active Bit Register
    public:
        Register::Bitfield<BASE_ADDRESS + IABR1_Offset, 0, 32, IABR1_ACTIVE_T> ACTIVE; /* ACTIVE */
    };

    class IABR2_T : public Register::Register<NVIC_IABR2::iabr2_reg_type, BASE_ADDRESS + IABR2_Offset> {
    // Interrupt Active Bit Register
    public:
        Register::Bitfield<BASE_ADDRESS + IABR2_Offset, 0, 32, IABR2_ACTIVE_T> ACTIVE; /* ACTIVE */
    };

    class IABR3_T : public Register::Register<NVIC_IABR3::iabr3_reg_type, BASE_ADDRESS + IABR3_Offset> {
    // Interrupt Active Bit Register
    public:
        Register::Bitfield<BASE_ADDRESS + IABR3_Offset, 0, 32, IABR3_ACTIVE_T> ACTIVE; /* ACTIVE */
    };

    class IPR0_T : public Register::Register<NVIC_IPR0::ipr0_reg_type, BASE_ADDRESS + IPR0_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR0_Offset, 0, 8, IPR0_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR0_Offset, 8, 8, IPR0_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR0_Offset, 16, 8, IPR0_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR0_Offset, 24, 8, IPR0_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR1_T : public Register::Register<NVIC_IPR1::ipr1_reg_type, BASE_ADDRESS + IPR1_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR1_Offset, 0, 8, IPR1_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR1_Offset, 8, 8, IPR1_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR1_Offset, 16, 8, IPR1_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR1_Offset, 24, 8, IPR1_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR2_T : public Register::Register<NVIC_IPR2::ipr2_reg_type, BASE_ADDRESS + IPR2_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR2_Offset, 0, 8, IPR2_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR2_Offset, 8, 8, IPR2_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR2_Offset, 16, 8, IPR2_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR2_Offset, 24, 8, IPR2_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR3_T : public Register::Register<NVIC_IPR3::ipr3_reg_type, BASE_ADDRESS + IPR3_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR3_Offset, 0, 8, IPR3_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR3_Offset, 8, 8, IPR3_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR3_Offset, 16, 8, IPR3_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR3_Offset, 24, 8, IPR3_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR4_T : public Register::Register<NVIC_IPR4::ipr4_reg_type, BASE_ADDRESS + IPR4_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR4_Offset, 0, 8, IPR4_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR4_Offset, 8, 8, IPR4_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR4_Offset, 16, 8, IPR4_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR4_Offset, 24, 8, IPR4_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR5_T : public Register::Register<NVIC_IPR5::ipr5_reg_type, BASE_ADDRESS + IPR5_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR5_Offset, 0, 8, IPR5_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR5_Offset, 8, 8, IPR5_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR5_Offset, 16, 8, IPR5_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR5_Offset, 24, 8, IPR5_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR6_T : public Register::Register<NVIC_IPR6::ipr6_reg_type, BASE_ADDRESS + IPR6_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR6_Offset, 0, 8, IPR6_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR6_Offset, 8, 8, IPR6_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR6_Offset, 16, 8, IPR6_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR6_Offset, 24, 8, IPR6_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR7_T : public Register::Register<NVIC_IPR7::ipr7_reg_type, BASE_ADDRESS + IPR7_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR7_Offset, 0, 8, IPR7_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR7_Offset, 8, 8, IPR7_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR7_Offset, 16, 8, IPR7_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR7_Offset, 24, 8, IPR7_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR8_T : public Register::Register<NVIC_IPR8::ipr8_reg_type, BASE_ADDRESS + IPR8_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR8_Offset, 0, 8, IPR8_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR8_Offset, 8, 8, IPR8_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR8_Offset, 16, 8, IPR8_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR8_Offset, 24, 8, IPR8_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR9_T : public Register::Register<NVIC_IPR9::ipr9_reg_type, BASE_ADDRESS + IPR9_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR9_Offset, 0, 8, IPR9_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR9_Offset, 8, 8, IPR9_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR9_Offset, 16, 8, IPR9_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR9_Offset, 24, 8, IPR9_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR10_T : public Register::Register<NVIC_IPR10::ipr10_reg_type, BASE_ADDRESS + IPR10_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR10_Offset, 0, 8, IPR10_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR10_Offset, 8, 8, IPR10_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR10_Offset, 16, 8, IPR10_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR10_Offset, 24, 8, IPR10_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR11_T : public Register::Register<NVIC_IPR11::ipr11_reg_type, BASE_ADDRESS + IPR11_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR11_Offset, 0, 8, IPR11_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR11_Offset, 8, 8, IPR11_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR11_Offset, 16, 8, IPR11_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR11_Offset, 24, 8, IPR11_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR12_T : public Register::Register<NVIC_IPR12::ipr12_reg_type, BASE_ADDRESS + IPR12_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR12_Offset, 0, 8, IPR12_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR12_Offset, 8, 8, IPR12_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR12_Offset, 16, 8, IPR12_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR12_Offset, 24, 8, IPR12_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR13_T : public Register::Register<NVIC_IPR13::ipr13_reg_type, BASE_ADDRESS + IPR13_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR13_Offset, 0, 8, IPR13_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR13_Offset, 8, 8, IPR13_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR13_Offset, 16, 8, IPR13_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR13_Offset, 24, 8, IPR13_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR14_T : public Register::Register<NVIC_IPR14::ipr14_reg_type, BASE_ADDRESS + IPR14_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR14_Offset, 0, 8, IPR14_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR14_Offset, 8, 8, IPR14_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR14_Offset, 16, 8, IPR14_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR14_Offset, 24, 8, IPR14_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR15_T : public Register::Register<NVIC_IPR15::ipr15_reg_type, BASE_ADDRESS + IPR15_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR15_Offset, 0, 8, IPR15_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR15_Offset, 8, 8, IPR15_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR15_Offset, 16, 8, IPR15_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR15_Offset, 24, 8, IPR15_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR16_T : public Register::Register<NVIC_IPR16::ipr16_reg_type, BASE_ADDRESS + IPR16_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR16_Offset, 0, 8, IPR16_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR16_Offset, 8, 8, IPR16_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR16_Offset, 16, 8, IPR16_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR16_Offset, 24, 8, IPR16_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR17_T : public Register::Register<NVIC_IPR17::ipr17_reg_type, BASE_ADDRESS + IPR17_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR17_Offset, 0, 8, IPR17_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR17_Offset, 8, 8, IPR17_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR17_Offset, 16, 8, IPR17_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR17_Offset, 24, 8, IPR17_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR18_T : public Register::Register<NVIC_IPR18::ipr18_reg_type, BASE_ADDRESS + IPR18_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR18_Offset, 0, 8, IPR18_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR18_Offset, 8, 8, IPR18_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR18_Offset, 16, 8, IPR18_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR18_Offset, 24, 8, IPR18_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR19_T : public Register::Register<NVIC_IPR19::ipr19_reg_type, BASE_ADDRESS + IPR19_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR19_Offset, 0, 8, IPR19_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR19_Offset, 8, 8, IPR19_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR19_Offset, 16, 8, IPR19_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR19_Offset, 24, 8, IPR19_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR20_T : public Register::Register<NVIC_IPR20::ipr20_reg_type, BASE_ADDRESS + IPR20_Offset> {
    // Interrupt Priority Register
    public:
        Register::Bitfield<BASE_ADDRESS + IPR20_Offset, 0, 8, IPR20_IPR_N0_T> IPR_N0; /* IPR_N0 */
        Register::Bitfield<BASE_ADDRESS + IPR20_Offset, 8, 8, IPR20_IPR_N1_T> IPR_N1; /* IPR_N1 */
        Register::Bitfield<BASE_ADDRESS + IPR20_Offset, 16, 8, IPR20_IPR_N2_T> IPR_N2; /* IPR_N2 */
        Register::Bitfield<BASE_ADDRESS + IPR20_Offset, 24, 8, IPR20_IPR_N3_T> IPR_N3; /* IPR_N3 */
    };

    class IPR21_T : public Register::Register<NVIC_IPR21::ipr21_reg_type, BASE_ADDRESS + IPR21_Offset> {
    // Interrupt Priority Register
    public:
    };

    class IPR22_T : public Register::Register<NVIC_IPR22::ipr22_reg_type, BASE_ADDRESS + IPR22_Offset> {
    // Interrupt Priority Register
    public:
    };

    class IPR23_T : public Register::Register<NVIC_IPR23::ipr23_reg_type, BASE_ADDRESS + IPR23_Offset> {
    // Interrupt Priority Register
    public:
    };

    class IPR24_T : public Register::Register<NVIC_IPR24::ipr24_reg_type, BASE_ADDRESS + IPR24_Offset> {
    // Interrupt Priority Register
    public:
    };

    class IPR25_T : public Register::Register<NVIC_IPR25::ipr25_reg_type, BASE_ADDRESS + IPR25_Offset> {
    // Interrupt Priority Register
    public:
    };

    ISER0_T ISER0;
    ISER1_T ISER1;
    ISER2_T ISER2;
    ISER3_T ISER3;
    ICER0_T ICER0;
    ICER1_T ICER1;
    ICER2_T ICER2;
    ICER3_T ICER3;
    ISPR0_T ISPR0;
    ISPR1_T ISPR1;
    ISPR2_T ISPR2;
    ISPR3_T ISPR3;
    ICPR0_T ICPR0;
    ICPR1_T ICPR1;
    ICPR2_T ICPR2;
    ICPR3_T ICPR3;
    IABR0_T IABR0;
    IABR1_T IABR1;
    IABR2_T IABR2;
    IABR3_T IABR3;
    IPR0_T IPR0;
    IPR1_T IPR1;
    IPR2_T IPR2;
    IPR3_T IPR3;
    IPR4_T IPR4;
    IPR5_T IPR5;
    IPR6_T IPR6;
    IPR7_T IPR7;
    IPR8_T IPR8;
    IPR9_T IPR9;
    IPR10_T IPR10;
    IPR11_T IPR11;
    IPR12_T IPR12;
    IPR13_T IPR13;
    IPR14_T IPR14;
    IPR15_T IPR15;
    IPR16_T IPR16;
    IPR17_T IPR17;
    IPR18_T IPR18;
    IPR19_T IPR19;
    IPR20_T IPR20;
    IPR21_T IPR21;
    IPR22_T IPR22;
    IPR23_T IPR23;
    IPR24_T IPR24;
    IPR25_T IPR25;
};

} // namespace STM32LIB

#endif // STM32G473XX_NVIC_HPP_

