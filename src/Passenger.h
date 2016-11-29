//
// Created by raz on 29/11/16.
//

#ifndef A_P1_PASSENGER_H
#define A_P1_PASSENGER_H


#include "Point.h"

class Passenger {
private:
    Point source;
    Point destination;
public:
    Passenger(const Point &source, const Point &destination);

    const Point &getSource() const;

    const Point &getDestination() const;

    int rate();
};


#endif //A_P1_PASSENGER_H
