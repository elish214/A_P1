//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TAXICENTER_H
#define A_P1_TAXICENTER_H

#include <deque>
#include <iostream>
#include <map>
#include "Driver.h"
#include "navigation/Point.h"

using namespace std;

/**
 * taxi center class.
 */
class TaxiCenter {
private:
    vector<Driver *> employees;
    vector<Taxi *> cabs;
    vector<TripInfo *> trips;
    map<Point, deque<Driver *>> locations;

public:
    TaxiCenter();

    virtual ~TaxiCenter();

    void push(Driver *driver);

    Driver *pop(Point p);

    vector<Driver *> &getEmployees();

    map<Point, deque<Driver *>> &getLocations();

    vector<Taxi *> &getCabs();

    vector<TripInfo *> &getTrips();

    int numOfTripsAt(int time);

    TripInfo *getTripAt(int time);

    TripInfo *getTripAt(int time, Point *start);

    TripInfo *getTripAt(int time, Driver *driver);

    TripInfo getFirstTrip();

    void addDriver(Driver *driver);

    Driver *getDriver(int i);

    void addTrip(TripInfo *trip);

    void addTaxi(Taxi *taxi);

    Taxi *getTaxi(int i);

    void start();

    void connect(Driver driver, Taxi *taxi);

    void answer(Passenger passenger);

    void advanceAllDrivers();

    friend ostream &operator<<(ostream &os, const TaxiCenter &center);

    int numOfTripsAt(int time, Point *start);

    int getTurn(Driver *driver);

    void eraseDriver(Driver *driver);

    bool isDriverIn(Driver *driver);

    bool isDriverIn(int id);
};


#endif //A_P1_TAXICENTER_H
