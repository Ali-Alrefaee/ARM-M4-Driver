/*
 * MRCC_Int.h
 *
 *  Created on: Jul 19, 2024
 *      Author: midoy
 */

#ifndef MRCC_INT_H_
#define MRCC_INT_H_



/********************BUSES***********************/
typedef enum
{
	AHB1=0,
	AHB2,
	APB1,
	APB2

}BUS;

/*****************************AHB1*******************************/
#define AHB1_GPIOA   0
#define AHB1_GPIOB   1
#define AHB1_GPIOC   2
#define AHB1_GPIOD   3
#define AHB1_GPIOE   4
#define AHB1_GPIOH   7
#define AHB1_CRC     12
#define AHB1_DMA1    21
#define AHB1_DMA2    22

/*****************************AHB2*******************************/
#define AHB2_OTGFS   7
/*****************************APB1*******************************/
#define APB1_TIM2     0
#define APB1_TIM3     1
#define APB1_TIM4     2
#define APB1_TIM5     3
#define APB1_WWDG     11
#define APB1_SPI2     14
#define APB1_SPI3     15
#define APB1_USART2   17
#define APB1_I2C1     21
#define APB1_I2C2     22
#define APB1_I2C3     23
#define APB1_PWR      28

/*****************************APB2*******************************/
#define APB2_TIM1     0
#define APB2_USART1   4
#define APB2_USART6   5
#define APB2_ADC1     8
#define APB2_SDIO     11
#define APB2_SPI1     12
#define APB2_SPI4     13
#define APB2_SYSCFG   14
#define APB2_TIM9     16
#define APB2_TIM10    17
#define APB2_TIM11    18

/**************************************************/



void MRCC_VInit(void);
void MRCC_VEnable_Clock_Peripheral(BUS Copy_uddtAdressBus,uint8 Copy_u8Peripheral);
void MRCC_VDisable_Clock_Peripheral(BUS Copy_uddtAdressBus,uint8 Copy_u8Peripheral);




#endif /* MRCC_INT_H_ */
