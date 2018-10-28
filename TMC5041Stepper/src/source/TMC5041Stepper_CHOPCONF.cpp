#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"

// CHOPCONF
uint32_t TMC5041Stepper::CHOPCONF_1() { TMC_READ_REG(CHOPCONF_1); }
void TMC5041Stepper::CHOPCONF_1(uint32_t input) { // Change the shadow register 
	CHOPCONF_1_sr = input;
	TMC_WRITE_REG(CHOPCONF_1);
}

void TMC5041Stepper::toff_1(		uint8_t B )	{ TMC_MOD_REG(CHOPCONF_1, TOFF);		}

uint32_t TMC5041Stepper::CHOPCONF_2() { TMC_READ_REG(CHOPCONF_2); }

void TMC5041Stepper::CHOPCONF_2(uint32_t input) { // Change the shadow register 
	CHOPCONF_2_sr = input;
	TMC_WRITE_REG(CHOPCONF_2);
}

void TMC5041Stepper::toff_2(		uint8_t B )	{ TMC_MOD_REG(CHOPCONF_2, TOFF);		}
/* TMC5041Stepper::toff
Define the function "toff" in the class "TMC5041"
B is the parameter
Call the function "TMC_MOD_REG(REG, SETTING)"
	REG = CHOPCONF, REG##_sr: 0x0000 0000UL // Correspond to the shadow register 
	SETTING = TOFF, SETTING##_bm: 0xFUL  // Correspond to the bits that can be changed
	REG##_sr &= ~SETTING##_bm: // Clear bits being set
		0x0000 0000UL &= ~0xFUL 
		0x0000 0000UL &= 0xFFFF FFF0UL
		REG##_sr = 0x0000 0000UL // The bits that cannot be changed are put to 0
	REG##_sr |= ((uint32_t)B<<SETTING##_bp)&SETTING##_bm; // Set new values (Only the bits that can change are modified by B, and the all is saved in the shadow register) 
	TMC_WRITE_REG(REG) // Call a new function
		send5041(TMC5041_WRITE|REG_##REG, &REG##_sr) // Call another function which will write the new values
			TMC5041_WRITE = 0x80; // Writing mode
			REG_CHOPCONF  = 0x6C;
			TMC5041_WRITE|REG_CHOPCONF // Correspond to adressByte 
			&REG##_sr = &CHOPCONF_sr // Coresspond to config	

*/
void TMC5041Stepper::tbl_1(		uint8_t B )	{ TMC_MOD_REG(CHOPCONF_1, TBL);		}
void TMC5041Stepper::mres_1(		uint8_t B )	{ TMC_MOD_REG(CHOPCONF_1, MRES);		}
uint8_t TMC5041Stepper::toff_1()		{ TMC_GET_BYTE(CHOPCONF_1, TOFF);		}
uint8_t TMC5041Stepper::tbl_1()		{ TMC_GET_BYTE(CHOPCONF_1, TBL);		}
uint8_t TMC5041Stepper::mres_1()		{ TMC_GET_BYTE(CHOPCONF_1, MRES);		}

void TMC5041Stepper::tbl_2(		uint8_t B )	{ TMC_MOD_REG(CHOPCONF_2, TBL);		}
void TMC5041Stepper::mres_2(		uint8_t B )	{ TMC_MOD_REG(CHOPCONF_2, MRES);		}
uint8_t TMC5041Stepper::toff_2()		{ TMC_GET_BYTE(CHOPCONF_2, TOFF);		}
uint8_t TMC5041Stepper::tbl_2()		{ TMC_GET_BYTE(CHOPCONF_2, TBL);		}
uint8_t TMC5041Stepper::mres_2()		{ TMC_GET_BYTE(CHOPCONF_2, MRES);		}