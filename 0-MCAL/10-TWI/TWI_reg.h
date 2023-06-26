#ifndef TWI_REG
#define TWI_REG
// TWI Bit Rate Register
#define TWBR *((volatile uint8 *)0x20)

// TWI Control Register
#define TWCR *((volatile uint8 *)0x56)
#define TWCR_TWINT 7U // TWI Interrupt Flag **finished current job
#define TWCR_TWEA 6U  // TWI Enable Acknowledge Bit **1 connect to bus ,0 disconnect
#define TWCR_TWSTA 5U // TWI START Condition Bit   **1 to became master 0 after send start
#define TWCR_TWSTO 4U // TWI STOP Condition Bit    **1 to generate stop clear automatic
#define TWCR_TWWC 3U  // TWI Write Collision Flag
#define TWCR_TWEN 2U  // TWI Enable Bit
#define TWCR_TWIE 0U  // TWI Interrupt Enable

// TWI Status Register
#define TWSR *((volatile uint8 *)0x21)
#define TWSR_TWS_MASK 0B11111000 // TWI Status
#define TWSR_TWPS1 1u            // TWI Prescaler Bits
#define TWSR_TWPS0 0u            // TWI Prescaler Bits

// TWI Data Register
#define TWDR *((volatile uint8 *)0x23)

// TWI Address Register
#define TWAR *((volatile uint8 *)0x22)
#define TWAR_TWA_MASK 0B11111110
#define TWAR_TWGCE 0U
#endif