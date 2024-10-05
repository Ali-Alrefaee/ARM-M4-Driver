/*
 * MRCC_Prv.h
 *
 *  Created on: Jul 19, 2024
 *      Author: midoy
 */

#ifndef MRCC_PRV_H_
#define MRCC_PRV_H_



typedef struct
{
	uint32 RCC_CR;
	uint32 RCC_PLLCFGR;
	uint32 RCC_CFGR;
	uint32 RCC_CIR;
	uint32 RCC_AHB1RSTR;
	uint32 RCC_AHB2RSTR;
	uint32 RESERVED1;
	uint32 RESERVED2;
	uint32 RCC_APB1RSTR;
	uint32 RCC_APB2RSTR;
	uint32 RESERVED3;
	uint32 RESERVED4;
	uint32 RCC_AHB1ENR;
	uint32 RCC_AHB2ENR;
	uint32 RESERVED5;
	uint32 RESERVED6;
	uint32 RCC_APB1ENR;
	uint32 RCC_APB2ENR;
	uint32 RESERVED7;
	uint32 RESERVED8;
	uint32 RCC_AHB1LPENR;
	uint32 RCC_AHB2LPENR;
	uint32 RESERVED9;
	uint32 RESERVED10;
	uint32 RCC_APB1LPENR;
	uint32 RCC_APB2LPENR;
	uint32 RESERVED11;
	uint32 RESERVED12;
	uint32 RCC_BDCR;
	uint32 RCC_CSR;
	uint32 RESERVED13;
	uint32 RESERVED14;
	uint32 RCC_SSCGR;
	uint32 RCC_PLLI2SCFGR;
	uint32 RESERVED15;
	uint32 RCC_DCKCFGR;
}MRCC_t;

#define RCC_BASE_ADRESS  0x40023800

#define RCC ((volatile MRCC_t*)(RCC_BASE_ADRESS))


/***************type of external oscillator*************************/
#define RC_CLOCK  0
#define Crystal_CLOCK 1

/*******************select the clock generally********************/
#define HSE_CLOCK 1
#define HSI_CLOCK 0



/****************No of bin of HSE*******/
#define  MRCC_HSEBYP 18
#define  MRCC_HSEON  16
#define  MRCC_HSERDY 17

/****************No of bin of HSI*******/
#define  MRCC_HSION 0
#define  MRCC_HSIRDY 1

/****************No of bin of System clock switch*******/
#define SW0 0
#define SW1 1

/*************Just as a Musk*********************/
#define CLOCK_Musk 3


#endif /* MRCC_PRV_H_ */
