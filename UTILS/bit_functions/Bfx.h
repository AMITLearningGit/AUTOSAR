/*
 * Bfx.h
 *
 * Created: 05/02/2020 07:25:15 PM
 *  Author: omar_
 */ 

#ifndef BFX_H_
#define BFX_H_
#include "Std_Types.h"
#define TRUE 1
#define FALSE 0
typedef uint8 boolean;



void Bfx_SetBit_u8u8 (uint8* Data,uint8 BitPn);
void Bfx_ClrBit_u8u8(uint8* Data,uint8 BitPn);
boolean Bfx_GetBit_u8u8_u8 (uint8* Data,uint8 BitPn);
void Bfx_SetBitMask_u8u8(uint8* Data, uint8 BitPn);
#endif /* BFX_H_ */