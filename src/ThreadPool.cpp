//
// Created by raz on 19/01/17.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(int poolSize) {
    size = poolSize;

    for (int i = 0; i < poolSize; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, startRun, (void*) this);
    }
    cout << "cool" << endl;
    pthread_mutex_init(&run_lock, 0);
}

ThreadPool::~ThreadPool() {
    for (int j = 0; j < size; j++) {
        pthread_join(threads.at(j), NULL);
    }

    pthread_mutex_destroy(&run_lock);
}

void *ThreadPool::startRun(void *element) {
    ThreadPool *tp = (ThreadPool*) element;
    cout << "cool2" << endl;
    tp->executeThread();

    return NULL;
}

void ThreadPool::executeThread() {
    TripInfo *t = NULL;
    while (true){
        while (trips.empty()) {
            //cout << "waiting" << endl;
            sleep(1);
        }
        pthread_mutex_lock(&run_lock);
        t = trips.front();
        trips.pop_front();
        pthread_mutex_unlock(&run_lock);

        t->findPath();
        t->setCalced(true);

    }
    
}

void ThreadPool::addTrip(TripInfo *trip) {
    trips.push_back(trip);
}


