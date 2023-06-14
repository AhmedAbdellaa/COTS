
#include "../../libraries/STD_TYPES_H.h"
#include "../../libraries/ErrType.h"
#include "../../0-MCAL/1-DIO/DIO_interface.h"

#include "SWITCH_interface.h"

uint8 SWITCH_u8GetState(SWITCH_Config_t* copy_Switch_Object){
    uint8 Local_u8ErrorState = OK;
    uint8 Local_u8SwitchState=1;
//    uint8 Local_u8SwitchStatePrev=0;
    if(copy_Switch_Object != NULL){
        if(copy_Switch_Object->PullType== SWITCH_PULL_UP){
        	DIO_u8_GetPinVal(copy_Switch_Object->port,copy_Switch_Object->Pin,&Local_u8SwitchState);
            if(Local_u8SwitchState == 0)
            	copy_Switch_Object->state =SWITCH_PRESSED;
            else
            	copy_Switch_Object->state =SWITCH_RELEASED;

        }else if(copy_Switch_Object->PullType== SWITCH_PULL_UP){
            DIO_u8_GetPinVal(copy_Switch_Object->port,copy_Switch_Object->Pin,&Local_u8SwitchState);
            if(Local_u8SwitchState == 1)
            	copy_Switch_Object->state =SWITCH_PRESSED;
            else
            	copy_Switch_Object->state =SWITCH_RELEASED;
        }else{
          Local_u8ErrorState = NOK;

        }


    }else
        Local_u8ErrorState = NULL_PTR;
    return Local_u8ErrorState;
}
