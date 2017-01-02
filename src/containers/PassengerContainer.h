//
// Created by raz on 30/12/16.
//

#ifndef A_P1_PASSENGERCONTAINER_H
#define A_P1_PASSENGERCONTAINER_H


#include "LocationContainer.h"

using namespace boost::archive;

/**
 * a passenger's container in order to send it to client.
 */
class PassengerContainer {
private:
    LocationContainer *source;
    LocationContainer *destination;
public:
    PassengerContainer(LocationContainer *source,
                       LocationContainer *destination);

    PassengerContainer();

    LocationContainer *getSource() const;

    LocationContainer *getDestination() const;

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


#endif //A_P1_PASSENGERCONTAINER_H
