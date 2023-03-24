 /***********************************************************/
/***************  Name   : Ahmed Elshehry **********************/
/***************  Date   : 29/12/2021  **********************/
/***************  SWC    : I2C        **********************/
/*************** Version : 1.0        **********************/
/***********************************************************/
/* Lib layer */
#include"STD_TYPES.h"
#include"BIT_MATH.h"


void I2C_void_master_init(void)
{
	//step to inialation i2c
	
	/*set prescale value of freq */
	//set twbr with value ==> 200khz
	//enable the ack 
	// enable i2c 
	CLR_BIT(I2C_u8_TWSR_REG,0);
	CLR_BIT(I2C_u8_TWSR_REG,1);
	I2C_u8_TWBR_REG=12;
	//enable the ack 
	SET_BIT(I2C_u8_TWCR_REG,6);
	// enable i2c 
	SET_BIT(I2C_u8_TWCR_REG,2);
}

I2C_Errorstate I2C_void_slave_init(u8 capy_u8adress)
{    
    I2C_Errorstate   local_enum_error_state=i2c_ok;
    if (capy_u8adress<=127)
	{
    //SET THE FLAG ADDRES 
	I2C_u8_TWAR_REG=capy_u8adress<<1;
	//enable the ack 
	// enable i2c 
	SET_BIT(I2C_u8_TWCR_REG,6);
	SET_BIT(I2C_u8_TWCR_REG,2);
	}
	
	else 
	{
		local_enum_error_state=i2c_error_adress;
	}
	return local_enum_error_state;
}


I2C_Errorstate   I2C_sent_start_conditio(void)
{   
    I2C_Errorstate local_enum_error_state=i2c_ok
    //clear the flag 
	SET_BIT(I2C_u8_TWCR_REG,7);
	//set start bit 
	SET_BIT(I2C_u8_TWCR_REG,5);
	//wait the flag action is set
	while((GET_BIT(I2C_u8_TWCR_REG,7))==0);
	//Cheek the ack start condation
	
    if((I2C_u8_TWSR_REG & 0XF8)!=0x08))
	{	
       local_enum_error_state=i2c_sc_error;
    }
	
    //clear start bit 
    CLR_BIT(I2C_u8_TWCR_REG,5);
	return loca_eunm_error_state;
}




I2C_Errorstate I2C_sent_restart_conditio(void)
{
	I2C_Errorstate local_enum_error_state=i2c_ok;
    //clear the flag 
	SET_BIT(I2C_u8_TWCR_REG,7);
	//set start bit 
	SET_BIT(I2C_u8_TWCR_REG,5);
	//wait the flag action is set
	while((GET_BIT(I2C_u8_TWCR_REG,7))==0);
	//Cheek the ack start condation
	if((I2C_u8_TWSR_REG & 0XF8)!=0x10))
	    {
	    local_enum_error_state=i2c_rsc_error;
	    
	    }
	
    //clear start bit 
    CLR_BIT(I2C_u8_TWCR_REG,5);
    return loca_eunm_error_state;
}


I2C_Errorstate I2C_sent_stop_conditio(void)
{
	I2C_Errorstate local_enum_error_state=i2c_ok;
	//clear the flag 
	CLR_BIT(I2C_u8_TWCR_REG,7);
	//set stOP CONDATION bit 
	SET_BIT(I2C_u8_TWCR_REG,4);
	return local_enum_error_state;
	
}

I2C_Errorstate  I2C_u8sent_slave_adr_withwrite(u8 capy_u8slaveaddress)
{

	
	
	I2C_Errorstate local_enum_error_state=i2c_ok;
	
	
    //write slave address and 0 to write 
	I2C_u8_TWDR_REG=capy_u8slaveaddress<<1;
	CLR_BIT(I2C_u8_TWDR_REG,0);
	
	//clear the flag 
    CLR_BIT(I2C_u8_TWCR_REG,7);
	//wait for the flage to be 1
	while((GET_BIT(I2C_u8_TWCR_REG,7))==0);
	//check the status code =sla+w
	//Cheek the stutas code to writedata_master
	if((I2C_u8_TWSR_REG & 0XF8)!=0x18))
	    {
	    local_enum_error_state=i2c_sla_w_error;
	    }
	
	return loca_eunm_error_state;
}
I2C_Errorstate I2C_u8sent_slave_adr_withread(u8 capy_u8slaveaddress)
{
	//write slave address and 1 to write 
	//clear flag 
	//wait for the flage to be 1
	//check the status code =sla+r
	
	I2C_Errorstate local_enum_error_state=i2c_ok;
    //write slave address and 0 to write 
	I2C_u8_TWDR_REG=capy_u8slaveaddress<<1;
	SET_BIT(I2C_u8_TWDR_REG,0);

	//clear the flag 
    CLR_BIT(I2C_u8_TWCR_REG,7);
	
	//wait for the flage to be 1
	while((GET_BIT(I2C_u8_TWCR_REG,7))==0);
	//check the status code =sla+R
	//Cheek the stutas code to writedata_master
	if((I2C_u8_TWSR_REG & 0XF8)!=0x40))
	    {
	    local_enum_error_state=i2c_sla_R_error;
	    }
	
	return loca_eunm_error_state;
}

I2C_Errorstate I2C_sent_DATAByte(u8 capy_databyte)
{   
    I2C_Errorstate loca_eunm_error_state=I2C_OK;
	//write data in twdr
	I2C_u8_TWDR_REG=capy_databyte;
	//clear the flag 
    CLR_BIT(I2C_u8_TWCR_REG,7);

	//wait for the flage to be 1
	while((GET_BIT(I2C_u8_TWCR_REG,7))==0);
	//check the status code =master sent recive
	if((I2C_u8_TWSR_REG & 0XF8)!=0x28))
	    {
	    local_enum_error_state=i2c_MT_DATA_error;
	    }
	return local_enum_error_state;
}


I2C_Errorstate I2C_read_DATAByte(u8 *capy_puRuturendatabyte)
{
	I2C_Errorstate loca_eunm_error_state=I2C_OK;
	//cheek pointer 
	if(capy_puRuturendatabyte!=NULL)
	{
		//clear the flag 
        CLR_BIT(I2C_u8_TWCR_REG,7);
		//wait for the flage to be 1
	    while((GET_BIT(I2C_u8_TWCR_REG,7))==0);
	    //check the status code =master recived data
	    if((I2C_u8_TWSR_REG & 0XF8)!=0x50))
	    {
	         local_enum_error_state=i2c_master_R_error;
	    }
		else 
		{
			*capy_puRuturendatabyte=I2C_u8_TWDR_REG;
		}

		
	}
	else 
	{
		loca_eunm_error_state=i2c_pointer_error;
	}
		return local_enum_error_state;
	//wait for the while be 1
}