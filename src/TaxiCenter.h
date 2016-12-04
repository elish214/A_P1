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
    vector<Taxi *> cabs;
    queue<TripInfo> trips;
public:
    TaxiCenter();

    const vector<Driver> &getEmployees() const;

    const vector<Taxi *> &getCabs() const;

    const queue<TripInfo> &getTrips() const;

    TripInfo getFirstTrip();

    void addDriver(Driver driver);

    void addTaxi(Taxi *taxi);

    void connect(Driver driver, Taxi *taxi);

    void answer(Passenger passenger);
};


#endif //A_P1_TAXICENTER_H
