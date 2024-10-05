/*
 * MGPIO_Int.h
 *
 *  Created on: Aug 4, 2024
 *      Author: WIN
 */

#ifndef MGPIO_INT_H_
#define MGPIO_INT_H_

/****************Ports***********************/
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2

/***************Pins***********************/
#define PIN_0   0
#define PIN_1   1
#define PIN_2   2
#define PIN_3   3
#define PIN_4   4
#define PIN_5   5
#define PIN_6   6
#define PIN_7   7
#define PIN_8   8
#define PIN_9   9
#define PIN_10  10
#define PIN_11  11
#define PIN_12  12
#define PIN_13  13
#define PIN_14  14
#define PIN_15  15

/********************modes************************************/
#define INPUT_MODE             0
#define OUTPUT_MODE  		   1
#define ALTERNATIVE_FUNC_MODE  2
#define ANALOG_MODE            3

/*********************output modes***********************************/
#define OUT_PUSH_PULL   0
#define OUT_OPEN_DRAIN  1

/********************speed*************************************/
#define SPEED_LOW     0
#define SPEED_MEDUIEM 1
#define SPEED_HIGH    2
#define SPEED_VHIGH   3

/********************output value*************************************/
#define GPIO_LOW  0
#define GPIO_HIGH 1


/*******************input values************************************/
#define INPUT_NO_PULL   0
#define INPUT_PULL_UP   1
#define INPUT_PULL_DOWN 2

/*************************Alternative**************************************/
// UART Values
#define ALTR_UART_TX_1 7             //PA9   AF07
#define ALTR_UART_RX_1 7             //PA10   AF07

// SPI value
#define ALTR_SPI 0b0101


/****************************************Set Pins**********************************************************/

void MGPIO_VSetMode(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Mode);

void MGPIO_VSetOutputPinMode(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8OutMode,uint8 Copy_u8Speed);

void MGPIO_VSetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8  Copy_u8Data);

void MGPIO_VSetInputPinMode(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8InputMode);

void MGPIO_VGetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 * Copy_pu8Data);



/**********************************Set Ports***************************************************************/
void MGPIO_VSetPortMode(uint8 Copy_u8Port, uint8 Copy_u8Mode);
void MGPIO_VSetOutputPortMode(uint8 Copy_u8Port, uint8 Copy_u8OutMode, uint8 Copy_u8Speed) ;
void MGPIO_VSetPortValue(uint8 Copy_u8Port, uint8 portValue);
void MGPIO_VGetPortValue(uint8 Copy_u8Port, uint8 * Copy_pu8Data);


/********************Alternative**********************/
void MGPIO_vSetAlternativeMode(uint8 Copy_u8Port,uint8 Copy_u8Pin ,uint8 Copy_u8Alternative);



#endif /* MGPIO_INT_H_ */
