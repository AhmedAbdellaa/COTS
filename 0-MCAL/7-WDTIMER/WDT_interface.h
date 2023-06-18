#ifndef WDT_INTERFACE
#define WDT_INTERFACE
typedef enum    {
    WDT_TTO5V_16_3MS=0,
    WDT_TTO5V_32_5MS,
    WDT_TTO5V_65MS,  
    WDT_TTO5V_0_13S, 
    WDT_TTO5V_0_26S, 
    WDT_TTO5V_0_52S, 
    WDT_TTO5V_1_0S,  
    WDT_TTO5V_2_1S,  
}WDT_CLK_Config_t;


/// @brief enable watch dog timer *set timer first before enable
void WDT_voidEnable();

/// @brief disable watch dog timer 
void WDT_voidDisable();

/// @brief set time for callback watchdog timer 
/// @param copy_WDT_CLK choose time value you want from WDT_CLK_Config_t 
void WDT_voidSetTime(WDT_CLK_Config_t copy_WDT_CLK);
#endif
