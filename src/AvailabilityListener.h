//
// Created by raz on 29/11/16.
//

#ifndef A_P1_AVAILABILITYLISTENER_H
#define A_P1_AVAILABILITYLISTENER_H


#include "EndTripListener.h"

class AvailabilityListener : public EndTripListener {
private:
    //driver
    //center
public:
    void endEvent() override;

};


#endif //A_P1_AVAILABILITYLISTENER_H
