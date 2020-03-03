#include "CAN.h"


extern volatile bool errFlag;
extern volatile bool rxFlag;
void CANIntHandler(void) {

	unsigned long status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE); // read interrupt status
	if(status == CAN_INT_INTID_STATUS) { // controller status interrupt
		status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);
		errFlag = 1;
	} else if(status == 1) { // msg object 1
		CANIntClear(CAN0_BASE, 1); // clear interrupt
		rxFlag = 1; // set rx flag
		errFlag = 0; // clear any error flags
	} else { // should never happen
		UARTprintf("Unexpected CAN bus interrupt\n");
	}
}
void CAN_Init(){
	// Set up CAN0
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinConfigure(GPIO_PE4_CAN0RX);
	GPIOPinConfigure(GPIO_PE5_CAN0TX);
	GPIOPinTypeCAN(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
	CANInit(CAN0_BASE);
	CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
	CANIntRegister(CAN0_BASE, CANIntHandler); // use dynamic vector table allocation
	CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
	IntEnable(INT_CAN0_TM4C123);
	CANEnable(CAN0_BASE);
}

