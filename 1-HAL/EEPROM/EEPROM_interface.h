#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

/// @brief write data to given EEPROM
/// @param copy_u16LocAddress address of EEPROM on bus
/// @param copy_u8DataByte 8-bit data want to write on EEPROM
/// @return error state
uint8 EEPROM_u8WriteDataByte(uint16 copy_u16LocAddress,uint8 copy_u8DataByte);

/// @brief read data to given EEPROM
/// @param copy_u16LocAddress address of EEPROM on bus
/// @param copy_u8DataByte 8-bit data want to read from EEPROM
/// @return error state
uint8 EEPROM_u8ReadDataByte(uint16 copy_u16LocAddress,uint8* ref_u8DataByte);

uint8 EEPROM_u8WriteInt(uint16 copy_u16LocAddress,sint32 copy_u8DataInt);
uint8 EEPROM_u8ReadInt(uint16 copy_u16LocAddress,sint32* ref_u8DataInt);

uint8 EEPROM_u8WriteString(uint16 copy_u16LocAddress,uint8* ref_u8String,uint8* ref_u8Length);
uint8 EEPROM_u8ReadString(uint16 copy_u16LocAddress,uint8* ref_u8String,uint8 copy_u8Length);
#endif