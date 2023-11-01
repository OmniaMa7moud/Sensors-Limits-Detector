/*
 * EXTinterrupt.c
 *
 * Created: 10/22/2023 11:52:05 AM
 *  Author: omnia
 */ 


#include "EXTinterrupt.h"

void (*CallbackFunc1)(void) = NULL;

void EXTinterrupt_init()
{
	//config DIO in DIO_config.h
	//Enable Interrupt
	 SET_BIT(GICR,INT0); 
	 SET_BIT(GICR,INT1); 
	 SET_BIT(GICR,INT2); 
		
	//Sense Control INT0
	switch(SENSE_CONTROL0)
	{
		case 0:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		
		case 1:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		case 2:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case 3:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		default:
			break;
	}
	
	//Sense Control INT1
	switch(SENSE_CONTROL1)
	{
		case 0:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		
		case 1:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		case 2:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		case 3:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		default:
			break;
	}
	//Sense Control INT2
	switch(SENSE_CONTROL2)
	{
		case 2:
			CLR_BIT(MCUCR,ISC10);
			break;
		case 3:
			SET_BIT(MCUCR,ISC10);
			break;
		default:
			break;
	}
}


void EXT0_VID_SET_CALL_BACK(void (*PTR0)(void))
{
	CallbackFunc1 = PTR0;
}

void __vector_1 (void) __attribute__ ((signal,used, externally_visible));
void __vector_1 (void) { if(CallbackFunc1 != NULL){ CallbackFunc1();}  }