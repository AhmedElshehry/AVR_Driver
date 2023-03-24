/***********************************************************/
/***************  Name   : Ahmed Elshehry **********************/
/***************  Date   : 28/12/2021  **********************/
/***************  SWC    : SPI        **********************/
/*************** Version : 1.0        **********************/
/***********************************************************/
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include"STD_TYPES.h"
typedef enum 
{
	i2c_ok=1,
	i2c_error_adress,
	i2c_sc_error,
	i2c_rsc_error,
	i2c_stop_error,
	i2c_sla_w_error,
	i2c_sla_R_error,
	i2c_MT_DATA_error,
	i2c_pointer_error,
	i2c_master_R_error
}I2C_Errorstate;

void             I2C_void_master_init(void);
I2C_Errorstate   I2C_void_slave_init(u8 capy_u8adress);
I2C_Errorstate   I2C_sent_start_conditio(void);
I2C_Errorstate I2C_sent_restart_conditio(void);
I2C_Errorstate I2C_sent_stop_conditio(void);
I2C_Errorstate  I2C_u8sent_slave_adr_withwrite(u8 capy_u8slaveaddress);
I2C_Errorstate I2C_u8sent_slave_adr_withread(u8 capy_u8slaveaddress);
I2C_Errorstate I2C_sent_DATAByte(u8 capy_databyte);
I2C_Errorstate I2C_read_DATAByte(u8 *capy_puRuturendatabyte);

#endif
