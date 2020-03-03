/*
 * Bfx.c
 *
 * Created: 05/02/2020 07:30:40 PM
 *  Author: omar_
 */ 
#include "Std_Types.h"
#include "Bfx.h"


void Bfx_SetBit_u8u8 (uint8* Data,uint8 BitPn)
{
	*Data |= (1<<BitPn);
}

void Bfx_ClrBit_u8u8(uint8* Data,uint8 BitPn)
{
	*Data &= ~(1<<BitPn);
}

boolean Bfx_GetBit_u8u8_u8(uint8* Data,uint8 BitPn){	if(0 != (1 & (*Data>>BitPn)))	{		return TRUE;	}	else	{		return FALSE;	}}void Bfx_SetBitMask_u8u8(uint8* Data, uint8 Mask){	*Data = *Data | Mask;}