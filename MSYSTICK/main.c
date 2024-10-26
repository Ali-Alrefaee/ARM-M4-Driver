#include "STD_Types.h"
#include "BIT_Math.h"
#include "MRCC_Int.h"
#include "MGPIO_Int.h"
#include "MNVIC_Int.h"
#include "MEXTI_int.h"
#include "MSYSTICK_int.h"


uint8 startflage=0;
uint8 counter=0;
uint8 Arr[33]={0};
void func1(void);
void func2(void);




void main()
{

	MRCC_VInit();
	MRCC_VEnable_Clock_Peripheral(MRCC_AHB1 , MRCC_AHB1_GPIOA);
	MRCC_VEnable_Clock_Peripheral(MRCC_APB2 , MRCC_APB2_SYSCFG);
	MSYSYTICK_voidInit();

	MGPIO_VSetMode(PORT_A , PIN_0 , INPUT_MODE);
	MGPIO_VSetInputPinMode(PORT_A , PIN_0, INPUT_PULL_UP);

	MNVIC_VoidEnableInterrupt(6);
	MEXTI_voidInerruptSetPort(EXTI_LineZero , EXTI_PortA);
	MEXTI_voidInterruptTrigger(EXTI_LineZero , EXTI_Falling);
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero , EXTI_Enable);
	MSYSYTICK_voidCtrlIntState(SYSTICKEnable);
	MEXTI0_voidCallBack(func1);


	while(1)
	{

	}

}




void func1(void)
{


	if(startflage==0)
	{
		startflage=1;
		MSYSTICK_VoidCallbackUs(func2 , 15000);
	}
	else
	{
		Arr[counter]=(MSTK_u32GetElapsedTime()/2);
		counter++;
		MSYSTICK_VoidCallbackUs(func2 , 15000);

	}

}



void func2(void)
{
	startflage=0;
	counter=0;
	uint8 i=0;
	uint8 value=0;

	for(i=0 ; i<8 ; i++)
	{
		if(Arr[17+i]>1000 && Arr[i]<1300)
		{
			CLR_BIT(value , i);
		}
		else if(Arr[17+i]>2000 && Arr[17+i]<2500)
		{
			SET_BIT(value,i);
		}
	}

}
















