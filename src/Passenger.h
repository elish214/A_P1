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
    Passenger(const Location &source, const Location &destination);

    Location &getSource();

    Location &getDestination();

    int rate();
};


#endif //A_P1_PASSENGER_H
