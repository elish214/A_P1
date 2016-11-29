//
// Created by raz on 29/11/16.
//

#ifndef A_P1_SATISFACTIONLISTENER_H
#define A_P1_SATISFACTIONLISTENER_H


#include "EndTripListener.h"
#include "Passenger.h"

class SatisfactionListener : public EndTripListener {
private:
    //driver
    Passenger passenger;
public:
    void endEvent() override;
};


#endif //A_P1_SATISFACTIONLISTENER_H
