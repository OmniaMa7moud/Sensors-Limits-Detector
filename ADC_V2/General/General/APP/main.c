/*
 * main.c
 *
 * Created: 10/20/2023 11:49:57 AM
 *  Author: omnia
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "..\MCAL\DIO\DIO.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/GIE/GIE.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/EXTinterrupt/EXTinterrupt.h"

void ISR_ADC(void);
void ISR_INT0(void);

	u8 addresscpy = 0;
	u8 readValu = 0 ;
	u8 adcValue = 0 ;
	u8 channelNum = 0;
	static u8 arr[3];

void clearLine()
{
	LCD_MOVE_CURSOR(4,1);
	LCD_SEND_STRING("                    ");
}


void ENABLE_INT0()
{
		DIO_SetPinVal(PD, 7 , 1);
			_delay_ms(10);
		DIO_SetPinVal(PD, 7 , 0);
			_delay_ms(10);
}



void checkLimit()
{
	//Temp limit
	if( (arr[0]>75) )
	{
		channelNum = 0;
		ENABLE_INT0();
	}//LDR limit
	else if(arr[1]> 150)
	{
		channelNum = 1;
		ENABLE_INT0();
	}//POT limit
	else if(arr[2]>150) 
	{
		channelNum = 2;
		ENABLE_INT0();
	}
	else 
	{//clear Buzzer
		 DIO_SetPinVal(PC,0,1); clearLine();
	}
}

int main()
{
	EXT0_VID_SET_CALL_BACK(ISR_INT0);
	EXT16_VID_SET_CALL_BACK(ISR_ADC);
	DIO_init();
	LCD_INIT();
	_delay_ms(500);
	GIE_voidEnable();
	EXTinterrupt_init();
	ADC_vInt();
	ADC_voidStartConversion(0);
	DIO_SetPinVal(PC, 0, 1);
	
	while(1)
	{

		LCD_MOVE_CURSOR(1,1);
		LCD_write_char(0x30);
		LCD_write_char((arr[0]/100)+48);
		LCD_write_char(((arr[0]/10)%10)+48);
		LCD_write_char((arr[0]%10)+48);
		LCD_write_char(0xDF);
		LCD_write_char(0x43);
		
		LCD_MOVE_CURSOR(2,1);
		LCD_write_char(0x30);
		LCD_write_char((arr[1]/100)+48);
		LCD_write_char(((arr[1]/10)%10)+48);
		LCD_write_char((arr[1]%10)+48);
		LCD_SEND_STRING(" LUX");
		
		LCD_MOVE_CURSOR(3,1);
		LCD_write_char(0x30);
		LCD_write_char((arr[2]/100)+48);
		LCD_write_char(((arr[2]/10)%10)+48);
		LCD_write_char((arr[2]%10)+48);
		LCD_SEND_STRING(" OHM");
		
		
		adcValue = ADC_GetValAsync();
		if(addresscpy == 0)
		{
			arr[0] = adcValue;
			addresscpy = 1;
			ADC_voidStartConversion(1);
		}
		else if(addresscpy == 1)
		{
			if(adcValue != 0) {arr[1] = adcValue;}
			addresscpy = 2;
			ADC_voidStartConversion(4);
		}
		else if(addresscpy == 2)
		{
			if(adcValue != 0) {arr[2] = adcValue;}
			addresscpy = 0;
			ADC_voidStartConversion(0);
		}
		checkLimit();
	}
}


void ISR_INT0(void)
{
	DIO_SetPinVal(PC,0,0); 
	if(channelNum == 0)
	{
		LCD_MOVE_CURSOR(4,1);
		LCD_SEND_STRING("Temp Exceeded Limit.");
	}
	else if(channelNum == 1)
	{
		LCD_MOVE_CURSOR(4,1);
		LCD_SEND_STRING("Light ExceededLimit.");
	}
	else if(channelNum == 2)
	{
		LCD_MOVE_CURSOR(4,1);
		LCD_SEND_STRING("Res Exceeded Limit.");
	}
	DIO_SetPinVal(PD, 2 , 1);
	_delay_ms(1000);
}


void ISR_ADC(void)
{
	
}

