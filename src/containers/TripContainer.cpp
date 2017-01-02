//
// Created by raz on 30/12/16.
//

#include "TripContainer.h"

/**
 * constructor.
 *
 * @param id an integer.
 * @param totalMeters an integer.
 * @param numOfPassengers tn integer.
 * @param taarif tn integer.
 * @param source a location.
 * @param destination a location.
 * @param route the best route.
 * @param time time of start.
 */
TripContainer::TripContainer(int id, int totalMeters, int numOfPassengers,
                             double taarif, LocationContainer *source,
                             LocationContainer *destination,
                             const vector<LocationContainer *> &route,
                             int time) : id(id), totalMeters( totalMeters),
                                         numOfPassengers(numOfPassengers),
                                         taarif(taarif),
                                         source(source),
                                         destination(destination),
                                         route(route),
                                         time(time){}

/**
 * constructor.
 */
TripContainer::TripContainer() {}

/**
 * returns trip's id.
 *
 * @return trip's id.
 */
int TripContainer::getId() const {
    return id;
}

/**
 * returns trip's total meters.
 *
 * @return  trip's total meters.
 */
int TripContainer::getTotalMeters() const {
    return totalMeters;
}

/**
 * returns trip's number of passenger.
 *
 * @return  trip's number of passenger.
 */
int TripContainer::getNumOfPassengers() const {
    return numOfPassengers;
}

/**
 * returns trip's taarif.
 *
 * @return trip's taarif.
 */
double TripContainer::getTaarif() const {
    return taarif;
}

/**
 * returns trip's route.
 *
 * @return trip's route.
 */
const vector<LocationContainer *> &TripContainer::getRoute() const {
    return route;
}

/**
 * returns trip's time.
 *
 * @return trip's time.
 */
int TripContainer::getTime() const {
    return time;
}

/**
 * returns trip's source.
 *
 * @return trip's source.
 */
const LocationContainer *TripContainer::getSource() const {
    return source;
}

/**
 * returns trip's destination.
 *
 * @return trip's destination.
 */
const LocationContainer *TripContainer::getDestination() const {
    return destination;
}
