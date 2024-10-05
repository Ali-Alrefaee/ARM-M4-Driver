/*
 * MRCC_Cfg.h
 *
 *  Created on: Jul 19, 2024
 *      Author: midoy
 */

#ifndef MRCC_CFG_H_
#define MRCC_CFG_H_


/***********************select the clock generally*********************/
#define SYS_CLK        MRCC_HSI_CLOCK
/*
 * CHoose between
 * 1- MRCC_HSE_CLOCK
 * 2- MRCC_HSI_CLOCK
 */


/***************type of external oscillator*************************/
#define HSE_Type      MRCC_Crystal_CLOCK
/*
 * CHoose between
 * 1- MRCC_RC_CLOCK       (Resistance and Capacitor clock) use one bin (bypass)
 * 2- MRCC_Crystal_CLOCK
 */



#endif /* MRCC_CFG_H_ */
