#ifndef STM32G473XX_ADC_Common_HPP_
#define STM32G473XX_ADC_Common_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"

/* Analog-to-Digital Converter */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using CCR_DUAL_T = uint32_t;
using CCR_DELAY_T = uint32_t;
using CCR_MDMA_T = uint32_t;
using CCR_CKMODE_T = uint32_t;
using CCR_PRESC_T = uint32_t;
using CDR_RDATA_SLV_T = uint32_t;
using CDR_RDATA_MST_T = uint32_t;

namespace ADC_Common_CSR {

    enum class csr_reg_type {};

    template<bool tf>
    using ADDRDY_MST = Register::Combo_Bit<csr_reg_type, 0, tf>;

    template<bool tf>
    using EOSMP_MST = Register::Combo_Bit<csr_reg_type, 1, tf>;

    template<bool tf>
    using EOC_MST = Register::Combo_Bit<csr_reg_type, 2, tf>;

    template<bool tf>
    using EOS_MST = Register::Combo_Bit<csr_reg_type, 3, tf>;

    template<bool tf>
    using OVR_MST = Register::Combo_Bit<csr_reg_type, 4, tf>;

    template<bool tf>
    using JEOC_MST = Register::Combo_Bit<csr_reg_type, 5, tf>;

    template<bool tf>
    using JEOS_MST = Register::Combo_Bit<csr_reg_type, 6, tf>;

    template<bool tf>
    using AWD1_MST = Register::Combo_Bit<csr_reg_type, 7, tf>;

    template<bool tf>
    using AWD2_MST = Register::Combo_Bit<csr_reg_type, 8, tf>;

    template<bool tf>
    using AWD3_MST = Register::Combo_Bit<csr_reg_type, 9, tf>;

    template<bool tf>
    using JQOVF_MST = Register::Combo_Bit<csr_reg_type, 10, tf>;

    template<bool tf>
    using ADRDY_SLV = Register::Combo_Bit<csr_reg_type, 16, tf>;

    template<bool tf>
    using EOSMP_SLV = Register::Combo_Bit<csr_reg_type, 17, tf>;

    template<bool tf>
    using EOC_SLV = Register::Combo_Bit<csr_reg_type, 18, tf>;

    template<bool tf>
    using EOS_SLV = Register::Combo_Bit<csr_reg_type, 19, tf>;

    template<bool tf>
    using OVR_SLV = Register::Combo_Bit<csr_reg_type, 20, tf>;

    template<bool tf>
    using JEOC_SLV = Register::Combo_Bit<csr_reg_type, 21, tf>;

    template<bool tf>
    using JEOS_SLV = Register::Combo_Bit<csr_reg_type, 22, tf>;

    template<bool tf>
    using AWD1_SLV = Register::Combo_Bit<csr_reg_type, 23, tf>;

    template<bool tf>
    using AWD2_SLV = Register::Combo_Bit<csr_reg_type, 24, tf>;

    template<bool tf>
    using AWD3_SLV = Register::Combo_Bit<csr_reg_type, 25, tf>;

    template<bool tf>
    using JQOVF_SLV = Register::Combo_Bit<csr_reg_type, 26, tf>;

} // ADC_Common_CSR
namespace ADC_Common_CCR {

    enum class ccr_reg_type {};

    template<CCR_DUAL_T val>
    using DUAL = Register::Combo_Bitfield<ccr_reg_type, 0, 5, CCR_DUAL_T, val>;

    template<CCR_DELAY_T val>
    using DELAY = Register::Combo_Bitfield<ccr_reg_type, 8, 4, CCR_DELAY_T, val>;

    template<bool tf>
    using DMACFG = Register::Combo_Bit<ccr_reg_type, 13, tf>;

    template<CCR_MDMA_T val>
    using MDMA = Register::Combo_Bitfield<ccr_reg_type, 14, 2, CCR_MDMA_T, val>;

    template<CCR_CKMODE_T val>
    using CKMODE = Register::Combo_Bitfield<ccr_reg_type, 16, 2, CCR_CKMODE_T, val>;

    template<bool tf>
    using VREFEN = Register::Combo_Bit<ccr_reg_type, 22, tf>;

    template<bool tf>
    using VSENSESEL = Register::Combo_Bit<ccr_reg_type, 23, tf>;

    template<bool tf>
    using VBATSEL = Register::Combo_Bit<ccr_reg_type, 24, tf>;

    template<CCR_PRESC_T val>
    using PRESC = Register::Combo_Bitfield<ccr_reg_type, 18, 4, CCR_PRESC_T, val>;

} // ADC_Common_CCR
namespace ADC_Common_CDR {

    enum class cdr_reg_type {};

    template<CDR_RDATA_SLV_T val>
    using RDATA_SLV = Register::Combo_Bitfield<cdr_reg_type, 16, 16, CDR_RDATA_SLV_T, val>;

    template<CDR_RDATA_MST_T val>
    using RDATA_MST = Register::Combo_Bitfield<cdr_reg_type, 0, 16, CDR_RDATA_MST_T, val>;

} // ADC_Common_CDR
template<uint32_t BASE_ADDRESS>
class ADC_Common {
public:
    static const uint32_t CSR_Offset = 0x0000;
    static const uint32_t CCR_Offset = 0x0008;
    static const uint32_t CDR_Offset = 0x000C;

    ADC_Common() = default;
    ADC_Common( const ADC_Common& ) = delete;
    const ADC_Common& operator=( const ADC_Common& ) = delete;

    class CSR_T : public Register::Register<ADC_Common_CSR::csr_reg_type, BASE_ADDRESS + CSR_Offset> {
    // ADC Common status register
    public:
        Register::Bit<BASE_ADDRESS + CSR_Offset, 0> ADDRDY_MST; /* ADDRDY_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 1> EOSMP_MST; /* EOSMP_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 2> EOC_MST; /* EOC_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 3> EOS_MST; /* EOS_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 4> OVR_MST; /* OVR_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 5> JEOC_MST; /* JEOC_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 6> JEOS_MST; /* JEOS_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 7> AWD1_MST; /* AWD1_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 8> AWD2_MST; /* AWD2_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 9> AWD3_MST; /* AWD3_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 10> JQOVF_MST; /* JQOVF_MST */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 16> ADRDY_SLV; /* ADRDY_SLV */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 17> EOSMP_SLV; /* EOSMP_SLV */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 18> EOC_SLV; /* End of regular conversion of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 19> EOS_SLV; /* End of regular sequence flag of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 20> OVR_SLV; /* Overrun flag of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 21> JEOC_SLV; /* End of injected conversion flag of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 22> JEOS_SLV; /* End of injected sequence flag of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 23> AWD1_SLV; /* Analog watchdog 1 flag of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 24> AWD2_SLV; /* Analog watchdog 2 flag of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 25> AWD3_SLV; /* Analog watchdog 3 flag of the slave ADC */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 26> JQOVF_SLV; /* Injected Context Queue Overflow flag of the slave ADC */
    };

    class CCR_T : public Register::Register<ADC_Common_CCR::ccr_reg_type, BASE_ADDRESS + CCR_Offset> {
    // ADC common control register
    public:
        Register::Bitfield<BASE_ADDRESS + CCR_Offset, 0, 5, CCR_DUAL_T> DUAL; /* Dual ADC mode selection */
        Register::Bitfield<BASE_ADDRESS + CCR_Offset, 8, 4, CCR_DELAY_T> DELAY; /* Delay between 2 sampling phases */
        Register::Bit<BASE_ADDRESS + CCR_Offset, 13> DMACFG; /* DMA configuration (for multi-ADC mode) */
        Register::Bitfield<BASE_ADDRESS + CCR_Offset, 14, 2, CCR_MDMA_T> MDMA; /* Direct memory access mode for multi ADC mode */
        Register::Bitfield<BASE_ADDRESS + CCR_Offset, 16, 2, CCR_CKMODE_T> CKMODE; /* ADC clock mode */
        Register::Bit<BASE_ADDRESS + CCR_Offset, 22> VREFEN; /* VREFINT enable */
        Register::Bit<BASE_ADDRESS + CCR_Offset, 23> VSENSESEL; /* VTS selection */
        Register::Bit<BASE_ADDRESS + CCR_Offset, 24> VBATSEL; /* VBAT selection */
        Register::Bitfield<BASE_ADDRESS + CCR_Offset, 18, 4, CCR_PRESC_T> PRESC; /* ADC prescaler */
    };

    class CDR_T : public Register::Register<ADC_Common_CDR::cdr_reg_type, BASE_ADDRESS + CDR_Offset> {
    // ADC common regular data register for dual and triple modes
    public:
        Register::Bitfield<BASE_ADDRESS + CDR_Offset, 16, 16, CDR_RDATA_SLV_T> RDATA_SLV; /* Regular data of the slave ADC */
        Register::Bitfield<BASE_ADDRESS + CDR_Offset, 0, 16, CDR_RDATA_MST_T> RDATA_MST; /* Regular data of the master ADC */
    };

    CSR_T CSR;
    CCR_T CCR;
    CDR_T CDR;
};

} // namespace STM32LIB

#endif // STM32G473XX_ADC_Common_HPP_

