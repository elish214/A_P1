//
// Created by raz on 16/01/17.
//

#ifndef A_P1_NEWDRIVERCONTAINER_H
#define A_P1_NEWDRIVERCONTAINER_H


#include "../Driver.h"

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
};


#endif //A_P1_NEWDRIVERCONTAINER_H
