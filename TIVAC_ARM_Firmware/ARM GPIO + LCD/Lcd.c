#include "Lcd.h"
#include "Lcd_cfg.h"
#include "Gpio.h"
#include "Utils.h"

void LCD_Init (void)
{
	GPIO_WriteChannel(LCD_RW,STD_low);
	delay_ms(20);
	
	LCD_WriteCommand(0x28);			//4-bit mode, 5x7 dots
	LCD_WriteCommand(0x0C);			//display on, cursor off
	LCD_WriteCommand(0x06);			//increment cursor
	LCD_WriteCommand(0x01);			//clear screen
	delay_ms(2);
	LCD_WriteCommand(0x80);	  	//cursor home position
	
}

void LCD_WriteCommand(uint8 command)
{
	GPIO_WritePort(GPIO_Port_B,((LCD_PORT & 0x0F) | (command & 0xF0)));        //send high nibble of command
	GPIO_WriteChannel(LCD_RS,STD_low);									     									 //RS = 0 (command register)
	GPIO_WriteChannel(LCD_RW,STD_low);									     									 //RW = 0 (write operation)
	pulse_EN_LCD();														     														 //high to low pulse
	
	GPIO_WritePort(GPIO_Port_B,((LCD_PORT & 0x0F) | (command << 4)));          //send low nibble of command
	GPIO_WriteChannel(LCD_RS,STD_low);									     									 //RS = 0 (command register)
	GPIO_WriteChannel(LCD_RW,STD_low);									     									 //RW = 0 (write operation)
	pulse_EN_LCD();														     														 //high to low pulse
}

void LCD_WriteChar(uint8 character)
{
	GPIO_WritePort(GPIO_Port_B,((LCD_PORT & 0x0F) | (character & 0xF0)));      //send high nibble of command
	GPIO_WriteChannel(LCD_RS,STD_high);									     									 //RS = 1 (data register)
	GPIO_WriteChannel(LCD_RW,STD_low);									     									 //RW = 0 (write operation)
	pulse_EN_LCD();														     														 //high to low pulse
	
	GPIO_WritePort(GPIO_Port_B,((LCD_PORT & 0x0F) | (character << 4)));        //send low nibble of command
	GPIO_WriteChannel(LCD_RS,STD_high);									     									 //RS = 1 (data register)
	GPIO_WriteChannel(LCD_RW,STD_low);									     									 //RW = 0 (write operation)
	pulse_EN_LCD();														     														 //high to low pulse
}

void LCD_WriteString (char *str)
{
	while(*str)
	{
		LCD_WriteChar(*str++);
	}
}

void LCD_Clear()
{
	LCD_WriteCommand (0x01);		//clear screen
	delay_ms(2);
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
	GPIO_WriteChannel(LCD_E,STD_high);
	delay_us(10);
	GPIO_WriteChannel(LCD_E,STD_low);
	delay_ms(2);
}
