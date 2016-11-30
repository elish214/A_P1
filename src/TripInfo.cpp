//
// Created by raz on 29/11/16.
//

#include "TripInfo.h"


TripInfo::TripInfo(int id, int numOfPassengers, Passenger passenger) :
        id(id), start(passenger.getSource()), end(passenger.getDestination()),
        numOfPassengers(numOfPassengers), passenger(passenger) {}

int TripInfo::getId() const {
    return id;
}

int TripInfo::getTotalMeters() const {
    return totalMeters;
}

Location &TripInfo::getStart() {
    return start;
}

Location &TripInfo::getEnd() {
    return end;
}

int TripInfo::getNumOfPassengers() const {
    return numOfPassengers;
}

int TripInfo::getTaarif() const {
    return taarif;
}

const Passenger &TripInfo::getPassenger() const {
    return passenger;
}

