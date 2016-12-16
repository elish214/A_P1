//
// Created by raz on 29/11/16.
//

#include "Driver.h"

using namespace std;

Driver::Driver(int id, int age, MaritalStatus status) : id(id), age(age),
                                                        status(status),
                                                        experience(0),
                                                        satisfaction(0, 0) {
    Point *p = new Point(0, 0);
    location = new Location(*p);
}

Driver::Driver() : satisfaction(0, 0) {
    Point *p = new Point(0, 0);
    location = new Location(*p);
}

Driver::~Driver() {
    //delete taxi;
    //delete location;
}

const Location *Driver::getLocation() const {
    return location;
}

void Driver::setLocation(Location *location) {
    this->location = location;
}

Taxi *Driver::getTaxi() const {
    return taxi;
}

void Driver::setTaxi(Taxi *taxi) {
    Driver::taxi = taxi;
}

void Driver::start(TripInfo trip) {

}

void Driver::drive(vector<Location *>) {

}

void Driver::notifyAllEndTrip() {

}

void Driver::addListener(EndTripListener *listener) {

}

void Driver::removeListener(EndTripListener *listener) {

}

bool Driver::isAvailability() const {
    return true;
}

void Driver::setAvailability(bool availability) {

}

double Driver::getSatisfaction() const {
    return 0.0;
}

/**
 * method overloading for operator '>>'.
 *
 * @param is input stream.
 * @param point a point.
 * @return input stream.
 */
istream &operator>>(istream &is, Driver &driver) {
    string s;

    getline(is, s, ',');
    driver.id = atoi(s.c_str());

    getline(is, s, ',');
    driver.age = atoi(s.c_str());

    getline(is, s, ',');
    driver.status = static_cast<MaritalStatus>(s[0]);

    getline(is, s, ',');
    driver.experience = atoi(s.c_str());

    getline(is, s, '\n');
    driver.taxiID = atoi(s.c_str());

    driver.satisfaction = Satisfaction(0, 0);

    return is;
}

string statusToString(MaritalStatus status) {
    switch (status) {
        case MaritalStatus::SINGLE:
            return "SINGLE";
        case MaritalStatus::MARRIED:
            return "MARRIED";
        case MaritalStatus::DIVORCED:
            return "DIVORCED";
        case MaritalStatus::WIDOWED:
            return "WIDOWED";
        default:
            return "NONE";
    }
}

ostream &operator<<(ostream &os, const Driver &driver) {
    os << "id: " << driver.id
       << " location: " << *driver.getLocation()
       << " age: " << driver.age
       << " status: " << statusToString(driver.status)
       << " experience: " << driver.experience
       << " taxi-" << *driver.taxi;
    return os;
}

int Driver::getId() const {
    return id;
}

int Driver::getTaxiID() const {
    return taxiID;
}




