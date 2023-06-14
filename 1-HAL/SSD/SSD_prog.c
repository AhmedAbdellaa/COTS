
#include "../../libraries/STD_TYPES_H.h"
#include "../../libraries/ErrType.h"
#include "../../0-MCAL/1-DIO/DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_prv.h"

void _SSD_VoidcustomPortValue(DIO_port_t copy_Port, DIO_pin_t copy_Pin, uint8 copy_u8PortVal)
{
    uint8 Local_u8PortValue;
    DIO_u8_GetPinVal(copy_Port, copy_Pin, &Local_u8PortValue);
    Local_u8PortValue |= copy_u8PortVal;

    DIO_u8_SetPortVal(copy_Port, Local_u8PortValue);
}

uint8 SSD_u8SetNumber(const SSD_Config_t *copy_SSD_Object, uint8 copy_u8Number)
{
    uint8 Local_u8ErrorState = OK;
    const static uint8 SSD_u8p_NumArr[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};

    if (copy_SSD_Object != NULL)
    {

        if (copy_SSD_Object->type == SSD_ComCathod)
        {

            if (copy_SSD_Object->LEDAPin == 0)
            {
                // set pins from bin0->bin6 value to high depends on the given number
                _SSD_VoidcustomPortValue(copy_SSD_Object->port, 7, (SSD_u8p_NumArr[copy_u8Number]) >> 1);
            }
            else if (copy_SSD_Object->LEDAPin == 1)
            {
                // set pins from bin1->bin7 value to high depends on the given number
                _SSD_VoidcustomPortValue(copy_SSD_Object->port, 0, SSD_u8p_NumArr[copy_u8Number]);
            }
            else
                Local_u8ErrorState = NOK;
        }
        else if (copy_SSD_Object->type == SSD_ComAnod)
        {
            if (copy_SSD_Object->LEDAPin == 0)
            {
                // set pins from bin0->bin6 value to high depends on the given number
                _SSD_VoidcustomPortValue(copy_SSD_Object->port, 7, ~((SSD_u8p_NumArr[copy_u8Number]) >> 1));
            }
            else if (copy_SSD_Object->LEDAPin == 1)
            {
                // set pins from bin1->bin7 value to high depends on the given number
                _SSD_VoidcustomPortValue(copy_SSD_Object->port, 7, ~(SSD_u8p_NumArr[copy_u8Number]));
            }
            else
                Local_u8ErrorState = NOK;
        }
        else
            Local_u8ErrorState = NOK;
    }
    else
        Local_u8ErrorState = NULL_PTR;

    return Local_u8ErrorState;
}
uint8 SSD_u8Enable(const SSD_Config_t *copy_SSD_Object)
{

    uint8 Local_u8ErrorState = OK;

    if (copy_SSD_Object != NULL)
    {
        if (copy_SSD_Object->type == SSD_ETA_KIT)
        {
            DIO_u8_SetPinVal(copy_SSD_Object->enable_port, copy_SSD_Object->enable_Pin, DIO_PIN_HIGH);
        }
        else if(copy_SSD_Object->type == SSD_ComCathod){
            DIO_u8_SetPinVal(copy_SSD_Object->enable_port, copy_SSD_Object->enable_Pin, DIO_PIN_LOW);
        }else if(copy_SSD_Object->type == SSD_ComAnod){
            DIO_u8_SetPinVal(copy_SSD_Object->enable_port, copy_SSD_Object->enable_Pin, DIO_PIN_HIGH);
        }else
            Local_u8ErrorState = NOK;
    }
    else
        Local_u8ErrorState = NULL_PTR;

    return Local_u8ErrorState;
}
uint8 SSD_u8Disable(const SSD_Config_t *copy_SSD_Object)
{
    uint8 Local_u8ErrorState = OK;

    if (copy_SSD_Object != NULL)
    {
        if (copy_SSD_Object->type == SSD_ETA_KIT)
        {
            DIO_u8_SetPinVal(copy_SSD_Object->enable_port, copy_SSD_Object->enable_Pin, DIO_PIN_LOW);
        }
        else if(copy_SSD_Object->type == SSD_ComCathod){
            DIO_u8_SetPinVal(copy_SSD_Object->enable_port, copy_SSD_Object->enable_Pin, DIO_PIN_HIGH);
        }else if(copy_SSD_Object->type == SSD_ComAnod){
            DIO_u8_SetPinVal(copy_SSD_Object->enable_port, copy_SSD_Object->enable_Pin, DIO_PIN_LOW);
        }else
            Local_u8ErrorState = NOK;
    }
    else
        Local_u8ErrorState = NULL_PTR;

    return Local_u8ErrorState;
}
