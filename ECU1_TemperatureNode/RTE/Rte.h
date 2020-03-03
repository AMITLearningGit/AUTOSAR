/*
 * Rte.h
 *
 * Created: 2/21/2020 01:39:32 PM
 *  Author: User
 */ 


#ifndef RTE_H_
#define RTE_H_

#include "Std_Types.h"
#include "SWC_Types.h"

#define RECEIVED		1
#define NOT_RECEIVED	0

#define FRAME_BYTES		10

Std_returnType RTE_GetTemp(uint16 temp);						//read temperature from BSW
Std_returnType RTE_ReadTemp(uint16* temp);						//write temperature to SWC (application)

Std_returnType RTE_SendFrame(uint8* frame);						//receive frame from application (temp+status+state)
Std_returnType RTE_WriteFrame(SWC_TYPE swc, uint8* frame);		//send frame from RTE to other SWCs through CAN


uint16 BSW_ReadTempSensor(void);								//get the temperature from the sensor in BSW

//------------------------------------

uint16 max6675_Get_temp(void);									//function should be implemented in max6675.c


#endif /* RTE_H_ */