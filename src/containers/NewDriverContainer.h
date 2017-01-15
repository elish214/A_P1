//
// Created by elish on 14/01/17.
//

#ifndef A_P1_NEWDRIVERCONTAINER_H
#define A_P1_NEWDRIVERCONTAINER_H


#include "../Driver.h"

/**
 * a new driver container class
 * using to pass to new thread's handling.
 */
class NewDriverContainer {
private:
    Driver* driver;
    int joiningTime;
    int descriptor;

public:
    NewDriverContainer(Driver* driver, int joiningTime, int descriptor);

    virtual ~NewDriverContainer();

    Driver* getDriver();

    int getJoiningTime();

    int getDescriptor();

    void setDriverLocation(Location* location);

    void setDriverAvailablity(bool isAvailable);
};


#endif //A_P1_NEWDRIVERCONTAINER_H
