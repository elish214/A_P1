//
// Created by raz on 29/11/16.
//

#include "TaxiCenter.h"

/**
 * constructor.
 */
TaxiCenter::TaxiCenter() {
    this->trips = deque<TripInfo>();
    this->cabs = vector<Taxi *>();
    this->employees = vector<Driver>();
}

/**
 * returns center's employees vector.

 * @return center's employees vector.
 */
vector<Driver> &TaxiCenter::getEmployees() {
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
void TaxiCenter::addDriver(Driver driver) {
    employees.emplace_back(driver);
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
    Location l1 = Location();
    Location l2 = Location();

    return TripInfo(0, 0, Passenger(l1, l2));
}

ostream &operator<<(ostream &os, const TaxiCenter &center) {
    os << "employees: " << endl;
    for (Driver driver : center.employees) {
        cout << '\t' << driver << endl;
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
