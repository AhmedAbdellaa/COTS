#ifndef T1S_INTERFACE
#define T1S_INTERFACE

#define IDLE    1u
#define BUSY    2U

/// @brief measure timer of pwm signal (period time and duty cycle) **timer1 must be initalized
/// @param reference_u16DutyCycle address of u16 value to return duty value in it
/// @param reference_u16PeriodTime address of u16 value to return cycle value in it 
/// @return error state return OK if everything is okay
uint8 T1S_voidPWM_Measure(uint16* reference_u16DutyCycle ,uint16* reference_u16PeriodTime);

/// @brief schedule timer for do event every given time **timer1 must be initalized
/// @param copy_u32Time_ms time in milli seconds
/// @param copy_u16Periodic how many time repeat it  put -1 for infinity repeat
/// @param copy_pvFuncPtr address to function to execute 
/// @return error state return OK if everything is okay
uint8 T1S_voidScheduleMS(uint32 copy_u32Time_ms, sint16 copy_u16Periodic, void (*copy_pvFuncPtr)(void));

/// @brief start pwm wave for given time 
/// @param copy_u32CycleTime time of cycle in microseconds
/// @param copy_u8Duty percent of duty time from cycle time
/// @return error state return OK if everything is okay
uint8 T1S_voidStartPwm(uint32 copy_u32CycleTime, uint8 copy_u8Duty);
#endif
