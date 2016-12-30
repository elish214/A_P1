//
// Created by raz on 29/11/16.
//

#include "AvailabilityListener.h"
BOOST_CLASS_EXPORT(AvailabilityListener)

/**
 * constructor.
 */
AvailabilityListener::AvailabilityListener() {}

/**
 * constructor.
 *
 * @param driver a driver.
 */
AvailabilityListener::AvailabilityListener(Driver *driver) : driver(driver) {}

/**
 * announce availability.
 */
void AvailabilityListener::endEvent() {

}

