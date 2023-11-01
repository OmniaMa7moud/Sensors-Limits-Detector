/*
 * ADDC_int.h
 *
 *  Created on: Aug 31, 2022
 *      Author: hp
 */
#include "ADC_cfg.h"
#include "ADC_pri.h"
#include "ADC_reg.h"
#include "../../LIB/std_macros.h"

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_


/*ADC Channels*/
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7



u8 ADC_GetValsync(u8 addresscpy);
void ADC_vInt(void);
void ADC_voidStartConversion(u8 addresscpy);
void ADC_voidDisable();
void ADC_voidEnable();

void ADC_voidEnableInt();
void ADC_voidDisableInt();
u8 ADC_GetValAsync();
void EXT16_VID_SET_CALL_BACK(void (*PTR0)(void));

void __vector_16 (void) __attribute__ ((signal,used, externally_visible));
#endif /* MCAL_ADC_ADC_INT_H_ */
