#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEXTI_cfg.h"
#include "MEXTI_prv.h"
#include "MEXTI_int.h"

static void (*Global_EXTIPtr[16])(void);


void MEXTI_voidInerruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port){

	SYSCFG->EXTICR[Copy_u8Line/Div_Fac] &= ~(Musk<<(4*(Copy_u8Line%Div_Fac)));
	SYSCFG->EXTICR[Copy_u8Line/Div_Fac] |= Copy_u8Port<<(4*(Copy_u8Line%Div_Fac));
}

void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis){

	switch (Copy_u8ENDis){
	case EXTI_Enable:
		EXTI->IMR |= 1<<(Copy_u8IntLine);
		break;
	case EXTI_Disable:
		EXTI->IMR &= ~(1<<(Copy_u8IntLine));
		break;
	default:  break;
	}


}
void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig){
	switch (Copy_u8Trig){
		case EXTI_Falling:
			EXTI->FTSR |= 1<<(Copy_u8IntLine);
			EXTI->RTSR &= ~(1<<(Copy_u8IntLine));
			break;
		case EXTI_Rising:
			EXTI->RTSR |= 1<<(Copy_u8IntLine);
			EXTI->FTSR &= ~(1<<(Copy_u8IntLine));
			break;
		case EXTI_OnChange:
			EXTI->RTSR |= 1<<(Copy_u8IntLine);
			EXTI->FTSR |= 1<<(Copy_u8IntLine);
			break;
		default:  break;
	}
}
void MEXTI0_voidCallBack(void (*ptr)(void)){
	Global_EXTIPtr[0]=ptr;
}
void MEXTI1_voidCallBack(void (*ptr)(void)){
	Global_EXTIPtr[1]=ptr;
}

void MEXTI2_voidCallBack(void (*ptr)(void)){
	Global_EXTIPtr[2]=ptr;
}

void MEXTI3_voidCallBack(void (*ptr)(void)){
	Global_EXTIPtr[3]=ptr;
}

void MEXTI4_voidCallBack(void (*ptr)(void)){
	Global_EXTIPtr[4]=ptr;
}


void EXTI0_IRQHandler(void){
	Global_EXTIPtr[0]();
    EXTI->PR |=1;
}

void EXTI1_IRQHandler(void){
	Global_EXTIPtr[1]();
	  EXTI->PR |=(1<<1);
}

void EXTI2_IRQHandler(void){
	Global_EXTIPtr[2]();
	  EXTI->PR |=(1<<2);
}

void EXTI3_IRQHandler(void){
	Global_EXTIPtr[3]();
	  EXTI->PR |=(1<<3);
}

void EXTI4_IRQHandler(void){
	Global_EXTIPtr[4]();
	  EXTI->PR |=(1<<4);
}


