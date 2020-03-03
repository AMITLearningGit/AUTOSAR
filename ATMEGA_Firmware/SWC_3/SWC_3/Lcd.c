/*
 * Lcd.c
 *
 * Created: 2/3/2020 03:37:16 PM
 *  Author: User
 */ 

#include "Lcd.h"
#include "Lcd_cfg.h"
#include "dio.h"

#include <util/delay.h>
void LCD_Init (void)
{
	Dio_WriteChannel(LCD_RW,STD_low);
	LCD_WriteCommand(0x28);		//4-bit mode, 5x7 dots
	//_delay_ms(2);
	LCD_WriteCommand(0x0C);		//display on, cursor off
	//_delay_ms(2);
	LCD_WriteCommand(0x06);		//increment cursor
	//_delay_ms(2);
	LCD_WriteCommand(0x01);		//clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x80);	    //cursor home position
	_delay_ms(200);
}

void LCD_WriteCommand(uint8 command)
{
	Dio_WritePort(Dio_Port_A,((LCD_PORT & 0x0F) | (command & 0xF0)));        //send high nibble of command
	Dio_WriteChannel(LCD_RS,STD_low);									     //RS = 0 (command register)
	//Dio_WriteChannel(LCD_RW,STD_low);									     //RW = 0 (write operation)
	pulse_EN_LCD();														     //high to low pulse
	
	Dio_WritePort(Dio_Port_A,((LCD_PORT & 0x0F) | (command << 4)));          //send low nibble of command
	Dio_WriteChannel(LCD_RS,STD_low);									     //RS = 0 (command register)
	//Dio_WriteChannel(LCD_RW,STD_low);									     //RW = 0 (write operation)
	pulse_EN_LCD();														     //high to low pulse
}

void LCD_WriteChar(uint8 character)
{
	Dio_WritePort(Dio_Port_A,((LCD_PORT & 0x0F) | (character & 0xF0)));      //send high nibble of command
	Dio_WriteChannel(LCD_RS,STD_high);									     //RS = 1 (data register)
	//Dio_WriteChannel(LCD_RW,STD_low);									     //RW = 0 (write operation)
	pulse_EN_LCD();														     //high to low pulse
	
	Dio_WritePort(Dio_Port_A,((LCD_PORT & 0x0F) | (character << 4)));        //send low nibble of command
	Dio_WriteChannel(LCD_RS,STD_high);									     //RS = 1 (data register)
	//Dio_WriteChannel(LCD_RW,STD_low);									     //RW = 0 (write operation)
	pulse_EN_LCD();														     //high to low pulse
}

void LCD_WriteString (char *str)
{
	while(*str)
	{
		LCD_WriteChar(*str++);
		//_delay_ms(1);
	}
}

void LCD_Clear()
{
	LCD_WriteCommand (0x01);		//clear screen
	LCD_WriteCommand (0x80);		//cursor home position
}


void LCD_String_xy (uint8 row, uint8 col, char* str)
{
	if(col < 16)
	{		
		if(row == 0)
		{
			LCD_WriteCommand(0x80 | (col & 0x0F));
			
		}else
		{
			LCD_WriteCommand(0xC0 | (col & 0x0F));
		
			}
			
	    LCD_WriteString(str);
		
	}		
}
void pulse_EN_LCD (void)
{
	Dio_WriteChannel(LCD_E,STD_high);
	_delay_us(10);
	Dio_WriteChannel(LCD_E,STD_low);
	_delay_ms(2);
}