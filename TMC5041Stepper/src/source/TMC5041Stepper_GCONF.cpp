#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"

// GCONF
uint32_t TMC5041Stepper::GCONF() { TMC_READ_REG(GCONF); }

void TMC5041Stepper::GCONF(uint32_t input) {
	GCONF_sr = input;
	TMC_WRITE_REG(GCONF);
}

void TMC5041Stepper::poscmp_enable(bool B)			{ TMC_MOD_REG(GCONF, POSCMP_ENABLE);		}
void TMC5041Stepper::test_mode(bool B)				{ TMC_MOD_REG(GCONF, TEST_MODE);		}
void TMC5041Stepper::shaft1(bool B)					{ TMC_MOD_REG(GCONF, SHAFT1);			}
void TMC5041Stepper::shaft2(bool B)					{ TMC_MOD_REG(GCONF, SHAFT2);		}
void TMC5041Stepper::lock_gconf(bool B) 				{ TMC_MOD_REG(GCONF, LOCK_GCONF);				}


bool TMC5041Stepper::poscmp_enable()					{ TMC_GET_BYTE(GCONF, POSCMP_ENABLE);		}
bool TMC5041Stepper::test_mode()						{ TMC_GET_BYTE(GCONF, TEST_MODE);		}
bool TMC5041Stepper::shaft1()						{ TMC_GET_BYTE(GCONF, SHAFT1);			}
bool TMC5041Stepper::shaft2()						{ TMC_GET_BYTE(GCONF, SHAFT2);		}
bool TMC5041Stepper::lock_gconf() 					{ TMC_GET_BYTE(GCONF, LOCK_GCONF);				}


