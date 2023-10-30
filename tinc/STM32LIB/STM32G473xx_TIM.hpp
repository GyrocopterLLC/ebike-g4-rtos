#ifndef STM32G473XX_TIM_HPP_
#define STM32G473XX_TIM_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"
#include "Timer_Types.hpp"

/* Advanced-timers */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using CR1_CKD_T = CR1_Clock_Division;
using CR1_CMS_T = CR1_Alignment_Mode;
using CR2_MMS2_T = CR2_Main_Mode_2;
using CR2_MMS_T = CR2_Main_Mode;
using SMCR_TS_4_3_T = uint32_t;
using SMCR_ETPS_T = SMCR_External_Trigger_Prescaler;
using SMCR_ETF_T = Timer_Filter;
using SMCR_TS_T = uint32_t;
using SMCR_SMS_T = SMCR_Secondary_Mode_Selection;
using CCMR1_Output_OC2M_T = CCMR_Output_Compare_Mode;
using CCMR1_Output_CC2S_T = CCMR_Capture_Compare_Selection;
using CCMR1_Output_OC1M_T = CCMR_Output_Compare_Mode;
using CCMR1_Output_CC1S_T = CCMR_Capture_Compare_Selection;
using CCMR1_Input_IC2F_T = Timer_Filter;
using CCMR1_Input_IC2PSC_T = CCMR_Input_Prescaler;
using CCMR1_Input_CC2S_T = CCMR_Capture_Compare_Selection;
using CCMR1_Input_IC1F_T = Timer_Filter;
using CCMR1_Input_ICPCS_T = CCMR_Input_Prescaler;
using CCMR1_Input_CC1S_T = CCMR_Capture_Compare_Selection;
using CCMR2_Output_OC4M_T = CCMR_Output_Compare_Mode;
using CCMR2_Output_CC4S_T = CCMR_Capture_Compare_Selection;
using CCMR2_Output_OC3M_T = CCMR_Output_Compare_Mode;
using CCMR2_Output_CC3S_T = CCMR_Capture_Compare_Selection;
using CCMR2_Input_IC4F_T = Timer_Filter;
using CCMR2_Input_IC4PSC_T = CCMR_Input_Prescaler;
using CCMR2_Input_CC4S_T = CCMR_Capture_Compare_Selection;
using CCMR2_Input_IC3F_T = Timer_Filter;
using CCMR2_Input_IC3PSC_T = CCMR_Input_Prescaler;
using CCMR2_Input_CC3S_T = CCMR_Capture_Compare_Selection;
using CNT_CNT_T = uint32_t;
using PSC_PSC_T = uint32_t;
using ARR_ARR_T = uint32_t;
using RCR_REP_T = uint32_t;
using CCR1_CCR1_T = uint32_t;
using CCR2_CCR2_T = uint32_t;
using CCR3_CCR3_T = uint32_t;
using CCR4_CCR4_T = uint32_t;
using BDTR_BK2F_T = Timer_Filter;
using BDTR_BKF_T = Timer_Filter;
using BDTR_LOCK_T = BDTR_Lock_Configuration;
using BDTR_DTG_T = uint32_t;
using CCR5_CCR5_T = uint32_t;
using CCR6_CCR6_T = uint32_t;
using CCMR3_Output_OC6M_T = CCMR_Output_Compare_Mode;
using CCMR3_Output_OC5M_T = CCMR_Output_Compare_Mode;
using DTR2_DTGF_T = uint32_t;
using ECR_IDIR_T = ECR_Index_Direction;
using ECR_IBLK_T = uint32_t;
using ECR_IPOS_T = ECR_Index_Positioning;
using ECR_PW_T = uint32_t;
using ECR_PWPRSC_T = uint32_t;
using TISEL_TI1SEL_T = uint32_t;
using TISEL_TI2SEL_T = uint32_t;
using TISEL_TI3SEL_T = uint32_t;
using TISEL_TI4SEL_T = uint32_t;
using AF1_ETRSEL_T = uint32_t;
using AF2_OCRSEL_T = uint32_t;
using DCR_DBL_T = uint32_t;
using DCR_DBA_T = uint32_t;
using DMAR_DMAB_T = uint32_t;

namespace TIM_CR1 {

    enum class cr1_reg_type {};

    template<bool tf>
    using DITHEN = Register::Combo_Bit<cr1_reg_type, 12, tf>;

    template<bool tf>
    using UIFREMAP = Register::Combo_Bit<cr1_reg_type, 11, tf>;

    template<CR1_CKD_T val>
    using CKD = Register::Combo_Bitfield<cr1_reg_type, 8, 2, CR1_CKD_T, val>;

    template<bool tf>
    using ARPE = Register::Combo_Bit<cr1_reg_type, 7, tf>;

    template<CR1_CMS_T val>
    using CMS = Register::Combo_Bitfield<cr1_reg_type, 5, 2, CR1_CMS_T, val>;

    template<bool tf>
    using DIR = Register::Combo_Bit<cr1_reg_type, 4, tf>;

    template<bool tf>
    using OPM = Register::Combo_Bit<cr1_reg_type, 3, tf>;

    template<bool tf>
    using URS = Register::Combo_Bit<cr1_reg_type, 2, tf>;

    template<bool tf>
    using UDIS = Register::Combo_Bit<cr1_reg_type, 1, tf>;

    template<bool tf>
    using CEN = Register::Combo_Bit<cr1_reg_type, 0, tf>;

} // TIM_CR1
namespace TIM_CR2 {

    enum class cr2_reg_type {};

    template<bool tf>
    using MMS_3 = Register::Combo_Bit<cr2_reg_type, 25, tf>;

    template<CR2_MMS2_T val>
    using MMS2 = Register::Combo_Bitfield<cr2_reg_type, 20, 4, CR2_MMS2_T, val>;

    template<bool tf>
    using OIS6 = Register::Combo_Bit<cr2_reg_type, 18, tf>;

    template<bool tf>
    using OIS5 = Register::Combo_Bit<cr2_reg_type, 16, tf>;

    template<bool tf>
    using OIS4N = Register::Combo_Bit<cr2_reg_type, 15, tf>;

    template<bool tf>
    using OIS4 = Register::Combo_Bit<cr2_reg_type, 14, tf>;

    template<bool tf>
    using OIS3N = Register::Combo_Bit<cr2_reg_type, 13, tf>;

    template<bool tf>
    using OIS3 = Register::Combo_Bit<cr2_reg_type, 12, tf>;

    template<bool tf>
    using OIS2N = Register::Combo_Bit<cr2_reg_type, 11, tf>;

    template<bool tf>
    using OIS2 = Register::Combo_Bit<cr2_reg_type, 10, tf>;

    template<bool tf>
    using OIS1N = Register::Combo_Bit<cr2_reg_type, 9, tf>;

    template<bool tf>
    using OIS1 = Register::Combo_Bit<cr2_reg_type, 8, tf>;

    template<bool tf>
    using TI1S = Register::Combo_Bit<cr2_reg_type, 7, tf>;

    template<CR2_MMS_T val>
    using MMS = Register::Combo_Bitfield<cr2_reg_type, 4, 3, CR2_MMS_T, val>;

    template<bool tf>
    using CCDS = Register::Combo_Bit<cr2_reg_type, 3, tf>;

    template<bool tf>
    using CCUS = Register::Combo_Bit<cr2_reg_type, 2, tf>;

    template<bool tf>
    using CCPC = Register::Combo_Bit<cr2_reg_type, 0, tf>;

} // TIM_CR2
namespace TIM_SMCR {

    enum class smcr_reg_type {};

    template<bool tf>
    using SMSPS = Register::Combo_Bit<smcr_reg_type, 25, tf>;

    template<bool tf>
    using SMSPE = Register::Combo_Bit<smcr_reg_type, 24, tf>;

    template<SMCR_TS_4_3_T val>
    using TS_4_3 = Register::Combo_Bitfield<smcr_reg_type, 20, 2, SMCR_TS_4_3_T, val>;

    template<bool tf>
    using SMS_3 = Register::Combo_Bit<smcr_reg_type, 16, tf>;

    template<bool tf>
    using ETP = Register::Combo_Bit<smcr_reg_type, 15, tf>;

    template<bool tf>
    using ECE = Register::Combo_Bit<smcr_reg_type, 14, tf>;

    template<SMCR_ETPS_T val>
    using ETPS = Register::Combo_Bitfield<smcr_reg_type, 12, 2, SMCR_ETPS_T, val>;

    template<SMCR_ETF_T val>
    using ETF = Register::Combo_Bitfield<smcr_reg_type, 8, 4, SMCR_ETF_T, val>;

    template<bool tf>
    using MSM = Register::Combo_Bit<smcr_reg_type, 7, tf>;

    template<SMCR_TS_T val>
    using TS = Register::Combo_Bitfield<smcr_reg_type, 4, 3, SMCR_TS_T, val>;

    template<bool tf>
    using OCCS = Register::Combo_Bit<smcr_reg_type, 3, tf>;

    template<SMCR_SMS_T val>
    using SMS = Register::Combo_Bitfield<smcr_reg_type, 0, 3, SMCR_SMS_T, val>;

} // TIM_SMCR
namespace TIM_DIER {

    enum class dier_reg_type {};

    template<bool tf>
    using TERRIE = Register::Combo_Bit<dier_reg_type, 23, tf>;

    template<bool tf>
    using IERRIE = Register::Combo_Bit<dier_reg_type, 22, tf>;

    template<bool tf>
    using DIRIE = Register::Combo_Bit<dier_reg_type, 21, tf>;

    template<bool tf>
    using IDXIE = Register::Combo_Bit<dier_reg_type, 20, tf>;

    template<bool tf>
    using TDE = Register::Combo_Bit<dier_reg_type, 14, tf>;

    template<bool tf>
    using COMDE = Register::Combo_Bit<dier_reg_type, 13, tf>;

    template<bool tf>
    using CC4DE = Register::Combo_Bit<dier_reg_type, 12, tf>;

    template<bool tf>
    using CC3DE = Register::Combo_Bit<dier_reg_type, 11, tf>;

    template<bool tf>
    using CC2DE = Register::Combo_Bit<dier_reg_type, 10, tf>;

    template<bool tf>
    using CC1DE = Register::Combo_Bit<dier_reg_type, 9, tf>;

    template<bool tf>
    using UDE = Register::Combo_Bit<dier_reg_type, 8, tf>;

    template<bool tf>
    using TIE = Register::Combo_Bit<dier_reg_type, 6, tf>;

    template<bool tf>
    using CC4IE = Register::Combo_Bit<dier_reg_type, 4, tf>;

    template<bool tf>
    using CC3IE = Register::Combo_Bit<dier_reg_type, 3, tf>;

    template<bool tf>
    using CC2IE = Register::Combo_Bit<dier_reg_type, 2, tf>;

    template<bool tf>
    using CC1IE = Register::Combo_Bit<dier_reg_type, 1, tf>;

    template<bool tf>
    using UIE = Register::Combo_Bit<dier_reg_type, 0, tf>;

    template<bool tf>
    using BIE = Register::Combo_Bit<dier_reg_type, 7, tf>;

    template<bool tf>
    using COMIE = Register::Combo_Bit<dier_reg_type, 5, tf>;

} // TIM_DIER
namespace TIM_SR {

    enum class sr_reg_type {};

    template<bool tf>
    using TERRF = Register::Combo_Bit<sr_reg_type, 23, tf>;

    template<bool tf>
    using IERRF = Register::Combo_Bit<sr_reg_type, 22, tf>;

    template<bool tf>
    using DIRF = Register::Combo_Bit<sr_reg_type, 21, tf>;

    template<bool tf>
    using IDXF = Register::Combo_Bit<sr_reg_type, 20, tf>;

    template<bool tf>
    using CC6IF = Register::Combo_Bit<sr_reg_type, 17, tf>;

    template<bool tf>
    using CC5IF = Register::Combo_Bit<sr_reg_type, 16, tf>;

    template<bool tf>
    using SBIF = Register::Combo_Bit<sr_reg_type, 13, tf>;

    template<bool tf>
    using CC4OF = Register::Combo_Bit<sr_reg_type, 12, tf>;

    template<bool tf>
    using CC3OF = Register::Combo_Bit<sr_reg_type, 11, tf>;

    template<bool tf>
    using CC2OF = Register::Combo_Bit<sr_reg_type, 10, tf>;

    template<bool tf>
    using CC1OF = Register::Combo_Bit<sr_reg_type, 9, tf>;

    template<bool tf>
    using B2IF = Register::Combo_Bit<sr_reg_type, 8, tf>;

    template<bool tf>
    using BIF = Register::Combo_Bit<sr_reg_type, 7, tf>;

    template<bool tf>
    using TIF = Register::Combo_Bit<sr_reg_type, 6, tf>;

    template<bool tf>
    using COMIF = Register::Combo_Bit<sr_reg_type, 5, tf>;

    template<bool tf>
    using CC4IF = Register::Combo_Bit<sr_reg_type, 4, tf>;

    template<bool tf>
    using CC3IF = Register::Combo_Bit<sr_reg_type, 3, tf>;

    template<bool tf>
    using CC2IF = Register::Combo_Bit<sr_reg_type, 2, tf>;

    template<bool tf>
    using CC1IF = Register::Combo_Bit<sr_reg_type, 1, tf>;

    template<bool tf>
    using UIF = Register::Combo_Bit<sr_reg_type, 0, tf>;

} // TIM_SR
namespace TIM_EGR {

    enum class egr_reg_type {};

    template<bool tf>
    using B2G = Register::Combo_Bit<egr_reg_type, 8, tf>;

    template<bool tf>
    using BG = Register::Combo_Bit<egr_reg_type, 7, tf>;

    template<bool tf>
    using TG = Register::Combo_Bit<egr_reg_type, 6, tf>;

    template<bool tf>
    using COMG = Register::Combo_Bit<egr_reg_type, 5, tf>;

    template<bool tf>
    using CC4G = Register::Combo_Bit<egr_reg_type, 4, tf>;

    template<bool tf>
    using CC3G = Register::Combo_Bit<egr_reg_type, 3, tf>;

    template<bool tf>
    using CC2G = Register::Combo_Bit<egr_reg_type, 2, tf>;

    template<bool tf>
    using CC1G = Register::Combo_Bit<egr_reg_type, 1, tf>;

    template<bool tf>
    using UG = Register::Combo_Bit<egr_reg_type, 0, tf>;

} // TIM_EGR
namespace TIM_CCMR1_Output {

    enum class ccmr1_output_reg_type {};

    template<bool tf>
    using OC2M_3 = Register::Combo_Bit<ccmr1_output_reg_type, 24, tf>;

    template<bool tf>
    using OC1M_3 = Register::Combo_Bit<ccmr1_output_reg_type, 16, tf>;

    template<bool tf>
    using OC2CE = Register::Combo_Bit<ccmr1_output_reg_type, 15, tf>;

    template<CCMR1_Output_OC2M_T val>
    using OC2M = Register::Combo_Bitfield<ccmr1_output_reg_type, 12, 3, CCMR1_Output_OC2M_T, val>;

    template<bool tf>
    using OC2PE = Register::Combo_Bit<ccmr1_output_reg_type, 11, tf>;

    template<bool tf>
    using OC2FE = Register::Combo_Bit<ccmr1_output_reg_type, 10, tf>;

    template<CCMR1_Output_CC2S_T val>
    using CC2S = Register::Combo_Bitfield<ccmr1_output_reg_type, 8, 2, CCMR1_Output_CC2S_T, val>;

    template<bool tf>
    using OC1CE = Register::Combo_Bit<ccmr1_output_reg_type, 7, tf>;

    template<CCMR1_Output_OC1M_T val>
    using OC1M = Register::Combo_Bitfield<ccmr1_output_reg_type, 4, 3, CCMR1_Output_OC1M_T, val>;

    template<bool tf>
    using OC1PE = Register::Combo_Bit<ccmr1_output_reg_type, 3, tf>;

    template<bool tf>
    using OC1FE = Register::Combo_Bit<ccmr1_output_reg_type, 2, tf>;

    template<CCMR1_Output_CC1S_T val>
    using CC1S = Register::Combo_Bitfield<ccmr1_output_reg_type, 0, 2, CCMR1_Output_CC1S_T, val>;

} // TIM_CCMR1_Output
namespace TIM_CCMR1_Input {

    enum class ccmr1_input_reg_type {};

    template<CCMR1_Input_IC2F_T val>
    using IC2F = Register::Combo_Bitfield<ccmr1_input_reg_type, 12, 4, CCMR1_Input_IC2F_T, val>;

    template<CCMR1_Input_IC2PSC_T val>
    using IC2PSC = Register::Combo_Bitfield<ccmr1_input_reg_type, 10, 2, CCMR1_Input_IC2PSC_T, val>;

    template<CCMR1_Input_CC2S_T val>
    using CC2S = Register::Combo_Bitfield<ccmr1_input_reg_type, 8, 2, CCMR1_Input_CC2S_T, val>;

    template<CCMR1_Input_IC1F_T val>
    using IC1F = Register::Combo_Bitfield<ccmr1_input_reg_type, 4, 4, CCMR1_Input_IC1F_T, val>;

    template<CCMR1_Input_ICPCS_T val>
    using ICPCS = Register::Combo_Bitfield<ccmr1_input_reg_type, 2, 2, CCMR1_Input_ICPCS_T, val>;

    template<CCMR1_Input_CC1S_T val>
    using CC1S = Register::Combo_Bitfield<ccmr1_input_reg_type, 0, 2, CCMR1_Input_CC1S_T, val>;

} // TIM_CCMR1_Input
namespace TIM_CCMR2_Output {

    enum class ccmr2_output_reg_type {};

    template<bool tf>
    using OC4M_3 = Register::Combo_Bit<ccmr2_output_reg_type, 24, tf>;

    template<bool tf>
    using OC3M_3 = Register::Combo_Bit<ccmr2_output_reg_type, 16, tf>;

    template<bool tf>
    using OC4CE = Register::Combo_Bit<ccmr2_output_reg_type, 15, tf>;

    template<CCMR2_Output_OC4M_T val>
    using OC4M = Register::Combo_Bitfield<ccmr2_output_reg_type, 12, 3, CCMR2_Output_OC4M_T, val>;

    template<bool tf>
    using OC4PE = Register::Combo_Bit<ccmr2_output_reg_type, 11, tf>;

    template<bool tf>
    using OC4FE = Register::Combo_Bit<ccmr2_output_reg_type, 10, tf>;

    template<CCMR2_Output_CC4S_T val>
    using CC4S = Register::Combo_Bitfield<ccmr2_output_reg_type, 8, 2, CCMR2_Output_CC4S_T, val>;

    template<bool tf>
    using OC3CE = Register::Combo_Bit<ccmr2_output_reg_type, 7, tf>;

    template<CCMR2_Output_OC3M_T val>
    using OC3M = Register::Combo_Bitfield<ccmr2_output_reg_type, 4, 3, CCMR2_Output_OC3M_T, val>;

    template<bool tf>
    using OC3PE = Register::Combo_Bit<ccmr2_output_reg_type, 3, tf>;

    template<bool tf>
    using OC3FE = Register::Combo_Bit<ccmr2_output_reg_type, 2, tf>;

    template<CCMR2_Output_CC3S_T val>
    using CC3S = Register::Combo_Bitfield<ccmr2_output_reg_type, 0, 2, CCMR2_Output_CC3S_T, val>;

} // TIM_CCMR2_Output
namespace TIM_CCMR2_Input {

    enum class ccmr2_input_reg_type {};

    template<CCMR2_Input_IC4F_T val>
    using IC4F = Register::Combo_Bitfield<ccmr2_input_reg_type, 12, 4, CCMR2_Input_IC4F_T, val>;

    template<CCMR2_Input_IC4PSC_T val>
    using IC4PSC = Register::Combo_Bitfield<ccmr2_input_reg_type, 10, 2, CCMR2_Input_IC4PSC_T, val>;

    template<CCMR2_Input_CC4S_T val>
    using CC4S = Register::Combo_Bitfield<ccmr2_input_reg_type, 8, 2, CCMR2_Input_CC4S_T, val>;

    template<CCMR2_Input_IC3F_T val>
    using IC3F = Register::Combo_Bitfield<ccmr2_input_reg_type, 4, 4, CCMR2_Input_IC3F_T, val>;

    template<CCMR2_Input_IC3PSC_T val>
    using IC3PSC = Register::Combo_Bitfield<ccmr2_input_reg_type, 2, 2, CCMR2_Input_IC3PSC_T, val>;

    template<CCMR2_Input_CC3S_T val>
    using CC3S = Register::Combo_Bitfield<ccmr2_input_reg_type, 0, 2, CCMR2_Input_CC3S_T, val>;

} // TIM_CCMR2_Input
namespace TIM_CCER {

    enum class ccer_reg_type {};

    template<bool tf>
    using CC6P = Register::Combo_Bit<ccer_reg_type, 21, tf>;

    template<bool tf>
    using CC6E = Register::Combo_Bit<ccer_reg_type, 20, tf>;

    template<bool tf>
    using CC5P = Register::Combo_Bit<ccer_reg_type, 17, tf>;

    template<bool tf>
    using CC5E = Register::Combo_Bit<ccer_reg_type, 16, tf>;

    template<bool tf>
    using CC4NP = Register::Combo_Bit<ccer_reg_type, 15, tf>;

    template<bool tf>
    using CC4NE = Register::Combo_Bit<ccer_reg_type, 14, tf>;

    template<bool tf>
    using CC4P = Register::Combo_Bit<ccer_reg_type, 13, tf>;

    template<bool tf>
    using CC4E = Register::Combo_Bit<ccer_reg_type, 12, tf>;

    template<bool tf>
    using CC3NP = Register::Combo_Bit<ccer_reg_type, 11, tf>;

    template<bool tf>
    using CC3NE = Register::Combo_Bit<ccer_reg_type, 10, tf>;

    template<bool tf>
    using CC3P = Register::Combo_Bit<ccer_reg_type, 9, tf>;

    template<bool tf>
    using CC3E = Register::Combo_Bit<ccer_reg_type, 8, tf>;

    template<bool tf>
    using CC2NP = Register::Combo_Bit<ccer_reg_type, 7, tf>;

    template<bool tf>
    using CC2NE = Register::Combo_Bit<ccer_reg_type, 6, tf>;

    template<bool tf>
    using CC2P = Register::Combo_Bit<ccer_reg_type, 5, tf>;

    template<bool tf>
    using CC2E = Register::Combo_Bit<ccer_reg_type, 4, tf>;

    template<bool tf>
    using CC1NP = Register::Combo_Bit<ccer_reg_type, 3, tf>;

    template<bool tf>
    using CC1NE = Register::Combo_Bit<ccer_reg_type, 2, tf>;

    template<bool tf>
    using CC1P = Register::Combo_Bit<ccer_reg_type, 1, tf>;

    template<bool tf>
    using CC1E = Register::Combo_Bit<ccer_reg_type, 0, tf>;

} // TIM_CCER
namespace TIM_CNT {

    enum class cnt_reg_type {};

    template<bool tf>
    using UIFCPY = Register::Combo_Bit<cnt_reg_type, 31, tf>;

    template<CNT_CNT_T val>
    using CNT = Register::Combo_Bitfield<cnt_reg_type, 0, 16, CNT_CNT_T, val>;

} // TIM_CNT
namespace TIM_PSC {

    enum class psc_reg_type {};

    template<PSC_PSC_T val>
    using PSC = Register::Combo_Bitfield<psc_reg_type, 0, 16, PSC_PSC_T, val>;

} // TIM_PSC
namespace TIM_ARR {

    enum class arr_reg_type {};

    template<ARR_ARR_T val>
    using ARR = Register::Combo_Bitfield<arr_reg_type, 0, 16, ARR_ARR_T, val>;

} // TIM_ARR
namespace TIM_RCR {

    enum class rcr_reg_type {};

    template<RCR_REP_T val>
    using REP = Register::Combo_Bitfield<rcr_reg_type, 0, 16, RCR_REP_T, val>;

} // TIM_RCR
namespace TIM_CCR1 {

    enum class ccr1_reg_type {};

    template<CCR1_CCR1_T val>
    using CCR1 = Register::Combo_Bitfield<ccr1_reg_type, 0, 16, CCR1_CCR1_T, val>;

} // TIM_CCR1
namespace TIM_CCR2 {

    enum class ccr2_reg_type {};

    template<CCR2_CCR2_T val>
    using CCR2 = Register::Combo_Bitfield<ccr2_reg_type, 0, 16, CCR2_CCR2_T, val>;

} // TIM_CCR2
namespace TIM_CCR3 {

    enum class ccr3_reg_type {};

    template<CCR3_CCR3_T val>
    using CCR3 = Register::Combo_Bitfield<ccr3_reg_type, 0, 16, CCR3_CCR3_T, val>;

} // TIM_CCR3
namespace TIM_CCR4 {

    enum class ccr4_reg_type {};

    template<CCR4_CCR4_T val>
    using CCR4 = Register::Combo_Bitfield<ccr4_reg_type, 0, 16, CCR4_CCR4_T, val>;

} // TIM_CCR4
namespace TIM_BDTR {

    enum class bdtr_reg_type {};

    template<bool tf>
    using BK2ID = Register::Combo_Bit<bdtr_reg_type, 29, tf>;

    template<bool tf>
    using BKBID = Register::Combo_Bit<bdtr_reg_type, 28, tf>;

    template<bool tf>
    using BK2DSRM = Register::Combo_Bit<bdtr_reg_type, 27, tf>;

    template<bool tf>
    using BKDSRM = Register::Combo_Bit<bdtr_reg_type, 26, tf>;

    template<bool tf>
    using BK2P = Register::Combo_Bit<bdtr_reg_type, 25, tf>;

    template<bool tf>
    using BK2E = Register::Combo_Bit<bdtr_reg_type, 24, tf>;

    template<BDTR_BK2F_T val>
    using BK2F = Register::Combo_Bitfield<bdtr_reg_type, 20, 4, BDTR_BK2F_T, val>;

    template<BDTR_BKF_T val>
    using BKF = Register::Combo_Bitfield<bdtr_reg_type, 16, 4, BDTR_BKF_T, val>;

    template<bool tf>
    using MOE = Register::Combo_Bit<bdtr_reg_type, 15, tf>;

    template<bool tf>
    using AOE = Register::Combo_Bit<bdtr_reg_type, 14, tf>;

    template<bool tf>
    using BKP = Register::Combo_Bit<bdtr_reg_type, 13, tf>;

    template<bool tf>
    using BKE = Register::Combo_Bit<bdtr_reg_type, 12, tf>;

    template<bool tf>
    using OSSR = Register::Combo_Bit<bdtr_reg_type, 11, tf>;

    template<bool tf>
    using OSSI = Register::Combo_Bit<bdtr_reg_type, 10, tf>;

    template<BDTR_LOCK_T val>
    using LOCK = Register::Combo_Bitfield<bdtr_reg_type, 8, 2, BDTR_LOCK_T, val>;

    template<BDTR_DTG_T val>
    using DTG = Register::Combo_Bitfield<bdtr_reg_type, 0, 8, BDTR_DTG_T, val>;

} // TIM_BDTR
namespace TIM_CCR5 {

    enum class ccr5_reg_type {};

    template<CCR5_CCR5_T val>
    using CCR5 = Register::Combo_Bitfield<ccr5_reg_type, 0, 16, CCR5_CCR5_T, val>;

    template<bool tf>
    using GC5C1 = Register::Combo_Bit<ccr5_reg_type, 29, tf>;

    template<bool tf>
    using GC5C2 = Register::Combo_Bit<ccr5_reg_type, 30, tf>;

    template<bool tf>
    using GC5C3 = Register::Combo_Bit<ccr5_reg_type, 31, tf>;

} // TIM_CCR5
namespace TIM_CCR6 {

    enum class ccr6_reg_type {};

    template<CCR6_CCR6_T val>
    using CCR6 = Register::Combo_Bitfield<ccr6_reg_type, 0, 16, CCR6_CCR6_T, val>;

} // TIM_CCR6
namespace TIM_CCMR3_Output {

    enum class ccmr3_output_reg_type {};

    template<bool tf>
    using OC6M_bit3 = Register::Combo_Bit<ccmr3_output_reg_type, 24, tf>;

    template<bool tf>
    using OC5M_bit3 = Register::Combo_Bit<ccmr3_output_reg_type, 16, tf>;

    template<bool tf>
    using OC6CE = Register::Combo_Bit<ccmr3_output_reg_type, 15, tf>;

    template<CCMR3_Output_OC6M_T val>
    using OC6M = Register::Combo_Bitfield<ccmr3_output_reg_type, 12, 3, CCMR3_Output_OC6M_T, val>;

    template<bool tf>
    using OC6PE = Register::Combo_Bit<ccmr3_output_reg_type, 11, tf>;

    template<bool tf>
    using OC6FE = Register::Combo_Bit<ccmr3_output_reg_type, 10, tf>;

    template<bool tf>
    using OC5CE = Register::Combo_Bit<ccmr3_output_reg_type, 7, tf>;

    template<CCMR3_Output_OC5M_T val>
    using OC5M = Register::Combo_Bitfield<ccmr3_output_reg_type, 4, 3, CCMR3_Output_OC5M_T, val>;

    template<bool tf>
    using OC5PE = Register::Combo_Bit<ccmr3_output_reg_type, 3, tf>;

    template<bool tf>
    using OC5FE = Register::Combo_Bit<ccmr3_output_reg_type, 2, tf>;

} // TIM_CCMR3_Output
namespace TIM_DTR2 {

    enum class dtr2_reg_type {};

    template<bool tf>
    using DTPE = Register::Combo_Bit<dtr2_reg_type, 17, tf>;

    template<bool tf>
    using DTAE = Register::Combo_Bit<dtr2_reg_type, 16, tf>;

    template<DTR2_DTGF_T val>
    using DTGF = Register::Combo_Bitfield<dtr2_reg_type, 0, 8, DTR2_DTGF_T, val>;

} // TIM_DTR2
namespace TIM_ECR {

    enum class ecr_reg_type {};

    template<bool tf>
    using IE = Register::Combo_Bit<ecr_reg_type, 0, tf>;

    template<ECR_IDIR_T val>
    using IDIR = Register::Combo_Bitfield<ecr_reg_type, 1, 2, ECR_IDIR_T, val>;

    template<ECR_IBLK_T val>
    using IBLK = Register::Combo_Bitfield<ecr_reg_type, 3, 2, ECR_IBLK_T, val>;

    template<bool tf>
    using FIDX = Register::Combo_Bit<ecr_reg_type, 5, tf>;

    template<ECR_IPOS_T val>
    using IPOS = Register::Combo_Bitfield<ecr_reg_type, 6, 2, ECR_IPOS_T, val>;

    template<ECR_PW_T val>
    using PW = Register::Combo_Bitfield<ecr_reg_type, 16, 8, ECR_PW_T, val>;

    template<ECR_PWPRSC_T val>
    using PWPRSC = Register::Combo_Bitfield<ecr_reg_type, 24, 3, ECR_PWPRSC_T, val>;

} // TIM_ECR
namespace TIM_TISEL {

    enum class tisel_reg_type {};

    template<TISEL_TI1SEL_T val>
    using TI1SEL = Register::Combo_Bitfield<tisel_reg_type, 0, 4, TISEL_TI1SEL_T, val>;

    template<TISEL_TI2SEL_T val>
    using TI2SEL = Register::Combo_Bitfield<tisel_reg_type, 8, 4, TISEL_TI2SEL_T, val>;

    template<TISEL_TI3SEL_T val>
    using TI3SEL = Register::Combo_Bitfield<tisel_reg_type, 16, 4, TISEL_TI3SEL_T, val>;

    template<TISEL_TI4SEL_T val>
    using TI4SEL = Register::Combo_Bitfield<tisel_reg_type, 24, 4, TISEL_TI4SEL_T, val>;

} // TIM_TISEL
namespace TIM_AF1 {

    enum class af1_reg_type {};

    template<AF1_ETRSEL_T val>
    using ETRSEL = Register::Combo_Bitfield<af1_reg_type, 14, 4, AF1_ETRSEL_T, val>;

    template<bool tf>
    using BKCMP4P = Register::Combo_Bit<af1_reg_type, 13, tf>;

    template<bool tf>
    using BKCMP3P = Register::Combo_Bit<af1_reg_type, 12, tf>;

    template<bool tf>
    using BKCMP2P = Register::Combo_Bit<af1_reg_type, 11, tf>;

    template<bool tf>
    using BKCMP1P = Register::Combo_Bit<af1_reg_type, 10, tf>;

    template<bool tf>
    using BKINP = Register::Combo_Bit<af1_reg_type, 9, tf>;

    template<bool tf>
    using BKCMP7E = Register::Combo_Bit<af1_reg_type, 7, tf>;

    template<bool tf>
    using BKCMP6E = Register::Combo_Bit<af1_reg_type, 6, tf>;

    template<bool tf>
    using BKCMP5E = Register::Combo_Bit<af1_reg_type, 5, tf>;

    template<bool tf>
    using BKCMP4E = Register::Combo_Bit<af1_reg_type, 4, tf>;

    template<bool tf>
    using BKCMP3E = Register::Combo_Bit<af1_reg_type, 3, tf>;

    template<bool tf>
    using BKCMP2E = Register::Combo_Bit<af1_reg_type, 2, tf>;

    template<bool tf>
    using BKCMP1E = Register::Combo_Bit<af1_reg_type, 1, tf>;

    template<bool tf>
    using BKINE = Register::Combo_Bit<af1_reg_type, 0, tf>;

} // TIM_AF1
namespace TIM_AF2 {

    enum class af2_reg_type {};

    template<AF2_OCRSEL_T val>
    using OCRSEL = Register::Combo_Bitfield<af2_reg_type, 16, 3, AF2_OCRSEL_T, val>;

    template<bool tf>
    using BK2CMP4P = Register::Combo_Bit<af2_reg_type, 13, tf>;

    template<bool tf>
    using BK2CMP3P = Register::Combo_Bit<af2_reg_type, 12, tf>;

    template<bool tf>
    using BK2CMP2P = Register::Combo_Bit<af2_reg_type, 11, tf>;

    template<bool tf>
    using BK2CMP1P = Register::Combo_Bit<af2_reg_type, 10, tf>;

    template<bool tf>
    using BK2INP = Register::Combo_Bit<af2_reg_type, 9, tf>;

    template<bool tf>
    using BK2CMP7E = Register::Combo_Bit<af2_reg_type, 7, tf>;

    template<bool tf>
    using BK2CMP6E = Register::Combo_Bit<af2_reg_type, 6, tf>;

    template<bool tf>
    using BK2CMP5E = Register::Combo_Bit<af2_reg_type, 5, tf>;

    template<bool tf>
    using BK2CMP4E = Register::Combo_Bit<af2_reg_type, 4, tf>;

    template<bool tf>
    using BK2CMP3E = Register::Combo_Bit<af2_reg_type, 3, tf>;

    template<bool tf>
    using BK2CMP2E = Register::Combo_Bit<af2_reg_type, 2, tf>;

    template<bool tf>
    using BK2CMP1E = Register::Combo_Bit<af2_reg_type, 1, tf>;

    template<bool tf>
    using BKINE = Register::Combo_Bit<af2_reg_type, 0, tf>;

} // TIM_AF2
namespace TIM_DCR {

    enum class dcr_reg_type {};

    template<DCR_DBL_T val>
    using DBL = Register::Combo_Bitfield<dcr_reg_type, 8, 5, DCR_DBL_T, val>;

    template<DCR_DBA_T val>
    using DBA = Register::Combo_Bitfield<dcr_reg_type, 0, 5, DCR_DBA_T, val>;

} // TIM_DCR
namespace TIM_DMAR {

    enum class dmar_reg_type {};

    template<DMAR_DMAB_T val>
    using DMAB = Register::Combo_Bitfield<dmar_reg_type, 0, 32, DMAR_DMAB_T, val>;

} // TIM_DMAR
template<uint32_t BASE_ADDRESS>
class TIM {
public:
    static const uint32_t CR1_Offset = 0x0000;
    static const uint32_t CR2_Offset = 0x0004;
    static const uint32_t SMCR_Offset = 0x0008;
    static const uint32_t DIER_Offset = 0x000C;
    static const uint32_t SR_Offset = 0x0010;
    static const uint32_t EGR_Offset = 0x0014;
    static const uint32_t CCMR1_Output_Offset = 0x0018;
    static const uint32_t CCMR1_Input_Offset = 0x0018;
    static const uint32_t CCMR2_Output_Offset = 0x001C;
    static const uint32_t CCMR2_Input_Offset = 0x001C;
    static const uint32_t CCER_Offset = 0x0020;
    static const uint32_t CNT_Offset = 0x0024;
    static const uint32_t PSC_Offset = 0x0028;
    static const uint32_t ARR_Offset = 0x002C;
    static const uint32_t RCR_Offset = 0x0030;
    static const uint32_t CCR1_Offset = 0x0034;
    static const uint32_t CCR2_Offset = 0x0038;
    static const uint32_t CCR3_Offset = 0x003C;
    static const uint32_t CCR4_Offset = 0x0040;
    static const uint32_t BDTR_Offset = 0x0044;
    static const uint32_t CCR5_Offset = 0x0048;
    static const uint32_t CCR6_Offset = 0x004C;
    static const uint32_t CCMR3_Output_Offset = 0x0050;
    static const uint32_t DTR2_Offset = 0x0054;
    static const uint32_t ECR_Offset = 0x0058;
    static const uint32_t TISEL_Offset = 0x005C;
    static const uint32_t AF1_Offset = 0x0060;
    static const uint32_t AF2_Offset = 0x0064;
    static const uint32_t DCR_Offset = 0x03DC;
    static const uint32_t DMAR_Offset = 0x03E0;

    TIM() = default;
    TIM( const TIM& ) = delete;
    const TIM& operator=( const TIM& ) = delete;

    class CR1_T : public Register::Register<TIM_CR1::cr1_reg_type, BASE_ADDRESS + CR1_Offset> {
    // control register 1
    public:
        Register::Bit<BASE_ADDRESS + CR1_Offset, 12> DITHEN; /* Dithering Enable */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 11> UIFREMAP; /* UIF status bit remapping */
        Register::Bitfield<BASE_ADDRESS + CR1_Offset, 8, 2, CR1_CKD_T> CKD; /* Clock division */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 7> ARPE; /* Auto-reload preload enable */
        Register::Bitfield<BASE_ADDRESS + CR1_Offset, 5, 2, CR1_CMS_T> CMS; /* Center-aligned mode selection */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 4> DIR; /* Direction */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 3> OPM; /* One-pulse mode */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 2> URS; /* Update request source */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 1> UDIS; /* Update disable */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 0> CEN; /* Counter enable */
    };

    class CR2_T : public Register::Register<TIM_CR2::cr2_reg_type, BASE_ADDRESS + CR2_Offset> {
    // control register 2
    public:
        Register::Bit<BASE_ADDRESS + CR2_Offset, 25> MMS_3; /* Master mode selection - bit 3 */
        Register::Bitfield<BASE_ADDRESS + CR2_Offset, 20, 4, CR2_MMS2_T> MMS2; /* Master mode selection 2 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 18> OIS6; /* Output Idle state 6 (OC6 output) */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 16> OIS5; /* Output Idle state 5 (OC5 output) */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 15> OIS4N; /* Output Idle state 4 (OC4N output) */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 14> OIS4; /* Output Idle state 4 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 13> OIS3N; /* Output Idle state 3 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 12> OIS3; /* Output Idle state 3 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 11> OIS2N; /* Output Idle state 2 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 10> OIS2; /* Output Idle state 2 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 9> OIS1N; /* Output Idle state 1 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 8> OIS1; /* Output Idle state 1 */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 7> TI1S; /* TI1 selection */
        Register::Bitfield<BASE_ADDRESS + CR2_Offset, 4, 3, CR2_MMS_T> MMS; /* Master mode selection */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 3> CCDS; /* Capture/compare DMA selection */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 2> CCUS; /* Capture/compare control update selection */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 0> CCPC; /* Capture/compare preloaded control */
    };

    class SMCR_T : public Register::Register<TIM_SMCR::smcr_reg_type, BASE_ADDRESS + SMCR_Offset> {
    // slave mode control register
    public:
        Register::Bit<BASE_ADDRESS + SMCR_Offset, 25> SMSPS; /* SMS Preload Source */
        Register::Bit<BASE_ADDRESS + SMCR_Offset, 24> SMSPE; /* SMS Preload Enable */
        Register::Bitfield<BASE_ADDRESS + SMCR_Offset, 20, 2, SMCR_TS_4_3_T> TS_4_3; /* Trigger selection - bit 4:3 */
        Register::Bit<BASE_ADDRESS + SMCR_Offset, 16> SMS_3; /* Slave mode selection - bit 3 */
        Register::Bit<BASE_ADDRESS + SMCR_Offset, 15> ETP; /* External trigger polarity */
        Register::Bit<BASE_ADDRESS + SMCR_Offset, 14> ECE; /* External clock enable */
        Register::Bitfield<BASE_ADDRESS + SMCR_Offset, 12, 2, SMCR_ETPS_T> ETPS; /* External trigger prescaler */
        Register::Bitfield<BASE_ADDRESS + SMCR_Offset, 8, 4, SMCR_ETF_T> ETF; /* External trigger filter */
        Register::Bit<BASE_ADDRESS + SMCR_Offset, 7> MSM; /* Master/Slave mode */
        Register::Bitfield<BASE_ADDRESS + SMCR_Offset, 4, 3, SMCR_TS_T> TS; /* Trigger selection */
        Register::Bit<BASE_ADDRESS + SMCR_Offset, 3> OCCS; /* OCREF clear selection */
        Register::Bitfield<BASE_ADDRESS + SMCR_Offset, 0, 3, SMCR_SMS_T> SMS; /* Slave mode selection */
    };

    class DIER_T : public Register::Register<TIM_DIER::dier_reg_type, BASE_ADDRESS + DIER_Offset> {
    // DMA/Interrupt enable register
    public:
        Register::Bit<BASE_ADDRESS + DIER_Offset, 23> TERRIE; /* Transition Error interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 22> IERRIE; /* Index Error interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 21> DIRIE; /* Direction Change interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 20> IDXIE; /* Index interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 14> TDE; /* Trigger DMA request enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 13> COMDE; /* COM DMA request enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 12> CC4DE; /* Capture/Compare 4 DMA request enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 11> CC3DE; /* Capture/Compare 3 DMA request enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 10> CC2DE; /* Capture/Compare 2 DMA request enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 9> CC1DE; /* Capture/Compare 1 DMA request enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 8> UDE; /* Update DMA request enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 6> TIE; /* Trigger interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 4> CC4IE; /* Capture/Compare 4 interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 3> CC3IE; /* Capture/Compare 3 interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 2> CC2IE; /* Capture/Compare 2 interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 1> CC1IE; /* Capture/Compare 1 interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 0> UIE; /* Update interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 7> BIE; /* Break interrupt enable */
        Register::Bit<BASE_ADDRESS + DIER_Offset, 5> COMIE; /* COM interrupt enable */
    };

    class SR_T : public Register::Register<TIM_SR::sr_reg_type, BASE_ADDRESS + SR_Offset> {
    // status register
    public:
        Register::Bit<BASE_ADDRESS + SR_Offset, 23> TERRF; /* Transition Error interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 22> IERRF; /* Index Error interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 21> DIRF; /* Direction Change interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 20> IDXF; /* Index interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 17> CC6IF; /* Compare 6 interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 16> CC5IF; /* Compare 5 interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 13> SBIF; /* System Break interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 12> CC4OF; /* Capture/Compare 4 overcapture flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 11> CC3OF; /* Capture/Compare 3 overcapture flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 10> CC2OF; /* Capture/compare 2 overcapture flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 9> CC1OF; /* Capture/Compare 1 overcapture flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 8> B2IF; /* Break 2 interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 7> BIF; /* Break interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 6> TIF; /* Trigger interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 5> COMIF; /* COM interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 4> CC4IF; /* Capture/Compare 4 interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 3> CC3IF; /* Capture/Compare 3 interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 2> CC2IF; /* Capture/Compare 2 interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 1> CC1IF; /* Capture/compare 1 interrupt flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 0> UIF; /* Update interrupt flag */
    };

    class EGR_T : public Register::Register<TIM_EGR::egr_reg_type, BASE_ADDRESS + EGR_Offset> {
    // event generation register
    public:
        Register::Bit<BASE_ADDRESS + EGR_Offset, 8> B2G; /* Break 2 generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 7> BG; /* Break generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 6> TG; /* Trigger generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 5> COMG; /* Capture/Compare control update generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 4> CC4G; /* Capture/compare 4 generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 3> CC3G; /* Capture/compare 3 generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 2> CC2G; /* Capture/compare 2 generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 1> CC1G; /* Capture/compare 1 generation */
        Register::Bit<BASE_ADDRESS + EGR_Offset, 0> UG; /* Update generation */
    };

    class CCMR1_Output_T : public Register::Register<TIM_CCMR1_Output::ccmr1_output_reg_type, BASE_ADDRESS + CCMR1_Output_Offset> {
    // capture/compare mode register 1 (output mode)
    public:
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 24> OC2M_3; /* Output Compare 2 mode - bit 3 */
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 16> OC1M_3; /* Output Compare 1 mode - bit 3 */
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 15> OC2CE; /* Output Compare 2 clear enable */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Output_Offset, 12, 3, CCMR1_Output_OC2M_T> OC2M; /* Output Compare 2 mode */
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 11> OC2PE; /* Output Compare 2 preload enable */
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 10> OC2FE; /* Output Compare 2 fast enable */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Output_Offset, 8, 2, CCMR1_Output_CC2S_T> CC2S; /* Capture/Compare 2 selection */
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 7> OC1CE; /* Output Compare 1 clear enable */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Output_Offset, 4, 3, CCMR1_Output_OC1M_T> OC1M; /* Output Compare 1 mode */
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 3> OC1PE; /* Output Compare 1 preload enable */
        Register::Bit<BASE_ADDRESS + CCMR1_Output_Offset, 2> OC1FE; /* Output Compare 1 fast enable */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Output_Offset, 0, 2, CCMR1_Output_CC1S_T> CC1S; /* Capture/Compare 1 selection */
    };

    class CCMR1_Input_T : public Register::Register<TIM_CCMR1_Input::ccmr1_input_reg_type, BASE_ADDRESS + CCMR1_Input_Offset> {
    // capture/compare mode register 1 (input mode)
    public:
        Register::Bitfield<BASE_ADDRESS + CCMR1_Input_Offset, 12, 4, CCMR1_Input_IC2F_T> IC2F; /* Input capture 2 filter */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Input_Offset, 10, 2, CCMR1_Input_IC2PSC_T> IC2PSC; /* Input capture 2 prescaler */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Input_Offset, 8, 2, CCMR1_Input_CC2S_T> CC2S; /* Capture/Compare 2 selection */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Input_Offset, 4, 4, CCMR1_Input_IC1F_T> IC1F; /* Input capture 1 filter */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Input_Offset, 2, 2, CCMR1_Input_ICPCS_T> ICPCS; /* Input capture 1 prescaler */
        Register::Bitfield<BASE_ADDRESS + CCMR1_Input_Offset, 0, 2, CCMR1_Input_CC1S_T> CC1S; /* Capture/Compare 1 selection */
    };

    class CCMR2_Output_T : public Register::Register<TIM_CCMR2_Output::ccmr2_output_reg_type, BASE_ADDRESS + CCMR2_Output_Offset> {
    // capture/compare mode register 2 (output mode)
    public:
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 24> OC4M_3; /* Output Compare 4 mode - bit 3 */
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 16> OC3M_3; /* Output Compare 3 mode - bit 3 */
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 15> OC4CE; /* Output compare 4 clear enable */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Output_Offset, 12, 3, CCMR2_Output_OC4M_T> OC4M; /* Output compare 4 mode */
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 11> OC4PE; /* Output compare 4 preload enable */
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 10> OC4FE; /* Output compare 4 fast enable */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Output_Offset, 8, 2, CCMR2_Output_CC4S_T> CC4S; /* Capture/Compare 4 selection */
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 7> OC3CE; /* Output compare 3 clear enable */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Output_Offset, 4, 3, CCMR2_Output_OC3M_T> OC3M; /* Output compare 3 mode */
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 3> OC3PE; /* Output compare 3 preload enable */
        Register::Bit<BASE_ADDRESS + CCMR2_Output_Offset, 2> OC3FE; /* Output compare 3 fast enable */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Output_Offset, 0, 2, CCMR2_Output_CC3S_T> CC3S; /* Capture/Compare 3 selection */
    };

    class CCMR2_Input_T : public Register::Register<TIM_CCMR2_Input::ccmr2_input_reg_type, BASE_ADDRESS + CCMR2_Input_Offset> {
    // capture/compare mode register 2 (input mode)
    public:
        Register::Bitfield<BASE_ADDRESS + CCMR2_Input_Offset, 12, 4, CCMR2_Input_IC4F_T> IC4F; /* Input capture 4 filter */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Input_Offset, 10, 2, CCMR2_Input_IC4PSC_T> IC4PSC; /* Input capture 4 prescaler */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Input_Offset, 8, 2, CCMR2_Input_CC4S_T> CC4S; /* Capture/Compare 4 selection */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Input_Offset, 4, 4, CCMR2_Input_IC3F_T> IC3F; /* Input capture 3 filter */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Input_Offset, 2, 2, CCMR2_Input_IC3PSC_T> IC3PSC; /* Input capture 3 prescaler */
        Register::Bitfield<BASE_ADDRESS + CCMR2_Input_Offset, 0, 2, CCMR2_Input_CC3S_T> CC3S; /* Capture/compare 3 selection */
    };

    class CCER_T : public Register::Register<TIM_CCER::ccer_reg_type, BASE_ADDRESS + CCER_Offset> {
    // capture/compare enable register
    public:
        Register::Bit<BASE_ADDRESS + CCER_Offset, 21> CC6P; /* Capture/Compare 6 output polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 20> CC6E; /* Capture/Compare 6 output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 17> CC5P; /* Capture/Compare 5 output polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 16> CC5E; /* Capture/Compare 5 output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 15> CC4NP; /* Capture/Compare 4 complementary output polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 14> CC4NE; /* Capture/Compare 4 complementary output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 13> CC4P; /* Capture/Compare 3 output Polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 12> CC4E; /* Capture/Compare 4 output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 11> CC3NP; /* Capture/Compare 3 output Polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 10> CC3NE; /* Capture/Compare 3 complementary output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 9> CC3P; /* Capture/Compare 3 output Polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 8> CC3E; /* Capture/Compare 3 output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 7> CC2NP; /* Capture/Compare 2 output Polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 6> CC2NE; /* Capture/Compare 2 complementary output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 5> CC2P; /* Capture/Compare 2 output Polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 4> CC2E; /* Capture/Compare 2 output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 3> CC1NP; /* Capture/Compare 1 output Polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 2> CC1NE; /* Capture/Compare 1 complementary output enable */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 1> CC1P; /* Capture/Compare 1 output Polarity */
        Register::Bit<BASE_ADDRESS + CCER_Offset, 0> CC1E; /* Capture/Compare 1 output enable */
    };

    class CNT_T : public Register::Register<TIM_CNT::cnt_reg_type, BASE_ADDRESS + CNT_Offset> {
    // counter
    public:
        Register::Bit<BASE_ADDRESS + CNT_Offset, 31> UIFCPY; /* UIFCPY */
        Register::Bitfield<BASE_ADDRESS + CNT_Offset, 0, 16, CNT_CNT_T> CNT; /* counter value */
    };

    class PSC_T : public Register::Register<TIM_PSC::psc_reg_type, BASE_ADDRESS + PSC_Offset> {
    // prescaler
    public:
        Register::Bitfield<BASE_ADDRESS + PSC_Offset, 0, 16, PSC_PSC_T> PSC; /* Prescaler value */
    };

    class ARR_T : public Register::Register<TIM_ARR::arr_reg_type, BASE_ADDRESS + ARR_Offset> {
    // auto-reload register
    public:
        Register::Bitfield<BASE_ADDRESS + ARR_Offset, 0, 16, ARR_ARR_T> ARR; /* Auto-reload value */
    };

    class RCR_T : public Register::Register<TIM_RCR::rcr_reg_type, BASE_ADDRESS + RCR_Offset> {
    // repetition counter register
    public:
        Register::Bitfield<BASE_ADDRESS + RCR_Offset, 0, 16, RCR_REP_T> REP; /* Repetition counter value */
    };

    class CCR1_T : public Register::Register<TIM_CCR1::ccr1_reg_type, BASE_ADDRESS + CCR1_Offset> {
    // capture/compare register 1
    public:
        Register::Bitfield<BASE_ADDRESS + CCR1_Offset, 0, 16, CCR1_CCR1_T> CCR1; /* Capture/Compare 1 value */
    };

    class CCR2_T : public Register::Register<TIM_CCR2::ccr2_reg_type, BASE_ADDRESS + CCR2_Offset> {
    // capture/compare register 2
    public:
        Register::Bitfield<BASE_ADDRESS + CCR2_Offset, 0, 16, CCR2_CCR2_T> CCR2; /* Capture/Compare 2 value */
    };

    class CCR3_T : public Register::Register<TIM_CCR3::ccr3_reg_type, BASE_ADDRESS + CCR3_Offset> {
    // capture/compare register 3
    public:
        Register::Bitfield<BASE_ADDRESS + CCR3_Offset, 0, 16, CCR3_CCR3_T> CCR3; /* Capture/Compare value */
    };

    class CCR4_T : public Register::Register<TIM_CCR4::ccr4_reg_type, BASE_ADDRESS + CCR4_Offset> {
    // capture/compare register 4
    public:
        Register::Bitfield<BASE_ADDRESS + CCR4_Offset, 0, 16, CCR4_CCR4_T> CCR4; /* Capture/Compare value */
    };

    class BDTR_T : public Register::Register<TIM_BDTR::bdtr_reg_type, BASE_ADDRESS + BDTR_Offset> {
    // break and dead-time register
    public:
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 29> BK2ID; /* BK2ID */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 28> BKBID; /* BKBID */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 27> BK2DSRM; /* BK2DSRM */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 26> BKDSRM; /* BKDSRM */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 25> BK2P; /* Break 2 polarity */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 24> BK2E; /* Break 2 Enable */
        Register::Bitfield<BASE_ADDRESS + BDTR_Offset, 20, 4, BDTR_BK2F_T> BK2F; /* Break 2 filter */
        Register::Bitfield<BASE_ADDRESS + BDTR_Offset, 16, 4, BDTR_BKF_T> BKF; /* Break filter */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 15> MOE; /* Main output enable */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 14> AOE; /* Automatic output enable */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 13> BKP; /* Break polarity */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 12> BKE; /* Break enable */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 11> OSSR; /* Off-state selection for Run mode */
        Register::Bit<BASE_ADDRESS + BDTR_Offset, 10> OSSI; /* Off-state selection for Idle mode */
        Register::Bitfield<BASE_ADDRESS + BDTR_Offset, 8, 2, BDTR_LOCK_T> LOCK; /* Lock configuration */
        Register::Bitfield<BASE_ADDRESS + BDTR_Offset, 0, 8, BDTR_DTG_T> DTG; /* Dead-time generator setup */
    };

    class CCR5_T : public Register::Register<TIM_CCR5::ccr5_reg_type, BASE_ADDRESS + CCR5_Offset> {
    // capture/compare register 4
    public:
        Register::Bitfield<BASE_ADDRESS + CCR5_Offset, 0, 16, CCR5_CCR5_T> CCR5; /* Capture/Compare value */
        Register::Bit<BASE_ADDRESS + CCR5_Offset, 29> GC5C1; /* Group Channel 5 and Channel 1 */
        Register::Bit<BASE_ADDRESS + CCR5_Offset, 30> GC5C2; /* Group Channel 5 and Channel 2 */
        Register::Bit<BASE_ADDRESS + CCR5_Offset, 31> GC5C3; /* Group Channel 5 and Channel 3 */
    };

    class CCR6_T : public Register::Register<TIM_CCR6::ccr6_reg_type, BASE_ADDRESS + CCR6_Offset> {
    // capture/compare register 4
    public:
        Register::Bitfield<BASE_ADDRESS + CCR6_Offset, 0, 16, CCR6_CCR6_T> CCR6; /* Capture/Compare value */
    };

    class CCMR3_Output_T : public Register::Register<TIM_CCMR3_Output::ccmr3_output_reg_type, BASE_ADDRESS + CCMR3_Output_Offset> {
    // capture/compare mode register 2 (output mode)
    public:
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 24> OC6M_bit3; /* Output Compare 6 mode bit 3 */
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 16> OC5M_bit3; /* Output Compare 5 mode bit 3 */
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 15> OC6CE; /* Output compare 6 clear enable */
        Register::Bitfield<BASE_ADDRESS + CCMR3_Output_Offset, 12, 3, CCMR3_Output_OC6M_T> OC6M; /* Output compare 6 mode */
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 11> OC6PE; /* Output compare 6 preload enable */
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 10> OC6FE; /* Output compare 6 fast enable */
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 7> OC5CE; /* Output compare 5 clear enable */
        Register::Bitfield<BASE_ADDRESS + CCMR3_Output_Offset, 4, 3, CCMR3_Output_OC5M_T> OC5M; /* Output compare 5 mode */
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 3> OC5PE; /* Output compare 5 preload enable */
        Register::Bit<BASE_ADDRESS + CCMR3_Output_Offset, 2> OC5FE; /* Output compare 5 fast enable */
    };

    class DTR2_T : public Register::Register<TIM_DTR2::dtr2_reg_type, BASE_ADDRESS + DTR2_Offset> {
    // timer Deadtime Register 2
    public:
        Register::Bit<BASE_ADDRESS + DTR2_Offset, 17> DTPE; /* Deadtime Preload Enable */
        Register::Bit<BASE_ADDRESS + DTR2_Offset, 16> DTAE; /* Deadtime Asymmetric Enable */
        Register::Bitfield<BASE_ADDRESS + DTR2_Offset, 0, 8, DTR2_DTGF_T> DTGF; /* Dead-time falling edge generator setup */
    };

    class ECR_T : public Register::Register<TIM_ECR::ecr_reg_type, BASE_ADDRESS + ECR_Offset> {
    // DMA control register
    public:
        Register::Bit<BASE_ADDRESS + ECR_Offset, 0> IE; /* Index Enable */
        Register::Bitfield<BASE_ADDRESS + ECR_Offset, 1, 2, ECR_IDIR_T> IDIR; /* Index Direction */
        Register::Bitfield<BASE_ADDRESS + ECR_Offset, 3, 2, ECR_IBLK_T> IBLK; /* Index Blanking */
        Register::Bit<BASE_ADDRESS + ECR_Offset, 5> FIDX; /* First Index */
        Register::Bitfield<BASE_ADDRESS + ECR_Offset, 6, 2, ECR_IPOS_T> IPOS; /* Index Positioning */
        Register::Bitfield<BASE_ADDRESS + ECR_Offset, 16, 8, ECR_PW_T> PW; /* Pulse width */
        Register::Bitfield<BASE_ADDRESS + ECR_Offset, 24, 3, ECR_PWPRSC_T> PWPRSC; /* Pulse Width prescaler */
    };

    class TISEL_T : public Register::Register<TIM_TISEL::tisel_reg_type, BASE_ADDRESS + TISEL_Offset> {
    // TIM timer input selection register
    public:
        Register::Bitfield<BASE_ADDRESS + TISEL_Offset, 0, 4, TISEL_TI1SEL_T> TI1SEL; /* TI1[0] to TI1[15] input selection */
        Register::Bitfield<BASE_ADDRESS + TISEL_Offset, 8, 4, TISEL_TI2SEL_T> TI2SEL; /* TI2[0] to TI2[15] input selection */
        Register::Bitfield<BASE_ADDRESS + TISEL_Offset, 16, 4, TISEL_TI3SEL_T> TI3SEL; /* TI3[0] to TI3[15] input selection */
        Register::Bitfield<BASE_ADDRESS + TISEL_Offset, 24, 4, TISEL_TI4SEL_T> TI4SEL; /* TI4[0] to TI4[15] input selection */
    };

    class AF1_T : public Register::Register<TIM_AF1::af1_reg_type, BASE_ADDRESS + AF1_Offset> {
    // TIM alternate function option register 1
    public:
        Register::Bitfield<BASE_ADDRESS + AF1_Offset, 14, 4, AF1_ETRSEL_T> ETRSEL; /* ETR source selection */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 13> BKCMP4P; /* BRK COMP4 input polarity */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 12> BKCMP3P; /* BRK COMP3 input polarity */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 11> BKCMP2P; /* BRK COMP2 input polarity */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 10> BKCMP1P; /* BRK COMP1 input polarity */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 9> BKINP; /* BRK BKIN input polarity */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 7> BKCMP7E; /* BRK COMP7 enable */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 6> BKCMP6E; /* BRK COMP6 enable */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 5> BKCMP5E; /* BRK COMP5 enable */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 4> BKCMP4E; /* BRK COMP4 enable */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 3> BKCMP3E; /* BRK COMP3 enable */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 2> BKCMP2E; /* BRK COMP2 enable */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 1> BKCMP1E; /* BRK COMP1 enable */
        Register::Bit<BASE_ADDRESS + AF1_Offset, 0> BKINE; /* BRK BKIN input enable */
    };

    class AF2_T : public Register::Register<TIM_AF2::af2_reg_type, BASE_ADDRESS + AF2_Offset> {
    // TIM alternate function option register 2
    public:
        Register::Bitfield<BASE_ADDRESS + AF2_Offset, 16, 3, AF2_OCRSEL_T> OCRSEL; /* OCREF_CLR source selection */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 13> BK2CMP4P; /* BRK2 COMP4 input polarity */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 12> BK2CMP3P; /* BRK2 COMP3 input polarity */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 11> BK2CMP2P; /* BRK2 COMP2 input polarity */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 10> BK2CMP1P; /* BRK2 COMP1 input polarity */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 9> BK2INP; /* BRK2 BKIN input polarity */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 7> BK2CMP7E; /* BRK2 COMP7 enable */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 6> BK2CMP6E; /* BRK2 COMP6 enable */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 5> BK2CMP5E; /* BRK2 COMP5 enable */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 4> BK2CMP4E; /* BRK2 COMP4 enable */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 3> BK2CMP3E; /* BRK2 COMP3 enable */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 2> BK2CMP2E; /* BRK2 COMP2 enable */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 1> BK2CMP1E; /* BRK2 COMP1 enable */
        Register::Bit<BASE_ADDRESS + AF2_Offset, 0> BKINE; /* BRK BKIN input enable */
    };

    class DCR_T : public Register::Register<TIM_DCR::dcr_reg_type, BASE_ADDRESS + DCR_Offset> {
    // control register
    public:
        Register::Bitfield<BASE_ADDRESS + DCR_Offset, 8, 5, DCR_DBL_T> DBL; /* DMA burst length */
        Register::Bitfield<BASE_ADDRESS + DCR_Offset, 0, 5, DCR_DBA_T> DBA; /* DMA base address */
    };

    class DMAR_T : public Register::Register<TIM_DMAR::dmar_reg_type, BASE_ADDRESS + DMAR_Offset> {
    // DMA address for full transfer
    public:
        Register::Bitfield<BASE_ADDRESS + DMAR_Offset, 0, 32, DMAR_DMAB_T> DMAB; /* DMA register for burst accesses */
    };

    CR1_T CR1;
    CR2_T CR2;
    SMCR_T SMCR;
    DIER_T DIER;
    SR_T SR;
    EGR_T EGR;
    CCMR1_Output_T CCMR1_Output;
    CCMR1_Input_T CCMR1_Input;
    CCMR2_Output_T CCMR2_Output;
    CCMR2_Input_T CCMR2_Input;
    CCER_T CCER;
    CNT_T CNT;
    PSC_T PSC;
    ARR_T ARR;
    RCR_T RCR;
    CCR1_T CCR1;
    CCR2_T CCR2;
    CCR3_T CCR3;
    CCR4_T CCR4;
    BDTR_T BDTR;
    CCR5_T CCR5;
    CCR6_T CCR6;
    CCMR3_Output_T CCMR3_Output;
    DTR2_T DTR2;
    ECR_T ECR;
    TISEL_T TISEL;
    AF1_T AF1;
    AF2_T AF2;
    DCR_T DCR;
    DMAR_T DMAR;
};

} // namespace STM32LIB

#endif // STM32G473XX_TIM_HPP_

