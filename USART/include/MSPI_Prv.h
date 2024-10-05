/*
 * MSPI_Prv.h
 *
 *  Created on: Aug 31, 2024
 *      Author: WIN
 */

#ifndef MSPI_PRV_H_
#define MSPI_PRV_H_

#define SPI_1_BASE_ADRESS   0x40013000

typedef struct
{
	uint32 SPI_CR1;
	uint32 SPI_CR2;
	uint32 SPI_SR;
	uint32 SPI_DR;
	uint32 SPI_CRCPR;
	uint32 SPI_RXCRCR;
	uint32 SPI_TXCRCR;
	uint32 SPI_I2SCFGR;
	uint32 SPI_I2SPR;


}MSPI_t;


#define SPI_1 ((volatile MSPI_t*)(SPI_1_BASE_ADRESS))


#endif /* MSPI_PRV_H_ */
