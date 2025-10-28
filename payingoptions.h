//
// Created by richard hague on 20/07/2025.
//

#ifndef PAYINGOPTIONS_H
#define PAYINGOPTIONS_H
#include"cars.h"


class payingoptions {
public:
int intrest;
string userinput;
int financeintrest;
int financeTimePeriod;
 int creditscore;
void payingopt(cars& car);
void payingfull(cars& car);
void payingfinance(cars& car);
 void financeCalculator(cars& car);



 payingoptions();

};



#endif //PAYINGOPTIONS_H
