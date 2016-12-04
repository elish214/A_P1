//
// Created by raz on 29/11/16.
//

#include "Driver.h"


Driver::Driver(int id, int age, MaritalStatus status) : id(id), age(age), status(status),
                                                   experience(0),
                                                   satisfaction(0,0) {}

const Location &Driver::getLocation() const {
    return location;
}

Taxi *Driver::getTaxi() const {
    return taxi;
}

void Driver::setTaxi(Taxi *taxi) {
    Driver::taxi = taxi;
}

void Driver::start(TripInfo trip) {

}

void Driver::drive(vector<Location*>) {

}

void Driver::notifyAllEndTrip() {

}

void Driver::addListener(EndTripListener *listener) {

}

void Driver::removeListener(EndTripListener *listener) {

}

void Driver::setLocation(const Location &location) {
    Driver::location = location;
}

bool Driver::isAvailability() const {
    return true;
}

void Driver::setAvailability(bool availability) {

}

double Driver::getSatisfaction() const {
    return 0.0;
}


