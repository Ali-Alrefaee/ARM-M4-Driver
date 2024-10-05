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
	MRCC_AHB1=0,
	MRCC_AHB2,
	MRCC_APB1,
	MRCC_APB2

}BUS;

/*****************************AHB1*******************************/
#define MRCC_AHB1_GPIOA   0
#define MRCC_AHB1_GPIOB   1
#define MRCC_AHB1_GPIOC   2
#define MRCC_AHB1_GPIOD   3
#define MRCC_AHB1_GPIOE   4
#define MRCC_AHB1_GPIOH   7
#define MRCC_AHB1_CRC     12
#define MRCC_AHB1_DMA1    21
#define MRCC_AHB1_DMA2    22

/*****************************AHB2*******************************/
#define MRCC_AHB2_OTGFS   7
/*****************************APB1*******************************/
#define MRCC_APB1_TIM2     0
#define MRCC_APB1_TIM3     1
#define MRCC_APB1_TIM4     2
#define MRCC_APB1_TIM5     3
#define MRCC_APB1_WWDG     11
#define MRCC_APB1_SPI2     14
#define MRCC_APB1_SPI3     15
#define MRCC_APB1_USART2   17
#define MRCC_APB1_I2C1     21
#define MRCC_APB1_I2C2     22
#define MRCC_APB1_I2C3     23
#define MRCC_APB1_PWR      28

/*****************************APB2*******************************/
#define MRCC_APB2_TIM1     0
#define MRCC_APB2_USART1   4
#define MRCC_APB2_USART6   5
#define MRCC_APB2_ADC1     8
#define MRCC_APB2_SDIO     11
#define MRCC_APB2_SPI1     12
#define MRCC_APB2_SPI4     13
#define MRCC_APB2_SYSCFG   14
#define MRCC_APB2_TIM9     16
#define MRCC_APB2_TIM10    17
#define MRCC_APB2_TIM11    18

/**************************************************/



void MRCC_VInit(void);
void MRCC_VEnable_Clock_Peripheral(BUS Copy_uddtAdressBus,uint8 Copy_u8Peripheral);
void MRCC_VDisable_Clock_Peripheral(BUS Copy_uddtAdressBus,uint8 Copy_u8Peripheral);




#endif /* MRCC_INT_H_ */
