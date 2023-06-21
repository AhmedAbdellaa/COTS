#ifndef PORT_CFG_H
#define PORT_CFG_H
/*
configure pin initial value Options: 1- INPUT
                                 2- OUTPUT
*/

#define PORTA_PIN0_DIR  INPUT
#define PORTA_PIN1_DIR  OUTPUT
#define PORTA_PIN2_DIR  OUTPUT
#define PORTA_PIN3_DIR  OUTPUT
#define PORTA_PIN4_DIR  OUTPUT
#define PORTA_PIN5_DIR  OUTPUT
#define PORTA_PIN6_DIR  OUTPUT
#define PORTA_PIN7_DIR  INPUT

#define PORTB_PIN0_DIR  INPUT
#define PORTB_PIN1_DIR  INPUT
#define PORTB_PIN2_DIR  OUTPUT
#define PORTB_PIN3_DIR  OUTPUT
#define PORTB_PIN4_DIR  INPUT
#define PORTB_PIN5_DIR  INPUT
#define PORTB_PIN6_DIR  INPUT
#define PORTB_PIN7_DIR  OUTPUT

#define PORTC_PIN0_DIR  INPUT
#define PORTC_PIN1_DIR  INPUT
#define PORTC_PIN2_DIR  OUTPUT
#define PORTC_PIN3_DIR  OUTPUT
#define PORTC_PIN4_DIR  OUTPUT
#define PORTC_PIN5_DIR  OUTPUT
#define PORTC_PIN6_DIR  INPUT
#define PORTC_PIN7_DIR  INPUT

#define PORTD_PIN0_DIR  OUTPUT
#define PORTD_PIN1_DIR  OUTPUT
#define PORTD_PIN2_DIR  INPUT
#define PORTD_PIN3_DIR  OUTPUT
#define PORTD_PIN4_DIR  OUTPUT
#define PORTD_PIN5_DIR  OUTPUT
#define PORTD_PIN6_DIR  INPUT
#define PORTD_PIN7_DIR  INPUT



/*
configure pin direction Options: A in case pin is input 0 FLoating 
                                                        1-PULLING 
                                 2- In case pin is  OUTPUT 0-LOW 
                                                            1-HIGH
*/
        
#define PORTA_PIN0_INITVAL  fLOATAING
#define PORTA_PIN1_INITVAL  fLOATAING
#define PORTA_PIN2_INITVAL  fLOATAING
#define PORTA_PIN3_INITVAL  fLOATAING
#define PORTA_PIN4_INITVAL  fLOATAING
#define PORTA_PIN5_INITVAL  fLOATAING
#define PORTA_PIN6_INITVAL  fLOATAING
#define PORTA_PIN7_INITVAL  fLOATAING

#define PORTB_PIN0_INITVAL  fLOATAING
#define PORTB_PIN1_INITVAL  fLOATAING
#define PORTB_PIN2_INITVAL  fLOATAING
#define PORTB_PIN3_INITVAL  fLOATAING
#define PORTB_PIN4_INITVAL  PULLEDUP
#define PORTB_PIN5_INITVAL  PULLEDUP
#define PORTB_PIN6_INITVAL  PULLEDUP
#define PORTB_PIN7_INITVAL  LOW

#define PORTC_PIN0_INITVAL  fLOATAING
#define PORTC_PIN1_INITVAL  fLOATAING
#define PORTC_PIN2_INITVAL  LOW
#define PORTC_PIN3_INITVAL  LOW
#define PORTC_PIN4_INITVAL  LOW
#define PORTC_PIN5_INITVAL  LOW
#define PORTC_PIN6_INITVAL  fLOATAING
#define PORTC_PIN7_INITVAL  fLOATAING

#define PORTD_PIN0_INITVAL  fLOATAING
#define PORTD_PIN1_INITVAL  fLOATAING
#define PORTD_PIN2_INITVAL  LOW
#define PORTD_PIN3_INITVAL  HIGH
#define PORTD_PIN4_INITVAL  HIGH
#define PORTD_PIN5_INITVAL  HIGH
#define PORTD_PIN6_INITVAL  fLOATAING
#define PORTD_PIN7_INITVAL  fLOATAING
#endif
