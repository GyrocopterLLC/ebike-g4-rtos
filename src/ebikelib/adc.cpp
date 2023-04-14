#include "STM32G473xx.hpp"
#include "Gpio.hpp"
#include "EbikeConfig.hpp"
#include "FreeRTOS.h"
#include "task.h"

#include "AdcHelpers.hpp"
#include "NvicHelpers.hpp"

using namespace EbikeLib;

const uint32_t Adc_Vreg_Startup_Delay = 1;

// Request IDs for the DMAMUX. Numbers are from the STM32G473 datasheet.
const uint32_t Dmamux_Req_Adc1 = 5;
const uint32_t Dmamux_Req_Adc2 = 36;
const uint32_t Dmamux_Req_Adc3 = 37;
//const uint32_t Dmamux_Req_Adc4 = 38;

const uint8_t num_adc_conversions = 10;

// Interrupt request IDs
const uint32_t ADC1_2_IRQn                 = 18;
const uint32_t ADC3_IRQn                   = 47;
const uint32_t DMA1_Channel1_IRQn          = 11;
const uint32_t DMA1_Channel2_IRQn          = 12;
const uint32_t DMA1_Channel3_IRQn          = 13;
//const uint32_t DMA1_Channel4_IRQn          = 14;

const uint32_t adc_interrupt_priority = 2;

uint16_t adc1_raw_regular_results[num_adc_conversions];
uint16_t adc2_raw_regular_results[num_adc_conversions];
uint16_t adc3_raw_regular_results[num_adc_conversions];
//uint16_t adc4_raw_regular_results[8];

uint32_t adc1_ticks = 0;
uint32_t adc2_ticks = 0;
uint32_t adc3_ticks = 0;

/**
 * Enables an ADC, checking that the ready bit shows it's good to go.
 */
template<uint32_t ADC_BASE_ADDRESS>
static void ADC_Enable() {
	auto adc = STM32LIB::ADC<ADC_BASE_ADDRESS>();
	if(adc.CR.ADEN.get() == false) {
		adc.ISR.ADRDY.set(true); // Set true to clear this bit
		adc.CR.ADEN.set(true);
		while(adc.ISR.ADRDY.get() == false) {} // wait for ADRDY bit to go true

	}
}

/*
 * Initializes four ADC units for regular and injected conversion modes.
 * All ADCs are triggered by TIM1 TRGO (should be set to CCR4)
 * ADC1 converts IC, Vbus, and Motor Temp
 * ADC2 converts IB, VA, VB, Throttle, and FET Temp
 * ADC3 converts IA and VC
 *
 * All conversions are done in regular sequence. Injected sequence is
 * not used.
 *
 * According to the errata, we should always perform two conversions
 * and throw out the second one due to instability when switching
 * inputs. The sampling switch changes to the next input in the
 * middle of a conversion, but if the next conversion is the same
 * as the current conversion, no switching will take place. Therefore,
 * we should use the first conversion of two of the same channel as the
 * best conversion.
 *
 * ADCs are all triggered together, which should help solve some of the
 * sampling switching issues. All the sampling times should be the same
 * for each channel being sampled simultaneously.
 *
 * Slot:	1		2		3		4		5
 * ADC1: 	Ic		Vbus	Vbus	MotorT	MotorT
 * ADC2:	Ib		Va		Vb		Thr		FetT
 * ADC3: 	Ia		Vc		Vc		Vc		Vc
 *
 * Note that each "slot" above is repeated 2x, so there are 10 conversions
 * in each sequence. Signals in Slot 1 have the fastest sampling time of 2.5
 * cycles (about 59ns at 42.5MHz). All of these are motor currents.
 * Signals in all other slots are set to 47.5 cycles (about 1.12us).
 * The maximum input resistance for the currents is 100 ohms. Good thing
 * we have an opamp driving them!
 * The max input resistance for the 47.5 cycle channels is 1800 to 2200 ohms,
 * depending on if the adc channel is 1-5 (fast channels) or 6+ (slow channels).
 */
void adc_init() {

	// Change GPIOs to analog mode
	gpio_mode<ADC_IC_Pin.Port, ADC_IC_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_IB_Pin.Port, ADC_IB_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_VA_Pin.Port, ADC_VA_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_VB_Pin.Port, ADC_VB_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_IA_Pin.Port, ADC_IA_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_VC_Pin.Port, ADC_VC_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_Thr_Pin.Port, ADC_Thr_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_Vbus_Pin.Port, ADC_Vbus_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_Motor_Temp_Pin.Port, ADC_Motor_Temp_Pin.Num, STM32LIB::GPIO_Mode::Analog>();
	gpio_mode<ADC_FET_Temp_Pin.Port, ADC_FET_Temp_Pin.Num, STM32LIB::GPIO_Mode::Analog>();

	// Enable clocks to the ADCs
	auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
	rcc.AHB2ENR.ADC12EN.set(true);
	rcc.AHB2ENR.ADC345EN.set(true);

	auto adc12common = STM32LIB::ADC_Common<STM32LIB::ADC12_Common_Base_Address>();
	auto adc345common = STM32LIB::ADC_Common<STM32LIB::ADC345_Common_Base_Address>();

	adc12common.CCR.VREFEN.set(true);
	adc12common.CCR.CKMODE.set(3); // clockmode is HCLK/4 (42.5MHz), synchronous mode. No jitter between trigger and starting conversions
	adc345common.CCR.VREFEN.set(true);
	adc345common.CCR.CKMODE.set(3);


	auto adc1 = STM32LIB::ADC<STM32LIB::ADC1_Base_Address>();
	auto adc2 = STM32LIB::ADC<STM32LIB::ADC2_Base_Address>();
	auto adc3 = STM32LIB::ADC<STM32LIB::ADC3_Base_Address>();
	//auto adc4 = STM32LIB::ADC<STM32LIB::ADC4_Base_Address>();

	// Take the ADCs out of deep power down
	adc1.CR.DEEPPWD.set(false);
	adc2.CR.DEEPPWD.set(false);
	adc3.CR.DEEPPWD.set(false);
//	adc4.CR.DEEPPWD.set(false);

	// Start the internal voltage regulators
	adc1.CR.ADVREGEN.set(true);
	adc2.CR.ADVREGEN.set(true);
	adc3.CR.ADVREGEN.set(true);
	//adc4.CR.ADVREGEN.set(true);

	vTaskDelay(Adc_Vreg_Startup_Delay);

	// Calibrate all ADCs
	adc1.CR.ADCAL.set(true);
	while(adc1.CR.ADCAL.get() == true) {}
	adc2.CR.ADCAL.set(true);
	while(adc2.CR.ADCAL.get() == true) {}
	adc3.CR.ADCAL.set(true);
	while(adc3.CR.ADCAL.get() == true) {}
	//adc4.CR.ADCAL.set(true);
	//while(adc4.CR.ADCAL.get() == true) {}

    // CFGR settings:   JQDIS = 1 (queue is disabled for injected conversions)
    //                  DMAEN = 1 (DMA is enabled to generate DMA requests)
    //                  DMACFG = 1 (DMA in circular mode)
	adc1.CFGR.apply<STM32LIB::ADC_CFGR::JQDIS<true>,
					STM32LIB::ADC_CFGR::DMAEN<true>,
					STM32LIB::ADC_CFGR::DMACFG<true>>();
	adc2.CFGR.apply<STM32LIB::ADC_CFGR::JQDIS<true>,
					STM32LIB::ADC_CFGR::DMAEN<true>,
					STM32LIB::ADC_CFGR::DMACFG<true>>();
	adc3.CFGR.apply<STM32LIB::ADC_CFGR::JQDIS<true>,
					STM32LIB::ADC_CFGR::DMAEN<true>,
					STM32LIB::ADC_CFGR::DMACFG<true>>();
//	adc4.CFGR.apply<STM32LIB::ADC_CFGR::JQDIS<true>,
//					STM32LIB::ADC_CFGR::DMAEN<true>,
//					STM32LIB::ADC_CFGR::DMACFG<true>>();

	adc1.CFGR2.set(0);
	adc2.CFGR2.set(0);
	adc3.CFGR2.set(0);
//	adc4.CFGR2.set(0);

    // Sampling time is 2.5 cycles for currents (about 59ns at 42.5MHz)
	// Since total conversion time is sampling + 12.5 cycles, this means
	// The Ia, Ib, Ic channels are converted in 15 cycles (about 353ns at 42.5MHz)
    // 47.5 cycles (1.12us) for all others
	// Total conversion for these channels is 47.5+12.5 = 60 cycles
	// 60 cycles at 42.5MHz = 1.41us

    // MTEMP and VBUS get 47.5 cycles
		set_sampling_time<ADC_Periph::ADC1, ADC_Motor_Temp_Channel>(4);
		set_sampling_time<ADC_Periph::ADC1, ADC_Vbus_Channel>(4);
    // FTEMP, VA, VB, and THR get 47.5 cycles
		set_sampling_time<ADC_Periph::ADC2, ADC_VA_Channel>(4);
		set_sampling_time<ADC_Periph::ADC2, ADC_VB_Channel>(4);
		set_sampling_time<ADC_Periph::ADC2, ADC_FET_Temp_Channel>(4);
		set_sampling_time<ADC_Periph::ADC2, ADC_Thr_Channel>(4);
    // VC gets 47.5 cycles
		set_sampling_time<ADC_Periph::ADC3, ADC_VC_Channel>(4);
    // VBUS gets 47.5 cycles
//		set_sampling_time<ADC_Periph::ADC4, ADC_Vbus_Channel>(4);

	// Conversion sequences!
	// Regular sequence - 10 conversions for everybody
		// ADC1 - IC, Vbus, Vbus, MotorT, MotorT
	adc1.SQR1.apply<STM32LIB::ADC_SQR1::L<num_adc_conversions-1>,
					STM32LIB::ADC_SQR1::SQ1<ADC_IC_Channel>,
					STM32LIB::ADC_SQR1::SQ2<ADC_IC_Channel>,
					STM32LIB::ADC_SQR1::SQ3<ADC_Vbus_Channel>,
					STM32LIB::ADC_SQR1::SQ4<ADC_Vbus_Channel>>();
	adc1.SQR2.apply<STM32LIB::ADC_SQR2::SQ5<ADC_Vbus_Channel>,
					STM32LIB::ADC_SQR2::SQ6<ADC_Vbus_Channel>,
					STM32LIB::ADC_SQR2::SQ7<ADC_Motor_Temp_Channel>,
					STM32LIB::ADC_SQR2::SQ8<ADC_Motor_Temp_Channel>,
					STM32LIB::ADC_SQR2::SQ9<ADC_Motor_Temp_Channel>>();
	adc1.SQR3.apply<STM32LIB::ADC_SQR3::SQ10<ADC_Motor_Temp_Channel>>();
		// ADC2 - IB, Va, Vb, Thr, FetT
	adc2.SQR1.apply<STM32LIB::ADC_SQR1::L<num_adc_conversions-1>,
					STM32LIB::ADC_SQR1::SQ1<ADC_IB_Channel>,
					STM32LIB::ADC_SQR1::SQ2<ADC_IB_Channel>,
					STM32LIB::ADC_SQR1::SQ3<ADC_VA_Channel>,
					STM32LIB::ADC_SQR1::SQ4<ADC_VA_Channel>>();
	adc2.SQR2.apply<STM32LIB::ADC_SQR2::SQ5<ADC_VB_Channel>,
					STM32LIB::ADC_SQR2::SQ6<ADC_VB_Channel>,
					STM32LIB::ADC_SQR2::SQ7<ADC_Thr_Channel>,
					STM32LIB::ADC_SQR2::SQ8<ADC_Thr_Channel>,
					STM32LIB::ADC_SQR2::SQ9<ADC_FET_Temp_Channel>>();
	adc2.SQR3.apply<STM32LIB::ADC_SQR3::SQ10<ADC_FET_Temp_Channel>>();
		// ADC3 - IA, Vc, Vc, Vc, Vc
	adc3.SQR1.apply<STM32LIB::ADC_SQR1::L<num_adc_conversions-1>,
					STM32LIB::ADC_SQR1::SQ1<ADC_IA_Channel>,
					STM32LIB::ADC_SQR1::SQ2<ADC_IA_Channel>,
					STM32LIB::ADC_SQR1::SQ3<ADC_VC_Channel>,
					STM32LIB::ADC_SQR1::SQ4<ADC_VC_Channel>>();
	adc3.SQR2.apply<STM32LIB::ADC_SQR2::SQ5<ADC_VC_Channel>,
					STM32LIB::ADC_SQR2::SQ6<ADC_VC_Channel>,
					STM32LIB::ADC_SQR2::SQ7<ADC_VC_Channel>,
					STM32LIB::ADC_SQR2::SQ8<ADC_VC_Channel>,
					STM32LIB::ADC_SQR2::SQ9<ADC_VC_Channel>>();
	adc3.SQR3.apply<STM32LIB::ADC_SQR3::SQ10<ADC_VC_Channel>>();
//    // and ADC4 converts VBUS 8 times
//	adc4.SQR1.apply<STM32LIB::ADC_SQR1::L<7>,
//					STM32LIB::ADC_SQR1::SQ1<ADC_Vbus_Channel>,
//					STM32LIB::ADC_SQR1::SQ2<ADC_Vbus_Channel>,
//					STM32LIB::ADC_SQR1::SQ3<ADC_Vbus_Channel>,
//					STM32LIB::ADC_SQR1::SQ4<ADC_Vbus_Channel>>();
//	adc4.SQR2.apply<STM32LIB::ADC_SQR2::SQ5<ADC_Vbus_Channel>,
//					STM32LIB::ADC_SQR2::SQ6<ADC_Vbus_Channel>,
//					STM32LIB::ADC_SQR2::SQ7<ADC_Vbus_Channel>,
//					STM32LIB::ADC_SQR2::SQ8<ADC_Vbus_Channel>>();

    // Injected sequences
    // ADC1, 2, and 3 convert the current sensor 2 times each
    // ADC4 doesn't have an injected sequence
    // External trigger is TIM1_TRGO, rising edge (set to oc4ref in TIM1)
//	adc1.JSQR.apply<STM32LIB::ADC_JSQR::JL<1>,
//					STM32LIB::ADC_JSQR::JEXTEN<1>,
//					STM32LIB::ADC_JSQR::JSQ1<ADC_IC_Channel>,
//					STM32LIB::ADC_JSQR::JSQ2<ADC_IC_Channel>>();
//	adc2.JSQR.apply<STM32LIB::ADC_JSQR::JL<1>,
//					STM32LIB::ADC_JSQR::JEXTEN<1>,
//					STM32LIB::ADC_JSQR::JSQ1<ADC_IB_Channel>,
//					STM32LIB::ADC_JSQR::JSQ2<ADC_IB_Channel>>();
//	adc3.JSQR.apply<STM32LIB::ADC_JSQR::JL<1>,
//					STM32LIB::ADC_JSQR::JEXTEN<1>,
//					STM32LIB::ADC_JSQR::JSQ1<ADC_IA_Channel>,
//					STM32LIB::ADC_JSQR::JSQ2<ADC_IA_Channel>>();

    // External trigger selection (regular sequence): hardware trigger on rising edge
    // of TIM1_TRGO1 (set to oc4ref in TIM1)
    // Also ignore overruns due to weird DMA crap.
	adc1.CFGR.apply<STM32LIB::ADC_CFGR::OVRMOD<true>, // overrun mode on - ADC_DR is overwritten with new data
					STM32LIB::ADC_CFGR::EXTSEL<9>, // External event = Tim1_Trgo
					STM32LIB::ADC_CFGR::EXTEN<1>>(); // External event triggered on rising edge
	adc2.CFGR.apply<STM32LIB::ADC_CFGR::OVRMOD<true>,
					STM32LIB::ADC_CFGR::EXTSEL<9>,
					STM32LIB::ADC_CFGR::EXTEN<1>>();
	adc3.CFGR.apply<STM32LIB::ADC_CFGR::OVRMOD<true>,
					STM32LIB::ADC_CFGR::EXTSEL<9>,
					STM32LIB::ADC_CFGR::EXTEN<1>>();
//	adc4.CFGR.apply<STM32LIB::ADC_CFGR::OVRMOD<true>,
//					STM32LIB::ADC_CFGR::EXTSEL<10>,
//					STM32LIB::ADC_CFGR::EXTEN<1>>();

    /*
     * Dual ADC mode settings
     * ADC1&2 are in regular sequence simultaneous. So triggers to ADC2 are actually ignored,
     * and conversions are started by ADC1. This doesn't really matter since they are both
     * set to the same external trigger.
     *
     * ADC3 runs solo. Go free!
     */
    // Enable DMA clock
	rcc.AHB1ENR.DMA1EN.set(true);
	rcc.AHB1ENR.DMAMUX1EN.set(true);
    // Configure settings on DMA channels, except for enabling the channel. That's later.
    //  --- 16-bit transfers (both MSIZE and PSIZE), memory increment mode, but not peripheral increment
    //  --- and circular mode. Direction is read from peripheral (bit is zero)
	auto dma1 = STM32LIB::DMA<STM32LIB::DMA1_Base_Address>();
	dma1.CCR1.apply<STM32LIB::DMA_CCR1::MSIZE<1>,
					STM32LIB::DMA_CCR1::PSIZE<1>,
					STM32LIB::DMA_CCR1::MINC<true>,
					STM32LIB::DMA_CCR1::CIRC<true>>();
	dma1.CCR2.apply<STM32LIB::DMA_CCR2::MSIZE<1>,
					STM32LIB::DMA_CCR2::PSIZE<1>,
					STM32LIB::DMA_CCR2::MINC<true>,
					STM32LIB::DMA_CCR2::CIRC<true>>();
	dma1.CCR3.apply<STM32LIB::DMA_CCR3::MSIZE<1>,
					STM32LIB::DMA_CCR3::PSIZE<1>,
					STM32LIB::DMA_CCR3::MINC<true>,
					STM32LIB::DMA_CCR3::CIRC<true>>();
//	dma1.CCR4.apply<STM32LIB::DMA_CCR4::MSIZE<1>,
//					STM32LIB::DMA_CCR4::PSIZE<1>,
//					STM32LIB::DMA_CCR4::MINC<true>,
//					STM32LIB::DMA_CCR4::CIRC<true>>();
	dma1.CNDTR1.NDT.set(num_adc_conversions); // each regular sequence is 10 conversions
	dma1.CNDTR2.NDT.set(num_adc_conversions);
	dma1.CNDTR3.NDT.set(num_adc_conversions);
//	dma1.CNDTR4.NDT.set(8);

	dma1.CMAR1.MA.set(reinterpret_cast<uint32_t>(&(adc1_raw_regular_results[0])));
	dma1.CMAR2.MA.set(reinterpret_cast<uint32_t>(&(adc2_raw_regular_results[0])));
	dma1.CMAR3.MA.set(reinterpret_cast<uint32_t>(&(adc3_raw_regular_results[0])));
//	dma1.CMAR4.MA.set(reinterpret_cast<uint32_t>(&(adc4_raw_regular_results[0])));

	dma1.CPAR1.PA.set(STM32LIB::ADC1_Base_Address + STM32LIB::ADC<0>::DR_Offset);
	dma1.CPAR2.PA.set(STM32LIB::ADC2_Base_Address + STM32LIB::ADC<0>::DR_Offset);
	dma1.CPAR3.PA.set(STM32LIB::ADC3_Base_Address + STM32LIB::ADC<0>::DR_Offset);
//	dma1.CPAR4.PA.set(STM32LIB::ADC4_Base_Address + STM32LIB::ADC<0>::DR_Offset);

    // Configure settings on DMAMUX. Just set the channel selection for channel 1 to ADC1, channel 2 to ADC3
    // None of the other special features (like synchronization) are needed
	auto dmamux = STM32LIB::DMAMUX<STM32LIB::DMAMUX_Base_Address>();

	dmamux.C0CR.DMAREQ_ID.set(Dmamux_Req_Adc1);
	dmamux.C1CR.DMAREQ_ID.set(Dmamux_Req_Adc2);
	dmamux.C2CR.DMAREQ_ID.set(Dmamux_Req_Adc3);
//	dmamux.C3CR.DMAREQ_ID.set(Dmamux_Req_Adc4);

    // Setup the ADC common register to enable dual mode.
//	adc12common.CCR.DUAL.set(0b00001); // 00001:Combined regular simultaneous + injected simultaneous mode
//	adc12common.CCR.DUAL.set(0b00110); // 00110: Regular simultaneous mode only


    // Apply current sensing offsets default value
    // We don't know what the calibrated zero point is yet, but it should be close
    // to the middle of the range
//    ADC_SetNull(ADC_IA, (MAXCOUNT+1)/2);
//    ADC_SetNull(ADC_IB, (MAXCOUNT+1)/2);
//    ADC_SetNull(ADC_IC, (MAXCOUNT+1)/2);

    // Interrupts - injected end of queue enabled
//    adc1.IER.JEOSIE.set(true);
//    set_interrupt_priority<ADC1_2_IRQn>(adc_interrupt_priority);
//    enable_interrupt<ADC1_2_IRQn>();
//    adc3.IER.JEOSIE.set(true);
//    set_interrupt_priority<ADC3_IRQn>(adc_interrupt_priority);
//    enable_interrupt<ADC3_IRQn>();

    // DMA interrupts - end of transfer enabled. Also enable the DMA now.
    dma1.CCR1.TCIE.set(true);
    dma1.CCR1.EN.set(true);
    dma1.CCR2.TCIE.set(true);
    dma1.CCR2.EN.set(true);
    dma1.CCR3.TCIE.set(true);
    dma1.CCR3.EN.set(true);
//    dma1.CCR4.TCIE.set(true);
//    dma1.CCR4.EN.set(true);

    set_interrupt_priority<DMA1_Channel1_IRQn>(adc_interrupt_priority);
    enable_interrupt<DMA1_Channel1_IRQn>();
    set_interrupt_priority<DMA1_Channel2_IRQn>(adc_interrupt_priority);
    enable_interrupt<DMA1_Channel2_IRQn>();
    set_interrupt_priority<DMA1_Channel3_IRQn>(adc_interrupt_priority);
    enable_interrupt<DMA1_Channel3_IRQn>();
//    set_interrupt_priority<DMA1_Channel4_IRQn>(adc_interrupt_priority);
//    enable_interrupt<DMA1_Channel4_IRQn>();

    // enable the ADCs
    ADC_Enable<STM32LIB::ADC1_Base_Address>();
    ADC_Enable<STM32LIB::ADC2_Base_Address>();
    ADC_Enable<STM32LIB::ADC3_Base_Address>();
//    ADC_Enable<STM32LIB::ADC4_Base_Address>();

    // Start conversions. Note that no conversions will take place until the hardware triggers
    // start coming in from the PWM timer.
    adc1.CR.ADSTART.set(true);
    adc2.CR.ADSTART.set(true);
    adc3.CR.ADSTART.set(true);
//    adc4.CR.ADSTART.set(true);
//    adc1.CR.JADSTART.set(true);
//    adc2.CR.JADSTART.set(true);
//    adc3.CR.JADSTART.set(true);
}

extern "C" {
// ADC interrupt vectors
void DMA1_CH1_IRQHandler(void) {
	adc1_ticks++;
	auto dma1 = STM32LIB::DMA<STM32LIB::DMA1_Base_Address>();
	dma1.IFCR.TCIF1.set(true);
}

void DMA1_CH2_IRQHandler(void) {
	adc2_ticks++;
	auto dma1 = STM32LIB::DMA<STM32LIB::DMA1_Base_Address>();
	dma1.IFCR.TCIF2.set(true);
}

void DMA1_CH3_IRQHandler(void) {
	adc3_ticks++;
	auto dma1 = STM32LIB::DMA<STM32LIB::DMA1_Base_Address>();
	dma1.IFCR.TCIF3.set(true);
}

}
