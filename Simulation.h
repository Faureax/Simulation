//
// Created by benedikt on 04.05.18.
//

#ifndef SIMULATIONSRC_SIMULATION_H
#define SIMULATIONSRC_SIMULATION_H
#include <iostream>
#include "Zeug.h"
#include "input.h"
void simulate(float Chance1, float Chance2, float Chance3, int_fast32_t revisions, std::string Search){
    using namespace std;
    int min(0);
    int max(100);
    std::random_device rd;    						// only used once to initialise (seed) engine
    std::mt19937 rng(rd());    						// random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max);// guaranteed unbiased
    int_fast16_t returned1(0);
    int_fast16_t returned2(0);
    int_fast16_t returned3(0);
    int Searched(0);
    int sizeofSearch(sizeof(Search));
    std::string Event;
    for(int_fast16_t rev(0);rev<revisions;rev++){
        float randomfloat = static_cast<float>(uni(rng))/100;
        bool Event1(randomfloat <= Chance1);
        bool Event2(randomfloat > Chance1 && randomfloat < 1 - Chance3);
        bool Event3(randomfloat >Chance2+Chance1);
        if (Event1){
            std::cout<<1<<std::endl;
            returned1++;
            Event.append("1");
        }
        else if(Event2){
            std::cout<<2<<std::endl;
            returned2++;
            Event.append("2");
        }
        else if(Event3){
            std::cout<<3<<std::endl;
            returned3++;
            Event.append("3");
        }
        else{
            rev--;
        }
    }
    int CountSearch=countstring(Event,Search);
    std::cout<<"Amount of times 1: "<<returned1<<std::endl;
    std::cout<<"Amount of times 2: "<<returned2<<std::endl;
    std::cout<<"Amount of times 3: "<<returned3<<std::endl;
    std::cout<<"Searched Event Found: "<<CountSearch<<std::endl;
    std::cout<<"Percentage of 1: "<<static_cast<float>(returned1)/revisions<<std::endl;
    std::cout<<"Percentage of 2: "<<static_cast<float>(returned2)/revisions<<std::endl;
    std::cout<<"Percentage of 3: "<<static_cast<float>(returned3)/revisions<<std::endl;
    std::cout<<"Percentage of Searched Event:"<<static_cast<float>(CountSearch)/revisions<<std::endl;
}
bool Checks(float Chance1, float Chance2, float Chance3, int_fast32_t revisions){
    float sum = Chance1+Chance2+Chance3;
    if(sum!=1 or revisions < 1){
        std::cout<<"Wrong inputs!"<<std::endl;
        return 0;
    }
    else{
        return 1;
    }
}
bool checkrevisions(int revisions){
    if(revisions>=1){
        return 1;
    }
    else{
        return 0;
    }
}
bool checkChance(float Chance){
    if(Chance>1){											//check if bigger than 1
        std::cout<<"Wrong input for Chance 1"<<std::endl;
        return 0;
    }
    else{
        return 1;
    }
}
void Simulation(){
    int_fast32_t revisions;
    float Chance1;
    float Chance2;
    revisions = getint("Put in the numbers of revisions:");	//get revisions
    if(not (checkrevisions(revisions))){
        std::cout<<"Something is wrong with your revisions"<<std::endl;
    }
    Chance1 = getfloat("Enter the chance of 1:");			//get values
    checkChance(Chance1);
    Chance2 = getfloat("Enter the Chance of 2:");			//get values
    checkChance(Chance2);
    float Chance3(1-Chance1-Chance2);						//calculate Chance of 3
    std::string Search(getstring("Enter The Event you want to search:"));
    if (Checks(Chance1,Chance2,Chance3, revisions)){
        simulate(Chance1, Chance2, Chance3, revisions, Search);
    }
    else {
        std::cout << "Something went wrong. Check your Values" << std::endl;
    }
}
#endif //SIMULATIONSRC_SIMULATION_H
