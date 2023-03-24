 /***********************************************************/
/***************  Name   : Ahmed Elshehry **********************/
/***************  Date   : 29/12/2021  **********************/
/***************  SWC    : I2C        **********************/
/*************** Version : 1.0        **********************/
/***********************************************************/
#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define I2C_u8_TWDR_REG           *((volatile u8 *)0x23)
#define I2C_u8_TWAR_REG            *((volatile u8 *)0x22)
#define I2C_u8_TWSR_REG            *((volatile u8 *)0x21)
#define I2C_u8_TWBR_REG            *((volatile u8 *)0x20) 
/*opation  1-spi_mode_master
           2- spi_mode_slave       */   
#define        spi_mode_master              1
#define        spi_mode_slave               0
#endif