/*
 * Port.h
 *
 * Created: 2/1/2020 01:41:08 PM
 *  Author: User
 */ 


#ifndef PORT_H_
#define PORT_H_

#include "dio_types.h"

void Port_Init (void);
typedef struct
{
	Dio_DirType pinDirection;
	Dio_LevelType pinLevel;
}Port_ConfigType;

extern const Port_ConfigType ConfigPtr[];

#endif /* PORT_H_ */