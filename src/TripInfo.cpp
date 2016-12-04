//
// Created by raz on 29/11/16.
//

#include "TripInfo.h"

/**
 * constructor.
 *
 * @param id an integer.
 * @param numOfPassengers number of passenger.
 * @param passenger a passenger.
 */
TripInfo::TripInfo(int id, int numOfPassengers, Passenger passenger) :
        id(id), start(passenger.getSource()), end(passenger.getDestination()),
        numOfPassengers(numOfPassengers), passenger(passenger) {}

/**
 * returns trip's ID.
 *
 * @return trip's ID.
 */
int TripInfo::getId() const {
    return id;
}

/**
 * returns trip's total meters.
 *
 * @return trip's total meters.
 */
int TripInfo::getTotalMeters() const {
    return totalMeters;
}

/**
 * returns trip's starting location.
 *
 * @return trip's starting location.
 */
Location &TripInfo::getStart() {
    return start;
}

/**
 * returns trip's ending location.
 *
 * @return trip's ending location.
 */
Location &TripInfo::getEnd() {
    return end;
}

/**
 * returns trip's number of passengers.
 *
 * @return trip's number of passengers.
 */
int TripInfo::getNumOfPassengers() const {
    return numOfPassengers;
}

/**
 * returns trip's taarif.
 *
 * @return trip's taarif.
 */
int TripInfo::getTaarif() const {
    return taarif;
}

/**
 * returns trip's passenger.
 *
 * @return trip's passenger.
 */
const Passenger &TripInfo::getPassenger() const {
    return passenger;
}