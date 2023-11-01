/*
 * ADC_prg.c
 *
 *  Created on: Aug 31, 2022
 *      Author: hp
 */

#include "ADC_int.h"
#include <util/delay.h>

void (*Callback)(void) = NULL;

void ADC_voidEnable()
{
	SET_BIT(ADCSRA,ADEN);
}

void ADC_voidDisable()
{
	CLR_BIT(ADCSRA,ADEN);
}


void ADC_voidStartConversion(u8 addresscpy)
{
	ADMUX=(ADMUX&0xE0)|addresscpy;
	SET_BIT(ADCSRA,ADSC);
}


void ADC_vInt(void)
{
	
	//config DIO in DIO_config.h
	switch(Voltage_reference)
	{
		case 0:
			CLR_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case 1:
			SET_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case 2:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
	}
	
	switch(ADJUSTMENT)
	{
		case 0:
			CLR_BIT(ADMUX,ADLAR);
			break;
		case 1:
			SET_BIT(ADMUX,ADLAR);
			break;
	}
	
	switch(PRESCALLER)
	{
		case 0:
			SET_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
		case 1:
			CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
		case 2:
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
			
		case 3:
			CLR_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		
		case 4:
			SET_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		
		case 5:
			CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		
		case 6:
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
	}
	switch(ADC_AUTO_TRIGGER_EN)
	{
		
		case 0:
			ADC_voidDisableInt();
			break;
			
		case 1:
			switch(ADC_AUTO_TRIGGER_SOURCE)
			{
				case 0:
					CLR_BIT(SFIOR, ADTS0);
					CLR_BIT(SFIOR, ADTS1);
					CLR_BIT(SFIOR, ADTS2);
					break;
				case 1:
					SET_BIT(SFIOR, ADTS0);
					CLR_BIT(SFIOR, ADTS1);
					CLR_BIT(SFIOR, ADTS2);
					break;
				case 2: //ext
					CLR_BIT(SFIOR, ADTS0);
					SET_BIT(SFIOR, ADTS1);
					CLR_BIT(SFIOR, ADTS2);
					break;
				case 3:
					SET_BIT(SFIOR, ADTS0);
					SET_BIT(SFIOR, ADTS1);
					CLR_BIT(SFIOR, ADTS2);
					break;
				case 4:
					CLR_BIT(SFIOR, ADTS0);
					CLR_BIT(SFIOR, ADTS1);
					SET_BIT(SFIOR, ADTS2);
					break;
				case 5:
					SET_BIT(SFIOR, ADTS0);
					CLR_BIT(SFIOR, ADTS1);
					SET_BIT(SFIOR, ADTS2);
					break;
				case 6:
					CLR_BIT(SFIOR, ADTS0);
					SET_BIT(SFIOR, ADTS1);
					SET_BIT(SFIOR, ADTS2);
					break;
				case 7:
					SET_BIT(SFIOR, ADTS0);
					SET_BIT(SFIOR, ADTS1);
					SET_BIT(SFIOR, ADTS2);
					break;
			}
			
			
			
			ADC_voidEnableInt();
			break;
			
		default:
			break;
	}
	
	
	ADC_voidEnable();
}



u8 ADC_GetValsync(u8 addresscpy)
{
	ADC_voidStartConversion(addresscpy);
	while((READ_BIT(ADCSRA,ADSC)));
	return ADCH;
}


u8 ADC_GetValAsync()
{
	return ADCH;
}


void ADC_voidEnableInt()
{
	SET_BIT(ADCSRA, ADIE);
	SET_BIT(ADCSRA, ADATE);
}


void ADC_voidDisableInt()
{
	CLR_BIT(ADCSRA, ADIE);
	CLR_BIT(ADCSRA, ADATE);
}


void EXT16_VID_SET_CALL_BACK(void (*PTR0)(void))
{
	Callback = PTR0;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible));
void __vector_16 (void){  if(Callback != NULL){Callback();}  }
