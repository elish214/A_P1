//
// Created by raz on 30/12/16.
//

#ifndef A_P1_TRIPCONTAINER_H
#define A_P1_TRIPCONTAINER_H

#include <boost/serialization/vector.hpp>
#include "PassengerContainer.h"
#include "../navigation/Node.h"

using namespace boost::archive;

class TripContainer {
private:
    int id;
    int totalMeters;
    int numOfPassengers;
    double taarif;
    PassengerContainer *passenger;
    vector<LocationContainer *> route;
    int time;
public:
    TripContainer(int id, int totalMeters, int numOfPassengers,
                  double taarif, PassengerContainer *passenger,
                  const vector<LocationContainer *> &route,
                  int time);

    TripContainer();

    int getId() const;

    int getTotalMeters() const;

    int getNumOfPassengers() const;

    double getTaarif() const;

    const PassengerContainer *getPassenger() const;

    const vector<LocationContainer *> &getRoute() const;

    int getTime() const;

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
        ar & totalMeters;
        ar & numOfPassengers;
        ar & taarif;
        ar & passenger;
        ar & route;
        ar & time;
    }
};


#endif //A_P1_TRIPCONTAINER_H
