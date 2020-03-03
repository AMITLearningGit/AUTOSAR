#ifndef LCD_H
#define LCD_H
		
#include "Lcd_cfg.h"
#include "STD_Types.h"

void LCD_Init (void) ;
void LCD_WriteCommand(uint8 command);
void LCD_WriteChar(uint8 character);
void LCD_WriteString (char *str);
void LCD_Clear(void);
void LCD_String_xy (uint8 row, uint8 col, char* str);

void pulse_EN_LCD (void);				//high to low pulse on enable pin

#endif /* LCD_H_ */
