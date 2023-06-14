#ifndef SSD_PRV_H
#define SSD_PRV_H

/*common cathode*/
//0->6
// const static uint8 SSD_u8p_NumArr[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};
// (SSD_u8p_NumArr>>1)
//1->7

/*common anode*/
//0->6
// ~(SSD_u8p_NumArr>>1)
//1->7
// ~(SSD_u8p_NumArr)


void _SSD_VoidcustomPortValue(DIO_port_t copy_Port,DIO_pin_t copy_Pin,uint8 copy_u8PortVal);

#endif
