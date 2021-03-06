//
// Created by raz on 29/11/16.
//

#include "TripInfo.h"
#include "navigation/Grid.h"
#include "navigation/BFS.h"
#include "validation/Checker.h"
#include "validation/Validator.h"
#include "validation/PositiveNumericChecker.h"
#include "validation/RangeNumericChecker.h"

#define ERROR -1

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
 *
 * @param id an integer.
 * @param numOfPassengers an integer.
 * @param passenger a passenger.
 * @param time a starting time.
 */
TripInfo::TripInfo(int id, int numOfPassengers, Passenger *passenger, int time)
        : id(id), numOfPassengers(numOfPassengers), passenger(passenger),
          time(time) {}

/**
 * constructor.
 */
TripInfo::TripInfo() : totalMeters(0) {
    //cout << "created" << endl;
    taarif = -1;
    calced = false;
    valid = true;
    start = NULL;
    end = NULL;
}

/**
 * constructor.
 *
 * @param route a vector.
 */
TripInfo::TripInfo(const vector<Node *> &route) : route(route) {
    start = new Location(-1, -1);
    end = new Location(-1, -1);
}

/**
 * constructor.
 *
 * @param tc trip container.
 */
TripInfo::TripInfo(TripContainer *tc) :
        id(tc->getId()), totalMeters(tc->getTotalMeters()),
        numOfPassengers(tc->getNumOfPassengers()),
        //passenger(new Passenger(*tc.getPassenger())), taarif(tc.getTaarif()),
        time(tc->getTime()) {

    start = new Location(tc->getSource());
    end = new Location(tc->getDestination());

    for (unsigned int i = 0; i < tc->getRoute().size(); ++i) {
        route.emplace_back(new Location(tc->getRoute().at(i)));
    }

    calced = true;

}

/**
 * destructor.
 */
TripInfo::~TripInfo() {
    //cout << id << " deleted" << endl;
    //delete passenger;
    if(start != NULL) {
        delete start;
    }
    if(end != NULL) {
        delete end;
    }
}

/**
 * for the use of the client to delete it's trip's route.
 */
void TripInfo::deleteRoute() {
    for (unsigned int i = 0; i < route.size(); i++) {
        delete route[i];
    }

    route.clear();
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

    //cout<< "calced!" << endl;
    //cout << isValid << endl;
    totalMeters = (int) route.size();

    /*
    for (int i = 0; i < route.size(); ++i) {
        cout << *route.at(i) << endl;
    }*/
}

/**
 * calculating trip's total meters.
 */
void TripInfo::calcPath() {
    //pthread_t thread;
    pthread_create(&thread, NULL, threadPath, (void *) this);
    //findPath();
}

/**
 * a static function for thread's operation.
 *
 * @param element an element.
 * @return void.
 */
void *TripInfo::threadPath(void *element) {
    TripInfo *t = (TripInfo *) element;

    t->findPath();
    t->setCalced(true);

    return NULL;
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
    bool valid;
    vector<Checker *> checkers;
    Validator v;

    checkers.emplace_back(new PositiveNumericChecker());
    checkers.emplace_back(new RangeNumericChecker(0, trip.getGrid()->getCols() - 1));
    checkers.emplace_back(new RangeNumericChecker(0, trip.getGrid()->getRows() - 1));
    checkers.emplace_back(new RangeNumericChecker(0, trip.getGrid()->getCols() - 1));
    checkers.emplace_back(new RangeNumericChecker(0, trip.getGrid()->getRows() - 1));
    checkers.emplace_back(new PositiveNumericChecker());
    checkers.emplace_back(new PositiveNumericChecker());
    checkers.emplace_back(new RangeNumericChecker(1, INT_MAX));

    is >> s;

    valid = v.validate(s, checkers, ',');

    for (unsigned int k = 0; k < checkers.size(); k++) {
        delete checkers[k];
    }

    checkers.clear();

    if (!valid) {
        trip.id = ERROR;
        //cout << trip.id << " get" << endl;
        return is;
    }

    istringstream ss(s);

    int x1, y1, x2, y2;

    getline(ss, s, ',');
    trip.id = stoi(s.c_str());

    getline(ss, s, ',');
    x1 = stoi(s.c_str());

    getline(ss, s, ',');
    y1 = stoi(s.c_str());

    if (trip.grid->get(x1, y1)->isObstacle()) {
        trip.id = ERROR;
        return is;
    }

    getline(ss, s, ',');
    x2 = stoi(s.c_str());


    getline(ss, s, ',');
    y2 = stoi(s.c_str());

    if (trip.grid->get(x2, y2)->isObstacle()) {
        trip.id = ERROR;
        return is;
    }

    if (x1 == x2 && y1 == y2) {
        trip.id = ERROR;
        return is;
    }

    trip.start = new Location(x1, y1);
    trip.end = new Location(x2, y2);

    getline(ss, s, ',');
    trip.numOfPassengers = stoi(s.c_str());

    getline(ss, s, ',');
    trip.taarif = stod(s.c_str());

    getline(ss, s, '\n');
    trip.time = stoi(s.c_str());

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

/**
 * returns object's container.
 *
 * @return  object's container.
 */
TripContainer *TripInfo::getContainer() {
    vector<LocationContainer *> r;

    for (unsigned int i = 0; i < route.size(); ++i) {
        r.emplace_back(route.at(i)->getContainer());
    }

    return new TripContainer(id, totalMeters, numOfPassengers, taarif,
                             start->getContainer(), end->getContainer(),
                             r, time);
}

/**
 * set trip's route.
 *
 * @param route a route.
 */
void TripInfo::setRoute(const vector<Node *> &route) {
    TripInfo::route = route;
}

/**
 * returns trip's time.
 *
 * @return trip's time.
 */
int TripInfo::getTime() const {
    return time;
}

/**
 * initial passengers.
 */
void TripInfo::initPassenger() {
    passenger = new Passenger(new Location(start), new Location(end));
}

/**
 * returns if route has been calculated.
 *
 * @return whether route has been calculated or not.
 */
bool TripInfo::isCalced() const {
    return calced;
}

/**
 * setting a flag.
 *
 * @param calced a status.
 */
void TripInfo::setCalced(bool calced) {
    TripInfo::calced = calced;
}

/**
 * returns trip's thread.
 *
 * @return trip's thread.
 */
pthread_t TripInfo::getThread() const {
    return thread;
}

/**
 * returns whether trip is valid or not.
 *
 * @return whether trip is valid or not.
 */
bool TripInfo::isValid() const {
    return valid;
}

/**
 * setting validation.
 *
 * @param valid a bool.
 */
void TripInfo::setValid(bool valid) {
    TripInfo::valid = valid;
}
