/*
 * Lcd.h
 *
 * Created: 2/3/2020 03:35:50 PM
 *  Author: User
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL			
#include <util/delay.h>			
#include "Lcd_cfg.h"

void LCD_Init (void) ;
void LCD_WriteCommand(uint8 command);
void LCD_WriteChar(uint8 character);
void LCD_WriteString (char *str);
void LCD_Clear();
void LCD_String_xy (uint8 row, uint8 col, char* str);

void pulse_EN_LCD (void);

#endif /* LCD_H_ */