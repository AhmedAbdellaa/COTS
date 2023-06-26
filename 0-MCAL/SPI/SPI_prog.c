
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/STD_TYPES_H.h"
#include "SPI_interface.h"
#include "SPI_reg.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"


uint8 SPI_u8TransceiveSync(uint8 copy_u8Data){
	//send data
	SPDR = copy_u8Data;
	//polling until data is sent
	while(GET_BIT(SPSR,SPSR_SPIF) ==0 );
	//receive data
	return SPDR ;
}



void SPI_voidInit()
{
/*data order*/
#if SPI_u8DORD_MODE == SPI_DORD_LSB
	SET_BIT(SPCR, SPCR_SPE);
#elif SPI_u8DORD_MODE == SPI_DORD_MSB
	CLS_BIT(SPCR, SPCR_SPE);
#else
#error SPI_u8DORD_MODE
#endif
/*master or slave*/
#if SPI_u8M_S_MODE == SPI_MSTR_MASTER
	SET_BIT(SPCR, SPCR_MSTR);
#elif SPI_u8M_S_MODE == SPI_MSTR_SLAVE
	CLS_BIT(SPCR, SPCR_MSTR);
#else
#error SPI_u8M_S_MODE
#endif
/*clock polarity select*/
#if SPI_u8CPOL == SPI_CPOL_RISING
CLS_BIT(SPCR,SPCR_CPOL);
#elif SPI_u8CPOL == SPI_CPOL_FALLING
SET_BIT(SPCR,SPCR_CPOL);
#else
#error SPI_u8CPOL
#endif
/*clock phase select*/
#if SPI_u8CPHA == SPI_CPHA_SAMPLE
	CLS_BIT(SPCR,SPCR_CPHA);
#elif SPI_u8CPHA == SPI_CPHA_SETUP
	SET_BIT(SPCR,SPCR_CPHA);
#else
#error SPI_u8CPHA
#endif
	/*clock rate select*/
	// #if  SPI_u8_SCK_FREQ
	
	SPCR &=0B11111100;//clear spr0 and 1
	SPCR |= (0B00000011 & SPI_u8_SCK_FREQ);

	SPSR &= 0B11111110;
	SPSR |= (0b00000001&(SPI_u8_SCK_FREQ>>2));
}


// 13 $018 SPI, STC Serial Transfer Complete
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{

}