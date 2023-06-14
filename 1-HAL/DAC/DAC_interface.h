#ifndef DAC_INTERFACE
#define DAC_INTERFACE

/// @brief generate digital signal for given volt value
/// @param copy_u16_volt analog value 
/// @return digital signal represented in 8-bits
uint8 DAC_u8AnalogVolt(uint16 copy_u16_volt);
#endif
