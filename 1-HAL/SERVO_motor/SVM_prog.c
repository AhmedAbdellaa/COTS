
#include "../../libraries/STD_TYPES_H.h"
#include "../../libraries/MAP.h"

#include "../../0-MCAL/1-DIO/DIO_interface.h"
#include "../../2-service/TIMER1_S_interface.h"
#include "../../0-MCAL/6-TIMER/TIMER_interface.h"
#include "SVM_interface.h"

void SVM_init()
{
	TIMER_voidChangCOM_Mode(TIMER1A, TIMER_COM_CLEAR);
	TIMER_voidChangWGM_Mode(TIMER1, TIMER_WGM_PWM_FAST_ICR1);
}
void SVM_voidRotateTo(uint8 copy_u8Angel)
{
	if ((copy_u8Angel >= 0) && (copy_u8Angel <= 180))
	{
		f64 Local_s32DutyPercent = MAP(0.0, 180.0, 2.1, 12.9, (f64)copy_u8Angel);
		T1S_voidStopPwm();
		T1S_voidStartPwm(20000, Local_s32DutyPercent);
	}
}
void SVM_voidStop()
{
	TIMER_voidChangCOM_Mode(TIMER1A, TIMER_COM_NORMAL);
	TIMER_voidChangWGM_Mode(TIMER1, TIMER_WGM_Normal);
	T1S_voidStopPwm();
}
