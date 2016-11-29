//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TAXICENTER_H
#define A_P1_TAXICENTER_H


#include <queue>
#include "Driver.h"

class TaxiCenter {
private:
    vector<Driver> employees;
    vector<Taxi> cabs;
    queue<TripInfo> trips;
public:
    void addDriver(Driver driver);

    void addTaxi(Taxi taxi);

    void connect(Driver, Taxi);

    void answer(Passenger passenger);
};


#endif //A_P1_TAXICENTER_H
