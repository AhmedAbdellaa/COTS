#ifndef SPI_CFG_H
#define SPI_CFG_H

/*
* configure SPI Data Order options :1-SPI_DORD_LSB  
*                                   2-SPI_DORD_MSB
*/
#define SPI_u8DORD_MODE              SPI_DORD_LSB
/*
* configure SPI Master/Slave Select, options :1-SPI_MSTR_SLAVE
*                                           2-SPI_MSTR_MASTER
*/
#define SPI_u8M_S_MODE              SPI_MSTR_MASTER
/*
* configure SPI Clock Polarity Select,Leading Edge options :1-SPI_CPOL_RISING
*                                           2-SPI_CPOL_FALLING
*/
#define SPI_u8CPOL              SPI_CPOL_RISING
/*
* configure SPI Clock Phase Select,Leading Edge options :1-SPI_CPHA_SAMPLE
*                                           2-SPI_CPHA_SETUP
*/
#define SPI_u8CPHA              SPI_CPHA_SAMPLE
/*
* configure SPI   Clock Rate, options : 1-SPI_SCK_FREQ_2
*                                                    2-SPI_SCK_FREQ_4
*                                                    3-SPI_SCK_FREQ_8
*                                                    4-SPI_SCK_FREQ_16
*                                                    5-SPI_SCK_FREQ_32
*                                                    6-SPI_SCK_FREQ_64
*                                                    7-SPI_SCK_FREQ_128
*/
#define SPI_u8_SCK_FREQ            SPI_SCK_FREQ_2

#endif
