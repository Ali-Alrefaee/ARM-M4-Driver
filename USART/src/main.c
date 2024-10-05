#include "STD_Types.h"
#include "BIT_Math.h"
#include "MRCC_Int.h"
#include "MGPIO_Int.h"
#include "USART_Int.h"









void main(void)
{

	MRCC_VInit();
	MRCC_VEnable_Clock_Peripheral(AHB1, AHB1_GPIOB);
	MRCC_VEnable_Clock_Peripheral(AHB2, 4);
	MUSART_init();

	MGPIO_VSetMode(PORT_B , PIN_6 , ALTERNATIVE_FUNC_MODE);
	MGPIO_VSetMode(PORT_B , PIN_7 , ALTERNATIVE_FUNC_MODE);


	MGPIO_vSetAlternativeMode(PORT_B , PIN_6,7);
	MGPIO_vSetAlternativeMode(PORT_B , PIN_7,7);





	while(1)
	{
		MUSART_SendData('A');
	}
}
