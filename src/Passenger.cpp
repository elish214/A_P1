//
// Created by raz on 29/11/16.
//

#include "Passenger.h"

Passenger::Passenger(Location &source, Location &destination) :
        source(source), destination(destination) {}

Passenger::Passenger() {}

Passenger::~Passenger() {

}

Location &Passenger::getSource() {
    return source;
}

Location &Passenger::getDestination() {
    return destination;
}

int Passenger::rate() {
    return 1;
}

bool Passenger::operator==(const Passenger &rhs) const {
    return source == rhs.source &&
           destination == rhs.destination;
}

bool Passenger::operator!=(const Passenger &rhs) const {
    return !(rhs == *this);
}
