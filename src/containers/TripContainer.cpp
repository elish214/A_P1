//
// Created by raz on 30/12/16.
//

#include "TripContainer.h"

TripContainer::TripContainer(int id, int totalMeters, int numOfPassengers,
                             double taarif, PassengerContainer *passenger,
                             const vector<LocationContainer *> &route,
                             int time) : id(id), totalMeters(
        totalMeters), numOfPassengers(numOfPassengers), taarif(taarif),
                                         passenger(
                                                 passenger),
                                         route(route), time(time) {}

TripContainer::TripContainer() {}

int TripContainer::getId() const {
    return id;
}

int TripContainer::getTotalMeters() const {
    return totalMeters;
}

int TripContainer::getNumOfPassengers() const {
    return numOfPassengers;
}

double TripContainer::getTaarif() const {
    return taarif;
}

const PassengerContainer *TripContainer::getPassenger() const {
    return passenger;
}

const vector<LocationContainer *> &TripContainer::getRoute() const {
    return route;
}

int TripContainer::getTime() const {
    return time;
}
