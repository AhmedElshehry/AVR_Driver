/***********************************************************/
/***************  Name   : Ahmed Elshehry **********************/
/***************  Date   : 28/12/2021  **********************/
/***************  SWC    : SPI        **********************/
/*************** Version : 1.0        **********************/
/***********************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPI_u8_SPDR_REG           *((volatile u8 *)0x2F)
#define SPI_u8_SPCR_REG            *((volatile u8 *)0x2D)
#define SPI_u8_SPSR_REG            *((volatile u8 *)0x2E)

/*opation  1-spi_mode_master
           2- spi_mode_slave       */   
#define        spi_mode_master              1
#define        spi_mode_slave               0
#endif