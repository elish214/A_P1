//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TAXICENTER_H
#define A_P1_TAXICENTER_H

#include <queue>
#include <ostream>
#include "Driver.h"

/**
 * taxi center class.
 */
class TaxiCenter {
private:
    vector<Driver> employees;
    vector<Taxi *> cabs;
    deque<TripInfo> trips;
public:
    TaxiCenter();

    vector<Driver> &getEmployees();

    vector<Taxi *> &getCabs();

    deque<TripInfo> &getTrips();

    TripInfo getFirstTrip();

    void addDriver(Driver driver);

    void addTaxi(Taxi *taxi);

    void connect(Driver driver, Taxi *taxi);

    void answer(Passenger passenger);

    friend ostream &operator<<(ostream &os, const TaxiCenter &center);
};


#endif //A_P1_TAXICENTER_H
