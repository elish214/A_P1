//
// Created by raz on 29/11/16.
//

#include "Passenger.h"

/**
 * constructor.
 *
 * @param source source location.
 * @param destination destination location.
 */
Passenger::Passenger(Location &source, Location &destination) :
        source(source), destination(destination) {}

/**
 * returns passenger's source location.
 *
 * @return passenger's source location.
 */
Location &Passenger::getSource() {
    return source;
}

/**
 * returns passenger's destination location.
 *
 * @return passenger's destination location.
 */
 Location &Passenger::getDestination() {
    return destination;
}

/**
 * returns random rate between 1 to 5.
 *
 * @return random rate between 1 to 5
 */
int Passenger::rate() {
    return 1;
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
 * distructor.
 */
Passenger::~Passenger() {

}
