//
// Created by raz on 29/11/16.
//

#include "SatisfactionListener.h"
//BOOST_CLASS_EXPORT(SatisfactionListener)


/**
 * constructor.
 */
SatisfactionListener::SatisfactionListener() {}

/**
 * constructor.
 *
 * @param driver a driver .
 * @param passenger a passenger.
 */
SatisfactionListener::SatisfactionListener(Driver *driver, Passenger *passenger)
        : driver(driver), passenger(passenger) {}

/**
 * announce the satisfaction of passenger.
 */
void SatisfactionListener::endEvent() {

}
