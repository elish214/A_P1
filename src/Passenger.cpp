//
// Created by raz on 29/11/16.
//

#include "Passenger.h"

Passenger::Passenger(const Location &source, const Location &destination) :
        source(source), destination(destination) {}

Location &Passenger::getSource() {
    return source;
}

Location &Passenger::getDestination() {
    return destination;
}

int Passenger::rate() {
    return 0;
}