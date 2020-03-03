


#ifndef PORT_H
#define PORT_H

#include "GPIO_Types.h"

void Port_Init (GPIO_PortType port);

typedef struct
{
	GPIO_DirType pinDirection;
	GPIO_LevelType pinLevel;
}Port_ConfigType;

extern const Port_ConfigType ConfigPtr[];




#endif

