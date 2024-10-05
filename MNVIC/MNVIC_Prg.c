/*
 * MNVIC_Prg.c
 *
 *  Created on: Jul 26, 2024
 *      Author: WIN
 */
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "MNVIC_Int.h"
#include "MNVIC_Prv.h"

static uint8 copy_u8Global;

void MNVIC_vEnableInterrupt(MNVIC_INTERRUPT_NAME Copy_u8Intpos)
{
	NVIC ->ISER[Copy_u8Intpos / NVIC_DIV] |=(1<<(Copy_u8Intpos % NVIC_DIV)) ;
}

void MNVIC_vDisableInterrupt(MNVIC_INTERRUPT_NAME Copy_u8Intpos)
{
	NVIC ->ICER[Copy_u8Intpos / NVIC_DIV] |=(1<<(Copy_u8Intpos % NVIC_DIV)) ;
}

void MNVIC_vSetInterruptPendingFlag(MNVIC_INTERRUPT_NAME Copy_u8IntPos)
{
	NVIC ->ISPR[Copy_u8IntPos / NVIC_DIV] |=1<<(Copy_u8IntPos % NVIC_DIV);
}

void MNVIC_vClearInterruptPendingFlag(MNVIC_INTERRUPT_NAME Copy_u8IntPos)
{
	NVIC ->ICPR[Copy_u8IntPos/NVIC_DIV] |=1<<(Copy_u8IntPos % NVIC_DIV);
}

void MNVIC_vGetInterruptActiveFlag(MNVIC_INTERRUPT_NAME Copy_u8IntPos,uint8 *Copy_Read)
{
	*Copy_Read=GET_BIT((NVIC->IABR[Copy_u8IntPos / NVIC_DIV]),(Copy_u8IntPos % NVIC_DIV));
}

void MNVIC_vSetInterruptGroupMode(MNVIC_Group_t    Copy_uddtGroupMode)
{
	uint32  copy_u32Local;
	copy_u8Global = Copy_uddtGroupMode;
	copy_u32Local = VEKCTKEY | (Copy_uddtGroupMode << 8);
	AIRCR = copy_u32Local;
}

void MNVIC_vSetInterruptPriority(MNVIC_INTERRUPT_NAME copy_u8IntPos , uint8 copy_u8GroupNum , uint8 copy_u8SubGroupNum)
{
	switch (copy_u8Global)
	{
		case MNVIC_Group16Sub0 :
			NVIC -> IPR [copy_u8IntPos] = (copy_u8GroupNum << 4);
			break;
		case MNVIC_Group8Sub2 :
			NVIC -> IPR [copy_u8IntPos] = (copy_u8GroupNum << 5) | (copy_u8SubGroupNum<<4);
			break;
		case MNVIC_Group4Sub4 :
			NVIC -> IPR [copy_u8IntPos] = (copy_u8GroupNum << 6) | (copy_u8SubGroupNum<<4);
			break;
		case MNVIC_Group2Sub8 :
			NVIC -> IPR [copy_u8IntPos] = (copy_u8GroupNum << 7) | (copy_u8SubGroupNum<<4);
			break;
		case MNVIC_Group0Sub16 :
			NVIC -> IPR [copy_u8IntPos] = (copy_u8SubGroupNum << 4);
			break;
	}

}
