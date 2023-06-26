#include <util/delay.h>
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/STD_TYPES_H.h"
#include "../../0-MCAL/10-TWI/TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_prv.h"
#include "EEPROM_cfg.h"
#include "../../0-MCAL/8-UART/UART_interface.h"

uint8 EEPROM_u8WriteDataByte(uint16 copy_u16LocAddress, uint8 copy_u8DataByte)
{
	uint8 Local_u8ErrorState = OK;

	if (copy_u16LocAddress <= EEPROM_MAX_ADDRESS)
	{
		uint8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | (uint8)(copy_u16LocAddress >> 8u);
		TWI_SendStartCondition();
		/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
		TWI_SendSLAWithWrite(Local_u8AddressPacket);
		/*send rest of 8bits word location in eeprom*/
		TWI_MasterWriteDataByte((uint8)copy_u16LocAddress);
		/*send 8-bit data want to send to eeprom*/
		TWI_MasterWriteDataByte(copy_u8DataByte);

		TWI_SendStopCondition();
		/*wait for 10ms for the eeprom write cycle*/
		_delay_ms(10);
	}
	else
	{
		/**/
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
uint8 EEPROM_u8ReadDataByte(uint16 copy_u16LocAddress, uint8 *ref_u8DataByte)
{
	uint8 Local_u8ErrorState = OK;
	if (ref_u8DataByte != NULL)
	{
		if (copy_u16LocAddress <= EEPROM_MAX_ADDRESS)
		{
			uint8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | (uint8)(copy_u16LocAddress >> 8u);
			// UART_VoidPrintInt(Local_u8AddressPacket);
			TWI_SendStartCondition();
			/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
			TWI_SendSLAWithWrite(Local_u8AddressPacket);
			/*send rest of 8bits word location in eeprom*/
			TWI_MasterWriteDataByte((uint8)copy_u16LocAddress);

			/*change bit from write to read*/
			TWI_SendRepeatedStart();
			/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
			TWI_SendSLAWithRead(Local_u8AddressPacket);
			/*read data from eeprom*/
			TWI_MasterReceiveDataByte(ref_u8DataByte);
// _delay_us(3);
			TWI_SendStopCondition();
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}


uint8 EEPROM_u8WriteInt(uint16 copy_u16LocAddress,sint32 copy_u8DataInt){
	uint8 Local_u8ErrorState = OK;

	if (copy_u16LocAddress <= EEPROM_MAX_ADDRESS)
	{
		uint8 Local_u8LocalCounter = 0;
		uint8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | (uint8)(copy_u16LocAddress >> 8u);
		TWI_SendStartCondition();
		/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
		TWI_SendSLAWithWrite(Local_u8AddressPacket);
		/*send rest of 8bits word location in eeprom*/
		TWI_MasterWriteDataByte((uint8)copy_u16LocAddress);

		/*send 32-bit data want to send to eeprom*/
		while(Local_u8LocalCounter <4){
			TWI_MasterWriteDataByte(copy_u8DataInt>>(Local_u8LocalCounter*8));
			Local_u8LocalCounter++;
		}
		TWI_SendStopCondition();
		/*wait for 10ms for the eeprom write cycle*/
		_delay_ms(10);
	}
	else
	{
		/**/
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
uint8 EEPROM_u8ReadInt(uint16 copy_u16LocAddress,sint32* ref_u8DataInt){
	uint8 Local_u8ErrorState = OK;
	
	if (ref_u8DataInt != NULL)
	{
		if (copy_u16LocAddress <= EEPROM_MAX_ADDRESS)
		{
			sint32 Local_s32Buffer=0;
			uint8 Local_u8LocalCounter = 0;
			uint8 Local_u8ByteReceived;
			uint8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | (uint8)(copy_u16LocAddress >> 8u);
			TWI_SendStartCondition();
			/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
			TWI_SendSLAWithWrite(Local_u8AddressPacket);
			/*send rest of 8bits word location in eeprom*/
			TWI_MasterWriteDataByte((uint8)copy_u16LocAddress);

			/*change bit from write to read*/
			TWI_SendRepeatedStart();
			/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
			TWI_SendSLAWithRead(Local_u8AddressPacket);
			/*read data from eeprom*/
			while(Local_u8LocalCounter <4){
			TWI_MasterReceiveDataByte(&Local_u8ByteReceived);
			Local_s32Buffer |=(((sint32) Local_u8ByteReceived)<<(Local_u8LocalCounter*8));
			Local_u8LocalCounter++;
			}
			*ref_u8DataInt = Local_s32Buffer;

			TWI_SendStopCondition();

		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}

uint8 EEPROM_u8WriteString(uint16 copy_u16LocAddress,uint8* ref_u8String,uint8* ref_u8Length){
	uint8 Local_u8ErrorState = OK;
	if (ref_u8Length != NULL && ref_u8String != NULL){
	if (copy_u16LocAddress <= EEPROM_MAX_ADDRESS)
	{
		uint8 Local_u8LocalCounter = 0;
		uint8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | (uint8)(copy_u16LocAddress >> 8u);
		TWI_SendStartCondition();
		/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
		TWI_SendSLAWithWrite(Local_u8AddressPacket);
		/*send rest of 8bits word location in eeprom*/
		TWI_MasterWriteDataByte((uint8)copy_u16LocAddress);

		/*send string data want to send to eeprom*/
		while(Local_u8LocalCounter <15 && ref_u8String[Local_u8LocalCounter]!='\0'){
			TWI_MasterWriteDataByte(ref_u8String[Local_u8LocalCounter]);
			Local_u8LocalCounter++;
		}
		*ref_u8Length= Local_u8LocalCounter;
		TWI_SendStopCondition();
		/*wait for 10ms for the eeprom write cycle*/
		_delay_ms(10);
	}
	else
	{
		/**/
		Local_u8ErrorState = NOK;
	}}else{
		Local_u8ErrorState = NULL_PTR;
	}

	return Local_u8ErrorState;
}
uint8 EEPROM_u8ReadString(uint16 copy_u16LocAddress,uint8* ref_u8String,uint8 copy_u8Length){
	uint8 Local_u8ErrorState = OK;
	
	if (ref_u8String != NULL )
	{
		if (copy_u16LocAddress <= EEPROM_MAX_ADDRESS)
		{
			uint8 Local_u8LocalCounter = 0;
			uint8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2u) | (uint8)(copy_u16LocAddress >> 8u);
			TWI_SendStartCondition();
			/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
			TWI_SendSLAWithWrite(Local_u8AddressPacket);
			/*send rest of 8bits word location in eeprom*/
			TWI_MasterWriteDataByte((uint8)copy_u16LocAddress);

			/*change bit from write to read*/
			TWI_SendRepeatedStart();
			/*send the address of eeprom with A2 connection and the first 2bits(msb) of word address*/
			TWI_SendSLAWithRead(Local_u8AddressPacket);
			/*read data from eeprom*/
			while(Local_u8LocalCounter <15 && Local_u8LocalCounter<copy_u8Length){
			TWI_MasterReceiveDataByte(&ref_u8String[Local_u8LocalCounter]);
			Local_u8LocalCounter++;
			}
			ref_u8String[Local_u8LocalCounter]= '\0';

			TWI_SendStopCondition();

		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}
