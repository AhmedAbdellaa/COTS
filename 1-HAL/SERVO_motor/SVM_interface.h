#ifndef SVM_INTERFACE_H
#define SVM_INTERFACE_H

/// @brief initialize timer1 COM to clear on compare and WGM to TIMER_WGM_PWM_FAST_ICR1
void SVM_init();

/// @brief rotate servo motor to given degree
/// @param copy_u8Angel angle to rotate to [0:180]
void SVM_voidRotateTo(uint8 copy_u8Angel);

/// @brief reset timer1 COM to normal on compare and WGM to TIMER_WGM_NORMAL
void SVM_voidStop();

#endif

