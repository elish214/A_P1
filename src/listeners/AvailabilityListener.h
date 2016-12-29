//
// Created by raz on 29/11/16.
//

#ifndef A_P1_AVAILABILITYLISTENER_H
#define A_P1_AVAILABILITYLISTENER_H


#include "EndTripListener.h"
#include "../Driver.h"

using namespace std;
using namespace boost::archive;

/**
 * availability listener.
 * uses to announce taxi center who's available for a ride.
 */
class AvailabilityListener : public EndTripListener {
private:
    Driver *driver;
public:
    AvailabilityListener(Driver *driver);

    void endEvent();

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
        ar & boost::serialization::base_object<EndTripListener>(*this);
        ar & driver;
    }
};


#endif //A_P1_AVAILABILITYLISTENER_H
