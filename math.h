/*
 * math.h
 *
 *  Created on: Apr 7, 2018
 *      Author: benedikt
 */

#ifndef MATH_H_
#define MATH_H_
#include <iostream>
int add(int x, int y){
	std::cout<<x+y<<std::endl;
	return x+y;
}
int divide(int x, int y){
	std::cout<<x/y<<std::endl;
	return x/y;
}
int multiply(int x, int y){
	std::cout<<x*y<<std::endl;
	return x*y;
}
int substract(int x, int y){
	std::cout<<x-y<<std::endl;
	return x-y;
}
int pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

#endif /* MATH_H_ */
