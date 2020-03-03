/*
 * bit_math.h
 *
 * Created: 2/1/2020 11:53:08 AM
 *  Author: User
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)	REG |= (1 << BIT)
#define CLR_BIT(REG,BIT)	REG &= ~(1 << BIT)
#define GET_BIT(REG,BIT)	((REG >> BIT) & 1)
#define TOGGLE_BIT(REG,BIT) REG ^= (1 << BIT)
#define MASK(BIT)           BIT&1



#endif /* BIT_MATH_H_ */