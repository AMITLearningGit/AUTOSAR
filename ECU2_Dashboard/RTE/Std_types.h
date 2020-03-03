/*
 * Std_types.h
 *
 * Created: 2/22/2020 11:21:57 AM
 *  Author: User
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long long uint32;

typedef  char sint8;
typedef  int sint16;
typedef  long long sint32;


typedef enum
{
	STD_low = 0,
	STD_high = 1
}Std_levelType;

typedef enum
{
	E_NOT_OK = 0,
	E_OK
}Std_returnType;



#endif /* STD_TYPES_H_ */