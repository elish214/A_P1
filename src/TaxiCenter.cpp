//
// Created by raz on 29/11/16.
//

#include <vector>
#include "TaxiCenter.h"

using namespace std;

/**
 * constructor.
 */
TaxiCenter::TaxiCenter() {
    //this->trips = deque<TripInfo>();
    //this->cabs = vector<Taxi *>();
    //this->employees = vector<Driver *>();
}

TaxiCenter::~TaxiCenter() {

    for (unsigned int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }

    for (unsigned int j = 0; j < cabs.size(); j++) {
        delete cabs[j];
    }
/*
    for (unsigned int k = 0; k < trips.size(); k++) {
        delete &(trips.at(k));
    }*/
    employees.clear();
    cabs.clear();
    trips.clear();
}

/**
 * returns center's employees vector.

 * @return center's employees vector.
 */
vector<Driver *> &TaxiCenter::getEmployees() {
    return employees;
}

/**
 * returns center's cabs vector.
 *
 * @return center's cabs vector.
 */
vector<Taxi *> &TaxiCenter::getCabs() {
    return cabs;
}

/**
 * returns center's trips queue.
 *
 * @return center's trips queue.
 */
deque<TripInfo*> &TaxiCenter::getTrips() {
    return trips;
}

/**
 * add driver to center.
 *
 * @param driver a driver.
 */
void TaxiCenter::addDriver(Driver *driver) {
    driver->setTaxi(getTaxi(driver->getTaxiID()));
    employees.emplace_back(driver);
    push(driver);
}

/**
 * returns the i'th driver.
 *
 * @param i an index.
 * @return the i'th driver.
 */
Driver *TaxiCenter::getDriver(int i) {
    Driver *d;

    for (unsigned int j = 0; j < employees.size(); j++) {
        d = employees.at(j);
        if (d->getId() == i) {
            return d;
        }
    }

    return NULL;
}

/**
 * adding a trip to center.
 *
 * @param trip a trip.
 */
void TaxiCenter::addTrip(TripInfo *trip) {
    trips.emplace_back(trip);
}

/**
 * add taxi to center.
 *
 * @param taxi a taxi.
 */
void TaxiCenter::addTaxi(Taxi *taxi) {
    cabs.emplace_back(taxi);
}

/**
 * returns the i'th taxi.
 *
 * @param i an index.
 * @return  the i'th taxi.
 */
Taxi *TaxiCenter::getTaxi(int i) {
    Taxi *t;

    for (unsigned int j = 0; j < cabs.size(); j++) {
        t = cabs.at(j);
        if (t->getId() == i){
            return t;
        }
    }

    return NULL;
}

/**
 * connect between taxi and a driver.
 *
 * @param driver a driver.
 * @param taxi a taxi.
 */
void TaxiCenter::connect(Driver driver, Taxi *taxi) {
    driver.setTaxi(taxi);
}

/**
 * answer passenger's call.
 *
 * @param passenger a passenger.
 */
void TaxiCenter::answer(Passenger passenger) {
    //create tripinfo, choose a driver and assign a cab to it.
}

/**
 * returns center's first trip in queue.
 *
 * @return center's first trip in queue.
 */
TripInfo TaxiCenter::getFirstTrip() {
    Location *l1 = new Location();
    Location *l2 = new Location();

    return TripInfo(0, 0, Passenger(l1, l2));
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param center a taxi center.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const TaxiCenter &center) {
    Driver *d;
    Taxi *t;
    TripInfo *ti;

    os << "employees: " << endl;
    for (unsigned int i = 0; i < center.employees.size(); i++) {
        d = center.employees.at(i);
        cout << '\t' << *d << endl;
    }

    os << endl << "cabs: " << endl;
    for (unsigned int j = 0; j < center.cabs.size(); j++) {
        t = center.cabs.at(j);
        cout << '\t' << *t << endl;
    }

    cout << endl << "trips: " << endl;
    for (unsigned int k = 0; k < center.trips.size(); k++) {
        ti = center.trips.at(k);
        cout << '\t' << ti << endl;
    }

    return os;
}

/**
 * print driver's location.
 *
 * @param locations location.
 */
void printLocations(map<Point, deque<Driver *>> locations) {
    for (map<Point, deque<Driver *>>::iterator it = locations.begin();
         it != locations.end(); ++it) {
        cout << it->first << ": ";

        for (unsigned int i = 0; i < it->second.size(); i++) {
            cout << it->second.at((unsigned long) i)->getId() << ", ";
        }

        cout << endl;
    }
}

/**
 * starting function.
 */
void TaxiCenter::start() {
    TripInfo *trip;
    Driver *driver;
    unsigned long availableDrivers = employees.size();

    //printLocations(locations);

    while (!trips.empty() && availableDrivers > 0) {
        trip = trips.front();
        trips.pop_front();
        driver = pop(*trip->getStart()->getPoint());

        driver->setLocation(trip->getEnd());
        driver->setExperience(driver->getExperience()+ 1);
        push(driver);
        availableDrivers--;
        delete trip;
    }

   // cout << "  V V V" << endl;
    //printLocations(locations);
}

/**
 * pushing function.
 *
 * @param driver a driver.
 */
void TaxiCenter::push(Driver *driver) {
    Point p = *driver->getLocation()->getPoint();
    map<Point, deque<Driver *>>::iterator it = locations.find(p);

    if (it == locations.end()) {
        deque<Driver *> d;
        d.emplace_back(driver);
        locations.insert(make_pair(*driver->getLocation()->getPoint(), d));
    } else {
        it->second.emplace_back(driver);
    }
}

/**
 * pop function.
 *
 * @param p a point.
 * @return a driver in the point.
 */
Driver *TaxiCenter::pop(Point p) {
    map<Point, deque<Driver *>>::iterator it = locations.find(p);
    Driver *driver = NULL;

    if (it != locations.end()) {
        driver = it->second.front();
        it->second.pop_front();
    }

    return driver;
}