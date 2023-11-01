/*
 * ADC_pri.h
 *
 *  Created on: Aug 31, 2022
 *      Author: hp
 */

#ifndef MCAL_ADC_ADC_PRI_H_
#define MCAL_ADC_ADC_PRI_H_

/*Prescaler Options*/
#define PRESCALER2   0
#define PRESCALER4   2
#define PRESCALER8   3
#define PRESCALER16  4
#define PRESCALER32  5
#define PRESCALER64  6
#define PRESCALER128 7


/*ADC Channels*/
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

/*ADC Channels Pin*/
#define ADC0_PIN 0
#define ADC1_PIN 1
#define ADC2_PIN 2
#define ADC3_PIN 3
#define ADC4_PIN 4
#define ADC5_PIN 5
#define ADC6_PIN 6
#define ADC7_PIN 7


#define WRITE_ADJUSTMENT 0
#define LEFT_ADJUSTMENT 1

#define ENABLE 1
#define DISABLE 0


#define AREF 0 
#define AVCC 1
#define Internal_Voltage 2 


//Trigger Sourse
#define Free_Running_mode 0
#define Analog_Comparator 1 
#define External_Interrupt0 2
#define Timer0_Compare_Match 3
#define Timer0_Overflow 4
#define  Timer1_Compare_MatchB 5
#define Timer1_Overflow 6
#define Timer1_Capture_Event 7


/*Prescaler Mask*/
//#define PRESCALER_MASK_BITS 0xf8

/*vector number of ADC interrupt*/
//void __vector_16 (void) __attribute__((signal));

/*Pointer to function*/
//ptr_fun_IvOu16_t G_ISR_ADC=ADDRESS_NULL;



#endif /* MCAL_ADC_ADC_PRI_H_ */
