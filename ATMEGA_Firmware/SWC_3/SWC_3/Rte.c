/*
 * Rte.c
 *
 * Created: 2/22/2020 11:14:55 AM
 *  Author: User
 */ 
#include "STD_Types.h"
#include "Port.h"
#include "Rte.h"
uint8 frame[FRAME_BYTES] ;
uint16 temp=1000;
//uint8 frame[FRAME_BYTES] = {1,2,3,4,5,6,7,8,9,10};				//for simulation


uint8 frameReceived[FRAME_BYTES] = {-1};
uint8 frameReceivedFlag = NOT_RECEIVED;


STD_returnType RTE_ReadFrame(uint8* frameBuffer)				//send frame to SWC (application)
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

STD_returnType RTE_GetFrame(void)					//get frame from comm stack (service)
{
	if (frameReceivedFlag == NOT_RECEIVED)						//last frame sent and waiting for other frame
	{
		int count = 0;
		for(count=0; count<FRAME_BYTES; count++)
		{
			frameReceived[count] = *(BSW_GetFrame()+count);
		}
		frameReceivedFlag = RECEIVED;
	}else															//last frame still not sent
		{
			return E_NOT_OK;
		}
	return E_OK;
}

uint8* BSW_GetFrame(void)
{
	//commstack_callbk();
	sprintf(frame,"%d,%c,%c",temp,'M','1');
	return frame;				//for simulation
}