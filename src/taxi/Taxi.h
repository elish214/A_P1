//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TAXI_H
#define A_P1_TAXI_H


#include "../enums/CarManufacturer.h"
#include "../enums/Color.h"

class Taxi {
private:
    int id;
    double KmPassed;
    CarManufacturer manufacturer;
    Color color;
public:
    void addMeters(double meters);

    virtual int getTaarif() = 0;

    virtual int getSpeed() = 0;
};


#endif //A_P1_TAXI_H
