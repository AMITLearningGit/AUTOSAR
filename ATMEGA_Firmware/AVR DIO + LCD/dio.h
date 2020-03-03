/*
 * DIO.h
 *
 * Created: 2/1/2020 11:46:06 AM
 *  Author: User
 */ 



#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "dio_types.h"

void Dio_WriteChannel(Dio_ChannelType channel, STD_levelType level);
void Dio_WritePort(Dio_PortType port, uint8 value);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
uint8 Dio_ReadPort(Dio_PortType port);


#endif /* DIO_H_ */