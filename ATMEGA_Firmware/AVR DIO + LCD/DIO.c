/*
 * AUTOSAR.c
 *
 * Created: 2/1/2020 11:30:19 AM
 * Author : User
 */ 

#include <avr/io.h>

#include "dio.h"
#include "dio_hw.h"
#include "dio_types.h"
#include "STD_Types.h"
#include "bit_math.h"



void Dio_WriteChannel(Dio_ChannelType channel, STD_levelType level)
{
	Dio_PortType port = channel/8;
	Dio_ChannelType channelPosition = channel%8;
	
	switch(port)
	{
		case Dio_Port_A :
			if(level == STD_low)
			{
				CLR_BIT(PORTA,channelPosition);
			}else
			{
				SET_BIT(PORTA,channelPosition);
			}
			break;
			
		case Dio_Port_B :
			if(level == STD_low)
			{
				CLR_BIT(PORTB,channelPosition);
			}else
			{
				SET_BIT(PORTB,channelPosition);
			}
			break;
			
		case Dio_Port_C :
			if(level == STD_low)
			{
				CLR_BIT(PORTC,channelPosition);
			}else
			{
				SET_BIT(PORTC,channelPosition);
			}
			break;
			
		case Dio_Port_D :
			if(level == STD_low)
			{
				CLR_BIT(PORTD,channelPosition);
			}else
			{
				SET_BIT(PORTD,channelPosition);
			}
			break;			
	}
	 
	
}
void Dio_WritePort(Dio_PortType port, uint8 value)
{
	switch(port)
	{
		case Dio_Port_A :
			PORTA = value; break;
		
		case Dio_Port_B :
			PORTB = value; break;
		
		case Dio_Port_C :
			PORTC = value; break;
		
		case Dio_Port_D :
			PORTD = value; break;
	}
}
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType channelState = STD_low;
	
	Dio_PortType port = ChannelId/8;
	Dio_ChannelType channelPosition = ChannelId%8;
	
	switch(port)
	{
		case Dio_Port_A :	
			channelState = GET_BIT(PINA,channelPosition); break;
			
		case Dio_Port_B :
			channelState = GET_BIT(PINB,channelPosition); break;
		
		case Dio_Port_C :
			channelState = GET_BIT(PINC,channelPosition); break;
		
		case Dio_Port_D :
			channelState = GET_BIT(PIND,channelPosition); break;
	}
	
	return channelState;
}
Dio_PortLevelType Dio_ReadPort(Dio_PortType port)
{
	Dio_PortLevelType portState = 0;
	
	switch(port)
	{
		case Dio_Port_A :
			portState = PORTA; break;
		
		case Dio_Port_B :
			portState = PORTB; break;
		
		case Dio_Port_C :
			portState = PORTC; break;
		
		case Dio_Port_D :
			portState = PORTD; break;
	}
	
	return portState;
	
}


