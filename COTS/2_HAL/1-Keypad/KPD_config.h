 /***********************************************************/
/***************  Name   : Ahmed Elshehry **********************/
/***************  Date   : 29/12/2021  **********************/
/***************  SWC    : Keypad       **********************/
/*************** Version : 1.0        **********************/
/***********************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H
/*PORT CONECTION */
#define KPD_u8_PORT             DIO_u8_PORTA
/* ROW PIN CONNECTION */
#define KPD_u8_R1_PIN           DIO_u8_PIN0
#define KPD_u8_R2_PIN           DIO_u8_PIN1
#define KPD_u8_R3_PIN           DIO_u8_PIN2
#define KPD_u8_R4_PIN           DIO_u8_PIN3
/* COULIM  PIN CONNECTION */
#define KPD_u8_C1_PIN           DIO_u8_PIN4
#define KPD_u8_C2_PIN           DIO_u8_PIN5
#define KPD_u8_C3_PIN           DIO_u8_PIN6
#define KPD_u8_C4_PIN           DIO_u8_PIN7
/* KEYPAD CONFIGRATION   */
#define KPD_KEYS               {{'1','2','3','+'},   \
				  	           {'4','5','6','-'},   \
				  	           {'7','8','9','*'},   \
				  	           {'0','=','/','%'}}
				              
#endif