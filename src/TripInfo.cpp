//
// Created by raz on 29/11/16.
//

#include "TripInfo.h"
#include "navigation/Grid.h"
#include "navigation/BFS.h"

/**
 * constructor.
 *
 * @param id an integer.
 * @param numOfPassengers number of passenger.
 * @param passenger a passenger.
 */
TripInfo::TripInfo(int id, int numOfPassengers, Passenger *passenger) :
        id(id), totalMeters(0), start(passenger->getSource()),
        end(passenger->getDestination()),
        numOfPassengers(numOfPassengers), passenger(passenger) {
    totalMeters = -1;
    taarif = -1;
}

/**
 * constructor.
 */
TripInfo::TripInfo() : totalMeters(0) {
    totalMeters = -1;
    taarif = -1;
}

/**
 * returns trip's grid.
 *
 * @return trip's grid.
 */
Grid *TripInfo::getGrid() const {
    return grid;
}

/**
 * setting trip's grid.
 *
 * @param g a grid.
 */
void TripInfo::setGrid(Grid *g) {
    TripInfo::grid = g;

    //Location *s = g->get(*start->getPoint());
    //Location *e = g->get(*end->getPoint());
//
    ////delete start;
    ////delete end;
//
    //start = s;
    //end = e;

}

TripInfo::~TripInfo() {
    delete passenger;
}

/**
 * returns trip's ID.
 *
 * @return trip's ID.
 */
int TripInfo::getId() const {
    return id;
}

/**
 * returns trip's total meters.
 *
 * @return trip's total meters.
 */
int TripInfo::getTotalMeters() const {
    return totalMeters;
}

/**
 * finding the best path for trip.
 */
void TripInfo::findPath() {
    BFS bfs;
    route = bfs.run(grid->get(*start->getPoint()), grid->get(*end->getPoint()));
}

/**
 * calculating trip's total meters.
 */
void TripInfo::calcMeters() {
    findPath();
    for (unsigned int i = 0; i < route.size(); i++) {
        totalMeters += 1;
    }
}

/**
 * returns trip's route.
 *
 * @return trip's route.
 */
vector<Node *> TripInfo::getRoute() {
    return route;
}

/**
 * returns trip's starting location.
 *
 * @return trip's starting location.
 */
Location *TripInfo::getStart() {
    return start;
}

/**
 * returns trip's starting location value.
 *
 * @return trip's starting location value.
 */
Location TripInfo::getStartVal() {
    return *start;
}

/**
 * returns trip's ending location.
 *
 * @return trip's ending location.
 */
Location *TripInfo::getEnd() {
    return end;
}

/**
 * returns trip's ending location value.
 *
 * @return trip's ending location value.
 */
Location TripInfo::getEndVal() {
    return *end;
}

/**
 * returns trip's number of passengers.
 *
 * @return trip's number of passengers.
 */
int TripInfo::getNumOfPassengers() const {
    return numOfPassengers;
}

/**
 * returns trip's taarif.
 *
 * @return trip's taarif.
 */
double TripInfo::getTaarif() const {
    return taarif;
}

/**
 * returns trip's passenger.
 *
 * @return trip's passenger.
 */
Passenger *TripInfo::getPassenger() const {
    return passenger;
}

/**
 * method overloading for operator '>>'.
 *
 * @param is input stream.
 * @param trip a tripInfo.
 * @return input stream.
 */
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

    getline(is, s, ',');
    trip.taarif = stod(s.c_str());

    getline(is, s, '\n');
    trip.time = atoi(s.c_str());

    return is;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param info a tripInfo.
 * @return output stream.
 */
ostream &operator<<(ostream &os, TripInfo &info) {
    os << "id: " << info.id << " totalMeters: " << info.totalMeters
       << " start: " << info.getStartVal() << " end: " << info.getEndVal()
       << " numOfPassengers: " << info.numOfPassengers << " taarif: "
       << info.taarif << " time: " << info.time;
    return os;
}

TripInfo::TripInfo(TripContainer tc) :
        id(tc.getId()), totalMeters(tc.getTotalMeters()),
        start(new Location(*tc.getSource())),
        end(new Location(*tc.getDestination())),
        numOfPassengers(tc.getNumOfPassengers()),
        //passenger(new Passenger(*tc.getPassenger())), taarif(tc.getTaarif()),
        time(tc.getTime()) {

    for (unsigned int i = 0; i < tc.getRoute().size(); ++i) {
        route.emplace_back(new Location(*tc.getRoute().at(i)));
    }

}

TripContainer *TripInfo::getContainer() {
    vector<LocationContainer *> r;

    for (unsigned int i = 0; i < route.size(); ++i) {
        r.emplace_back(route.at(i)->getContainer());
    }

    return new TripContainer(id, totalMeters, numOfPassengers, taarif,
                             start->getContainer(), end->getContainer(),
                             r, time);
}

void TripInfo::setRoute(const vector<Node *> &route) {
    TripInfo::route = route;
}

TripInfo::TripInfo(int id, int numOfPassengers, Passenger *passenger, int time)
        : id(id), numOfPassengers(numOfPassengers), passenger(passenger),
          time(time) {}

int TripInfo::getTime() const {
    return time;
}

void TripInfo::initPassenger() {
    passenger = new Passenger(new Location(start), new Location(end));
}
