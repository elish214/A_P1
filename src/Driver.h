//
// Created by raz on 29/11/16.
//

#ifndef A_P1_DRIVER_H
#define A_P1_DRIVER_H


#include "enums/MaritalStatus.h"
#include "Satisfaction.h"
#include "navigation/Location.h"
#include "listeners/EndTripListener.h"
#include "TripInfo.h"
#include "taxi/Taxi.h"

class Driver {
private:
    int id;
    int age;
    MaritalStatus status;
    int experience;
    Satisfaction satisfaction;

private:
    Taxi *taxi;
    Location location;
    vector<EndTripListener *> endTripListeners;
    bool availability;
public:
    Driver(int id, int age, MaritalStatus status);

    const Location &getLocation() const;

    void setLocation(const Location &location);

    Taxi *getTaxi() const;

    void setTaxi(Taxi *taxi);

    void start(TripInfo trip);

    void drive(vector<Location*>);

    double getSatisfaction() const;

    bool isAvailability() const;

    void setAvailability(bool availability);

    void notifyAllEndTrip();

    void addListener(EndTripListener *listener);

    void removeListener(EndTripListener *listener);
};


#endif //A_P1_DRIVER_H
