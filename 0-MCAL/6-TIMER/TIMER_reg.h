#ifndef TIMER_REG
#define TIMER_REG

// Timer/Counter Interrupt Mask Register
#define TIMSK *((volatile uint8 *)0x59)
#define TIMSK_OCIE0 1U  //Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0 0U  //Timer/Counter0 Overflow Interrupt Enable

//Timer/Counter Interrupt Flag Register
#define TIFR *((volatile uint8 *)0x58)
#define TIFR_OCIE0 1U  //Timer/Counter0 Output Compare Match Flag
#define TIFR_TOIE0 0U  //Timer/Counter0 Overflow Flag

//define Timer/Counter Control Register
#define TCCR0 *((volatile uint8 *)0x53)
#define TCCR0_FOC0 7U //Force Output Compare
// Waveform Generation Mode
#define TCCR0_WGM00 6U
#define TCCR0_WGM01 3U
// Compare Match Output Mode
#define TCCR0_COM01 5U
#define TCCR0_COM00 4U
// Clock Select Bit Description
#define TCCR0_WGM01_Mask 0B11111000

//Timer/Counter Register 
#define TCNT0 *((volatile uint8 *)0x52)
//Output Compare Register
#define OCR0 *((volatile uint8 *)0x5C)

#endif
