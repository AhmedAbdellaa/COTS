#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

typedef enum SWITCH_PullType_t{
    SWITCH_PULL_UP,SWITCH_PULL_DOWN
}SWITCH_PullType_t;

typedef enum SWITCH_State_t{
    SWITCH_RELEASED,SWITCH_PRESSED
}SWITCH_State_t;

typedef struct SWITCH_Config_t
{
    SWITCH_PullType_t PullType;
    DIO_port_t port;
    DIO_pin_t Pin;
    uint8 state;
}SWITCH_Config_t;



/// @brief get button state [SWITCH_RELEASED,SWITCH_PRESSED]
/// @param copy_Switch_Object address of button object 
/// @return error state if everything is ok will return OK
uint8 SWITCH_u8GetState(SWITCH_Config_t* copy_Switch_Object);
#endif
