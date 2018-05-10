/*
 * input.h
 *
 *  Created on: Apr 8, 2018
 *      Author: benedikt
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <iostream>
#include <cmath>
#include "math.h"
int getint(std::string z){
	int_fast16_t x;
	std::cout<<z<<std::endl;
	std::cin>>x;
	return x;
}
float getfloat(std::string message){
	float x;
	std::cout<<message<<std::endl;
	std::cin>>x;
	return x;
}
std::string getstring(std::string message){
	std::cout<<message<<std::endl;
	std::string result;
	std::cin>>result;
	return result;
}
#endif /* INPUT_H_ */
