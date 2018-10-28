#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"


/**
 *	Helper functions
 */

///////////////////////////////////////////////////////////////////////////////////////
// POSITION INITIALIZATION
void TMC5041Stepper::Ini_pos_1()	{
	do{
		Serial.print("Position --> ");
		XACTUAL_MSG_1();
		delay(100);
	}while(!position_reached_1());
}
void TMC5041Stepper::Ini_pos_2()	{
	do{
		Serial.print("Position --> ");
		XACTUAL_MSG_2();
		delay(100);
	}while(!position_reached_2());
}
/* The actual position wil be print until it reach the target position*/
///////////////////////////////////////////////////////////////////////////////////////
// MVP
void TMC5041Stepper::MVP_1(bool dir, uint32_t pas)	{
	A1_1(0x3E8);
	V1_1(0xC350); // Acceleration threshold veloci
	VSTOP_1(0xA); // Stop velocity near to zero
	RAMPMODE_1(0x0); // Target position move, ready to move
	if (dir==1) {
		XTARGET_1_sr = XACTUAL_1() + pas;
	}
	else {
		XTARGET_1_sr = XACTUAL_1() - pas;
	}
	TMC_WRITE_REG(XTARGET_1);	
}
void TMC5041Stepper::MVP_2(bool dir, uint32_t pas)	{
	A1_2(0x3E8);ty V1
	AMAX_1(0x1F4); // Acceleration above V1
	VMAX_1(0x304D0); 
	DMAX_1(0x2BC); // Deceleration above V1
	D1_1(0x578); // Deceleration below V1
	V1_2(0xC350); // Acceleration threshold velocity V1
	AMAX_2(0x1F4); // Acceleration above V1
	VMAX_2(0x304D0); 
	DMAX_2(0x2BC); // Deceleration above V1
	D1_2(0x578); // Deceleration below V1
	VSTOP_2(0xA); // Stop velocity near to zero
	RAMPMODE_2(0x0); // Target position move, ready to move
	if (dir==1) {
		XTARGET_2_sr = XACTUAL_2() + pas;
	}
	else {
		XTARGET_2_sr = XACTUAL_2() - pas;
	}
	TMC_WRITE_REG(XTARGET_2);	
}
//* Move to a position */ 

///////////////////////////////////////////////////////////////////////////////////////
// Rotate
void TMC5041Stepper::RO_1(bool dir, uint32_t amax, uint32_t vmax)	{ 
	AMAX_1(amax); // acceleration
	VMAX_1(vmax); // Max velocity 
	if (dir==1){
		RAMPMODE_1(0x1); // Positive velocity
	}
	else{
		RAMPMODE_1(0x2); // Negative velocity
	}
}

void TMC5041Stepper::RO_2(bool dir, uint32_t amax, uint32_t vmax)	{ 
	AMAX_2(amax); // acceleration
	VMAX_2(vmax); // Max velocity 
	if (dir==1){
		RAMPMODE_2(0x1); // Positive velocity
	}
	else{
		RAMPMODE_2(0x2); // Negative velocity
	}
}

///////////////////////////////////////////////////////////////////////////////////////
// RFS reference search
void TMC5041Stepper::RFS_1(bool dir)	{
	uint16_t mstep = microsteps_1();
	// Serial.print("Microsteps: ");
	// Serial.println(mstep);
	uint32_t pas = 100*mstep;
	uint32_t amax = 500*mstep;
	uint32_t vmax = 400*mstep;
	A1_1(500);
	V1_1(200);
	D1_1(50);
	DMAX_1(200);
	//VSTART(50);

	MVP_1(dir, pas);
	Serial.println("MVP");
	
	en_softstop_1(1); // enable soft stop
	sg_stop_1(0);
	latch_r_inactive_1(0);
	latch_r_active_1(1);
	latch_l_inactive_1(0);
	latch_l_active_1(1);
	pol_stop_l_1(1);
	pol_stop_r_1(1);
	stop_r_enable_1(1);
	stop_l_enable_1(1);
	
	// Serial.print("SW_MODE 1: ");
	// Serial.println(SW_MODE_1(), BIN);

	TZEROWAIT_1(0x2710); // Waiting time after ramping down to zero velocity before next movement (between 0-2sec)
	
	
	delay(1000);
	RO_1(!dir, amax, vmax);
	
	Serial.print("Rampstat avant RFS 1: ");
	Serial.println(RAMP_STAT_1(), BIN);
	
	do{
		delay(100);
		// Serial.print("VZERO: ");
		// Serial.println(vzero_1());
	}while(!vzero_1());
	
	Serial.print("Rampstat après RFS 1: ");
	Serial.println(RAMP_STAT_1(), BIN);
	
	RAMPMODE_1(3); // hold the velocity
	int32_t delta = XACTUAL_1() - XLATCH_1();
	XACTUAL_MSG_1();
	XLATCH_MSG_1();
	XACTUAL_1(delta);
	Serial.print("Delta: ");
	Serial.println(delta);
	delay(1000);
	XTARGET_1(0);
	//XTARGET_MSG_1();
	/* A move to position 0 will bring back the motor exactly to the switching pointer */
}

void TMC5041Stepper::RFS_2(bool dir)	{
	uint16_t mstep = microsteps_2();
	// Serial.print("Microsteps: ");
	// Serial.println(mstep);
	uint32_t pas = 100*mstep;
	uint32_t amax = 500*mstep;
	uint32_t vmax = 400*mstep;
	A1_2(500);
	V1_2(200);
	D1_2(50);
	DMAX_2(200);
	//VSTART(50);

	MVP_2( dir, pas);
	Serial.println("MVP");
	
	en_softstop_2(1); // enable soft stop
	sg_stop_2(0);
	latch_r_inactive_2(0);
	latch_r_active_2(1);
	latch_l_inactive_2(0);
	latch_l_active_2(1);
	pol_stop_l_2(1);
	pol_stop_r_2(1);
	stop_r_enable_2(1);
	stop_l_enable_2(1);
	
	// Serial.print("SW_MODE 2: ");
	// Serial.println(SW_MODE_2(), BIN);

	TZEROWAIT_2(0x2710); // Waiting time after ramping down to zero velocity before next movement (between 0-2sec)
	
	
	delay(1000);
	RO_2(!dir, amax, vmax);
	
	Serial.print("Rampstat avant RFS 2: ");
	Serial.println(RAMP_STAT_2(), BIN);
	
	do{
		delay(100);
		// Serial.print("VZERO: ");
		// Serial.println(vzero_2());
	}while(!vzero_2());
	
	Serial.print("Rampstat après RFS 2: ");
	Serial.println(RAMP_STAT_2(), BIN);
	
	RAMPMODE_2(3); // hold the velocity
	int32_t delta = XACTUAL_2() - XLATCH_2();
	XACTUAL_MSG_2();
	XLATCH_MSG_2();
	XACTUAL_2(delta);
	Serial.print("Delta: ");
	Serial.println(delta);
	delay(1000);
	XTARGET_2(0);
	//XTARGET_MSG_2();
	/* A move to position 0 will bring back the motor exactly to the switching pointer */
}
///////////////////////////////////////////////////////////////////////////////////////
// MST Stop motor movement
void TMC5041Stepper::MST_1()	{
	RAMPMODE_1(1); // Velocity mode
	VMAX_1(0); // Stop motor
}
void TMC5041Stepper::MST_2()	{
	RAMPMODE_2(1); // Velocity mode
	VMAX_2(0); // Stop motor
}
///////////////////////////////////////////////////////////////////////////////////////
// Microsteps
void TMC5041Stepper::microsteps_1(uint16_t ms) {
	switch(ms) {
		case 256: mres_1(0); break;
		case 128: mres_1(1); break;
		case  64: mres_1(2); break;
		case  32: mres_1(3); break;
		case  16: mres_1(4); break;
		case   8: mres_1(5); break;
		case   4: mres_1(6); break;
		case   2: mres_1(7); break;
		case   1: mres_1(8); break;
		default: break;
	}
}

void TMC5041Stepper::microsteps_2(uint16_t ms) {
	switch(ms) {
		case 256: mres_2(0); break;
		case 128: mres_2(1); break;
		case  64: mres_2(2); break;
		case  32: mres_2(3); break;
		case  16: mres_2(4); break;
		case   8: mres_2(5); break;
		case   4: mres_2(6); break;
		case   2: mres_2(7); break;
		case   1: mres_2(8); break;
		default: break;
	}
}

uint16_t TMC5041Stepper::microsteps_1() {
	switch(mres_1()) {
		case 0: return 256;
		case 1: return 128;
		case 2: return  64;
		case 3: return  32;
		case 4: return  16;
		case 5: return   8;
		case 6: return   4;
		case 7: return   2;
		case 8: return   1;
	}
	return 0;
}

uint16_t TMC5041Stepper::microsteps_2() {
	switch(mres_2()) {
		case 0: return 256;
		case 1: return 128;
		case 2: return  64;
		case 3: return  32;
		case 4: return  16;
		case 5: return   8;
		case 6: return   4;
		case 7: return   2;
		case 8: return   1;
	}
	return 0;
}