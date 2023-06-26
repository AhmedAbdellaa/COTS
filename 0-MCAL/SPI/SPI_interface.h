#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/// @brief send eight bit on spi and received 8-bit shifted from slave
/// @param copy_u8Data 8-bit data want to send to slave
/// @return shifted data from slave
uint8 SPI_u8TransceiveSync(uint8 copy_u8Data);

/// @brief init spi using config file
void SPI_voidInit();

#endif