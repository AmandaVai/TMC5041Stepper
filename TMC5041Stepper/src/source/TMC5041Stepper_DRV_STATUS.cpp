#include "TMC5041Stepper.h"
#include "TMC5041Stepper_MACROS.h"

uint32_t TMC5041Stepper::DRV_STATUS_1() { TMC_READ_REG_R(DRV_STATUS_1); }

uint16_t TMC5041Stepper::sg_result_1(){ TMC_GET_BYTE_R(DRV_STATUS_1, SG_RESULT); 	}
bool TMC5041Stepper::fsactive_1()		{ TMC_GET_BYTE_R(DRV_STATUS_1, FSACTIVE); 	}
uint8_t TMC5041Stepper::cs_actual_1()	{ TMC_GET_BYTE_R(DRV_STATUS_1, CS_ACTUAL); 	}
bool TMC5041Stepper::stallguard_1()	{ TMC_GET_BYTE_R(DRV_STATUS_1, STALLGUARD); 	}
bool TMC5041Stepper::ot_1()			{ TMC_GET_BYTE_R(DRV_STATUS_1, OT); 			}
bool TMC5041Stepper::otpw_1()			{ TMC_GET_BYTE_R(DRV_STATUS_1, OTPW); 		}
bool TMC5041Stepper::s2ga_1()			{ TMC_GET_BYTE_R(DRV_STATUS_1, S2GA); 		}
bool TMC5041Stepper::s2gb_1()			{ TMC_GET_BYTE_R(DRV_STATUS_1, S2GB); 		}
bool TMC5041Stepper::ola_1()			{ TMC_GET_BYTE_R(DRV_STATUS_1, OLA); 			}
bool TMC5041Stepper::olb_1()			{ TMC_GET_BYTE_R(DRV_STATUS_1, OLB); 			}
bool TMC5041Stepper::stst_1()			{ TMC_GET_BYTE_R(DRV_STATUS_1, STST); 		}

// uint16_t TMC5041Stepper::sg_result_1()	{
	// uint32_t drv_status = 0x00000000UL;
	// Serial.print("drv_status=");
	// Serial.print(drv_status);
	// drv_status = DRV_STATUS_1();
	// Serial.print("\tdrv_status=");
	// Serial.print(drv_status);
	// Serial.print("\t");

	// return drv_status&SG_RESULT_bm;
// }

uint32_t TMC5041Stepper::DRV_STATUS_2() { TMC_READ_REG_R(DRV_STATUS_2); }

uint16_t TMC5041Stepper::sg_result_2(){ TMC_GET_BYTE_R(DRV_STATUS_2, SG_RESULT); 	}
bool TMC5041Stepper::fsactive_2()		{ TMC_GET_BYTE_R(DRV_STATUS_2, FSACTIVE); 	}
uint8_t TMC5041Stepper::cs_actual_2()	{ TMC_GET_BYTE_R(DRV_STATUS_2, CS_ACTUAL); 	}
bool TMC5041Stepper::stallguard_2()	{ TMC_GET_BYTE_R(DRV_STATUS_2, STALLGUARD); 	}
bool TMC5041Stepper::ot_2()			{ TMC_GET_BYTE_R(DRV_STATUS_2, OT); 			}
bool TMC5041Stepper::otpw_2()			{ TMC_GET_BYTE_R(DRV_STATUS_2, OTPW); 		}
bool TMC5041Stepper::s2ga_2()			{ TMC_GET_BYTE_R(DRV_STATUS_2, S2GA); 		}
bool TMC5041Stepper::s2gb_2()			{ TMC_GET_BYTE_R(DRV_STATUS_2, S2GB); 		}
bool TMC5041Stepper::ola_2()			{ TMC_GET_BYTE_R(DRV_STATUS_2, OLA); 			}
bool TMC5041Stepper::olb_2()			{ TMC_GET_BYTE_R(DRV_STATUS_2, OLB); 			}
bool TMC5041Stepper::stst_2()			{ TMC_GET_BYTE_R(DRV_STATUS_2, STST); 		}

// uint16_t TMC5041Stepper::sg_result_2()	{
	// uint32_t drv_status = 0x00000000UL;
	// Serial.print("drv_status=");
	// Serial.print(drv_status);
	// drv_status = DRV_STATUS_2();
	// Serial.print("\tdrv_status=");
	// Serial.print(drv_status);
	// Serial.print("\t");

	// return drv_status&SG_RESULT_bm;
// }