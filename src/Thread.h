//
// Created by raz on 17/01/17.
//

#ifndef A_P1_THREAD_H
#define A_P1_THREAD_H


#include <sys/types.h>
#include "Driver.h"

/**
 * thread representing class.
 */
class Thread {
private:
    pthread_t pthread;
    Driver *driver;
    int descriptor;
    int localClock;

public:
    Thread(Driver *driver, int descriptor);

    virtual ~Thread();

    pthread_t *getThread();

    Driver *getDriver() const;

    int getDescriptor() const;

    int getLocalClock() const;

    void incClock();
};


#endif //A_P1_THREAD_H
