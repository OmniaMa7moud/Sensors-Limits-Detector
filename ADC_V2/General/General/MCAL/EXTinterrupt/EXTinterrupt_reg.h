/*
 * EXTinterrupt_reg.h
 *
 * Created: 10/22/2023 11:52:34 AM
 *  Author: omnia
 */ 

#include "../../LIB/std_macros.h"

#ifndef EXTINTERRUPT_REG_H_
#define EXTINTERRUPT_REG_H_

#define MCUCR *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)
#define GICR *((volatile u8*) 0x5b)
#define GIFR *((volatile u8*) 0x5a)


#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6


#define INT2 5
#define INT0 6
#define INT1 7

#define INTF2 5
#define INTF0 6
#define INTF1 7




#endif /* EXTINTERRUPT_REG_H_ */