//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TAXI_H
#define A_P1_TAXI_H

#include <ostream>
#include "../enums/CarManufacturer.h"
#include "../enums/Color.h"

using namespace std;

class Taxi {
private:
    int id;
    double KmPassed;
    CarManufacturer manufacturer;
    Color color;
public:
    Taxi(int id, CarManufacturer manufacturer, Color color);

    Taxi();

    void addMeters(double meters);

    double getKmPassed() const;

    virtual int getTaarif() = 0;

    virtual int getSpeed() = 0;

    friend istream &operator>>(istream &is, Taxi &taxi);

    friend ostream &operator<<(ostream &os, const Taxi &taxi);
};


#endif //A_P1_TAXI_H
