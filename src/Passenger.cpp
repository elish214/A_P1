//
// Created by raz on 29/11/16.
//

#include "Passenger.h"

Passenger::Passenger(const Point &source, const Point &destination) : source(
        source), destination(destination) {}

const Point &Passenger::getSource() const {
    return source;
}

const Point &Passenger::getDestination() const {
    return destination;
}

int Passenger::rate() {
    return 0;
}
