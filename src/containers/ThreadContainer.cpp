//
// Created by elish on 15/01/17.
//

#include "ThreadContainer.h"

/**
 * constructor.
 */
ThreadContainer::ThreadContainer() {}

/**
 * destructor.
 */
ThreadContainer::~ThreadContainer() {}

/**
 * returns container's thread.
 *
 * @return container's thread.
 */
pthread_t* ThreadContainer::getThread() {
    return &thread;
}
