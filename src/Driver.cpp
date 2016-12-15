//
// Created by raz on 29/11/16.
//

#include "Driver.h"

using namespace std;

/**
 * constructor.
 *
 * @param id an integer.
 * @param age an integer.
 * @param status an enum.
 */
Driver::Driver(int id, int age, MaritalStatus status) : id(id), age(age),
                                                        status(status),
                                                        experience(0),
                                                        satisfaction(0, 0) {
    Point *p = new Point(0, 0);
    location = new Location(*p);
}

/**
 * constructor.
 */
Driver::Driver() : satisfaction(0, 0) {
    Point *p = new Point(0, 0);
    location = new Location(*p);
}

/**
 * distructor.
 */
Driver::~Driver() {
    delete taxi;
    delete location;
    //delete all listeners.
}

/**
 * returns driver's location.
 *
 * @return driver's location.
 */
const Location *Driver::getLocation() const {
    return location;
}

/**
 * setting driver's location.
 *
 * @param location driver's location.
 */
void Driver::setLocation(Location *location) {
    this->location = location;
}

/**
 * returns driver's taxi.
 *
 * @return driver's taxi.
 */
Taxi *Driver::getTaxi() const {
    return taxi;
}

/**
 * setting driver's taxi.
 *
 * @param taxi driver's taxi.
 */
void Driver::setTaxi(Taxi *taxi) {
    Driver::taxi = taxi;
}

/**
 * starting trip.
 *
 * @param trip a trip.
 */
void Driver::start(TripInfo trip) {

}

/**
 * drive the route.
 */
void Driver::drive(vector<Location *>) {

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
 * removing listener.
 *
 * @param listener a listener.
 */
void Driver::removeListener(EndTripListener *listener) {

}

/**
 * returns whether is available.
 *
 * @return whether is available.
 */
bool Driver::isAvailability() const {
    return true;
}

/**
 * setting driver's availability.
 *
 * @param availability a boolean value.
 */
void Driver::setAvailability(bool availability) {

}

/**
 * returns driver's satisfaction.
 *
 * @return driver's satisfaction.
 */
double Driver::getSatisfaction() {
    return satisfaction.getRating();
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

/**
 * returns enum as a string.
 *
 * @param status aan enum.
 * @return enum as a string.
 */
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
            //default:;
    }
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param driver a driver.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const Driver &driver) {
    os << "id: " << driver.id
       << " location: " << *driver.getLocation()
       << " age: " << driver.age
       << " status: " << statusToString(driver.status)
       << " experience: " << driver.experience
       << " taxi-" << *driver.taxi;
    return os;
}

/**
 * returns driver's id.
 *
 * @return driver's id.
 */
int Driver::getId() const {
    return id;
}

/**
 * returns driver's taxi's id.
 *
 * @return driver's taxi's id.
 */
int Driver::getTaxiID() const {
    return taxiID;
}

/**
 * setting experience.
 *
 * @param experience an integer.
 */
void Driver::setExperience(int experience) {
    Driver::experience = experience;
}

int Driver::getExperience() {
    return experience;
}

