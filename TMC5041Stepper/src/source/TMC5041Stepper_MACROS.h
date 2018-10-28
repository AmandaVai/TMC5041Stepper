#ifndef TMC5041Stepper_MACROS_H
#define TMC5041Stepper_MACROS_H
#include "TMC5041Stepper.h"
#include "../TMC5041Stepper_REGDEFS.h"

#define TMC_WRITE_REG(R) 	send5041(TMC5041_WRITE|REG_##R, &R##_sr);

#define TMC_READ_REG(R)   	send5041(TMC5041_READ|REG_##R, &R##_sr); return R##_sr;

#define TMC_READ_REG_R(R)   tmp_sr=0; send5041(TMC5041_READ|REG_##R, &tmp_sr); return tmp_sr;


#define TMC_MOD_REG(REG, SETTING) 	REG##_sr &= ~SETTING##_bm; \
								REG##_sr |= ((uint32_t)B<<SETTING##_bp)&SETTING##_bm; \
								TMC_WRITE_REG(REG);

#define TMC_GET_BYTE(REG, SETTING) 	return (REG()&SETTING##_bm) >> SETTING##_bp;

#define TMC_GET_BYTE_R(REG, SETTING) return (REG()&SETTING##_bm) >> SETTING##_bp;

#define TMC_GET_BIT(REG, SETTING) 	return (bool)((REG()&SETTING##_bm) >> SETTING##_bp);

#define TMC_PRINT(R, SETTING)	send5041(TMC5041_READ|REG_##R, &R##_sr); Serial.print(B); Serial.println((R()&SETTING##_bm) >> SETTING##_bp, DEC);

#endif
