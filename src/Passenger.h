//
// Created by raz on 29/11/16.
//

#ifndef A_P1_PASSENGER_H
#define A_P1_PASSENGER_H


#include "navigation/Point.h"
#include "navigation/Location.h"

class Passenger {
private:
    Location source;
    Location destination;
public:
    Passenger(Location &source, Location &destination);

    Passenger();

    virtual ~Passenger();

    Location &getSource();

    Location &getDestination();

    int rate();

    bool operator==(const Passenger &rhs) const;

    bool operator!=(const Passenger &rhs) const;
};


#endif //A_P1_PASSENGER_H
