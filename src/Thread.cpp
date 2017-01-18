//
// Created by raz on 17/01/17.
//

#include "Thread.h"

/**
 * constructor.
 *
 * @param driver a driver.
 * @param descriptor an integer.
 */
Thread::Thread(Driver *driver, int descriptor) : driver(driver), descriptor(descriptor), localClock(0) {}

/**
 * destructor.
 */
Thread::~Thread() {}

/**
 * returns the thread.
 *
 * @return the thread.
 */
pthread_t *Thread::getThread() {
    return &pthread;
}

/**
 * returns driver.
 *
 * @return driver.
 */
Driver *Thread::getDriver() const {
    return driver;
}

/**
 * returns descriptor.
 *
 * @return descriptor.
 */
int Thread::getDescriptor() const {
    return descriptor;
}

/**
 * returns local clock.
 *
 * @return local clock.
 */
int Thread::getLocalClock() const {
    return localClock;
}

/**
 * incrementing clock.
 */
void Thread::incClock() {
    localClock++;
}
