#ifndef DRV8353_HPP_
#define DRV8353_HPP_

#pragma once


namespace EbikeLib {

enum class DRV8353_Source_Drive_Strength {
	Src_50mA = 		0x01,
	Src_100mA = 	0x02,
	Src_150mA = 	0x03,
	Src_300mA = 	0x04,
	Src_350mA = 	0x05,
	Src_400mA = 	0x06,
	Src_450mA = 	0x07,
	Src_550mA = 	0x08,
	Src_600mA = 	0x09,
	Src_650mA = 	0x0A,
	Src_700mA = 	0x0B,
	Src_850mA = 	0x0C,
	Src_900mA = 	0x0D,
	Src_950mA = 	0x0E,
	Src_1000mA = 	0x0F
};

enum class DRV8353_Sink_Drive_Strength {
	Snk_100mA = 	0x01,
	Snk_200mA = 	0x02,
	Snk_300mA = 	0x03,
	Snk_600mA = 	0x04,
	Snk_700mA = 	0x05,
	Snk_800mA = 	0x06,
	Snk_900mA = 	0x07,
	Snk_1100mA = 	0x08,
	Snk_1200mA = 	0x09,
	Snk_1300mA = 	0x0A,
	Snk_1400mA = 	0x0B,
	Snk_170mA = 	0x0C,
	Snk_1800mA = 	0x0D,
	Snk_1900mA = 	0x0E,
	Snk_2000mA = 	0x0F
};

enum class DRV8353_Registers {
	Fault1_Status_Reg = 0x00,
	Fault2_Status_Reg = 0x01,
	Control_Reg = 0x02,
	Gate_HS_Reg = 0x03,
	Gate_LS_Reg = 0x04,
	OCP_Control_Reg = 0x05,
	CSA_Control_Reg = 0x06,
	Cal_Mode_Reg = 0x07
};

enum class DRV8353_Fault1_RegBits {
	Fault = 	0x400, // All faults OR'd together
	VdsOCP = 	0x200, // Vds monitor over current (all drivers OR'd)
	GDF = 		0x100, // Gate driver fault
	UVLO = 		0x080, // Under voltage lock-out
	OTSD = 		0x040, // Over temp shutdown
	VdsHa = 	0x020, // Vds over current, high side phase A
	VdsLa = 	0x010, // Vds over current, low side phase A
	VdsHb = 	0x008, // Vds over current, high side phase B
	VdsLb = 	0x004, // Vds over current, low side phase B
	VdsHc = 	0x002, // Vds over current, high side phase C
	VdsLc = 	0x001  // Vds over current, low side phase C
};

enum class DRV8353_Fault2_RegBits {
	SaOC = 		0x400, // Shunt amplifier overcurrent, phase A
	SbOC = 		0x200, // Shunt amplifier overcurrent, phase B
	ScOC = 		0x100, // Shunt amplifier overcurrent, phase C
	OTW = 		0x080, // Over temperature warning
	GDUV = 		0x040, // Gate driver under voltage
	VgsHa = 	0x020, // Gate driver fault, high side phase A
	VgsLa = 	0x010, // Gate driver fault, low side phase A
	VgsHb = 	0x008, // Gate driver fault, high side phase B
	VgsLb = 	0x004, // Gate driver fault, low side phase B
	VgsHc = 	0x002, // Gate driver fault, high side phase C
	VgsLc = 	0x001  // Gate driver fault, low side phase C
};

enum class DRV8353_Control_RegBits {
	OcpAct =	0x400, // shutdown only the fault half-bridge (0) or all three (1)
	DisGUV =	0x200, // disable gate driver under voltage fault
	DisGDF =	0x100, // disable gate fault
	OTWRep =	0x080, // report over temp warning on fault bit and pin
	PWMMode_1 = 0x040, // 00 - 6x pwm, 01 - 3x pwm, 10 - 1x pwm, 11 - independent pwm
	PWMMode_0 = 0x020,
	PWMCom = 	0x010, // 0 - 1x pwm uses synchronous rectification, 1 - asynchronous
	PWMDir =	0x008, // change direction in 1x pwm mode
	Coast =		0x004, // All FETs in High-Z (gates output low)
	Brake = 	0x002, // All high FETs High-Z, low FETs on
	ClrFlt =	0x001  // Clear latched faults, alternative to resetting enable pin
};

enum class DRV8353_Control_PWMMode {
	PWM_6x = 0x000,
	PWM_3x = 0x020,
	PWM_1x = 0x040,
	PWM_Independent = 0x060
};

enum class DRV8353_Gate_HS_RegBits {
	Lock_2 = 	0x400, // Write 110 to lock the settings, 011 to unlock. Other patterns ignored
	Lock_1 = 	0x200,
	Lock_0 = 	0x100,
	IdriveHS_3 = 0x080,
	IdriveHS_2 = 0x040,
	IdriveHS_1 = 0x020,
	IdriveHS_0 = 0x010,
	IdriveNHS_3 = 0x008,
	IdriveNHS_2 = 0x004,
	IdriveNHS_1 = 0x002,
	IdriveNHS_0 = 0x001
};

enum class DRV8353_Gate_LS_RegBits {
	CBC = 		0x400, // When OCP_MODE = 01, sets whether a new PWM input is needed to clear VDSOCP and SENOCP faults
	Tdrive_1 = 	0x200, // Time setting for peak gate current drive
	Tdrive_0 = 	0x100,
	IdriveLS_3 = 0x080,
	IdriveLS_2 = 0x040,
	IdriveLS_1 = 0x020,
	IdriveLS_0 = 0x010,
	IdriveNLS_3 = 0x008,
	IdriveNLS_2 = 0x004,
	IdriveNLS_1 = 0x002,
	IdriveNLS_0 = 0x001
};

template<DRV8353_Source_Drive_Strength lim>
constexpr uint16_t DRV8353_Gate_Source() {
	return (static_cast<uint16_t>(lim) << 4);
}

template<DRV8353_Sink_Drive_Strength lim>
constexpr uint16_t DRV8353_Gate_Sink() {
	return static_cast<uint16_t>(lim);
}

enum class DRV8353_Tdrive {
	T_500ns = 	0x000,
	T_1000ns =	0x100,
	T_2000ns =	0x200,
	T_4000ns =	0x300
};

enum class DRV8353_OCP_RegBits {
	Tretry =	0x400, // 0 - retry is 8ms, 1 - retry is 50us
	DeadTime_1 = 	0x200, // Hardware deadtime between high/low side
	DeadTime_0 =	0x100,
	Mode_1 =		0x080, // Overcurrent fault mode
	Mode_0 =		0x040,
	Deglitch_1 =	0x020, // Deglitch time setting
	Deglitch_0 =	0x010,
	VdsLevel_3 =	0x008, // Vds overcurrent limit voltage
	VdsLevel_2 =	0x004,
	VdsLevel_1 =	0x002,
	VdsLevel_0 =	0x001
};

enum class DRV8353_Dead_Time {
	DT_50ns = 0x000,
	DT_100ns = 0x100,
	DT_200ns = 0x200,
	DT_400ns = 0x300
};

enum class DRV8353_OC_Mode {
	Latched = 0x000,
	Auto_Retry = 0x040,
	Report_Only = 0x080,
	No_Action = 0x0C0
};

enum class DRV8353_Deglitch {
	Deglitch_1us = 0x000,
	Deglitch_2us = 0x010,
	Deglitch_4us = 0x020,
	Deglitch_8us = 0x030
};

enum class DRV8353_Vds_Limit {
    VDS_0p06 = 0x0,
    VDS_0p07 = 0x1,
    VDS_0p08 = 0x2,
    VDS_0p09 = 0x3,
    VDS_0p1  = 0x4,
    VDS_0p2  = 0x5,
    VDS_0p3  = 0x6,
    VDS_0p4  = 0x7,
    VDS_0p5  = 0x8,
    VDS_0p6  = 0x9,
    VDS_0p7  = 0xA,
    VDS_0p8  = 0xB,
    VDS_0p9  = 0xC,
    VDS_1    = 0xD,
    VDS_1p5  = 0xE,
    VDS_2    = 0xF
};

enum class DRV8353_CSA_RegBits {
	Fet = 			0x400, // 0 - sense amplifer in shunt resistor mode, 1 - low side VDS sensing
	VrefDiv =		0x200, // 0 - Vref (unidirectional), 1 - Vref/2 (bidirectional)
	LsRef =			0x100, // 0 - VDS_OCP measured from SH to SP, 1 - measured from SH to SN
	Gain_1 =		0x080,
	Gain_0 = 		0x040,
	DisSen = 		0x020, // set to disable sense overcurrent fault
	CalA =			0x010, // Set to short amplifier A inputs for manual calibration
	CalB =			0x008, // Short amplifier B inputs
	CalC = 			0x004, // Short amplifier C inputs
	SenLevel_1 =	0x002, // Sense overcurrent voltage level
	SenLevel_0 =	0x001
};

enum class DRV8353_Gain {
    Gain_5 = 	0x000,
    Gain_10 = 	0x040,
    Gain_20 = 	0x080,
    Gain_40 = 	0x0C0
};

enum class DRV8353_Sense_OC {
	Sense_0p25 = 0x00,
	Sense_0p5 = 0x01,
	Sense_0p75 = 0x02,
	Sense_1 = 0x03
};

enum class DRV8353_Cal_RegBits {
	Mode =		0x001 // set to use internal auto-calibration routine
};


class DRV8353 {
public:
	// Sit and spin in a loop waiting for SPI completion
	// If it takes longer than about 3us, quit
	const uint32_t SPI_MAX_WAIT_CYCLES = 500;
	// First bit of the SPI transaction is read/write bit
	// Write = 0, Read = 1
	const uint16_t Drv_Rw_Bit = 0x8000u;

	DRV8353();

	void init();
	void enable();
	void disable();
	bool set_gain(DRV8353_Gain newgain);
	DRV8353_Gain get_gain();
	bool set_vds_limit(DRV8353_Vds_Limit newlimit);
	DRV8353_Vds_Limit get_vds_limit();
	bool set_calibration(uint8_t channel_bit_pack);
	uint32_t get_fault_status();

private:
	uint16_t spi_write(uint16_t data_out);
	uint16_t write_reg(DRV8353_Registers reg_addr, uint16_t data);
	uint16_t read_reg(DRV8353_Registers reg_addr);
};


} // namespace EbikeLib



#endif /* DRV8353_HPP_ */
