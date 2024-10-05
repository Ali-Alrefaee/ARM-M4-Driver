/*
 * USART_Prv.h
 *
 *  Created on: Aug 24, 2024
 *      Author: WIN
 */

#ifndef USART_PRV_H_
#define USART_PRV_H_

#define USART_BASE_ADRESS  0x40011000

typedef struct
{
	uint32 SBK       :1;
	uint32 RWU       :1;
	uint32 RE        :1;
	uint32 TE        :1;
	uint32 IDLEIE    :1;
	uint32 RXNEIE    :1;
	uint32 TCIE      :1;
	uint32 TXEIE     :1;
	uint32 PEIE      :1;
	uint32 PS        :1;
	uint32 PCE       :1;
	uint32 WAKE      :1;
	uint32 M         :1;
	uint32 UE        :1;
	uint32 RESERVED1 :1;
	uint32 OVER8     :1;
	uint32 RESERVED2 :16;
}MUSART_CR1;


typedef struct
{
	uint32 USART_SR;
	uint32 USART_DR;
	uint32 USART_BRR;
	MUSART_CR1 USART_CR1;
	uint32 USART_CR2;
	uint32 USART_CR3;
	uint32 USART_GTPR;

}USART_t;


#define USART ((volatile USART_t*)(USART_BASE_ADRESS))


#endif /* USART_PRV_H_ */
