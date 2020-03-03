#include "CAN.h"




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


void CAN0_Init(){
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
			
}