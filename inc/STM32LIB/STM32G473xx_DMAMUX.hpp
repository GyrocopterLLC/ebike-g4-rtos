#ifndef STM32G473XX_DMAMUX_HPP_
#define STM32G473XX_DMAMUX_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"

/* DMAMUX */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using C0CR_DMAREQ_ID_T = uint32_t;
using C0CR_SPOL_T = uint32_t;
using C0CR_NBREQ_T = uint32_t;
using C0CR_SYNC_ID_T = uint32_t;
using C1CR_DMAREQ_ID_T = uint32_t;
using C1CR_SPOL_T = uint32_t;
using C1CR_NBREQ_T = uint32_t;
using C1CR_SYNC_ID_T = uint32_t;
using C2CR_DMAREQ_ID_T = uint32_t;
using C2CR_SPOL_T = uint32_t;
using C2CR_NBREQ_T = uint32_t;
using C2CR_SYNC_ID_T = uint32_t;
using C3CR_DMAREQ_ID_T = uint32_t;
using C3CR_SPOL_T = uint32_t;
using C3CR_NBREQ_T = uint32_t;
using C3CR_SYNC_ID_T = uint32_t;
using C4CR_DMAREQ_ID_T = uint32_t;
using C4CR_SPOL_T = uint32_t;
using C4CR_NBREQ_T = uint32_t;
using C4CR_SYNC_ID_T = uint32_t;
using C5CR_DMAREQ_ID_T = uint32_t;
using C5CR_SPOL_T = uint32_t;
using C5CR_NBREQ_T = uint32_t;
using C5CR_SYNC_ID_T = uint32_t;
using C6CR_DMAREQ_ID_T = uint32_t;
using C6CR_SPOL_T = uint32_t;
using C6CR_NBREQ_T = uint32_t;
using C6CR_SYNC_ID_T = uint32_t;
using C7CR_DMAREQ_ID_T = uint32_t;
using C7CR_SPOL_T = uint32_t;
using C7CR_NBREQ_T = uint32_t;
using C7CR_SYNC_ID_T = uint32_t;
using C8CR_DMAREQ_ID_T = uint32_t;
using C8CR_SPOL_T = uint32_t;
using C8CR_NBREQ_T = uint32_t;
using C8CR_SYNC_ID_T = uint32_t;
using C9CR_DMAREQ_ID_T = uint32_t;
using C9CR_SPOL_T = uint32_t;
using C9CR_NBREQ_T = uint32_t;
using C9CR_SYNC_ID_T = uint32_t;
using C10CR_DMAREQ_ID_T = uint32_t;
using C10CR_SPOL_T = uint32_t;
using C10CR_NBREQ_T = uint32_t;
using C10CR_SYNC_ID_T = uint32_t;
using C11CR_DMAREQ_ID_T = uint32_t;
using C11CR_SPOL_T = uint32_t;
using C11CR_NBREQ_T = uint32_t;
using C11CR_SYNC_ID_T = uint32_t;
using C12CR_DMAREQ_ID_T = uint32_t;
using C12CR_SPOL_T = uint32_t;
using C12CR_NBREQ_T = uint32_t;
using C12CR_SYNC_ID_T = uint32_t;
using C13CR_DMAREQ_ID_T = uint32_t;
using C13CR_SPOL_T = uint32_t;
using C13CR_NBREQ_T = uint32_t;
using C13CR_SYNC_ID_T = uint32_t;
using C14CR_DMAREQ_ID_T = uint32_t;
using C14CR_SPOL_T = uint32_t;
using C14CR_NBREQ_T = uint32_t;
using C14CR_SYNC_ID_T = uint32_t;
using C15CR_DMAREQ_ID_T = uint32_t;
using C15CR_SPOL_T = uint32_t;
using C15CR_NBREQ_T = uint32_t;
using C15CR_SYNC_ID_T = uint32_t;
using CSR_SOF_T = uint32_t;
using CFR_CSOF_T = uint32_t;
using RG0CR_SIG_ID_T = uint32_t;
using RG0CR_GPOL_T = uint32_t;
using RG0CR_GNBREQ_T = uint32_t;
using RG1CR_SIG_ID_T = uint32_t;
using RG1CR_GPOL_T = uint32_t;
using RG1CR_GNBREQ_T = uint32_t;
using RG2CR_SIG_ID_T = uint32_t;
using RG2CR_GPOL_T = uint32_t;
using RG2CR_GNBREQ_T = uint32_t;
using RG3CR_SIG_ID_T = uint32_t;
using RG3CR_GPOL_T = uint32_t;
using RG3CR_GNBREQ_T = uint32_t;
using RGSR_OF_T = uint32_t;
using RGCFR_COF_T = uint32_t;

namespace DMAMUX_C0CR {

    enum class c0cr_reg_type {};

    template<C0CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c0cr_reg_type, 0, 7, C0CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c0cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c0cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c0cr_reg_type, 16, tf>;

    template<C0CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c0cr_reg_type, 17, 2, C0CR_SPOL_T, val>;

    template<C0CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c0cr_reg_type, 19, 5, C0CR_NBREQ_T, val>;

    template<C0CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c0cr_reg_type, 24, 5, C0CR_SYNC_ID_T, val>;

} // DMAMUX_C0CR
namespace DMAMUX_C1CR {

    enum class c1cr_reg_type {};

    template<C1CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c1cr_reg_type, 0, 7, C1CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c1cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c1cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c1cr_reg_type, 16, tf>;

    template<C1CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c1cr_reg_type, 17, 2, C1CR_SPOL_T, val>;

    template<C1CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c1cr_reg_type, 19, 5, C1CR_NBREQ_T, val>;

    template<C1CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c1cr_reg_type, 24, 5, C1CR_SYNC_ID_T, val>;

} // DMAMUX_C1CR
namespace DMAMUX_C2CR {

    enum class c2cr_reg_type {};

    template<C2CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c2cr_reg_type, 0, 7, C2CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c2cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c2cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c2cr_reg_type, 16, tf>;

    template<C2CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c2cr_reg_type, 17, 2, C2CR_SPOL_T, val>;

    template<C2CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c2cr_reg_type, 19, 5, C2CR_NBREQ_T, val>;

    template<C2CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c2cr_reg_type, 24, 5, C2CR_SYNC_ID_T, val>;

} // DMAMUX_C2CR
namespace DMAMUX_C3CR {

    enum class c3cr_reg_type {};

    template<C3CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c3cr_reg_type, 0, 7, C3CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c3cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c3cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c3cr_reg_type, 16, tf>;

    template<C3CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c3cr_reg_type, 17, 2, C3CR_SPOL_T, val>;

    template<C3CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c3cr_reg_type, 19, 5, C3CR_NBREQ_T, val>;

    template<C3CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c3cr_reg_type, 24, 5, C3CR_SYNC_ID_T, val>;

} // DMAMUX_C3CR
namespace DMAMUX_C4CR {

    enum class c4cr_reg_type {};

    template<C4CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c4cr_reg_type, 0, 7, C4CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c4cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c4cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c4cr_reg_type, 16, tf>;

    template<C4CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c4cr_reg_type, 17, 2, C4CR_SPOL_T, val>;

    template<C4CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c4cr_reg_type, 19, 5, C4CR_NBREQ_T, val>;

    template<C4CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c4cr_reg_type, 24, 5, C4CR_SYNC_ID_T, val>;

} // DMAMUX_C4CR
namespace DMAMUX_C5CR {

    enum class c5cr_reg_type {};

    template<C5CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c5cr_reg_type, 0, 7, C5CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c5cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c5cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c5cr_reg_type, 16, tf>;

    template<C5CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c5cr_reg_type, 17, 2, C5CR_SPOL_T, val>;

    template<C5CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c5cr_reg_type, 19, 5, C5CR_NBREQ_T, val>;

    template<C5CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c5cr_reg_type, 24, 5, C5CR_SYNC_ID_T, val>;

} // DMAMUX_C5CR
namespace DMAMUX_C6CR {

    enum class c6cr_reg_type {};

    template<C6CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c6cr_reg_type, 0, 7, C6CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c6cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c6cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c6cr_reg_type, 16, tf>;

    template<C6CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c6cr_reg_type, 17, 2, C6CR_SPOL_T, val>;

    template<C6CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c6cr_reg_type, 19, 5, C6CR_NBREQ_T, val>;

    template<C6CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c6cr_reg_type, 24, 5, C6CR_SYNC_ID_T, val>;

} // DMAMUX_C6CR
namespace DMAMUX_C7CR {

    enum class c7cr_reg_type {};

    template<C7CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c7cr_reg_type, 0, 7, C7CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c7cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c7cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c7cr_reg_type, 16, tf>;

    template<C7CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c7cr_reg_type, 17, 2, C7CR_SPOL_T, val>;

    template<C7CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c7cr_reg_type, 19, 5, C7CR_NBREQ_T, val>;

    template<C7CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c7cr_reg_type, 24, 5, C7CR_SYNC_ID_T, val>;

} // DMAMUX_C7CR
namespace DMAMUX_C8CR {

    enum class c8cr_reg_type {};

    template<C8CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c8cr_reg_type, 0, 7, C8CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c8cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c8cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c8cr_reg_type, 16, tf>;

    template<C8CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c8cr_reg_type, 17, 2, C8CR_SPOL_T, val>;

    template<C8CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c8cr_reg_type, 19, 5, C8CR_NBREQ_T, val>;

    template<C8CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c8cr_reg_type, 24, 5, C8CR_SYNC_ID_T, val>;

} // DMAMUX_C8CR
namespace DMAMUX_C9CR {

    enum class c9cr_reg_type {};

    template<C9CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c9cr_reg_type, 0, 7, C9CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c9cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c9cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c9cr_reg_type, 16, tf>;

    template<C9CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c9cr_reg_type, 17, 2, C9CR_SPOL_T, val>;

    template<C9CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c9cr_reg_type, 19, 5, C9CR_NBREQ_T, val>;

    template<C9CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c9cr_reg_type, 24, 5, C9CR_SYNC_ID_T, val>;

} // DMAMUX_C9CR
namespace DMAMUX_C10CR {

    enum class c10cr_reg_type {};

    template<C10CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c10cr_reg_type, 0, 7, C10CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c10cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c10cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c10cr_reg_type, 16, tf>;

    template<C10CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c10cr_reg_type, 17, 2, C10CR_SPOL_T, val>;

    template<C10CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c10cr_reg_type, 19, 5, C10CR_NBREQ_T, val>;

    template<C10CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c10cr_reg_type, 24, 5, C10CR_SYNC_ID_T, val>;

} // DMAMUX_C10CR
namespace DMAMUX_C11CR {

    enum class c11cr_reg_type {};

    template<C11CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c11cr_reg_type, 0, 7, C11CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c11cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c11cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c11cr_reg_type, 16, tf>;

    template<C11CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c11cr_reg_type, 17, 2, C11CR_SPOL_T, val>;

    template<C11CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c11cr_reg_type, 19, 5, C11CR_NBREQ_T, val>;

    template<C11CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c11cr_reg_type, 24, 5, C11CR_SYNC_ID_T, val>;

} // DMAMUX_C11CR
namespace DMAMUX_C12CR {

    enum class c12cr_reg_type {};

    template<C12CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c12cr_reg_type, 0, 7, C12CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c12cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c12cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c12cr_reg_type, 16, tf>;

    template<C12CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c12cr_reg_type, 17, 2, C12CR_SPOL_T, val>;

    template<C12CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c12cr_reg_type, 19, 5, C12CR_NBREQ_T, val>;

    template<C12CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c12cr_reg_type, 24, 5, C12CR_SYNC_ID_T, val>;

} // DMAMUX_C12CR
namespace DMAMUX_C13CR {

    enum class c13cr_reg_type {};

    template<C13CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c13cr_reg_type, 0, 7, C13CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c13cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c13cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c13cr_reg_type, 16, tf>;

    template<C13CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c13cr_reg_type, 17, 2, C13CR_SPOL_T, val>;

    template<C13CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c13cr_reg_type, 19, 5, C13CR_NBREQ_T, val>;

    template<C13CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c13cr_reg_type, 24, 5, C13CR_SYNC_ID_T, val>;

} // DMAMUX_C13CR
namespace DMAMUX_C14CR {

    enum class c14cr_reg_type {};

    template<C14CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c14cr_reg_type, 0, 7, C14CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c14cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c14cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c14cr_reg_type, 16, tf>;

    template<C14CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c14cr_reg_type, 17, 2, C14CR_SPOL_T, val>;

    template<C14CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c14cr_reg_type, 19, 5, C14CR_NBREQ_T, val>;

    template<C14CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c14cr_reg_type, 24, 5, C14CR_SYNC_ID_T, val>;

} // DMAMUX_C14CR
namespace DMAMUX_C15CR {

    enum class c15cr_reg_type {};

    template<C15CR_DMAREQ_ID_T val>
    using DMAREQ_ID = Register::Combo_Bitfield<c15cr_reg_type, 0, 7, C15CR_DMAREQ_ID_T, val>;

    template<bool tf>
    using SOIE = Register::Combo_Bit<c15cr_reg_type, 8, tf>;

    template<bool tf>
    using EGE = Register::Combo_Bit<c15cr_reg_type, 9, tf>;

    template<bool tf>
    using SE = Register::Combo_Bit<c15cr_reg_type, 16, tf>;

    template<C15CR_SPOL_T val>
    using SPOL = Register::Combo_Bitfield<c15cr_reg_type, 17, 2, C15CR_SPOL_T, val>;

    template<C15CR_NBREQ_T val>
    using NBREQ = Register::Combo_Bitfield<c15cr_reg_type, 19, 5, C15CR_NBREQ_T, val>;

    template<C15CR_SYNC_ID_T val>
    using SYNC_ID = Register::Combo_Bitfield<c15cr_reg_type, 24, 5, C15CR_SYNC_ID_T, val>;

} // DMAMUX_C15CR
namespace DMAMUX_CSR {

    enum class csr_reg_type {};

    template<CSR_SOF_T val>
    using SOF = Register::Combo_Bitfield<csr_reg_type, 0, 16, CSR_SOF_T, val>;

} // DMAMUX_CSR
namespace DMAMUX_CFR {

    enum class cfr_reg_type {};

    template<CFR_CSOF_T val>
    using CSOF = Register::Combo_Bitfield<cfr_reg_type, 0, 16, CFR_CSOF_T, val>;

} // DMAMUX_CFR
namespace DMAMUX_RG0CR {

    enum class rg0cr_reg_type {};

    template<RG0CR_SIG_ID_T val>
    using SIG_ID = Register::Combo_Bitfield<rg0cr_reg_type, 0, 5, RG0CR_SIG_ID_T, val>;

    template<bool tf>
    using OIE = Register::Combo_Bit<rg0cr_reg_type, 8, tf>;

    template<bool tf>
    using GE = Register::Combo_Bit<rg0cr_reg_type, 16, tf>;

    template<RG0CR_GPOL_T val>
    using GPOL = Register::Combo_Bitfield<rg0cr_reg_type, 17, 2, RG0CR_GPOL_T, val>;

    template<RG0CR_GNBREQ_T val>
    using GNBREQ = Register::Combo_Bitfield<rg0cr_reg_type, 19, 5, RG0CR_GNBREQ_T, val>;

} // DMAMUX_RG0CR
namespace DMAMUX_RG1CR {

    enum class rg1cr_reg_type {};

    template<RG1CR_SIG_ID_T val>
    using SIG_ID = Register::Combo_Bitfield<rg1cr_reg_type, 0, 5, RG1CR_SIG_ID_T, val>;

    template<bool tf>
    using OIE = Register::Combo_Bit<rg1cr_reg_type, 8, tf>;

    template<bool tf>
    using GE = Register::Combo_Bit<rg1cr_reg_type, 16, tf>;

    template<RG1CR_GPOL_T val>
    using GPOL = Register::Combo_Bitfield<rg1cr_reg_type, 17, 2, RG1CR_GPOL_T, val>;

    template<RG1CR_GNBREQ_T val>
    using GNBREQ = Register::Combo_Bitfield<rg1cr_reg_type, 19, 5, RG1CR_GNBREQ_T, val>;

} // DMAMUX_RG1CR
namespace DMAMUX_RG2CR {

    enum class rg2cr_reg_type {};

    template<RG2CR_SIG_ID_T val>
    using SIG_ID = Register::Combo_Bitfield<rg2cr_reg_type, 0, 5, RG2CR_SIG_ID_T, val>;

    template<bool tf>
    using OIE = Register::Combo_Bit<rg2cr_reg_type, 8, tf>;

    template<bool tf>
    using GE = Register::Combo_Bit<rg2cr_reg_type, 16, tf>;

    template<RG2CR_GPOL_T val>
    using GPOL = Register::Combo_Bitfield<rg2cr_reg_type, 17, 2, RG2CR_GPOL_T, val>;

    template<RG2CR_GNBREQ_T val>
    using GNBREQ = Register::Combo_Bitfield<rg2cr_reg_type, 19, 5, RG2CR_GNBREQ_T, val>;

} // DMAMUX_RG2CR
namespace DMAMUX_RG3CR {

    enum class rg3cr_reg_type {};

    template<RG3CR_SIG_ID_T val>
    using SIG_ID = Register::Combo_Bitfield<rg3cr_reg_type, 0, 5, RG3CR_SIG_ID_T, val>;

    template<bool tf>
    using OIE = Register::Combo_Bit<rg3cr_reg_type, 8, tf>;

    template<bool tf>
    using GE = Register::Combo_Bit<rg3cr_reg_type, 16, tf>;

    template<RG3CR_GPOL_T val>
    using GPOL = Register::Combo_Bitfield<rg3cr_reg_type, 17, 2, RG3CR_GPOL_T, val>;

    template<RG3CR_GNBREQ_T val>
    using GNBREQ = Register::Combo_Bitfield<rg3cr_reg_type, 19, 5, RG3CR_GNBREQ_T, val>;

} // DMAMUX_RG3CR
namespace DMAMUX_RGSR {

    enum class rgsr_reg_type {};

    template<RGSR_OF_T val>
    using OF = Register::Combo_Bitfield<rgsr_reg_type, 0, 4, RGSR_OF_T, val>;

} // DMAMUX_RGSR
namespace DMAMUX_RGCFR {

    enum class rgcfr_reg_type {};

    template<RGCFR_COF_T val>
    using COF = Register::Combo_Bitfield<rgcfr_reg_type, 0, 4, RGCFR_COF_T, val>;

} // DMAMUX_RGCFR
template<uint32_t BASE_ADDRESS>
class DMAMUX {
public:
    static const uint32_t C0CR_Offset = 0x0000;
    static const uint32_t C1CR_Offset = 0x0004;
    static const uint32_t C2CR_Offset = 0x0008;
    static const uint32_t C3CR_Offset = 0x000C;
    static const uint32_t C4CR_Offset = 0x0010;
    static const uint32_t C5CR_Offset = 0x0014;
    static const uint32_t C6CR_Offset = 0x0018;
    static const uint32_t C7CR_Offset = 0x001C;
    static const uint32_t C8CR_Offset = 0x0020;
    static const uint32_t C9CR_Offset = 0x0024;
    static const uint32_t C10CR_Offset = 0x0028;
    static const uint32_t C11CR_Offset = 0x002C;
    static const uint32_t C12CR_Offset = 0x0030;
    static const uint32_t C13CR_Offset = 0x0034;
    static const uint32_t C14CR_Offset = 0x0038;
    static const uint32_t C15CR_Offset = 0x003C;
    static const uint32_t CSR_Offset = 0x0080;
    static const uint32_t CFR_Offset = 0x0084;
    static const uint32_t RG0CR_Offset = 0x0100;
    static const uint32_t RG1CR_Offset = 0x0104;
    static const uint32_t RG2CR_Offset = 0x0108;
    static const uint32_t RG3CR_Offset = 0x010C;
    static const uint32_t RGSR_Offset = 0x0140;
    static const uint32_t RGCFR_Offset = 0x0144;

    DMAMUX() = default;
    DMAMUX( const DMAMUX& ) = delete;
    const DMAMUX& operator=( const DMAMUX& ) = delete;

    class C0CR_T : public Register::Register<DMAMUX_C0CR::c0cr_reg_type, BASE_ADDRESS + C0CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C0CR_Offset, 0, 7, C0CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C0CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C0CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C0CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C0CR_Offset, 17, 2, C0CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C0CR_Offset, 19, 5, C0CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C0CR_Offset, 24, 5, C0CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C1CR_T : public Register::Register<DMAMUX_C1CR::c1cr_reg_type, BASE_ADDRESS + C1CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C1CR_Offset, 0, 7, C1CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C1CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C1CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C1CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C1CR_Offset, 17, 2, C1CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C1CR_Offset, 19, 5, C1CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C1CR_Offset, 24, 5, C1CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C2CR_T : public Register::Register<DMAMUX_C2CR::c2cr_reg_type, BASE_ADDRESS + C2CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C2CR_Offset, 0, 7, C2CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C2CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C2CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C2CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C2CR_Offset, 17, 2, C2CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C2CR_Offset, 19, 5, C2CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C2CR_Offset, 24, 5, C2CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C3CR_T : public Register::Register<DMAMUX_C3CR::c3cr_reg_type, BASE_ADDRESS + C3CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C3CR_Offset, 0, 7, C3CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C3CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C3CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C3CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C3CR_Offset, 17, 2, C3CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C3CR_Offset, 19, 5, C3CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C3CR_Offset, 24, 5, C3CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C4CR_T : public Register::Register<DMAMUX_C4CR::c4cr_reg_type, BASE_ADDRESS + C4CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C4CR_Offset, 0, 7, C4CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C4CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C4CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C4CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C4CR_Offset, 17, 2, C4CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C4CR_Offset, 19, 5, C4CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C4CR_Offset, 24, 5, C4CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C5CR_T : public Register::Register<DMAMUX_C5CR::c5cr_reg_type, BASE_ADDRESS + C5CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C5CR_Offset, 0, 7, C5CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C5CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C5CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C5CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C5CR_Offset, 17, 2, C5CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C5CR_Offset, 19, 5, C5CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C5CR_Offset, 24, 5, C5CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C6CR_T : public Register::Register<DMAMUX_C6CR::c6cr_reg_type, BASE_ADDRESS + C6CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C6CR_Offset, 0, 7, C6CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C6CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C6CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C6CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C6CR_Offset, 17, 2, C6CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C6CR_Offset, 19, 5, C6CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C6CR_Offset, 24, 5, C6CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C7CR_T : public Register::Register<DMAMUX_C7CR::c7cr_reg_type, BASE_ADDRESS + C7CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C7CR_Offset, 0, 7, C7CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C7CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C7CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C7CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C7CR_Offset, 17, 2, C7CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C7CR_Offset, 19, 5, C7CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C7CR_Offset, 24, 5, C7CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C8CR_T : public Register::Register<DMAMUX_C8CR::c8cr_reg_type, BASE_ADDRESS + C8CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C8CR_Offset, 0, 7, C8CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C8CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C8CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C8CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C8CR_Offset, 17, 2, C8CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C8CR_Offset, 19, 5, C8CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C8CR_Offset, 24, 5, C8CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C9CR_T : public Register::Register<DMAMUX_C9CR::c9cr_reg_type, BASE_ADDRESS + C9CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C9CR_Offset, 0, 7, C9CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C9CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C9CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C9CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C9CR_Offset, 17, 2, C9CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C9CR_Offset, 19, 5, C9CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C9CR_Offset, 24, 5, C9CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C10CR_T : public Register::Register<DMAMUX_C10CR::c10cr_reg_type, BASE_ADDRESS + C10CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C10CR_Offset, 0, 7, C10CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C10CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C10CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C10CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C10CR_Offset, 17, 2, C10CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C10CR_Offset, 19, 5, C10CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C10CR_Offset, 24, 5, C10CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C11CR_T : public Register::Register<DMAMUX_C11CR::c11cr_reg_type, BASE_ADDRESS + C11CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C11CR_Offset, 0, 7, C11CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C11CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C11CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C11CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C11CR_Offset, 17, 2, C11CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C11CR_Offset, 19, 5, C11CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C11CR_Offset, 24, 5, C11CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C12CR_T : public Register::Register<DMAMUX_C12CR::c12cr_reg_type, BASE_ADDRESS + C12CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C12CR_Offset, 0, 7, C12CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C12CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C12CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C12CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C12CR_Offset, 17, 2, C12CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C12CR_Offset, 19, 5, C12CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C12CR_Offset, 24, 5, C12CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C13CR_T : public Register::Register<DMAMUX_C13CR::c13cr_reg_type, BASE_ADDRESS + C13CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C13CR_Offset, 0, 7, C13CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C13CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C13CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C13CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C13CR_Offset, 17, 2, C13CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C13CR_Offset, 19, 5, C13CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C13CR_Offset, 24, 5, C13CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C14CR_T : public Register::Register<DMAMUX_C14CR::c14cr_reg_type, BASE_ADDRESS + C14CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C14CR_Offset, 0, 7, C14CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C14CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C14CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C14CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C14CR_Offset, 17, 2, C14CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C14CR_Offset, 19, 5, C14CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C14CR_Offset, 24, 5, C14CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class C15CR_T : public Register::Register<DMAMUX_C15CR::c15cr_reg_type, BASE_ADDRESS + C15CR_Offset> {
    // DMAMux - DMA request line multiplexer channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + C15CR_Offset, 0, 7, C15CR_DMAREQ_ID_T> DMAREQ_ID; /* Input DMA request line selected */
        Register::Bit<BASE_ADDRESS + C15CR_Offset, 8> SOIE; /* Interrupt enable at synchronization event overrun */
        Register::Bit<BASE_ADDRESS + C15CR_Offset, 9> EGE; /* Event generation enable/disable */
        Register::Bit<BASE_ADDRESS + C15CR_Offset, 16> SE; /* Synchronous operating mode enable/disable */
        Register::Bitfield<BASE_ADDRESS + C15CR_Offset, 17, 2, C15CR_SPOL_T> SPOL; /* Synchronization event type selector Defines the synchronization event on the selected synchronization input: */
        Register::Bitfield<BASE_ADDRESS + C15CR_Offset, 19, 5, C15CR_NBREQ_T> NBREQ; /* Number of DMA requests to forward Defines the number of DMA requests forwarded before output event is generated. In synchronous mode, it also defines the number of DMA requests to forward after a synchronization event, then stop forwarding. The actual number of DMA requests forwarded is NBREQ+1. Note: This field can only be written when both SE and EGE bits are reset. */
        Register::Bitfield<BASE_ADDRESS + C15CR_Offset, 24, 5, C15CR_SYNC_ID_T> SYNC_ID; /* Synchronization input selected */
    };

    class CSR_T : public Register::Register<DMAMUX_CSR::csr_reg_type, BASE_ADDRESS + CSR_Offset> {
    // DMAMUX request line multiplexer interrupt channel status register
    public:
        Register::Bitfield<BASE_ADDRESS + CSR_Offset, 0, 16, CSR_SOF_T> SOF; /* Synchronization overrun event flag */
    };

    class CFR_T : public Register::Register<DMAMUX_CFR::cfr_reg_type, BASE_ADDRESS + CFR_Offset> {
    // DMAMUX request line multiplexer interrupt clear flag register
    public:
        Register::Bitfield<BASE_ADDRESS + CFR_Offset, 0, 16, CFR_CSOF_T> CSOF; /* Clear synchronization overrun event flag */
    };

    class RG0CR_T : public Register::Register<DMAMUX_RG0CR::rg0cr_reg_type, BASE_ADDRESS + RG0CR_Offset> {
    // DMAMux - DMA request generator channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + RG0CR_Offset, 0, 5, RG0CR_SIG_ID_T> SIG_ID; /* DMA request trigger input selected */
        Register::Bit<BASE_ADDRESS + RG0CR_Offset, 8> OIE; /* Interrupt enable at trigger event overrun */
        Register::Bit<BASE_ADDRESS + RG0CR_Offset, 16> GE; /* DMA request generator channel enable/disable */
        Register::Bitfield<BASE_ADDRESS + RG0CR_Offset, 17, 2, RG0CR_GPOL_T> GPOL; /* DMA request generator trigger event type selection Defines the trigger event on the selected DMA request trigger input */
        Register::Bitfield<BASE_ADDRESS + RG0CR_Offset, 19, 5, RG0CR_GNBREQ_T> GNBREQ; /* Number of DMA requests to generate Defines the number of DMA requests generated after a trigger event, then stop generating. The actual number of generated DMA requests is GNBREQ+1. Note: This field can only be written when GE bit is reset. */
    };

    class RG1CR_T : public Register::Register<DMAMUX_RG1CR::rg1cr_reg_type, BASE_ADDRESS + RG1CR_Offset> {
    // DMAMux - DMA request generator channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + RG1CR_Offset, 0, 5, RG1CR_SIG_ID_T> SIG_ID; /* DMA request trigger input selected */
        Register::Bit<BASE_ADDRESS + RG1CR_Offset, 8> OIE; /* Interrupt enable at trigger event overrun */
        Register::Bit<BASE_ADDRESS + RG1CR_Offset, 16> GE; /* DMA request generator channel enable/disable */
        Register::Bitfield<BASE_ADDRESS + RG1CR_Offset, 17, 2, RG1CR_GPOL_T> GPOL; /* DMA request generator trigger event type selection Defines the trigger event on the selected DMA request trigger input */
        Register::Bitfield<BASE_ADDRESS + RG1CR_Offset, 19, 5, RG1CR_GNBREQ_T> GNBREQ; /* Number of DMA requests to generate Defines the number of DMA requests generated after a trigger event, then stop generating. The actual number of generated DMA requests is GNBREQ+1. Note: This field can only be written when GE bit is reset. */
    };

    class RG2CR_T : public Register::Register<DMAMUX_RG2CR::rg2cr_reg_type, BASE_ADDRESS + RG2CR_Offset> {
    // DMAMux - DMA request generator channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + RG2CR_Offset, 0, 5, RG2CR_SIG_ID_T> SIG_ID; /* DMA request trigger input selected */
        Register::Bit<BASE_ADDRESS + RG2CR_Offset, 8> OIE; /* Interrupt enable at trigger event overrun */
        Register::Bit<BASE_ADDRESS + RG2CR_Offset, 16> GE; /* DMA request generator channel enable/disable */
        Register::Bitfield<BASE_ADDRESS + RG2CR_Offset, 17, 2, RG2CR_GPOL_T> GPOL; /* DMA request generator trigger event type selection Defines the trigger event on the selected DMA request trigger input */
        Register::Bitfield<BASE_ADDRESS + RG2CR_Offset, 19, 5, RG2CR_GNBREQ_T> GNBREQ; /* Number of DMA requests to generate Defines the number of DMA requests generated after a trigger event, then stop generating. The actual number of generated DMA requests is GNBREQ+1. Note: This field can only be written when GE bit is reset. */
    };

    class RG3CR_T : public Register::Register<DMAMUX_RG3CR::rg3cr_reg_type, BASE_ADDRESS + RG3CR_Offset> {
    // DMAMux - DMA request generator channel x control register
    public:
        Register::Bitfield<BASE_ADDRESS + RG3CR_Offset, 0, 5, RG3CR_SIG_ID_T> SIG_ID; /* DMA request trigger input selected */
        Register::Bit<BASE_ADDRESS + RG3CR_Offset, 8> OIE; /* Interrupt enable at trigger event overrun */
        Register::Bit<BASE_ADDRESS + RG3CR_Offset, 16> GE; /* DMA request generator channel enable/disable */
        Register::Bitfield<BASE_ADDRESS + RG3CR_Offset, 17, 2, RG3CR_GPOL_T> GPOL; /* DMA request generator trigger event type selection Defines the trigger event on the selected DMA request trigger input */
        Register::Bitfield<BASE_ADDRESS + RG3CR_Offset, 19, 5, RG3CR_GNBREQ_T> GNBREQ; /* Number of DMA requests to generate Defines the number of DMA requests generated after a trigger event, then stop generating. The actual number of generated DMA requests is GNBREQ+1. Note: This field can only be written when GE bit is reset. */
    };

    class RGSR_T : public Register::Register<DMAMUX_RGSR::rgsr_reg_type, BASE_ADDRESS + RGSR_Offset> {
    // DMAMux - DMA request generator status register
    public:
        Register::Bitfield<BASE_ADDRESS + RGSR_Offset, 0, 4, RGSR_OF_T> OF; /* Trigger event overrun flag The flag is set when a trigger event occurs on DMA request generator channel x, while the DMA request generator counter value is lower than GNBREQ. The flag is cleared by writing 1 to the corresponding COFx bit in DMAMUX_RGCFR register. */
    };

    class RGCFR_T : public Register::Register<DMAMUX_RGCFR::rgcfr_reg_type, BASE_ADDRESS + RGCFR_Offset> {
    // DMAMux - DMA request generator clear flag register
    public:
        Register::Bitfield<BASE_ADDRESS + RGCFR_Offset, 0, 4, RGCFR_COF_T> COF; /* Clear trigger event overrun flag Upon setting, this bit clears the corresponding overrun flag OFx in the DMAMUX_RGCSR register. */
    };

    C0CR_T C0CR;
    C1CR_T C1CR;
    C2CR_T C2CR;
    C3CR_T C3CR;
    C4CR_T C4CR;
    C5CR_T C5CR;
    C6CR_T C6CR;
    C7CR_T C7CR;
    C8CR_T C8CR;
    C9CR_T C9CR;
    C10CR_T C10CR;
    C11CR_T C11CR;
    C12CR_T C12CR;
    C13CR_T C13CR;
    C14CR_T C14CR;
    C15CR_T C15CR;
    CSR_T CSR;
    CFR_T CFR;
    RG0CR_T RG0CR;
    RG1CR_T RG1CR;
    RG2CR_T RG2CR;
    RG3CR_T RG3CR;
    RGSR_T RGSR;
    RGCFR_T RGCFR;
};

} // namespace STM32LIB

#endif // STM32G473XX_DMAMUX_HPP_

