#ifndef STM_INTERFACE_H
#define STM_INTERFACE_H

typedef enum STM_DIRECTION_t{
    STM_CLOCK_WISE, STM_COUNTER_CLOCK_WISE
}STM_DIRECTION_t;

typedef struct STM_CONFIG_t
{
    DIO_port_t port;
    DIO_pin_t bluePin;
    DIO_pin_t pinkPin;
    DIO_pin_t yellowPin;
    DIO_pin_t orangePin;
}STM_CONFIG_t;

/// @brief rotate stepper motor in given direction 
/// @param reference_stepper address of motor object
/// @param copy_u16angle rotation angle
/// @param copy_STMdirection direction [STM_CLOCK_WISE, STM_COUNTER_CLOCK_WISE]
/// @return error state if everything is ok will return OK
uint8 STM_u8Rotate(const STM_CONFIG_t* reference_stepper, uint16 copy_u16angle,STM_DIRECTION_t copy_STMdirection);

#endif
