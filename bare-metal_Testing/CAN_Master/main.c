/*
 * CAN bus LED controller master firmware
 * Written for TI Tiva TM4C123GH6PM
 */

#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/adc.h"
#include "utils/uartstdio.h"

#define PI 3.14159265359f

volatile bool errFlag = 0; // transmission error flag
unsigned int sysClock; // clockspeed in hz

void delay(unsigned int milliseconds) {
	//SysCtlDelay((sysClock / 3) * (milliseconds / 1000.0f));
	for(int i=0;i<500000;i++);
}

// CAN interrupt handler
void CANIntHandler(void) {

	unsigned long status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE); // read interrupt status

	if(status == CAN_INT_INTID_STATUS) { // controller status interrupt
		status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL); // read back error bits, do something with them?
		errFlag = 1;
	} else if(status == 1) { // message object 1
		CANIntClear(CAN0_BASE, 1); // clear interrupt
		errFlag = 0; // clear any error flags
	} else { // should never happen
		UARTprintf("Unexpected CAN bus interrupt\n");
	}
}

int main(void) {

	tCANMsgObject msg; // the CAN message object
	unsigned int msgData; // the message data is four bytes long which we can allocate as an int32
	unsigned char *msgDataPtr = (unsigned char *)&msgData; // make a pointer to msgData so we can access individual bytes

	// Run from crystal at 16Mhz
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	// Set up debugging UART
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTStdioConfig(0, 115200, SysCtlClockGet());

	// Set up CAN0
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinConfigure(GPIO_PE4_CAN0RX);
	GPIOPinConfigure(GPIO_PE5_CAN0TX);
	GPIOPinTypeCAN(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
	
	CANInit(CAN0_BASE);
	CANBitRateSet(CAN0_BASE,SysCtlClockGet(), 500000);
	CANIntRegister(CAN0_BASE, CANIntHandler); // use dynamic vector table allocation
	CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
	IntEnable(INT_CAN0_TM4C123);
	CANEnable(CAN0_BASE);
		  //ADC
			uint32_t TempValueC ;
	    uint32_t TempValueF ;
	    uint32_t ADCValues[1];
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	    SysCtlDelay(3);
	    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
			ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_TS | ADC_CTL_IE | ADC_CTL_END);
	    ADCSequenceEnable(ADC0_BASE, 3);
			ADCIntClear(ADC0_BASE, 3);
			
			
			
	// Set up msg object
	msgData = 'M';
	msg.ui32MsgID = 1;
	msg.ui32MsgIDMask = 0;
	msg.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
	msg.ui32MsgLen = sizeof(msgDataPtr);
	msg.pui8MsgData = msgDataPtr;

	unsigned int t = 0; // loop counter
	float freq = 0.3; // frequency scaler

	while(1) {
		
					ADCProcessorTrigger(ADC0_BASE, 3);
	        // Wait for conversion to be completed.
	        while(!ADCIntStatus(ADC0_BASE, 3, false))
	        {}
	        // Clear the ADC interrupt flag.
	        ADCIntClear(ADC0_BASE, 3);
	        // Read ADC Value.
	        ADCSequenceDataGet(ADC0_BASE, 3, ADCValues);
	        // Use non-calibrated conversion provided in the data sheet. I use floats in intermediate
	        // math but you could use intergers with multiplied by powers of 10 and divide on the end
	        // Make sure you divide last to avoid dropout.
	        TempValueC = (uint32_t)(147.5 - ((75.0*3.3 *(float)ADCValues[0])) / 4096.0);
	        // Get Fahrenheit value.  Make sure you divide last to avoid dropout.
	        TempValueF = ((TempValueC * 9) + 160) / 5;
	        // Display the temperature value on the console.
	        UARTprintf("Temperature = %3d*C or %3d*F\r\n", TempValueC,TempValueF);
		
		
		msgDataPtr[0] = (unsigned char)'M';
		msgDataPtr[1] = 0;
		msgDataPtr[2] = 0;
		msgDataPtr[3] = 0; // 50% intensity
		/*
		// set up next colour (scale sinf (0-1) to 0-255)
		msgDataPtr[0] = (0.5 + 0.5*sinf(t*freq)) * 0xFF;
		msgDataPtr[1] = (0.5 + 0.5*sinf(t*freq + (2*PI/3))) * 0xFF; // 120 degrees out of phase
		msgDataPtr[2] = (0.5 + 0.5*sinf(t*freq + (4*PI/3))) * 0xFF; // 240 degrees out of phase
		msgDataPtr[3] = 128; // 50% intensity
		*/
		UARTprintf("Sending colour\tr: %d\tg: %d\tb: %d\n", msgDataPtr[0], msgDataPtr[1], msgDataPtr[2]); // write colour to UART for debugging
		CANMessageSet(CAN0_BASE, 1, &msg, MSG_OBJ_TYPE_TX); // send as msg object 1

		 delay(100); // wait 100ms

		if(errFlag) { // check for errors
			UARTprintf("CAN Bus Error\n");
		}

		t++; // overflow is fine
	}

	return 0;
}

