#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"
#include <SPI.h>
// #include "SW_SPI.h"

TMC5041Stepper::TMC5041Stepper(uint16_t pinCS) : _pinCS(pinCS) { _started = false; }

//TMC5041Stepper::TMC5041Stepper(uint16_t pinEN, uint16_t pinDIR, uint16_t pinStep, uint16_t pinCS) {
TMC5041Stepper::TMC5041Stepper(uint16_t pinEN, uint16_t pinCS) {
	_started = false;
	_pinEN = pinEN;
	//_pinSTEP = pinStep;
	_pinCS = pinCS;
	//_pinDIR = pinDIR;
}


void TMC5041Stepper::begin() {
//#ifdef TMC5041DEBUG
	// Serial.println("TMC5041 Stepper driver library");
	// Serial.print("Enable pin: ");
	// Serial.println(_pinEN);
	// Serial.print("Chip select pin: ");
	// Serial.println(_pinCS);
//#endif
	// delay(200);

	//set pins
	if (_pinEN != 0xFFFF) {
		pinMode(_pinEN, OUTPUT);
		digitalWrite(_pinEN, HIGH); //deactivate driver (LOW active)
	}


	pinMode(_pinCS, OUTPUT);
	digitalWrite(_pinCS, HIGH);

	// if (uses_sw_spi) TMC_SW_SPI.init();

	// Reset registers
	push();

	toff_1(5); //off_time(8);
	tbl_1(2); //blank_time(24);
	toff_2(5); //off_time(8);
	tbl_2(2); //blank_time(24);

	_started = true;
}

void TMC5041Stepper::send5041(uint8_t addressByte, uint32_t *config) {
	SPI.beginTransaction(SPISettings(16000000/8, MSBFIRST, SPI_MODE3));
	digitalWrite(_pinCS, LOW);

	status_response = SPI.transfer(addressByte & 0xFF); // s =

	if (addressByte >> 7) { // Check if WRITE command
		//*config &= ~mask; // Clear bits being set
		//*config |= (value & mask); // Set new values
		SPI.transfer((*config >> 24) & 0xFF);
		SPI.transfer((*config >> 16) & 0xFF);
		SPI.transfer((*config >>  8) & 0xFF);
		SPI.transfer(*config & 0xFF);
	} else { // READ command
		SPI.transfer16(0x0000); // Clear SPI
		SPI.transfer16(0x0000);
		digitalWrite(_pinCS, HIGH);
		digitalWrite(_pinCS, LOW);

		SPI.transfer(addressByte & 0xFF); // Send the address byte again
		*config = SPI.transfer(0x00);
		*config <<= 8;
		*config|= SPI.transfer(0x00);
		*config <<= 8;
		*config|= SPI.transfer(0x00);
		*config <<= 8;
		*config|= SPI.transfer(0x00);
	}

	digitalWrite(_pinCS, HIGH);
	SPI.endTransaction();
	//}
}

// bool TMC5041Stepper::checkOT() {
	// uint32_t response = DRV_STATUS_1();
	// if (response & OTPW_bm) {
		// flag_otpw = 1;
		// return true; // bit 26 for overtemperature warning flag
	// }
	// return false;
// }

bool TMC5041Stepper::getOTPW() { return flag_otpw; }

void TMC5041Stepper::clear_otpw() {	flag_otpw = 0; }

//bool TMC5041Stepper::isEnabled() { return !digitalRead(_pinEN) && toff(); }

void TMC5041Stepper::push() {
	GCONF(GCONF_sr); // Position comparator enabled
	IHOLD_IRUN_1(IHOLD_IRUN_1_sr);
	IHOLD_IRUN_2(IHOLD_IRUN_2_sr);
	// TPOWERDOWN(TPOWERDOWN_sr);
	// TPWMTHRS(TPWMTHRS_sr);
	// TCOOLTHRS(TCOOLTHRS_sr);
	// THIGH(THIGH_sr);
	// XDIRECT(XDIRECT_sr);
	// VDCMIN(VDCMIN_sr);
	CHOPCONF_1(CHOPCONF_1_sr);
	CHOPCONF_2(CHOPCONF_2_sr);
	// COOLCONF(COOLCONF_sr);
	PWMCONF_1(PWMCONF_1_sr);
	PWMCONF_2(PWMCONF_2_sr);
	// ENCM_CTRL(ENCM_CTRL_sr);
}

// uint8_t TMC5041Stepper::test_connection() {
	// uint32_t drv_status = DRV_STATUS();
	// switch (drv_status) {
	    // case 0xFFFFFFFF: return 1;
	    // case 0: return 2;
	    // default: return 0;
	// }
// }

///////////////////////////////////////////////////////////////////////////////////////
// TZEROWAIT
void TMC5041Stepper::TZEROWAIT_1( uint32_t input) {
		TZEROWAIT_1_sr = input;
		TMC_WRITE_REG(TZEROWAIT_1);	
}
void TMC5041Stepper::TZEROWAIT_2( uint32_t input) {
		TZEROWAIT_2_sr = input;
		TMC_WRITE_REG(TZEROWAIT_2);	
}
///////////////////////////////////////////////////////////////////////////////////////
// RAMPMODE
void TMC5041Stepper::RAMPMODE_1(uint32_t input) {
		RAMPMODE_1_sr = input;
		TMC_WRITE_REG(RAMPMODE_1);

}
void TMC5041Stepper::RAMPMODE_2(uint32_t input) {
		RAMPMODE_2_sr = input;
		TMC_WRITE_REG(RAMPMODE_2);
}
uint32_t TMC5041Stepper::RAMPMODE_1() { 	
		TMC_READ_REG(RAMPMODE_1); 		
}
uint32_t TMC5041Stepper::RAMPMODE_2() { 	
		TMC_READ_REG(RAMPMODE_2); 		
}
///////////////////////////////////////////////////////////////////////////////////////
// AMAX
void TMC5041Stepper::AMAX_1(uint32_t input) {
	AMAX_1_sr = input;
	TMC_WRITE_REG(AMAX_1);	
}
void TMC5041Stepper::AMAX_2(uint32_t input) {
	AMAX_2_sr = input;
	TMC_WRITE_REG(AMAX_2);	
}
uint32_t TMC5041Stepper::AMAX_1() { 	
	TMC_READ_REG(AMAX_1); 		
}
uint32_t TMC5041Stepper::AMAX_2() { 	
	TMC_READ_REG(AMAX_2); 		
}

///////////////////////////////////////////////////////////////////////////////////////
// VMAX
void TMC5041Stepper::VMAX_1(uint32_t input) {
	VMAX_1_sr = input;
	TMC_WRITE_REG(VMAX_1);	
}
void TMC5041Stepper::VMAX_2(uint32_t input) {
	VMAX_2_sr = input;
	TMC_WRITE_REG(VMAX_2);	
}
uint32_t TMC5041Stepper::VMAX_1() { 	
	TMC_READ_REG(VMAX_1); 		
}
uint32_t TMC5041Stepper::VMAX_2() { 	
	TMC_READ_REG(VMAX_2); 		
}
///////////////////////////////////////////////////////////////////////////////////////
// A1
void TMC5041Stepper::A1_1( uint32_t input) {
	A1_1_sr = input;
	TMC_WRITE_REG(A1_1);
}
void TMC5041Stepper::A1_2( uint32_t input) {
	A1_2_sr = input;
	TMC_WRITE_REG(A1_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// V1
void TMC5041Stepper::V1_1( uint32_t input) {
	V1_1_sr = input;
	TMC_WRITE_REG(V1_1);
}
void TMC5041Stepper::V1_2( uint32_t input) {
	V1_2_sr = input;
	TMC_WRITE_REG(V1_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// DMAX
void TMC5041Stepper::DMAX_1( uint32_t input) {
	DMAX_1_sr = input;
	TMC_WRITE_REG(DMAX_1);
}
void TMC5041Stepper::DMAX_2( uint32_t input) {
	DMAX_2_sr = input;
	TMC_WRITE_REG(DMAX_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// D1
void TMC5041Stepper::D1_1( uint32_t input) {
	D1_1_sr = input;
	TMC_WRITE_REG(D1_1);
}
void TMC5041Stepper::D1_2( uint32_t input) {
	D1_2_sr = input;
	TMC_WRITE_REG(D1_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// VSTOP
void TMC5041Stepper::VSTOP_1(uint32_t input) {
	VSTOP_1_sr = input;
	TMC_WRITE_REG(VSTOP_1);
}
void TMC5041Stepper::VSTOP_2(uint32_t input) {
	VSTOP_2_sr = input;
	TMC_WRITE_REG(VSTOP_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// W: VSTART
void TMC5041Stepper::VSTART_1(uint32_t input) {
	VSTART_1_sr = input;
	TMC_WRITE_REG(VSTOP_1);
}
void TMC5041Stepper::VSTART_2(uint32_t input) {
	VSTART_2_sr = input;
	TMC_WRITE_REG(VSTART_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// R: VACTUAL
int32_t TMC5041Stepper::VACTUAL_1() { 
	TMC_READ_REG(VACTUAL_1);
}
int32_t TMC5041Stepper::VACTUAL_2() { 
	TMC_READ_REG(VACTUAL_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// XTARGET
void TMC5041Stepper::XTARGET_1( int32_t input) {
	XTARGET_1_sr = input;
	TMC_WRITE_REG(XTARGET_1);	
}
void TMC5041Stepper::XTARGET_2( int32_t input) {
	XTARGET_2_sr = input;
	TMC_WRITE_REG(XTARGET_2);	
}
int32_t TMC5041Stepper::XTARGET_1() { 
	TMC_READ_REG(XTARGET_1);
}
int32_t TMC5041Stepper::XTARGET_2() { 
	TMC_READ_REG(XTARGET_2);
}
void TMC5041Stepper::XTARGET_MSG_1() {
	char B[30] = "XTARGET motor 1: ";
	TMC_PRINT(XTARGET_1, XTARGET);	
}
void TMC5041Stepper::XTARGET_MSG_2() {
	char B[30] = "XTARGET motor 2: ";
	TMC_PRINT(XTARGET_2, XTARGET);	
}
///////////////////////////////////////////////////////////////////////////////////////
// XACTUAL
void TMC5041Stepper::XACTUAL_1( int32_t input) {
	XACTUAL_1_sr = input;
	TMC_WRITE_REG(XACTUAL_1);	
}
void TMC5041Stepper::XACTUAL_2( int32_t input) {
	XACTUAL_2_sr = input;
	TMC_WRITE_REG(XACTUAL_2);	
}
int32_t TMC5041Stepper::XACTUAL_1() { 
	TMC_READ_REG(XACTUAL_1);
}
int32_t TMC5041Stepper::XACTUAL_2() { 
	TMC_READ_REG(XACTUAL_2);
}
void TMC5041Stepper::XACTUAL_MSG_1() {
	char B[30] = "XACTUAL motor 1: ";
	TMC_PRINT(XACTUAL_1, XACTUAL);	
}
void TMC5041Stepper::XACTUAL_MSG_2() {
	char B[30] = "XACTUAL motor 2: ";
	TMC_PRINT(XACTUAL_2, XACTUAL);	
}
///////////////////////////////////////////////////////////////////////////////////////
// RAMP_STAT
uint32_t TMC5041Stepper::RAMP_STAT_1() { TMC_READ_REG(RAMP_STAT_1); }
uint32_t TMC5041Stepper::RAMP_STAT_2() { TMC_READ_REG(RAMP_STAT_2); }

uint8_t TMC5041Stepper::position_reached_1()		{ TMC_GET_BIT(RAMP_STAT_1, POSITION_REACHED);		}
uint8_t TMC5041Stepper::position_reached_2()		{ TMC_GET_BIT(RAMP_STAT_2, POSITION_REACHED);		}

uint8_t TMC5041Stepper::vzero_1()		{ TMC_GET_BIT(RAMP_STAT_1, VZERO);		}
uint8_t TMC5041Stepper::vzero_2()		{ TMC_GET_BIT(RAMP_STAT_2, VZERO);		}

uint8_t TMC5041Stepper::status_sg_1()		{ TMC_GET_BIT(RAMP_STAT_1, STATUS_SG);		}
uint8_t TMC5041Stepper::status_sg_2()		{ TMC_GET_BIT(RAMP_STAT_2, STATUS_SG);		}

uint8_t TMC5041Stepper::second_move_1()		{ TMC_GET_BIT(RAMP_STAT_1, SECOND_MOVE);		}
uint8_t TMC5041Stepper::second_move_2()		{ TMC_GET_BIT(RAMP_STAT_2, SECOND_MOVE);		}

uint8_t TMC5041Stepper::t_zerowait_active_1()		{ TMC_GET_BIT(RAMP_STAT_1, T_ZEROWAIT_ACTIVE);		}
uint8_t TMC5041Stepper::t_zerowait_active_2()		{ TMC_GET_BIT(RAMP_STAT_2, T_ZEROWAIT_ACTIVE);		}

uint8_t TMC5041Stepper::velocity_reached_1()		{ TMC_GET_BIT(RAMP_STAT_1, VELOCITY_REACHED);		}
uint8_t TMC5041Stepper::velocity_reached_2()		{ TMC_GET_BIT(RAMP_STAT_2, VELOCITY_REACHED);		}

uint8_t TMC5041Stepper::event_pos_reached_1()		{ TMC_GET_BIT(RAMP_STAT_1, EVENT_POS_REACHED);		}
uint8_t TMC5041Stepper::event_pos_reached_2()		{ TMC_GET_BIT(RAMP_STAT_2, EVENT_POS_REACHED);		}

uint8_t TMC5041Stepper::event_stop_sg_1()		{ TMC_GET_BIT(RAMP_STAT_1, EVENT_STOP_SG);		}
uint8_t TMC5041Stepper::event_stop_sg_2()		{ TMC_GET_BIT(RAMP_STAT_2, EVENT_STOP_SG);		}

uint8_t TMC5041Stepper::event_stop_r_1()		{ TMC_GET_BIT(RAMP_STAT_1, EVENT_STOP_R);		}
uint8_t TMC5041Stepper::event_stop_r_2()		{ TMC_GET_BIT(RAMP_STAT_2, EVENT_STOP_R);		}

uint8_t TMC5041Stepper::event_stop_l_1()		{ TMC_GET_BIT(RAMP_STAT_1, EVENT_STOP_L);		}
uint8_t TMC5041Stepper::event_stop_l_2()		{ TMC_GET_BIT(RAMP_STAT_2, EVENT_STOP_L);		}

uint8_t TMC5041Stepper::status_latch_r_1()		{ TMC_GET_BIT(RAMP_STAT_1, STATUS_LATCH_R);		}
uint8_t TMC5041Stepper::status_latch_r_2()		{ TMC_GET_BIT(RAMP_STAT_2, STATUS_LATCH_R);		}

uint8_t TMC5041Stepper::status_latch_l_1()		{ TMC_GET_BIT(RAMP_STAT_1, STATUS_LATCH_L);		}
uint8_t TMC5041Stepper::status_latch_l_2()		{ TMC_GET_BIT(RAMP_STAT_2, STATUS_LATCH_L);		}

uint8_t TMC5041Stepper::status_stop_r_1()		{ TMC_GET_BIT(RAMP_STAT_1, STATUS_STOP_R);		}
uint8_t TMC5041Stepper::status_stop_r_2()		{ TMC_GET_BIT(RAMP_STAT_2, STATUS_STOP_R);		}

uint8_t TMC5041Stepper::status_stop_l_1()		{ TMC_GET_BIT(RAMP_STAT_1, STATUS_STOP_L);		}
uint8_t TMC5041Stepper::status_stop_l_2()		{ TMC_GET_BIT(RAMP_STAT_2, STATUS_STOP_L);		}
///////////////////////////////////////////////////////////////////////////////////////
// SW_MODE
uint32_t TMC5041Stepper::SW_MODE_1() { TMC_READ_REG(SW_MODE_1); }
uint32_t TMC5041Stepper::SW_MODE_2() { TMC_READ_REG(SW_MODE_2); }

void TMC5041Stepper::en_softstop_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, EN_SOFTSTOP);	}
void TMC5041Stepper::latch_r_inactive_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, LATCH_R_INACTIVE);	}
void TMC5041Stepper::latch_r_active_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, LATCH_R_ACTIVE);	}
void TMC5041Stepper::latch_l_inactive_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, LATCH_L_INACTIVE);	}
void TMC5041Stepper::latch_l_active_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, LATCH_L_ACTIVE);	}
void TMC5041Stepper::pol_stop_r_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, POL_STOP_R);	}
void TMC5041Stepper::pol_stop_l_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, POL_STOP_L);	}
void TMC5041Stepper::stop_r_enable_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, STOP_R_ENABLE);	}
void TMC5041Stepper::stop_l_enable_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, STOP_L_ENABLE);	}
void TMC5041Stepper::sg_stop_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, SG_STOP);	}
void TMC5041Stepper::swap_lr_1( uint8_t B )	{ TMC_MOD_REG(SW_MODE_1, SWAP_LR);	}

void TMC5041Stepper::en_softstop_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, EN_SOFTSTOP);	}
void TMC5041Stepper::latch_r_inactive_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, LATCH_R_INACTIVE);	}
void TMC5041Stepper::latch_r_active_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, LATCH_R_ACTIVE);	}
void TMC5041Stepper::latch_l_inactive_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, LATCH_L_INACTIVE);	}
void TMC5041Stepper::latch_l_active_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, LATCH_L_ACTIVE);	}
void TMC5041Stepper::pol_stop_r_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, POL_STOP_R);	}
void TMC5041Stepper::pol_stop_l_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, POL_STOP_L);	}
void TMC5041Stepper::stop_r_enable_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, STOP_R_ENABLE);	}
void TMC5041Stepper::stop_l_enable_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, STOP_L_ENABLE);	}
void TMC5041Stepper::sg_stop_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, SG_STOP);	}
void TMC5041Stepper::swap_lr_2( uint8_t B )	{ TMC_MOD_REG(SW_MODE_2, SWAP_LR);	}

///////////////////////////////////////////////////////////////////////////////////////
// XLATCH

int32_t TMC5041Stepper::XLATCH_1() { 
	TMC_READ_REG(XLATCH_1);
}
void TMC5041Stepper::XLATCH_MSG_1() {
	char B[30] = "XLATCH motor 1: ";
	TMC_PRINT(XLATCH_1, XLATCH);
}
int32_t TMC5041Stepper::XLATCH_2() { 
	TMC_READ_REG(XLATCH_2);
}
void TMC5041Stepper::XLATCH_MSG_2() {
	char B[30] = "XLATCH motor 2: ";
	TMC_PRINT(XLATCH_2, XLATCH);
}

///////////////////////////////////////////////////////////////////////////////////////
// W: X_COMPARE
void TMC5041Stepper::X_COMPARE( int32_t input) {
	X_COMPARE_sr = input;
	TMC_WRITE_REG(X_COMPARE);	
}

///////////////////////////////////////////////////////////////////////////////////////
// R+C: GSTAT
void 	TMC5041Stepper::GSTAT(uint8_t input){
	GSTAT_sr = input;
	TMC_WRITE_REG(GSTAT);
}
uint8_t TMC5041Stepper::GSTAT()			 	{ TMC_READ_REG_R(GSTAT); 		}
bool 	TMC5041Stepper::reset()				{ TMC_GET_BYTE(GSTAT, RESET);	}
bool 	TMC5041Stepper::drv_err1()			{ TMC_GET_BYTE(GSTAT, DRV_ERR1);	}
bool 	TMC5041Stepper::drv_err2()			{ TMC_GET_BYTE(GSTAT, DRV_ERR2);	}
bool 	TMC5041Stepper::uv_cp()				{ TMC_GET_BYTE(GSTAT, UV_CP);	}
// ///////////////////////////////////////////////////////////////////////////////////////
// // R: IOIN
// uint32_t 	TMC5041Stepper::IOIN() 			{ TMC_READ_REG_R(IOIN); 				}
// bool 		TMC5041Stepper::step()			{ TMC_GET_BYTE_R(IOIN, STEP);			}
// bool 		TMC5041Stepper::dir()			{ TMC_GET_BYTE_R(IOIN, DIR);			}
// bool 		TMC5041Stepper::dcen_cfg4()		{ TMC_GET_BYTE_R(IOIN, DCEN_CFG4);		}
// bool 		TMC5041Stepper::dcin_cfg5()		{ TMC_GET_BYTE_R(IOIN, DCIN_CFG5);		}
// bool 		TMC5041Stepper::drv_enn_cfg6()	{ TMC_GET_BYTE_R(IOIN, DRV_ENN_CFG6);	}
// bool 		TMC5041Stepper::dco()			{ TMC_GET_BYTE_R(IOIN, DCO);			}
// uint8_t 	TMC5041Stepper::version() 		{ TMC_GET_BYTE_R(IOIN, VERSION);		}
// ///////////////////////////////////////////////////////////////////////////////////////
// // W: TPOWERDOWN
// uint8_t TMC5041Stepper::TPOWERDOWN() { return TPOWERDOWN_sr; }
// void TMC5041Stepper::TPOWERDOWN(uint8_t input) {
	// TPOWERDOWN_sr = input;
	// TMC_WRITE_REG(TPOWERDOWN);
// }
// ///////////////////////////////////////////////////////////////////////////////////////
// // R: TSTEP
// uint32_t TMC5041Stepper::TSTEP() { TMC_READ_REG_R(TSTEP); }
// ///////////////////////////////////////////////////////////////////////////////////////
// // W: TPWMTHRS
// uint32_t TMC5041Stepper::TPWMTHRS() { return TPWMTHRS_sr; }
// void TMC5041Stepper::TPWMTHRS(uint32_t input) {
	// TPWMTHRS_sr = input;
	// TMC_WRITE_REG(TPWMTHRS);
// }
///////////////////////////////////////////////////////////////////////////////////////
// W: VCOOLTHRS
uint32_t TMC5041Stepper::VCOOLTHRS_1() { return VCOOLTHRS_1_sr; }
void TMC5041Stepper::VCOOLTHRS_1(uint32_t input) {
	VCOOLTHRS_1_sr = input;
	TMC_WRITE_REG(VCOOLTHRS_1);
}
uint32_t TMC5041Stepper::VCOOLTHRS_2() { return VCOOLTHRS_2_sr; }
void TMC5041Stepper::VCOOLTHRS_2(uint32_t input) {
	VCOOLTHRS_2_sr = input;
	TMC_WRITE_REG(VCOOLTHRS_2);
}
///////////////////////////////////////////////////////////////////////////////////////
// W: VHIGH
uint32_t TMC5041Stepper::VHIGH_1() { return VHIGH_1_sr; }
void TMC5041Stepper::VHIGH_1(uint32_t input) {
	VHIGH_1_sr = input;
	TMC_WRITE_REG(VHIGH_1);
}
uint32_t TMC5041Stepper::VHIGH_2() { return VHIGH_2_sr; }
void TMC5041Stepper::VHIGH_2(uint32_t input) {
	VHIGH_2_sr = input;
	TMC_WRITE_REG(VHIGH_2);
}
// ///////////////////////////////////////////////////////////////////////////////////////
// // RW: XDIRECT
// uint32_t TMC5041Stepper::XDIRECT() { TMC_READ_REG(XDIRECT); }
// void TMC5041Stepper::XDIRECT(uint32_t input) {
	// XDIRECT_sr = input;
	// TMC_WRITE_REG(XDIRECT);
// }
// void TMC5041Stepper::coil_A(int16_t B) 	{ TMC_MOD_REG(XDIRECT, COIL_A); 	}
// void TMC5041Stepper::coil_B(int16_t B) 	{ TMC_MOD_REG(XDIRECT, COIL_B); 	}
// int16_t TMC5041Stepper::coil_A() 		{ TMC_GET_BYTE_R(XDIRECT, COIL_A); 	}
// int16_t TMC5041Stepper::coil_B() 		{ TMC_GET_BYTE_R(XDIRECT, COIL_A); 	}
// ///////////////////////////////////////////////////////////////////////////////////////
// // W: VDCMIN
// uint32_t TMC5041Stepper::VDCMIN() { return VDCMIN_sr; }
// void TMC5041Stepper::VDCMIN(uint32_t input) {
	// VDCMIN_sr = input;
	// TMC_WRITE_REG(VDCMIN);
// }
///////////////////////////////////////////////////////////////////////////////////////
// R: MSCNT
uint16_t TMC5041Stepper::MSCNT_1() { TMC_READ_REG_R(MSCNT_1); }
uint16_t TMC5041Stepper::MSCNT_2() { TMC_READ_REG_R(MSCNT_2); }
///////////////////////////////////////////////////////////////////////////////////////
// R: MSCURACT
uint32_t TMC5041Stepper::MSCURACT_1() { TMC_READ_REG_R(MSCURACT_1); }
int16_t TMC5041Stepper::cur_a_1() {
	int16_t value = (MSCURACT_1()&CUR_A_bm) >> CUR_A_bp;
	if (value > 255) value -= 512;
	return value;
}
int16_t TMC5041Stepper::cur_b_1() {
	int16_t value = (MSCURACT_1()&CUR_B_bm) >> CUR_B_bp;
	if (value > 255) value -= 512;
	return value;
}
uint32_t TMC5041Stepper::MSCURACT_2() { TMC_READ_REG_R(MSCURACT_2); }
int16_t TMC5041Stepper::cur_a_2() {
	int16_t value = (MSCURACT_2()&CUR_A_bm) >> CUR_A_bp;
	if (value > 255) value -= 512;
	return value;
}
int16_t TMC5041Stepper::cur_b_2() {
	int16_t value = (MSCURACT_2()&CUR_B_bm) >> CUR_B_bp;
	if (value > 255) value -= 512;
	return value;
}
// ///////////////////////////////////////////////////////////////////////////////////////
// // R: PWM_SCALE
// uint8_t TMC5041Stepper::PWM_SCALE() { TMC_READ_REG_R(PWM_SCALE); }
// ///////////////////////////////////////////////////////////////////////////////////////
// // W: ENCM_CTRL
// uint8_t TMC5041Stepper::ENCM_CTRL() { return ENCM_CTRL_sr; }
// void TMC5041Stepper::ENCM_CTRL(uint8_t input) {
	// ENCM_CTRL_sr = input;
	// TMC_WRITE_REG(ENCM_CTRL);
// }
// void TMC5041Stepper::inv(bool B)		{ TMC_MOD_REG(ENCM_CTRL, INV);		}
// void TMC5041Stepper::maxspeed(bool B)	{ TMC_MOD_REG(ENCM_CTRL, MAXSPEED); }
// bool TMC5041Stepper::inv() 				{ TMC_GET_BYTE(ENCM_CTRL, INV); 	}
// bool TMC5041Stepper::maxspeed() 		{ TMC_GET_BYTE(ENCM_CTRL, MAXSPEED);}
// ///////////////////////////////////////////////////////////////////////////////////////
// // R: LOST_STEPS
// uint32_t TMC5041Stepper::LOST_STEPS() { TMC_READ_REG_R(LOST_STEPS); }


/**
 *	Helper functions
 */


/*	
	Requested current = mA = I_rms/1000
	Equation for current:
	I_rms = (CS+1)/32 * V_fs/(R_sense+0.02ohm) * 1/sqrt(2)
	Solve for CS ->
	CS = 32*sqrt(2)*I_rms*(R_sense+0.02)/V_fs - 1
	
	Example:
	vsense = 0b0 -> V_fs = 0.325V
	mA = 1640mA = I_rms/1000 = 1.64A
	R_sense = 0.10 Ohm
	->
	CS = 32*sqrt(2)*1.64*(0.10+0.02)/0.325 - 1 = 26.4
	CS = 26
*/	
void TMC5041Stepper::rms_current(uint16_t mA, float multiplier, float RS) {
	Rsense = RS;
	uint8_t CS = 32.0*1.41421*mA/1000.0*(Rsense+0.02)/0.325 - 1;
	// If Current Scale is too low, turn on high sensitivity R_sense and calculate again
	if (CS < 16) {
		vsense(true);
		CS = 32.0*1.41421*mA/1000.0*(Rsense+0.02)/0.180 - 1;
	} else if(vsense()) { // If CS >= 16, turn off high_sense_r if it's currently ON
		vsense(false);
	}
	irun(CS);
	ihold(CS*multiplier);
	val_mA = mA;
}

uint16_t TMC5041Stepper::rms_current() {
	return (float)(irun()+1)/32.0 * (vsense()?0.180:0.325)/(Rsense+0.02) / 1.41421 * 1000;
}

void TMC5041Stepper::setCurrent(uint16_t mA, float R, float multiplier) { rms_current(mA, multiplier, R); }
uint16_t TMC5041Stepper::getCurrent() {	return val_mA; }

void TMC5041Stepper::SilentStepStick5041(uint16_t current) { rms_current(current); }



// void TMC5041Stepper::sg_current_decrease(uint8_t value) {
	// switch(value) {
		// case 32: sedn(0b00); break;
		// case  8: sedn(0b01); break;
		// case  2: sedn(0b10); break;
		// case  1: sedn(0b11); break;
	// }
// }
// uint8_t TMC5041Stepper::sg_current_decrease() {
	// switch(sedn()) {
		// case 0b00: return 32;
		// case 0b01: return  8;
		// case 0b10: return  2;
		// case 0b11: return  1;
	// }
	// return 0;
// }
