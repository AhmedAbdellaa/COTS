
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/STD_TYPES_H.h"
#include "./DAC_interface.h"




uint8 DAC_u8AnalogVolt( uint16 copy_u16_volt){
    //step = maxvolt(5000mv)/2^res(256) =19.53125
    //analog = digital *step /// digital = analog/step
    uint8 digital = (uint8)((f32)copy_u16_volt / 19.53125f);
    return digital;
}