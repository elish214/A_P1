//
// Created by raz on 29/11/16.
//

#include "TripInfo.h"
#include "navigation/BFS.h"


TripInfo::TripInfo(int id, int numOfPassengers, Passenger passenger) :
        id(id), start(passenger.getSource()), end(passenger.getDestination()),
        numOfPassengers(numOfPassengers), passenger(passenger), totalMeters(0) {}

TripInfo::TripInfo() : totalMeters(0) {}

Grid *TripInfo::getGrid() const {
    return grid;
}

void TripInfo::setGrid(Grid *g) {
    TripInfo::grid = g;
}

int TripInfo::getId() const {
    return id;
}

int TripInfo::getTotalMeters() const {
    return totalMeters;
}

void TripInfo::findPath() {
    BFS bfs;
    route = bfs.run(start, end);
}

void TripInfo::calcMeters() {
    findPath();
    for (int i = 0; i < route.size(); i++) {
        totalMeters += 1 ;
    }
}

vector<Node *> TripInfo::getRoute() {
    return route;
}

Location *TripInfo::getStart() {
    return start;
}

Location TripInfo::getStartVal() {
    return *start;
}

Location *TripInfo::getEnd() {
    return end;
}

Location TripInfo::getEndVal() {
    return *end;
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

    trip.start = new Location(x1, y1);

    getline(is, s, ',');
    x2 = atoi(s.c_str());

    getline(is, s, ',');
    y2 = atoi(s.c_str());

    trip.end = new Location(x2, y2);

    getline(is, s, ',');
    trip.numOfPassengers = atoi(s.c_str());

    getline(is, s, '\n');
    trip.taarif = stod(s.c_str());

    return is;
}

ostream &operator<<(ostream &os, TripInfo &info) {
    os << "id: " << info.id << " totalMeters: " << info.totalMeters
       << " start: " << info.getStartVal() << " end: " << info.getEndVal()
       << " numOfPassengers: " << info.numOfPassengers << " taarif: "
       << info.taarif;
    return os;
}