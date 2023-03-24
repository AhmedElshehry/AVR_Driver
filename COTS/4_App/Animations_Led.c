/*
 * mian.c
 *
 *  Created on: Jan 17, 2023
 *      Author: Ahmed Elshehry
 */
#include "DIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define BUTTON_PRESSED   0
int main(void)
{
	u8 Button_statue=1,Return;
    DIO_voidInit();
	while(1)
	{
		for(int i=0;i<7;i++)
		{
			 Return =DIO_u8SetPinValue(DIO_u8_PORTC, i,DIO_u8_HIGH);
			 Return =DIO_u8SetPinValue(DIO_u8_PORTB, i,DIO_u8_LOW);
			 _delay_ms(50);
			 Return =DIO_u8SetPinValue(DIO_u8_PORTC, i ,DIO_u8_LOW);
			 Return =DIO_u8SetPinValue(DIO_u8_PORTB, i,DIO_u8_HIGH);


		}

	}


return 0;
}

