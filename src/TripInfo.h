//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TRIPINFO_H
#define A_P1_TRIPINFO_H


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
    Location start;
    Location end;
    int numOfPassengers;
    int taarif;
    Passenger passenger;
public:
    TripInfo(int id, int numOfPassengers, Passenger passenger);

    int getId() const;

    int getTotalMeters() const;

    Location &getStart();

    Location &getEnd();

    int getNumOfPassengers() const;

    int getTaarif() const;

    const Passenger &getPassenger() const;

};


#endif //A_P1_TRIPINFO_H
