/*
 * USART_Prog.c
 *
 *  Created on: Aug 24, 2024
 *      Author: WIN
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "USART_Prv.h"
#include "USART_Int.h"


void MUSART_init(void)
{
	//OVER SAMBLE -->16
	USART->USART_CR1.OVER8=0;

	//BAUDRATE
	USART->USART_BRR=(104<<4)|(3);

	//WORD LENGHT -->8 BIT
	USART->USART_CR1.M=0;

	//PARITY --> OFF
	USART->USART_CR1.PCE=0;

	//TRANSMIT ENABLE
	USART->USART_CR1.TE=1;

	//RECIVE ENABLE
	USART->USART_CR1.RE=1;

	//USART ENABLE
	USART->USART_CR1.UE=1;

}

void MUSART_SendData(uint8 Copy_u8Data)
{
	while(!GET_BIT(USART->USART_SR , 7 ));
	USART->USART_DR = Copy_u8Data;
}

uint8 MUSART_RecieveData(void)
{
	while(!GET_BIT(USART->USART_SR , 5 ));
	return	(uint8) USART->USART_DR;
}



