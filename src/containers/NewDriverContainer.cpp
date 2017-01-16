//
// Created by raz on 16/01/17.
//

#include "NewDriverContainer.h"

/**
 * constructor.
 *
 * @param driver a driver.
 * @param joiningTime a time.
 * @param descriptor an integer.
 */
NewDriverContainer::NewDriverContainer(Driver* driver, int joiningTime, int descriptor)
        : driver(driver), joiningTime(joiningTime), descriptor(descriptor) {}

/**
 * destructor.
 */
NewDriverContainer::~NewDriverContainer() {}

/**
 * returns container's driver.
 *
 * @return container's driver.
 */
Driver* NewDriverContainer::getDriver() {
    return driver;
}

/**
 * returns container's driver's joining time.
 *
 * @return container's driver's joining time.
 */
int NewDriverContainer::getJoiningTime() {
    return joiningTime;
}

/**
 * returns container's driver's descriptor.
 *
 * @return container's driver's descriptor.
 */
int NewDriverContainer::getDescriptor() {
    return descriptor;
}

