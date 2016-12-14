//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TRIPINFO_H
#define A_P1_TRIPINFO_H


#include <iostream>
#include "navigation/Point.h"
#include "Passenger.h"
#include "navigation/Location.h"

/**
 * trip information class.
 */
class TripInfo {
private:
    int id;
    int totalMeters;
    Location *start;
    Location *end;
    int numOfPassengers;
    double taarif;
    Passenger passenger;
    Grid *grid;
    vector<Node*> route;

public:
    TripInfo();

    TripInfo(int id, int numOfPassengers, Passenger passenger);

    Grid *getGrid() const;

    void setGrid(Grid *g);

    int getId() const;

    int getTotalMeters() const;

    void findPath();

    void calcMeters();

    vector<Node*> getRoute();

    Location *getStart();

    Location *getEnd();

    int getNumOfPassengers() const;

    double getTaarif() const;

    const Passenger &getPassenger() const;

    friend istream &operator>>(istream &is, TripInfo &trip);

    friend ostream &operator<<(ostream &os, const TripInfo &info);
};


#endif //A_P1_TRIPINFO_H
