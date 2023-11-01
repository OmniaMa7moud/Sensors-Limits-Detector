/*
 * EXTinterrupt_config.h
 *
 * Created: 10/22/2023 11:52:56 AM
 *  Author: omnia
 */ 

#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/std_macros.h"

#ifndef EXTINTERRUPT_CONFIG_H_
#define EXTINTERRUPT_CONFIG_H_



//Sence Control

#define SENSE_CONTROL0 FALLING_EDGE
#define SENSE_CONTROL1 FALLING_EDGE
//INT0 has only 2 modes (FALLING_EDGE - RISING_EDGE)
#define SENSE_CONTROL2 FALLING_EDGE
#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define ENABLE 1
#define DISABLE 0

#define EXTINT0_PORT PORTD
#define EXTINT1_PORT PORTD
#define EXTINT2_PORT PORTB

#define EXTINT0_PIN PIN2
#define EXTINT1_PIN PIN3
#define EXTINT2_PIN PIN2

#define EN_INT0 ENABLE
#define EN_INT1 DISABLE
#define EN_INT2 DISABLE 


#endif /* EXTINTERRUPT_CONFIG_H_ */