//
// Created by raz on 29/11/16.
//

#ifndef A_P1_SATISFACTIONLISTENER_H
#define A_P1_SATISFACTIONLISTENER_H


#include "EndTripListener.h"
#include "../Passenger.h"
#include "../Driver.h"

class SatisfactionListener : public EndTripListener {
private:
    Driver *driver;
    Passenger *passenger;
public:
    SatisfactionListener(Driver *driver, Passenger *passenger);

    void endEvent() override;
};


#endif //A_P1_SATISFACTIONLISTENER_H
