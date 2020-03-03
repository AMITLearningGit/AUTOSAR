/*
 * Rte.c
 *
 * Created: 2/22/2020 11:14:55 AM
 *  Author: User
 */ 

#include "Rte.h"

uint8 frame[FRAME_BYTES] = {1,2,3,4,5,6,7,8,9,10};				//for simulation


uint8 frameReceived[FRAME_BYTES] = {-1};
uint8 frameReceivedFlag = NOT_RECEIVED;


Std_returnType RTE_ReadFrame(uint8* frameBuffer)				//send frame to SWC (application)
{
	if (frameReceivedFlag == RECEIVED)							
	{
		int count = 0;
		for(count=0; count<FRAME_BYTES; count++)
		{
			*(frameBuffer+count) = frameReceived[count];
		}
		frameReceivedFlag = NOT_RECEIVED;
	}else															//frame still not received
		{
			return E_NOT_OK;
		}
	return E_OK;
	
}

Std_returnType RTE_GetFrame(void)					//get frame from comm stack (service)
{
	if (frameReceivedFlag == NOT_RECEIVED)						//last frame sent and waiting for other frame
	{
		int count = 0;
		for(count=0; count<FRAME_BYTES; count++)
		{
			frameReceived[count] = *(commstack_callbk()+count);
		}
		frameReceivedFlag = RECEIVED;
	}else															//last frame still not sent
		{
			return E_NOT_OK;
		}
	return E_OK;
}

uint8* commstack_callbk(void)
{
	return frame;				//for simulation
}