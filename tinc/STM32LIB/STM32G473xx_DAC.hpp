#ifndef STM32G473XX_DAC_HPP_
#define STM32G473XX_DAC_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"
#include "DAC_Types.hpp"

/* Digital-to-analog converter */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using CR_TSEL1_T = uint32_t;
using CR_WAVE1_T = DAC_Wave_Select;
using CR_MAMP1_T = uint32_t;
using CR_TSEL2_T = uint32_t;
using CR_WAVE2_T = DAC_Wave_Select;
using CR_MAMP2_T = uint32_t;
using DHR12R1_DACC1DHR_T = uint32_t;
using DHR12R1_DACC1DHRB_T = uint32_t;
using DHR12L1_DACC1DHR_T = uint32_t;
using DHR12L1_DACC1DHRB_T = uint32_t;
using DHR8R1_DACC1DHR_T = uint32_t;
using DHR8R1_DACC1DHRB_T = uint32_t;
using DHR12R2_DACC2DHR_T = uint32_t;
using DHR12R2_DACC2DHRB_T = uint32_t;
using DHR12L2_DACC2DHR_T = uint32_t;
using DHR12L2_DACC2DHRB_T = uint32_t;
using DHR8R2_DACC2DHR_T = uint32_t;
using DHR8R2_DACC2DHRB_T = uint32_t;
using DHR12RD_DACC1DHR_T = uint32_t;
using DHR12RD_DACC2DHR_T = uint32_t;
using DHR12LD_DACC1DHR_T = uint32_t;
using DHR12LD_DACC2DHR_T = uint32_t;
using DHR8RD_DACC1DHR_T = uint32_t;
using DHR8RD_DACC2DHR_T = uint32_t;
using DOR1_DACC1DOR_T = uint32_t;
using DOR1_DACC1DORB_T = uint32_t;
using DOR2_DACC2DOR_T = uint32_t;
using DOR2_DACC2DORB_T = uint32_t;
using CCR_OTRIM1_T = uint32_t;
using CCR_OTRIM2_T = uint32_t;
using MCR_MODE1_T = DAC_Mode;
using MCR_HFSEL_T = DAC_High_Frequency_Mode;
using MCR_MODE2_T = DAC_Mode;
using SHSR1_TSAMPLE1_T = uint32_t;
using SHSR2_TSAMPLE2_T = uint32_t;
using SHHR_THOLD1_T = uint32_t;
using SHHR_THOLD2_T = uint32_t;
using SHRR_TREFRESH1_T = uint32_t;
using SHRR_TREFRESH2_T = uint32_t;
using STR1_STRSTDATA1_T = uint32_t;
using STR1_STINCDATA1_T = uint32_t;
using STR2_STRSTDATA2_T = uint32_t;
using STR2_STINCDATA2_T = uint32_t;
using STMODR_STRSTTRIGSEL1_T = uint32_t;
using STMODR_STINCTRIGSEL1_T = uint32_t;
using STMODR_STRSTTRIGSEL2_T = uint32_t;
using STMODR_STINCTRIGSEL2_T = uint32_t;

namespace DAC_CR {

    enum class cr_reg_type {};

    template<bool tf>
    using EN1 = Register::Combo_Bit<cr_reg_type, 0, tf>;

    template<bool tf>
    using TEN1 = Register::Combo_Bit<cr_reg_type, 1, tf>;

    template<CR_TSEL1_T val>
    using TSEL1 = Register::Combo_Bitfield<cr_reg_type, 2, 4, CR_TSEL1_T, val>;

    template<CR_WAVE1_T val>
    using WAVE1 = Register::Combo_Bitfield<cr_reg_type, 6, 2, CR_WAVE1_T, val>;

    template<CR_MAMP1_T val>
    using MAMP1 = Register::Combo_Bitfield<cr_reg_type, 8, 4, CR_MAMP1_T, val>;

    template<bool tf>
    using DMAEN1 = Register::Combo_Bit<cr_reg_type, 12, tf>;

    template<bool tf>
    using DMAUDRIE1 = Register::Combo_Bit<cr_reg_type, 13, tf>;

    template<bool tf>
    using CEN1 = Register::Combo_Bit<cr_reg_type, 14, tf>;

    template<bool tf>
    using EN2 = Register::Combo_Bit<cr_reg_type, 16, tf>;

    template<bool tf>
    using TEN2 = Register::Combo_Bit<cr_reg_type, 17, tf>;

    template<CR_TSEL2_T val>
    using TSEL2 = Register::Combo_Bitfield<cr_reg_type, 18, 4, CR_TSEL2_T, val>;

    template<CR_WAVE2_T val>
    using WAVE2 = Register::Combo_Bitfield<cr_reg_type, 22, 2, CR_WAVE2_T, val>;

    template<CR_MAMP2_T val>
    using MAMP2 = Register::Combo_Bitfield<cr_reg_type, 24, 4, CR_MAMP2_T, val>;

    template<bool tf>
    using DMAEN2 = Register::Combo_Bit<cr_reg_type, 28, tf>;

    template<bool tf>
    using DMAUDRIE2 = Register::Combo_Bit<cr_reg_type, 29, tf>;

    template<bool tf>
    using CEN2 = Register::Combo_Bit<cr_reg_type, 30, tf>;

} // DAC_CR
namespace DAC_SWTRGR {

    enum class swtrgr_reg_type {};

    template<bool tf>
    using SWTRIG1 = Register::Combo_Bit<swtrgr_reg_type, 0, tf>;

    template<bool tf>
    using SWTRIG2 = Register::Combo_Bit<swtrgr_reg_type, 1, tf>;

    template<bool tf>
    using SWTRIGB1 = Register::Combo_Bit<swtrgr_reg_type, 16, tf>;

    template<bool tf>
    using SWTRIGB2 = Register::Combo_Bit<swtrgr_reg_type, 17, tf>;

} // DAC_SWTRGR
namespace DAC_DHR12R1 {

    enum class dhr12r1_reg_type {};

    template<DHR12R1_DACC1DHR_T val>
    using DACC1DHR = Register::Combo_Bitfield<dhr12r1_reg_type, 0, 12, DHR12R1_DACC1DHR_T, val>;

    template<DHR12R1_DACC1DHRB_T val>
    using DACC1DHRB = Register::Combo_Bitfield<dhr12r1_reg_type, 16, 12, DHR12R1_DACC1DHRB_T, val>;

} // DAC_DHR12R1
namespace DAC_DHR12L1 {

    enum class dhr12l1_reg_type {};

    template<DHR12L1_DACC1DHR_T val>
    using DACC1DHR = Register::Combo_Bitfield<dhr12l1_reg_type, 4, 12, DHR12L1_DACC1DHR_T, val>;

    template<DHR12L1_DACC1DHRB_T val>
    using DACC1DHRB = Register::Combo_Bitfield<dhr12l1_reg_type, 20, 12, DHR12L1_DACC1DHRB_T, val>;

} // DAC_DHR12L1
namespace DAC_DHR8R1 {

    enum class dhr8r1_reg_type {};

    template<DHR8R1_DACC1DHR_T val>
    using DACC1DHR = Register::Combo_Bitfield<dhr8r1_reg_type, 0, 8, DHR8R1_DACC1DHR_T, val>;

    template<DHR8R1_DACC1DHRB_T val>
    using DACC1DHRB = Register::Combo_Bitfield<dhr8r1_reg_type, 8, 8, DHR8R1_DACC1DHRB_T, val>;

} // DAC_DHR8R1
namespace DAC_DHR12R2 {

    enum class dhr12r2_reg_type {};

    template<DHR12R2_DACC2DHR_T val>
    using DACC2DHR = Register::Combo_Bitfield<dhr12r2_reg_type, 0, 12, DHR12R2_DACC2DHR_T, val>;

    template<DHR12R2_DACC2DHRB_T val>
    using DACC2DHRB = Register::Combo_Bitfield<dhr12r2_reg_type, 16, 12, DHR12R2_DACC2DHRB_T, val>;

} // DAC_DHR12R2
namespace DAC_DHR12L2 {

    enum class dhr12l2_reg_type {};

    template<DHR12L2_DACC2DHR_T val>
    using DACC2DHR = Register::Combo_Bitfield<dhr12l2_reg_type, 4, 12, DHR12L2_DACC2DHR_T, val>;

    template<DHR12L2_DACC2DHRB_T val>
    using DACC2DHRB = Register::Combo_Bitfield<dhr12l2_reg_type, 20, 12, DHR12L2_DACC2DHRB_T, val>;

} // DAC_DHR12L2
namespace DAC_DHR8R2 {

    enum class dhr8r2_reg_type {};

    template<DHR8R2_DACC2DHR_T val>
    using DACC2DHR = Register::Combo_Bitfield<dhr8r2_reg_type, 0, 8, DHR8R2_DACC2DHR_T, val>;

    template<DHR8R2_DACC2DHRB_T val>
    using DACC2DHRB = Register::Combo_Bitfield<dhr8r2_reg_type, 8, 8, DHR8R2_DACC2DHRB_T, val>;

} // DAC_DHR8R2
namespace DAC_DHR12RD {

    enum class dhr12rd_reg_type {};

    template<DHR12RD_DACC1DHR_T val>
    using DACC1DHR = Register::Combo_Bitfield<dhr12rd_reg_type, 0, 12, DHR12RD_DACC1DHR_T, val>;

    template<DHR12RD_DACC2DHR_T val>
    using DACC2DHR = Register::Combo_Bitfield<dhr12rd_reg_type, 16, 12, DHR12RD_DACC2DHR_T, val>;

} // DAC_DHR12RD
namespace DAC_DHR12LD {

    enum class dhr12ld_reg_type {};

    template<DHR12LD_DACC1DHR_T val>
    using DACC1DHR = Register::Combo_Bitfield<dhr12ld_reg_type, 4, 12, DHR12LD_DACC1DHR_T, val>;

    template<DHR12LD_DACC2DHR_T val>
    using DACC2DHR = Register::Combo_Bitfield<dhr12ld_reg_type, 20, 12, DHR12LD_DACC2DHR_T, val>;

} // DAC_DHR12LD
namespace DAC_DHR8RD {

    enum class dhr8rd_reg_type {};

    template<DHR8RD_DACC1DHR_T val>
    using DACC1DHR = Register::Combo_Bitfield<dhr8rd_reg_type, 0, 8, DHR8RD_DACC1DHR_T, val>;

    template<DHR8RD_DACC2DHR_T val>
    using DACC2DHR = Register::Combo_Bitfield<dhr8rd_reg_type, 8, 8, DHR8RD_DACC2DHR_T, val>;

} // DAC_DHR8RD
namespace DAC_DOR1 {

    enum class dor1_reg_type {};

    template<DOR1_DACC1DOR_T val>
    using DACC1DOR = Register::Combo_Bitfield<dor1_reg_type, 0, 12, DOR1_DACC1DOR_T, val>;

    template<DOR1_DACC1DORB_T val>
    using DACC1DORB = Register::Combo_Bitfield<dor1_reg_type, 16, 12, DOR1_DACC1DORB_T, val>;

} // DAC_DOR1
namespace DAC_DOR2 {

    enum class dor2_reg_type {};

    template<DOR2_DACC2DOR_T val>
    using DACC2DOR = Register::Combo_Bitfield<dor2_reg_type, 0, 12, DOR2_DACC2DOR_T, val>;

    template<DOR2_DACC2DORB_T val>
    using DACC2DORB = Register::Combo_Bitfield<dor2_reg_type, 16, 12, DOR2_DACC2DORB_T, val>;

} // DAC_DOR2
namespace DAC_SR {

    enum class sr_reg_type {};

    template<bool tf>
    using DACRDY = Register::Combo_Bit<sr_reg_type, 11, tf>;

    template<bool tf>
    using DORSTAT1 = Register::Combo_Bit<sr_reg_type, 12, tf>;

    template<bool tf>
    using DMAUDR1 = Register::Combo_Bit<sr_reg_type, 13, tf>;

    template<bool tf>
    using CAL_FLAG1 = Register::Combo_Bit<sr_reg_type, 14, tf>;

    template<bool tf>
    using BWST1 = Register::Combo_Bit<sr_reg_type, 15, tf>;

    template<bool tf>
    using DAC2RDY = Register::Combo_Bit<sr_reg_type, 27, tf>;

    template<bool tf>
    using DORSTAT2 = Register::Combo_Bit<sr_reg_type, 28, tf>;

    template<bool tf>
    using DMAUDR2 = Register::Combo_Bit<sr_reg_type, 29, tf>;

    template<bool tf>
    using CAL_FLAG2 = Register::Combo_Bit<sr_reg_type, 30, tf>;

    template<bool tf>
    using BWST2 = Register::Combo_Bit<sr_reg_type, 31, tf>;

} // DAC_SR
namespace DAC_CCR {

    enum class ccr_reg_type {};

    template<CCR_OTRIM1_T val>
    using OTRIM1 = Register::Combo_Bitfield<ccr_reg_type, 0, 5, CCR_OTRIM1_T, val>;

    template<CCR_OTRIM2_T val>
    using OTRIM2 = Register::Combo_Bitfield<ccr_reg_type, 16, 5, CCR_OTRIM2_T, val>;

} // DAC_CCR
namespace DAC_MCR {

    enum class mcr_reg_type {};

    template<MCR_MODE1_T val>
    using MODE1 = Register::Combo_Bitfield<mcr_reg_type, 0, 3, MCR_MODE1_T, val>;

    template<bool tf>
    using DMADOUBLE1 = Register::Combo_Bit<mcr_reg_type, 8, tf>;

    template<bool tf>
    using SINFORMAT1 = Register::Combo_Bit<mcr_reg_type, 9, tf>;

    template<MCR_HFSEL_T val>
    using HFSEL = Register::Combo_Bitfield<mcr_reg_type, 14, 2, MCR_HFSEL_T, val>;

    template<MCR_MODE2_T val>
    using MODE2 = Register::Combo_Bitfield<mcr_reg_type, 16, 3, MCR_MODE2_T, val>;

    template<bool tf>
    using DMADOUBLE2 = Register::Combo_Bit<mcr_reg_type, 24, tf>;

    template<bool tf>
    using SINFORMAT2 = Register::Combo_Bit<mcr_reg_type, 25, tf>;

} // DAC_MCR
namespace DAC_SHSR1 {

    enum class shsr1_reg_type {};

    template<SHSR1_TSAMPLE1_T val>
    using TSAMPLE1 = Register::Combo_Bitfield<shsr1_reg_type, 0, 10, SHSR1_TSAMPLE1_T, val>;

} // DAC_SHSR1
namespace DAC_SHSR2 {

    enum class shsr2_reg_type {};

    template<SHSR2_TSAMPLE2_T val>
    using TSAMPLE2 = Register::Combo_Bitfield<shsr2_reg_type, 0, 10, SHSR2_TSAMPLE2_T, val>;

} // DAC_SHSR2
namespace DAC_SHHR {

    enum class shhr_reg_type {};

    template<SHHR_THOLD1_T val>
    using THOLD1 = Register::Combo_Bitfield<shhr_reg_type, 0, 10, SHHR_THOLD1_T, val>;

    template<SHHR_THOLD2_T val>
    using THOLD2 = Register::Combo_Bitfield<shhr_reg_type, 16, 10, SHHR_THOLD2_T, val>;

} // DAC_SHHR
namespace DAC_SHRR {

    enum class shrr_reg_type {};

    template<SHRR_TREFRESH1_T val>
    using TREFRESH1 = Register::Combo_Bitfield<shrr_reg_type, 0, 8, SHRR_TREFRESH1_T, val>;

    template<SHRR_TREFRESH2_T val>
    using TREFRESH2 = Register::Combo_Bitfield<shrr_reg_type, 16, 8, SHRR_TREFRESH2_T, val>;

} // DAC_SHRR
namespace DAC_STR1 {

    enum class str1_reg_type {};

    template<STR1_STRSTDATA1_T val>
    using STRSTDATA1 = Register::Combo_Bitfield<str1_reg_type, 0, 12, STR1_STRSTDATA1_T, val>;

    template<bool tf>
    using STDIR1 = Register::Combo_Bit<str1_reg_type, 12, tf>;

    template<STR1_STINCDATA1_T val>
    using STINCDATA1 = Register::Combo_Bitfield<str1_reg_type, 16, 16, STR1_STINCDATA1_T, val>;

} // DAC_STR1
namespace DAC_STR2 {

    enum class str2_reg_type {};

    template<STR2_STRSTDATA2_T val>
    using STRSTDATA2 = Register::Combo_Bitfield<str2_reg_type, 0, 12, STR2_STRSTDATA2_T, val>;

    template<bool tf>
    using STDIR2 = Register::Combo_Bit<str2_reg_type, 12, tf>;

    template<STR2_STINCDATA2_T val>
    using STINCDATA2 = Register::Combo_Bitfield<str2_reg_type, 16, 16, STR2_STINCDATA2_T, val>;

} // DAC_STR2
namespace DAC_STMODR {

    enum class stmodr_reg_type {};

    template<STMODR_STRSTTRIGSEL1_T val>
    using STRSTTRIGSEL1 = Register::Combo_Bitfield<stmodr_reg_type, 0, 4, STMODR_STRSTTRIGSEL1_T, val>;

    template<STMODR_STINCTRIGSEL1_T val>
    using STINCTRIGSEL1 = Register::Combo_Bitfield<stmodr_reg_type, 8, 4, STMODR_STINCTRIGSEL1_T, val>;

    template<STMODR_STRSTTRIGSEL2_T val>
    using STRSTTRIGSEL2 = Register::Combo_Bitfield<stmodr_reg_type, 16, 4, STMODR_STRSTTRIGSEL2_T, val>;

    template<STMODR_STINCTRIGSEL2_T val>
    using STINCTRIGSEL2 = Register::Combo_Bitfield<stmodr_reg_type, 24, 4, STMODR_STINCTRIGSEL2_T, val>;

} // DAC_STMODR
template<uint32_t BASE_ADDRESS>
class DAC {
public:
    static const uint32_t CR_Offset = 0x0000;
    static const uint32_t SWTRGR_Offset = 0x0004;
    static const uint32_t DHR12R1_Offset = 0x0008;
    static const uint32_t DHR12L1_Offset = 0x000C;
    static const uint32_t DHR8R1_Offset = 0x0010;
    static const uint32_t DHR12R2_Offset = 0x0014;
    static const uint32_t DHR12L2_Offset = 0x0018;
    static const uint32_t DHR8R2_Offset = 0x001C;
    static const uint32_t DHR12RD_Offset = 0x0020;
    static const uint32_t DHR12LD_Offset = 0x0024;
    static const uint32_t DHR8RD_Offset = 0x0028;
    static const uint32_t DOR1_Offset = 0x002C;
    static const uint32_t DOR2_Offset = 0x0030;
    static const uint32_t SR_Offset = 0x0034;
    static const uint32_t CCR_Offset = 0x0038;
    static const uint32_t MCR_Offset = 0x003C;
    static const uint32_t SHSR1_Offset = 0x0040;
    static const uint32_t SHSR2_Offset = 0x0044;
    static const uint32_t SHHR_Offset = 0x0048;
    static const uint32_t SHRR_Offset = 0x004C;
    static const uint32_t STR1_Offset = 0x0058;
    static const uint32_t STR2_Offset = 0x005C;
    static const uint32_t STMODR_Offset = 0x0060;

    DAC() = default;
    DAC( const DAC& ) = delete;
    const DAC& operator=( const DAC& ) = delete;

    class CR_T : public Register::Register<DAC_CR::cr_reg_type, BASE_ADDRESS + CR_Offset> {
    // DAC control register
    public:
        Register::Bit<BASE_ADDRESS + CR_Offset, 0> EN1; /* DAC channel1 enable This bit is set and cleared by software to enable/disable DAC channel1. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 1> TEN1; /* DAC channel1 trigger enable */
        Register::Bitfield<BASE_ADDRESS + CR_Offset, 2, 4, CR_TSEL1_T> TSEL1; /* DAC channel1 trigger selection These bits select the external event used to trigger DAC channel1. Note: Only used if bit TEN1 = 1 (DAC channel1 trigger enabled). */
        Register::Bitfield<BASE_ADDRESS + CR_Offset, 6, 2, CR_WAVE1_T> WAVE1; /* DAC channel1 noise/triangle wave generation enable These bits are set and cleared by software. Note: Only used if bit TEN1 = 1 (DAC channel1 trigger enabled). */
        Register::Bitfield<BASE_ADDRESS + CR_Offset, 8, 4, CR_MAMP1_T> MAMP1; /* DAC channel1 mask/amplitude selector These bits are written by software to select mask in wave generation mode or amplitude in triangle generation mode. = 1011: Unmask bits[11:0] of LFSR/ triangle amplitude equal to 4095 */
        Register::Bit<BASE_ADDRESS + CR_Offset, 12> DMAEN1; /* DAC channel1 DMA enable This bit is set and cleared by software. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 13> DMAUDRIE1; /* DAC channel1 DMA Underrun Interrupt enable This bit is set and cleared by software. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 14> CEN1; /* DAC Channel 1 calibration enable This bit is set and cleared by software to enable/disable DAC channel 1 calibration, it can be written only if bit EN1=0 into DAC_CR (the calibration mode can be entered/exit only when the DAC channel is disabled) Otherwise, the write operation is ignored. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 16> EN2; /* DAC channel2 enable This bit is set and cleared by software to enable/disable DAC channel2. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 17> TEN2; /* DAC channel2 trigger enable */
        Register::Bitfield<BASE_ADDRESS + CR_Offset, 18, 4, CR_TSEL2_T> TSEL2; /* DAC channel2 trigger selection These bits select the external event used to trigger DAC channel2 Note: Only used if bit TEN2 = 1 (DAC channel2 trigger enabled). */
        Register::Bitfield<BASE_ADDRESS + CR_Offset, 22, 2, CR_WAVE2_T> WAVE2; /* DAC channel2 noise/triangle wave generation enable These bits are set/reset by software. 1x: Triangle wave generation enabled Note: Only used if bit TEN2 = 1 (DAC channel2 trigger enabled) */
        Register::Bitfield<BASE_ADDRESS + CR_Offset, 24, 4, CR_MAMP2_T> MAMP2; /* DAC channel2 mask/amplitude selector These bits are written by software to select mask in wave generation mode or amplitude in triangle generation mode. = 1011: Unmask bits[11:0] of LFSR/ triangle amplitude equal to 4095 */
        Register::Bit<BASE_ADDRESS + CR_Offset, 28> DMAEN2; /* DAC channel2 DMA enable This bit is set and cleared by software. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 29> DMAUDRIE2; /* DAC channel2 DMA underrun interrupt enable This bit is set and cleared by software. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 30> CEN2; /* DAC Channel 2 calibration enable This bit is set and cleared by software to enable/disable DAC channel 2 calibration, it can be written only if bit EN2=0 into DAC_CR (the calibration mode can be entered/exit only when the DAC channel is disabled) Otherwise, the write operation is ignored. */
    };

    class SWTRGR_T : public Register::Register<DAC_SWTRGR::swtrgr_reg_type, BASE_ADDRESS + SWTRGR_Offset> {
    // DAC software trigger register
    public:
        Register::Bit<BASE_ADDRESS + SWTRGR_Offset, 0> SWTRIG1; /* DAC channel1 software trigger This bit is set by software to trigger the DAC in software trigger mode. Note: This bit is cleared by hardware (one APB1 clock cycle later) once the DAC_DHR1 register value has been loaded into the DAC_DOR1 register. */
        Register::Bit<BASE_ADDRESS + SWTRGR_Offset, 1> SWTRIG2; /* DAC channel2 software trigger This bit is set by software to trigger the DAC in software trigger mode. Note: This bit is cleared by hardware (one APB1 clock cycle later) once the DAC_DHR2 register value has been loaded into the DAC_DOR2 register. */
        Register::Bit<BASE_ADDRESS + SWTRGR_Offset, 16> SWTRIGB1; /* DAC channel1 software trigger B */
        Register::Bit<BASE_ADDRESS + SWTRGR_Offset, 17> SWTRIGB2; /* DAC channel2 software trigger B */
    };

    class DHR12R1_T : public Register::Register<DAC_DHR12R1::dhr12r1_reg_type, BASE_ADDRESS + DHR12R1_Offset> {
    // DAC channel1 12-bit right-aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR12R1_Offset, 0, 12, DHR12R1_DACC1DHR_T> DACC1DHR; /* DAC channel1 12-bit right-aligned data These bits are written by software which specifies 12-bit data for DAC channel1. */
        Register::Bitfield<BASE_ADDRESS + DHR12R1_Offset, 16, 12, DHR12R1_DACC1DHRB_T> DACC1DHRB; /* DAC channel1 12-bit right-aligned data B */
    };

    class DHR12L1_T : public Register::Register<DAC_DHR12L1::dhr12l1_reg_type, BASE_ADDRESS + DHR12L1_Offset> {
    // DAC channel1 12-bit left aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR12L1_Offset, 4, 12, DHR12L1_DACC1DHR_T> DACC1DHR; /* DAC channel1 12-bit left-aligned data These bits are written by software which specifies 12-bit data for DAC channel1. */
        Register::Bitfield<BASE_ADDRESS + DHR12L1_Offset, 20, 12, DHR12L1_DACC1DHRB_T> DACC1DHRB; /* DAC channel1 12-bit left-aligned data B */
    };

    class DHR8R1_T : public Register::Register<DAC_DHR8R1::dhr8r1_reg_type, BASE_ADDRESS + DHR8R1_Offset> {
    // DAC channel1 8-bit right aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR8R1_Offset, 0, 8, DHR8R1_DACC1DHR_T> DACC1DHR; /* DAC channel1 8-bit right-aligned data These bits are written by software which specifies 8-bit data for DAC channel1. */
        Register::Bitfield<BASE_ADDRESS + DHR8R1_Offset, 8, 8, DHR8R1_DACC1DHRB_T> DACC1DHRB; /* DAC channel1 8-bit right-aligned data */
    };

    class DHR12R2_T : public Register::Register<DAC_DHR12R2::dhr12r2_reg_type, BASE_ADDRESS + DHR12R2_Offset> {
    // DAC channel2 12-bit right aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR12R2_Offset, 0, 12, DHR12R2_DACC2DHR_T> DACC2DHR; /* DAC channel2 12-bit right-aligned data These bits are written by software which specifies 12-bit data for DAC channel2. */
        Register::Bitfield<BASE_ADDRESS + DHR12R2_Offset, 16, 12, DHR12R2_DACC2DHRB_T> DACC2DHRB; /* DAC channel2 12-bit right-aligned data */
    };

    class DHR12L2_T : public Register::Register<DAC_DHR12L2::dhr12l2_reg_type, BASE_ADDRESS + DHR12L2_Offset> {
    // DAC channel2 12-bit left aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR12L2_Offset, 4, 12, DHR12L2_DACC2DHR_T> DACC2DHR; /* DAC channel2 12-bit left-aligned data These bits are written by software which specify 12-bit data for DAC channel2. */
        Register::Bitfield<BASE_ADDRESS + DHR12L2_Offset, 20, 12, DHR12L2_DACC2DHRB_T> DACC2DHRB; /* DAC channel2 12-bit left-aligned data B */
    };

    class DHR8R2_T : public Register::Register<DAC_DHR8R2::dhr8r2_reg_type, BASE_ADDRESS + DHR8R2_Offset> {
    // DAC channel2 8-bit right-aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR8R2_Offset, 0, 8, DHR8R2_DACC2DHR_T> DACC2DHR; /* DAC channel2 8-bit right-aligned data These bits are written by software which specifies 8-bit data for DAC channel2. */
        Register::Bitfield<BASE_ADDRESS + DHR8R2_Offset, 8, 8, DHR8R2_DACC2DHRB_T> DACC2DHRB; /* DAC channel2 8-bit right-aligned data */
    };

    class DHR12RD_T : public Register::Register<DAC_DHR12RD::dhr12rd_reg_type, BASE_ADDRESS + DHR12RD_Offset> {
    // Dual DAC 12-bit right-aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR12RD_Offset, 0, 12, DHR12RD_DACC1DHR_T> DACC1DHR; /* DAC channel1 12-bit right-aligned data These bits are written by software which specifies 12-bit data for DAC channel1. */
        Register::Bitfield<BASE_ADDRESS + DHR12RD_Offset, 16, 12, DHR12RD_DACC2DHR_T> DACC2DHR; /* DAC channel2 12-bit right-aligned data These bits are written by software which specifies 12-bit data for DAC channel2. */
    };

    class DHR12LD_T : public Register::Register<DAC_DHR12LD::dhr12ld_reg_type, BASE_ADDRESS + DHR12LD_Offset> {
    // DUAL DAC 12-bit left aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR12LD_Offset, 4, 12, DHR12LD_DACC1DHR_T> DACC1DHR; /* DAC channel1 12-bit left-aligned data These bits are written by software which specifies 12-bit data for DAC channel1. */
        Register::Bitfield<BASE_ADDRESS + DHR12LD_Offset, 20, 12, DHR12LD_DACC2DHR_T> DACC2DHR; /* DAC channel2 12-bit left-aligned data These bits are written by software which specifies 12-bit data for DAC channel2. */
    };

    class DHR8RD_T : public Register::Register<DAC_DHR8RD::dhr8rd_reg_type, BASE_ADDRESS + DHR8RD_Offset> {
    // DUAL DAC 8-bit right aligned data holding register
    public:
        Register::Bitfield<BASE_ADDRESS + DHR8RD_Offset, 0, 8, DHR8RD_DACC1DHR_T> DACC1DHR; /* DAC channel1 8-bit right-aligned data These bits are written by software which specifies 8-bit data for DAC channel1. */
        Register::Bitfield<BASE_ADDRESS + DHR8RD_Offset, 8, 8, DHR8RD_DACC2DHR_T> DACC2DHR; /* DAC channel2 8-bit right-aligned data These bits are written by software which specifies 8-bit data for DAC channel2. */
    };

    class DOR1_T : public Register::Register<DAC_DOR1::dor1_reg_type, BASE_ADDRESS + DOR1_Offset> {
    // DAC channel1 data output register
    public:
        Register::Bitfield<BASE_ADDRESS + DOR1_Offset, 0, 12, DOR1_DACC1DOR_T> DACC1DOR; /* DAC channel1 data output These bits are read-only, they contain data output for DAC channel1. */
        Register::Bitfield<BASE_ADDRESS + DOR1_Offset, 16, 12, DOR1_DACC1DORB_T> DACC1DORB; /* DAC channel1 data output */
    };

    class DOR2_T : public Register::Register<DAC_DOR2::dor2_reg_type, BASE_ADDRESS + DOR2_Offset> {
    // DAC channel2 data output register
    public:
        Register::Bitfield<BASE_ADDRESS + DOR2_Offset, 0, 12, DOR2_DACC2DOR_T> DACC2DOR; /* DAC channel2 data output These bits are read-only, they contain data output for DAC channel2. */
        Register::Bitfield<BASE_ADDRESS + DOR2_Offset, 16, 12, DOR2_DACC2DORB_T> DACC2DORB; /* DAC channel2 data output */
    };

    class SR_T : public Register::Register<DAC_SR::sr_reg_type, BASE_ADDRESS + SR_Offset> {
    // DAC status register
    public:
        Register::Bit<BASE_ADDRESS + SR_Offset, 11> DACRDY; /* DAC channel1 ready status bit */
        Register::Bit<BASE_ADDRESS + SR_Offset, 12> DORSTAT1; /* DAC channel1 output register status bit */
        Register::Bit<BASE_ADDRESS + SR_Offset, 13> DMAUDR1; /* DAC channel1 DMA underrun flag This bit is set by hardware and cleared by software (by writing it to 1). */
        Register::Bit<BASE_ADDRESS + SR_Offset, 14> CAL_FLAG1; /* DAC Channel 1 calibration offset status This bit is set and cleared by hardware */
        Register::Bit<BASE_ADDRESS + SR_Offset, 15> BWST1; /* DAC Channel 1 busy writing sample time flag This bit is systematically set just after Sample & Hold mode enable and is set each time the software writes the register DAC_SHSR1, It is cleared by hardware when the write operation of DAC_SHSR1 is complete. (It takes about 3LSI periods of synchronization). */
        Register::Bit<BASE_ADDRESS + SR_Offset, 27> DAC2RDY; /* DAC channel 2 ready status bit */
        Register::Bit<BASE_ADDRESS + SR_Offset, 28> DORSTAT2; /* DAC channel 2 output register status bit */
        Register::Bit<BASE_ADDRESS + SR_Offset, 29> DMAUDR2; /* DAC channel2 DMA underrun flag This bit is set by hardware and cleared by software (by writing it to 1). */
        Register::Bit<BASE_ADDRESS + SR_Offset, 30> CAL_FLAG2; /* DAC Channel 2 calibration offset status This bit is set and cleared by hardware */
        Register::Bit<BASE_ADDRESS + SR_Offset, 31> BWST2; /* DAC Channel 2 busy writing sample time flag This bit is systematically set just after Sample & Hold mode enable and is set each time the software writes the register DAC_SHSR2, It is cleared by hardware when the write operation of DAC_SHSR2 is complete. (It takes about 3 LSI periods of synchronization). */
    };

    class CCR_T : public Register::Register<DAC_CCR::ccr_reg_type, BASE_ADDRESS + CCR_Offset> {
    // DAC calibration control register
    public:
        Register::Bitfield<BASE_ADDRESS + CCR_Offset, 0, 5, CCR_OTRIM1_T> OTRIM1; /* DAC Channel 1 offset trimming value */
        Register::Bitfield<BASE_ADDRESS + CCR_Offset, 16, 5, CCR_OTRIM2_T> OTRIM2; /* DAC Channel 2 offset trimming value */
    };

    class MCR_T : public Register::Register<DAC_MCR::mcr_reg_type, BASE_ADDRESS + MCR_Offset> {
    // DAC mode control register
    public:
        Register::Bitfield<BASE_ADDRESS + MCR_Offset, 0, 3, MCR_MODE1_T> MODE1; /* DAC Channel 1 mode These bits can be written only when the DAC is disabled and not in the calibration mode (when bit EN1=0 and bit CEN1 =0 in the DAC_CR register). If EN1=1 or CEN1 =1 the write operation is ignored. They can be set and cleared by software to select the DAC Channel 1 mode: DAC Channel 1 in normal Mode DAC Channel 1 in sample &amp; hold mode */
        Register::Bit<BASE_ADDRESS + MCR_Offset, 8> DMADOUBLE1; /* DAC Channel1 DMA double data mode */
        Register::Bit<BASE_ADDRESS + MCR_Offset, 9> SINFORMAT1; /* Enable signed format for DAC channel1 */
        Register::Bitfield<BASE_ADDRESS + MCR_Offset, 14, 2, MCR_HFSEL_T> HFSEL; /* High frequency interface mode selection */
        Register::Bitfield<BASE_ADDRESS + MCR_Offset, 16, 3, MCR_MODE2_T> MODE2; /* DAC Channel 2 mode These bits can be written only when the DAC is disabled and not in the calibration mode (when bit EN2=0 and bit CEN2 =0 in the DAC_CR register). If EN2=1 or CEN2 =1 the write operation is ignored. They can be set and cleared by software to select the DAC Channel 2 mode: DAC Channel 2 in normal Mode DAC Channel 2 in sample &amp; hold mode */
        Register::Bit<BASE_ADDRESS + MCR_Offset, 24> DMADOUBLE2; /* DAC Channel2 DMA double data mode */
        Register::Bit<BASE_ADDRESS + MCR_Offset, 25> SINFORMAT2; /* Enable signed format for DAC channel2 */
    };

    class SHSR1_T : public Register::Register<DAC_SHSR1::shsr1_reg_type, BASE_ADDRESS + SHSR1_Offset> {
    // DAC Sample and Hold sample time register 1
    public:
        Register::Bitfield<BASE_ADDRESS + SHSR1_Offset, 0, 10, SHSR1_TSAMPLE1_T> TSAMPLE1; /* DAC Channel 1 sample Time (only valid in sample &amp; hold mode) These bits can be written when the DAC channel1 is disabled or also during normal operation. in the latter case, the write can be done only when BWSTx of DAC_SR register is low, If BWSTx=1, the write operation is ignored. */
    };

    class SHSR2_T : public Register::Register<DAC_SHSR2::shsr2_reg_type, BASE_ADDRESS + SHSR2_Offset> {
    // DAC Sample and Hold sample time register 2
    public:
        Register::Bitfield<BASE_ADDRESS + SHSR2_Offset, 0, 10, SHSR2_TSAMPLE2_T> TSAMPLE2; /* DAC Channel 2 sample Time (only valid in sample &amp; hold mode) These bits can be written when the DAC channel2 is disabled or also during normal operation. in the latter case, the write can be done only when BWSTx of DAC_SR register is low, if BWSTx=1, the write operation is ignored. */
    };

    class SHHR_T : public Register::Register<DAC_SHHR::shhr_reg_type, BASE_ADDRESS + SHHR_Offset> {
    // DAC Sample and Hold hold time register
    public:
        Register::Bitfield<BASE_ADDRESS + SHHR_Offset, 0, 10, SHHR_THOLD1_T> THOLD1; /* DAC Channel 1 hold Time (only valid in sample &amp; hold mode) Hold time= (THOLD[9:0]) x T LSI */
        Register::Bitfield<BASE_ADDRESS + SHHR_Offset, 16, 10, SHHR_THOLD2_T> THOLD2; /* DAC Channel 2 hold time (only valid in sample &amp; hold mode). Hold time= (THOLD[9:0]) x T LSI */
    };

    class SHRR_T : public Register::Register<DAC_SHRR::shrr_reg_type, BASE_ADDRESS + SHRR_Offset> {
    // DAC Sample and Hold refresh time register
    public:
        Register::Bitfield<BASE_ADDRESS + SHRR_Offset, 0, 8, SHRR_TREFRESH1_T> TREFRESH1; /* DAC Channel 1 refresh Time (only valid in sample &amp; hold mode) Refresh time= (TREFRESH[7:0]) x T LSI */
        Register::Bitfield<BASE_ADDRESS + SHRR_Offset, 16, 8, SHRR_TREFRESH2_T> TREFRESH2; /* DAC Channel 2 refresh Time (only valid in sample &amp; hold mode) Refresh time= (TREFRESH[7:0]) x T LSI */
    };

    class STR1_T : public Register::Register<DAC_STR1::str1_reg_type, BASE_ADDRESS + STR1_Offset> {
    // Sawtooth register
    public:
        Register::Bitfield<BASE_ADDRESS + STR1_Offset, 0, 12, STR1_STRSTDATA1_T> STRSTDATA1; /* DAC Channel 1 Sawtooth reset value */
        Register::Bit<BASE_ADDRESS + STR1_Offset, 12> STDIR1; /* DAC Channel1 Sawtooth direction setting */
        Register::Bitfield<BASE_ADDRESS + STR1_Offset, 16, 16, STR1_STINCDATA1_T> STINCDATA1; /* DAC CH1 Sawtooth increment value (12.4 bit format) */
    };

    class STR2_T : public Register::Register<DAC_STR2::str2_reg_type, BASE_ADDRESS + STR2_Offset> {
    // Sawtooth register
    public:
        Register::Bitfield<BASE_ADDRESS + STR2_Offset, 0, 12, STR2_STRSTDATA2_T> STRSTDATA2; /* DAC Channel 2 Sawtooth reset value */
        Register::Bit<BASE_ADDRESS + STR2_Offset, 12> STDIR2; /* DAC Channel2 Sawtooth direction setting */
        Register::Bitfield<BASE_ADDRESS + STR2_Offset, 16, 16, STR2_STINCDATA2_T> STINCDATA2; /* DAC CH2 Sawtooth increment value (12.4 bit format) */
    };

    class STMODR_T : public Register::Register<DAC_STMODR::stmodr_reg_type, BASE_ADDRESS + STMODR_Offset> {
    // Sawtooth Mode register
    public:
        Register::Bitfield<BASE_ADDRESS + STMODR_Offset, 0, 4, STMODR_STRSTTRIGSEL1_T> STRSTTRIGSEL1; /* DAC Channel 1 Sawtooth Reset trigger selection */
        Register::Bitfield<BASE_ADDRESS + STMODR_Offset, 8, 4, STMODR_STINCTRIGSEL1_T> STINCTRIGSEL1; /* DAC Channel 1 Sawtooth Increment trigger selection */
        Register::Bitfield<BASE_ADDRESS + STMODR_Offset, 16, 4, STMODR_STRSTTRIGSEL2_T> STRSTTRIGSEL2; /* DAC Channel 1 Sawtooth Reset trigger selection */
        Register::Bitfield<BASE_ADDRESS + STMODR_Offset, 24, 4, STMODR_STINCTRIGSEL2_T> STINCTRIGSEL2; /* DAC Channel 2 Sawtooth Increment trigger selection */
    };

    CR_T CR;
    SWTRGR_T SWTRGR;
    DHR12R1_T DHR12R1;
    DHR12L1_T DHR12L1;
    DHR8R1_T DHR8R1;
    DHR12R2_T DHR12R2;
    DHR12L2_T DHR12L2;
    DHR8R2_T DHR8R2;
    DHR12RD_T DHR12RD;
    DHR12LD_T DHR12LD;
    DHR8RD_T DHR8RD;
    DOR1_T DOR1;
    DOR2_T DOR2;
    SR_T SR;
    CCR_T CCR;
    MCR_T MCR;
    SHSR1_T SHSR1;
    SHSR2_T SHSR2;
    SHHR_T SHHR;
    SHRR_T SHRR;
    STR1_T STR1;
    STR2_T STR2;
    STMODR_T STMODR;
};

} // namespace STM32LIB

#endif // STM32G473XX_DAC_HPP_

