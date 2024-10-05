/*
 * MRCC_Cfg.h
 *
 *  Created on: Jul 19, 2024
 *      Author: midoy
 */

#ifndef MRCC_CFG_H_
#define MRCC_CFG_H_


/***************type of external oscillator*************************/
#define HSE_Type      Crystal_CLOCK
/*
 * CHoose between
 * 1- RC_CLOCK       (Resistance and Capacitor clock) use one bin (bypass)
 * 2- Crystal_CLOCK
 */


/***********************select the clock generally*********************/
#define SYS_CLK        HSI_CLOCK
/*
 * CHoose between
 * 1- HSE_CLOCK
 * 2- HSI_CLOCK
 */


#endif /* MRCC_CFG_H_ */
