#ifndef WDT_REG
#define WDT_REG

// Watchdog Timer Control
#define WDTCR *((volatile uint8*)0x41)
#define WDTCR_WDTOE         4u
#define WDTCR_WDE           3u
#define WDTCR_WDP_MASK      0b11111000
#define WDTCR_OFF_MASK      0b00011000
#endif
