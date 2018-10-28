#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"

// COOLCONF
uint32_t TMC5041Stepper::COOLCONF_1() { return COOLCONF_1_sr; }
void TMC5041Stepper::COOLCONF_1(uint32_t input) {
	COOLCONF_1_sr = input;
	TMC_WRITE_REG(COOLCONF_1);
}

void TMC5041Stepper::semin_1(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_1, SEMIN);		}
void TMC5041Stepper::seup_1(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_1, SEUP);		}
void TMC5041Stepper::semax_1(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_1, SEMAX);		}
void TMC5041Stepper::sedn_1(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_1, SEDN);		}
void TMC5041Stepper::seimin_1(	bool 	B )	{ TMC_MOD_REG(COOLCONF_1, SEIMIN);	}
void TMC5041Stepper::sgt_1(		int8_t  B )	{ TMC_MOD_REG(COOLCONF_1, SGT);		}
void TMC5041Stepper::sfilt_1(		bool 	B )	{ TMC_MOD_REG(COOLCONF_1, SFILT);		}

uint8_t TMC5041Stepper::semin_1()	{ TMC_GET_BYTE(COOLCONF_1, SEMIN);	}
uint8_t TMC5041Stepper::seup_1()	{ TMC_GET_BYTE(COOLCONF_1, SEUP);		}
uint8_t TMC5041Stepper::semax_1()	{ TMC_GET_BYTE(COOLCONF_1, SEMAX);	}
uint8_t TMC5041Stepper::sedn_1()	{ TMC_GET_BYTE(COOLCONF_1, SEDN);		}
bool TMC5041Stepper::seimin_1()	{ TMC_GET_BYTE(COOLCONF_1, SEIMIN);	}
int8_t TMC5041Stepper::sgt_1()	{ TMC_GET_BYTE(COOLCONF_1, SGT);		}
bool TMC5041Stepper::sfilt_1()	{ TMC_GET_BYTE(COOLCONF_1, SFILT);	}

// int8_t TMC5041Stepper::sgt_1() {
	// // Two's complement in a 7bit value
	// int8_t val = (COOLCONF_1()&SGT_bm) >> SGT_bp;
	// return val <= 63 ? val : val - 128;
// }

uint32_t TMC5041Stepper::COOLCONF_2() { return COOLCONF_2_sr; }
void TMC5041Stepper::COOLCONF_2(uint32_t input) {
	COOLCONF_2_sr = input;
	TMC_WRITE_REG(COOLCONF_2);
}

void TMC5041Stepper::semin_2(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_2, SEMIN);		}
void TMC5041Stepper::seup_2(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_2, SEUP);		}
void TMC5041Stepper::semax_2(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_2, SEMAX);		}
void TMC5041Stepper::sedn_2(		uint8_t B )	{ TMC_MOD_REG(COOLCONF_2, SEDN);		}
void TMC5041Stepper::seimin_2(	bool 	B )	{ TMC_MOD_REG(COOLCONF_2, SEIMIN);	}
void TMC5041Stepper::sgt_2(		int8_t  B )	{ TMC_MOD_REG(COOLCONF_2, SGT);		}
void TMC5041Stepper::sfilt_2(		bool 	B )	{ TMC_MOD_REG(COOLCONF_2, SFILT);		}

uint8_t TMC5041Stepper::semin_2()	{ TMC_GET_BYTE(COOLCONF_2, SEMIN);	}
uint8_t TMC5041Stepper::seup_2()	{ TMC_GET_BYTE(COOLCONF_2, SEUP);		}
uint8_t TMC5041Stepper::semax_2()	{ TMC_GET_BYTE(COOLCONF_2, SEMAX);	}
uint8_t TMC5041Stepper::sedn_2()	{ TMC_GET_BYTE(COOLCONF_2, SEDN);		}
bool TMC5041Stepper::seimin_2()	{ TMC_GET_BYTE(COOLCONF_2, SEIMIN);	}
int8_t TMC5041Stepper::sgt_2()	{ TMC_GET_BYTE(COOLCONF_2, SGT);		}
bool TMC5041Stepper::sfilt_2()	{ TMC_GET_BYTE(COOLCONF_2, SFILT);	}

// int8_t TMC5041Stepper::sgt_2() {
	// // Two's complement in a 7bit value
	// int8_t val = (COOLCONF_2()&SGT_bm) >> SGT_bp;
	// return val <= 63 ? val : val - 128;
// }