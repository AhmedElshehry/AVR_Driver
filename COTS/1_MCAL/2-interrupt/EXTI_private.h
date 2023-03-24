/*******************************************/
/*************Name:Ahmed Elshehry ************/
/*************data 17/12/2021 ************/
/************* sw:external interrupt   ************/
/*************version 1.0 ************/
#ifndef    EXTI_private_H
#define   EXTI_private_H

//   define register of external interrupt
#define  EXTI_u8_MCUCR                   *((volatile u8  *) 0x55)
#define  EXTI_u8_MCUSR                   *((volatile u8  *) 0x54 )

#define  EXTI_u8_GICR                      *((volatile u8 *) 0x5B)
#define  EXTI_u8_GIFR                      *((volatile u8 *) 0x5A)














#endif