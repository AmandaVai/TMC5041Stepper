#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"


// PWMCONF
uint32_t TMC5041Stepper::PWMCONF_1() { return PWMCONF_1_sr; }
void TMC5041Stepper::PWMCONF_1(uint32_t input) {
	PWMCONF_1_sr = input;
	TMC_WRITE_REG(PWMCONF_1);
}

uint32_t TMC5041Stepper::PWMCONF_2() { return PWMCONF_2_sr; }
void TMC5041Stepper::PWMCONF_2(uint32_t input) {
	PWMCONF_2_sr = input;
	TMC_WRITE_REG(PWMCONF_2);
}

void TMC5041Stepper::pwm_ampl_1(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_1, PWM_AMPL);		}
void TMC5041Stepper::pwm_grad_1(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_1, PWM_GRAD);		}
void TMC5041Stepper::pwm_freq_1(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_1, PWM_FREQ);		}
void TMC5041Stepper::pwm_autoscale_1(	bool 	B )	{ TMC_MOD_REG(PWMCONF_1, PWM_AUTOSCALE);	}
void TMC5041Stepper::freewheel_1(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_1, FREEWHEEL);		}

uint8_t TMC5041Stepper::pwm_ampl_1()		{ TMC_GET_BYTE(PWMCONF_1, PWM_AMPL);		}
uint8_t TMC5041Stepper::pwm_grad_1()		{ TMC_GET_BYTE(PWMCONF_1, PWM_GRAD);		}
uint8_t TMC5041Stepper::pwm_freq_1()		{ TMC_GET_BYTE(PWMCONF_1, PWM_FREQ);		}
bool 	TMC5041Stepper::pwm_autoscale_1()	{ TMC_GET_BYTE(PWMCONF_1, PWM_AUTOSCALE);	}
uint8_t TMC5041Stepper::freewheel_1()		{ TMC_GET_BYTE(PWMCONF_1, FREEWHEEL);		}

void TMC5041Stepper::pwm_ampl_2(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_2, PWM_AMPL);		}
void TMC5041Stepper::pwm_grad_2(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_2, PWM_GRAD);		}
void TMC5041Stepper::pwm_freq_2(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_2, PWM_FREQ);		}
void TMC5041Stepper::pwm_autoscale_2(	bool 	B )	{ TMC_MOD_REG(PWMCONF_2, PWM_AUTOSCALE);	}
void TMC5041Stepper::freewheel_2(		uint8_t B )	{ TMC_MOD_REG(PWMCONF_2, FREEWHEEL);		}

uint8_t TMC5041Stepper::pwm_ampl_2()		{ TMC_GET_BYTE(PWMCONF_2, PWM_AMPL);		}
uint8_t TMC5041Stepper::pwm_grad_2()		{ TMC_GET_BYTE(PWMCONF_2, PWM_GRAD);		}
uint8_t TMC5041Stepper::pwm_freq_2()		{ TMC_GET_BYTE(PWMCONF_2, PWM_FREQ);		}
bool 	TMC5041Stepper::pwm_autoscale_2()	{ TMC_GET_BYTE(PWMCONF_2, PWM_AUTOSCALE);	}
uint8_t TMC5041Stepper::freewheel_2()		{ TMC_GET_BYTE(PWMCONF_2, FREEWHEEL);		}


// PWM_STATUS
uint32_t TMC5041Stepper::PWM_STATUS_1() { TMC_READ_REG_R(PWM_STATUS_1); }
uint32_t TMC5041Stepper::PWM_STATUS_2() { TMC_READ_REG_R(PWM_STATUS_2); }