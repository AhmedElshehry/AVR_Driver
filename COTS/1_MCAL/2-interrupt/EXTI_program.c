/*******************************************/
/*************Name:Ahmed Elshehry ************/
/*************data 17/12/2021 ************/
/************* sw:external interrupt   ************/
/*************version 1.0 ************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_congh.h"
#include "EXTI_interface.h"

// Global array of pointer to funcation
 static void (*EXTI_ApfEXTI[3])(void)={NULL,NULL,NULL};


u8  EXTI_u8EXTIsetcallback( u8 capy_u8_index,void (*capy_pf) (void) )
{
u8 local_error_state =STD_TYPES_OK;
// cheek the interrupt with range and the pointer not null
  if((u8 capy_u8_index<=EXTI_u8_INT2)&&(capy_pf!=NULL))
  {   //put the adder from call back to pointer of index interrupt to action ISR 
	  EXTI_ApfEXTI[capy_u8_index]=capy_pf;
  }
   else 
   {
	   local_error_state=STD_TYPES_NOK;
	   
   }
   
return local_error_state;
}

//  PROTOTYPE External interrupt INT0 
void __vector_1(void)      __attribute__((signal));
void __vector_1(void)
{     // cheek the pointer not null 
       if(EXTI_ApfEXTI[EXTI_u8_INT0]!=NULL)
	   {//call the isr funcation to exacution INT0
		  EXTI_ApfEXTI[EXTI_u8_INT0]();
	   }
} 

//prototype  External interrupt INT1 
void __vector_2(void)      __attribute__((signal));
void __vector_2(void)
{     if( EXTI_ApfEXTI[EXTI_u8_INT1]!=NULL)
	  {
		  EXTI_ApfEXTI[EXTI_u8_INT1]();
	  }
} 
	
//prototype External interrupt INT2
void __vector_3(void)      __attribute__((signal));
void __vector_3(void)
{     if( EXTI_ApfEXTI[EXTI_u8_INT2]!=NULL)
	  {
		  EXTI_ApfEXTI[EXTI_u8_INT2]();
	  }
} 

u8 EXTI_u8EXTI_Enable(u8 capy_u8EXTI_index,u8 capy_u8Edge_index)
	{
		u8 local_error_state=STD_TYPES_OK; 
		switch(capy_u8EXTI_index)
		{
			case EXTI_u8_INT0:
			     switch {capy_u8Edge_index)
			     {
			     	case EXTI_u8raising_edge:
			     	SET_BIT(EXTI_u8_MCUCR,0);
			     	SET_BIT(EXTI_u8_MCUCR,1);
					/*   enable the flag of interrupt of Galbal INT0 ==>GIE */
					//enable EXTI INt0
					SET_BIT(EXTI_u8_GICR ,6);
			     	break;
					case EXTI_u8failing_edge:
			     	CLR_BIT(EXTI_u8_MCUCR,0);
			     	SET_BIT(EXTI_u8_MCUCR,1);
					/*   enable the flag of interrupt of Galbal INT0 ==>GIE */
					//enable EXTI INt0
					SET_BIT(EXTI_u8_GICR ,6);
			     	break;
				    case EXTI_u8any_logic_change_edge:
			     	SET_BIT(EXTI_u8_MCUCR,0);
					CLR_BIT(EXTI_u8_MCUCR,1);
					/*   enable the flag of interrupt of Galbal INT0 ==>GIE */
					//enable EXTI INt0
					SET_BIT(EXTI_u8_GICR ,6);
			     	break;
				    case  EXTI_u8low_level_edge :
			     	CLR_BIT(EXTI_u8_MCUCR,0);
			     	CLR_BIT(EXTI_u8_MCUCR,1);
					/*   enable the flag of interrupt of Galbal INT0 ==>GIE */
					//enable EXTI INt0
					SET_BIT(EXTI_u8_GICR ,6);
			     	break;
					default local_error_state=STD_TYPES_NOK;
			     }
		   break;
		   case EXTI_u8_INT1:
			     switch {capy_u8Edge_index)
			     {
			     	case EXTI_u8raising_edge:
			     	SET_BIT(EXTI_u8_MCUCR,2);
			     	SET_BIT(EXTI_u8_MCUCR,3);
					/*   enable the flag of interrupt of Galbal INT1 ==>GIE */
					//enable EXTI INT1
					SET_BIT(EXTI_u8_GICR ,7);
			     	break;
					case EXTI_u8failing_edge:
			     	CLR_BIT(EXTI_u8_MCUCR,2);
			     	SET_BIT(EXTI_u8_MCUCR,3);
					/*   enable the flag of interrupt of Galbal INT1 ==>GIE */
					//enable EXTI INT1
					SET_BIT(EXTI_u8_GICR ,7);
			     	break;
				    case EXTI_u8any_logic_change_edge:
			     	SET_BIT(EXTI_u8_MCUCR,2);
					CLR_BIT(EXTI_u8_MCUCR,3);
					/*   enable the flag of interrupt of Galbal INT1 ==>GIE */
					//enable EXTI INT1
					SET_BIT(EXTI_u8_GICR ,7);
			     	break;
				    case  EXTI_u8low_level_edge :
			     	CLR_BIT(EXTI_u8_MCUCR,2);
			     	CLR_BIT(EXTI_u8_MCUCR,3);
					/*   enable the flag of interrupt of Galbal INT1==>GIE */
					//enable EXTI INT1
					SET_BIT(EXTI_u8_GICR ,7);
			     	break;
					default local_error_state=STD_TYPES_NOK;
			     }
		   break;
		   case EXTI_u8_INT2:
			     switch {capy_u8Edge_index)
			     {
			     	case EXTI_u8raising_edge:
			     	SET_BIT(EXTI_u8_MCUCSR,6);
					/*   enable the flag of interrupt of Galbal INT2 ==>GIE */
					//enable EXTI INT2
					SET_BIT(EXTI_u8_GICR ,5);
			     	break;
					case EXTI_u8failing_edge:
			     	CLR_BIT(EXTI_u8_MCUCSR,6);
					/*   enable the flag of interrupt of Galbal INT2 ==>GIE */
					//enable EXTI INT2
					SET_BIT(EXTI_u8_GICR ,5);
			     	break;
					default local_error_state=STD_TYPES_NOK;
			     }
		   break;
		   default local_error_state=STD_TYPES_NOK;
		
		}
		return local_error_state;
		
	}


	