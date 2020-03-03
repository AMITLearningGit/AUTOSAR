/*
 * RTE_TemperatureRanging_Connection.h
 *
 * Created: 2/21/2020 1:33:50 PM
 *  Author: youse
 */ 


#ifndef RTE_TEMPERATURERANGING_CONNECTION_H_
#define RTE_TEMPERATURERANGING_CONNECTION_H_


#define Temperature_Reading_Ret unsigned short
#define Temperature_Reading_Passing unsigned short*
#define RTE_ReadT
#define Temp_Low 10
#define Temp_High 50

struct message {
	unsigned short temperature;
	unsigned char status;
	unsigned char state;
	unsigned char Buff[10];
};


struct message Temperature_Message_Def();

#define Pointer_Name Dummy_Ptr
Temperature_Reading_Ret (*Pointer_Name) (Temperature_Reading_Passing x);


#endif /* RTE_TEMPERATURERANGING_CONNECTION_H_ */