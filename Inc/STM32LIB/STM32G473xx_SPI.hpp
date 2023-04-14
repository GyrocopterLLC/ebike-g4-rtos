#ifndef STM32G473XX_SPI_HPP_
#define STM32G473XX_SPI_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"

/* Serial peripheral interface/Inter-IC sound */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using CR1_BR_T = uint32_t;
using CR2_DS_T = uint32_t;
using SR_FRLVL_T = uint32_t;
using SR_FTLVL_T = uint32_t;
using DR_DR_T = uint32_t;
using CRCPR_CRCPOLY_T = uint32_t;
using RXCRCR_RxCRC_T = uint32_t;
using TXCRCR_TxCRC_T = uint32_t;
using I2SCFGR_DATLEN_T = uint32_t;
using I2SCFGR_I2SSTD_T = uint32_t;
using I2SCFGR_I2SCFG_T = uint32_t;
using I2SPR_I2SDIV_T = uint32_t;

namespace SPI_CR1 {

    enum class cr1_reg_type {};

    template<bool tf>
    using BIDIMODE = Register::Combo_Bit<cr1_reg_type, 15, tf>;

    template<bool tf>
    using BIDIOE = Register::Combo_Bit<cr1_reg_type, 14, tf>;

    template<bool tf>
    using CRCEN = Register::Combo_Bit<cr1_reg_type, 13, tf>;

    template<bool tf>
    using CRCNEXT = Register::Combo_Bit<cr1_reg_type, 12, tf>;

    template<bool tf>
    using DFF = Register::Combo_Bit<cr1_reg_type, 11, tf>;

    template<bool tf>
    using RXONLY = Register::Combo_Bit<cr1_reg_type, 10, tf>;

    template<bool tf>
    using SSM = Register::Combo_Bit<cr1_reg_type, 9, tf>;

    template<bool tf>
    using SSI = Register::Combo_Bit<cr1_reg_type, 8, tf>;

    template<bool tf>
    using LSBFIRST = Register::Combo_Bit<cr1_reg_type, 7, tf>;

    template<bool tf>
    using SPE = Register::Combo_Bit<cr1_reg_type, 6, tf>;

    template<CR1_BR_T val>
    using BR = Register::Combo_Bitfield<cr1_reg_type, 3, 3, CR1_BR_T, val>;

    template<bool tf>
    using MSTR = Register::Combo_Bit<cr1_reg_type, 2, tf>;

    template<bool tf>
    using CPOL = Register::Combo_Bit<cr1_reg_type, 1, tf>;

    template<bool tf>
    using CPHA = Register::Combo_Bit<cr1_reg_type, 0, tf>;

} // SPI_CR1
namespace SPI_CR2 {

    enum class cr2_reg_type {};

    template<bool tf>
    using RXDMAEN = Register::Combo_Bit<cr2_reg_type, 0, tf>;

    template<bool tf>
    using TXDMAEN = Register::Combo_Bit<cr2_reg_type, 1, tf>;

    template<bool tf>
    using SSOE = Register::Combo_Bit<cr2_reg_type, 2, tf>;

    template<bool tf>
    using NSSP = Register::Combo_Bit<cr2_reg_type, 3, tf>;

    template<bool tf>
    using FRF = Register::Combo_Bit<cr2_reg_type, 4, tf>;

    template<bool tf>
    using ERRIE = Register::Combo_Bit<cr2_reg_type, 5, tf>;

    template<bool tf>
    using RXNEIE = Register::Combo_Bit<cr2_reg_type, 6, tf>;

    template<bool tf>
    using TXEIE = Register::Combo_Bit<cr2_reg_type, 7, tf>;

    template<CR2_DS_T val>
    using DS = Register::Combo_Bitfield<cr2_reg_type, 8, 4, CR2_DS_T, val>;

    template<bool tf>
    using FRXTH = Register::Combo_Bit<cr2_reg_type, 12, tf>;

    template<bool tf>
    using LDMA_RX = Register::Combo_Bit<cr2_reg_type, 13, tf>;

    template<bool tf>
    using LDMA_TX = Register::Combo_Bit<cr2_reg_type, 14, tf>;

} // SPI_CR2
namespace SPI_SR {

    enum class sr_reg_type {};

    template<bool tf>
    using RXNE = Register::Combo_Bit<sr_reg_type, 0, tf>;

    template<bool tf>
    using TXE = Register::Combo_Bit<sr_reg_type, 1, tf>;

    template<bool tf>
    using CRCERR = Register::Combo_Bit<sr_reg_type, 4, tf>;

    template<bool tf>
    using MODF = Register::Combo_Bit<sr_reg_type, 5, tf>;

    template<bool tf>
    using OVR = Register::Combo_Bit<sr_reg_type, 6, tf>;

    template<bool tf>
    using BSY = Register::Combo_Bit<sr_reg_type, 7, tf>;

    template<bool tf>
    using TIFRFE = Register::Combo_Bit<sr_reg_type, 8, tf>;

    template<SR_FRLVL_T val>
    using FRLVL = Register::Combo_Bitfield<sr_reg_type, 9, 2, SR_FRLVL_T, val>;

    template<SR_FTLVL_T val>
    using FTLVL = Register::Combo_Bitfield<sr_reg_type, 11, 2, SR_FTLVL_T, val>;

} // SPI_SR
namespace SPI_DR {

    enum class dr_reg_type {};

    template<DR_DR_T val>
    using DR = Register::Combo_Bitfield<dr_reg_type, 0, 16, DR_DR_T, val>;

} // SPI_DR
namespace SPI_CRCPR {

    enum class crcpr_reg_type {};

    template<CRCPR_CRCPOLY_T val>
    using CRCPOLY = Register::Combo_Bitfield<crcpr_reg_type, 0, 16, CRCPR_CRCPOLY_T, val>;

} // SPI_CRCPR
namespace SPI_RXCRCR {

    enum class rxcrcr_reg_type {};

    template<RXCRCR_RxCRC_T val>
    using RxCRC = Register::Combo_Bitfield<rxcrcr_reg_type, 0, 16, RXCRCR_RxCRC_T, val>;

} // SPI_RXCRCR
namespace SPI_TXCRCR {

    enum class txcrcr_reg_type {};

    template<TXCRCR_TxCRC_T val>
    using TxCRC = Register::Combo_Bitfield<txcrcr_reg_type, 0, 16, TXCRCR_TxCRC_T, val>;

} // SPI_TXCRCR
namespace SPI_I2SCFGR {

    enum class i2scfgr_reg_type {};

    template<bool tf>
    using CHLEN = Register::Combo_Bit<i2scfgr_reg_type, 0, tf>;

    template<I2SCFGR_DATLEN_T val>
    using DATLEN = Register::Combo_Bitfield<i2scfgr_reg_type, 1, 2, I2SCFGR_DATLEN_T, val>;

    template<bool tf>
    using CKPOL = Register::Combo_Bit<i2scfgr_reg_type, 3, tf>;

    template<I2SCFGR_I2SSTD_T val>
    using I2SSTD = Register::Combo_Bitfield<i2scfgr_reg_type, 4, 2, I2SCFGR_I2SSTD_T, val>;

    template<bool tf>
    using PCMSYNC = Register::Combo_Bit<i2scfgr_reg_type, 7, tf>;

    template<I2SCFGR_I2SCFG_T val>
    using I2SCFG = Register::Combo_Bitfield<i2scfgr_reg_type, 8, 2, I2SCFGR_I2SCFG_T, val>;

    template<bool tf>
    using I2SE = Register::Combo_Bit<i2scfgr_reg_type, 10, tf>;

    template<bool tf>
    using I2SMOD = Register::Combo_Bit<i2scfgr_reg_type, 11, tf>;

} // SPI_I2SCFGR
namespace SPI_I2SPR {

    enum class i2spr_reg_type {};

    template<I2SPR_I2SDIV_T val>
    using I2SDIV = Register::Combo_Bitfield<i2spr_reg_type, 0, 8, I2SPR_I2SDIV_T, val>;

    template<bool tf>
    using ODD = Register::Combo_Bit<i2spr_reg_type, 8, tf>;

    template<bool tf>
    using MCKOE = Register::Combo_Bit<i2spr_reg_type, 9, tf>;

} // SPI_I2SPR
template<uint32_t BASE_ADDRESS>
class SPI {
public:
    static const uint32_t CR1_Offset = 0x0000;
    static const uint32_t CR2_Offset = 0x0004;
    static const uint32_t SR_Offset = 0x0008;
    static const uint32_t DR_Offset = 0x000C;
    static const uint32_t CRCPR_Offset = 0x0010;
    static const uint32_t RXCRCR_Offset = 0x0014;
    static const uint32_t TXCRCR_Offset = 0x0018;
    static const uint32_t I2SCFGR_Offset = 0x001C;
    static const uint32_t I2SPR_Offset = 0x0020;

    SPI() = default;
    SPI( const SPI& ) = delete;
    const SPI& operator=( const SPI& ) = delete;

    class CR1_T : public Register::Register<SPI_CR1::cr1_reg_type, BASE_ADDRESS + CR1_Offset> {
    // control register 1
    public:
        Register::Bit<BASE_ADDRESS + CR1_Offset, 15> BIDIMODE; /* Bidirectional data mode enable */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 14> BIDIOE; /* Output enable in bidirectional mode */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 13> CRCEN; /* Hardware CRC calculation enable */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 12> CRCNEXT; /* CRC transfer next */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 11> DFF; /* Data frame format */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 10> RXONLY; /* Receive only */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 9> SSM; /* Software slave management */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 8> SSI; /* Internal slave select */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 7> LSBFIRST; /* Frame format */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 6> SPE; /* SPI enable */
        Register::Bitfield<BASE_ADDRESS + CR1_Offset, 3, 3, CR1_BR_T> BR; /* Baud rate control */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 2> MSTR; /* Master selection */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 1> CPOL; /* Clock polarity */
        Register::Bit<BASE_ADDRESS + CR1_Offset, 0> CPHA; /* Clock phase */
    };

    class CR2_T : public Register::Register<SPI_CR2::cr2_reg_type, BASE_ADDRESS + CR2_Offset> {
    // control register 2
    public:
        Register::Bit<BASE_ADDRESS + CR2_Offset, 0> RXDMAEN; /* Rx buffer DMA enable */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 1> TXDMAEN; /* Tx buffer DMA enable */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 2> SSOE; /* SS output enable */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 3> NSSP; /* NSS pulse management */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 4> FRF; /* Frame format */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 5> ERRIE; /* Error interrupt enable */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 6> RXNEIE; /* RX buffer not empty interrupt enable */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 7> TXEIE; /* Tx buffer empty interrupt enable */
        Register::Bitfield<BASE_ADDRESS + CR2_Offset, 8, 4, CR2_DS_T> DS; /* Data size */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 12> FRXTH; /* FIFO reception threshold */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 13> LDMA_RX; /* Last DMA transfer for reception */
        Register::Bit<BASE_ADDRESS + CR2_Offset, 14> LDMA_TX; /* Last DMA transfer for transmission */
    };

    class SR_T : public Register::Register<SPI_SR::sr_reg_type, BASE_ADDRESS + SR_Offset> {
    // status register
    public:
        Register::Bit<BASE_ADDRESS + SR_Offset, 0> RXNE; /* Receive buffer not empty */
        Register::Bit<BASE_ADDRESS + SR_Offset, 1> TXE; /* Transmit buffer empty */
        Register::Bit<BASE_ADDRESS + SR_Offset, 4> CRCERR; /* CRC error flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 5> MODF; /* Mode fault */
        Register::Bit<BASE_ADDRESS + SR_Offset, 6> OVR; /* Overrun flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 7> BSY; /* Busy flag */
        Register::Bit<BASE_ADDRESS + SR_Offset, 8> TIFRFE; /* TI frame format error */
        Register::Bitfield<BASE_ADDRESS + SR_Offset, 9, 2, SR_FRLVL_T> FRLVL; /* FIFO reception level */
        Register::Bitfield<BASE_ADDRESS + SR_Offset, 11, 2, SR_FTLVL_T> FTLVL; /* FIFO transmission level */
    };

    class DR_T : public Register::Register<SPI_DR::dr_reg_type, BASE_ADDRESS + DR_Offset> {
    // data register
    public:
        Register::Bitfield<BASE_ADDRESS + DR_Offset, 0, 16, DR_DR_T> DR; /* Data register */
    };

    class CRCPR_T : public Register::Register<SPI_CRCPR::crcpr_reg_type, BASE_ADDRESS + CRCPR_Offset> {
    // CRC polynomial register
    public:
        Register::Bitfield<BASE_ADDRESS + CRCPR_Offset, 0, 16, CRCPR_CRCPOLY_T> CRCPOLY; /* CRC polynomial register */
    };

    class RXCRCR_T : public Register::Register<SPI_RXCRCR::rxcrcr_reg_type, BASE_ADDRESS + RXCRCR_Offset> {
    // RX CRC register
    public:
        Register::Bitfield<BASE_ADDRESS + RXCRCR_Offset, 0, 16, RXCRCR_RxCRC_T> RxCRC; /* Rx CRC register */
    };

    class TXCRCR_T : public Register::Register<SPI_TXCRCR::txcrcr_reg_type, BASE_ADDRESS + TXCRCR_Offset> {
    // TX CRC register
    public:
        Register::Bitfield<BASE_ADDRESS + TXCRCR_Offset, 0, 16, TXCRCR_TxCRC_T> TxCRC; /* Tx CRC register */
    };

    class I2SCFGR_T : public Register::Register<SPI_I2SCFGR::i2scfgr_reg_type, BASE_ADDRESS + I2SCFGR_Offset> {
    // configuration register
    public:
        Register::Bit<BASE_ADDRESS + I2SCFGR_Offset, 0> CHLEN; /* CHLEN */
        Register::Bitfield<BASE_ADDRESS + I2SCFGR_Offset, 1, 2, I2SCFGR_DATLEN_T> DATLEN; /* DATLEN */
        Register::Bit<BASE_ADDRESS + I2SCFGR_Offset, 3> CKPOL; /* CKPOL */
        Register::Bitfield<BASE_ADDRESS + I2SCFGR_Offset, 4, 2, I2SCFGR_I2SSTD_T> I2SSTD; /* I2SSTD */
        Register::Bit<BASE_ADDRESS + I2SCFGR_Offset, 7> PCMSYNC; /* PCMSYNC */
        Register::Bitfield<BASE_ADDRESS + I2SCFGR_Offset, 8, 2, I2SCFGR_I2SCFG_T> I2SCFG; /* I2SCFG */
        Register::Bit<BASE_ADDRESS + I2SCFGR_Offset, 10> I2SE; /* I2SE */
        Register::Bit<BASE_ADDRESS + I2SCFGR_Offset, 11> I2SMOD; /* I2SMOD */
    };

    class I2SPR_T : public Register::Register<SPI_I2SPR::i2spr_reg_type, BASE_ADDRESS + I2SPR_Offset> {
    // prescaler register
    public:
        Register::Bitfield<BASE_ADDRESS + I2SPR_Offset, 0, 8, I2SPR_I2SDIV_T> I2SDIV; /* I2SDIV */
        Register::Bit<BASE_ADDRESS + I2SPR_Offset, 8> ODD; /* ODD */
        Register::Bit<BASE_ADDRESS + I2SPR_Offset, 9> MCKOE; /* MCKOE */
    };

    CR1_T CR1;
    CR2_T CR2;
    SR_T SR;
    DR_T DR;
    CRCPR_T CRCPR;
    RXCRCR_T RXCRCR;
    TXCRCR_T TXCRCR;
    I2SCFGR_T I2SCFGR;
    I2SPR_T I2SPR;
};

} // namespace STM32LIB

#endif // STM32G473XX_SPI_HPP_

