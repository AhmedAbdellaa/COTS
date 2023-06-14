#ifndef TIMER_INTERFACE
#define TIMER_INTERFACE



typedef enum {
    TIMER0,
    TIMER1A,
    TIMER1B,
    TIMER2,
    
}TIMER_TINum_t;

typedef struct TIMER_CALLBACK_CONFIG_t {

uint16 TIMER_u16OCR_TCNT_initVal; 
uint32 TIMER_U32ISRDoNum; //number of go into isr include preload overflow step
}TIMER_CALLBACK_CONFIG_t;


/// @brief initialize timers from configure file
void TIMER_voidInit(void);

/// @brief provide ISR function for given timer
/// @param copy_TINum number choose from  TIMER_TINum_t  
/// @param reference_TimerCallbackConf ISR Parameter {[TCNT,OCR] initialize , number times of repeat }
/// @param copy_pvFuncPtr address of the function want to execute when timer finish happen
/// @return error state if everything is ok will return OK
uint8 TIMER_u8SetCallBack(TIMER_TINum_t copy_TINum,TIMER_CALLBACK_CONFIG_t* reference_TimerCallbackConf,void(*copy_pvFuncPtr)(void));


#endif
