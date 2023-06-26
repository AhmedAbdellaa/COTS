#ifndef SPI_REG
#define SPI_REG
// SPI Control Register
#define SPCR   *((volatile uint8*)0x2D)
#define SPCR_SPIE   7U //SPI Interrupt Enable
#define SPCR_SPE    6U  //SPI Enable
#define SPCR_DORD   5U  //Data Order
#define SPCR_MSTR   4U  //Master/Slave Select
#define SPCR_CPOL   3U  //Clock Polarity
#define SPCR_CPHA   2U  //Clock Phase
#define SPCR_SPR1   1U //SPI Clock Rate
#define SPCR_SPR0   0U //SPI Clock Rate

// SPI Status Register
#define SPSR   *((volatile uint8*)0x2E)
#define SPSR_SPIF    7U //SPI Interrupt Flag
#define SPSR_WCOL    6U  //Write COLlision Flag
#define SPSR_SPI2X   0U //Double SPI Speed Bit(SPI Clock Rate)
// SPI Data Register
#define SPDR   *((volatile uint8*)0x2F)
#endif
    // SPIF