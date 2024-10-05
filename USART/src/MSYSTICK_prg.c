#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MSYSTICK_prv.h"
#include "MSYSTICK_cfg.h"
#include "MSYSTICK_int.h"

static void(*Global_ptr)(void)=0;

void MSYSYTICK_voidInit(void)
{
#if (SYSTICK_Source==AHB)
	SYSTICK->CTRL |=1<<ClockSource;

#elif (SYSTICK_Source==AHB_DIVIDEBY8)

	SYSTICK->CTRL &=~(1<<ClockSource);

#endif
}

void MSYSYTICK_voidStart(uint32 Copy_u32Loadvalue)
{
	SYSTICK->LOAD = Copy_u32Loadvalue;
	SYSTICK->VAL =0;
	SYSTICK->CTRL |=1;
}

uint8   MSYSYTICK_voidReadFlag(void)
{
	return GET_BIT(SYSTICK->CTRL,CountFlag);
}

void MSYSYTICK_voidCtrlIntState(SYSTICKState Copy_State )
{
	switch (Copy_State){
	case SYSTICKEnable:
		SYSTICK->CTRL |=1<<TickInt;
		break;
	case SYSTICKDisable:
		SYSTICK->CTRL &=~(1<<TickInt);
		break;
	default:  break;
	}
}

uint32  MSTK_u32GetElapsedTime(void)
{
	return ((SYSTICK->LOAD)-(SYSTICK->VAL)) ;
}

uint32  MSTK_u32GetRemainingTime(void)
{
	return SYSTICK->VAL ;
}

void MSYSYTICK_voidDelayMs(uint32 Copy_u32Delayvalue){
	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	MSYSYTICK_voidStart(Copy_u32Delayvalue*2);
	while(MSYSYTICK_voidReadFlag()==0);

}

void MSYSYTICK_voidDelayms(uint32 Copy_u32Delayvalue){

	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);
	MSYSYTICK_voidStart(Copy_u32Delayvalue*2000);
	while(MSYSYTICK_voidReadFlag()==0);
}

void MSYSTICK_VoidCallbackms(void(*ptr)(void),uint32 Time_ms)
{
Global_ptr=ptr;
MSYSYTICK_voidStart(Time_ms*2000);
}

void MSYSTICK_VoidCallbackUs(void(*ptr)(void),uint32 Time_Us)
{
Global_ptr=ptr;
MSYSYTICK_voidStart(Time_Us*2);
}

void SysTick_Handler (void)
{
  Global_ptr();
  MSYSYTICK_voidReadFlag();
}






