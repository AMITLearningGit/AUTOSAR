#include "utils.h"

/*
*delay in milli-seconds calculated for 8Mhz Oscillator
*/
void delay_ms(int n)
{
	int x,y;
	for(x=0;x<n;x++){
		for(y=0;y<3180;y++){}
		}
}
/*
*delay in micro-seconds calculated for 8Mhz Oscillator

*/
void delay_us(int n)
{
	int x,y;
	for(x=0;x<n;x++){
		for(y=0;y<3;y++){}
		}
}
