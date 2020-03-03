/*
 * port_Lcfg.c
 *
 * Created: 2/1/2020 01:50:43 PM
 *  Author: User
 */ 
#include "Port.h"
#include "dio_hw.h"
#include "bit_math.h"

const Port_ConfigType ConfigPtr[] = {
/*PA0*/		{Output,STD_low},
/*PA1*/		{Output,STD_low},
/*PA2*/		{Output,STD_low},
/*PA3*/		{Output,STD_low},
/*PA4*/		{Output,STD_low},
/*PA5*/		{Output,STD_low},
/*PA6*/	   	{Output,STD_low},
/*PA7*/		{Output,STD_low},
	
/*PB0*/		{Output,STD_low},
/*PB1*/		{Output,STD_low},
/*PB2*/		{Output,STD_low},
/*PB3*/		{Output,STD_low},
/*PB4*/		{Output,STD_low},
/*PB5*/		{Output,STD_low},
/*PB6*/		{Output,STD_low},
/*PB7*/		{Output,STD_low},
	
/*PC0*/		{Output,STD_low},
/*PC1*/		{Output,STD_low},
/*PC2*/		{Output,STD_low},
/*PC3*/		{Output,STD_low},
/*PC4*/		{Output,STD_low},
/*PC5*/		{Output,STD_low},
/*PC6*/		{Output,STD_low},
/*PC7*/		{Output,STD_low},
	
/*PD0*/		{Output,STD_low},
/*PD1*/		{Output,STD_low},
/*PD2*/		{Output,STD_low},
/*PD3*/		{Output,STD_low},
/*PD4*/		{Output,STD_low},
/*PD5*/		{Output,STD_low},
/*PD6*/		{Output,STD_low},
/*PD7*/		{Output,STD_low},
};

void Port_Init ()
{
	Dio_ChannelType currentChannel = 0;
	uint8 currentPin = 0;
	Dio_PortType currentPort = 0;
	
	for(currentChannel = Dio_Channel_A0; currentChannel < PINCOUNT; currentChannel++)
	{
		currentPort = currentChannel/8;
		currentPin = currentChannel%8;
		
		if (ConfigPtr[currentChannel].pinDirection == Output)
		{
			switch(currentPort)
			{
				case Dio_Port_A : 
					SET_BIT(DDRA,currentPin); break;
				
				case Dio_Port_B :
					SET_BIT(DDRB,currentPin); break;
				
				case Dio_Port_C :
					SET_BIT(DDRC,currentPin); break;
				
				case Dio_Port_D :
					SET_BIT(DDRD,currentPin); break;
			}
		}else
		{
			switch(currentPort)
			{
				case Dio_Port_A :
					CLR_BIT(DDRA,currentPin); break;
				
				case Dio_Port_B :
					CLR_BIT(DDRB,currentPin); break;
				
				case Dio_Port_C :
					CLR_BIT(DDRC,currentPin); break;
				
				case Dio_Port_D :
					CLR_BIT(DDRD,currentPin); break;
			}
		}
	}
}
