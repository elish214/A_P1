//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TRIPINFO_H
#define A_P1_TRIPINFO_H


#include <iostream>
#include "navigation/Point.h"
#include "Passenger.h"
#include "navigation/Location.h"
#include "containers/TripContainer.h"

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
    Passenger *passenger;
    Grid *grid;
    vector<Node*> route;
    int time;

public:
    TripInfo(int id, int numOfPassengers, Passenger *passenger, int time);

    TripInfo(int id, int numOfPassengers, Passenger *passenger);

    TripInfo(TripContainer tc);

    TripInfo();

    virtual ~TripInfo();

    Grid *getGrid() const;

    void setGrid(Grid *g);

    void initPassenger();

    int getId() const;

    int getTotalMeters() const;

    void findPath();

    void calcMeters();

    int getTime() const;

    vector<Node*> getRoute();

    void setRoute(const vector<Node *> &route);

    Location *getStart();

    Location getStartVal();

    Location *getEnd();

    Location getEndVal();

    TripContainer *getContainer();

    int getNumOfPassengers() const;

    double getTaarif() const;

    Passenger *getPassenger() const;

    friend istream &operator>>(istream &is, TripInfo &trip);

    friend ostream &operator<<(ostream &os, TripInfo &info);
};


#endif //A_P1_TRIPINFO_H
