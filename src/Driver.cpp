//
// Created by raz on 29/11/16.
//

#include "Driver.h"

/**
 * constructor.
 *
 * @param id an integer.
 * @param age an integer.
 * @param status an enum.
 */
Driver::Driver(int id, int age, MaritalStatus status) : id(id), age(age), status(status),
                                                        experience(0),
                                                        satisfaction(0, 0) {
    Point *p = new Point(0, 0);
    location = new Location(*p);
}

/**
 * returns driver's location.
 *
 * @return driver's location.
 */
const Location &Driver::getLocation() const {
    return *location;
}

/**
 * returns driver's taxi.
 *
 * @return driver's taxi
 */
Taxi *Driver::getTaxi() const {
    return taxi;
}

/**
 * set driver's taxi.
 *
 * @param taxi a taxi.
 */
void Driver::setTaxi(Taxi *taxi) {
    Driver::taxi = taxi;
}

/**
 * start driving. get to start point.

 * @param trip a trip information.
 *
 */
void Driver::start(TripInfo trip) {

}

/**
 * get a path and drive it.
 */
void Driver::drive(vector<Location*>) {

}

/**
 * notify all listeners.
 */
void Driver::notifyAllEndTrip() {

}

/**
 * add listener.
 *
 * @param listener a listener.
 */
void Driver::addListener(EndTripListener *listener) {

}

/**
 * remove listener.
 *
 * @param listener a listener.
 */
void Driver::removeListener(EndTripListener *listener) {

}

/**
 * set driver's location.
 *
 * @param location a location.
 */
void Driver::setLocation(const Location &location) {

}

/**
 * returns if driver is available.
 *
 * @return if driver is available.
 */
bool Driver::isAvailability() const {
    return true;
}

/**
 * set driver's availability.
 *
 * @param availability a boolean.
 */
void Driver::setAvailability(bool availability) {

}

/**
 * returns satisfaction of driver.
 *
 * @return satisfaction of driver.
 */
double Driver::getSatisfaction() const {
    return 0.0;
}

/**
 * distructor.
 */
Driver::~Driver() {
    //delete taxi;
    //delete location;
}