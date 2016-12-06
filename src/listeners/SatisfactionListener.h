//
// Created by raz on 29/11/16.
//

#ifndef A_P1_SATISFACTIONLISTENER_H
#define A_P1_SATISFACTIONLISTENER_H


#include "EndTripListener.h"
#include "../Passenger.h"
#include "../Driver.h"

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
};


#endif //A_P1_SATISFACTIONLISTENER_H
