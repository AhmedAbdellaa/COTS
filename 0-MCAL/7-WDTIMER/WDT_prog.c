
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/STD_TYPES_H.h"
#include "WDT_interface.h"
#include "WDT_reg.h"


void WDT_voidEnable(){
    SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_voidDisable(){
    WDTCR |= WDTCR_OFF_MASK;
}
void WDT_voidSetTime(WDT_CLK_Config_t copy_WDT_CLK){
if((copy_WDT_CLK>= WDT_TTO5V_16_3MS) && (copy_WDT_CLK<= WDT_TTO5V_2_1S)){
  WDTCR &=WDTCR_WDP_MASK;  
  WDTCR |=copy_WDT_CLK;
}else{
    /**/
}
}