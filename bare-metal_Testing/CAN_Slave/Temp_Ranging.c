/*
 * Temp_Ranging.c
 *
 * Created: 2/21/2020 1:30:21 PM
 *  Author: youse
 */ 

#include <avr/io.h>
#include "Rte.h"
#include "RTE_TemperatureRanging_Connection.h"

struct message Temperature_Message_Def(){
	struct message Temperature_Message;
	RTE_ReadTemp(&Temperature_Message.temperature);
	unsigned short x;
	if(Temperature_Message.temperature >=Temp_High){
		Temperature_Message.status='H';
		Temperature_Message.state = 1;
		 
	}
	else if(Temperature_Message.temperature  < Temp_Low ){
		Temperature_Message.status='C';
		Temperature_Message.state = 0;
		RTE_ReadTemp(&Temperature_Message.temperature);
	}
	else if(Temperature_Message.temperature >Temp_Low && Temperature_Message.temperature  <  Temp_High){
		Temperature_Message.status='M';
		Temperature_Message.state = 0;
		RTE_ReadTemp(&Temperature_Message.temperature);
		}
		sprintf(Temperature_Message.Buff,"%s,%c,%c",Temperature_Message.temperature,Temperature_Message.status,Temperature_Message.state);
		
		return Temperature_Message;
}