//
// Created by raz on 16/01/17.
//

#ifndef A_P1_THREADCONTAINER_H
#define A_P1_THREADCONTAINER_H


#include <sys/types.h>

class ThreadContainer {
private:
    pthread_t thread;

public:
    ThreadContainer();

    virtual ~ThreadContainer();

    pthread_t* getThread();
};


#endif //A_P1_THREADCONTAINER_H
