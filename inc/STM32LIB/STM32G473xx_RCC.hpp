#ifndef STM32G473XX_RCC_HPP_
#define STM32G473XX_RCC_HPP_
#pragma once

#include <cstdint>
#include "Register.hpp"
#include "RCC_Types.hpp"

/* Reset and clock control */
namespace STM32LIB { 

/* Overwritable types for each of the bitfields.
 * Defaults to uint32_t, but feel free to redefine with your
 * own custom enum class later. */
using ICSCR_HSICAL_T = uint32_t;
using ICSCR_HSITRIM_T = uint32_t;
using CFGR_SW_T = RCC_System_Clock;
using CFGR_SWS_T = RCC_System_Clock;
using CFGR_HPRE_T = RCC_AHB_Prescaler;
using CFGR_PPRE1_T = RCC_APB_Prescaler;
using CFGR_PPRE2_T = RCC_APB_Prescaler;
using CFGR_MCOSEL_T = RCC_MCO_Select;
using CFGR_MCOPRE_T = RCC_MCO_Prescaler;
using PLLCFGR_PLLSRC_T = RCC_PLL_Source;
using PLLCFGR_PLLM_T = uint32_t;
using PLLCFGR_PLLN_T = uint32_t;
using PLLCFGR_PLLQ_T = uint32_t;
using PLLCFGR_PLLR_T = uint32_t;
using PLLCFGR_PLLPDIV_T = uint32_t;
using CCIPR_USART1SEL_T = uint32_t;
using CCIPR_USART2SEL_T = uint32_t;
using CCIPR_USART3SEL_T = uint32_t;
using CCIPR_UART4SEL_T = uint32_t;
using CCIPR_UART5SEL_T = uint32_t;
using CCIPR_LPUART1SEL_T = uint32_t;
using CCIPR_I2C1SEL_T = uint32_t;
using CCIPR_I2C2SEL_T = uint32_t;
using CCIPR_I2C3SEL_T = uint32_t;
using CCIPR_LPTIM1SEL_T = uint32_t;
using CCIPR_SAI1SEL_T = uint32_t;
using CCIPR_I2S23SEL_T = uint32_t;
using CCIPR_FDCANSEL_T = uint32_t;
using CCIPR_CLK48SEL_T = uint32_t;
using CCIPR_ADC12SEL_T = uint32_t;
using CCIPR_ADC345SEL_T = uint32_t;
using BDCR_LSEDRV_T = uint32_t;
using BDCR_RTCSEL_T = uint32_t;
using CRRCR_HSI48CAL_T = uint32_t;
using CCIPR2_I2C4SEL_T = uint32_t;
using CCIPR2_QSPISEL_T = uint32_t;

namespace RCC_CR {

    enum class cr_reg_type {};

    template<bool tf>
    using HSION = Register::Combo_Bit<cr_reg_type, 8, tf>;

    template<bool tf>
    using HSIKERON = Register::Combo_Bit<cr_reg_type, 9, tf>;

    template<bool tf>
    using HSIRDY = Register::Combo_Bit<cr_reg_type, 10, tf>;

    template<bool tf>
    using HSEON = Register::Combo_Bit<cr_reg_type, 16, tf>;

    template<bool tf>
    using HSERDY = Register::Combo_Bit<cr_reg_type, 17, tf>;

    template<bool tf>
    using HSEBYP = Register::Combo_Bit<cr_reg_type, 18, tf>;

    template<bool tf>
    using CSSON = Register::Combo_Bit<cr_reg_type, 19, tf>;

    template<bool tf>
    using PLLON = Register::Combo_Bit<cr_reg_type, 24, tf>;

    template<bool tf>
    using PLLRDY = Register::Combo_Bit<cr_reg_type, 25, tf>;

} // RCC_CR
namespace RCC_ICSCR {

    enum class icscr_reg_type {};

    template<ICSCR_HSICAL_T val>
    using HSICAL = Register::Combo_Bitfield<icscr_reg_type, 16, 8, ICSCR_HSICAL_T, val>;

    template<ICSCR_HSITRIM_T val>
    using HSITRIM = Register::Combo_Bitfield<icscr_reg_type, 24, 7, ICSCR_HSITRIM_T, val>;

} // RCC_ICSCR
namespace RCC_CFGR {

    enum class cfgr_reg_type {};

    template<CFGR_SW_T val>
    using SW = Register::Combo_Bitfield<cfgr_reg_type, 0, 2, CFGR_SW_T, val>;

    template<CFGR_SWS_T val>
    using SWS = Register::Combo_Bitfield<cfgr_reg_type, 2, 2, CFGR_SWS_T, val>;

    template<CFGR_HPRE_T val>
    using HPRE = Register::Combo_Bitfield<cfgr_reg_type, 4, 4, CFGR_HPRE_T, val>;

    template<CFGR_PPRE1_T val>
    using PPRE1 = Register::Combo_Bitfield<cfgr_reg_type, 8, 3, CFGR_PPRE1_T, val>;

    template<CFGR_PPRE2_T val>
    using PPRE2 = Register::Combo_Bitfield<cfgr_reg_type, 11, 3, CFGR_PPRE2_T, val>;

    template<CFGR_MCOSEL_T val>
    using MCOSEL = Register::Combo_Bitfield<cfgr_reg_type, 24, 4, CFGR_MCOSEL_T, val>;

    template<CFGR_MCOPRE_T val>
    using MCOPRE = Register::Combo_Bitfield<cfgr_reg_type, 28, 3, CFGR_MCOPRE_T, val>;

} // RCC_CFGR
namespace RCC_PLLCFGR {

    enum class pllcfgr_reg_type {};

    template<PLLCFGR_PLLSRC_T val>
    using PLLSRC = Register::Combo_Bitfield<pllcfgr_reg_type, 0, 2, PLLCFGR_PLLSRC_T, val>;

    template<PLLCFGR_PLLM_T val>
    using PLLM = Register::Combo_Bitfield<pllcfgr_reg_type, 4, 4, PLLCFGR_PLLM_T, val>;

    template<PLLCFGR_PLLN_T val>
    using PLLN = Register::Combo_Bitfield<pllcfgr_reg_type, 8, 7, PLLCFGR_PLLN_T, val>;

    template<bool tf>
    using PLLPEN = Register::Combo_Bit<pllcfgr_reg_type, 16, tf>;

    template<bool tf>
    using PLLP = Register::Combo_Bit<pllcfgr_reg_type, 17, tf>;

    template<bool tf>
    using PLLQEN = Register::Combo_Bit<pllcfgr_reg_type, 20, tf>;

    template<PLLCFGR_PLLQ_T val>
    using PLLQ = Register::Combo_Bitfield<pllcfgr_reg_type, 21, 2, PLLCFGR_PLLQ_T, val>;

    template<bool tf>
    using PLLREN = Register::Combo_Bit<pllcfgr_reg_type, 24, tf>;

    template<PLLCFGR_PLLR_T val>
    using PLLR = Register::Combo_Bitfield<pllcfgr_reg_type, 25, 2, PLLCFGR_PLLR_T, val>;

    template<PLLCFGR_PLLPDIV_T val>
    using PLLPDIV = Register::Combo_Bitfield<pllcfgr_reg_type, 27, 5, PLLCFGR_PLLPDIV_T, val>;

} // RCC_PLLCFGR
namespace RCC_CIER {

    enum class cier_reg_type {};

    template<bool tf>
    using LSIRDYIE = Register::Combo_Bit<cier_reg_type, 0, tf>;

    template<bool tf>
    using LSERDYIE = Register::Combo_Bit<cier_reg_type, 1, tf>;

    template<bool tf>
    using HSIRDYIE = Register::Combo_Bit<cier_reg_type, 3, tf>;

    template<bool tf>
    using HSERDYIE = Register::Combo_Bit<cier_reg_type, 4, tf>;

    template<bool tf>
    using PLLRDYIE = Register::Combo_Bit<cier_reg_type, 5, tf>;

    template<bool tf>
    using LSECSSIE = Register::Combo_Bit<cier_reg_type, 9, tf>;

    template<bool tf>
    using HSI48RDYIE = Register::Combo_Bit<cier_reg_type, 10, tf>;

} // RCC_CIER
namespace RCC_CIFR {

    enum class cifr_reg_type {};

    template<bool tf>
    using LSIRDYF = Register::Combo_Bit<cifr_reg_type, 0, tf>;

    template<bool tf>
    using LSERDYF = Register::Combo_Bit<cifr_reg_type, 1, tf>;

    template<bool tf>
    using HSIRDYF = Register::Combo_Bit<cifr_reg_type, 3, tf>;

    template<bool tf>
    using HSERDYF = Register::Combo_Bit<cifr_reg_type, 4, tf>;

    template<bool tf>
    using PLLRDYF = Register::Combo_Bit<cifr_reg_type, 5, tf>;

    template<bool tf>
    using CSSF = Register::Combo_Bit<cifr_reg_type, 8, tf>;

    template<bool tf>
    using LSECSSF = Register::Combo_Bit<cifr_reg_type, 9, tf>;

    template<bool tf>
    using HSI48RDYF = Register::Combo_Bit<cifr_reg_type, 10, tf>;

} // RCC_CIFR
namespace RCC_CICR {

    enum class cicr_reg_type {};

    template<bool tf>
    using LSIRDYC = Register::Combo_Bit<cicr_reg_type, 0, tf>;

    template<bool tf>
    using LSERDYC = Register::Combo_Bit<cicr_reg_type, 1, tf>;

    template<bool tf>
    using HSIRDYC = Register::Combo_Bit<cicr_reg_type, 3, tf>;

    template<bool tf>
    using HSERDYC = Register::Combo_Bit<cicr_reg_type, 4, tf>;

    template<bool tf>
    using PLLRDYC = Register::Combo_Bit<cicr_reg_type, 5, tf>;

    template<bool tf>
    using CSSC = Register::Combo_Bit<cicr_reg_type, 8, tf>;

    template<bool tf>
    using LSECSSC = Register::Combo_Bit<cicr_reg_type, 9, tf>;

    template<bool tf>
    using HSI48RDYC = Register::Combo_Bit<cicr_reg_type, 10, tf>;

} // RCC_CICR
namespace RCC_AHB1RSTR {

    enum class ahb1rstr_reg_type {};

    template<bool tf>
    using DMA1RST = Register::Combo_Bit<ahb1rstr_reg_type, 0, tf>;

    template<bool tf>
    using DMA2RST = Register::Combo_Bit<ahb1rstr_reg_type, 1, tf>;

    template<bool tf>
    using DMAMUX1RST = Register::Combo_Bit<ahb1rstr_reg_type, 2, tf>;

    template<bool tf>
    using CORDICRST = Register::Combo_Bit<ahb1rstr_reg_type, 3, tf>;

    template<bool tf>
    using FMACRST = Register::Combo_Bit<ahb1rstr_reg_type, 4, tf>;

    template<bool tf>
    using FLASHRST = Register::Combo_Bit<ahb1rstr_reg_type, 8, tf>;

    template<bool tf>
    using CRCRST = Register::Combo_Bit<ahb1rstr_reg_type, 12, tf>;

} // RCC_AHB1RSTR
namespace RCC_AHB2RSTR {

    enum class ahb2rstr_reg_type {};

    template<bool tf>
    using GPIOARST = Register::Combo_Bit<ahb2rstr_reg_type, 0, tf>;

    template<bool tf>
    using GPIOBRST = Register::Combo_Bit<ahb2rstr_reg_type, 1, tf>;

    template<bool tf>
    using GPIOCRST = Register::Combo_Bit<ahb2rstr_reg_type, 2, tf>;

    template<bool tf>
    using GPIODRST = Register::Combo_Bit<ahb2rstr_reg_type, 3, tf>;

    template<bool tf>
    using GPIOERST = Register::Combo_Bit<ahb2rstr_reg_type, 4, tf>;

    template<bool tf>
    using GPIOFRST = Register::Combo_Bit<ahb2rstr_reg_type, 5, tf>;

    template<bool tf>
    using GPIOGRST = Register::Combo_Bit<ahb2rstr_reg_type, 6, tf>;

    template<bool tf>
    using ADC12RST = Register::Combo_Bit<ahb2rstr_reg_type, 13, tf>;

    template<bool tf>
    using ADC345RST = Register::Combo_Bit<ahb2rstr_reg_type, 14, tf>;

    template<bool tf>
    using DAC1RST = Register::Combo_Bit<ahb2rstr_reg_type, 16, tf>;

    template<bool tf>
    using DAC2RST = Register::Combo_Bit<ahb2rstr_reg_type, 17, tf>;

    template<bool tf>
    using DAC3RST = Register::Combo_Bit<ahb2rstr_reg_type, 18, tf>;

    template<bool tf>
    using DAC4RST = Register::Combo_Bit<ahb2rstr_reg_type, 19, tf>;

    template<bool tf>
    using AESRST = Register::Combo_Bit<ahb2rstr_reg_type, 24, tf>;

    template<bool tf>
    using RNGRST = Register::Combo_Bit<ahb2rstr_reg_type, 26, tf>;

} // RCC_AHB2RSTR
namespace RCC_AHB3RSTR {

    enum class ahb3rstr_reg_type {};

    template<bool tf>
    using FMCRST = Register::Combo_Bit<ahb3rstr_reg_type, 0, tf>;

    template<bool tf>
    using QSPIRST = Register::Combo_Bit<ahb3rstr_reg_type, 8, tf>;

} // RCC_AHB3RSTR
namespace RCC_APB1RSTR1 {

    enum class apb1rstr1_reg_type {};

    template<bool tf>
    using TIM2RST = Register::Combo_Bit<apb1rstr1_reg_type, 0, tf>;

    template<bool tf>
    using TIM3RST = Register::Combo_Bit<apb1rstr1_reg_type, 1, tf>;

    template<bool tf>
    using TIM4RST = Register::Combo_Bit<apb1rstr1_reg_type, 2, tf>;

    template<bool tf>
    using TIM5RST = Register::Combo_Bit<apb1rstr1_reg_type, 3, tf>;

    template<bool tf>
    using TIM6RST = Register::Combo_Bit<apb1rstr1_reg_type, 4, tf>;

    template<bool tf>
    using TIM7RST = Register::Combo_Bit<apb1rstr1_reg_type, 5, tf>;

    template<bool tf>
    using CRSRST = Register::Combo_Bit<apb1rstr1_reg_type, 8, tf>;

    template<bool tf>
    using SPI2RST = Register::Combo_Bit<apb1rstr1_reg_type, 14, tf>;

    template<bool tf>
    using SPI3RST = Register::Combo_Bit<apb1rstr1_reg_type, 15, tf>;

    template<bool tf>
    using USART2RST = Register::Combo_Bit<apb1rstr1_reg_type, 17, tf>;

    template<bool tf>
    using USART3RST = Register::Combo_Bit<apb1rstr1_reg_type, 18, tf>;

    template<bool tf>
    using UART4RST = Register::Combo_Bit<apb1rstr1_reg_type, 19, tf>;

    template<bool tf>
    using UART5RST = Register::Combo_Bit<apb1rstr1_reg_type, 20, tf>;

    template<bool tf>
    using I2C1RST = Register::Combo_Bit<apb1rstr1_reg_type, 21, tf>;

    template<bool tf>
    using I2C2RST = Register::Combo_Bit<apb1rstr1_reg_type, 22, tf>;

    template<bool tf>
    using USBRST = Register::Combo_Bit<apb1rstr1_reg_type, 23, tf>;

    template<bool tf>
    using FDCANRST = Register::Combo_Bit<apb1rstr1_reg_type, 25, tf>;

    template<bool tf>
    using PWRRST = Register::Combo_Bit<apb1rstr1_reg_type, 28, tf>;

    template<bool tf>
    using I2C3RST = Register::Combo_Bit<apb1rstr1_reg_type, 30, tf>;

    template<bool tf>
    using LPTIM1RST = Register::Combo_Bit<apb1rstr1_reg_type, 31, tf>;

} // RCC_APB1RSTR1
namespace RCC_APB1RSTR2 {

    enum class apb1rstr2_reg_type {};

    template<bool tf>
    using LPUART1RST = Register::Combo_Bit<apb1rstr2_reg_type, 0, tf>;

    template<bool tf>
    using I2C4RST = Register::Combo_Bit<apb1rstr2_reg_type, 1, tf>;

    template<bool tf>
    using UCPD1RST = Register::Combo_Bit<apb1rstr2_reg_type, 8, tf>;

} // RCC_APB1RSTR2
namespace RCC_APB2RSTR {

    enum class apb2rstr_reg_type {};

    template<bool tf>
    using SYSCFGRST = Register::Combo_Bit<apb2rstr_reg_type, 0, tf>;

    template<bool tf>
    using TIM1RST = Register::Combo_Bit<apb2rstr_reg_type, 11, tf>;

    template<bool tf>
    using SPI1RST = Register::Combo_Bit<apb2rstr_reg_type, 12, tf>;

    template<bool tf>
    using TIM8RST = Register::Combo_Bit<apb2rstr_reg_type, 13, tf>;

    template<bool tf>
    using USART1RST = Register::Combo_Bit<apb2rstr_reg_type, 14, tf>;

    template<bool tf>
    using SPI4RST = Register::Combo_Bit<apb2rstr_reg_type, 15, tf>;

    template<bool tf>
    using TIM15RST = Register::Combo_Bit<apb2rstr_reg_type, 16, tf>;

    template<bool tf>
    using TIM16RST = Register::Combo_Bit<apb2rstr_reg_type, 17, tf>;

    template<bool tf>
    using TIM17RST = Register::Combo_Bit<apb2rstr_reg_type, 18, tf>;

    template<bool tf>
    using TIM20RST = Register::Combo_Bit<apb2rstr_reg_type, 20, tf>;

    template<bool tf>
    using SAI1RST = Register::Combo_Bit<apb2rstr_reg_type, 21, tf>;

    template<bool tf>
    using HRTIM1RST = Register::Combo_Bit<apb2rstr_reg_type, 26, tf>;

} // RCC_APB2RSTR
namespace RCC_AHB1ENR {

    enum class ahb1enr_reg_type {};

    template<bool tf>
    using DMA1EN = Register::Combo_Bit<ahb1enr_reg_type, 0, tf>;

    template<bool tf>
    using DMA2EN = Register::Combo_Bit<ahb1enr_reg_type, 1, tf>;

    template<bool tf>
    using DMAMUX1EN = Register::Combo_Bit<ahb1enr_reg_type, 2, tf>;

    template<bool tf>
    using CORDICEN = Register::Combo_Bit<ahb1enr_reg_type, 3, tf>;

    template<bool tf>
    using FMACEN = Register::Combo_Bit<ahb1enr_reg_type, 4, tf>;

    template<bool tf>
    using FLASHEN = Register::Combo_Bit<ahb1enr_reg_type, 8, tf>;

    template<bool tf>
    using CRCEN = Register::Combo_Bit<ahb1enr_reg_type, 12, tf>;

} // RCC_AHB1ENR
namespace RCC_AHB2ENR {

    enum class ahb2enr_reg_type {};

    template<bool tf>
    using GPIOAEN = Register::Combo_Bit<ahb2enr_reg_type, 0, tf>;

    template<bool tf>
    using GPIOBEN = Register::Combo_Bit<ahb2enr_reg_type, 1, tf>;

    template<bool tf>
    using GPIOCEN = Register::Combo_Bit<ahb2enr_reg_type, 2, tf>;

    template<bool tf>
    using GPIODEN = Register::Combo_Bit<ahb2enr_reg_type, 3, tf>;

    template<bool tf>
    using GPIOEEN = Register::Combo_Bit<ahb2enr_reg_type, 4, tf>;

    template<bool tf>
    using GPIOFEN = Register::Combo_Bit<ahb2enr_reg_type, 5, tf>;

    template<bool tf>
    using GPIOGEN = Register::Combo_Bit<ahb2enr_reg_type, 6, tf>;

    template<bool tf>
    using ADC12EN = Register::Combo_Bit<ahb2enr_reg_type, 13, tf>;

    template<bool tf>
    using ADC345EN = Register::Combo_Bit<ahb2enr_reg_type, 14, tf>;

    template<bool tf>
    using DAC1EN = Register::Combo_Bit<ahb2enr_reg_type, 16, tf>;

    template<bool tf>
    using DAC2EN = Register::Combo_Bit<ahb2enr_reg_type, 17, tf>;

    template<bool tf>
    using DAC3EN = Register::Combo_Bit<ahb2enr_reg_type, 18, tf>;

    template<bool tf>
    using DAC4EN = Register::Combo_Bit<ahb2enr_reg_type, 19, tf>;

    template<bool tf>
    using AESEN = Register::Combo_Bit<ahb2enr_reg_type, 24, tf>;

    template<bool tf>
    using RNGEN = Register::Combo_Bit<ahb2enr_reg_type, 26, tf>;

} // RCC_AHB2ENR
namespace RCC_AHB3ENR {

    enum class ahb3enr_reg_type {};

    template<bool tf>
    using FMCEN = Register::Combo_Bit<ahb3enr_reg_type, 0, tf>;

    template<bool tf>
    using QSPIEN = Register::Combo_Bit<ahb3enr_reg_type, 8, tf>;

} // RCC_AHB3ENR
namespace RCC_APB1ENR1 {

    enum class apb1enr1_reg_type {};

    template<bool tf>
    using TIM2EN = Register::Combo_Bit<apb1enr1_reg_type, 0, tf>;

    template<bool tf>
    using TIM3EN = Register::Combo_Bit<apb1enr1_reg_type, 1, tf>;

    template<bool tf>
    using TIM4EN = Register::Combo_Bit<apb1enr1_reg_type, 2, tf>;

    template<bool tf>
    using TIM5EN = Register::Combo_Bit<apb1enr1_reg_type, 3, tf>;

    template<bool tf>
    using TIM6EN = Register::Combo_Bit<apb1enr1_reg_type, 4, tf>;

    template<bool tf>
    using TIM7EN = Register::Combo_Bit<apb1enr1_reg_type, 5, tf>;

    template<bool tf>
    using CRSEN = Register::Combo_Bit<apb1enr1_reg_type, 8, tf>;

    template<bool tf>
    using RTCAPBEN = Register::Combo_Bit<apb1enr1_reg_type, 10, tf>;

    template<bool tf>
    using WWDGEN = Register::Combo_Bit<apb1enr1_reg_type, 11, tf>;

    template<bool tf>
    using SPI2EN = Register::Combo_Bit<apb1enr1_reg_type, 14, tf>;

    template<bool tf>
    using SPI3EN = Register::Combo_Bit<apb1enr1_reg_type, 15, tf>;

    template<bool tf>
    using USART2EN = Register::Combo_Bit<apb1enr1_reg_type, 17, tf>;

    template<bool tf>
    using USART3EN = Register::Combo_Bit<apb1enr1_reg_type, 18, tf>;

    template<bool tf>
    using UART4EN = Register::Combo_Bit<apb1enr1_reg_type, 19, tf>;

    template<bool tf>
    using UART5EN = Register::Combo_Bit<apb1enr1_reg_type, 20, tf>;

    template<bool tf>
    using I2C1EN = Register::Combo_Bit<apb1enr1_reg_type, 21, tf>;

    template<bool tf>
    using I2C2EN = Register::Combo_Bit<apb1enr1_reg_type, 22, tf>;

    template<bool tf>
    using USBEN = Register::Combo_Bit<apb1enr1_reg_type, 23, tf>;

    template<bool tf>
    using FDCANEN = Register::Combo_Bit<apb1enr1_reg_type, 25, tf>;

    template<bool tf>
    using PWREN = Register::Combo_Bit<apb1enr1_reg_type, 28, tf>;

    template<bool tf>
    using I2C3EN = Register::Combo_Bit<apb1enr1_reg_type, 30, tf>;

    template<bool tf>
    using LPTIM1EN = Register::Combo_Bit<apb1enr1_reg_type, 31, tf>;

} // RCC_APB1ENR1
namespace RCC_APB1ENR2 {

    enum class apb1enr2_reg_type {};

    template<bool tf>
    using LPUART1EN = Register::Combo_Bit<apb1enr2_reg_type, 0, tf>;

    template<bool tf>
    using I2C4EN = Register::Combo_Bit<apb1enr2_reg_type, 1, tf>;

    template<bool tf>
    using UCPD1EN = Register::Combo_Bit<apb1enr2_reg_type, 8, tf>;

} // RCC_APB1ENR2
namespace RCC_APB2ENR {

    enum class apb2enr_reg_type {};

    template<bool tf>
    using SYSCFGEN = Register::Combo_Bit<apb2enr_reg_type, 0, tf>;

    template<bool tf>
    using TIM1EN = Register::Combo_Bit<apb2enr_reg_type, 11, tf>;

    template<bool tf>
    using SPI1EN = Register::Combo_Bit<apb2enr_reg_type, 12, tf>;

    template<bool tf>
    using TIM8EN = Register::Combo_Bit<apb2enr_reg_type, 13, tf>;

    template<bool tf>
    using USART1EN = Register::Combo_Bit<apb2enr_reg_type, 14, tf>;

    template<bool tf>
    using SPI4EN = Register::Combo_Bit<apb2enr_reg_type, 15, tf>;

    template<bool tf>
    using TIM15EN = Register::Combo_Bit<apb2enr_reg_type, 16, tf>;

    template<bool tf>
    using TIM16EN = Register::Combo_Bit<apb2enr_reg_type, 17, tf>;

    template<bool tf>
    using TIM17EN = Register::Combo_Bit<apb2enr_reg_type, 18, tf>;

    template<bool tf>
    using TIM20EN = Register::Combo_Bit<apb2enr_reg_type, 20, tf>;

    template<bool tf>
    using SAI1EN = Register::Combo_Bit<apb2enr_reg_type, 21, tf>;

    template<bool tf>
    using HRTIM1EN = Register::Combo_Bit<apb2enr_reg_type, 26, tf>;

} // RCC_APB2ENR
namespace RCC_AHB1SMENR {

    enum class ahb1smenr_reg_type {};

    template<bool tf>
    using DMA1SMEN = Register::Combo_Bit<ahb1smenr_reg_type, 0, tf>;

    template<bool tf>
    using DMA2SMEN = Register::Combo_Bit<ahb1smenr_reg_type, 1, tf>;

    template<bool tf>
    using DMAMUX1SMEN = Register::Combo_Bit<ahb1smenr_reg_type, 2, tf>;

    template<bool tf>
    using CORDICSMEN = Register::Combo_Bit<ahb1smenr_reg_type, 3, tf>;

    template<bool tf>
    using FMACSMEN = Register::Combo_Bit<ahb1smenr_reg_type, 4, tf>;

    template<bool tf>
    using FLASHSMEN = Register::Combo_Bit<ahb1smenr_reg_type, 8, tf>;

    template<bool tf>
    using SRAM1SMEN = Register::Combo_Bit<ahb1smenr_reg_type, 9, tf>;

    template<bool tf>
    using CRCSMEN = Register::Combo_Bit<ahb1smenr_reg_type, 12, tf>;

} // RCC_AHB1SMENR
namespace RCC_AHB2SMENR {

    enum class ahb2smenr_reg_type {};

    template<bool tf>
    using GPIOASMEN = Register::Combo_Bit<ahb2smenr_reg_type, 0, tf>;

    template<bool tf>
    using GPIOBSMEN = Register::Combo_Bit<ahb2smenr_reg_type, 1, tf>;

    template<bool tf>
    using GPIOCSMEN = Register::Combo_Bit<ahb2smenr_reg_type, 2, tf>;

    template<bool tf>
    using GPIODSMEN = Register::Combo_Bit<ahb2smenr_reg_type, 3, tf>;

    template<bool tf>
    using GPIOESMEN = Register::Combo_Bit<ahb2smenr_reg_type, 4, tf>;

    template<bool tf>
    using GPIOFSMEN = Register::Combo_Bit<ahb2smenr_reg_type, 5, tf>;

    template<bool tf>
    using GPIOGSMEN = Register::Combo_Bit<ahb2smenr_reg_type, 6, tf>;

    template<bool tf>
    using CCMSRAMSMEN = Register::Combo_Bit<ahb2smenr_reg_type, 9, tf>;

    template<bool tf>
    using SRAM2SMEN = Register::Combo_Bit<ahb2smenr_reg_type, 10, tf>;

    template<bool tf>
    using ADC12SMEN = Register::Combo_Bit<ahb2smenr_reg_type, 13, tf>;

    template<bool tf>
    using ADC345SMEN = Register::Combo_Bit<ahb2smenr_reg_type, 14, tf>;

    template<bool tf>
    using DAC1SMEN = Register::Combo_Bit<ahb2smenr_reg_type, 16, tf>;

    template<bool tf>
    using DAC2SMEN = Register::Combo_Bit<ahb2smenr_reg_type, 17, tf>;

    template<bool tf>
    using DAC3SMEN = Register::Combo_Bit<ahb2smenr_reg_type, 18, tf>;

    template<bool tf>
    using DAC4SMEN = Register::Combo_Bit<ahb2smenr_reg_type, 19, tf>;

    template<bool tf>
    using AESSMEN = Register::Combo_Bit<ahb2smenr_reg_type, 24, tf>;

    template<bool tf>
    using RNGEN = Register::Combo_Bit<ahb2smenr_reg_type, 26, tf>;

} // RCC_AHB2SMENR
namespace RCC_AHB3SMENR {

    enum class ahb3smenr_reg_type {};

    template<bool tf>
    using FMCSMEN = Register::Combo_Bit<ahb3smenr_reg_type, 0, tf>;

    template<bool tf>
    using QSPISMEN = Register::Combo_Bit<ahb3smenr_reg_type, 8, tf>;

} // RCC_AHB3SMENR
namespace RCC_APB1SMENR1 {

    enum class apb1smenr1_reg_type {};

    template<bool tf>
    using TIM2SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 0, tf>;

    template<bool tf>
    using TIM3SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 1, tf>;

    template<bool tf>
    using TIM4SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 2, tf>;

    template<bool tf>
    using TIM5SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 3, tf>;

    template<bool tf>
    using TIM6SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 4, tf>;

    template<bool tf>
    using TIM7SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 5, tf>;

    template<bool tf>
    using CRSSMEN = Register::Combo_Bit<apb1smenr1_reg_type, 8, tf>;

    template<bool tf>
    using RTCAPBSMEN = Register::Combo_Bit<apb1smenr1_reg_type, 10, tf>;

    template<bool tf>
    using WWDGSMEN = Register::Combo_Bit<apb1smenr1_reg_type, 11, tf>;

    template<bool tf>
    using SPI2SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 14, tf>;

    template<bool tf>
    using SPI3SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 15, tf>;

    template<bool tf>
    using USART2SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 17, tf>;

    template<bool tf>
    using USART3SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 18, tf>;

    template<bool tf>
    using UART4SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 19, tf>;

    template<bool tf>
    using UART5SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 20, tf>;

    template<bool tf>
    using I2C1SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 21, tf>;

    template<bool tf>
    using I2C2SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 22, tf>;

    template<bool tf>
    using USBSMEN = Register::Combo_Bit<apb1smenr1_reg_type, 23, tf>;

    template<bool tf>
    using FDCANSMEN = Register::Combo_Bit<apb1smenr1_reg_type, 25, tf>;

    template<bool tf>
    using PWRSMEN = Register::Combo_Bit<apb1smenr1_reg_type, 28, tf>;

    template<bool tf>
    using I2C3SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 30, tf>;

    template<bool tf>
    using LPTIM1SMEN = Register::Combo_Bit<apb1smenr1_reg_type, 31, tf>;

} // RCC_APB1SMENR1
namespace RCC_APB1SMENR2 {

    enum class apb1smenr2_reg_type {};

    template<bool tf>
    using LPUART1SMEN = Register::Combo_Bit<apb1smenr2_reg_type, 0, tf>;

    template<bool tf>
    using I2C4SMEN = Register::Combo_Bit<apb1smenr2_reg_type, 1, tf>;

    template<bool tf>
    using UCPD1SMEN = Register::Combo_Bit<apb1smenr2_reg_type, 8, tf>;

} // RCC_APB1SMENR2
namespace RCC_APB2SMENR {

    enum class apb2smenr_reg_type {};

    template<bool tf>
    using SYSCFGSMEN = Register::Combo_Bit<apb2smenr_reg_type, 0, tf>;

    template<bool tf>
    using TIM1SMEN = Register::Combo_Bit<apb2smenr_reg_type, 11, tf>;

    template<bool tf>
    using SPI1SMEN = Register::Combo_Bit<apb2smenr_reg_type, 12, tf>;

    template<bool tf>
    using TIM8SMEN = Register::Combo_Bit<apb2smenr_reg_type, 13, tf>;

    template<bool tf>
    using USART1SMEN = Register::Combo_Bit<apb2smenr_reg_type, 14, tf>;

    template<bool tf>
    using SPI4SMEN = Register::Combo_Bit<apb2smenr_reg_type, 15, tf>;

    template<bool tf>
    using TIM15SMEN = Register::Combo_Bit<apb2smenr_reg_type, 16, tf>;

    template<bool tf>
    using TIM16SMEN = Register::Combo_Bit<apb2smenr_reg_type, 17, tf>;

    template<bool tf>
    using TIM17SMEN = Register::Combo_Bit<apb2smenr_reg_type, 18, tf>;

    template<bool tf>
    using TIM20SMEN = Register::Combo_Bit<apb2smenr_reg_type, 20, tf>;

    template<bool tf>
    using SAI1SMEN = Register::Combo_Bit<apb2smenr_reg_type, 21, tf>;

    template<bool tf>
    using HRTIM1SMEN = Register::Combo_Bit<apb2smenr_reg_type, 26, tf>;

} // RCC_APB2SMENR
namespace RCC_CCIPR {

    enum class ccipr_reg_type {};

    template<CCIPR_USART1SEL_T val>
    using USART1SEL = Register::Combo_Bitfield<ccipr_reg_type, 0, 2, CCIPR_USART1SEL_T, val>;

    template<CCIPR_USART2SEL_T val>
    using USART2SEL = Register::Combo_Bitfield<ccipr_reg_type, 2, 2, CCIPR_USART2SEL_T, val>;

    template<CCIPR_USART3SEL_T val>
    using USART3SEL = Register::Combo_Bitfield<ccipr_reg_type, 4, 2, CCIPR_USART3SEL_T, val>;

    template<CCIPR_UART4SEL_T val>
    using UART4SEL = Register::Combo_Bitfield<ccipr_reg_type, 6, 2, CCIPR_UART4SEL_T, val>;

    template<CCIPR_UART5SEL_T val>
    using UART5SEL = Register::Combo_Bitfield<ccipr_reg_type, 8, 2, CCIPR_UART5SEL_T, val>;

    template<CCIPR_LPUART1SEL_T val>
    using LPUART1SEL = Register::Combo_Bitfield<ccipr_reg_type, 10, 2, CCIPR_LPUART1SEL_T, val>;

    template<CCIPR_I2C1SEL_T val>
    using I2C1SEL = Register::Combo_Bitfield<ccipr_reg_type, 12, 2, CCIPR_I2C1SEL_T, val>;

    template<CCIPR_I2C2SEL_T val>
    using I2C2SEL = Register::Combo_Bitfield<ccipr_reg_type, 14, 2, CCIPR_I2C2SEL_T, val>;

    template<CCIPR_I2C3SEL_T val>
    using I2C3SEL = Register::Combo_Bitfield<ccipr_reg_type, 16, 2, CCIPR_I2C3SEL_T, val>;

    template<CCIPR_LPTIM1SEL_T val>
    using LPTIM1SEL = Register::Combo_Bitfield<ccipr_reg_type, 18, 2, CCIPR_LPTIM1SEL_T, val>;

    template<CCIPR_SAI1SEL_T val>
    using SAI1SEL = Register::Combo_Bitfield<ccipr_reg_type, 20, 2, CCIPR_SAI1SEL_T, val>;

    template<CCIPR_I2S23SEL_T val>
    using I2S23SEL = Register::Combo_Bitfield<ccipr_reg_type, 22, 2, CCIPR_I2S23SEL_T, val>;

    template<CCIPR_FDCANSEL_T val>
    using FDCANSEL = Register::Combo_Bitfield<ccipr_reg_type, 24, 2, CCIPR_FDCANSEL_T, val>;

    template<CCIPR_CLK48SEL_T val>
    using CLK48SEL = Register::Combo_Bitfield<ccipr_reg_type, 26, 2, CCIPR_CLK48SEL_T, val>;

    template<CCIPR_ADC12SEL_T val>
    using ADC12SEL = Register::Combo_Bitfield<ccipr_reg_type, 28, 2, CCIPR_ADC12SEL_T, val>;

    template<CCIPR_ADC345SEL_T val>
    using ADC345SEL = Register::Combo_Bitfield<ccipr_reg_type, 30, 2, CCIPR_ADC345SEL_T, val>;

} // RCC_CCIPR
namespace RCC_BDCR {

    enum class bdcr_reg_type {};

    template<bool tf>
    using LSEON = Register::Combo_Bit<bdcr_reg_type, 0, tf>;

    template<bool tf>
    using LSERDY = Register::Combo_Bit<bdcr_reg_type, 1, tf>;

    template<bool tf>
    using LSEBYP = Register::Combo_Bit<bdcr_reg_type, 2, tf>;

    template<BDCR_LSEDRV_T val>
    using LSEDRV = Register::Combo_Bitfield<bdcr_reg_type, 3, 2, BDCR_LSEDRV_T, val>;

    template<bool tf>
    using LSECSSON = Register::Combo_Bit<bdcr_reg_type, 5, tf>;

    template<bool tf>
    using LSECSSD = Register::Combo_Bit<bdcr_reg_type, 6, tf>;

    template<BDCR_RTCSEL_T val>
    using RTCSEL = Register::Combo_Bitfield<bdcr_reg_type, 8, 2, BDCR_RTCSEL_T, val>;

    template<bool tf>
    using RTCEN = Register::Combo_Bit<bdcr_reg_type, 15, tf>;

    template<bool tf>
    using BDRST = Register::Combo_Bit<bdcr_reg_type, 16, tf>;

    template<bool tf>
    using LSCOEN = Register::Combo_Bit<bdcr_reg_type, 24, tf>;

    template<bool tf>
    using LSCOSEL = Register::Combo_Bit<bdcr_reg_type, 25, tf>;

} // RCC_BDCR
namespace RCC_CSR {

    enum class csr_reg_type {};

    template<bool tf>
    using LSION = Register::Combo_Bit<csr_reg_type, 0, tf>;

    template<bool tf>
    using LSIRDY = Register::Combo_Bit<csr_reg_type, 1, tf>;

    template<bool tf>
    using RMVF = Register::Combo_Bit<csr_reg_type, 23, tf>;

    template<bool tf>
    using OBLRSTF = Register::Combo_Bit<csr_reg_type, 25, tf>;

    template<bool tf>
    using PINRSTF = Register::Combo_Bit<csr_reg_type, 26, tf>;

    template<bool tf>
    using BORRSTF = Register::Combo_Bit<csr_reg_type, 27, tf>;

    template<bool tf>
    using SFTRSTF = Register::Combo_Bit<csr_reg_type, 28, tf>;

    template<bool tf>
    using IWDGRSTF = Register::Combo_Bit<csr_reg_type, 29, tf>;

    template<bool tf>
    using WWDGRSTF = Register::Combo_Bit<csr_reg_type, 30, tf>;

    template<bool tf>
    using LPWRRSTF = Register::Combo_Bit<csr_reg_type, 31, tf>;

} // RCC_CSR
namespace RCC_CRRCR {

    enum class crrcr_reg_type {};

    template<bool tf>
    using HSI48ON = Register::Combo_Bit<crrcr_reg_type, 0, tf>;

    template<bool tf>
    using HSI48RDY = Register::Combo_Bit<crrcr_reg_type, 1, tf>;

    template<CRRCR_HSI48CAL_T val>
    using HSI48CAL = Register::Combo_Bitfield<crrcr_reg_type, 7, 9, CRRCR_HSI48CAL_T, val>;

} // RCC_CRRCR
namespace RCC_CCIPR2 {

    enum class ccipr2_reg_type {};

    template<CCIPR2_I2C4SEL_T val>
    using I2C4SEL = Register::Combo_Bitfield<ccipr2_reg_type, 0, 2, CCIPR2_I2C4SEL_T, val>;

    template<CCIPR2_QSPISEL_T val>
    using QSPISEL = Register::Combo_Bitfield<ccipr2_reg_type, 20, 2, CCIPR2_QSPISEL_T, val>;

} // RCC_CCIPR2
template<uint32_t BASE_ADDRESS>
class RCC {
public:
    static const uint32_t CR_Offset = 0x0000;
    static const uint32_t ICSCR_Offset = 0x0004;
    static const uint32_t CFGR_Offset = 0x0008;
    static const uint32_t PLLCFGR_Offset = 0x000C;
    static const uint32_t CIER_Offset = 0x0018;
    static const uint32_t CIFR_Offset = 0x001C;
    static const uint32_t CICR_Offset = 0x0020;
    static const uint32_t AHB1RSTR_Offset = 0x0028;
    static const uint32_t AHB2RSTR_Offset = 0x002C;
    static const uint32_t AHB3RSTR_Offset = 0x0030;
    static const uint32_t APB1RSTR1_Offset = 0x0038;
    static const uint32_t APB1RSTR2_Offset = 0x003C;
    static const uint32_t APB2RSTR_Offset = 0x0040;
    static const uint32_t AHB1ENR_Offset = 0x0048;
    static const uint32_t AHB2ENR_Offset = 0x004C;
    static const uint32_t AHB3ENR_Offset = 0x0050;
    static const uint32_t APB1ENR1_Offset = 0x0058;
    static const uint32_t APB1ENR2_Offset = 0x005C;
    static const uint32_t APB2ENR_Offset = 0x0060;
    static const uint32_t AHB1SMENR_Offset = 0x0068;
    static const uint32_t AHB2SMENR_Offset = 0x006C;
    static const uint32_t AHB3SMENR_Offset = 0x0070;
    static const uint32_t APB1SMENR1_Offset = 0x0078;
    static const uint32_t APB1SMENR2_Offset = 0x007C;
    static const uint32_t APB2SMENR_Offset = 0x0080;
    static const uint32_t CCIPR_Offset = 0x0088;
    static const uint32_t BDCR_Offset = 0x0090;
    static const uint32_t CSR_Offset = 0x0094;
    static const uint32_t CRRCR_Offset = 0x0098;
    static const uint32_t CCIPR2_Offset = 0x009C;

    RCC() = default;
    RCC( const RCC& ) = delete;
    const RCC& operator=( const RCC& ) = delete;

    class CR_T : public Register::Register<RCC_CR::cr_reg_type, BASE_ADDRESS + CR_Offset> {
    // Clock control register
    public:
        Register::Bit<BASE_ADDRESS + CR_Offset, 8> HSION; /* HSI16 clock enable. Set and cleared by software.Cleared by hardware to stop the HSI16 oscillator when entering Stop, Standby or Shutdown mode.. Set by hardware to force the HSI16 oscillator ON when STOPWUCK=1 or HSIASFS = 1 when leaving Stop modes, or in case of failure of the HSE crystal oscillator.This bit is set by hardware if the HSI16 is used directly or indirectly as system clock. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 9> HSIKERON; /* HSI16 always enable for peripheral kernels.. Set and cleared by software to force HSI16 ON even in Stop modes. The HSI16 can only feed USARTs and I<sup>2</sup>Cs peripherals configured with HSI16 as kernel clock. Keeping the HSI16 ON in Stop mode allows to avoid slowing down the communication speed because of the HSI16 startup time. This bit has no effect on HSION value. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 10> HSIRDY; /* HSI16 clock ready flag. Set by hardware to indicate that HSI16 oscillator is stable. This bit is set only when HSI16 is enabled by software by setting HSION. Note: Once the HSION bit is cleared, HSIRDY goes low after 6 HSI16 clock cycles. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 16> HSEON; /* HSE clock enable. Set and cleared by software.Cleared by hardware to stop the HSE oscillator when entering Stop, Standby or Shutdown mode. This bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 17> HSERDY; /* HSE clock ready flag. Set by hardware to indicate that the HSE oscillator is stable. Note: Once the HSEON bit is cleared, HSERDY goes low after 6 HSE clock cycles. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 18> HSEBYP; /* HSE crystal oscillator bypass. Set and cleared by software to bypass the oscillator with an external clock. The external clock must be enabled with the HSEON bit set, to be used by the device. The HSEBYP bit can be written only if the HSE oscillator is disabled. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 19> CSSON; /* Clock security system enableSet by software to enable the clock security system. When CSSON is set, the clock detector is enabled by hardware when the HSE oscillator is ready, and disabled by hardware if a HSE clock failure is detected. This bit is set only and is cleared by reset. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 24> PLLON; /* Main PLL enable. Set and cleared by software to enable the main PLL.Cleared by hardware when entering Stop, Standby or Shutdown mode. This bit cannot be reset if the PLL clock is used as the system clock. */
        Register::Bit<BASE_ADDRESS + CR_Offset, 25> PLLRDY; /* Main PLL clock ready flag. Set by hardware to indicate that the main PLL is locked. */
    };

    class ICSCR_T : public Register::Register<RCC_ICSCR::icscr_reg_type, BASE_ADDRESS + ICSCR_Offset> {
    // Internal clock sources calibration register
    public:
        Register::Bitfield<BASE_ADDRESS + ICSCR_Offset, 16, 8, ICSCR_HSICAL_T> HSICAL; /* HSI16 clock calibrationThese bits are initialized at startup with the factory-programmed HSI16 calibration trim value. When HSITRIM is written, HSICAL is updated with the sum of HSITRIM and the factory trim value. */
        Register::Bitfield<BASE_ADDRESS + ICSCR_Offset, 24, 7, ICSCR_HSITRIM_T> HSITRIM; /* HSI16 clock trimmingThese bits provide an additional user-programmable trimming value that is added to the HSICAL[7:0] bits. It can be programmed to adjust to variations in voltage and temperature that influence the frequency of the HSI16.The default value is 16, which, when added to the HSICAL value, should trim the HSI16 to 16 MHz � 1 %. */
    };

    class CFGR_T : public Register::Register<RCC_CFGR::cfgr_reg_type, BASE_ADDRESS + CFGR_Offset> {
    // Clock configuration register
    public:
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 0, 2, CFGR_SW_T> SW; /* System clock switch. Set and cleared by software to select system clock source (SYSCLK).Configured by hardware to force HSI16 oscillator selection when exiting stop and standby modes or in case of failure of the HSE oscillator. */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 2, 2, CFGR_SWS_T> SWS; /* System clock switch status. Set and cleared by hardware to indicate which clock source is used as system clock. */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 4, 4, CFGR_HPRE_T> HPRE; /* AHB prescaler. Set and cleared by software to control the division factor of the AHB clock.Note: Depending on the device voltage range, the software has to set correctly these bits to ensure that the system frequency does not exceed the maximum allowed frequency (for more details please refer to Section 6.1.5: Dynamic voltage scaling management). After a write operation to these bits and before decreasing the voltage range, this register must be read to be sure that the new value has been taken into account.0xxx: SYSCLK not divided */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 8, 3, CFGR_PPRE1_T> PPRE1; /* APB1 prescaler. Set and cleared by software to control the division factor of the APB1 clock (PCLK1).0xx: HCLK not divided */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 11, 3, CFGR_PPRE2_T> PPRE2; /* APB2 prescaler. Set and cleared by software to control the division factor of the APB2 clock (PCLK2).0xx: HCLK not divided */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 24, 4, CFGR_MCOSEL_T> MCOSEL; /* Microcontroller clock output . Set and cleared by software.Others: ReservedNote: This clock output may have some truncated cycles at startup or during MCO clock source switching. */
        Register::Bitfield<BASE_ADDRESS + CFGR_Offset, 28, 3, CFGR_MCOPRE_T> MCOPRE; /* Microcontroller clock output prescaler. These bits are set and cleared by software.It is highly recommended to change this prescaler before MCO output is enabled.Others: not allowed */
    };

    class PLLCFGR_T : public Register::Register<RCC_PLLCFGR::pllcfgr_reg_type, BASE_ADDRESS + PLLCFGR_Offset> {
    // PLL configuration register
    public:
        Register::Bitfield<BASE_ADDRESS + PLLCFGR_Offset, 0, 2, PLLCFGR_PLLSRC_T> PLLSRC; /* Main PLL entry clock source. Set and cleared by software to select PLL clock source. These bits can be written only when PLL is disabled.In order to save power, when no PLL is used, the value of PLLSRC should be 00. */
        Register::Bitfield<BASE_ADDRESS + PLLCFGR_Offset, 4, 4, PLLCFGR_PLLM_T> PLLM; /* Division factor for the main PLL input clock. Set and cleared by software to divide the PLL input clock before the VCO. These bits can be written only when all PLLs are disabled.VCO input frequency = PLL input clock frequency / PLLM with 1 <= PLLM <= 16...Note: The software has to set these bits correctly to ensure that the VCO input frequency is within the range defined in the device datasheet. */
        Register::Bitfield<BASE_ADDRESS + PLLCFGR_Offset, 8, 7, PLLCFGR_PLLN_T> PLLN; /* Main PLL multiplication factor for VCO. Set and cleared by software to control the multiplication factor of the VCO. These bits can be written only when the PLL is disabled. VCO output frequency = VCO input frequency x PLLN with 8 =< PLLN =< 127......Note: The software has to set correctly these bits to assure that the VCO output frequency is within the range defined in the device datasheet. */
        Register::Bit<BASE_ADDRESS + PLLCFGR_Offset, 16> PLLPEN; /* Main PLL PLL “P” clock output enable. Set and reset by software to enable the PLL “P” clock output of the PLL.In order to save power, when the PLL “P” clock output of the PLL is not used, the value of PLLPEN should be 0. */
        Register::Bit<BASE_ADDRESS + PLLCFGR_Offset, 17> PLLP; /* Main PLL division factor for PLL “P” clock.. Set and cleared by software to control the frequency of the main PLL output clock PLL “P” clock. These bits can be written only if PLL is disabled.When the PLLPDIV[4:0] is set to “00000”PLL “P” output clock frequency = VCO frequency / PLLP with PLLP =7, or 17Note: The software has to set these bits correctly not to exceed 170 MHz on this domain. */
        Register::Bit<BASE_ADDRESS + PLLCFGR_Offset, 20> PLLQEN; /* Main PLL “Q” clock output enable. Set and reset by software to enable the PLL “Q” clock output of the PLL.In order to save power, when the PLL “Q” clock output of the PLL is not used, the value of PLLQEN should be 0. */
        Register::Bitfield<BASE_ADDRESS + PLLCFGR_Offset, 21, 2, PLLCFGR_PLLQ_T> PLLQ; /* Main PLL division factor for PLL “Q” clock.. Set and cleared by software to control the frequency of the main PLL output clock PLL “Q” clock. This output can be selected for USB, RNG, SAI (48 MHz clock). These bits can be written only if PLL is disabled.PLL “Q” output clock frequency = VCO frequency / PLLQ with PLLQ = 2, 4, 6, or 8Note: The software has to set these bits correctly not to exceed 170 MHz on this domain. */
        Register::Bit<BASE_ADDRESS + PLLCFGR_Offset, 24> PLLREN; /* PLL “R” clock output enable. Set and reset by software to enable the PLL “R” clock output of the PLL (used as system clock).This bit cannot be written when PLL “R” clock output of the PLL is used as System Clock.In order to save power, when the PLL “R” clock output of the PLL is not used, the value of PLLREN should be 0. */
        Register::Bitfield<BASE_ADDRESS + PLLCFGR_Offset, 25, 2, PLLCFGR_PLLR_T> PLLR; /* Main PLL division factor for PLL “R” clock (system clock). Set and cleared by software to control the frequency of the main PLL output clock PLLCLK. This output can be selected as system clock. These bits can be written only if PLL is disabled.PLL “R” output clock frequency = VCO frequency / PLLR with PLLR = 2, 4, 6, or 8Note: The software has to set these bits correctly not to exceed 170 MHz on this domain. */
        Register::Bitfield<BASE_ADDRESS + PLLCFGR_Offset, 27, 5, PLLCFGR_PLLPDIV_T> PLLPDIV; /* Main PLLP division factor. Set and cleared by software to control the PLL “P” frequency. PLL “P” output clock frequency = VCO frequency / PLLPDIV..... */
    };

    class CIER_T : public Register::Register<RCC_CIER::cier_reg_type, BASE_ADDRESS + CIER_Offset> {
    // Clock interrupt enable register
    public:
        Register::Bit<BASE_ADDRESS + CIER_Offset, 0> LSIRDYIE; /* LSI ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by the LSI oscillator stabilization. */
        Register::Bit<BASE_ADDRESS + CIER_Offset, 1> LSERDYIE; /* LSE ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by the LSE oscillator stabilization. */
        Register::Bit<BASE_ADDRESS + CIER_Offset, 3> HSIRDYIE; /* HSI16 ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by the HSI16 oscillator stabilization. */
        Register::Bit<BASE_ADDRESS + CIER_Offset, 4> HSERDYIE; /* HSE ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by the HSE oscillator stabilization. */
        Register::Bit<BASE_ADDRESS + CIER_Offset, 5> PLLRDYIE; /* PLL ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by PLL lock. */
        Register::Bit<BASE_ADDRESS + CIER_Offset, 9> LSECSSIE; /* LSE clock security system interrupt enable. Set and cleared by software to enable/disable interrupt caused by the clock security system on LSE. */
        Register::Bit<BASE_ADDRESS + CIER_Offset, 10> HSI48RDYIE; /* HSI48 ready interrupt enable . Set and cleared by software to enable/disable interrupt caused by the internal HSI48 oscillator. */
    };

    class CIFR_T : public Register::Register<RCC_CIFR::cifr_reg_type, BASE_ADDRESS + CIFR_Offset> {
    // Clock interrupt flag register
    public:
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 0> LSIRDYF; /* LSI ready interrupt flag. Set by hardware when the LSI clock becomes stable and LSIRDYDIE is set.Cleared by software setting the LSIRDYC bit. */
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 1> LSERDYF; /* LSE ready interrupt flag. Set by hardware when the LSE clock becomes stable and LSERDYDIE is set.Cleared by software setting the LSERDYC bit. */
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 3> HSIRDYF; /* HSI16 ready interrupt flag. Set by hardware when the HSI16 clock becomes stable and HSIRDYDIE is set in a response to setting the HSION (refer to Clock control register (RCC_CR)). When HSION is not set but the HSI16 oscillator is enabled by the peripheral through a clock request, this bit is not . Set and no interrupt is generated.Cleared by software setting the HSIRDYC bit. */
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 4> HSERDYF; /* HSE ready interrupt flag. Set by hardware when the HSE clock becomes stable and HSERDYDIE is set.Cleared by software setting the HSERDYC bit. */
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 5> PLLRDYF; /* PLL ready interrupt flag. Set by hardware when the PLL locks and PLLRDYDIE is set.Cleared by software setting the PLLRDYC bit. */
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 8> CSSF; /* Clock security system interrupt flag. Set by hardware when a failure is detected in the HSE oscillator.Cleared by software setting the CSSC bit. */
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 9> LSECSSF; /* LSE Clock security system interrupt flag. Set by hardware when a failure is detected in the LSE oscillator.Cleared by software setting the LSECSSC bit. */
        Register::Bit<BASE_ADDRESS + CIFR_Offset, 10> HSI48RDYF; /* HSI48 ready interrupt flag . Set by hardware when the HSI48 clock becomes stable and HSI48RDYIE is set in a response to setting the HSI48ON (refer to Clock recovery RC register (RCC_CRRCR)). Cleared by software setting the HSI48RDYC bit. */
    };

    class CICR_T : public Register::Register<RCC_CICR::cicr_reg_type, BASE_ADDRESS + CICR_Offset> {
    // Clock interrupt clear register
    public:
        Register::Bit<BASE_ADDRESS + CICR_Offset, 0> LSIRDYC; /* LSI ready interrupt clearThis bit is set by software to clear the LSIRDYF flag. */
        Register::Bit<BASE_ADDRESS + CICR_Offset, 1> LSERDYC; /* LSE ready interrupt clearThis bit is set by software to clear the LSERDYF flag. */
        Register::Bit<BASE_ADDRESS + CICR_Offset, 3> HSIRDYC; /* HSI16 ready interrupt clearThis bit is set software to clear the HSIRDYF flag. */
        Register::Bit<BASE_ADDRESS + CICR_Offset, 4> HSERDYC; /* HSE ready interrupt clearThis bit is set by software to clear the HSERDYF flag. */
        Register::Bit<BASE_ADDRESS + CICR_Offset, 5> PLLRDYC; /* PLL ready interrupt clearThis bit is set by software to clear the PLLRDYF flag. */
        Register::Bit<BASE_ADDRESS + CICR_Offset, 8> CSSC; /* Clock security system interrupt clearThis bit is set by software to clear the CSSF flag. */
        Register::Bit<BASE_ADDRESS + CICR_Offset, 9> LSECSSC; /* LSE Clock security system interrupt clearThis bit is set by software to clear the LSECSSF flag. */
        Register::Bit<BASE_ADDRESS + CICR_Offset, 10> HSI48RDYC; /* HSI48 oscillator ready interrupt clear This bit is set by software to clear the HSI48RDYF flag. */
    };

    class AHB1RSTR_T : public Register::Register<RCC_AHB1RSTR::ahb1rstr_reg_type, BASE_ADDRESS + AHB1RSTR_Offset> {
    // AHB1 peripheral reset register
    public:
        Register::Bit<BASE_ADDRESS + AHB1RSTR_Offset, 0> DMA1RST; /* DMA1 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1RSTR_Offset, 1> DMA2RST; /* DMA2 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1RSTR_Offset, 2> DMAMUX1RST; /* . Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1RSTR_Offset, 3> CORDICRST; /* . Set and cleared by software */
        Register::Bit<BASE_ADDRESS + AHB1RSTR_Offset, 4> FMACRST; /* . Set and cleared by software */
        Register::Bit<BASE_ADDRESS + AHB1RSTR_Offset, 8> FLASHRST; /* Flash memory interface reset. Set and cleared by software. This bit can be activated only when the Flash memory is in power down mode. */
        Register::Bit<BASE_ADDRESS + AHB1RSTR_Offset, 12> CRCRST; /* CRC reset. Set and cleared by software. */
    };

    class AHB2RSTR_T : public Register::Register<RCC_AHB2RSTR::ahb2rstr_reg_type, BASE_ADDRESS + AHB2RSTR_Offset> {
    // AHB2 peripheral reset register
    public:
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 0> GPIOARST; /* IO port A reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 1> GPIOBRST; /* IO port B reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 2> GPIOCRST; /* IO port C reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 3> GPIODRST; /* IO port D reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 4> GPIOERST; /* IO port E reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 5> GPIOFRST; /* IO port F reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 6> GPIOGRST; /* IO port G reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 13> ADC12RST; /* ADC12 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 14> ADC345RST; /* ADC345 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 16> DAC1RST; /* DAC1 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 17> DAC2RST; /* DAC2 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 18> DAC3RST; /* DAC3 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 19> DAC4RST; /* DAC4 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 24> AESRST; /* AESRST reset . Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2RSTR_Offset, 26> RNGRST; /* RNG reset. Set and cleared by software. */
    };

    class AHB3RSTR_T : public Register::Register<RCC_AHB3RSTR::ahb3rstr_reg_type, BASE_ADDRESS + AHB3RSTR_Offset> {
    // AHB3 peripheral reset register
    public:
        Register::Bit<BASE_ADDRESS + AHB3RSTR_Offset, 0> FMCRST; /* Flexible static memory controller reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB3RSTR_Offset, 8> QSPIRST; /* QUADSPI reset. Set and cleared by software. */
    };

    class APB1RSTR1_T : public Register::Register<RCC_APB1RSTR1::apb1rstr1_reg_type, BASE_ADDRESS + APB1RSTR1_Offset> {
    // APB1 peripheral reset register 1
    public:
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 0> TIM2RST; /* TIM2 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 1> TIM3RST; /* TIM3 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 2> TIM4RST; /* TIM3 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 3> TIM5RST; /* TIM5 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 4> TIM6RST; /* TIM6 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 5> TIM7RST; /* TIM7 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 8> CRSRST; /* CRS reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 14> SPI2RST; /* SPI2 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 15> SPI3RST; /* SPI3 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 17> USART2RST; /* USART2 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 18> USART3RST; /* USART3 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 19> UART4RST; /* UART4 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 20> UART5RST; /* UART5 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 21> I2C1RST; /* I2C1 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 22> I2C2RST; /* I2C2 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 23> USBRST; /* USB device reset. Set and reset by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 25> FDCANRST; /* FDCAN reset. Set and reset by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 28> PWRRST; /* Power interface reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 30> I2C3RST; /* I2C3 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR1_Offset, 31> LPTIM1RST; /* Low Power Timer 1 reset. Set and cleared by software. */
    };

    class APB1RSTR2_T : public Register::Register<RCC_APB1RSTR2::apb1rstr2_reg_type, BASE_ADDRESS + APB1RSTR2_Offset> {
    // APB1 peripheral reset register 2
    public:
        Register::Bit<BASE_ADDRESS + APB1RSTR2_Offset, 0> LPUART1RST; /* Low-power UART 1 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1RSTR2_Offset, 1> I2C4RST; /* I2C4 reset . Set and cleared by software */
        Register::Bit<BASE_ADDRESS + APB1RSTR2_Offset, 8> UCPD1RST; /* UCPD1 reset. Set and cleared by software. */
    };

    class APB2RSTR_T : public Register::Register<RCC_APB2RSTR::apb2rstr_reg_type, BASE_ADDRESS + APB2RSTR_Offset> {
    // APB2 peripheral reset register
    public:
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 0> SYSCFGRST; /* SYSCFG + COMP + OPAMP + VREFBUF reset */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 11> TIM1RST; /* TIM1 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 12> SPI1RST; /* SPI1 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 13> TIM8RST; /* TIM8 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 14> USART1RST; /* USART1 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 15> SPI4RST; /* SPI4 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 16> TIM15RST; /* TIM15 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 17> TIM16RST; /* TIM16 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 18> TIM17RST; /* TIM17 timer reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 20> TIM20RST; /* TIM20 reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 21> SAI1RST; /* Serial audio interface 1 (SAI1) reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2RSTR_Offset, 26> HRTIM1RST; /* HRTIM1 reset. Set and cleared by software. */
    };

    class AHB1ENR_T : public Register::Register<RCC_AHB1ENR::ahb1enr_reg_type, BASE_ADDRESS + AHB1ENR_Offset> {
    // AHB1 peripheral clock enable register
    public:
        Register::Bit<BASE_ADDRESS + AHB1ENR_Offset, 0> DMA1EN; /* DMA1 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1ENR_Offset, 1> DMA2EN; /* DMA2 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1ENR_Offset, 2> DMAMUX1EN; /* DMAMUX1 clock enable. Set and reset by software. */
        Register::Bit<BASE_ADDRESS + AHB1ENR_Offset, 3> CORDICEN; /* CORDIC clock enable. Set and reset by software. */
        Register::Bit<BASE_ADDRESS + AHB1ENR_Offset, 4> FMACEN; /* FMAC enable. Set and reset by software. */
        Register::Bit<BASE_ADDRESS + AHB1ENR_Offset, 8> FLASHEN; /* Flash memory interface clock enable. Set and cleared by software. This bit can be disabled only when the Flash is in power down mode. */
        Register::Bit<BASE_ADDRESS + AHB1ENR_Offset, 12> CRCEN; /* CRC clock enable. Set and cleared by software. */
    };

    class AHB2ENR_T : public Register::Register<RCC_AHB2ENR::ahb2enr_reg_type, BASE_ADDRESS + AHB2ENR_Offset> {
    // AHB2 peripheral clock enable register
    public:
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 0> GPIOAEN; /* IO port A clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 1> GPIOBEN; /* IO port B clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 2> GPIOCEN; /* IO port C clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 3> GPIODEN; /* IO port D clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 4> GPIOEEN; /* IO port E clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 5> GPIOFEN; /* IO port F clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 6> GPIOGEN; /* IO port G clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 13> ADC12EN; /* ADC12 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 14> ADC345EN; /* ADC345 clock enable . Set and cleared by software */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 16> DAC1EN; /* DAC1 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 17> DAC2EN; /* DAC2 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 18> DAC3EN; /* DAC3 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 19> DAC4EN; /* DAC4 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 24> AESEN; /* AES clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2ENR_Offset, 26> RNGEN; /* RNG enable. Set and cleared by software. */
    };

    class AHB3ENR_T : public Register::Register<RCC_AHB3ENR::ahb3enr_reg_type, BASE_ADDRESS + AHB3ENR_Offset> {
    // AHB3 peripheral clock enable register
    public:
        Register::Bit<BASE_ADDRESS + AHB3ENR_Offset, 0> FMCEN; /* Flexible static memory controller clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB3ENR_Offset, 8> QSPIEN; /* QUADSPI memory interface clock enable. Set and cleared by software. */
    };

    class APB1ENR1_T : public Register::Register<RCC_APB1ENR1::apb1enr1_reg_type, BASE_ADDRESS + APB1ENR1_Offset> {
    // APB1 peripheral clock enable register 1
    public:
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 0> TIM2EN; /* TIM2 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 1> TIM3EN; /* TIM3 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 2> TIM4EN; /* TIM4 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 3> TIM5EN; /* TIM5 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 4> TIM6EN; /* TIM6 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 5> TIM7EN; /* TIM7 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 8> CRSEN; /* CRS Recovery System clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 10> RTCAPBEN; /* RTC APB clock enable . Set and cleared by software */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 11> WWDGEN; /* Window watchdog clock enableSet by software to enable the window watchdog clock. Reset by hardware system reset. This bit can also be . Set by hardware if the WWDG_SW option bit is reset. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 14> SPI2EN; /* SPI2 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 15> SPI3EN; /* SPI3 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 17> USART2EN; /* USART2 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 18> USART3EN; /* USART3 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 19> UART4EN; /* UART4 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 20> UART5EN; /* UART5 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 21> I2C1EN; /* I2C1 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 22> I2C2EN; /* I2C2 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 23> USBEN; /* USB device clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 25> FDCANEN; /* FDCAN clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 28> PWREN; /* Power interface clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 30> I2C3EN; /* I2C3 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR1_Offset, 31> LPTIM1EN; /* Low power timer 1 clock enable. Set and cleared by software. */
    };

    class APB1ENR2_T : public Register::Register<RCC_APB1ENR2::apb1enr2_reg_type, BASE_ADDRESS + APB1ENR2_Offset> {
    // APB1 peripheral clock enable register 2
    public:
        Register::Bit<BASE_ADDRESS + APB1ENR2_Offset, 0> LPUART1EN; /* Low power UART 1 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1ENR2_Offset, 1> I2C4EN; /* I2C4 clock enable . Set and cleared by software */
        Register::Bit<BASE_ADDRESS + APB1ENR2_Offset, 8> UCPD1EN; /* UCPD1 clock enable. Set and cleared by software. */
    };

    class APB2ENR_T : public Register::Register<RCC_APB2ENR::apb2enr_reg_type, BASE_ADDRESS + APB2ENR_Offset> {
    // APB2 peripheral clock enable register
    public:
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 0> SYSCFGEN; /* SYSCFG + COMP + VREFBUF + OPAMP clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 11> TIM1EN; /* TIM1 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 12> SPI1EN; /* SPI1 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 13> TIM8EN; /* TIM8 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 14> USART1EN; /* USART1clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 15> SPI4EN; /* SPI4 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 16> TIM15EN; /* TIM15 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 17> TIM16EN; /* TIM16 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 18> TIM17EN; /* TIM17 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 20> TIM20EN; /* TIM20 timer clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 21> SAI1EN; /* SAI1 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2ENR_Offset, 26> HRTIM1EN; /* HRTIM1 clock enable. Set and cleared by software. */
    };

    class AHB1SMENR_T : public Register::Register<RCC_AHB1SMENR::ahb1smenr_reg_type, BASE_ADDRESS + AHB1SMENR_Offset> {
    // AHB1 peripheral clocks enable in Sleep and Stop modes register
    public:
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 0> DMA1SMEN; /* DMA1 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 1> DMA2SMEN; /* DMA2 clocks enable during Sleep and Stop modes. Set and cleared by software during Sleep mode. */
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 2> DMAMUX1SMEN; /* DMAMUX1 clock enable during Sleep and Stop modes.. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 3> CORDICSMEN; /* CORDICSM clock enable.. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 4> FMACSMEN; /* FMACSM clock enable.. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 8> FLASHSMEN; /* Flash memory interface clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 9> SRAM1SMEN; /* SRAM1 interface clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB1SMENR_Offset, 12> CRCSMEN; /* CRC clocks enable during Sleep and Stop modes. Set and cleared by software. */
    };

    class AHB2SMENR_T : public Register::Register<RCC_AHB2SMENR::ahb2smenr_reg_type, BASE_ADDRESS + AHB2SMENR_Offset> {
    // AHB2 peripheral clocks enable in Sleep and Stop modes register
    public:
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 0> GPIOASMEN; /* IO port A clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 1> GPIOBSMEN; /* IO port B clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 2> GPIOCSMEN; /* IO port C clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 3> GPIODSMEN; /* IO port D clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 4> GPIOESMEN; /* IO port E clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 5> GPIOFSMEN; /* IO port F clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 6> GPIOGSMEN; /* IO port G clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 9> CCMSRAMSMEN; /* CCM SRAM interface clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 10> SRAM2SMEN; /* SRAM2 interface clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 13> ADC12SMEN; /* ADC12 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 14> ADC345SMEN; /* ADC345 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 16> DAC1SMEN; /* DAC1 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 17> DAC2SMEN; /* DAC2 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 18> DAC3SMEN; /* DAC3 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 19> DAC4SMEN; /* DAC4 clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 24> AESSMEN; /* AESM clocks enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB2SMENR_Offset, 26> RNGEN; /* RNG enable. Set and cleared by software. */
    };

    class AHB3SMENR_T : public Register::Register<RCC_AHB3SMENR::ahb3smenr_reg_type, BASE_ADDRESS + AHB3SMENR_Offset> {
    // AHB3 peripheral clocks enable in Sleep and Stop modes register
    public:
        Register::Bit<BASE_ADDRESS + AHB3SMENR_Offset, 0> FMCSMEN; /* Flexible static memory controller clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + AHB3SMENR_Offset, 8> QSPISMEN; /* QUADSPI memory interface clock enable during Sleep and Stop modes. Set and cleared by software. */
    };

    class APB1SMENR1_T : public Register::Register<RCC_APB1SMENR1::apb1smenr1_reg_type, BASE_ADDRESS + APB1SMENR1_Offset> {
    // APB1 peripheral clocks enable in Sleep and Stop modes register 1
    public:
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 0> TIM2SMEN; /* TIM2 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 1> TIM3SMEN; /* TIM3 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 2> TIM4SMEN; /* TIM4 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 3> TIM5SMEN; /* TIM5 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 4> TIM6SMEN; /* TIM6 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 5> TIM7SMEN; /* TIM7 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 8> CRSSMEN; /* CRS timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 10> RTCAPBSMEN; /* RTC APB clock enable during Sleep and Stop modes. Set and cleared by software */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 11> WWDGSMEN; /* Window watchdog clocks enable during Sleep and Stop modes. Set and cleared by software. This bit is forced to ‘1’ by hardware when the hardware WWDG option is activated. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 14> SPI2SMEN; /* SPI2 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 15> SPI3SMEN; /* SPI3 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 17> USART2SMEN; /* USART2 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 18> USART3SMEN; /* USART3 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 19> UART4SMEN; /* UART4 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 20> UART5SMEN; /* UART5 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 21> I2C1SMEN; /* I2C1 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 22> I2C2SMEN; /* I2C2 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 23> USBSMEN; /* USB device clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 25> FDCANSMEN; /* FDCAN clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 28> PWRSMEN; /* Power interface clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 30> I2C3SMEN; /* I2C3 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR1_Offset, 31> LPTIM1SMEN; /* Low power timer 1 clocks enable during Sleep and Stop modes. Set and cleared by software. */
    };

    class APB1SMENR2_T : public Register::Register<RCC_APB1SMENR2::apb1smenr2_reg_type, BASE_ADDRESS + APB1SMENR2_Offset> {
    // APB1 peripheral clocks enable in Sleep and Stop modes register 2
    public:
        Register::Bit<BASE_ADDRESS + APB1SMENR2_Offset, 0> LPUART1SMEN; /* Low power UART 1 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB1SMENR2_Offset, 1> I2C4SMEN; /* I2C4 clocks enable during Sleep and Stop modes . Set and cleared by software */
        Register::Bit<BASE_ADDRESS + APB1SMENR2_Offset, 8> UCPD1SMEN; /* UCPD1 clocks enable during Sleep and Stop modes. Set and cleared by software. */
    };

    class APB2SMENR_T : public Register::Register<RCC_APB2SMENR::apb2smenr_reg_type, BASE_ADDRESS + APB2SMENR_Offset> {
    // APB2 peripheral clocks enable in Sleep and Stop modes register
    public:
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 0> SYSCFGSMEN; /* SYSCFG + COMP + VREFBUF + OPAMP clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 11> TIM1SMEN; /* TIM1 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 12> SPI1SMEN; /* SPI1 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 13> TIM8SMEN; /* TIM8 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 14> USART1SMEN; /* USART1clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 15> SPI4SMEN; /* SPI4 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 16> TIM15SMEN; /* TIM15 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 17> TIM16SMEN; /* TIM16 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 18> TIM17SMEN; /* TIM17 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 20> TIM20SMEN; /* TIM20 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 21> SAI1SMEN; /* SAI1 clocks enable during Sleep and Stop modes. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + APB2SMENR_Offset, 26> HRTIM1SMEN; /* HRTIM1 timer clocks enable during Sleep and Stop modes. Set and cleared by software. */
    };

    class CCIPR_T : public Register::Register<RCC_CCIPR::ccipr_reg_type, BASE_ADDRESS + CCIPR_Offset> {
    // Peripherals independent clock configuration register
    public:
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 0, 2, CCIPR_USART1SEL_T> USART1SEL; /* USART1 clock source selection. This bit is set and cleared by software to select the USART1 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 2, 2, CCIPR_USART2SEL_T> USART2SEL; /* USART2 clock source selection. This bit is set and cleared by software to select the USART2 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 4, 2, CCIPR_USART3SEL_T> USART3SEL; /* USART3 clock source selection. This bit is set and cleared by software to select the USART3 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 6, 2, CCIPR_UART4SEL_T> UART4SEL; /* UART4 clock source selection. This bit is set and cleared by software to select the UART4 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 8, 2, CCIPR_UART5SEL_T> UART5SEL; /* UART5 clock source selection. These bits are set and cleared by software to select the UART5 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 10, 2, CCIPR_LPUART1SEL_T> LPUART1SEL; /* LPUART1 clock source selection. These bits are set and cleared by software to select the LPUART1 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 12, 2, CCIPR_I2C1SEL_T> I2C1SEL; /* I2C1 clock source selection. These bits are set and cleared by software to select the I2C1 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 14, 2, CCIPR_I2C2SEL_T> I2C2SEL; /* I2C2 clock source selection. These bits are set and cleared by software to select the I2C2 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 16, 2, CCIPR_I2C3SEL_T> I2C3SEL; /* I2C3 clock source selection. These bits are set and cleared by software to select the I2C3 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 18, 2, CCIPR_LPTIM1SEL_T> LPTIM1SEL; /* Low power timer 1 clock source selection. These bits are set and cleared by software to select the LPTIM1 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 20, 2, CCIPR_SAI1SEL_T> SAI1SEL; /* clock source selection. These bits are set and cleared by software to select the SAI clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 22, 2, CCIPR_I2S23SEL_T> I2S23SEL; /* clock source selection. These bits are set and cleared by software to select the I2S23 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 24, 2, CCIPR_FDCANSEL_T> FDCANSEL; /* None */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 26, 2, CCIPR_CLK48SEL_T> CLK48SEL; /* 48 MHz clock source selection. These bits are set and cleared by software to select the 48 MHz clock source used by USB device FS and RNG. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 28, 2, CCIPR_ADC12SEL_T> ADC12SEL; /* ADC1/2 clock source selection. These bits are set and cleared by software to select the clock source used by the ADC interface. */
        Register::Bitfield<BASE_ADDRESS + CCIPR_Offset, 30, 2, CCIPR_ADC345SEL_T> ADC345SEL; /* ADC3/4/5 clock source selection. These bits are set and cleared by software to select the clock source used by the ADC345 interface. */
    };

    class BDCR_T : public Register::Register<RCC_BDCR::bdcr_reg_type, BASE_ADDRESS + BDCR_Offset> {
    // RTC domain control register
    public:
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 0> LSEON; /* LSE oscillator enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 1> LSERDY; /* LSE oscillator ready. Set and cleared by hardware to indicate when the external 32 kHz oscillator is stable. After the LSEON bit is cleared, LSERDY goes low after 6 external low-speed oscillator clock cycles. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 2> LSEBYP; /* LSE oscillator bypass. Set and cleared by software to bypass oscillator in debug mode. This bit can be written only when the external 32 kHz oscillator is disabled (LSEON=0 and LSERDY=0). */
        Register::Bitfield<BASE_ADDRESS + BDCR_Offset, 3, 2, BDCR_LSEDRV_T> LSEDRV; /* LSE oscillator drive capabilitySet by software to modulate the LSE oscillator’s drive capability. The oscillator is in Xtal mode when it is not in bypass mode. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 5> LSECSSON; /* CSS on LSE enableSet by software to enable the Clock Security System on LSE (32 kHz oscillator).LSECSSON must be enabled after the LSE oscillator is enabled (LSEON bit enabled) and ready (LSERDY flag . Set by hardware), and after the RTCSEL bit is selected.Once enabled this bit cannot be disabled, except after a LSE failure detection (LSECSSD=1). In that case the software MUST disable the LSECSSON bit. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 6> LSECSSD; /* CSS on LSE failure Detection. Set by hardware to indicate when a failure has been detected by the Clock Security Systemon the external 32 kHz oscillator (LSE). */
        Register::Bitfield<BASE_ADDRESS + BDCR_Offset, 8, 2, BDCR_RTCSEL_T> RTCSEL; /* RTC clock source selectionSet by software to select the clock source for the RTC. Once the RTC clock source has been selected, it cannot be changed anymore unless the RTC domain is reset, or unless a failure is detected on LSE (LSECSSD is set). The BDRST bit can be used to reset them. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 15> RTCEN; /* RTC clock enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 16> BDRST; /* RTC domain software reset. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 24> LSCOEN; /* Low speed clock output enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + BDCR_Offset, 25> LSCOSEL; /* Low speed clock output selection. Set and cleared by software. */
    };

    class CSR_T : public Register::Register<RCC_CSR::csr_reg_type, BASE_ADDRESS + CSR_Offset> {
    // Control/status register
    public:
        Register::Bit<BASE_ADDRESS + CSR_Offset, 0> LSION; /* LSI oscillator enable. Set and cleared by software. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 1> LSIRDY; /* LSI oscillator ready. Set and cleared by hardware to indicate when the LSI oscillator is stable. After the LSION bit is cleared, LSIRDY goes low after 3 LSI oscillator clock cycles. This bit can be set even if LSION = 0 if the LSI is requested by the Clock Security System on LSE, by the Independent Watchdog or by the RTC. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 23> RMVF; /* Remove reset flagSet by software to clear the reset flags. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 25> OBLRSTF; /* Option byte loader reset flag. Set by hardware when a reset from the Option Byte loading occurs.Cleared by writing to the RMVF bit. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 26> PINRSTF; /* Pin reset flag. Set by hardware when a reset from the NRST pin occurs.Cleared by writing to the RMVF bit. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 27> BORRSTF; /* BOR flag. Set by hardware when a BOR occurs.Cleared by writing to the RMVF bit. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 28> SFTRSTF; /* Software reset flag. Set by hardware when a software reset occurs.Cleared by writing to the RMVF bit. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 29> IWDGRSTF; /* Independent window watchdog reset flag. Set by hardware when an independent watchdog reset domain occurs.Cleared by writing to the RMVF bit. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 30> WWDGRSTF; /* Window watchdog reset flag. Set by hardware when a window watchdog reset occurs.Cleared by writing to the RMVF bit. */
        Register::Bit<BASE_ADDRESS + CSR_Offset, 31> LPWRRSTF; /* Low-power reset flag. Set by hardware when a reset occurs due to illegal Stop, Standby or Shutdown mode entry.Cleared by writing to the RMVF bit. */
    };

    class CRRCR_T : public Register::Register<RCC_CRRCR::crrcr_reg_type, BASE_ADDRESS + CRRCR_Offset> {
    // Clock recovery RC register
    public:
        Register::Bit<BASE_ADDRESS + CRRCR_Offset, 0> HSI48ON; /* HSI48 clock enable. Set and cleared by software.Cleared by hardware to stop the HSI48 when entering in Stop, Standby or Shutdown modes. */
        Register::Bit<BASE_ADDRESS + CRRCR_Offset, 1> HSI48RDY; /* HSI48 clock ready flag. Set by hardware to indicate that HSI48 oscillator is stable. This bit is set only when HSI48 is enabled by software by setting HSI48ON. */
        Register::Bitfield<BASE_ADDRESS + CRRCR_Offset, 7, 9, CRRCR_HSI48CAL_T> HSI48CAL; /* HSI48 clock calibrationThese bits are initialized at startup with the factory-programmed HSI48 calibration trim value.They are ready only. */
    };

    class CCIPR2_T : public Register::Register<RCC_CCIPR2::ccipr2_reg_type, BASE_ADDRESS + CCIPR2_Offset> {
    // Peripherals independent clock configuration register
    public:
        Register::Bitfield<BASE_ADDRESS + CCIPR2_Offset, 0, 2, CCIPR2_I2C4SEL_T> I2C4SEL; /* I2C4 clock source selection. These bits are set and cleared by software to select the I2C4 clock source. */
        Register::Bitfield<BASE_ADDRESS + CCIPR2_Offset, 20, 2, CCIPR2_QSPISEL_T> QSPISEL; /* QUADSPI clock source selection. Set and reset by software. */
    };

    CR_T CR;
    ICSCR_T ICSCR;
    CFGR_T CFGR;
    PLLCFGR_T PLLCFGR;
    CIER_T CIER;
    CIFR_T CIFR;
    CICR_T CICR;
    AHB1RSTR_T AHB1RSTR;
    AHB2RSTR_T AHB2RSTR;
    AHB3RSTR_T AHB3RSTR;
    APB1RSTR1_T APB1RSTR1;
    APB1RSTR2_T APB1RSTR2;
    APB2RSTR_T APB2RSTR;
    AHB1ENR_T AHB1ENR;
    AHB2ENR_T AHB2ENR;
    AHB3ENR_T AHB3ENR;
    APB1ENR1_T APB1ENR1;
    APB1ENR2_T APB1ENR2;
    APB2ENR_T APB2ENR;
    AHB1SMENR_T AHB1SMENR;
    AHB2SMENR_T AHB2SMENR;
    AHB3SMENR_T AHB3SMENR;
    APB1SMENR1_T APB1SMENR1;
    APB1SMENR2_T APB1SMENR2;
    APB2SMENR_T APB2SMENR;
    CCIPR_T CCIPR;
    BDCR_T BDCR;
    CSR_T CSR;
    CRRCR_T CRRCR;
    CCIPR2_T CCIPR2;
};

} // namespace STM32LIB

#endif // STM32G473XX_RCC_HPP_

