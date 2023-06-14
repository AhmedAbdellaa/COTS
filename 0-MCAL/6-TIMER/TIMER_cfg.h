#ifndef TIMER_CFG_H
#define TIMER_CFG_H
#include "TIMER_interface.h"
/*
* configure TIMER0 interrupt mask, options : TIMER_DISBLE_INT
*                                           2-TIMER_OVERFLOW_INT
*                                           3-TIMER_COMPARE_INT                                      
*/
#define TIMER_u8TI0_INTM              TIMER_OVERFLOW_INT
/*
* configure TIMER0 Waveform Generation Mode, options : 1-TIMER_NORMAL
*                                                    2-TIMER_PWM  
*                                                    3-TIMER_CTC
*                                                    4-TIMER_FAST_PWM
*/
#define TIMER_u8TI0_WGM              TIMER_NORMAL
/*
* configure TIMER0 Compare Match Output Mode, options : 1-TIMER_NORMAL
*                                                    2-TIMER_TOGGLE  
*                                                    3-TIMER_CLEAR
*                                                    4-TIMER_SET
*                                                    5-TIMER_RESERVED
*/
#define TIMER_u8TI0_COM             TIMER_NORMAL
/* 
* configure TIMER0 the clock source to be used: 1-TIMER_NO_CLK
*                                           2-TIMER_NO_PS
*                                           3-TIMER_PS_8
*                                           4-TIMER_PS_64
*                                           5-TIMER_PS_256
*                                           6-TIMER_PS_1024
*                                           7-TIMER_EXT_CLK_FALLING_EDGE
*                                           8-TIMER_EXT_CLK_RISING_EDGE
*/
#define TIMER_u8TI0_CLK              TIMER_PS_1024



#endif
