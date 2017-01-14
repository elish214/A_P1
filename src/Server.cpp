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

using namespace std;

int systemClock = 0;
int timeClock = 0;
int sock;
TaxiCenter center;
Command *command;
int threads = 0;
int finished = 0;

pthread_mutex_t trip_locker;
pthread_mutex_t _locker;

static void *threadRun(void *element);

/**
 * entry point.
 *
 * @return 0.
 */
int main(int argc, char *argv[]) {
    sock = atoi(argv[1]);
    char buffer[1024];

    Grid *grid;
    center = TaxiCenter();
    Driver *driver;
    DriverContainer *dc;
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
    cout << "alive" << endl;
    int rows, cols;
    //Socket *socket = new Udp(1, sock);
    Socket *socket = new Tcp(1, sock);
    cout << "alive" << endl;
    Connection con = Connection(socket);
    cout << "alive" << endl;
    con.initialize();
    cout << "alive1" << endl;


    //Driver *d1 = new Driver(0, 15, MaritalStatus::MARRIED, 5, 0);
    //Driver *d2 = new Driver(1, 54, MaritalStatus::DIVORCED, 2, 1);
//
    //systemClock = 0;
//
    //pthread_mutex_init(&locker, 0);
//
    //
    //pthread_t thread1;
    //pthread_t thread2;
    //pthread_create(&thread1, NULL, threadRun, (void *) d1);
    //pthread_create(&thread2, NULL, threadRun, (void *) d2);
//
//
    //for (int i = 0; i < 100; ++i) {
    //    systemClock++;
    //    sleep(1);
    //}




    cin >> rows >> cols;
    grid = new Grid(rows, cols);
    cout << "alive" << endl;
    cin >> numOfObstacles;
    cout << "alive" << endl;
    for (int j = 0; j < numOfObstacles; ++j) {
        cin >> point;
        grid->get(point)->setObstacle(true);
    }
    cout << "alive" << endl;
    /*
    cout << "-----------------------" << endl
         << "GRID: " << *grid << endl
         << "-----------------------" << endl;
    */

    pthread_t pthreads[10];


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
                    cout << "work?" << endl;
                    dc = con.receive<DriverContainer>();
                    cout << "good" << endl;

                    driver = new Driver(*dc);
                    driver->setLocation(grid->get(0, 0));
                    driver->setDescriptor(descriptor);
                    center.addDriver(driver);

                    delete dc;
                    //assign a taxi and send it back.
                    taxi = center.getTaxi(driver->getTaxiID());
                    driver->setTaxi(taxi);
                    cout << "work" << endl;
                    //con.receiveString(buffer);
                    con.send(taxi);
                    cout << "alive driver" << endl;
                    con.receiveString(buffer);
                    //cout << "got driver: " << *driver << endl;
                    //cout << "sent taxi: " << *taxi << endl;


                    cout << *driver << " threads.. ";
                    pthread_create(&pthreads[j], NULL, threadRun, (void *) driver);
                    cout << "ok" << endl;
                    threads++;
                }//cout << "finished waiting for drivers" << endl;
                /*
                driver = new Driver();
                cin >> *driver;
                 */
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
                //systemClock++;

                //waiting for threads to finish
                //while (threads != finished) {
                //    sleep(1);
                //}
                //finished = 0;

                cout << *center.getDriver(id)->getLocation() << endl;

                //con.send(command);
                //cout << "alive after" << endl;
                //lc = con.receive<LocationContainer>();
                //cout << "alive again" << endl;
                //location = new Location(lc);
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

                //if (center.numOfTripsAt(timeClock)) {
                //    command->setOp(Operation::NEW_RIDE);
                //    cout << "sending " << *command << endl;
//
                //    con.send(command);
//
                //    cout << "sent command" << endl;
                //    trip = center.getTripAt(timeClock);
//
                //    while (!trip->isCalced()) {
                //        sleep(1);
                //    }
//
                //    tc = trip->getContainer();
                //    cout << "send trip" << endl;
//
                //    con.receiveString(buffer);
                //    con.send(tc);
//
                //    cout << "sent it" << endl;
                //    delete tc;
                //    command->setOp(Operation::ADVANCE);
//
                //    con.receiveString(buffer);
                //}
//
                //timeClock++;
                //cout << *command << endl;
                //con.send(command);
                //cout << "sent command advance" << endl;
                //con.receiveString(buffer);
                //cout << "sent string" << endl;

                //lc = con.receive<LocationContainer>();
                //location = new Location(lc);
                //cout << clock << " : " << *location << endl;

                break;

            case Operation::EXIT:
                //cout << *command << endl;
                //con.send(command);

                timeClock++;
                isRunning = false;
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

    //close(sock); // create warning in valgrind.
    //delete udp;  // no need.
    return 0;
}

void *threadRun(void *element) {
    Driver *driver = (Driver *) element;

    cout << *driver << endl;

    bool isRunning = true;
    int localClock = timeClock;
    char buffer[1024];


    LocationContainer *lc;
    Location *location;
    TripContainer *tc;
    TripInfo *trip;

    Socket *socket = new Tcp(1, sock);
    cout << "alive thread" << endl;
    Connection con = Connection(socket);
    con.setDescriptor(driver->getDescriptor());
    cout << "alive thread 2" << endl;

    //for (int j = 0; j < 100; ++j) {
    //    pthread_mutex_lock(&locker);
    //    cout << *driver << " : " << systemClock << endl;
    //    pthread_mutex_unlock(&locker);
    //    sleep(1);
    //}

    do {
        while (localClock == timeClock) {
            //cout << localClock << " : " << timeClock << endl;
            sleep(1);
        }

        localClock++;
        cout << "localClock: " << localClock << endl;

        switch (command->getOp()) {
            case Operation::ADVANCE:
                //center.advanceAllDrivers();
                cout << "advance" << endl;

                pthread_mutex_lock(&trip_locker);
                trip = center.getTripAt(timeClock, driver->getLocation()->getPoint());
                pthread_mutex_unlock(&trip_locker);

                if (trip != NULL) {
                    command->setOp(Operation::NEW_RIDE);
                    cout << "sending " << *command << endl;

                    con.send(command);

                    cout << "sent command" << endl;


                    while (!trip->isCalced()) {
                        sleep(1);
                    }

                    tc = trip->getContainer();
                    cout << "send trip" << endl;

                    con.receiveString(buffer);

                    cout << *trip << endl;

                    con.send(tc);

                    cout << "sent it" << endl;
                    delete tc;
                    command->setOp(Operation::ADVANCE);

                    con.receiveString(buffer);
                }

                //timeClock++;
                cout << *command << endl;
                con.send(command);
                cout << "sent command advance" << endl;
                lc = con.receive<LocationContainer>();
                cout << "alive again" << endl;
                location = new Location(lc);

                cout << *location << endl;
                driver->setLocation(location);
                delete lc;

                //lc = con.receive<LocationContainer>();
                //location = new Location(lc);
                //cout << clock << " : " << *location << endl;

                break;

            case Operation::EXIT:
                //cout << *command << endl;
                con.send(command);
                isRunning = false;
                break;

            default:
                break;
        }

        //pthread_mutex_lock(&locker);
        //finished++;
        //pthread_mutex_unlock(&locker);
        /*
        cout << "-----------------------" << endl
             << "CENTER:" << endl << center << endl
             << "-----------------------" << endl;
        */
    } while (isRunning);

    return NULL;
}
