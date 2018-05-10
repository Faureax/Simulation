/*
 * Zeug.h
 *
 *  Created on: Apr 14, 2018
 *      Author: benedikt
 */

#ifndef ZEUG_H_
#define ZEUG_H_
#include <iostream>
#include <cmath>
#include "input.h"
#include <string>
bool isEqual(int x, int y){
	return (static_cast<int>(x)==y);
}
void Equality(int_fast16_t x, int_fast16_t y){
	if (isEqual(x,y)){
			std::cout<<"Equal"<<std::endl;
		}
	else{
		if (x <y){
			std::cout<<"x is smaller than y";
		}
		else{
			std::cout<<"x is bigger than y";
			}
		}
}
int larger(int x, int y){
	if(x>y){
		return x;
	}
	else if(y>x){
		return y;
	}
	else{
		std::cout<<"Both values are the same, returning x"<<std::endl;
		return x;
	}
}
void Asciicode(char x){
	std::cout<<"Character\t"<<x<<" has Ascii code:\t"<<static_cast<int>(x)<<std::endl;
}
int switchexample(int_least32_t x){
    switch(x) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        default:
            return 0;
            break;
    }
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
	double diff = fabs(a - b);
	if (diff <= absEpsilon)
		return true;
	return diff <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}
int countstring(std::string str, std::string search){
    int strlenght(sizeof(str));
    int count(0);
    int searchlenght(sizeof(search));
    int step2(0);
    for(int step(0);step<strlenght;step++){
        step2=0;
        while (search[step2]==str[step]){
            count++;
            step2++;
        }
    }

    return count;
}

#endif /* ZEUG_H_ */
