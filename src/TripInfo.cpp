//

#include "TripInfo.h"


TripInfo::TripInfo(int id, int numOfPassengers, Passenger passenger) :
        id(id), start(passenger.getSource()), end(passenger.getDestination()),
        numOfPassengers(numOfPassengers), passenger(passenger) {}

//
// Created by raz on 29/11/16.
TripInfo::TripInfo() {}

int TripInfo::getId() const {
    return id;
}

int TripInfo::getTotalMeters() const {
    return totalMeters;
}

Location &TripInfo::getStart() {
    return start;
}

Location &TripInfo::getEnd() {
    return end;
}

int TripInfo::getNumOfPassengers() const {
    return numOfPassengers;
}

double TripInfo::getTaarif() const {
    return taarif;
}

const Passenger &TripInfo::getPassenger() const {
    return passenger;
}

istream &operator>>(istream &is, TripInfo &trip) {
    string s;
    int x1, y1, x2, y2;

    getline(is, s, ',');
    trip.id = atoi(s.c_str());

    getline(is, s, ',');
    x1 = atoi(s.c_str());

    getline(is, s, ',');
    y1 = atoi(s.c_str());

    trip.start = Location(x1, y1);

    getline(is, s, ',');
    x2 = atoi(s.c_str());

    getline(is, s, ',');
    y2 = atoi(s.c_str());

    trip.end = Location(x2, y2);

    getline(is, s, ',');
    trip.numOfPassengers = atoi(s.c_str());

    getline(is, s, '\n');
    trip.taarif = stod(s.c_str());

    return is;
}

ostream &operator<<(ostream &os, const TripInfo &info) {
    os << "id: " << info.id << " totalMeters: " << info.totalMeters
       << " start: " << info.start << " end: " << info.end
       << " numOfPassengers: " << info.numOfPassengers << " taarif: "
       << info.taarif;
    return os;
}

