

#include "Port.h"
#include "TM4C123GH6PM.h"
#include "Bit_Math.h"

#define PINCOUNT 43

const Port_ConfigType ConfigPtr[] = {
/*PA0*/		{Output,STD_low},
/*PA1*/		{Output,STD_low},
/*PA2*/		{Output,STD_low},
/*PA3*/		{Output,STD_low},
/*PA4*/		{Output,STD_low},
/*PA5*/		{Output,STD_low},
/*PA6*/	  {Output,STD_low},
/*PA7*/		{Output,STD_low},
	
/*PB0*/		{Output,STD_low},
/*PB1*/		{Output,STD_low},
/*PB2*/		{Output,STD_low},
/*PB3*/		{Output,STD_low},
/*PB4*/		{Output,STD_low},
/*PB5*/		{Output,STD_low},
/*PB6*/		{Output,STD_low},
/*PB7*/		{Output,STD_low},
	
/*PC0*/		{Output,STD_low},
/*PC1*/		{Output,STD_low},
/*PC2*/		{Output,STD_low},
/*PC3*/		{Output,STD_low},
/*PC4*/		{Output,STD_low},
/*PC5*/		{Output,STD_low},
/*PC6*/		{Output,STD_low},
/*PC7*/		{Output,STD_low},
	
/*PD0*/		{Output,STD_low},
/*PD1*/		{Output,STD_low},
/*PD2*/		{Output,STD_low},
/*PD3*/		{Output,STD_low},
/*PD4*/		{Output,STD_low},
/*PD5*/		{Output,STD_low},
/*PD6*/		{Output,STD_low},
/*PD7*/		{Output,STD_low},

/*PE0*/		{Output,STD_low},
/*PE1*/		{Output,STD_low},
/*PE2*/		{Output,STD_low},
/*PE3*/		{Output,STD_low},
/*PE4*/		{Output,STD_low},
/*PE5*/		{Output,STD_low},

/*PF0*/		{Input,STD_low},
/*PF1*/		{Output,STD_low},
/*PF2*/		{Output,STD_low},
/*PF3*/		{Output,STD_low},
/*PF4*/		{Input,STD_low}
};


void Port_Init(GPIO_PortType port)
{
	uint8 pinCounter = 0;
	uint8 portCount = 0;
	uint8 offset = 0;
	uint8 currentPin = 0;
	
	volatile unsigned long delay;

	GPIOA_Type* GPIO;
	switch(port)
	{
		case GPIO_Port_A :
			GPIO = GPIOA;
			SYSCTL -> RCGC2 |= 0x01;   					//32-bit register (4 bytes) //every port has 1 bit in first (LSB) byte (00FE DCBA) //enable clock
			delay = SYSCTL -> RCGC2;    	 			//dummy cycle to wait for initialization
			portCount = 8;
			offset = 0;
			break;
		
		case GPIO_Port_B :
			GPIO = GPIOB;
			SYSCTL -> RCGC2 |= 0x02;
			delay = SYSCTL -> RCGC2;    	 						//dummy cycle to wait for initialization
			portCount = 8;
			offset = 8;
			break;
		
		case GPIO_Port_C :
			GPIO = GPIOC;
			SYSCTL -> RCGC2 |= 0x04;
			delay = SYSCTL -> RCGC2;    	 						//dummy cycle to wait for initialization
			portCount = 8;
			offset = 16;
			break;
		
		case GPIO_Port_D :
			GPIO = GPIOD;
			SYSCTL -> RCGC2 |= 0x08;
			delay = SYSCTL -> RCGC2;    	 						//dummy cycle to wait for initialization
			portCount = 8;
			offset = 24;
			break;
		
		case GPIO_Port_E :
			GPIO = GPIOE;
			SYSCTL -> RCGC2 |= 0x10;
			delay = SYSCTL -> RCGC2;    	 						//dummy cycle to wait for initialization
			portCount = 6;
			offset = 32;
			break;
		
		default :
			GPIO = GPIOF;
			SYSCTL -> RCGC2 |= 0x20;
			delay = SYSCTL -> RCGC2;    	 						//dummy cycle to wait for initialization
			portCount = 5;
			offset = 38;
			break;
	}
	
	 GPIO -> LOCK = 0x4C4F434B;							  //unlock GPIO Port 
	 GPIO -> CR = 0xFF;												//allow changes to whole port
	 GPIO -> AMSEL = 0x00;										//disable analog on Port
	 GPIO -> AFSEL = 0x00;										//disable alt funct
 	 GPIO -> PCTL = 0x00;											//0 for GPIO functionality
	
	
	for (currentPin=offset; currentPin < (portCount+offset); currentPin++)	//set pin directions according to configuration
	{
		if (ConfigPtr[currentPin].pinDirection == Output)
		{
			SET_BIT(GPIO -> DIR,pinCounter);
			pinCounter++;
		}else
			{
				CLR_BIT(GPIO -> DIR,pinCounter);
				pinCounter++;
			}
	
	}

	if(port == GPIO_Port_F)
	{
		GPIO -> PUR = 0x11;
	}else
		{
			GPIO -> PUR = 0x00;
		}
		
	GPIO -> DEN = 0xFF;										//enable digital I/O to whole port
}


