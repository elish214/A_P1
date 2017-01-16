//
// Created by raz on 14/11/16.
//

#include <iostream>
#include "navigation/Grid.h"
#include "Driver.h"
#include "sockets/Udp.h"
#include "sockets/Connection.h"
#include "taxi/StandardTaxi.h"
#include "enums/Operation.h"
#include "containers/Command.h"
#include "TaxiCenter.h"
#include "taxi/TaxiFactory.h"
#include "sockets/Tcp.h"
#include "containers/NewDriverContainer.h"
#include "containers/ThreadContainer.h"

using namespace std;

int systemClock = 0;
int timeClock = 0;
int sock;
TaxiCenter center;
Command *command;
int threadsCounter = 0;
int finished = 0;

pthread_mutex_t trip_locker;
pthread_mutex_t _locker;
pthread_mutex_t end_thread;

static void *threadRun(void *element);

/**
 * entry point.
 *
 * @return 0.
 */
int main(int argc, char *argv[]) {
    sock = atoi(argv[1]);
    char buffer[130000];

    vector<ThreadContainer *> threads;
    ThreadContainer *thread;

    Grid *grid;
    center = TaxiCenter();
    Driver *driver;
    DriverContainer *dc;
    NewDriverContainer *ndc;
    TripInfo *trip;
    Point point = Point(-1, -1);
    TaxiFactory factory;
    Taxi *taxi;
    bool isRunning = true;
    int opNum, numOfObstacles, id, numOfDrivers, descriptor;
    Operation op;
    command = new Command();
    //Node *node;
    LocationContainer *lc;
    TripContainer *tc;
    Location *location;
    int rows, cols;
    //Socket *socket = new Udp(1, sock);
    Socket *socket = new Tcp(1, sock);
    Connection con = Connection(socket);
    con.initialize();

    cin >> rows >> cols;
    grid = new Grid(rows, cols);
    cin >> numOfObstacles;
    for (int j = 0; j < numOfObstacles; ++j) {
        cin >> point;
        grid->get(point)->setObstacle(true);
    }
    /*
    cout << "-----------------------" << endl
         << "GRID: " << *grid << endl
         << "-----------------------" << endl;
    */

    do {
        //operation
        cin >> opNum;
        op = static_cast<Operation>(opNum);
        command->setOp(op);
        cout << "alive" << endl;
        cout << *command << endl;

        switch (op) {
            case Operation::NEW_DRIVER:
                cin >> numOfDrivers;
                cout << "waiting for drivers" << endl;
                for (int j = 0; j < numOfDrivers; ++j) {
                    descriptor = con.accept();
                    dc = con.receive<DriverContainer>();

                    driver = new Driver(*dc);
                    driver->setLocation(grid->get(0, 0));
                    center.addDriver(driver);

                    delete dc;
                    //assign a taxi and send it back.
                    taxi = center.getTaxi(driver->getTaxiID());
                    driver->setTaxi(taxi);
                    //con.receiveString(buffer);
                    con.send(taxi);
                    con.receiveString(buffer);
                    //cout << "got driver: " << *driver << endl;
                    //cout << "sent taxi: " << *taxi << endl;
                    thread = new ThreadContainer();
                    //pthread_t pthread;
                    cout << *driver << " threads.. " << endl;
                    ndc = new NewDriverContainer(driver, timeClock, descriptor);
                    //pthread_create(&pthread, NULL, threadRun, (void *) ndc);
                    pthread_create(thread->getThread(), NULL, threadRun, (void *) ndc);
                    threads.push_back(thread);

                    cout << "ok" << endl;
                    threadsCounter++;
                }
                break;
            case Operation::NEW_RIDE:
                //   cout << "new ride" << endl;
                trip = new TripInfo();
                cin >> *trip;
                trip->setGrid(grid);
                //trip->initPassenger();
                //trip->getStart()->setGrid(grid);
                //trip->getEnd()->setGrid(grid);
                trip->calcPath();
                center.addTrip(trip);
                cout << "alive trip" << endl;
                break;
            case Operation::NEW_VEHICLE:
                //   cout << "new vehicle" << endl;

                cin >> factory;
                center.addTaxi(factory.getTaxi());
                cout << "alive taxi" << endl;
                break;
            case Operation::DRIVER_LOCATION:
                //   cout << "driver location" << endl;

                cin >> id;
                //cout << *(center.getDriver(id)->getLocation()) << endl;
                cout << "alive before" << endl;

                cout << *center.getDriver(id)->getLocation() << endl;

                //delete lc;
                //delete location;
                break;
            case Operation::START:
                //   cout << "start" << endl;
                //center.start();
                break;

            case Operation::ADVANCE:
                //center.advanceAllDrivers();
                cout << "advance" << endl;

                timeClock++;
;
                //cout << clock << " : " << *location << endl;
                break;

            case Operation::EXIT:
                //cout << *command << endl;
                //con.send(command);

                timeClock++;
                isRunning = false;

                for (int k = 0; k < threads.size(); ++k) {
                    pthread_join(*threads.at(k)->getThread(), NULL);
                }
                break;
        }
        /*
        cout << "-----------------------" << endl
             << "CENTER:" << endl << center << endl
             << "-----------------------" << endl;
        */
    } while (isRunning);

    delete grid;
    delete command;

    return 0;
}


/**
 * threads operation.
 *
 * @param element an element.
 * @return NULL.
 */
void *threadRun(void *element) {
    NewDriverContainer *ndc = (NewDriverContainer *) element;

    //cout << *ndc->getDriver() << endl;

    bool isRunning = true;
    int localClock = ndc->getJoiningTime();
    char buffer[130000];

    Command *localCommand;
    LocationContainer *lc;
    Location *location;
    TripContainer *tc;
    TripInfo *trip;

    Socket *socket = new Tcp(1, sock);
    cout << "alive thread" << endl;
    Connection con = Connection(socket);
    con.setDescriptor(ndc->getDescriptor());
    cout << "alive thread 2" << endl;

    do {
        while (localClock == timeClock) {
            //cout << localClock << " : " << timeClock << endl;
            sleep(1);
        }

        localClock++;
        cout << "localClock: " << localClock << endl;
        cout << ndc->getDriver()->getId() << "  "
             << *ndc->getDriver()->getLocation() << endl;

        localCommand = command;
        switch (localCommand->getOp()) {
            case Operation::ADVANCE:
                //center.advanceAllDrivers();
                cout << "advance" << endl;
                if(ndc->getDriver()->isAvailability()) {
                    pthread_mutex_lock(&trip_locker);
                    trip = center.getTripAt(timeClock,
                                            ndc->getDriver()->getLocation()->getPoint());
                    //cout << ndc->getDriver()->getId() << *trip << endl;
                    pthread_mutex_unlock(&trip_locker);

                    if (trip != NULL) {
                        localCommand->setOp(Operation::NEW_RIDE);
                        cout << "sending " << *localCommand << endl;

                        con.send(localCommand);

                        cout << "sent command" << endl;

                        pthread_join(trip->getThread(),NULL);
                        tc = trip->getContainer();
                        cout << "send trip" << endl;

                        con.receiveString(buffer);

                        cout << *trip << endl;

                        con.send(tc);

                        cout << "sent it" << endl;
                        delete tc;

                        con.receiveString(buffer);
                        ndc->setDriverAvailablity(false);
                        //cout << ndc->getDriver()->getId() << "  "
                        //     << *ndc->getDriver()->getLocation() << endl;
                    }
                } else {

                    //timeClock++;
                    cout << *localCommand << endl;
                    con.send(localCommand);
                    cout << "sent command advance" << endl;
                    lc = con.receive<LocationContainer>();
                    cout << "alive again" << endl;
                    location = new Location(lc);

                    cout << *location << endl;
                    //driver->setLocation(location);
                    ndc->setDriverLocation(location);
                    cout << ndc->getDriver()->getId() << "  "
                         << *ndc->getDriver()->getLocation() << endl;
                    delete lc;

                    //lc = con.receive<LocationContainer>();
                    //location = new Location(lc);
                    //cout << clock << " : " << *location << endl;
                }
                break;

            case Operation::EXIT:
                //cout << *command << endl;
                delete ndc;
                con.send(localCommand);
                isRunning = false;

                break;

            default:
                break;
        }

        /*
        cout << "-----------------------" << endl
             << "CENTER:" << endl << center << endl
             << "-----------------------" << endl;
        */
    } while (isRunning);

    return NULL;
}
