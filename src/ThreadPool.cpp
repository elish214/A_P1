//
// Created by raz on 19/01/17.
//

#include "ThreadPool.h"

/**
 * constructor.
 *
 * @param poolSize an integer.
 */
ThreadPool::ThreadPool(int poolSize) {
    size = poolSize;

    for (int i = 0; i < poolSize; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, startRun, (void *) this);
        threads.push_back(thread);
    }
    pthread_mutex_init(&run_lock, 0);
}

/**
 * destructor.
 */
ThreadPool::~ThreadPool() {
    for (int j = 0; j < size; j++) {
        pthread_cancel(threads.at(j));
        //cout << "dead" << endl;
    }

    pthread_mutex_destroy(&run_lock);
}

/**
 * thread's start.
 *
 * @param element an element.
 * @return void.
 */
void *ThreadPool::startRun(void *element) {
    ThreadPool *tp = (ThreadPool *) element;
    tp->executeThread();

    return NULL;
}

/**
 * thread's run.
 */
void ThreadPool::executeThread() {
    TripInfo *t = NULL;
    while (true) {
        pthread_mutex_lock(&run_lock);

        while (trips.empty()) {
            usleep(100);
        }

        t = trips.front();
        trips.pop_front();

        pthread_mutex_unlock(&run_lock);

        //cout << t->getId() << endl;
        t->findPath();
        //cout << "S:" << t->getRoute().size() << endl;

        if (*t->getStart() != *t->getEnd() && t->getRoute().size() == 1) {
            t->setValid(false);
        } else {
            t->setValid(true);
        }


        t->setCalced(true);
    }
}

/**
 * adding trip to threadpool's deque.
 *
 * @param trip a trip info.
 */
void ThreadPool::addTrip(TripInfo *trip) {
    trips.push_back(trip);
}
