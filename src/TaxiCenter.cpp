//
// Created by raz on 29/11/16.
//

#include "TaxiCenter.h"

TaxiCenter::TaxiCenter() : {}

const vector<Driver> &TaxiCenter::getEmployees() const {
    return employees;
}

const vector<Taxi *> &TaxiCenter::getCabs() const {
    return cabs;
}

const queue<TripInfo> &TaxiCenter::getTrips() const {
    return trips;
}

void TaxiCenter::addDriver(Driver driver) {
    employees.emplace_back(driver);
}

void TaxiCenter::addTaxi(Taxi *taxi) {
    cabs.emplace_back(taxi);
}

void TaxiCenter::connect(Driver driver, Taxi *taxi) {
    driver.setTaxi(taxi);
}

void TaxiCenter::answer(Passenger passenger) {
    //create tripinfo, choose a driver and assign a cab to it.
}


