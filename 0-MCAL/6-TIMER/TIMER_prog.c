
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/STD_TYPES_H.h"
#include "./TIMER_interface.h"
#include "TIMER_reg.h"
#include "TIMER_prv.h"
#include "TIMER_cfg.h"

static void (*TIMER_PFunctionPtr[4])(void) = {NULL, NULL, NULL, NULL};
static TIMER_CALLBACK_CONFIG_t *Gloable_TimerCallbackConf[4] = {NULL, NULL, NULL, NULL};
uint8 TIMER_u8SetCallBack(TIMER_TINum_t copy_TINum, TIMER_CALLBACK_CONFIG_t *referance_TimerCallbackConf, void (*copy_pvFuncPtr)(void))
{
	uint8 Local_u8ErrorState = OK;
	if ((copy_pvFuncPtr != NULL) && (referance_TimerCallbackConf != NULL))
	{
		if ((copy_TINum >= TIMER0) && (copy_TINum <= TIMER2))
		{

			TIMER_PFunctionPtr[copy_TINum] = copy_pvFuncPtr;
			Gloable_TimerCallbackConf[copy_TINum] = referance_TimerCallbackConf;
			TCNT0 = (uint8)Gloable_TimerCallbackConf[TIMER0]->TIMER_u16OCR_TCNT_initVal;
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}
uint8 TIMERCompare_u8SetCallBack(TIMER_TINum_t copy_TINum, TIMER_CALLBACK_CONFIG_t *referance_TimerCallbackConf, void (*copy_pvFuncPtr)(void))
{
	uint8 Local_u8ErrorState = OK;
	if ((copy_pvFuncPtr != NULL) && (referance_TimerCallbackConf != NULL))
	{
		switch (copy_TINum)
		{
		case TIMER0:
			if (TIMER_u8TI0_INTM == TIMER_COMPARE_INT)
			{
				TIMER_PFunctionPtr[copy_TINum] = copy_pvFuncPtr;
				// number of do isr
				Gloable_TimerCallbackConf[copy_TINum]= referance_TimerCallbackConf;
				OCR0 = referance_TimerCallbackConf->TIMER_u16OCR_TCNT_initVal;
			}
			break;

		default:
			Local_u8ErrorState = NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}

// 5 $008 TIMER2 COMP Timer/Counter2 Compare Match
// 6 $00A TIMER2 OVF Timer/Counter2 Overflow
// 7 $00C TIMER1 CAPT Timer/Counter1 Capture Event
// 8 $00E TIMER1 COMPA Timer/Counter1 Compare Match A
// 9 $010 TIMER1 COMPB Timer/Counter1 Compare Match B
// 10 $012 TIMER1 OVF Timer/Counter1 Overflow

// 11 $014 TIMER0 COMP Timer/Counter0 Compare Match
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static uint16 Local_u16Counter = 1; // init the overflows tracking counter

	if ((TIMER_PFunctionPtr[TIMER0] != NULL) && (Gloable_TimerCallbackConf[TIMER0] != NULL))
	{

		// if the counter equal to number of overflows do the function and reset the counter to 0
		if (Local_u16Counter == Gloable_TimerCallbackConf[TIMER0]->TIMER_U32ISRDoNum)
		{
			TIMER_PFunctionPtr[TIMER0]();
			Local_u16Counter = 1;
		}
		else
		{
			/*do nothing*/
			Local_u16Counter++;
		}
	}
	else
	{
		/*do nothing*/
	}
}
// 12 $016 TIMER0 OVF Timer/Counter0 Overflow
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static uint16 Local_u16Counter = 1; // init the overflows tracking counter

	if ((TIMER_PFunctionPtr[TIMER0] != NULL) && (Gloable_TimerCallbackConf[TIMER0] != NULL))
	{

		// if the counter equal to numper of overflows do the function and reset the counter to 0
		if (Local_u16Counter == Gloable_TimerCallbackConf[TIMER0]->TIMER_U32ISRDoNum)
		{
			TIMER_PFunctionPtr[TIMER0]();
			Local_u16Counter = 1;
			// if there is preload at it in the first over flow for next counter
			TCNT0 = (uint8)Gloable_TimerCallbackConf[TIMER0]->TIMER_u16OCR_TCNT_initVal;
		}
		else
		{
			/*do nothing*/
			Local_u16Counter++;
		}
	}
	else
	{
		/*do nothing*/
	}
}

void TIMER_voidInit(void)
{

#if TIMER_u8TI0_INTM == TIMER_DISBLE_INT
	CLS_BIT(TIMSK, TIMSK_OCIE0);
	CLS_BIT(TIMSK, TIMSK_TOIE0);
#elif TIMER_u8TI0_INTM == TIMER_OVERFLOW_INT
	CLS_BIT(TIMSK, TIMSK_OCIE0);
	SET_BIT(TIMSK, TIMSK_TOIE0);
#elif TIMER_u8TI0_INTM == TIMER_COMPARE_INT
	CLS_BIT(TIMSK, TIMSK_TOIE0);
	SET_BIT(TIMSK, TIMSK_OCIE0);
#else
#error "Wrong TIMER_u8TI0_INTM configuration option"
#endif

#if TIMER_u8TI0_WGM == TIMER_NORMAL
	CLS_BIT(TCCR0, TCCR0_WGM00);
	CLS_BIT(TCCR0, TCCR0_WGM01);
#elif TIMER_u8TI0_WGM == TIMER_PWM
	SET_BIT(TCCR0, TCCR0_WGM00);
	CLS_BIT(TCCR0, TCCR0_WGM01);
#elif TIMER_u8TI0_WGM == TIMER_CTC
	CLS_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
#elif TIMER_u8TI0_WGM == TIMER_FAST_PWM
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
#else
#error "Wrong TIMER_u8TI0_WGM configuration option"
#endif

#if TIMER_u8TI0_COM == TIMER_NORMAL
	CLS_BIT(TCCR0, TCCR0_COM00);
	CLS_BIT(TCCR0, TCCR0_COM01);
#elif TIMER_u8TI0_COM == TIMER_TOGGLE || TIMER_u8TI0_COM == TIMER_RESERVED
	SET_BIT(TCCR0, TCCR0_COM00);
	CLS_BIT(TCCR0, TCCR0_COM01);
#elif TIMER_u8TI0_COM == TIMER_CLEAR
	CLS_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#elif TIMER_u8TI0_COM == TIMER_SET
	SET_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#else
#error "Wrong TIMER_u8TI0_COM configuration option"
#endif

	TCCR0 &= TCCR0_WGM01_Mask;
	TCCR0 |= TIMER_u8TI0_CLK;
}