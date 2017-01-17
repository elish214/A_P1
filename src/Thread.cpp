//
// Created by raz on 17/01/17.
//

#include "Thread.h"

Thread::Thread(Driver *driver, int descriptor) : driver(driver), descriptor(descriptor), localClock(0) {}

Thread::~Thread() {

}

pthread_t *Thread::getThread() {
    return &pthread;
}

Driver *Thread::getDriver() const {
    return driver;
}

int Thread::getDescriptor() const {
    return descriptor;
}

int Thread::getLocalClock() const {
    return localClock;
}

void Thread::incClock() {
    localClock++;
}
