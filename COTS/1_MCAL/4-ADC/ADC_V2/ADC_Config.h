/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef		ADC_CONFIG_H
#define		ADC_CONFIG_H

/* Options:to select voltage refrance
			ADC_AREF	
			ADC_AVCC    
			ADC_INTERNAL
*/
#define		ADC_REFVOLT		ADC_AVCC


/* Options:
			1- RIGHT
            2- LEFT
*/
#define  ADC_ADJUST_CTRL		 RIGHT

/* Options:to seclect prescaler
      1-  ADC_PRESCALAR_BY_2
      2-  ADC_PRESCALAR_BY_4
      3-  ADC_PRESCALAR_BY_8
      4-  ADC_PRESCALAR_BY_16
      5-  ADC_PRESCALAR_BY_32
      6-  ADC_PRESCALAR_BY_64
      7-  ADC_PRESCALAR_BY_128         */

#define        ADC_PRESCALAR_VAL    ADC_PRESCALAR_BY_128


#endif
