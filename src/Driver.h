//
// Created by raz on 29/11/16.
//

#ifndef A_P1_DRIVER_H
#define A_P1_DRIVER_H


#include "MaritalStatus.h"
#include "Satisfaction.h"
#include "Location.h"
#include "EndTripListener.h"

class Driver {
private:
    int id;
    int age;
    MaritalStatus status;
    int experience;
    Satisfaction satisfaction;
    //taxi
    Location location;
    vector<EndTripListener> endTripListeners;
public:

};


#endif //A_P1_DRIVER_H
