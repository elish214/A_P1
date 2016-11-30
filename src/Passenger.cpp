//
// Created by raz on 29/11/16.
//

#include "Passenger.h"

Passenger::Passenger(const Point &source, const Point &destination) : source(
        source), destination(destination) {}

Point &Passenger::getSource() {
    return source;
}

Point &Passenger::getDestination() {
    return destination;
}

int Passenger::rate() {
    return 0;
}
