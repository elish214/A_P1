//
// Created by raz on 30/12/16.
//

#include "TripContainer.h"

TripContainer::TripContainer(int id, int totalMeters, int numOfPassengers,
                             double taarif, LocationContainer *source,
                             LocationContainer *destination,
                             const vector<LocationContainer *> &route,
                             int time) : id(id), totalMeters(
        totalMeters), numOfPassengers(numOfPassengers), taarif(taarif),
                                         route(route), time(time),
                                         source(source),
                                         destination(destination) {}

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

const vector<LocationContainer *> &TripContainer::getRoute() const {
    return route;
}

int TripContainer::getTime() const {
    return time;
}

const LocationContainer *TripContainer::getSource() const {
    return source;
}

const LocationContainer *TripContainer::getDestination() const {
    return destination;
}
