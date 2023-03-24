/***********************************************************/
/***************  Name   : Ahmed Elshehry **********************/
/***************  Date   : 28/12/2021  **********************/
/***************  SWC    : SPI        **********************/
/*************** Version : 1.0        **********************/
/***********************************************************/
/* Lib layer */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void SPI_voidInit(void)
{
   #if (spi_select_mode==spi_mode_master) 
	   //THE Select the master 
 SET_BIT(SPI_u8_SPCR_REG,4);
   
     // to select the normal speed mode for the clk F_osc/4 
  CLR_BIT(SPI_u8_SPCR_REG,1);
  CLR_BIT(SPI_u8_SPCR_REG,0);
  CLR_BIT(SPI_u8_SPSR_REG,0);
   #elif (spi_select_mode==spi_mode_slave)
	   	   //THE Select the master 
    CLR_BIT(SPI_u8_SPCR_REG,4);
 //TO WORK DATA ORDER MSB  THE FRIST SENT 
 CLR_BIT(SPI_u8_SPCR_REG,5);
 
 // to select to work faling edga
  SET_BIT(SPI_u8_SPCR_REG,3);
  //select clock phase write data  with faling edga
   SET_BIT(SPI_u8_SPCR_REG,2);

  #endif
  //Eable the priPHaral SPI 
   SET_BIT(SPI_u8_SPCR_REG,6);
}