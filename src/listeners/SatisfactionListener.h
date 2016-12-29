//
// Created by raz on 29/11/16.
//

#ifndef A_P1_SATISFACTIONLISTENER_H
#define A_P1_SATISFACTIONLISTENER_H


#include "EndTripListener.h"
#include "../Passenger.h"
#include "../Driver.h"

using namespace std;
using namespace boost::archive;

/**
 * satisfaction listener class.
 * uses to announce the satisfaction of the passenger of trip.
 */
class SatisfactionListener : public EndTripListener {
private:
    Driver *driver;
    Passenger *passenger;
public:
    SatisfactionListener(Driver *driver, Passenger *passenger);

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
        ar & passenger;
    }
};


#endif //A_P1_SATISFACTIONLISTENER_H
