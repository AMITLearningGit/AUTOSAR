
#include "TM4C123GH6PM.h"
#include "Kit_Connections.h"
#include "Port.h"
#include "STD_Types.h"
#include "Bit_Math.h"
#include "Gpio_Types.h"
#include "Gpio.h"
#include "Kit_Connections.h"
#include "Lcd.h"
#include "Utils.h"

//default clock is 8MHZ
int main(void)
{
	/*
	Port_Init(GPIO_Port_F);

	while(1)
	{
		
		while(GPIO_ReadChannel(BUTTON1) == STD_low)
			{
				GPIO_WriteChannel(GREEN_LED,STD_low);
				GPIO_WriteChannel(BLUE_LED,STD_high);
			}
			GPIO_WriteChannel(BLUE_LED,STD_low);
			GPIO_WriteChannel(GREEN_LED,STD_high);
	}*/

	Port_Init(GPIO_Port_B);

	LCD_Init();
	
	LCD_WriteChar('H');
	LCD_WriteChar('e');
	LCD_WriteString("llo World");
	delay_ms(1000);
	LCD_Clear();
	LCD_WriteCommand(0x80);
	LCD_WriteString("LCD cleared");
	delay_ms(1000);
	
	LCD_String_xy(0,5,"TEST!");
	LCD_String_xy(1,13,"HERE!");

	return 0;
}


