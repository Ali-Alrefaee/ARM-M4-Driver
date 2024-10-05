/*
 * MGPIO_Int.h
 *
 *  Created on: Aug 4, 2024
 *      Author: WIN
 */

#ifndef MGPIO_INT_H_
#define MGPIO_INT_H_

/****************Ports***********************/
typedef enum
{
	MGPIO_PORT_A = 0,
	MGPIO_PORT_B ,
	MGPIO_PORT_C
}PORT;

/***************Pins***********************/
typedef enum
{
	MGPIO_PIN_0 = 0,
	MGPIO_PIN_1,
	MGPIO_PIN_2,
	MGPIO_PIN_3,
	MGPIO_PIN_4,
	MGPIO_PIN_5,
	MGPIO_PIN_6,
	MGPIO_PIN_7,
	MGPIO_PIN_8,
	MGPIO_PIN_9,
	MGPIO_PIN_10,
	MGPIO_PIN_11,
	MGPIO_PIN_12,
	MGPIO_PIN_13,
	MGPIO_PIN_14,
	MGPIO_PIN_15
}PIN;

/********************modes************************************/
typedef enum
{
	MGPIO_INPUT_MODE = 0,
	MGPIO_OUTPUT_MODE,
	MGPIO_ALTERNATIVE_FUNC_MODE,
	MGPIO_ANALOG_MODE
}MODE;

/*********************output modes***********************************/
typedef enum
{
	MGPIO_OUT_PUSH_PULL = 0,
	MGPIO_OUT_OPEN_DRAIN
}Output_Modes;


/********************speed*************************************/
typedef enum
{
	MGPIO_SPEED_LOW = 0,
	MGPIO_SPEED_MEDUIEM,
	MGPIO_SPEED_HIGH,
	MGPIO_SPEED_VHIGH
}SPEED;

/********************output value*************************************/
typedef enum
{
	MGPIO_LOW = 0,
	MGPIO_HIGH
}Output_Value;

/*******************input modes************************************/
typedef enum
{
	MGPIO_INPUT_NO_PULL = 0,
	MGPIO_INPUT_PULL_UP,
	MGPIO_INPUT_PULL_DOWN
}Input_Modes;


/*************************Alternative**************************************/
// UART Values
#define MGPIO_ALTR_UART_TX_1 7             //PA9   AF07
#define MGPIO_ALTR_UART_RX_1 7             //PA10   AF07

// SPI value
#define MGPIO_ALTR_SPI 0b0101


/****************************************Set Pins**********************************************************/

void MGPIO_VSetPinMode(PORT Copy_u8Port,PIN Copy_u8Pin,MODE Copy_u8Mode);

void MGPIO_VSetOutputPinMode(PORT Copy_u8Port,PIN Copy_u8Pin,Output_Modes Copy_u8OutMode,SPEED Copy_u8Speed);

void MGPIO_VSetPinValue(PORT Copy_u8Port,PIN Copy_u8Pin,Output_Value  Copy_u8Data);

void MGPIO_VSetInputPinMode(PORT Copy_u8Port,PIN Copy_u8Pin,Input_Modes Copy_u8InputMode);

void MGPIO_VGetPinValue(PORT Copy_u8Port,PIN Copy_u8Pin,uint8 * Copy_pu8Data);



/**********************************Set Ports***************************************************************/
void MGPIO_VSetPortMode(PORT Copy_u8Port, MODE Copy_u8Mode);
void MGPIO_VSetOutputPortMode(PORT Copy_u8Port, Output_Modes Copy_u8OutMode, SPEED Copy_u8Speed) ;
void MGPIO_VSetPortValue(PORT Copy_u8Port, Output_Value portValue);
void MGPIO_VSetInputPortMode(PORT Copy_u8Port,Input_Modes Copy_u8InputMode);
void MGPIO_VGetPortValue(PORT Copy_u8Port, uint8 * Copy_pu8Data);


/********************Alternative**********************/
void MGPIO_vSetAlternativeMode(PORT Copy_u8Port,PIN Copy_u8Pin ,uint8 Copy_u8Alternative);



#endif /* MGPIO_INT_H_ */
