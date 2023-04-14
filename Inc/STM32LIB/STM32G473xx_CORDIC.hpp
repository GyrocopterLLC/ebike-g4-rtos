#ifndef STM32G473XX_CORDIC_HPP_
#define STM32G473XX_CORDIC_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"
#include "CORDIC_Types.hpp"

/* CORDIC Co-processor */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using CSR_FUNC_T = Cordic_Function;
using CSR_PRECISION_T = uint32_t;
using CSR_SCALE_T = uint32_t;
using WDATA_ARG_T = uint32_t;
using RDATA_RES_T = uint32_t;

namespace CORDIC_CSR {

    enum class csr_reg_type {};

    template<CSR_FUNC_T val>
    using FUNC = Register::Combo_Bitfield<csr_reg_type, 0, 4, CSR_FUNC_T, val>;

    template<CSR_PRECISION_T val>
    using PRECISION = Register::Combo_Bitfield<csr_reg_type, 4, 4, CSR_PRECISION_T, val>;

    template<CSR_SCALE_T val>
    using SCALE = Register::Combo_Bitfield<csr_reg_type, 8, 3, CSR_SCALE_T, val>;

    template<bool tf>
    using IEN = Register::Combo_Bit<csr_reg_type, 16, tf>;

    template<bool tf>
    using DMAREN = Register::Combo_Bit<csr_reg_type, 17, tf>;

    template<bool tf>
    using DMAWEN = Register::Combo_Bit<csr_reg_type, 18, tf>;

    template<bool tf>
    using NRES = Register::Combo_Bit<csr_reg_type, 19, tf>;

    template<bool tf>
    using NARGS = Register::Combo_Bit<csr_reg_type, 20, tf>;

    template<bool tf>
    using RESSIZE = Register::Combo_Bit<csr_reg_type, 21, tf>;

    template<bool tf>
    using ARGSIZE = Register::Combo_Bit<csr_reg_type, 22, tf>;

    template<bool tf>
    using RRDY = Register::Combo_Bit<csr_reg_type, 31, tf>;

} // CORDIC_CSR
namespace CORDIC_WDATA {

    enum class wdata_reg_type {};

    template<WDATA_ARG_T val>
    using ARG = Register::Combo_Bitfield<wdata_reg_type, 0, 32, WDATA_ARG_T, val>;

} // CORDIC_WDATA
namespace CORDIC_RDATA {

    enum class rdata_reg_type {};

    template<RDATA_RES_T val>
    using RES = Register::Combo_Bitfield<rdata_reg_type, 0, 32, RDATA_RES_T, val>;

} // CORDIC_RDATA
template<uint32_t BASE_ADDRESS>
class CORDIC {
public:
    static const uint32_t CSR_Offset = 0x0000;
    static const uint32_t WDATA_Offset = 0x0004;
    static const uint32_t RDATA_Offset = 0x0008;

    CORDIC() = default;
    CORDIC( const CORDIC& ) = delete;
    const CORDIC& operator=( const CORDIC& ) = delete;

    class CSR_T : public Register::Register<CORDIC_CSR::csr_reg_type, BASE_ADDRESS + CSR_Offset> {
    // CORDIC Control Status register
    public:
        Register::Bitfield<BASE_ADDRESS + CSR_Offset, 0, 4, CSR_FUNC_T> FUNC; /* FUNC */
        Register::Bitfield<BASE_ADDRESS + CSR_Offset, 4, 4, CSR_PRECISION_T> PRECISION; /* PRECISION */
        Register::Bitfield<BASE_ADDRESS + CSR_Offset, 8, 3, CSR_SCALE_T> SCALE; /* SCALE */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 16> IEN; /* IEN */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 17> DMAREN; /* DMAREN */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 18> DMAWEN; /* DMAWEN */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 19> NRES; /* NRES */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 20> NARGS; /* NARGS */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 21> RESSIZE; /* RESSIZE */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 22> ARGSIZE; /* ARGSIZE */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 31> RRDY; /* RRDY */
    };

    class WDATA_T : public Register::Register<CORDIC_WDATA::wdata_reg_type, BASE_ADDRESS + WDATA_Offset> {
    // FMAC Write Data register
    public:
        Register::Bitfield<BASE_ADDRESS + WDATA_Offset, 0, 32, WDATA_ARG_T> ARG; /* ARG */
    };

    class RDATA_T : public Register::Register<CORDIC_RDATA::rdata_reg_type, BASE_ADDRESS + RDATA_Offset> {
    // FMAC Read Data register
    public:
        Register::Bitfield<BASE_ADDRESS + RDATA_Offset, 0, 32, RDATA_RES_T> RES; /* RES */
    };

    CSR_T CSR;
    WDATA_T WDATA;
    RDATA_T RDATA;
};

} // namespace STM32LIB

#endif // STM32G473XX_CORDIC_HPP_

