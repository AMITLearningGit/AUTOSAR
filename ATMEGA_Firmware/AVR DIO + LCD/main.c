/*
 * main.c
 *
 * Created: 2/1/2020 02:54:48 PM
 *  Author: User
 */ 

#include "dio.h"
#include "dio_hw.h"
#include "dio_types.h"
#include "STD_Types.h"
#include "Port.h"
#include "Lcd.h"
#include "LEDs_cfg.h"


int main (void)
{
	Port_Init(&Config); 
	LCD_Init();
	LCD_WriteCommand(0x80);

	LCD_WriteString("Hello World");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteCommand(0xC0);
	LCD_WriteString("Great.");
	_delay_ms(1000);
	

	
	return 0;
}
