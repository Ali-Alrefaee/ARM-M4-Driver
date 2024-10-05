/*
 * NVIC_Prv.h
 *
 *  Created on: Jul 26, 2024
 *      Author: WIN
 */

#ifndef MNVIC_PRV_H_
#define MNVIC_PRV_H_

typedef struct
{
	uint32 ISER[8];
	uint32 RESERVED1[24];
	uint32 ICER[8];
	uint32 RESERVED2[24];
	uint32 ISPR[8];
	uint32 RESERVED3[24];
	uint32 ICPR[8];
	uint32 RESERVED4[24];
	uint32 IABR[8];
	uint32 RESERVED5[56];
	uint8 IPR[240];
	uint32 RESERVED6[580];
	uint32 STIR;


}MNVIC_t;


#define MNVIC_BASE_ADRESS   0xE000E100


#define NVIC       ((volatile MNVIC_t*)(MNVIC_BASE_ADRESS))
#define  AIRCR      *((volatile uint32*)(0xE000ED0C))






#endif /* MNVIC_PRV_H_ */
