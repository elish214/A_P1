//
// Created by raz on 29/11/16.
//

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
deque<TripInfo> &TaxiCenter::getTrips() {
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

Driver *TaxiCenter::getDriver(int i) {
    for (Driver *driver:employees) {
        if (driver->getId() == i) {
            return driver;
        }
    }

    return nullptr;
}

void TaxiCenter::addTrip(TripInfo trip) {
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

Taxi *TaxiCenter::getTaxi(int i) {
    for (Taxi *taxi:cabs) {
        if (taxi->getId() == i) {
            return taxi;
        }
    }

    return nullptr;
}

/**
 * fonnect between taxi and a driver.
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

ostream &operator<<(ostream &os, const TaxiCenter &center) {
    os << "employees: " << endl;
    for (Driver *driver : center.employees) {
        cout << '\t' << *driver << endl;
    }

    os << endl << "cabs: " << endl;
    for (Taxi *taxi : center.cabs) {
        cout << '\t' << *taxi << endl;
    }

    cout << endl << "trips: " << endl;
    for (TripInfo trip : center.trips) {
        cout << '\t' << trip << endl;
    }

    return os;
}

void printLocations(map<Point, deque<Driver *>> locations) {
    for (map<Point, deque<Driver *>>::iterator it = locations.begin();
         it != locations.end(); ++it) {
        cout << it->first << ": ";

        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second.at((unsigned long) i)->getId() << ", ";
        }

        cout << endl;
    }
}

void TaxiCenter::start() {
    TripInfo trip;
    Driver *driver;
    unsigned long availableDrivers = employees.size();

    printLocations(locations);

    while (!trips.empty() && availableDrivers > 0) {
        trip = trips.front();
        trips.pop_front();
        driver = pop(*trip.getStart()->getPoint());

        driver->setLocation(trip.getEnd());

        push(driver);
        availableDrivers--;
    }

    cout << "  V V V" << endl;
    printLocations(locations);
}

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

Driver *TaxiCenter::pop(Point p) {
    map<Point, deque<Driver *>>::iterator it = locations.find(p);
    Driver *driver = nullptr;

    if (it != locations.end()) {
        driver = it->second.front();
        it->second.pop_front();
    }

    return driver;
}
