//
// Created by raz on 29/11/16.
//

#ifndef A_P1_AVAILABILITYLISTENER_H
#define A_P1_AVAILABILITYLISTENER_H


#include "EndTripListener.h"
#include "../Driver.h"

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

};


#endif //A_P1_AVAILABILITYLISTENER_H
