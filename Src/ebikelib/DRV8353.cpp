#include "STM32G473xx.hpp"
#include "Gpio.hpp"
#include "EbikeConfig.hpp"
#include "FreeRTOS.h"
#include "task.h"

#include "DRV8353.hpp"

using namespace EbikeLib;

DRV8353::DRV8353() {

	// ---- Init GPIO (driver enable pin, chip select pin) ----
	gpio_mode<DRV_SCK_Pin.Port, DRV_SCK_Pin.Num, STM32LIB::GPIO_Mode::Alternate_Function>();
	gpio_mode<DRV_MISO_Pin.Port, DRV_MISO_Pin.Num, STM32LIB::GPIO_Mode::Alternate_Function>();
	gpio_mode<DRV_MOSI_Pin.Port, DRV_MOSI_Pin.Num, STM32LIB::GPIO_Mode::Alternate_Function>();
	gpio_mode<DRV_CS_Pin.Port, DRV_CS_Pin.Num, STM32LIB::GPIO_Mode::Output>();
	gpio_mode<DRV_EN_Pin.Port, DRV_EN_Pin.Num, STM32LIB::GPIO_Mode::Output>();
	gpio_af<DRV_SCK_Pin.Port, DRV_SCK_Pin.Num, Spi_SCK_Af_Num>();
	gpio_af<DRV_MISO_Pin.Port, DRV_MISO_Pin.Num, Spi_MISO_Af_Num>();
	gpio_af<DRV_MOSI_Pin.Port, DRV_MOSI_Pin.Num, Spi_MOSI_Af_Num>();

	// Initial states - Chip Select and Enable both inactive
	gpio_set<DRV_CS_Pin.Port, DRV_CS_Pin.Num>(true);
	gpio_set<DRV_EN_Pin.Port, DRV_EN_Pin.Num>(false);

	// ---- Init SPI1 for communication to DRV8353 ----
	// From datasheet:
	// - The SCLK pin should be low when the nSCS pin transitions from high to low and from low to high.
	// - Data is captured on the falling edge of SCLK and data is propagated on the rising edge of SCLK.
	// - The SPI input data (SDI) word consists of a 16 bit word, with a 5 bit command and 11 bits of data.
	//   The SPI output data (SDO) word consists of 11-bit register data. The first 5 bits are don’t care bits.

	auto rcc = STM32LIB::RCC<STM32LIB::RCC_Base_Address>();
	rcc.APB2ENR.SPI1EN.set(true);

	auto spi1 = STM32LIB::SPI<STM32LIB::SPI1_Base_Address>();
	spi1.CR1.apply<
		STM32LIB::SPI_CR1::BR<4>, 	// clock is divided by 32. gives about 5MHz (170 / 32 = 5.3125MHz)
									// maximum for DRV8353 is 10MHz
		STM32LIB::SPI_CR1::MSTR<true>, 		// mcu is the spi controller
		STM32LIB::SPI_CR1::SSM<true>, 		// software select line control
		STM32LIB::SPI_CR1::SSI<true>,		// force select line software value high
		STM32LIB::SPI_CR1::CPOL<false>,		// clock idles low
		STM32LIB::SPI_CR1::CPHA<true>		// data captured on second edge after idle (falling edge)
		>();

	spi1.CR2.DS.set(16-1); // data length is 16 bits

	init();
}

void DRV8353::init() {
	// ---- Set desired register values ----
	enable();
	vTaskDelay(5); // give it a moment to get ready

	write_reg(DRV8353_Registers::Control_Reg, static_cast<uint16_t>(DRV8353_Control_RegBits::OcpAct)); // Shuts down all 3 bridges during overcurrent events
	vTaskDelay(1); // give each command a little wait before the next one

    // Gate drive settings.
    // Using TPW4R50ANH mosfets with 58nC total gate charge, 12nC gate-drain charge
    // Rise time goal: 50ns -
    //      IdriveP > Qgd/tr = 12/50 = 240mA (closest is 300mA, 0100b)
    // Fall time goal: 25ns -
    //      IdriveN > Qgd/tf = 12/25 = 480mA (closest is 600mA, 0100b)
    // Tdrive is 500, 1000, 2000, or 4000ns. Since we expect to be done switching in
    // 50ns or less, 500ns (setting b00) is safe to choose.
	write_reg(DRV8353_Registers::Gate_HS_Reg, DRV8353_Gate_Source<DRV8353_Source_Drive_Strength::Src_300mA>() +
			DRV8353_Gate_Sink<DRV8353_Sink_Drive_Strength::Snk_600mA>());
	vTaskDelay(1);
	write_reg(DRV8353_Registers::Gate_LS_Reg, DRV8353_Gate_Source<DRV8353_Source_Drive_Strength::Src_300mA>() +
			DRV8353_Gate_Sink<DRV8353_Sink_Drive_Strength::Snk_600mA>() + static_cast<uint16_t>(DRV8353_Gate_LS_RegBits::CBC));
	vTaskDelay(1);

    // OCP - 100ns dead time (generally dead time is set by the MCU), overcurrent faults are latched,
    //          deglitch time is 2us, and VDS over current level is 0.6V (worst case
    //          100degC Rdson = 6mOhm, trip at 100A) (setting is 1001b)
	write_reg(DRV8353_Registers::OCP_Control_Reg, static_cast<uint16_t>(DRV8353_Dead_Time::DT_100ns) +
			static_cast<uint16_t>(DRV8353_Deglitch::Deglitch_2us) +
			static_cast<uint16_t>(DRV8353_Vds_Limit::VDS_0p6));
	vTaskDelay(1);


#if 0
    // Run auto calibration.
	write_reg(DRV8353_Registers::Cal_Mode_Reg, static_cast<uint16_t>(DRV8353_Cal_RegBits::Mode)); // Enable auto-calibration mode
	vTaskDelay(5);
    // Run auto-cal for channel A
    write_reg(DRV8353_Registers::CSA_Control_Reg,static_cast<uint16_t>(DRV8353_CSA_RegBits::CalA) +
    		static_cast<uint16_t>(DRV8353_CSA_RegBits::VrefDiv));
    vTaskDelay(5);
    // Run auto-cal for channel B
    write_reg(DRV8353_Registers::CSA_Control_Reg,static_cast<uint16_t>(DRV8353_CSA_RegBits::CalB) +
    		static_cast<uint16_t>(DRV8353_CSA_RegBits::VrefDiv));
    vTaskDelay(5);
    // Run auto-cal for channel C
    write_reg(DRV8353_Registers::CSA_Control_Reg,static_cast<uint16_t>(DRV8353_CSA_RegBits::CalC) +
    		static_cast<uint16_t>(DRV8353_CSA_RegBits::VrefDiv));
    vTaskDelay(5);
    // Reset back into normal calibration mode
    write_reg(DRV8353_Registers::Cal_Mode_Reg, 0); // Disable auto-calibration mode
    vTaskDelay(5);
#endif

    // CSA - Normal shunt resistor connections, bidirectional, 2nd smallest gain (10V/V, setting of 01b),
    //          sense over current threshold is 0.25V (equivalent to 125A with 2mOhm shunt, setting of 00b)
	write_reg(DRV8353_Registers::CSA_Control_Reg, static_cast<uint16_t>(DRV8353_CSA_RegBits::VrefDiv) +
			static_cast<uint16_t>(DRV8353_Gain::Gain_10));
	vTaskDelay(1);
}

void DRV8353::enable() {
	gpio_set<DRV_EN_Pin.Port, DRV_EN_Pin.Num>(true); // startup the chip
}

void DRV8353::disable() {
	gpio_set<DRV_EN_Pin.Port, DRV_EN_Pin.Num>(false); // shutdown the chip
}

uint16_t DRV8353::spi_write(uint16_t data_out) {
	uint32_t timeout_tracker;
	uint16_t retval = 0xFFFFu;
	auto spi1 = STM32LIB::SPI<STM32LIB::SPI1_Base_Address>();
    // First pull chip select line low.
	gpio_set<DRV_CS_Pin.Port, DRV_CS_Pin.Num>(false);

    // Begin by feeding the Tx FIFO with data
	spi1.DR.set(data_out);

    // Enable SPI to begin transaction
	spi1.CR1.SPE.set(true);

    timeout_tracker = SPI_MAX_WAIT_CYCLES;
    // Wait for RX FIFO to have some data in it (RX-not-empty = 1)
    while((spi1.SR.RXNE.get()) == false) {
        // Quit if it takes too long, return all 1's
        // which shouldn't happen in a real transaction
        timeout_tracker--;
        if(timeout_tracker == 0) {
            break;
        }
    }

    if((spi1.SR.RXNE.get()) == true) {
        retval = static_cast<uint16_t>(spi1.DR.get());
    }
    spi1.CR1.SPE.set(false);
    // Return CS line high
	gpio_set<DRV_CS_Pin.Port, DRV_CS_Pin.Num>(true);

	// TODO
	// Make a little wait spin function that doesn't rely on FreeRTOS
	// Then I can get rid of most of those vTaskDelays in this file

	return retval;
}

uint16_t DRV8353::write_reg(DRV8353_Registers reg_addr, uint16_t data) {
	// Spi transaction format:
	// First bit is read/write. Write = 0, Read = 1
	// Next 4 bits are register address (valid 0 through 7)
	// Final 11 bits are data

	uint16_t spiword = (static_cast<uint16_t>(reg_addr) << 11) + data;
	return spi_write(spiword) & (0x07FFu); // First 5 bits are don't-care
}

uint16_t DRV8353::read_reg(DRV8353_Registers reg_addr) {
	uint16_t spiword = (Drv_Rw_Bit) + (static_cast<uint16_t>(reg_addr) << 11u);
	return spi_write(spiword) & (0x07FFu);
}
bool DRV8353::set_gain(DRV8353_Gain newgain) {
	uint16_t temp_reg;
	uint16_t gain_bits = static_cast<uint16_t>(DRV8353_CSA_RegBits::Gain_0) +
			static_cast<uint16_t>(DRV8353_CSA_RegBits::Gain_1);

	// Read and modify
	temp_reg = read_reg(DRV8353_Registers::CSA_Control_Reg);
	temp_reg = temp_reg & (~gain_bits);
	temp_reg = temp_reg | static_cast<uint16_t>(newgain);

	// Write new gain value
	temp_reg = write_reg(DRV8353_Registers::CSA_Control_Reg, temp_reg);

	// Confirm changes
	temp_reg = read_reg(DRV8353_Registers::CSA_Control_Reg);
	return (temp_reg & gain_bits) == static_cast<uint16_t>(newgain);
}

DRV8353_Gain DRV8353::get_gain() {
	uint16_t gain_bits = static_cast<uint16_t>(DRV8353_CSA_RegBits::Gain_0) +
				static_cast<uint16_t>(DRV8353_CSA_RegBits::Gain_1);
	uint16_t temp_reg = read_reg(DRV8353_Registers::CSA_Control_Reg);

	temp_reg = temp_reg & gain_bits;
	return static_cast<DRV8353_Gain>(temp_reg);
}

bool DRV8353::set_vds_limit(DRV8353_Vds_Limit newlimit) {
	uint16_t temp_reg;
	uint16_t vds_bits = static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_0) +
			static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_1) +
			static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_2) +
			static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_3);

	// Read and modify
	temp_reg = read_reg(DRV8353_Registers::OCP_Control_Reg);
	temp_reg = temp_reg & (~vds_bits);
	temp_reg = temp_reg | static_cast<uint16_t>(newlimit);

	// Write new gain value
	temp_reg = write_reg(DRV8353_Registers::OCP_Control_Reg, temp_reg);

	// Confirm changes
	temp_reg = read_reg(DRV8353_Registers::OCP_Control_Reg);
	return (temp_reg & vds_bits) == static_cast<uint16_t>(newlimit);

}

DRV8353_Vds_Limit DRV8353::get_vds_limit() {
	uint16_t vds_bits = static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_0) +
				static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_1) +
				static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_2) +
				static_cast<uint16_t>(DRV8353_OCP_RegBits::VdsLevel_3);
	uint16_t temp_reg = read_reg(DRV8353_Registers::OCP_Control_Reg);

	temp_reg = temp_reg & vds_bits;
	return static_cast<DRV8353_Vds_Limit>(temp_reg);
}

// In channel_bit_pack, bit0 = Channel A, bit1 = Channel B, bit2 = Channel C
// Set channel's bit to 1 to enable its calibration mode
// Set it to 0 to return to normal mode
bool DRV8353::set_calibration(uint8_t channel_bit_pack) {
	uint16_t temp_reg;
	uint16_t cal_bits = static_cast<uint16_t>(DRV8353_CSA_RegBits::CalA) +
			static_cast<uint16_t>(DRV8353_CSA_RegBits::CalB) +
			static_cast<uint16_t>(DRV8353_CSA_RegBits::CalC);

	uint16_t new_cal = 0;
	if(channel_bit_pack && 0x01) new_cal = new_cal + static_cast<uint16_t>(DRV8353_CSA_RegBits::CalA);
	if(channel_bit_pack && 0x02) new_cal = new_cal + static_cast<uint16_t>(DRV8353_CSA_RegBits::CalB);
	if(channel_bit_pack && 0x04) new_cal = new_cal + static_cast<uint16_t>(DRV8353_CSA_RegBits::CalC);

	temp_reg = read_reg(DRV8353_Registers::CSA_Control_Reg);
	temp_reg = temp_reg & (~cal_bits);
	temp_reg = temp_reg | new_cal;

	temp_reg = write_reg(DRV8353_Registers::CSA_Control_Reg, temp_reg);

	temp_reg = read_reg(DRV8353_Registers::CSA_Control_Reg);
	return (temp_reg & cal_bits) == new_cal;
}

uint32_t DRV8353::get_fault_status() {
	// Fault1 in upper 16 bits, Fault2 in lower 16 bits
	return (static_cast<uint32_t>(read_reg(DRV8353_Registers::Fault1_Status_Reg)) << (16u))
			+ static_cast<uint32_t>(read_reg(DRV8353_Registers::Fault2_Status_Reg));
}

