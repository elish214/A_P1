//
// Created by raz on 29/11/16.
//

#include "TaxiCenter.h"

/**
 * constructor.
 */
TaxiCenter::TaxiCenter() {}

/**
 * returns center's employees vector.

 * @return center's employees vector.
 */
const vector<Driver> &TaxiCenter::getEmployees() const {
    return employees;
}

/**
 * returns center's cabs vector.
 *
 * @return center's cabs vector.
 */
const vector<Taxi *> &TaxiCenter::getCabs() const {
    return cabs;
}

/**
 * returns center's trips queue.
 *
 * @return center's trips queue.
 */
const queue<TripInfo> &TaxiCenter::getTrips() const {
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


    int size = (int) center.trips.size();
    TripInfo temp;

    cout << endl << "trips: " << endl;
    for (int i = 0; i < size; i++) {
        temp = center.trips.front();
        cout << '\t' << temp << endl;
        center.trips.pop();
        center.trips.push(temp);
    }
    return os;
}
