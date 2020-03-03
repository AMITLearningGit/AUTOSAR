



#ifndef GPIO_H
#define GPIO_H

#include "STD_Types.h"
#include "GPIO_Types.h"
#include "TM4C123GH6PM.h"

void GPIO_WriteChannel(GPIO_ChannelType channel, STD_levelType level);
void GPIO_WritePort(GPIO_PortType port, uint8 value);
GPIO_LevelType GPIO_ReadChannel(GPIO_ChannelType ChannelId);
GPIO_PortLevelType GPIO_ReadPort(GPIO_PortType port);

void config_GPIO_port(GPIOA_Type** GPIO, GPIO_PortType port);		//configure GPIO according to current port

#endif

