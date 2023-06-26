#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum
{
    NoError,
    NullPtrErr,
    StartCondErr,
    RepStartErr,
    SendWriteErr,
    SendReadErr,
    WriteDataErr,
    ReadDataErr,
} TWI_ErrorStatus_t;

/// @brief init mcu as master node on the bus
/// @param copy_u8Address address of node pass 0 if u don't want to write address
void TWI_voidMasterInit(uint8 copy_u8Address);

/// @brief init mcu as slave
/// @param copy_u8Address address of slave
void TWI_voidSlaveInit(uint8 copy_u8Address);

/// @brief master send start condition on bus to init the frame
/// @return error state 
TWI_ErrorStatus_t TWI_SendStartCondition();

/// @brief send start condition again
/// @return error state 
TWI_ErrorStatus_t TWI_SendRepeatedStart();

/// @brief send read flag for given slave address
/// @param copy_u8SLA 7-bit slave address
/// @return error state 
TWI_ErrorStatus_t TWI_SendSLAWithWrite(uint8 copy_u8SLA);

/// @brief send write flag for given slave address
/// @param copy_u8SLA 7-bit slave address
/// @return error state 
TWI_ErrorStatus_t TWI_SendSLAWithRead(uint8 copy_u8SLA);

/// @brief write 8-bit data on the bus
/// @param copy_u8DataByte 8-bit data to send
/// @return error state 
TWI_ErrorStatus_t TWI_MasterWriteDataByte(uint8 copy_u8DataByte);

/// @brief read data from slave 
/// @param ref_u8DataByte address to save data 
/// @return error state 
TWI_ErrorStatus_t TWI_MasterReceiveDataByte(uint8 *ref_u8DataByte);

/// @brief end of frame signal
void TWI_SendStopCondition();
#endif