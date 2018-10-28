#pragma once

//#define TMC5041DEBUG
#include <Arduino.h>
#include <stdint.h>
#include <SPI.h>

#define TMC5041STEPPER_VERSION 0x020402 // v2.4.2

class TMC5041Stepper {
	public:
		TMC5041Stepper(uint16_t pinCS);
		TMC5041Stepper(uint16_t pinEN, uint16_t pinCS);
		//TMC5041Stepper(uint16_t pinEN, uint16_t pinDIR, uint16_t pinStep, uint16_t pinCS, uint16_t pinMOSI, uint16_t pinMISO, uint16_t pinSCK);
		void begin();
		void checkStatus();
		void rms_current(uint16_t mA, float multiplier=0.5, float RS=0.11);
		uint16_t rms_current();
		void SilentStepStick5041(uint16_t mA);
		void setCurrent(uint16_t mA, float Rsense, float multiplier);
		uint16_t getCurrent();
		bool checkOT();
		bool getOTPW();
		void clear_otpw();
		bool isEnabled();
		void push();
		uint8_t test_connection();
		// GCONF
		uint32_t GCONF();
		void GCONF(								uint32_t value);
		void poscmp_enable(bool B);
		void test_mode(bool B);				
		void shaft1(bool B);					
		void shaft2(bool B);					
		void lock_gconf(bool B); 				
		bool poscmp_enable();					
		bool test_mode();						
		bool shaft1();						
		bool shaft2();						
		bool lock_gconf(); 					


		// IHOLD_IRUN
		void IHOLD_IRUN_1(uint32_t input);
		uint32_t IHOLD_IRUN_1();
		void IHOLD_IRUN_2(uint32_t input);
		uint32_t IHOLD_IRUN_2();
		void 	ihold(							uint8_t B);
		void 	irun(								uint8_t B);
		void 	iholddelay(					uint8_t B);
		uint8_t ihold();
		uint8_t irun();
		uint8_t iholddelay();
		// GSTAT
		void 	GSTAT(							uint8_t input);
		uint8_t GSTAT();
		bool 	reset();
		bool 	drv_err1();
		bool 	drv_err2();
		bool 	uv_cp();
		// X_COMPARE
		void X_COMPARE( int32_t input);
		// IOIN
		uint32_t 	IOIN();
		bool 		step();
		bool 		dir();
		bool 		dcen_cfg4();
		bool 		dcin_cfg5();
		bool 		drv_enn_cfg6();
		bool 		dco();
		uint8_t 	version();
		// TZEROWAIT
		void TZEROWAIT_1(						uint32_t input);
		void TZEROWAIT_2(						uint32_t input);
		// AMAX
		void AMAX_1(					uint32_t input);
		uint32_t AMAX_1();
		void AMAX_2(					uint32_t input);
		uint32_t AMAX_2();
		// VMAX
		void VMAX_1(						uint32_t input);
		uint32_t VMAX_1();
		void VMAX_2(						uint32_t input);
		uint32_t VMAX_2();
		// RAMPMODE
		void RAMPMODE_1(						uint32_t input);
		uint32_t RAMPMODE_1();
		void RAMPMODE_2(						uint32_t input);
		uint32_t RAMPMODE_2();
		// A1
		void A1_1(				uint32_t input);
		void A1_2(				uint32_t input);
		// V1
		void V1_1(					uint32_t input);
		void V1_2(					uint32_t input);
		// DMAX
		void DMAX_1(						uint32_t input);
		void DMAX_2(						uint32_t input);
		// D1
		void D1_1(						uint32_t input);
		void D1_2(						uint32_t input);
		// VSTOP
		void VSTOP_1(				uint32_t input);
		void VSTOP_2(				uint32_t input);
		// VSTART
		void VSTART_1(				uint32_t input);
		void VSTART_2(				uint32_t input);
		// R: VACTUAL
		int32_t VACTUAL_1(); 
		int32_t VACTUAL_2();
		// XTARGET
		void XTARGET_2(						int32_t input);
		int32_t XTARGET_2();
		void XTARGET_MSG_2();
		void XTARGET_1(						int32_t input);
		int32_t XTARGET_1();
		void XTARGET_MSG_1();
		// XACTUAL
		void XACTUAL_2(						int32_t input);
		int32_t XACTUAL_2();
		void XACTUAL_MSG_2();
		void XACTUAL_1(						int32_t input);
		int32_t XACTUAL_1();
		void XACTUAL_MSG_1();
		// XLATCH
		int32_t XLATCH_1();
		void XLATCH_MSG_1();
		int32_t XLATCH_2();
		void XLATCH_MSG_2();
		// RAMP_STAT
		uint32_t RAMP_STAT_1();
		uint8_t position_reached_1();
		uint8_t vzero_1();
		uint32_t RAMP_STAT_2();
		uint8_t position_reached_2();
		uint8_t vzero_2();
		uint8_t status_sg_1();
		uint8_t status_sg_2();

		uint8_t second_move_1()	;
		uint8_t second_move_2()	;

		uint8_t t_zerowait_active_1();
		uint8_t t_zerowait_active_2();

		uint8_t velocity_reached_1();
		uint8_t velocity_reached_2();

		uint8_t event_pos_reached_1();
		uint8_t event_pos_reached_2();
		
		uint8_t event_stop_sg_1();
		uint8_t event_stop_sg_2();

		uint8_t event_stop_r_1();
		uint8_t event_stop_r_2();

		uint8_t event_stop_l_1();
		uint8_t event_stop_l_2();

		uint8_t status_latch_r_1();
		uint8_t status_latch_r_2();

		uint8_t status_latch_l_1();
		uint8_t status_latch_l_2();

		uint8_t status_stop_r_1();
		uint8_t status_stop_r_2();

		uint8_t status_stop_l_1();
		uint8_t status_stop_l_2();
		
		// SW_MODE
		uint32_t SW_MODE_1();
		void en_softstop_1( uint8_t B );
		void latch_r_inactive_1( uint8_t B );
		void latch_r_active_1( uint8_t B );	
		void latch_l_inactive_1( uint8_t B );	
		void latch_l_active_1( uint8_t B );	
		void pol_stop_r_1( uint8_t B );	
		void pol_stop_l_1( uint8_t B );	
		void stop_r_enable_1( uint8_t B );	
		void stop_l_enable_1( uint8_t B );
		void sg_stop_1( uint8_t B );
		void swap_lr_1( uint8_t B );
		uint32_t SW_MODE_2();
		void en_softstop_2( uint8_t B );
		void latch_r_inactive_2( uint8_t B );
		void latch_r_active_2( uint8_t B );	
		void latch_l_inactive_2( uint8_t B );	
		void latch_l_active_2( uint8_t B );	
		void pol_stop_r_2( uint8_t B );	
		void pol_stop_l_2( uint8_t B );	
		void stop_r_enable_2( uint8_t B );	
		void stop_l_enable_2( uint8_t B );
		void sg_stop_2( uint8_t B );
		void swap_lr_2( uint8_t B );
		// POSITION INITIALIZATION
		void Ini_pos_1();
		void Ini_pos_2();
		// MVP
		void MVP_1( bool dir, uint32_t pas);
		void MVP_2( bool dir, uint32_t pas);
		// Rotate
		void RO_1( bool dir, uint32_t amax, uint32_t vmax);
		void RO_2( bool dir, uint32_t amax, uint32_t vmax);
		// RFS
		void RFS_1( bool dir);
		void RFS_2( bool dir);
		// MST
		void MST_1();
		void MST_2();
		// uint8_t XACTUAL_get_byte();
		// // TPOWERDOWN
		// uint8_t TPOWERDOWN();
		// void TPOWERDOWN(					uint8_t input);
		// // TSTEP
		// uint32_t TSTEP();
		// // TPWMTHRS
		// uint32_t TPWMTHRS();
		// void TPWMTHRS(						uint32_t input);
		// VCOOLTHRS
		uint32_t VCOOLTHRS_1();
		void VCOOLTHRS_1(						uint32_t input);
		uint32_t VCOOLTHRS_2();
		void VCOOLTHRS_2(						uint32_t input);
		// VHIGH
		uint32_t VHIGH_1();
		void VHIGH_1(								uint32_t input);
		uint32_t VHIGH_2();
		void VHIGH_2(								uint32_t input);
		// // XDRIRECT
		// uint32_t XDIRECT();
		// void XDIRECT(							uint32_t input);
		// void coil_A(							int16_t 	B);
		// void coil_B(							int16_t 	B);
		// int16_t coil_A();
		// int16_t coil_B();
		// // VDCMIN
		// uint32_t VDCMIN();
		// void VDCMIN(							uint32_t input);
		// MSCNT
		uint16_t MSCNT_1();
		uint16_t MSCNT_2();
		// MSCURACT
		uint32_t MSCURACT_1();
		int16_t cur_a_1();
		int16_t cur_b_1();
		uint32_t MSCURACT_2();
		int16_t cur_a_2();
		int16_t cur_b_2();
		// CHOPCONF
		uint32_t CHOPCONF_1();
		void CHOPCONF_1(						uint32_t value);
		void toff_1(								uint8_t B);
		uint32_t CHOPCONF_2();
		void CHOPCONF_2(						uint32_t value);
		void toff_2(								uint8_t B);
		void hstrt(							uint8_t B);
		void hend(								uint8_t B);
		void fd(									uint8_t B);
		void disfdcc(							bool 		B);
		void rndtf(								bool 		B);
		void chm(									bool 		B);
		void tbl_1(									uint8_t B);
		void tbl_2(									uint8_t B);
		void vsense(							bool 		B);
		void vhighfs(							bool 		B);
		void vhighchm(						bool 		B);
		void sync(								uint8_t B);
		void mres_1(								uint8_t B);
		void mres_2(								uint8_t B);
		void intpol(							bool 		B);
		void dedge(								bool 		B);
		void diss2g(							bool 		B);
		uint8_t toff_1();
		uint8_t toff_2();
		uint8_t hstrt();
		uint8_t hend();
		uint8_t fd();
		bool 	disfdcc();
		bool 	rndtf();
		bool 	chm();
		uint8_t tbl_1();
		uint8_t tbl_2();
		bool 	vsense();
		bool 	vhighfs();
		bool 	vhighchm();
		uint8_t sync();
		uint8_t mres_1();
		uint8_t mres_2();
		bool 	intpol();
		bool 	dedge();
		bool 	diss2g();
		// COOLCONF
		void COOLCONF_1(uint32_t value);
		uint32_t COOLCONF_1();
		void semin_1(								uint8_t B);
		void seup_1(								uint8_t B);
		void semax_1(								uint8_t B);
		void sedn_1(								uint8_t B);
		void seimin_1(							bool 		B);
		void sgt_1(									int8_t B);
		void sfilt_1(								bool 		B);
		uint8_t semin_1();
		uint8_t seup_1();
		uint8_t semax_1();
		uint8_t sedn_1();
		bool seimin_1();
		int8_t sgt_1();
		bool sfilt_1();
		void COOLCONF_2(uint32_t value);
		uint32_t COOLCONF_2();
		void semin_2(								uint8_t B);
		void seup_2(								uint8_t B);
		void semax_2(								uint8_t B);
		void sedn_2(								uint8_t B);
		void seimin_2(							bool 		B);
		void sgt_2(									int8_t B);
		void sfilt_2(								bool 		B);
		uint8_t semin_2();
		uint8_t seup_2();
		uint8_t semax_2();
		uint8_t sedn_2();
		bool seimin_2();
		int8_t sgt_2();
		bool sfilt_2();
		// PWMCONF
		void PWMCONF_1(							uint32_t value);
		uint32_t PWMCONF_1();
		void PWMCONF_2(							uint32_t value);
		uint32_t PWMCONF_2();
		void pwm_ampl_1(						uint8_t B);
		void pwm_grad_1(						uint8_t B);
		void pwm_freq_1(						uint8_t B);
		void pwm_autoscale_1(				bool		B);
		void freewheel_1(						uint8_t B);
		uint8_t pwm_ampl_1();
		uint8_t pwm_grad_1();
		uint8_t pwm_freq_1();
		bool 	pwm_autoscale_1();
		uint8_t freewheel_1();
		void pwm_ampl_2(						uint8_t B);
		void pwm_grad_2(						uint8_t B);
		void pwm_freq_2(						uint8_t B);
		void pwm_autoscale_2(				bool		B);
		void freewheel_2(						uint8_t B);
		uint8_t pwm_ampl_2();
		uint8_t pwm_grad_2();
		uint8_t pwm_freq_2();
		bool 	pwm_autoscale_2();
		uint8_t freewheel_2();
		// PWM_STATUS
		uint32_t PWM_STATUS_1();
		uint32_t PWM_STATUS_2();

		// DRVSTATUS
		uint32_t DRV_STATUS_1();
		uint16_t sg_result_1();
		bool fsactive_1();
		uint8_t cs_actual_1();
		bool stallguard_1();
		bool ot_1();
		bool otpw_1();
		bool s2ga_1();
		bool s2gb_1();
		bool ola_1();
		bool olb_1();
		bool stst_1();
		uint32_t DRV_STATUS_2();
		uint16_t sg_result_2();
		bool fsactive_2();
		uint8_t cs_actual_2();
		bool stallguard_2();
		bool ot_2();
		bool otpw_2();
		bool s2ga_2();
		bool s2gb_2();
		bool ola_2();
		bool olb_2();
		bool stst_2();
		// // PWM_SCALE
		// uint8_t PWM_SCALE();
		// // ENCM_CTRL
		// uint8_t ENCM_CTRL();
		// void ENCM_CTRL(						uint8_t input);
		// void inv(									bool B);
		// void maxspeed(						bool B);
		// bool inv();
		// bool maxspeed();
		// // LOST_STEPS
		// uint32_t LOST_STEPS();

		// Helper functions
		void microsteps_1( uint16_t ms);
		uint16_t microsteps_1();
		void microsteps_2( uint16_t ms);
		uint16_t microsteps_2();
		void blank_time(uint8_t value);
		uint8_t blank_time();
		void hysteresis_end(int8_t value);
		int8_t hysteresis_end();
		void hysteresis_start(uint8_t value);
		uint8_t hysteresis_start();
		void sg_current_decrease(uint8_t value);
		uint8_t sg_current_decrease();

		// Aliases

		// RC
		inline uint8_t 	status_flags()										__attribute__((always_inline)) { return GSTAT(); 										}
		// R
		inline uint32_t input()														__attribute__((always_inline)) { return IOIN(); 										}
		// W: IHOLD_IRUN
		inline uint8_t 	hold_current()										__attribute__((always_inline)) { return ihold(); 										}
		inline uint8_t 	run_current()											__attribute__((always_inline)) { return irun(); 										}
		inline uint8_t 	hold_delay()											__attribute__((always_inline)) { return iholddelay(); 							}
		inline void 		hold_current(			 uint8_t value) __attribute__((always_inline)) {				ihold(value); 							}
		inline void 		run_current(			 uint8_t value) __attribute__((always_inline)) {				irun(value); 								}
		inline void 		hold_delay(				 uint8_t value) __attribute__((always_inline)) {				iholddelay(value); 					}
		// // W
		// inline uint8_t 	power_down_delay()								__attribute__((always_inline)) { return TPOWERDOWN(); 							}
		// inline void 		power_down_delay(	 uint8_t value) __attribute__((always_inline)) { 				TPOWERDOWN(value); 					}
		// // R
		// inline uint32_t microstep_time()									__attribute__((always_inline)) { return TSTEP(); 										}
		// W
		// inline uint32_t stealth_max_speed()								__attribute__((always_inline)) { return TPWMTHRS(); 								}
		// inline void 		stealth_max_speed(uint32_t value)	__attribute__((always_inline)) {				TPWMTHRS(value); 						}
		// W
		// inline uint32_t coolstep_min_speed()							__attribute__((always_inline)) { return TCOOLTHRS(); 								}
		// inline void    coolstep_min_speed(uint32_t value) __attribute__((always_inline)) {				TCOOLTHRS(value); 					}
		// // W
		// inline uint32_t mode_sw_speed()										__attribute__((always_inline)) { return THIGH(); 										}
		// inline void 		mode_sw_speed(		uint32_t value)	__attribute__((always_inline)) {				THIGH(value); 							}
		// // RW: XDIRECT
		// inline int16_t 	coil_A_current()									__attribute__((always_inline)) { return coil_A(); 									}
		// inline void 		coil_A_current(		 int16_t value)	__attribute__((always_inline)) {				coil_B(value); 							}
		// inline int16_t 	coil_B_current()									__attribute__((always_inline)) { return coil_A(); 									}
		// inline void 		coil_B_current(		 int16_t value)	__attribute__((always_inline)) {				coil_B(value); 							}
		// W
		// inline uint32_t DCstep_min_speed()								__attribute__((always_inline)) { return VDCMIN(); 									}
		// inline void 		DCstep_min_speed(	uint32_t value)	__attribute__((always_inline)) {				VDCMIN(value); 							}
		// RW: CHOPCONF
//		inline uint8_t 	off_time()												__attribute__((always_inline)) { return toff(); 										}
//		inline uint8_t 	hysteresis_start()								__attribute__((always_inline)) { return hstrt(); 										}
//		inline int8_t 	hysteresis_low()									__attribute__((always_inline)) { return hend(); 										}
		inline int8_t 	hysteresis_low()									__attribute__((always_inline)) { return hysteresis_end(); 					}
		inline uint8_t 	fast_decay_time()									__attribute__((always_inline)) { return fd(); 											}
		inline bool 		disable_I_comparator()						__attribute__((always_inline)) { return disfdcc(); 									}
		inline bool 		random_off_time()									__attribute__((always_inline)) { return rndtf(); 										}
		inline bool 		chopper_mode()										__attribute__((always_inline)) { return chm(); 											}
//		inline uint8_t 	blank_time()											__attribute__((always_inline)) { return tbl(); 											}
		inline bool 		high_sense_R()										__attribute__((always_inline)) { return vsense(); 									}
		inline bool 		fullstep_threshold()							__attribute__((always_inline)) { return vhighfs(); 									}
		inline bool 		high_speed_mode()									__attribute__((always_inline)) { return vhighchm(); 								}
		inline uint8_t 	sync_phases()											__attribute__((always_inline)) { return sync(); 										}
//		inline uint16_t microsteps()											__attribute__((always_inline)) { return mres(); 										}
		inline bool 		interpolate()											__attribute__((always_inline)) { return intpol(); 									}
		inline bool 		double_edge_step()								__attribute__((always_inline)) { return dedge(); 										}
		inline bool 		disable_short_protection()				__attribute__((always_inline)) { return diss2g(); 									}
//		inline void 		off_time(					 uint8_t value)	__attribute__((always_inline)) {				toff(value); 								}
//		inline void 		hysteresis_start(	 uint8_t value)	__attribute__((always_inline)) {				hstrt(value); 							}
//		inline void 		hysteresis_low(		  int8_t value)	__attribute__((always_inline)) {				hend(value); 								}
		inline void 		hysteresis_low(		  int8_t value)	__attribute__((always_inline)) {				hysteresis_end(value); 			}
		inline void 		fast_decay_time(	 uint8_t value)	__attribute__((always_inline)) {				fd(value); 									}
		inline void 		disable_I_comparator( bool value)	__attribute__((always_inline)) {				disfdcc(value);							}
		inline void 		random_off_time(			bool value)	__attribute__((always_inline)) {				rndtf(value); 							}
		inline void 		chopper_mode(					bool value)	__attribute__((always_inline)) {				chm(value); 								}
//		inline void 		blank_time(				 uint8_t value)	__attribute__((always_inline)) {				tbl(value); 								}
		inline void 		high_sense_R(					bool value)	__attribute__((always_inline)) {				vsense(value); 							}
		inline void 		fullstep_threshold(		bool value)	__attribute__((always_inline)) {				vhighfs(value); 						}
		inline void 		high_speed_mode(			bool value)	__attribute__((always_inline)) {				vhighchm(value); 						}
		inline void 		sync_phases(			 uint8_t value)	__attribute__((always_inline)) {				sync(value); 								}
//		inline void			microsteps(				uint16_t value)	__attribute__((always_inline)) {				mres(value); 								}
		inline void 		interpolate(					bool value)	__attribute__((always_inline)) {				intpol(value); 							}
		inline void 		double_edge_step(			bool value)	__attribute__((always_inline)) {				dedge(value); 							}
		inline void 	disable_short_protection(bool value)__attribute__((always_inline)) {				diss2g(value); 							}
		// // W: COOLCONF
		// inline uint8_t 	sg_min()													__attribute__((always_inline)) { return semin(); 										}
		// inline uint8_t 	sg_step_width()										__attribute__((always_inline)) { return seup(); 										}
		// inline uint8_t 	sg_max()													__attribute__((always_inline)) { return semax(); 										}
// //		inline uint8_t 	sg_current_decrease()							__attribute__((always_inline)) { return sedn(); 										}
		// inline uint8_t 	smart_min_current()								__attribute__((always_inline)) { return seimin(); 									}
		// inline int8_t 	sg_stall_value()									__attribute__((always_inline)) { return sgt(); 											}
		// inline bool 		sg_filter()												__attribute__((always_inline)) { return sfilt(); 										}
		// inline void 		sg_min(						 uint8_t value)	__attribute__((always_inline)) {				semin(value); 							}
		// inline void 		sg_step_width(		 uint8_t value)	__attribute__((always_inline)) {				seup(value); 								}
		// inline void 		sg_max(						 uint8_t value)	__attribute__((always_inline)) {				semax(value); 							}
// //		inline void 		sg_current_decrease(uint8_t value)__attribute__((always_inline)) {				sedn(value); 								}
		// inline void 		smart_min_current( uint8_t value)	__attribute__((always_inline)) {				seimin(value); 							}
		// inline void 		sg_stall_value(			int8_t value)	__attribute__((always_inline)) {				sgt(value); 								}
		// inline void 		sg_filter(						bool value)	__attribute__((always_inline)) {				sfilt(value); 							}
		// W: PWMCONF
		// inline uint8_t 	stealth_amplitude()								__attribute__((always_inline)) { return pwm_ampl(); 								}
		// inline uint8_t 	stealth_gradient()								__attribute__((always_inline)) { return pwm_grad(); 								}
		// inline uint8_t 	stealth_freq()										__attribute__((always_inline)) { return pwm_freq(); 								}
		// inline bool 		stealth_autoscale()								__attribute__((always_inline)) { return pwm_autoscale(); 						}
		// inline bool 		stealth_symmetric()								__attribute__((always_inline)) { return pwm_symmetric(); 						}
		// inline uint8_t 	standstill_mode()									__attribute__((always_inline)) { return freewheel(); 								}
		// inline void 		stealth_amplitude( uint8_t value)	__attribute__((always_inline)) {				pwm_ampl(value); 						}
		// inline void 		stealth_gradient(	 uint8_t value)	__attribute__((always_inline)) {				pwm_grad(value); 						}
		// inline void 		stealth_freq(			 uint8_t value)	__attribute__((always_inline)) {				pwm_freq(value); 						}
		// inline void 		stealth_autoscale(		bool value)	__attribute__((always_inline)) {				pwm_autoscale(value); 			}
		// inline void 		stealth_symmetric(		bool value)	__attribute__((always_inline)) {				pwm_symmetric(value); 			}
		// inline void 		standstill_mode(	 uint8_t value)	__attribute__((always_inline)) {				freewheel(value); 					}
		// // W: ENCM_CTRL
		// inline bool 		invert_encoder()									__attribute__((always_inline)) { return inv(); 											}
		// inline void 		invert_encoder(				bool value)	__attribute__((always_inline)) {				inv(value); 								}
		// R: DRV_STATUS
		//inline uint32_t DRVSTATUS()												__attribute__((always_inline)) { return DRV_STATUS(); 							}

		// Backwards compatibility
		inline void hysterisis_end(int8_t value) __attribute__((always_inline)) { hysteresis_end(value); }
		inline int8_t hysterisis_end() __attribute__((always_inline)) { return hysteresis_end(); }
		inline void hysterisis_start(uint8_t value) __attribute__((always_inline)) { hysteresis_start(value); }
		inline uint8_t hysterisis_start() __attribute__((always_inline)) { return hysteresis_start(); }


		float Rsense = 0.11;
		bool _started;
		uint8_t status_response;
		bool flag_otpw = false;

		// Stored settings for Marlin LCD
		struct {
			uint16_t I_rms = 0;
			bool stealthChop_enabled = false;
			uint8_t hybrid_thrs = 0;
			int8_t homing_thrs = 0;
			uint8_t cs_actual = 0;
			uint16_t sg_result = 0;
		} stored;

	private:
		//char string1[100] = " ";
		//const uint8_t WRITE     = 0b10000000;
		//const uint8_t READ      = 0b00000000;
		uint16_t _pinEN        = 0xFFFF;
		uint16_t _pinSTEP      = 0xFFFF;
		uint16_t _pinCS        = 0xFFFF;
		//const int MOSI_PIN    = 12;
		//const int MISO_PIN    = 11;
		//const int SCK_PIN     = 13;
		uint16_t _pinDIR       = 0xFFFF;

		// Shadow registers
		uint32_t 			GCONF_sr 		= 0x00000000UL,
							DRV_STATUS_1_sr = 0x00000000UL,
							DRV_STATUS_2_sr = 0x00000000UL,
							MSCNT_1_sr 		= 0x00000000UL,
							MSCNT_2_sr 		= 0x00000000UL,							
							MSCURACT_1_sr 	= 0x00000000UL,
							MSCURACT_2_sr 	= 0x00000000UL,	
							X_COMPARE_sr 	= 0x00000000UL,
							IHOLD_IRUN_1_sr = 0x00000000UL,
							IHOLD_IRUN_2_sr = 0x00000000UL,
							TSTEP_sr 		= 0x00000000UL,
							TPWMTHRS_sr 	= 0x00000000UL,
							XDIRECT_sr 		= 0x00000000UL,
							VDCMIN_sr 		= 0x00000000UL,
							MSLUT0_sr 		= 0x00000000UL,
							MSLUT1_sr 		= 0x00000000UL,
							MSLUT2_sr 		= 0x00000000UL,
							MSLUT3_sr 		= 0x00000000UL,
							MSLUT4_sr 		= 0x00000000UL,
							MSLUT5_sr 		= 0x00000000UL,
							MSLUT6_sr 		= 0x00000000UL,
							MSLUT7_sr 		= 0x00000000UL,
							MSLUTSEL_sr 	= 0x00000000UL,
							CHOPCONF_1_sr 	= 0x00000000UL,
							CHOPCONF_2_sr 	= 0x00000000UL,
							COOLCONF_1_sr 	= 0x00000000UL,
							COOLCONF_2_sr 	= 0x00000000UL,
							DCCTRL_sr 		= 0x00000000UL,
							PWMCONF_1_sr 	= 0x00000000UL,
							PWMCONF_2_sr 	= 0x00000000UL,
							tmp_sr 			= 0x00000000UL,
							TPOWERDOWN_sr 	= 0x00000000UL,
							ENCM_CTRL_sr 	= 0x00000000UL,
							GSTAT_sr		= 0x00000000UL,
							MSLUTSTART_sr 	= 0x00000000UL,
							RAMPMODE_1_sr 	= 0x00000001UL,
							RAMPMODE_2_sr 	= 0x00000001UL,
							RAMP_STAT_1_sr 	= 0x00000000UL,
							RAMP_STAT_2_sr 	= 0x00000000UL,
							AMAX_1_sr 		= 0x00000000UL,
							VMAX_1_sr 		= 0x00000000UL,
							A1_1_sr 		= 0x00000000UL,
							V1_1_sr 		= 0x00000000UL,
							DMAX_1_sr 		= 0x00000000UL,
							D1_1_sr 		= 0x00000000UL,
							VSTOP_1_sr 		= 0x00000000UL,
							VSTART_1_sr 	= 0x00000000UL,
							AMAX_2_sr 		= 0x00000000UL,
							VMAX_2_sr 		= 0x00000000UL,
							A1_2_sr 		= 0x00000000UL,
							V1_2_sr 		= 0x00000000UL,
							DMAX_2_sr 		= 0x00000000UL,
							D1_2_sr 		= 0x00000000UL,
							VSTOP_2_sr 		= 0x00000000UL,
							VSTART_2_sr 	= 0x00000000UL,
							XTARGET_1_sr 	= 0x00000000L,
							XACTUAL_1_sr 	= 0x00000000L,
							XTARGET_2_sr 	= 0x00000000L,
							XACTUAL_2_sr 	= 0x00000000L,
							XLATCH_1_sr 	= 0x00000000L,
							XLATCH_2_sr 	= 0x00000000L,
							TZEROWAIT_1_sr 	= 0x00000000UL,
							TZEROWAIT_2_sr 	= 0x00000000UL,
							VACTUAL_1_sr	= 0x00000000UL,
							VACTUAL_2_sr	= 0x00000000UL,
							SW_MODE_1_sr	= 0x00000000UL,
							SW_MODE_2_sr	= 0x00000000UL,
							VCOOLTHRS_1_sr	= 0x00000000UL,
							VCOOLTHRS_2_sr	= 0x00000000UL,
							PWM_STATUS_1_sr	= 0x00000000UL,
							PWM_STATUS_2_sr	= 0x00000000UL,
							VHIGH_1_sr		= 0x00000000UL,
							VHIGH_2_sr		= 0x00000000UL;

		void send5041(uint8_t addressByte, uint32_t *config);

		uint16_t val_mA  = 0;
		bool uses_sw_spi = false;
};
