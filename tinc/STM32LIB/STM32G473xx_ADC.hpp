#ifndef STM32G473XX_ADC_HPP_
#define STM32G473XX_ADC_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"

/* Analog-to-Digital Converter */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using CFGR_AWD1CH_T = uint32_t;
using CFGR_DISCNUM_T = uint32_t;
using CFGR_EXTEN_T = uint32_t;
using CFGR_EXTSEL_T = uint32_t;
using CFGR_RES_T = uint32_t;
using CFGR2_OVSS_T = uint32_t;
using CFGR2_OVSR_T = uint32_t;
using SMPR1_SMP9_T = uint32_t;
using SMPR1_SMP8_T = uint32_t;
using SMPR1_SMP7_T = uint32_t;
using SMPR1_SMP6_T = uint32_t;
using SMPR1_SMP5_T = uint32_t;
using SMPR1_SMP4_T = uint32_t;
using SMPR1_SMP3_T = uint32_t;
using SMPR1_SMP2_T = uint32_t;
using SMPR1_SMP1_T = uint32_t;
using SMPR1_SMP0_T = uint32_t;
using SMPR2_SMP18_T = uint32_t;
using SMPR2_SMP17_T = uint32_t;
using SMPR2_SMP16_T = uint32_t;
using SMPR2_SMP15_T = uint32_t;
using SMPR2_SMP14_T = uint32_t;
using SMPR2_SMP13_T = uint32_t;
using SMPR2_SMP12_T = uint32_t;
using SMPR2_SMP11_T = uint32_t;
using SMPR2_SMP10_T = uint32_t;
using TR1_HT1_T = uint32_t;
using TR1_AWDFILT_T = uint32_t;
using TR1_LT1_T = uint32_t;
using TR2_HT2_T = uint32_t;
using TR2_LT2_T = uint32_t;
using TR3_HT3_T = uint32_t;
using TR3_LT3_T = uint32_t;
using SQR1_SQ4_T = uint32_t;
using SQR1_SQ3_T = uint32_t;
using SQR1_SQ2_T = uint32_t;
using SQR1_SQ1_T = uint32_t;
using SQR1_L_T = uint32_t;
using SQR2_SQ9_T = uint32_t;
using SQR2_SQ8_T = uint32_t;
using SQR2_SQ7_T = uint32_t;
using SQR2_SQ6_T = uint32_t;
using SQR2_SQ5_T = uint32_t;
using SQR3_SQ14_T = uint32_t;
using SQR3_SQ13_T = uint32_t;
using SQR3_SQ12_T = uint32_t;
using SQR3_SQ11_T = uint32_t;
using SQR3_SQ10_T = uint32_t;
using SQR4_SQ16_T = uint32_t;
using SQR4_SQ15_T = uint32_t;
using DR_RDATA_T = uint32_t;
using JSQR_JSQ4_T = uint32_t;
using JSQR_JSQ3_T = uint32_t;
using JSQR_JSQ2_T = uint32_t;
using JSQR_JSQ1_T = uint32_t;
using JSQR_JEXTEN_T = uint32_t;
using JSQR_JEXTSEL_T = uint32_t;
using JSQR_JL_T = uint32_t;
using OFR1_OFFSET1_CH_T = uint32_t;
using OFR1_OFFSET1_T = uint32_t;
using OFR2_OFFSET1_CH_T = uint32_t;
using OFR2_OFFSET1_T = uint32_t;
using OFR3_OFFSET1_CH_T = uint32_t;
using OFR3_OFFSET1_T = uint32_t;
using OFR4_OFFSET1_CH_T = uint32_t;
using OFR4_OFFSET1_T = uint32_t;
using JDR1_JDATA1_T = uint32_t;
using JDR2_JDATA2_T = uint32_t;
using JDR3_JDATA3_T = uint32_t;
using JDR4_JDATA4_T = uint32_t;
using AWD2CR_AWD2CH_T = uint32_t;
using AWD3CR_AWD3CH_T = uint32_t;
using DIFSEL_DIFSEL_1_18_T = uint32_t;
using CALFACT_CALFACT_D_T = uint32_t;
using CALFACT_CALFACT_S_T = uint32_t;
using GCOMP_GCOMPCOEFF_T = uint32_t;

namespace ADC_ISR {

    enum class isr_reg_type {};

    template<bool tf>
    using JQOVF = Register::Combo_Bit<isr_reg_type, 10, tf>;

    template<bool tf>
    using AWD3 = Register::Combo_Bit<isr_reg_type, 9, tf>;

    template<bool tf>
    using AWD2 = Register::Combo_Bit<isr_reg_type, 8, tf>;

    template<bool tf>
    using AWD1 = Register::Combo_Bit<isr_reg_type, 7, tf>;

    template<bool tf>
    using JEOS = Register::Combo_Bit<isr_reg_type, 6, tf>;

    template<bool tf>
    using JEOC = Register::Combo_Bit<isr_reg_type, 5, tf>;

    template<bool tf>
    using OVR = Register::Combo_Bit<isr_reg_type, 4, tf>;

    template<bool tf>
    using EOS = Register::Combo_Bit<isr_reg_type, 3, tf>;

    template<bool tf>
    using EOC = Register::Combo_Bit<isr_reg_type, 2, tf>;

    template<bool tf>
    using EOSMP = Register::Combo_Bit<isr_reg_type, 1, tf>;

    template<bool tf>
    using ADRDY = Register::Combo_Bit<isr_reg_type, 0, tf>;

} // ADC_ISR
namespace ADC_IER {

    enum class ier_reg_type {};

    template<bool tf>
    using JQOVFIE = Register::Combo_Bit<ier_reg_type, 10, tf>;

    template<bool tf>
    using AWD3IE = Register::Combo_Bit<ier_reg_type, 9, tf>;

    template<bool tf>
    using AWD2IE = Register::Combo_Bit<ier_reg_type, 8, tf>;

    template<bool tf>
    using AWD1IE = Register::Combo_Bit<ier_reg_type, 7, tf>;

    template<bool tf>
    using JEOSIE = Register::Combo_Bit<ier_reg_type, 6, tf>;

    template<bool tf>
    using JEOCIE = Register::Combo_Bit<ier_reg_type, 5, tf>;

    template<bool tf>
    using OVRIE = Register::Combo_Bit<ier_reg_type, 4, tf>;

    template<bool tf>
    using EOSIE = Register::Combo_Bit<ier_reg_type, 3, tf>;

    template<bool tf>
    using EOCIE = Register::Combo_Bit<ier_reg_type, 2, tf>;

    template<bool tf>
    using EOSMPIE = Register::Combo_Bit<ier_reg_type, 1, tf>;

    template<bool tf>
    using ADRDYIE = Register::Combo_Bit<ier_reg_type, 0, tf>;

} // ADC_IER
namespace ADC_CR {

    enum class cr_reg_type {};

    template<bool tf>
    using ADCAL = Register::Combo_Bit<cr_reg_type, 31, tf>;

    template<bool tf>
    using ADCALDIF = Register::Combo_Bit<cr_reg_type, 30, tf>;

    template<bool tf>
    using DEEPPWD = Register::Combo_Bit<cr_reg_type, 29, tf>;

    template<bool tf>
    using ADVREGEN = Register::Combo_Bit<cr_reg_type, 28, tf>;

    template<bool tf>
    using JADSTP = Register::Combo_Bit<cr_reg_type, 5, tf>;

    template<bool tf>
    using ADSTP = Register::Combo_Bit<cr_reg_type, 4, tf>;

    template<bool tf>
    using JADSTART = Register::Combo_Bit<cr_reg_type, 3, tf>;

    template<bool tf>
    using ADSTART = Register::Combo_Bit<cr_reg_type, 2, tf>;

    template<bool tf>
    using ADDIS = Register::Combo_Bit<cr_reg_type, 1, tf>;

    template<bool tf>
    using ADEN = Register::Combo_Bit<cr_reg_type, 0, tf>;

} // ADC_CR
namespace ADC_CFGR {

    enum class cfgr_reg_type {};

    template<bool tf>
    using JQDIS = Register::Combo_Bit<cfgr_reg_type, 31, tf>;

    template<CFGR_AWD1CH_T val>
    using AWD1CH = Register::Combo_Bitfield<cfgr_reg_type, 26, 5, CFGR_AWD1CH_T, val>;

    template<bool tf>
    using JAUTO = Register::Combo_Bit<cfgr_reg_type, 25, tf>;

    template<bool tf>
    using JAWD1EN = Register::Combo_Bit<cfgr_reg_type, 24, tf>;

    template<bool tf>
    using AWD1EN = Register::Combo_Bit<cfgr_reg_type, 23, tf>;

    template<bool tf>
    using AWD1SGL = Register::Combo_Bit<cfgr_reg_type, 22, tf>;

    template<bool tf>
    using JQM = Register::Combo_Bit<cfgr_reg_type, 21, tf>;

    template<bool tf>
    using JDISCEN = Register::Combo_Bit<cfgr_reg_type, 20, tf>;

    template<CFGR_DISCNUM_T val>
    using DISCNUM = Register::Combo_Bitfield<cfgr_reg_type, 17, 3, CFGR_DISCNUM_T, val>;

    template<bool tf>
    using DISCEN = Register::Combo_Bit<cfgr_reg_type, 16, tf>;

    template<bool tf>
    using ALIGN = Register::Combo_Bit<cfgr_reg_type, 15, tf>;

    template<bool tf>
    using AUTDLY = Register::Combo_Bit<cfgr_reg_type, 14, tf>;

    template<bool tf>
    using CONT = Register::Combo_Bit<cfgr_reg_type, 13, tf>;

    template<bool tf>
    using OVRMOD = Register::Combo_Bit<cfgr_reg_type, 12, tf>;

    template<CFGR_EXTEN_T val>
    using EXTEN = Register::Combo_Bitfield<cfgr_reg_type, 10, 2, CFGR_EXTEN_T, val>;

    template<CFGR_EXTSEL_T val>
    using EXTSEL = Register::Combo_Bitfield<cfgr_reg_type, 5, 5, CFGR_EXTSEL_T, val>;

    template<CFGR_RES_T val>
    using RES = Register::Combo_Bitfield<cfgr_reg_type, 3, 2, CFGR_RES_T, val>;

    template<bool tf>
    using DMACFG = Register::Combo_Bit<cfgr_reg_type, 1, tf>;

    template<bool tf>
    using DMAEN = Register::Combo_Bit<cfgr_reg_type, 0, tf>;

} // ADC_CFGR
namespace ADC_CFGR2 {

    enum class cfgr2_reg_type {};

    template<bool tf>
    using SMPTRIG = Register::Combo_Bit<cfgr2_reg_type, 27, tf>;

    template<bool tf>
    using BULB = Register::Combo_Bit<cfgr2_reg_type, 26, tf>;

    template<bool tf>
    using SWTRIG = Register::Combo_Bit<cfgr2_reg_type, 25, tf>;

    template<bool tf>
    using GCOMP = Register::Combo_Bit<cfgr2_reg_type, 16, tf>;

    template<bool tf>
    using ROVSM = Register::Combo_Bit<cfgr2_reg_type, 10, tf>;

    template<bool tf>
    using TROVS = Register::Combo_Bit<cfgr2_reg_type, 9, tf>;

    template<CFGR2_OVSS_T val>
    using OVSS = Register::Combo_Bitfield<cfgr2_reg_type, 5, 4, CFGR2_OVSS_T, val>;

    template<CFGR2_OVSR_T val>
    using OVSR = Register::Combo_Bitfield<cfgr2_reg_type, 2, 3, CFGR2_OVSR_T, val>;

    template<bool tf>
    using JOVSE = Register::Combo_Bit<cfgr2_reg_type, 1, tf>;

    template<bool tf>
    using ROVSE = Register::Combo_Bit<cfgr2_reg_type, 0, tf>;

} // ADC_CFGR2
namespace ADC_SMPR1 {

    enum class smpr1_reg_type {};

    template<SMPR1_SMP9_T val>
    using SMP9 = Register::Combo_Bitfield<smpr1_reg_type, 27, 3, SMPR1_SMP9_T, val>;

    template<SMPR1_SMP8_T val>
    using SMP8 = Register::Combo_Bitfield<smpr1_reg_type, 24, 3, SMPR1_SMP8_T, val>;

    template<SMPR1_SMP7_T val>
    using SMP7 = Register::Combo_Bitfield<smpr1_reg_type, 21, 3, SMPR1_SMP7_T, val>;

    template<SMPR1_SMP6_T val>
    using SMP6 = Register::Combo_Bitfield<smpr1_reg_type, 18, 3, SMPR1_SMP6_T, val>;

    template<SMPR1_SMP5_T val>
    using SMP5 = Register::Combo_Bitfield<smpr1_reg_type, 15, 3, SMPR1_SMP5_T, val>;

    template<SMPR1_SMP4_T val>
    using SMP4 = Register::Combo_Bitfield<smpr1_reg_type, 12, 3, SMPR1_SMP4_T, val>;

    template<SMPR1_SMP3_T val>
    using SMP3 = Register::Combo_Bitfield<smpr1_reg_type, 9, 3, SMPR1_SMP3_T, val>;

    template<SMPR1_SMP2_T val>
    using SMP2 = Register::Combo_Bitfield<smpr1_reg_type, 6, 3, SMPR1_SMP2_T, val>;

    template<SMPR1_SMP1_T val>
    using SMP1 = Register::Combo_Bitfield<smpr1_reg_type, 3, 3, SMPR1_SMP1_T, val>;

    template<bool tf>
    using SMPPLUS = Register::Combo_Bit<smpr1_reg_type, 31, tf>;

    template<SMPR1_SMP0_T val>
    using SMP0 = Register::Combo_Bitfield<smpr1_reg_type, 0, 3, SMPR1_SMP0_T, val>;

} // ADC_SMPR1
namespace ADC_SMPR2 {

    enum class smpr2_reg_type {};

    template<SMPR2_SMP18_T val>
    using SMP18 = Register::Combo_Bitfield<smpr2_reg_type, 24, 3, SMPR2_SMP18_T, val>;

    template<SMPR2_SMP17_T val>
    using SMP17 = Register::Combo_Bitfield<smpr2_reg_type, 21, 3, SMPR2_SMP17_T, val>;

    template<SMPR2_SMP16_T val>
    using SMP16 = Register::Combo_Bitfield<smpr2_reg_type, 18, 3, SMPR2_SMP16_T, val>;

    template<SMPR2_SMP15_T val>
    using SMP15 = Register::Combo_Bitfield<smpr2_reg_type, 15, 3, SMPR2_SMP15_T, val>;

    template<SMPR2_SMP14_T val>
    using SMP14 = Register::Combo_Bitfield<smpr2_reg_type, 12, 3, SMPR2_SMP14_T, val>;

    template<SMPR2_SMP13_T val>
    using SMP13 = Register::Combo_Bitfield<smpr2_reg_type, 9, 3, SMPR2_SMP13_T, val>;

    template<SMPR2_SMP12_T val>
    using SMP12 = Register::Combo_Bitfield<smpr2_reg_type, 6, 3, SMPR2_SMP12_T, val>;

    template<SMPR2_SMP11_T val>
    using SMP11 = Register::Combo_Bitfield<smpr2_reg_type, 3, 3, SMPR2_SMP11_T, val>;

    template<SMPR2_SMP10_T val>
    using SMP10 = Register::Combo_Bitfield<smpr2_reg_type, 0, 3, SMPR2_SMP10_T, val>;

} // ADC_SMPR2
namespace ADC_TR1 {

    enum class tr1_reg_type {};

    template<TR1_HT1_T val>
    using HT1 = Register::Combo_Bitfield<tr1_reg_type, 16, 12, TR1_HT1_T, val>;

    template<TR1_AWDFILT_T val>
    using AWDFILT = Register::Combo_Bitfield<tr1_reg_type, 12, 3, TR1_AWDFILT_T, val>;

    template<TR1_LT1_T val>
    using LT1 = Register::Combo_Bitfield<tr1_reg_type, 0, 12, TR1_LT1_T, val>;

} // ADC_TR1
namespace ADC_TR2 {

    enum class tr2_reg_type {};

    template<TR2_HT2_T val>
    using HT2 = Register::Combo_Bitfield<tr2_reg_type, 16, 8, TR2_HT2_T, val>;

    template<TR2_LT2_T val>
    using LT2 = Register::Combo_Bitfield<tr2_reg_type, 0, 8, TR2_LT2_T, val>;

} // ADC_TR2
namespace ADC_TR3 {

    enum class tr3_reg_type {};

    template<TR3_HT3_T val>
    using HT3 = Register::Combo_Bitfield<tr3_reg_type, 16, 8, TR3_HT3_T, val>;

    template<TR3_LT3_T val>
    using LT3 = Register::Combo_Bitfield<tr3_reg_type, 0, 8, TR3_LT3_T, val>;

} // ADC_TR3
namespace ADC_SQR1 {

    enum class sqr1_reg_type {};

    template<SQR1_SQ4_T val>
    using SQ4 = Register::Combo_Bitfield<sqr1_reg_type, 24, 5, SQR1_SQ4_T, val>;

    template<SQR1_SQ3_T val>
    using SQ3 = Register::Combo_Bitfield<sqr1_reg_type, 18, 5, SQR1_SQ3_T, val>;

    template<SQR1_SQ2_T val>
    using SQ2 = Register::Combo_Bitfield<sqr1_reg_type, 12, 5, SQR1_SQ2_T, val>;

    template<SQR1_SQ1_T val>
    using SQ1 = Register::Combo_Bitfield<sqr1_reg_type, 6, 5, SQR1_SQ1_T, val>;

    template<SQR1_L_T val>
    using L = Register::Combo_Bitfield<sqr1_reg_type, 0, 4, SQR1_L_T, val>;

} // ADC_SQR1
namespace ADC_SQR2 {

    enum class sqr2_reg_type {};

    template<SQR2_SQ9_T val>
    using SQ9 = Register::Combo_Bitfield<sqr2_reg_type, 24, 5, SQR2_SQ9_T, val>;

    template<SQR2_SQ8_T val>
    using SQ8 = Register::Combo_Bitfield<sqr2_reg_type, 18, 5, SQR2_SQ8_T, val>;

    template<SQR2_SQ7_T val>
    using SQ7 = Register::Combo_Bitfield<sqr2_reg_type, 12, 5, SQR2_SQ7_T, val>;

    template<SQR2_SQ6_T val>
    using SQ6 = Register::Combo_Bitfield<sqr2_reg_type, 6, 5, SQR2_SQ6_T, val>;

    template<SQR2_SQ5_T val>
    using SQ5 = Register::Combo_Bitfield<sqr2_reg_type, 0, 5, SQR2_SQ5_T, val>;

} // ADC_SQR2
namespace ADC_SQR3 {

    enum class sqr3_reg_type {};

    template<SQR3_SQ14_T val>
    using SQ14 = Register::Combo_Bitfield<sqr3_reg_type, 24, 5, SQR3_SQ14_T, val>;

    template<SQR3_SQ13_T val>
    using SQ13 = Register::Combo_Bitfield<sqr3_reg_type, 18, 5, SQR3_SQ13_T, val>;

    template<SQR3_SQ12_T val>
    using SQ12 = Register::Combo_Bitfield<sqr3_reg_type, 12, 5, SQR3_SQ12_T, val>;

    template<SQR3_SQ11_T val>
    using SQ11 = Register::Combo_Bitfield<sqr3_reg_type, 6, 5, SQR3_SQ11_T, val>;

    template<SQR3_SQ10_T val>
    using SQ10 = Register::Combo_Bitfield<sqr3_reg_type, 0, 5, SQR3_SQ10_T, val>;

} // ADC_SQR3
namespace ADC_SQR4 {

    enum class sqr4_reg_type {};

    template<SQR4_SQ16_T val>
    using SQ16 = Register::Combo_Bitfield<sqr4_reg_type, 6, 5, SQR4_SQ16_T, val>;

    template<SQR4_SQ15_T val>
    using SQ15 = Register::Combo_Bitfield<sqr4_reg_type, 0, 5, SQR4_SQ15_T, val>;

} // ADC_SQR4
namespace ADC_DR {

    enum class dr_reg_type {};

    template<DR_RDATA_T val>
    using RDATA = Register::Combo_Bitfield<dr_reg_type, 0, 16, DR_RDATA_T, val>;

} // ADC_DR
namespace ADC_JSQR {

    enum class jsqr_reg_type {};

    template<JSQR_JSQ4_T val>
    using JSQ4 = Register::Combo_Bitfield<jsqr_reg_type, 27, 5, JSQR_JSQ4_T, val>;

    template<JSQR_JSQ3_T val>
    using JSQ3 = Register::Combo_Bitfield<jsqr_reg_type, 21, 5, JSQR_JSQ3_T, val>;

    template<JSQR_JSQ2_T val>
    using JSQ2 = Register::Combo_Bitfield<jsqr_reg_type, 15, 5, JSQR_JSQ2_T, val>;

    template<JSQR_JSQ1_T val>
    using JSQ1 = Register::Combo_Bitfield<jsqr_reg_type, 9, 5, JSQR_JSQ1_T, val>;

    template<JSQR_JEXTEN_T val>
    using JEXTEN = Register::Combo_Bitfield<jsqr_reg_type, 7, 2, JSQR_JEXTEN_T, val>;

    template<JSQR_JEXTSEL_T val>
    using JEXTSEL = Register::Combo_Bitfield<jsqr_reg_type, 2, 5, JSQR_JEXTSEL_T, val>;

    template<JSQR_JL_T val>
    using JL = Register::Combo_Bitfield<jsqr_reg_type, 0, 2, JSQR_JL_T, val>;

} // ADC_JSQR
namespace ADC_OFR1 {

    enum class ofr1_reg_type {};

    template<bool tf>
    using OFFSET1_EN = Register::Combo_Bit<ofr1_reg_type, 31, tf>;

    template<OFR1_OFFSET1_CH_T val>
    using OFFSET1_CH = Register::Combo_Bitfield<ofr1_reg_type, 26, 5, OFR1_OFFSET1_CH_T, val>;

    template<bool tf>
    using SATEN = Register::Combo_Bit<ofr1_reg_type, 25, tf>;

    template<bool tf>
    using OFFSETPOS = Register::Combo_Bit<ofr1_reg_type, 24, tf>;

    template<OFR1_OFFSET1_T val>
    using OFFSET1 = Register::Combo_Bitfield<ofr1_reg_type, 0, 12, OFR1_OFFSET1_T, val>;

} // ADC_OFR1
namespace ADC_OFR2 {

    enum class ofr2_reg_type {};

    template<bool tf>
    using OFFSET1_EN = Register::Combo_Bit<ofr2_reg_type, 31, tf>;

    template<OFR2_OFFSET1_CH_T val>
    using OFFSET1_CH = Register::Combo_Bitfield<ofr2_reg_type, 26, 5, OFR2_OFFSET1_CH_T, val>;

    template<bool tf>
    using SATEN = Register::Combo_Bit<ofr2_reg_type, 25, tf>;

    template<bool tf>
    using OFFSETPOS = Register::Combo_Bit<ofr2_reg_type, 24, tf>;

    template<OFR2_OFFSET1_T val>
    using OFFSET1 = Register::Combo_Bitfield<ofr2_reg_type, 0, 12, OFR2_OFFSET1_T, val>;

} // ADC_OFR2
namespace ADC_OFR3 {

    enum class ofr3_reg_type {};

    template<bool tf>
    using OFFSET1_EN = Register::Combo_Bit<ofr3_reg_type, 31, tf>;

    template<OFR3_OFFSET1_CH_T val>
    using OFFSET1_CH = Register::Combo_Bitfield<ofr3_reg_type, 26, 5, OFR3_OFFSET1_CH_T, val>;

    template<bool tf>
    using SATEN = Register::Combo_Bit<ofr3_reg_type, 25, tf>;

    template<bool tf>
    using OFFSETPOS = Register::Combo_Bit<ofr3_reg_type, 24, tf>;

    template<OFR3_OFFSET1_T val>
    using OFFSET1 = Register::Combo_Bitfield<ofr3_reg_type, 0, 12, OFR3_OFFSET1_T, val>;

} // ADC_OFR3
namespace ADC_OFR4 {

    enum class ofr4_reg_type {};

    template<bool tf>
    using OFFSET1_EN = Register::Combo_Bit<ofr4_reg_type, 31, tf>;

    template<OFR4_OFFSET1_CH_T val>
    using OFFSET1_CH = Register::Combo_Bitfield<ofr4_reg_type, 26, 5, OFR4_OFFSET1_CH_T, val>;

    template<bool tf>
    using SATEN = Register::Combo_Bit<ofr4_reg_type, 25, tf>;

    template<bool tf>
    using OFFSETPOS = Register::Combo_Bit<ofr4_reg_type, 24, tf>;

    template<OFR4_OFFSET1_T val>
    using OFFSET1 = Register::Combo_Bitfield<ofr4_reg_type, 0, 12, OFR4_OFFSET1_T, val>;

} // ADC_OFR4
namespace ADC_JDR1 {

    enum class jdr1_reg_type {};

    template<JDR1_JDATA1_T val>
    using JDATA1 = Register::Combo_Bitfield<jdr1_reg_type, 0, 16, JDR1_JDATA1_T, val>;

} // ADC_JDR1
namespace ADC_JDR2 {

    enum class jdr2_reg_type {};

    template<JDR2_JDATA2_T val>
    using JDATA2 = Register::Combo_Bitfield<jdr2_reg_type, 0, 16, JDR2_JDATA2_T, val>;

} // ADC_JDR2
namespace ADC_JDR3 {

    enum class jdr3_reg_type {};

    template<JDR3_JDATA3_T val>
    using JDATA3 = Register::Combo_Bitfield<jdr3_reg_type, 0, 16, JDR3_JDATA3_T, val>;

} // ADC_JDR3
namespace ADC_JDR4 {

    enum class jdr4_reg_type {};

    template<JDR4_JDATA4_T val>
    using JDATA4 = Register::Combo_Bitfield<jdr4_reg_type, 0, 16, JDR4_JDATA4_T, val>;

} // ADC_JDR4
namespace ADC_AWD2CR {

    enum class awd2cr_reg_type {};

    template<AWD2CR_AWD2CH_T val>
    using AWD2CH = Register::Combo_Bitfield<awd2cr_reg_type, 0, 19, AWD2CR_AWD2CH_T, val>;

} // ADC_AWD2CR
namespace ADC_AWD3CR {

    enum class awd3cr_reg_type {};

    template<AWD3CR_AWD3CH_T val>
    using AWD3CH = Register::Combo_Bitfield<awd3cr_reg_type, 0, 19, AWD3CR_AWD3CH_T, val>;

} // ADC_AWD3CR
namespace ADC_DIFSEL {

    enum class difsel_reg_type {};

    template<bool tf>
    using DIFSEL_0 = Register::Combo_Bit<difsel_reg_type, 0, tf>;

    template<DIFSEL_DIFSEL_1_18_T val>
    using DIFSEL_1_18 = Register::Combo_Bitfield<difsel_reg_type, 1, 18, DIFSEL_DIFSEL_1_18_T, val>;

} // ADC_DIFSEL
namespace ADC_CALFACT {

    enum class calfact_reg_type {};

    template<CALFACT_CALFACT_D_T val>
    using CALFACT_D = Register::Combo_Bitfield<calfact_reg_type, 16, 7, CALFACT_CALFACT_D_T, val>;

    template<CALFACT_CALFACT_S_T val>
    using CALFACT_S = Register::Combo_Bitfield<calfact_reg_type, 0, 7, CALFACT_CALFACT_S_T, val>;

} // ADC_CALFACT
namespace ADC_GCOMP {

    enum class gcomp_reg_type {};

    template<GCOMP_GCOMPCOEFF_T val>
    using GCOMPCOEFF = Register::Combo_Bitfield<gcomp_reg_type, 0, 14, GCOMP_GCOMPCOEFF_T, val>;

} // ADC_GCOMP
template<uint32_t BASE_ADDRESS>
class ADC {
public:
    static const uint32_t ISR_Offset = 0x0000;
    static const uint32_t IER_Offset = 0x0004;
    static const uint32_t CR_Offset = 0x0008;
    static const uint32_t CFGR_Offset = 0x000C;
    static const uint32_t CFGR2_Offset = 0x0010;
    static const uint32_t SMPR1_Offset = 0x0014;
    static const uint32_t SMPR2_Offset = 0x0018;
    static const uint32_t TR1_Offset = 0x0020;
    static const uint32_t TR2_Offset = 0x0024;
    static const uint32_t TR3_Offset = 0x0028;
    static const uint32_t SQR1_Offset = 0x0030;
    static const uint32_t SQR2_Offset = 0x0034;
    static const uint32_t SQR3_Offset = 0x0038;
    static const uint32_t SQR4_Offset = 0x003C;
    static const uint32_t DR_Offset = 0x0040;
    static const uint32_t JSQR_Offset = 0x004C;
    static const uint32_t OFR1_Offset = 0x0060;
    static const uint32_t OFR2_Offset = 0x0064;
    static const uint32_t OFR3_Offset = 0x0068;
    static const uint32_t OFR4_Offset = 0x006C;
    static const uint32_t JDR1_Offset = 0x0080;
    static const uint32_t JDR2_Offset = 0x0084;
    static const uint32_t JDR3_Offset = 0x0088;
    static const uint32_t JDR4_Offset = 0x008C;
    static const uint32_t AWD2CR_Offset = 0x00A0;
    static const uint32_t AWD3CR_Offset = 0x00A4;
    static const uint32_t DIFSEL_Offset = 0x00B0;
    static const uint32_t CALFACT_Offset = 0x00B4;
    static const uint32_t GCOMP_Offset = 0x00C0;

    ADC() = default;
    ADC( const ADC& ) = delete;
    const ADC& operator=( const ADC& ) = delete;

    class ISR_T : public Register::Register<ADC_ISR::isr_reg_type, BASE_ADDRESS + ISR_Offset> {
    // interrupt and status register
    public:
        Register::Bit<BASE_ADDRESS + ISR_Offset, 10> JQOVF; /* JQOVF */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 9> AWD3; /* AWD3 */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 8> AWD2; /* AWD2 */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 7> AWD1; /* AWD1 */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 6> JEOS; /* JEOS */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 5> JEOC; /* JEOC */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 4> OVR; /* OVR */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 3> EOS; /* EOS */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 2> EOC; /* EOC */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 1> EOSMP; /* EOSMP */
        Register::Bit<BASE_ADDRESS + ISR_Offset, 0> ADRDY; /* ADRDY */
    };

    class IER_T : public Register::Register<ADC_IER::ier_reg_type, BASE_ADDRESS + IER_Offset> {
    // interrupt enable register
    public:
        Register::Bit<BASE_ADDRESS + IER_Offset, 10> JQOVFIE; /* JQOVFIE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 9> AWD3IE; /* AWD3IE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 8> AWD2IE; /* AWD2IE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 7> AWD1IE; /* AWD1IE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 6> JEOSIE; /* JEOSIE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 5> JEOCIE; /* JEOCIE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 4> OVRIE; /* OVRIE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 3> EOSIE; /* EOSIE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 2> EOCIE; /* EOCIE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 1> EOSMPIE; /* EOSMPIE */
        Register::Bit<BASE_ADDRESS + IER_Offset, 0> ADRDYIE; /* ADRDYIE */
    };

    class CR_T : public Register::Register<ADC_CR::cr_reg_type, BASE_ADDRESS + CR_Offset> {
    // control register
    public:
        Register::Bit<BASE_ADDRESS + CR_Offset, 31> ADCAL; /* ADCAL */
        Register::Bit<BASE_ADDRESS + CR_Offset, 30> ADCALDIF; /* ADCALDIF */
        Register::Bit<BASE_ADDRESS + CR_Offset, 29> DEEPPWD; /* DEEPPWD */
        Register::Bit<BASE_ADDRESS + CR_Offset, 28> ADVREGEN; /* ADVREGEN */
        Register::Bit<BASE_ADDRESS + CR_Offset, 5> JADSTP; /* JADSTP */
        Register::Bit<BASE_ADDRESS + CR_Offset, 4> ADSTP; /* ADSTP */
        Register::Bit<BASE_ADDRESS + CR_Offset, 3> JADSTART; /* JADSTART */
        Register::Bit<BASE_ADDRESS + CR_Offset, 2> ADSTART; /* ADSTART */
        Register::Bit<BASE_ADDRESS + CR_Offset, 1> ADDIS; /* ADDIS */
        Register::Bit<BASE_ADDRESS + CR_Offset, 0> ADEN; /* ADEN */
    };

    class CFGR_T : public Register::Register<ADC_CFGR::cfgr_reg_type, BASE_ADDRESS + CFGR_Offset> {
    // configuration register
    public:
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 31> JQDIS; /* Injected Queue disable */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 26, 5, CFGR_AWD1CH_T> AWD1CH; /* Analog watchdog 1 channel selection */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 25> JAUTO; /* JAUTO */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 24> JAWD1EN; /* JAWD1EN */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 23> AWD1EN; /* AWD1EN */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 22> AWD1SGL; /* AWD1SGL */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 21> JQM; /* JQM */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 20> JDISCEN; /* JDISCEN */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 17, 3, CFGR_DISCNUM_T> DISCNUM; /* DISCNUM */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 16> DISCEN; /* DISCEN */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 15> ALIGN; /* ALIGN */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 14> AUTDLY; /* AUTDLY */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 13> CONT; /* CONT */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 12> OVRMOD; /* OVRMOD */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 10, 2, CFGR_EXTEN_T> EXTEN; /* EXTEN */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 5, 5, CFGR_EXTSEL_T> EXTSEL; /* External trigger selection for regular group */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 3, 2, CFGR_RES_T> RES; /* RES */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 1> DMACFG; /* DMACFG */
        Register::Bit<BASE_ADDRESS + CFGR_Offset, 0> DMAEN; /* DMAEN */
    };

    class CFGR2_T : public Register::Register<ADC_CFGR2::cfgr2_reg_type, BASE_ADDRESS + CFGR2_Offset> {
    // configuration register
    public:
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 27> SMPTRIG; /* SMPTRIG */
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 26> BULB; /* BULB */
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 25> SWTRIG; /* SWTRIG */
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 16> GCOMP; /* GCOMP */
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 10> ROVSM; /* EXTEN */
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 9> TROVS; /* Triggered Regular Oversampling */
        Register::Bitfield<BASE_ADDRESS + CFGR2_Offset, 5, 4, CFGR2_OVSS_T> OVSS; /* ALIGN */
        Register::Bitfield<BASE_ADDRESS + CFGR2_Offset, 2, 3, CFGR2_OVSR_T> OVSR; /* RES */
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 1> JOVSE; /* DMACFG */
        Register::Bit<BASE_ADDRESS + CFGR2_Offset, 0> ROVSE; /* DMAEN */
    };

    class SMPR1_T : public Register::Register<ADC_SMPR1::smpr1_reg_type, BASE_ADDRESS + SMPR1_Offset> {
    // sample time register 1
    public:
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 27, 3, SMPR1_SMP9_T> SMP9; /* SMP9 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 24, 3, SMPR1_SMP8_T> SMP8; /* SMP8 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 21, 3, SMPR1_SMP7_T> SMP7; /* SMP7 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 18, 3, SMPR1_SMP6_T> SMP6; /* SMP6 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 15, 3, SMPR1_SMP5_T> SMP5; /* SMP5 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 12, 3, SMPR1_SMP4_T> SMP4; /* SMP4 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 9, 3, SMPR1_SMP3_T> SMP3; /* SMP3 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 6, 3, SMPR1_SMP2_T> SMP2; /* SMP2 */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 3, 3, SMPR1_SMP1_T> SMP1; /* SMP1 */
        Register::Bit<BASE_ADDRESS + SMPR1_Offset, 31> SMPPLUS; /* Addition of one clock cycle to the sampling time */
        Register::Bitfield<BASE_ADDRESS + SMPR1_Offset, 0, 3, SMPR1_SMP0_T> SMP0; /* SMP0 */
    };

    class SMPR2_T : public Register::Register<ADC_SMPR2::smpr2_reg_type, BASE_ADDRESS + SMPR2_Offset> {
    // sample time register 2
    public:
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 24, 3, SMPR2_SMP18_T> SMP18; /* SMP18 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 21, 3, SMPR2_SMP17_T> SMP17; /* SMP17 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 18, 3, SMPR2_SMP16_T> SMP16; /* SMP16 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 15, 3, SMPR2_SMP15_T> SMP15; /* SMP15 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 12, 3, SMPR2_SMP14_T> SMP14; /* SMP14 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 9, 3, SMPR2_SMP13_T> SMP13; /* SMP13 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 6, 3, SMPR2_SMP12_T> SMP12; /* SMP12 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 3, 3, SMPR2_SMP11_T> SMP11; /* SMP11 */
        Register::Bitfield<BASE_ADDRESS + SMPR2_Offset, 0, 3, SMPR2_SMP10_T> SMP10; /* SMP10 */
    };

    class TR1_T : public Register::Register<ADC_TR1::tr1_reg_type, BASE_ADDRESS + TR1_Offset> {
    // watchdog threshold register 1
    public:
        Register::Bitfield<BASE_ADDRESS + TR1_Offset, 16, 12, TR1_HT1_T> HT1; /* HT1 */
        Register::Bitfield<BASE_ADDRESS + TR1_Offset, 12, 3, TR1_AWDFILT_T> AWDFILT; /* AWDFILT */
        Register::Bitfield<BASE_ADDRESS + TR1_Offset, 0, 12, TR1_LT1_T> LT1; /* LT1 */
    };

    class TR2_T : public Register::Register<ADC_TR2::tr2_reg_type, BASE_ADDRESS + TR2_Offset> {
    // watchdog threshold register
    public:
        Register::Bitfield<BASE_ADDRESS + TR2_Offset, 16, 8, TR2_HT2_T> HT2; /* HT2 */
        Register::Bitfield<BASE_ADDRESS + TR2_Offset, 0, 8, TR2_LT2_T> LT2; /* LT2 */
    };

    class TR3_T : public Register::Register<ADC_TR3::tr3_reg_type, BASE_ADDRESS + TR3_Offset> {
    // watchdog threshold register 3
    public:
        Register::Bitfield<BASE_ADDRESS + TR3_Offset, 16, 8, TR3_HT3_T> HT3; /* HT3 */
        Register::Bitfield<BASE_ADDRESS + TR3_Offset, 0, 8, TR3_LT3_T> LT3; /* LT3 */
    };

    class SQR1_T : public Register::Register<ADC_SQR1::sqr1_reg_type, BASE_ADDRESS + SQR1_Offset> {
    // regular sequence register 1
    public:
        Register::Bitfield<BASE_ADDRESS + SQR1_Offset, 24, 5, SQR1_SQ4_T> SQ4; /* SQ4 */
        Register::Bitfield<BASE_ADDRESS + SQR1_Offset, 18, 5, SQR1_SQ3_T> SQ3; /* SQ3 */
        Register::Bitfield<BASE_ADDRESS + SQR1_Offset, 12, 5, SQR1_SQ2_T> SQ2; /* SQ2 */
        Register::Bitfield<BASE_ADDRESS + SQR1_Offset, 6, 5, SQR1_SQ1_T> SQ1; /* SQ1 */
        Register::Bitfield<BASE_ADDRESS + SQR1_Offset, 0, 4, SQR1_L_T> L; /* Regular channel sequence length */
    };

    class SQR2_T : public Register::Register<ADC_SQR2::sqr2_reg_type, BASE_ADDRESS + SQR2_Offset> {
    // regular sequence register 2
    public:
        Register::Bitfield<BASE_ADDRESS + SQR2_Offset, 24, 5, SQR2_SQ9_T> SQ9; /* SQ9 */
        Register::Bitfield<BASE_ADDRESS + SQR2_Offset, 18, 5, SQR2_SQ8_T> SQ8; /* SQ8 */
        Register::Bitfield<BASE_ADDRESS + SQR2_Offset, 12, 5, SQR2_SQ7_T> SQ7; /* SQ7 */
        Register::Bitfield<BASE_ADDRESS + SQR2_Offset, 6, 5, SQR2_SQ6_T> SQ6; /* SQ6 */
        Register::Bitfield<BASE_ADDRESS + SQR2_Offset, 0, 5, SQR2_SQ5_T> SQ5; /* SQ5 */
    };

    class SQR3_T : public Register::Register<ADC_SQR3::sqr3_reg_type, BASE_ADDRESS + SQR3_Offset> {
    // regular sequence register 3
    public:
        Register::Bitfield<BASE_ADDRESS + SQR3_Offset, 24, 5, SQR3_SQ14_T> SQ14; /* SQ14 */
        Register::Bitfield<BASE_ADDRESS + SQR3_Offset, 18, 5, SQR3_SQ13_T> SQ13; /* SQ13 */
        Register::Bitfield<BASE_ADDRESS + SQR3_Offset, 12, 5, SQR3_SQ12_T> SQ12; /* SQ12 */
        Register::Bitfield<BASE_ADDRESS + SQR3_Offset, 6, 5, SQR3_SQ11_T> SQ11; /* SQ11 */
        Register::Bitfield<BASE_ADDRESS + SQR3_Offset, 0, 5, SQR3_SQ10_T> SQ10; /* SQ10 */
    };

    class SQR4_T : public Register::Register<ADC_SQR4::sqr4_reg_type, BASE_ADDRESS + SQR4_Offset> {
    // regular sequence register 4
    public:
        Register::Bitfield<BASE_ADDRESS + SQR4_Offset, 6, 5, SQR4_SQ16_T> SQ16; /* SQ16 */
        Register::Bitfield<BASE_ADDRESS + SQR4_Offset, 0, 5, SQR4_SQ15_T> SQ15; /* SQ15 */
    };

    class DR_T : public Register::Register<ADC_DR::dr_reg_type, BASE_ADDRESS + DR_Offset> {
    // regular Data Register
    public:
        Register::Bitfield<BASE_ADDRESS + DR_Offset, 0, 16, DR_RDATA_T> RDATA; /* Regular Data converted */
    };

    class JSQR_T : public Register::Register<ADC_JSQR::jsqr_reg_type, BASE_ADDRESS + JSQR_Offset> {
    // injected sequence register
    public:
        Register::Bitfield<BASE_ADDRESS + JSQR_Offset, 27, 5, JSQR_JSQ4_T> JSQ4; /* JSQ4 */
        Register::Bitfield<BASE_ADDRESS + JSQR_Offset, 21, 5, JSQR_JSQ3_T> JSQ3; /* JSQ3 */
        Register::Bitfield<BASE_ADDRESS + JSQR_Offset, 15, 5, JSQR_JSQ2_T> JSQ2; /* JSQ2 */
        Register::Bitfield<BASE_ADDRESS + JSQR_Offset, 9, 5, JSQR_JSQ1_T> JSQ1; /* JSQ1 */
        Register::Bitfield<BASE_ADDRESS + JSQR_Offset, 7, 2, JSQR_JEXTEN_T> JEXTEN; /* JEXTEN */
        Register::Bitfield<BASE_ADDRESS + JSQR_Offset, 2, 5, JSQR_JEXTSEL_T> JEXTSEL; /* JEXTSEL */
        Register::Bitfield<BASE_ADDRESS + JSQR_Offset, 0, 2, JSQR_JL_T> JL; /* JL */
    };

    class OFR1_T : public Register::Register<ADC_OFR1::ofr1_reg_type, BASE_ADDRESS + OFR1_Offset> {
    // offset register 1
    public:
        Register::Bit<BASE_ADDRESS + OFR1_Offset, 31> OFFSET1_EN; /* OFFSET1_EN */
        Register::Bitfield<BASE_ADDRESS + OFR1_Offset, 26, 5, OFR1_OFFSET1_CH_T> OFFSET1_CH; /* OFFSET1_CH */
        Register::Bit<BASE_ADDRESS + OFR1_Offset, 25> SATEN; /* SATEN */
        Register::Bit<BASE_ADDRESS + OFR1_Offset, 24> OFFSETPOS; /* OFFSETPOS */
        Register::Bitfield<BASE_ADDRESS + OFR1_Offset, 0, 12, OFR1_OFFSET1_T> OFFSET1; /* OFFSET1 */
    };

    class OFR2_T : public Register::Register<ADC_OFR2::ofr2_reg_type, BASE_ADDRESS + OFR2_Offset> {
    // offset register 2
    public:
        Register::Bit<BASE_ADDRESS + OFR2_Offset, 31> OFFSET1_EN; /* OFFSET1_EN */
        Register::Bitfield<BASE_ADDRESS + OFR2_Offset, 26, 5, OFR2_OFFSET1_CH_T> OFFSET1_CH; /* OFFSET1_CH */
        Register::Bit<BASE_ADDRESS + OFR2_Offset, 25> SATEN; /* SATEN */
        Register::Bit<BASE_ADDRESS + OFR2_Offset, 24> OFFSETPOS; /* OFFSETPOS */
        Register::Bitfield<BASE_ADDRESS + OFR2_Offset, 0, 12, OFR2_OFFSET1_T> OFFSET1; /* OFFSET1 */
    };

    class OFR3_T : public Register::Register<ADC_OFR3::ofr3_reg_type, BASE_ADDRESS + OFR3_Offset> {
    // offset register 3
    public:
        Register::Bit<BASE_ADDRESS + OFR3_Offset, 31> OFFSET1_EN; /* OFFSET1_EN */
        Register::Bitfield<BASE_ADDRESS + OFR3_Offset, 26, 5, OFR3_OFFSET1_CH_T> OFFSET1_CH; /* OFFSET1_CH */
        Register::Bit<BASE_ADDRESS + OFR3_Offset, 25> SATEN; /* SATEN */
        Register::Bit<BASE_ADDRESS + OFR3_Offset, 24> OFFSETPOS; /* OFFSETPOS */
        Register::Bitfield<BASE_ADDRESS + OFR3_Offset, 0, 12, OFR3_OFFSET1_T> OFFSET1; /* OFFSET1 */
    };

    class OFR4_T : public Register::Register<ADC_OFR4::ofr4_reg_type, BASE_ADDRESS + OFR4_Offset> {
    // offset register 4
    public:
        Register::Bit<BASE_ADDRESS + OFR4_Offset, 31> OFFSET1_EN; /* OFFSET1_EN */
        Register::Bitfield<BASE_ADDRESS + OFR4_Offset, 26, 5, OFR4_OFFSET1_CH_T> OFFSET1_CH; /* OFFSET1_CH */
        Register::Bit<BASE_ADDRESS + OFR4_Offset, 25> SATEN; /* SATEN */
        Register::Bit<BASE_ADDRESS + OFR4_Offset, 24> OFFSETPOS; /* OFFSETPOS */
        Register::Bitfield<BASE_ADDRESS + OFR4_Offset, 0, 12, OFR4_OFFSET1_T> OFFSET1; /* OFFSET1 */
    };

    class JDR1_T : public Register::Register<ADC_JDR1::jdr1_reg_type, BASE_ADDRESS + JDR1_Offset> {
    // injected data register 1
    public:
        Register::Bitfield<BASE_ADDRESS + JDR1_Offset, 0, 16, JDR1_JDATA1_T> JDATA1; /* JDATA1 */
    };

    class JDR2_T : public Register::Register<ADC_JDR2::jdr2_reg_type, BASE_ADDRESS + JDR2_Offset> {
    // injected data register 2
    public:
        Register::Bitfield<BASE_ADDRESS + JDR2_Offset, 0, 16, JDR2_JDATA2_T> JDATA2; /* JDATA2 */
    };

    class JDR3_T : public Register::Register<ADC_JDR3::jdr3_reg_type, BASE_ADDRESS + JDR3_Offset> {
    // injected data register 3
    public:
        Register::Bitfield<BASE_ADDRESS + JDR3_Offset, 0, 16, JDR3_JDATA3_T> JDATA3; /* JDATA3 */
    };

    class JDR4_T : public Register::Register<ADC_JDR4::jdr4_reg_type, BASE_ADDRESS + JDR4_Offset> {
    // injected data register 4
    public:
        Register::Bitfield<BASE_ADDRESS + JDR4_Offset, 0, 16, JDR4_JDATA4_T> JDATA4; /* JDATA4 */
    };

    class AWD2CR_T : public Register::Register<ADC_AWD2CR::awd2cr_reg_type, BASE_ADDRESS + AWD2CR_Offset> {
    // Analog Watchdog 2 Configuration Register
    public:
        Register::Bitfield<BASE_ADDRESS + AWD2CR_Offset, 0, 19, AWD2CR_AWD2CH_T> AWD2CH; /* AWD2CH */
    };

    class AWD3CR_T : public Register::Register<ADC_AWD3CR::awd3cr_reg_type, BASE_ADDRESS + AWD3CR_Offset> {
    // Analog Watchdog 3 Configuration Register
    public:
        Register::Bitfield<BASE_ADDRESS + AWD3CR_Offset, 0, 19, AWD3CR_AWD3CH_T> AWD3CH; /* AWD3CH */
    };

    class DIFSEL_T : public Register::Register<ADC_DIFSEL::difsel_reg_type, BASE_ADDRESS + DIFSEL_Offset> {
    // Differential Mode Selection Register 2
    public:
        Register::Bit<BASE_ADDRESS + DIFSEL_Offset, 0> DIFSEL_0; /* Differential mode for channels 0 */
        Register::Bitfield<BASE_ADDRESS + DIFSEL_Offset, 1, 18, DIFSEL_DIFSEL_1_18_T> DIFSEL_1_18; /* Differential mode for channels 15 to 1 */
    };

    class CALFACT_T : public Register::Register<ADC_CALFACT::calfact_reg_type, BASE_ADDRESS + CALFACT_Offset> {
    // Calibration Factors
    public:
        Register::Bitfield<BASE_ADDRESS + CALFACT_Offset, 16, 7, CALFACT_CALFACT_D_T> CALFACT_D; /* CALFACT_D */
        Register::Bitfield<BASE_ADDRESS + CALFACT_Offset, 0, 7, CALFACT_CALFACT_S_T> CALFACT_S; /* CALFACT_S */
    };

    class GCOMP_T : public Register::Register<ADC_GCOMP::gcomp_reg_type, BASE_ADDRESS + GCOMP_Offset> {
    // Gain compensation Register
    public:
        Register::Bitfield<BASE_ADDRESS + GCOMP_Offset, 0, 14, GCOMP_GCOMPCOEFF_T> GCOMPCOEFF; /* GCOMPCOEFF */
    };

    ISR_T ISR;
    IER_T IER;
    CR_T CR;
    CFGR_T CFGR;
    CFGR2_T CFGR2;
    SMPR1_T SMPR1;
    SMPR2_T SMPR2;
    TR1_T TR1;
    TR2_T TR2;
    TR3_T TR3;
    SQR1_T SQR1;
    SQR2_T SQR2;
    SQR3_T SQR3;
    SQR4_T SQR4;
    DR_T DR;
    JSQR_T JSQR;
    OFR1_T OFR1;
    OFR2_T OFR2;
    OFR3_T OFR3;
    OFR4_T OFR4;
    JDR1_T JDR1;
    JDR2_T JDR2;
    JDR3_T JDR3;
    JDR4_T JDR4;
    AWD2CR_T AWD2CR;
    AWD3CR_T AWD3CR;
    DIFSEL_T DIFSEL;
    CALFACT_T CALFACT;
    GCOMP_T GCOMP;
};

} // namespace STM32LIB

#endif // STM32G473XX_ADC_HPP_

