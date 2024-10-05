#include "STD_Types.h"
#include "BIT_Math.h"
#include "MGPIO_Prv.h"
#include "MGPIO_Int.h"






void MGPIO_VSetPinMode(PORT Copy_u8Port,PIN Copy_u8Pin,MODE Copy_u8Mode)
{

	switch (Copy_u8Port) {
	case MGPIO_PORT_A:
		//check for the pins that must not be changed
		if ((Copy_u8Pin == MGPIO_PIN_13) || (Copy_u8Pin == MGPIO_PIN_14) || (Copy_u8Pin == MGPIO_PIN_15) )
		{
			//do nothing
		}
		else
		{
			GPIOA->MODER &=~(GPIO_MASK<<(Copy_u8Pin*2));
			GPIOA->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2));
		}
		break;
	case MGPIO_PORT_B:
		//check for the pins that must not be changed
		if ((Copy_u8Pin == MGPIO_PIN_2) || (Copy_u8Pin == MGPIO_PIN_3) || (Copy_u8Pin == MGPIO_PIN_4) )
		{
			//do nothing
		}
		else
		{
			GPIOB->MODER &=~(GPIO_MASK<<(Copy_u8Pin*2));
			GPIOB->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2));
		}
		break;
	case MGPIO_PORT_C:
		GPIOC->MODER &=~(GPIO_MASK<<(Copy_u8Pin*2));
		GPIOC->MODER |=(Copy_u8Mode<<(Copy_u8Pin*2));
		break;
	default:
		break;
	}

}

void MGPIO_VSetOutputPinMode(PORT Copy_u8Port,PIN Copy_u8Pin,Output_Modes Copy_u8OutMode,SPEED Copy_u8Speed)
{

	switch (Copy_u8Port) {
	case MGPIO_PORT_A:
		//check for the pins that must not be changed
		if ((Copy_u8Pin == MGPIO_PIN_13) || (Copy_u8Pin == MGPIO_PIN_14) || (Copy_u8Pin == MGPIO_PIN_15) )
		{
			//do nothing
		}
		else
		{

			//PUSH_PULL OR OPEN_DRAIN
			// if we have pin as 1 and we want to or it with 0 it have no action and it still 1 so want to clear first
			GPIOA->OTYPER &=~(1<<Copy_u8Pin);
			GPIOA->OTYPER |=(Copy_u8OutMode<<Copy_u8Pin);

			//SPEED
			GPIOA->OSPEEDR &=~(GPIO_MASK<<(Copy_u8Pin*2));
			GPIOA->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
		}

		break;
	case MGPIO_PORT_B:
		if ((Copy_u8Pin == MGPIO_PIN_2) || (Copy_u8Pin == MGPIO_PIN_3) || (Copy_u8Pin == MGPIO_PIN_4) )
		{
			//do nothing
		}
		else
		{
			//PUSH_PULL OR OPEN_DRAIN
			GPIOB->OTYPER &=~(1<<Copy_u8Pin);
			GPIOB->OTYPER |=(Copy_u8OutMode<<Copy_u8Pin);

			//SPEED
			GPIOB->OSPEEDR &=~(GPIO_MASK<<(Copy_u8Pin*2));
			GPIOB->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
		}
		break;
	case MGPIO_PORT_C:
		//PUSH_PULL OR OPEN_DRAIN
		GPIOC->OTYPER &=~(1<<Copy_u8Pin);
		GPIOC->OTYPER |=(Copy_u8OutMode<<Copy_u8Pin);

		//SPEED
		GPIOC->OSPEEDR &=~(GPIO_MASK<<(Copy_u8Pin*2));
		GPIOC->OSPEEDR |=(Copy_u8Speed<<(Copy_u8Pin*2));
		break;
	default:
		break;


	}
}


void MGPIO_VSetPinValue(PORT Copy_u8Port,PIN Copy_u8Pin,Output_Value  Copy_u8Data)
{
	switch (Copy_u8Port) {
	case MGPIO_PORT_A:
		//check for the pins that must not be changed
		if ((Copy_u8Pin == MGPIO_PIN_13) || (Copy_u8Pin == MGPIO_PIN_14) || (Copy_u8Pin == MGPIO_PIN_15) )
		{
			//do nothing
		}
		else
		{
			GPIOA->ODR &=~(1<<Copy_u8Pin);
			GPIOA->ODR |=(Copy_u8Data<<Copy_u8Pin);
		}
		break;
	case MGPIO_PORT_B:
		if ((Copy_u8Pin == MGPIO_PIN_2) || (Copy_u8Pin == MGPIO_PIN_3) || (Copy_u8Pin == MGPIO_PIN_4) )
		{
			//do nothing
		}
		else
		{
			GPIOB->ODR &=~(1<<Copy_u8Pin);
			GPIOB->ODR |=(Copy_u8Data<<Copy_u8Pin);
		}
		break;
	case MGPIO_PORT_C:
		GPIOC->ODR &=~(1<<Copy_u8Pin);
		GPIOC->ODR |=(Copy_u8Data<<Copy_u8Pin);
		break;
	default:
		break;
	}
}


void MGPIO_VSetInputPinMode(PORT Copy_u8Port,PIN Copy_u8Pin,Input_Modes Copy_u8InputMode)
{
	switch (Copy_u8Port) {
	case MGPIO_PORT_A:
		//check for the pins that must not be changed
		if ((Copy_u8Pin == MGPIO_PIN_13) || (Copy_u8Pin == MGPIO_PIN_14) || (Copy_u8Pin == MGPIO_PIN_15) )
		{
			//do nothing
		}
		else
		{
			GPIOA->PUPDR &=~(GPIO_MASK<<(Copy_u8Pin*2));
			GPIOA->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
		}
		break;

	case MGPIO_PORT_B:
		if ((Copy_u8Pin == MGPIO_PIN_2) || (Copy_u8Pin == MGPIO_PIN_3) || (Copy_u8Pin == MGPIO_PIN_4) )
		{
			//do nothing
		}
		else
		{
			GPIOB->PUPDR &=~(GPIO_MASK<<(Copy_u8Pin*2));
			GPIOB->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
		}
		break;

	case MGPIO_PORT_C:
		GPIOC->PUPDR &=~(GPIO_MASK<<(Copy_u8Pin*2));
		GPIOC->PUPDR |=(Copy_u8InputMode<<(Copy_u8Pin*2));
		break;

	default:
		break;
	}
}

void MGPIO_VGetPinValue(PORT Copy_u8Port,PIN Copy_u8Pin,uint8 * Copy_pu8Data)
{
	switch (Copy_u8Port) {
	case MGPIO_PORT_A:
		* Copy_pu8Data= GET_BIT(GPIOA->IDR,Copy_u8Pin);
		break;

	case MGPIO_PORT_B:
		* Copy_pu8Data= GET_BIT(GPIOB->IDR,Copy_u8Pin);
		break;

	case MGPIO_PORT_C:
		* Copy_pu8Data= GET_BIT(GPIOC->IDR,Copy_u8Pin);
		break;

	default:
		break;

	}
}


/*****************************************************************************************************/
/* Ports */
/*****************************************************************************************************/

void MGPIO_VSetPortMode(PORT Copy_u8Port, MODE Copy_u8Mode)
{

	uint32 modeValue = 0;

	// Iterate through all pins and set the modeValue accordingly
	for (int i = 0; i < 16; i++)
	{
		modeValue |= (Copy_u8Mode << (2 * i));
	}

	// Switch on the port to set the modeValue in the corresponding MODER register
	switch (Copy_u8Port) {
	// If port is A
	case MGPIO_PORT_A:
		GPIOA->MODER = modeValue;
		break;

		// If port is B
	case MGPIO_PORT_B:
		GPIOB->MODER = modeValue;
		break;

		// If port is C
	case MGPIO_PORT_C:
		GPIOC->MODER = modeValue;
		break;
	}

}

// Function to set the output mode (push pull , open drain) of a specific port
void MGPIO_VSetOutputPortMode(PORT Copy_u8Port, Output_Modes Copy_u8OutMode, SPEED Copy_u8Speed)
{
	// Check if portID is within valid range

	uint32 modeValue = 0;
	uint32 speedValue = 0;

	// Iterate through all pins and set the speedValue accordingly
	for (int i = 0; i < 16; i++)
	{
		modeValue |= (Copy_u8OutMode << (i));
	}



	// Iterate through all pins and set the speedValue accordingly
	for (int i = 0; i < 16; i++)
	{
		speedValue |= (Copy_u8Speed << (2 * i));
	}

	// Switch on the port to set the portOutputMode in the corresponding OTYPER register
	switch (Copy_u8Port) {
	// If port is A
	case MGPIO_PORT_A:
		GPIOA->OTYPER = modeValue;
		GPIOA->OSPEEDR = speedValue;
		break;

		// If port is B
	case MGPIO_PORT_B:
		GPIOB->OTYPER = modeValue;
		GPIOB->OSPEEDR = speedValue;
		break;

		// If port is C
	case MGPIO_PORT_C:
		GPIOC->OTYPER = modeValue;
		GPIOC->OSPEEDR = speedValue;
		break;
	}

}



// Function to set the port value (reset , set) of a specific port
void MGPIO_VSetPortValue(PORT Copy_u8Port, Output_Value portValue)
{

	uint32 Portvalue = 0;

	// Iterate through all pins and set the speedValue accordingly
	for (int i = 0; i < 16; i++) {
		Portvalue |= (portValue << (i));
	}
	// Switch on the port to set the specified portValue in the corresponding ODR register
	switch (Copy_u8Port) {
	// If port is A
	case MGPIO_PORT_A:
		GPIOA->ODR = Portvalue;
		break;

		// If port is B
	case MGPIO_PORT_B:
		GPIOB->ODR = Portvalue;
		break;

		// If port is C
	case MGPIO_PORT_C:
		GPIOC->ODR = Portvalue;
		break;
	}

}

// Function to get the port value (reset , set) of a specific port
void MGPIO_VGetPortValue(PORT Copy_u8Port, uint8 * Copy_pu8Data)
{

	// Switch on the port to read the value from the corresponding IDR register
	switch (Copy_u8Port) {
	// If port is A
	case MGPIO_PORT_A:
		* Copy_pu8Data = (uint16) (GPIOA->IDR);
		break;

		// If port is B
	case MGPIO_PORT_B:
		* Copy_pu8Data = (uint16) (GPIOB->IDR);
		break;

		// If port is C
	case MGPIO_PORT_C:
		* Copy_pu8Data = (uint16) (GPIOC->IDR);
		break;

	default:
		// Do Nothing
		break;
	}

}


void MGPIO_VSetInputPortMode(PORT Copy_u8Port,Input_Modes Copy_u8InputMode)
{

	uint32 modeValue = 0;

	// Iterate through all pins and set the speedValue accordingly
	for (int i = 0; i < 16; i++) {
		modeValue |= (Copy_u8InputMode << (2*i));
	}


	switch (Copy_u8Port) {
	// If port is A
	case MGPIO_PORT_A:
		GPIOA->PUPDR = modeValue;
		break;

		// If port is B
	case MGPIO_PORT_B:
		GPIOB->PUPDR = modeValue;
		break;

		// If port is C
	case MGPIO_PORT_C:
		GPIOC->PUPDR = modeValue;
		break;
	}

}


/*******************************************************************************/
void MGPIO_vSetAlternativeMode(PORT Copy_u8Port,PIN Copy_u8Pin ,uint8 Copy_u8Alternative)
{
	if (Copy_u8Pin < MGPIO_PIN_8 )
	{
		switch (Copy_u8Port) {
		case MGPIO_PORT_A:
			//setting the mode
			GPIOA->AFRL &= ~(GPIO_ALTERNATIVE_MASK<<(Copy_u8Pin*4));
			GPIOA->AFRL |= (Copy_u8Alternative<<(Copy_u8Pin*4));
			break;
		case MGPIO_PORT_B:
			//check for the pins that must not be changed
			if ((Copy_u8Pin == MGPIO_PIN_2) || (Copy_u8Pin == MGPIO_PIN_3) || (Copy_u8Pin == MGPIO_PIN_4) )
			{
				//do nothing
			}
			else
			{
				//setting the mode
				GPIOA->AFRL &= ~(GPIO_ALTERNATIVE_MASK<<(Copy_u8Pin*4));
				GPIOB->AFRL |= (Copy_u8Alternative<<(Copy_u8Pin*4));
			}
			break;
		case MGPIO_PORT_C:
			//setting the mode
			GPIOA->AFRL &= ~(GPIO_ALTERNATIVE_MASK<<(Copy_u8Pin*4));
			GPIOC->AFRL |= (Copy_u8Alternative<<(Copy_u8Pin*4));
			break;
		default:
			break;
		}
	}
	else if ( (Copy_u8Pin >= MGPIO_PIN_8) && (Copy_u8Pin <= MGPIO_PIN_15) )
	{
		switch (Copy_u8Port) {
		case MGPIO_PORT_A:
			//check for the pins that must not be changed
			if ((Copy_u8Pin == MGPIO_PIN_13) || (Copy_u8Pin == MGPIO_PIN_14) || (Copy_u8Pin == MGPIO_PIN_15) )
			{
				//do nothing
			}
			else
			{
				//setting the mode
				GPIOA->AFRL &= ~(GPIO_ALTERNATIVE_MASK<<(Copy_u8Pin*4));
				GPIOA->AFRH |= (Copy_u8Alternative<<((Copy_u8Pin-8)*4));
			}
			break;
		case MGPIO_PORT_B:
			//setting the mode
			GPIOA->AFRL &= ~(GPIO_ALTERNATIVE_MASK<<(Copy_u8Pin*4));
			GPIOB->AFRH |= (Copy_u8Alternative<<((Copy_u8Pin-8)*4));
			break;
		case MGPIO_PORT_C:
			//setting the mode
			GPIOA->AFRL &= ~(GPIO_ALTERNATIVE_MASK<<(Copy_u8Pin*4));
			GPIOA->AFRH |= (Copy_u8Alternative<<((Copy_u8Pin-8)*4));
			break;
		default:
			break;
		}

	}
	else
	{

	}
}


