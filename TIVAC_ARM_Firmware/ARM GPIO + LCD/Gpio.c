

#include "Gpio.h"
#include "TM4C123GH6PM.h"
#include "Gpio_Types.h"
#include "STD_Types.h"
#include "Bit_Math.h"


void GPIO_WriteChannel(GPIO_ChannelType channel, STD_levelType level)
{
	GPIO_PortType currentPort;
	GPIO_ChannelType currentChannel;
	
	if(channel <= 31)											//get port and pin
	{
		 currentPort = channel/8;
		 currentChannel = channel%8;
	}else if (channel <= 37)
		{
			currentPort = GPIO_Port_E;
			currentChannel = channel - 32;
		}else
			{
				currentPort = GPIO_Port_F;
				currentChannel = channel - 38;	
			}
			
		GPIOA_Type* GPIO;
		config_GPIO_port(&GPIO,currentPort); 								//configure GPIO according to current port

		if (level == STD_high)
		{
			SET_BIT(GPIO -> DATA,currentChannel);
		}else
			{
				CLR_BIT(GPIO -> DATA,currentChannel);	
			}
			
		GPIO = (GPIOA_Type*)0;

}
GPIO_LevelType GPIO_ReadChannel(GPIO_ChannelType ChannelId)
{
	GPIO_PortType currentPort;
	GPIO_ChannelType currentChannel;
	GPIO_LevelType channelValue = 0;
	
	if(ChannelId <= 31)											//get port and pin
	{
		 currentPort = ChannelId/8;
		 currentChannel = ChannelId%8;
	}else if (ChannelId <= 37)
		{
			currentPort = GPIO_Port_E;
			currentChannel = ChannelId - 32;
		}else
			{
				currentPort = GPIO_Port_F;
				currentChannel = ChannelId - 38;	
			}
			
		GPIOA_Type* GPIO;
		config_GPIO_port(&GPIO,currentPort); 								//configure GPIO according to current port

		channelValue = GET_BIT(GPIO -> DATA,currentChannel);
			
		GPIO = (GPIOA_Type*)0;
			
		return channelValue;
			
}

void GPIO_WritePort(GPIO_PortType port, uint8 value)
{
		GPIOA_Type* GPIO;
		config_GPIO_port(&GPIO,port); 								//configure GPIO according to current port
			
			GPIO -> DATA = (GPIO_PortLevelType) value;
			GPIO = (GPIOA_Type*)0;
}


GPIO_PortLevelType GPIO_ReadPort(GPIO_PortType port)
{
	GPIO_PortLevelType portBuffer = 0;
	GPIOA_Type* GPIO;
	config_GPIO_port(&GPIO,port); 								//configure GPIO according to current port
	
	portBuffer = GPIO -> DATA;
	GPIO = (GPIOA_Type*)0;
	
	return portBuffer;
}
void config_GPIO_port(GPIOA_Type** GPIO, GPIO_PortType port)
{
		switch(port)
			{
				case GPIO_Port_A :
					*GPIO = GPIOA;
					break;
				
				case GPIO_Port_B :
					*GPIO = GPIOB;
					break;
				
				case GPIO_Port_C :
					*GPIO = GPIOC;
					break;
				
				case GPIO_Port_D :
					*GPIO = GPIOD;
					break;
				
				case GPIO_Port_E :
					*GPIO = GPIOE;
					break;
				
				default :
					*GPIO = GPIOF;
					break;
			}
}



