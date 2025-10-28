
// Created by richard hague on 12/07/2025

#ifndef CARS_H
#define CARS_H
#include "cars.h"
#include <string>
#include "payingoptions.h"
using namespace std;
#include <vector>

struct car {
    int ID;
    int price;
    string model;
};

struct upgradeOptions {
    int carID;
    int uniquecarID;
    string name_of_package;
    string description;
    int price;





};
class cars {
public:
    vector<car> carlist;
    car selectedcar;
    /////////////////////////////////////
    vector<upgradeOptions> upgradelist;
    upgradeOptions selectedupgrade;







    cars();
    void listcars();
    void chooseOption();
    void CarOptions();
    void listupgrades();



};





#endif //CARS_H
