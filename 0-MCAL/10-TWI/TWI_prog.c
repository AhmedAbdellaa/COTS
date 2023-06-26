
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/STD_TYPES_H.h"
#include "TWI_interface.h"
#include "TWI_reg.h"
#include "TWI_prv.h"

void TWI_voidMasterInit(uint8 copy_u8Address)
{
	/*set master address skip if 0*/
	if (copy_u8Address != 0u)
	{
		TWAR = copy_u8Address << 1;
	}
	else
	{
		/**/
	}
	/*cpu freq = 16MHZ,prescaler = 0,communication freq = 400khz*/
	CLS_BIT(TWSR, TWSR_TWPS1);
	CLS_BIT(TWSR, TWSR_TWPS0);
	TWBR = 12u;
	/*enable acknowledgment */
	SET_BIT(TWCR, TWCR_TWEA);
	/*twi enable*/
	SET_BIT(TWCR, TWCR_TWEN);
}
void TWI_voidSlaveInit(uint8 copy_u8Address)
{
	/*set slave address */
	TWAR = copy_u8Address << 1;

	/*cpu freq = 16MHZ,prescaler = 0,communication freq = 400khz*/
	CLS_BIT(TWSR, TWSR_TWPS1);
	CLS_BIT(TWSR, TWSR_TWPS0);
	TWBR = 12u;
	/*enable acknowledgment */
	SET_BIT(TWCR, TWCR_TWEA);
	/*twi enable*/
	SET_BIT(TWCR, TWCR_TWEN);
}
TWI_ErrorStatus_t TWI_SendStartCondition()
{
	TWI_ErrorStatus_t Local_u8ErrorState = NoError;
	/*set start condition bit*/
	SET_BIT(TWCR, TWCR_TWSTA);
	/*clear the flag to enable previous action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*wait until the previous action finish*/
	while ((GET_BIT(TWCR, TWCR_TWINT)) == 0)
	{
	}
	/*check the status of the bus*/
	if ((TWSR & TWSR_TWS_MASK) != START_ACK)
	{
		Local_u8ErrorState = StartCondErr;
	}
	else
	{
	}
	return Local_u8ErrorState;
}

TWI_ErrorStatus_t TWI_SendRepeatedStart()
{
	TWI_ErrorStatus_t Local_u8ErrorState = NoError;
	/*set start condition bit*/
	SET_BIT(TWCR, TWCR_TWSTA);
	/*clear the flag to enable previous action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*wait until the previous action finish*/
	while ((GET_BIT(TWCR, TWCR_TWINT)) == 0)
	{
	}
	/*check the status of the bus*/
	if ((TWSR & TWSR_TWS_MASK) != REP_START_ACK)
	{
		Local_u8ErrorState = RepStartErr;
	}
	else
	{
	}
	return Local_u8ErrorState;
}
TWI_ErrorStatus_t TWI_SendSLAWithWrite(uint8 copy_u8SLA)
{
	TWI_ErrorStatus_t Local_u8ErrorState = NoError;

	/*write slave address*/
	TWDR = (copy_u8SLA << 1u);
	/*clear bit 0 for write request*/
	CLS_BIT(TWDR, 0u);

	/*clear start condition bit*/
	CLS_BIT(TWCR, TWCR_TWSTA);
	/*clear the flag to enable previous action*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*wait until the previous action finish*/
	while ((GET_BIT(TWCR, TWCR_TWINT)) == 0)
	{
	}
	/*check the status of the bus*/
	if ((TWSR & TWSR_TWS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_u8ErrorState = SendWriteErr;
	}
	else
	{
	}
	return Local_u8ErrorState;
}
TWI_ErrorStatus_t TWI_SendSLAWithRead(uint8 copy_u8SLA)
{
	TWI_ErrorStatus_t Local_u8ErrorState = NoError;

	/*write slave address*/
	TWDR = (copy_u8SLA << 1u);
	/*set bit 1 for write request*/
	SET_BIT(TWDR, 0u);
	/*clear start condition bit*/
	CLS_BIT(TWCR, TWCR_TWSTA);
	/*clear the flag to enable previous action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*wait until the previous action finish*/
	while ((GET_BIT(TWCR, TWCR_TWINT)) == 0)
	{
	}
	/*check the status of the bus*/
	if ((TWSR & TWSR_TWS_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_u8ErrorState = SendReadErr;
	}
	else
	{
	}
	return Local_u8ErrorState;
}
TWI_ErrorStatus_t TWI_MasterWriteDataByte(uint8 copy_u8DataByte)
{
	TWI_ErrorStatus_t Local_u8ErrorState = NoError;

	/*write data on bus*/
	TWDR = copy_u8DataByte;
	/*clear the flag to enable previous action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*wait until the previous action finish*/
	while ((GET_BIT(TWCR, TWCR_TWINT)) == 0)
	{
	}
	/*check the status of the bus*/
	if ((TWSR & TWSR_TWS_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_u8ErrorState = WriteDataErr;
	}
	else
	{
	}
	return Local_u8ErrorState;
}
TWI_ErrorStatus_t TWI_MasterReceiveDataByte(uint8 *ref_u8DataByte)
{
	TWI_ErrorStatus_t Local_u8ErrorState = NoError;
	if(ref_u8DataByte != NULL){
	/*clear the flag to enable slave to send data*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*wait until the previous action finish*/
	while ((GET_BIT(TWCR, TWCR_TWINT)) == 0)
	{
	}
	/*check the status of the bus*/
	if ((TWSR & TWSR_TWS_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_u8ErrorState = ReadDataErr;
	}
	else
	{
		/*read data from bus*/
		*ref_u8DataByte = TWDR;
	}
	}
	else{
		Local_u8ErrorState = NullPtrErr;
	}
	return Local_u8ErrorState;
}
void TWI_SendStopCondition()
{
	/*set stop condition bit*/
	SET_BIT(TWCR, TWCR_TWSTO);
	SET_BIT(TWCR,TWCR_TWEN);
	/*clear the flag to enable previous action*/
	SET_BIT(TWCR, TWCR_TWINT);
	
}
