//
// Created by raz on 19/01/17.
//

#ifndef A_P1_THREADPOOL_H
#define A_P1_THREADPOOL_H

#include <vector>
#include "Thread.h"

using namespace std;

class ThreadPool {
private:
    int size;
    vector<pthread_t> threads;
    deque<TripInfo*> trips;
    pthread_mutex_t run_lock;

public:
    ThreadPool(int poolSize);

    virtual ~ThreadPool();

    static void* startRun(void* element);

    void executeThread();

    void addTrip(TripInfo *trip);
};


#endif //A_P1_THREADPOOL_H
