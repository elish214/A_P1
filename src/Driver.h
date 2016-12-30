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

using namespace std;
using namespace boost::archive;

/***
 * driver class.
 * this is a taxi driver.
 */
class Driver {
private:
    int id;
    int age;
    MaritalStatus status;
    int taxiID;
    int experience;
    Satisfaction satisfaction;
    Taxi *taxi;
    Location *location;
    vector<EndTripListener *> endTripListeners;
    bool availability;
    //vector<Node*> route;

public:
    Driver(int id, int age, MaritalStatus status, int taxiId);

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

    void moveOneStep();

    friend istream &operator>>(istream &is, Driver &driver);

    friend ostream &operator<<(ostream &os, const Driver &driver);

    friend class boost::serialization::access;

    /**
     * serialization implement.
     *
     * @tparam Archive a template.
     * @param ar an archive.
     * @param version an unsigned int.
     */
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & id;
        ar & age;
        ar & status;
        ar & taxiID;
        ar & experience;
        ar & satisfaction;
        ar & taxi;
        ar & location;
        //ar & endTripListeners;
        ar & availability;
    }
};


#endif //A_P1_DRIVER_H
