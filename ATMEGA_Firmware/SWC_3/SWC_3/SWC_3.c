/*
 * SWC_3.c
 *
 * Created: 2/22/2020 1:28:19 PM
 *  Author: youse
 */ 


//#include <avr/io.h>
#include "Port.h"
#include "Lcd.h"
#include "util/delay.h"
#include "Rte.h"

uint8 Func_Assign_Temp(uint8* Temp,uint8 *Buff);
int main(void)
{
	Port_Init();
	//LCD_Clear();
	_delay_ms(200);
	LCD_Init();
	RTE_GetFrame();
	unsigned char Buff[10];
	unsigned char Temp_Buff[4];

	//Temp_Buff[3]='X';
	RTE_ReadFrame(Buff);
	uint8 x=Func_Assign_Temp(Temp_Buff,Buff);
	//_delay_ms(200);
	uint8 indicator;
	if(x==3){
		indicator = 4;
	}
	else {
		indicator =5;
	}
	if(Buff[indicator+2] == '0'){
		DDRD |= (1<< 3);
		PORTD |= (1<<3);
	}
	
	

	
	while(1)
	{
		//TODO:: Please write your application code
	}
}

uint8 Func_Assign_Temp(uint8* Temp,uint8 *Buff){
	uint8 i=0;
	while(Buff[i]!=','){
		Temp[i]=Buff[i];
		i++;
	}
	Temp[i]='\0';
	return i;
}