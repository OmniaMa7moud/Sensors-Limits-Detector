/*
 * ADC_cfg.h
 *
 *  Created on: Aug 31, 2022
 *      Author: hp
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

#include "../../LIB/std_macros.h"
#include "ADC_pri.h"

#define  ADC_AUTO_TRIGGER_EN ENABLE
/*
 Free_Running_mode 
 Analog_Comparator
 External_Interrupt0 
 Timer0_Compare_Match 
 Timer0_Overflow 
  Timer1_Compare_MatchB 
 Timer1_Overflow 
 Timer1_Capture_Event 
*/
#define ADC_AUTO_TRIGGER_SOURCE Free_Running_mode

#define Voltage_reference AVCC


/*options PRESCALER_MODE:
 PRESCALER2
 PRESCALER4
 PRESCALER8
 PRESCALER16
 PRESCALER32
 PRESCALER64
 PRESCALER128
 * */
#define PRESCALLER PRESCALER64

/*
WRITE_ADJUSTMENT
LEFT_ADJUSTMENT
*/
#define ADJUSTMENT LEFT_ADJUSTMENT




#endif /* MCAL_ADC_ADC_CFG_H_ */
