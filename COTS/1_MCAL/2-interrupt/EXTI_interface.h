/*******************************************/
/*************Name:Ahmed Elshehry ************/
/*************data 17/12/2021 ************/
/************* sw:external interrupt   ************/
/*************version 1.0 ************/
#ifndef    EXTI_interface_H
#define   EXTI_interface_H

 // macro of external interrupt index   
#define  EXTI_u8_INT0                         0
#define  EXTI_u8_INT1                         1
#define  EXTI_u8_INT2                         2

 //macro of edge index 
 #define EXTI_u8raising_edge                                 0
 #define EXTI_u8failing_edge                                 1 
 #define EXTI_u8any_logic_change_edge                        2 
 #define EXTI_u8low_level_edge                               3   
   // the prototype of the funcation call back from software applacation to ISR TO work 
u8  EXTI_u8EXTIsetcallback( u8 capy_u8_index,void (*capy_pf) (void) );
// the function to select the interrupt when do and the index of interrupt 
u8 EXTI_u8EXTI_Enable(u8 capy_u8EXTI_index,u8 capy_u8Edge_index);
//the protot type to disable interrupt 
u8 EXTI_u8EXTI_disable(u8 capy_u8EXTI_index );















#endif