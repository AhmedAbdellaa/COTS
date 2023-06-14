#include <util/delay.h>
#include "../../libraries/STD_TYPES_H.h"
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../0-MCAL/1-DIO/DIO_interface.h"
#include "STM_interface.h"

uint8 STM_u8Rotate(const STM_CONFIG_t *referance_stepper, uint16 copy_u16Angle, STM_DIRECTION_t copy_STMdirection)
{
    uint8 Local_u8ErrorType = OK;
    if (referance_stepper != NULL)
    {


        /*360(full roatate)/0.1758(full step degree) ) = 2048 (full step counts)*/
        uint16 local_u16steps = ((uint32)copy_u16Angle * 2048UL) / 360UL; // convert degree to number of full step
        uint16 local_u16Iter = 0;
        if (copy_STMdirection == STM_COUNTER_CLOCK_WISE)
        {
        	for (; local_u16Iter < local_u16steps; local_u16Iter++)
			{
				if (local_u16Iter % 4 == 0)
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->yellowPin, DIO_PIN_HIGH);
				DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->orangePin, DIO_PIN_LOW); // activate this pin in uln2003a
				_delay_ms(3);
				if (local_u16Iter % 4 == 1)
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->pinkPin, DIO_PIN_HIGH);
				DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->yellowPin, DIO_PIN_LOW); // activate this pin in uln2003a
				_delay_ms(3);
				if (local_u16Iter % 4 == 2)
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->bluePin, DIO_PIN_HIGH);
				DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->pinkPin, DIO_PIN_LOW); // activate this pin in uln2003a
				_delay_ms(3);
				if (local_u16Iter % 4 == 3)
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->orangePin, DIO_PIN_HIGH);
				DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->bluePin, DIO_PIN_LOW); // activate this pin in uln2003a
				_delay_ms(3);
			}
        }
        else if (copy_STMdirection == STM_CLOCK_WISE)
        {
        	for (; local_u16Iter < local_u16steps; local_u16Iter++)
			{
				if (local_u16Iter % 4 == 0)
				{
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->orangePin, DIO_PIN_HIGH);
					// _delay_ms(10);
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->bluePin, DIO_PIN_LOW); // activate this pin in uln2003a
					_delay_ms(3);
				}
				else if (local_u16Iter % 4 == 1)
				{
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->bluePin, DIO_PIN_HIGH);
					// _delay_ms(10);
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->pinkPin, DIO_PIN_LOW); // activate this pin in uln2003a
					_delay_ms(3);
				}
				else if (local_u16Iter % 4 == 2)
				{
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->pinkPin, DIO_PIN_HIGH);
					// _delay_ms(10);
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->yellowPin, DIO_PIN_LOW); // activate this pin in uln2003a
					_delay_ms(3);
				}
				else if (local_u16Iter % 4 == 3)
				{
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->yellowPin, DIO_PIN_HIGH);
					// _delay_ms(10);
					DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->orangePin, DIO_PIN_LOW); // activate this pin in uln2003a
					_delay_ms(3);
				}
			}

        }
        else
            Local_u8ErrorType = NOK;
    }
    else
        Local_u8ErrorType = NULL_PTR;
    if (Local_u8ErrorType == OK){
    	//
//    	_delay_ms(10);
		DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->bluePin, DIO_PIN_HIGH);
		DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->pinkPin, DIO_PIN_HIGH);
		DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->yellowPin, DIO_PIN_HIGH);
		DIO_u8_SetPinVal(referance_stepper->port, referance_stepper->orangePin, DIO_PIN_HIGH);

    }
    return Local_u8ErrorType;
}
