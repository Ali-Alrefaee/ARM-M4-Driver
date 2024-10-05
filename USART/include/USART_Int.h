/*
 * USART_Int.h
 *
 *  Created on: Aug 24, 2024
 *      Author: WIN
 */

#ifndef USART_INT_H_
#define USART_INT_H_


void MUSART_init(void);
void MUSART_SendData(uint8 Copy_u8Data);
uint8 MUSART_RecieveData(void);

#endif /* USART_INT_H_ */
