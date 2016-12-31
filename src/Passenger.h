//
// Created by raz on 29/11/16.
//

#ifndef A_P1_PASSENGER_H
#define A_P1_PASSENGER_H


#include <ostream>
#include <cstdlib>
#include "navigation/Point.h"
#include "navigation/Location.h"
#include "containers/PassengerContainer.h"

using namespace std;
using namespace boost::archive;

/**
 * a passenger class.
 */
class Passenger {
private:
    Location *source;
    Location *destination;
public:
    Passenger(Location *source, Location *destination);

    Passenger(PassengerContainer pc);

    Passenger();

    virtual ~Passenger();

    Location *getSource();

    Location *getDestination();

    void setSource(Location *source);

    void setDestination(Location *destination);

    int rate();

    PassengerContainer *getContainer();

    bool operator==(const Passenger &rhs) const;

    bool operator!=(const Passenger &rhs) const;

    friend ostream &operator<<(ostream &os, const Passenger &passenger);

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
        ar & source;
        ar & destination;
    }
};


#endif //A_P1_PASSENGER_H
