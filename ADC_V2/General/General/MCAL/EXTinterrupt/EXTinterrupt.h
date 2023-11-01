/*
 * EXTinterrupt.h
 *
 * Created: 10/22/2023 11:52:16 AM
 *  Author: omnia
 */ 

#include "EXTinterrupt_config.h"
#include "EXTinterrupt_reg.h"
#include "../../LIB/std_macros.h"

#ifndef EXTINTERRUPT_H_
#define EXTINTERRUPT_H_


void EXTinterrupt_init();

void EXT0_VID_SET_CALL_BACK(void (*PTR0)(void));
void EXT1_VID_SET_CALL_BACK(void (*PTR1)(void));
void EXT2_VID_SET_CALL_BACK(void (*PTR2)(void));

void _vector_1 (void) __attribute__ ((signal,used, externally_visible));
void _vector_2 (void) __attribute__ ((signal,used, externally_visible));
void _vector_3 (void) __attribute__ ((signal,used, externally_visible));

#endif /* EXTINTERRUPT_H_ */