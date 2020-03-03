


#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include "STD_Types.h"

typedef uint32 GPIO_PortLevelType;
typedef STD_levelType GPIO_LevelType;

typedef enum
{
	GPIO_Channel_A0,
	GPIO_Channel_A1,
	GPIO_Channel_A2,
	GPIO_Channel_A3,
	GPIO_Channel_A4,
	GPIO_Channel_A5,
	GPIO_Channel_A6,
	GPIO_Channel_A7,

	GPIO_Channel_B0,
	GPIO_Channel_B1,
	GPIO_Channel_B2,
	GPIO_Channel_B3,
	GPIO_Channel_B4,
	GPIO_Channel_B5,
	GPIO_Channel_B6,
	GPIO_Channel_B7,

	GPIO_Channel_C0,
	GPIO_Channel_C1,
	GPIO_Channel_C2,
	GPIO_Channel_C3,
	GPIO_Channel_C4,
	GPIO_Channel_C5,
	GPIO_Channel_C6,
	GPIO_Channel_C7,

	GPIO_Channel_D0,
	GPIO_Channel_D1,
	GPIO_Channel_D2,
	GPIO_Channel_D3,
	GPIO_Channel_D4,
	GPIO_Channel_D5,
	GPIO_Channel_D6,
	GPIO_Channel_D7,
	
	GPIO_Channel_E0,
	GPIO_Channel_E1,
	GPIO_Channel_E2,
	GPIO_Channel_E3,
	GPIO_Channel_E4,
	GPIO_Channel_E5,
	
	GPIO_Channel_F0,
	GPIO_Channel_F1,
	GPIO_Channel_F2,
	GPIO_Channel_F3,
	GPIO_Channel_F4
	
}GPIO_ChannelType;


typedef enum
{
	GPIO_Port_A,
	GPIO_Port_B,
	GPIO_Port_C,
	GPIO_Port_D,
	GPIO_Port_E,
	GPIO_Port_F
}GPIO_PortType;

typedef enum
{
	Input = 0,
	Output
}GPIO_DirType;


#endif

