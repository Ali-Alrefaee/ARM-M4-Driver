/*
 * MRCC_Prg.c
 *
 *  Created on: Jul 19, 2024
 *      Author: midoy
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "MRCC_Prv.h"
#include "MRCC_Cfg.h"
#include "MRCC_Int.h"


void MRCC_VInit(void)
{
	// HSI ,HSE
#if(SYS_CLK==HSE_CLOCK)

	//BYBASS PIN
#if(HSE_Type==Crystal_CLOCK)
	//CLR_BIT(RCC->RCC_CR,HSEBYP);
	RCC->RCC_CR &=~(1<<MRCC_HSEBYP);
#elif (HSE_Type==RC_CLOCK)
	//SET_BIT(RCC->RCC_CR,HSEBYP);
	RCC->RCC_CR |=(1<<MRCC_HSEBYP);
#endif

	//HSE_ON
	RCC->RCC_CR |=(1<<MRCC_HSEON);
	//Wait on flag
	while(!GET_BIT(RCC->RCC_CR,MRCC_HSERDY));
	//switch to HSE
	RCC->RCC_CFGR &=~(CLOCK_Musk<<SW0);
	RCC->RCC_CFGR |=(HSE_CLOCK<<SW0);
	//Turn off HSI
	RCC->RCC_CR &=~(1<<MRCC_HSION);  //For confirmation

#elif(SYS_CLK==HSI_CLOCK)
	//HSI_ON
	RCC->RCC_CR |=(1<<MRCC_HSION);
	//Wait on flag
	while(!GET_BIT(RCC->RCC_CR,MRCC_HSIRDY));
	//switch to HSI
	RCC->RCC_CFGR &=~(CLOCK_Musk<<SW0);
	RCC->RCC_CFGR |=(HSI_CLOCK<<SW0);

#endif
}

void MRCC_VEnable_Clock_Peripheral(BUS Copy_uddtAdressBus,uint8 Copy_u8Peripheral)
{

	switch (Copy_uddtAdressBus) {
	case AHB1:
		RCC->RCC_AHB1ENR |=(1<<Copy_u8Peripheral);
		break;
	case AHB2:
		RCC->RCC_AHB2ENR |=(1<<Copy_u8Peripheral);
		break;
	case APB1:
		RCC->RCC_APB1ENR |=(1<<Copy_u8Peripheral);
		break;
	case APB2:
		RCC->RCC_APB2ENR |=(1<<Copy_u8Peripheral);
		break;
	default:
		break;
	}
}

void MRCC_VDisable_Clock_Peripheral(BUS Copy_uddtAdressBus,uint8 Copy_u8Peripheral)
{

	switch (Copy_uddtAdressBus) {
	case AHB1:
		RCC->RCC_AHB1ENR &=~(1<<Copy_u8Peripheral);
		break;
	case AHB2:
		RCC->RCC_AHB2ENR &=~(1<<Copy_u8Peripheral);
		break;
	case APB1:
		RCC->RCC_APB1ENR &=~(1<<Copy_u8Peripheral);
		break;
	case APB2:
		RCC->RCC_APB2ENR &=~(1<<Copy_u8Peripheral);
		break;
	default:
		break;
	}

}

