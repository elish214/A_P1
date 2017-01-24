//
// Created by raz on 29/11/16.
//

#include "Driver.h"
#define ERROR -1

using namespace std;

/**
 * constructor.
 *
 * @param id an integer.
 * @param age an integer.
 * @param status an enum.
 * @param experience an integer.
 * @param taxiID an integer..
 */
Driver::Driver(int id, int age, MaritalStatus status, int experience,
               int taxiID) : id(id), age(age), status(status),
                             experience(experience), taxiID(taxiID) {
    taxi = NULL;
    location = new Location(0, 0);
}

/**
 * constructor.
 *
 * @param id an integer.
 * @param age an integer.
 * @param status an enum.
 */
Driver::Driver(int id, int age, MaritalStatus status, int taxiId) : id(id),
                                                                    age(age),
                                                                    status(status),
                                                                    experience(0),
                                                                    taxiID(taxiId),
                                                                    satisfaction(0, 0) {
    taxi = NULL;
    location = new Location(0, 0);
}

/**
 * constructor.
 */
Driver::Driver() : satisfaction(0, 0) {
    taxi = NULL;
    location = new Location(0, 0);
}

/**
 * constructor.
 *
 * @param container a driver container.
 */
Driver::Driver(DriverContainer container) :
        satisfaction(0, 0) {
    id = container.getId();
    age = container.getAge();
    status = container.getStatus();
    taxiID = container.getTaxiID();
    experience = container.getExperience();
    available = true;
}

/**
 * destructor.
 */
Driver::~Driver() {
    //delete taxi;
    //delete location;
    //delete all listeners.
}

/**
 * client's use to delete itself.
 */
void Driver::deleteLocation(){
    delete location;
}

/**
 * returns driver's location.
 *
 * @return driver's location.
 */
const Node *Driver::getLocation() const {
    return location;
}

/**
 * setting driver's location.
 *
 * @param location driver's location.
 */
void Driver::setLocation(Node *location) {
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

    try {
        getline(is, s, ',');
        driver.id = stoi(s.c_str());
        if (driver.id < 0) {
            driver.id = ERROR;
            return is;
        }
    } catch (exception e) {
        driver.id = ERROR;
        return is;
    }

    try {
    getline(is, s, ',');
    driver.age = stoi(s.c_str());
    if (driver.age < 0) {
        driver.id = ERROR;
        return is;
        }
    } catch (exception e) {
        driver.id = ERROR;
        return is;
    }

    getline(is, s, ',');
    driver.status = static_cast<MaritalStatus>(s[0]);
    if (driver.status != MaritalStatus::DIVORCED &&
        driver.status != MaritalStatus::WIDOWED &&
        driver.status != MaritalStatus::MARRIED &&
        driver.status != MaritalStatus::SINGLE) {
        driver.id = ERROR;
        return is;
    }

    try {
        getline(is, s, ',');
        driver.experience = stoi(s.c_str());
        if (driver.experience < 0) {
            driver.id = ERROR;
            return is;
        }
    } catch (exception e) {
        driver.id = ERROR;
        return is;
    }

    try {
        getline(is, s, '\n');
        driver.taxiID = stoi(s.c_str());
        if (driver.taxiID < 0) {
            driver.id = ERROR;
            return is;
        }
    } catch (exception e) {
        driver.id = ERROR;
        return is;
    }

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
        default:
            return "NONE";
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
       << " taxi: " << driver.taxiID;
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

/**
 * returns driver's experience.
 *
 * @return driver's experience.
 */
int Driver::getExperience() {
    return experience;
}

/**
 * Driver [step] steps on grid
 */
void Driver::moveOneStep(int step) {
    //advance according to 'step'.
    for (int i = 0; i < step; i++) {
        if (route.size() != 0) {
            setLocation(route.front());
            route.erase(route.begin());
        }
    }
}

/**
 * Move [taxi->speed] steps
 */
void Driver::moveTaxiStep() {
    moveOneStep(getTaxi()->getSpeed());
}

/**
 *  returns driver's container.
 *
 * @return driver's container.
 */
DriverContainer *Driver::getContainer() {
    return new DriverContainer(id, age, status, taxiID, experience);
}

/**
 * setting driver's route.
 *
 * @param route a vector.
 */
void Driver::setRoute(const vector<Node *> &route) {
    Driver::route = route;
}

int Driver::getDescriptor() const {
    return descriptor;
}

void Driver::setDescriptor(int descriptor) {
    Driver::descriptor = descriptor;
}

/**
 * returns whether is available.
 *
 * @return whether is available.
 */
bool Driver::isAvailable() const {
    return available;
}

/**
 * setting driver's availability.
 *
 * @param availability a boolean value.
 */
void Driver::setAvailable(bool available) {
    Driver::available = available;
}

bool Driver::operator==(const Driver &rhs) const {
    return id == rhs.id;
}

bool Driver::operator!=(const Driver &rhs) const {
    return !(rhs == *this);
}


