#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"

// IHOLD_IRUN
void TMC5041Stepper::IHOLD_IRUN_1(uint32_t input) {
	IHOLD_IRUN_1_sr = input;
	TMC_WRITE_REG(IHOLD_IRUN_1);
}
uint32_t TMC5041Stepper::IHOLD_IRUN_1() { return IHOLD_IRUN_1_sr; }

void TMC5041Stepper::IHOLD_IRUN_2(uint32_t input) {
	IHOLD_IRUN_2_sr = input;
	TMC_WRITE_REG(IHOLD_IRUN_2);
}
uint32_t TMC5041Stepper::IHOLD_IRUN_2() { return IHOLD_IRUN_2_sr; }


// void 	TMC5041Stepper::ihold(uint8_t B) 		{ TMC_MOD_REG(IHOLD_IRUN, IHOLD);		}
// void 	TMC5041Stepper::irun(uint8_t B)  		{ TMC_MOD_REG(IHOLD_IRUN, IRUN); 		}
// void 	TMC5041Stepper::iholddelay(uint8_t B)	{ TMC_MOD_REG(IHOLD_IRUN, IHOLDDELAY); 	}
// uint8_t TMC5041Stepper::ihold() 				{ TMC_GET_BYTE(IHOLD_IRUN, IHOLD);		}
// uint8_t TMC5041Stepper::irun()  				{ TMC_GET_BYTE(IHOLD_IRUN, IRUN); 		}
// uint8_t TMC5041Stepper::iholddelay()  			{ TMC_GET_BYTE(IHOLD_IRUN, IHOLDDELAY);	}
