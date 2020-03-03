/*
 * Rte.c
 *
 * Created: 2/21/2020 01:39:45 PM
 *  Author: User
 */ 
#include "Rte.h"


uint8 frameBuffer[FRAME_BYTES] = {-1};
uint8 frameReceivedFlag = NOT_RECEIVED;
	
uint16 tempReceived;
uint8 tempReceivedFlag = NOT_RECEIVED;

Std_returnType RTE_GetTemp(uint16 temp)					//get temperature from the sensor in BSW
{
	tempReceived = BSW_ReadTempSensor();
	tempReceivedFlag = RECEIVED;
	return E_OK;
}

Std_returnType RTE_ReadTemp(uint16* temp)				//write temperature to SWC (application)
{
	if(tempReceivedFlag == RECEIVED)
	{
		*temp = tempReceived;
		tempReceivedFlag = NOT_RECEIVED;
	}else
		{
			return E_NOT_OK;
		}
	return E_OK;
}

Std_returnType RTE_SendFrame(uint8* frame)				//receive frame from application (temp+status+state)
{
	uint8 i = 0;
	for(i=0; i<FRAME_BYTES; i++)
	{
		frameBuffer[i] = *(frame+i);
	}
	frameReceivedFlag = RECEIVED;
	
	return E_OK;	
}

Std_returnType RTE_WriteFrame(SWC_TYPE swc, uint8* frame)			//send frame from RTE to other SWCs through CAN
{
	if (frameReceivedFlag == RECEIVED)
	{
		//callback function for CAN
		//comstack_callbk();
		frameReceivedFlag == NOT_RECEIVED;
	}else
		{
			return E_NOT_OK;
		}
	return E_OK;	
}

uint16 BSW_ReadTempSensor(void)									
{
	uint16 sensorTemp = 0;
	
	sensorTemp = max6675_Get_temp();
	
	return sensorTemp;	
}