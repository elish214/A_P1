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

/**
 * destructor.
 */
TaxiCenter::~TaxiCenter() {

    for (unsigned int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }

    for (unsigned int j = 0; j < cabs.size(); j++) {
        delete cabs[j];
    }

    for (unsigned int k = 0; k < trips.size(); k++) {
        delete trips[k];
    }

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
vector<TripInfo *> &TaxiCenter::getTrips() {
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
        if (t->getId() == i) {
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

    return TripInfo(0, 0, new Passenger(l1, l2));
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
        trips.erase(trips.begin());
        driver = pop(*trip->getStart()->getPoint());
        //driver.setRoute(trip->getRoute());
        driver->setLocation(trip->getEnd());
        driver->setExperience(driver->getExperience() + 1);
        push(driver);
        availableDrivers--;
        delete trip;
    }

    //cout << "  V V V" << endl;
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

    //cout << "here " << *driver << endl;
    if (it == locations.end()) {
        deque<Driver *> d;
        d.emplace_back(driver);
        locations.insert(make_pair(*driver->getLocation()->getPoint(), d));
    } else {
        if(!isDriverIn(driver)) {
            it->second.emplace_back(driver);
        }
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

/**
 * advance all taxi center's drivers one step.
 */
void TaxiCenter::advanceAllDrivers() {
    Driver *d;
    for (unsigned int i = 0; i < employees.size(); i++) {
        d = employees.at(i);
        //d->moveOneStep();

    }
}

/**
 * returns how many trips are assigned at a specific time.
 *
 * @param time a specific time.
 * @return an integer.
 */
int TaxiCenter::numOfTripsAt(int time) {
    int count = 0;

    for (unsigned int i = 0; i < trips.size(); ++i) {
        if (trips.at(i)->getTime() == time) {
            count++;
        }
    }

    return count;
}

int TaxiCenter::numOfTripsAt(int time, Point *start) {
    int count = 0;

    for (unsigned int i = 0; i < trips.size(); ++i) {
        if ((trips[i]->getTime() == time) && (*trips[i]->getStart()->getPoint() == *start)) {
            count++;
        }
    }

    return count;
}

/**
 * returns a trip that assigned to the specific time.
 *
 * @param time a specific time.
 * @return a trip.
 */
TripInfo *TaxiCenter::getTripAt(int time) {
    TripInfo *trip = NULL;

    for (unsigned int i = 0; i < trips.size(); ++i) {
        if (trips.at(i)->getTime() == time) {
            trip = trips.at(i);
            //trips.erase(trips.begin() + i);
            break;
        }
    }

    return trip;
}

TripInfo *TaxiCenter::getTripAt(int time, Point *start) {
    TripInfo *trip;

    for (unsigned int i = 0; i < trips.size(); ++i) {
        trip = trips.at(i);

        if ((trip->getTime() == time) && (*trip->getStart()->getPoint() == *start)) {
            trips.erase(trips.begin() + i);
            return trip;
        }
    }


    return NULL;
}

int TaxiCenter::getTurn(Driver *driver) {
    map<Point, deque<Driver *>>::iterator it = locations.find(*driver->getLocation()->getPoint());

    for (unsigned int i = 0; i < it->second.size(); ++i) {
        if(*driver == *it->second.at(i)) {
            //cout << *driver << " turn: " << i+1 << endl;
            return i + 1;
        }
    }

    return -1;
}

TripInfo *TaxiCenter::getTripAt(int time, Driver *driver) {
    TripInfo *trip;
    int numOfTrips = numOfTripsAt(time, driver->getLocation()->getPoint());
    int turn = getTurn(driver);

    //cout << driver->getId() << " " << turn << " : " << numOfTrips << endl;

    if(turn > numOfTrips) {
        return NULL;
    }

    for (unsigned int i = 0; i < trips.size(); ++i) {
        trip = trips.at(i);

        if ((trip->getTime() == time) && *trip->getStart()->getPoint() == *driver->getLocation()->getPoint()) {
            if (turn == 1) {
                trips.erase(trips.begin() + i);
                return trip;
            }
            turn--;
        }
    }

    return NULL;
}

void TaxiCenter::eraseDriver(Driver *driver) {
    map<Point, deque<Driver *>>::iterator it = locations.find(*driver->getLocation()->getPoint());
    Driver* temp;
    for (unsigned int i = 0; i < it->second.size(); ++i) {
        temp = it->second.at(0);
        if (*driver == *temp) {
            it->second.erase(it->second.begin() + i);
            break;
        }
    }

    cout << "DEQUEEEEEEEEEEEEEEEE: ";
    for (unsigned int j = 0; j < it->second.size(); ++j) {
        cout << it->second.at(j)->getId() << " ";
    }
    cout << endl;

}

bool TaxiCenter::isDriverIn(Driver *driver) {
    map<Point, deque<Driver *>>::iterator it = locations.find(*driver->getLocation()->getPoint());

    for (unsigned int i = 0; i < it->second.size(); ++i) {
        if(*driver == *it->second.at(i)) {
            return true;
        }
    }

    return false;
}

map<Point, deque<Driver *>> &TaxiCenter::getLocations() {
    return locations;
}
