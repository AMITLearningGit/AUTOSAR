/*
 * CAN bus LED controller slave firmware
 * Written for TI Tiva TM4C123GH6PM
 */
#include <TM4C123GH6PM.h>
#include "CAN.h"
volatile bool rxFlag = 0; // msg recieved flag
volatile bool errFlag = 0; // error flag

/*

*/

int main(void) {

	tCANMsgObject msg; // the CAN msg object
	unsigned char msgData[8]; // 8 byte buffer for rx message data

	// Run from crystal at 50Mhz
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	// Set up debugging UART
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTStdioConfig(0, 115200, SysCtlClockGet());

	CAN_Init();

	// Set up LED driver
	  RGBInit(1);

	// Use ID and mask 0 to recieved messages with any CAN ID
	msg.ui32MsgID = 0;
	msg.ui32MsgIDMask = 0;
	msg.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
	msg.ui32MsgLen = 8; // allow up to 8 bytes

	// Load msg into CAN peripheral message object 1 so it can trigger interrupts on any matched rx messages
	CANMessageSet(CAN0_BASE, 1, &msg, MSG_OBJ_TYPE_RX);

	unsigned int colour[3];
	float intensity;
	

	while(1) {

		if(rxFlag) { // rx interrupt has occured

			msg.pui8MsgData = msgData; // set pointer to rx buffer
			CANMessageGet(CAN0_BASE, 1, &msg, 0); // read CAN message object 1 from CAN peripheral

			rxFlag = 0; // clear rx flag

			if(msg.ui32Flags & MSG_OBJ_DATA_LOST) { // check msg flags for any lost messages 
				UARTprintf("CAN message loss detected\n");
			}

			// read in colour data from rx buffer (scale from 0-255 to 0-0xFFFF for LED driver)
			colour[0] = msgData[0]; //* 0xFF;
			colour[1] = msgData[1]; //* 0xFF;
			colour[2] = msgData[2]; //* 0xFF;
			intensity = msgData[3]; /// 255.0f; // scale from 0-255 to float 0-1
			if(colour[0]=='m'){
				GPIOF->DIR=0xFF;
				GPIOF->DATA=0xFF;
							RGBSet(colour, intensity);

			}
			else{
			/*Do Nothing*/
			}
			if(colour[1]=='r'){
				GPIOF->DIR=0xFF;
				GPIOF->DATA=0xFF;
			}
			else{
			/*Do Nothing*/
			}
			if(colour[2]=='b'){
				GPIOF->DIR=0xFF;
				GPIOF->DATA=0xFF;
			}
			else{
			/*Do Nothing*/
			}
			if(intensity=='g'){
				GPIOF->DIR=0xFF;
				GPIOF->DATA=0xFF;
			}
			else{
			/*Do Nothing*/
			}
			// write to UART for debugging
			UARTprintf("Received colour\tr: %d\tg: %d\tb: %d\ti: %d\n", msgData[0], msgData[1], msgData[2], msgData[3]);

			// set colour and intensity
			
		}
	}

	return 0;
}
