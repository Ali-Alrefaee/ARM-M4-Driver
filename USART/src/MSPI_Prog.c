/*
 * MSPI_Prog.c
 *
 *  Created on: Aug 31, 2024
 *      Author: WIN
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MSPI_Prv.h"
#include "MSPI_Int.h"

void MSPI_vInit(void)
{

	//master select
	SPI_1 -> SPI_CR1 |=(1<<2);

	//cpol -->high
	SPI_1 -> SPI_CR1 |=(1<<1);


	//spi Enable
	SPI_1 -> SPI_CR1 |=(1<<6);


}

void MSPI_vSlaveInit(void)
{
	//slave select
	SPI_1 -> SPI_CR1 &=~(1<<2);

	//cpol -->high
	SPI_1 -> SPI_CR1 |=(1<<1);


	//spi Enable
	SPI_1 -> SPI_CR1 |=(1<<6);

}


uint8 MSPI_u8Trancive(uint8 Copy_u8Data)
{
	while(GET_BIT(SPI_1->SPI_SR , 1)==0);
	SPI_1 -> SPI_DR = Copy_u8Data;
	while(GET_BIT(SPI_1->SPI_SR , 0)==0);

	return (uint8) SPI_1->SPI_DR;
}
