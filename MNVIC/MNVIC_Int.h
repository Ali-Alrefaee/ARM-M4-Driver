/*
 * MNVIC_Int.h
 *
 *  Created on: Jul 26, 2024
 *      Author: WIN
 */

#ifndef MNVIC_INT_H_
#define MNVIC_INT_H_


#define VEKCTKEY            0x05FA0000
#define NVIC_DIV            32




typedef enum
{
	MNVIC_Group16Sub0 = 3,
	MNVIC_Group8Sub2,
	MNVIC_Group4Sub4,
	MNVIC_Group2Sub8,
	MNVIC_Group0Sub16

}MNVIC_Group_t;


typedef enum
{
	MNVIC_EXTI0 = 6,
	MNVIC_EXTI1,
	MNVIC_EXTI2,
	MNVIC_EXTI3,
	MNVIC_EXTI4

}MNVIC_INTERRUPT_NAME;


void MNVIC_vEnableInterrupt(MNVIC_INTERRUPT_NAME Copy_u8Intpos);
void MNVIC_vDisableInterrupt(MNVIC_INTERRUPT_NAME Copy_u8Intpos);
void MNVIC_vSetInterruptPendingFlag(MNVIC_INTERRUPT_NAME Copy_u8IntPos) ;
void MNVIC_vClearInterruptPendingFlag(MNVIC_INTERRUPT_NAME Copy_u8IntPos) ;
void MNVIC_vGetInterruptActiveFlag(MNVIC_INTERRUPT_NAME Copy_u8IntPos,uint8 *Copy_Read) ;
void MNVIC_vSetInterruptGroupMode(MNVIC_Group_t    Copy_uddtGroupMode);
void MNVIC_vSetInterruptPriority(MNVIC_INTERRUPT_NAME copy_u8IntPos , uint8 copy_u8GroupNum , uint8 copy_u8SubGroupNum);



#endif /* MNVIC_INT_H_ */
