/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************  Name   :Ahmed elshehry *******************/
/***************  Date   : 12/12/2021  **********************/
/***************  SWC    : SEVEN SEGMENT DISPLAY     **********************/
/*************** Version : 1.0        **********************/
/***************************************************************************************/

#ifndef SEVENSEG_CONFIG_H
#define SEVENSEG_CONFIG_H
//#include "sevenseg_interface.h"
/*the config the Seven segment disblay 
opation : 1-  COMENN_ANODE 
          2-  COMENN_CATHODE  */
#define       COMMAN             COMENN_CATHODE

/*the config the Seven segment disblay to select PORT CONNECTED
opation : 1-  PORTA  
          2-  PORTB   */
#define       SEV_SEG_PORT        (DIO_u8_PORTC)

#define       FuncSev_valueDisplayNumber(A,B)                   DIO_u8SetPortValue(A,B)

#endif
