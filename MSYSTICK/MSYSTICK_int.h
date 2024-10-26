#ifndef MSYSTICK_INT_H
#define MSYSTICK_INT_H

typedef enum
{
	SYSTICKEnable,
	SYSTICKDisable
}SYSTICKState;

void MSYSYTICK_voidInit(void);

void MSYSYTICK_voidStart(uint32 Copy_u32Loadvalue);

void MSYSYTICK_voidDelayMs(uint32 Copy_u32Delayvalue);

void MSYSYTICK_voidDelayms(uint32 Copy_u32Delayvalue);

uint8   MSYSYTICK_voidReadFlag(void);

void MSYSYTICK_voidCtrlIntState(SYSTICKState Copy_State );

uint32  MSTK_u32GetElapsedTime(void);

uint32  MSTK_u32GetRemainingTime(void);

void MSYSTICK_VoidCallback(void(*ptr)(void),uint32 Time_ms);














#endif
