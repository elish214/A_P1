//
// Created by raz on 29/11/16.
//

#include "Passenger.h"

/**
 * constructor.
 *
 * @param source a location.
 * @param destination another location.
 */
Passenger::Passenger(Location *source, Location *destination) :
        source(source), destination(destination) {}

/**
 * constructor.
 */
Passenger::Passenger() {}

/**
 * distructor.
 */
Passenger::~Passenger() {}

/**
 * returns passenger's source location.
 *
 * @return passenger's source location.
 */
Location *Passenger::getSource() {
    return source;
}

/**
 * returns passenger's destination location.
 *
 * @return passenger's destination location.
 */
Location *Passenger::getDestination() {
    return destination;
}

/**
 * randomly return a rate.
 *
 * @return random rate.
 */
int Passenger::rate() {
    return rand() % 5 + 1;
}

/**
 * method overloading for operator '=='.
 *
 * @param rhs another passenger.
 * @return whether it equals to current passenger or not.
 */
bool Passenger::operator==(const Passenger &rhs) const {
    return source == rhs.source &&
           destination == rhs.destination;
}

/**
 * method overloading for operator '!='.
 *
 * @param rhs another passenger.
 * @return whether it isn't equals to current passenger or not.
 */
bool Passenger::operator!=(const Passenger &rhs) const {
    return !(rhs == *this);
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param passenger a passenger.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const Passenger &passenger) {
    os << "source: " << passenger.source << " destination: " << passenger.destination;
    return os;
}