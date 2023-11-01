/*
 * GIE.c
 *
 * Created: 10/22/2023 12:02:27 PM
 *  Author: omnia
 */ 

#include "GIE_reg.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}