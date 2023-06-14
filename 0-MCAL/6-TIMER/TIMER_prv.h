#ifndef TIMER_PRV_H
#define TIMER_PRV_H


#define TIMER_DISBLE_INT      1U
#define TIMER_OVERFLOW_INT    2U
#define TIMER_COMPARE_INT     3U   



#define TIMER_NORMAL       1U
#define TIMER_PWM          2U
#define TIMER_CTC          3U
#define TIMER_FAST_PWM     4U



// #define TIMER_NORMAL       1U
#define TIMER_TOGGLE       2U
#define TIMER_CLEAR        3U
#define TIMER_SET          4U
#define TIMER_RESERVED     5U


 
#define TIMER_NO_CLK                    0U
#define TIMER_NO_PS                     1U
#define TIMER_PS_8                      2U
#define TIMER_PS_64                     3U
#define TIMER_PS_256                    4U
#define TIMER_PS_1024                   5U
#define TIMER_EXT_CLK_FALLING_EDGE      6U
#define TIMER_EXT_CLK_RISING_EDGE       7U




#endif
