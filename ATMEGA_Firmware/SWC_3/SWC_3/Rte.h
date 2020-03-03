/*
 * Rte.h
 *
 * Created: 2/22/2020 11:15:06 AM
 *  Author: User
 */ 


#ifndef RTE_H_
#define RTE_H_

#include "STD_types.h"

#define FRAME_BYTES			10

#define RECEIVED			1
#define NOT_RECEIVED		0

STD_returnType RTE_ReadFrame(uint8* frameBuffer);			//send frame to SWC (application)

STD_returnType RTE_GetFrame(void);							//get frame from comm stack (service)

uint8* BSW_GetFrame(void);



#endif /* RTE_H_ */