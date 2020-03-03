/*
 * Display_Temp.c
 *
 * Created: 2/22/2020 11:12:47 AM
 *  Author: youse
 */ 


#include "Lcd.h"
#include "util/delay.h"
void LCD_Display(unsigned char *temp,unsigned char status){
	LCD_Clear();
	
	
	
	
	if(status == 'H'){
		_delay_ms(10);
		//LCD_WriteCommand(0x80);
		
		LCD_String_xy(0,0,"HOT_Temp Fan:ON");
		LCD_String_xy(1,0,temp);
		_delay_ms(10);
	}		
		else if(status == 'M'){
	
		LCD_WriteCommand(0x80);
		LCD_String_xy(0,0,"Med Temp Fan:Rdy");
		LCD_String_xy(1,0,temp);
		_delay_ms(10);
		}		
		else if(status == 'C'){
		
		LCD_WriteCommand(0x80);
		LCD_String_xy(0,0,"Low Temp Fan:OFF");
		LCD_String_xy(1,0,temp);
		_delay_ms(10);
		}	
		_delay_ms(10);
		
	}