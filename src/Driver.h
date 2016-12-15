//
// Created by raz on 29/11/16.
//

#ifndef A_P1_DRIVER_H
#define A_P1_DRIVER_H


#include <ostream>
#include "enums/MaritalStatus.h"
#include "Satisfaction.h"
#include "navigation/Location.h"
#include "listeners/EndTripListener.h"
#include "TripInfo.h"
#include "taxi/Taxi.h"

/***
 * driver class.
 * this is a taxi driver.
 */
class Driver {
private:
    int id;
    int age;
    MaritalStatus status;
    int experience;
    Satisfaction satisfaction;
    Taxi *taxi;
    int taxiID;
    Location *location;
    vector<EndTripListener *> endTripListeners;
    bool availability;

public:
    Driver(int id, int age, MaritalStatus status);

    Driver();

    virtual ~Driver();

    int getId() const;

    const Location *getLocation() const;

    void setLocation(Location *location);

    Taxi *getTaxi() const;

    void setExperience(int experience);

    int getExperience();

    void setTaxi(Taxi *taxi);

    void start(TripInfo trip);

    void drive(vector<Location*>);

    double getSatisfaction();

    int getTaxiID() const;

    bool isAvailability() const;

    void setAvailability(bool availability);

    void notifyAllEndTrip();

    void addListener(EndTripListener *listener);

    void removeListener(EndTripListener *listener);

    friend istream &operator>>(istream &is, Driver &driver);

    friend ostream &operator<<(ostream &os, const Driver &driver);
};


#endif //A_P1_DRIVER_H
