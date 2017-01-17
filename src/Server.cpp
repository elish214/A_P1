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
#include "containers/ThreadContainer.h"
#include "containers/NewDriverContainer.h"

using namespace std;

int systemClock = 0;
int timeClock = 0;
int sock;
TaxiCenter center;
Command *command;
int threadsCounter = 0;
int finished = 0;

vector<Command*> commands;

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
    int rows, cols;
    //Socket *socket = new Udp(1, sock);
    Socket *socket = new Tcp(1, sock);
    Connection con = Connection(socket);
    con.initialize();

    NewDriverContainer *ndc;

    vector<ThreadContainer *> threads;

    cin >> rows >> cols;
    grid = new Grid(rows, cols);
    cin >> numOfObstacles;
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

    do {
        //operation
        cin >> opNum;
        op = static_cast<Operation>(opNum);
        command->setOp(op);
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
                    driver->setDescriptor(descriptor);
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


                    threads.emplace_back(new ThreadContainer());
                    cout << *driver << " threads.. " << endl;
                    ndc = new NewDriverContainer(driver, timeClock, descriptor);
                    pthread_create(threads.at(threads.size() - 1)->getThread(), NULL, threadRun, (void *) ndc);
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
                break;
            case Operation::NEW_VEHICLE:
                //   cout << "new vehicle" << endl;

                cin >> factory;
                center.addTaxi(factory.getTaxi());
                break;
            case Operation::DRIVER_LOCATION:
                //   cout << "driver location" << endl;

                cin >> id;
                //cout << *(center.getDriver(id)->getLocation()) << endl;

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
                commands.push_back(new Command(Operation::ADVANCE));
                timeClock++;
                //lc = con.receive<LocationContainer>();
                //location = new Location(lc);
                //cout << clock << " : " << *location << endl;

                break;

            case Operation::EXIT:
                //cout << *command << endl;
                //con.send(command);
                commands.push_back(new Command(Operation::EXIT));
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

    for (unsigned int k = 0; k < threads.size(); ++k) {
        pthread_join(*threads.at(k)->getThread(), NULL);
    }

    for (unsigned int t = 0; t < commands.size(); t++) {
        delete commands[t];
    }

    commands.clear();

    delete grid;
    delete command;

    return 0;
}


/**
 * thread's operation.
 *
 * @param element an element.
 * @return void.
 */
void *threadRun(void *element) {
    NewDriverContainer *ndc = (NewDriverContainer *) element;

    cout << *ndc->getDriver() << endl;

    bool isRunning = true;
    Driver *driver = ndc->getDriver();
    int localClock = ndc->getJoiningTime();
    Command *tripCommand = new Command(Operation::NEW_RIDE);
    Command *localCommand;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    map<Point, deque<Driver *>>::iterator it;

    LocationContainer *lc;
    Location *location;
    TripContainer *tc;
    TripInfo *trip = NULL;

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
        localCommand = commands.at((unsigned int) localClock);
        cout << *localCommand << endl;
        localClock++;
        cout << "localClock: " << localClock << endl;

        switch (localCommand->getOp()) {
            case Operation::ADVANCE:
                //center.advanceAllDrivers();
                cout << "advance" << endl;


                it = center.getLocations().find(*driver->getLocation()->getPoint());
                cout << "in deque: " << it->second.size() << endl;

                if (driver->isAvailable()) {
                    pthread_mutex_lock(&trip_locker);
                    trip = center.getTripAt(localClock - 1, driver);
                    if(trip != NULL) {
                        cout << driver->getId() << " got here!" << endl;
                        center.eraseDriver(driver);
                    }
                    pthread_mutex_unlock(&trip_locker);

                    if (trip != NULL) {
                        //command->setOp(Operation::NEW_RIDE);
                        cout << "sending " << *localCommand << endl;

                        con.send(tripCommand);

                        pthread_join(trip->getThread(), NULL);
                        tc = trip->getContainer();

                        con.receiveString(buffer);

                        cout << *trip << endl;

                        con.send(tc);

                        delete tc;
                        //command->setOp(Operation::ADVANCE);

                        con.receiveString(buffer);
                        driver->setAvailable(false);
                        //center.pop(*driver->getLocation()->getPoint());
                    }
                }

                //timeClock++;
                cout << *localCommand << endl;
                con.send(localCommand);
                lc = con.receive<LocationContainer>();
                location = new Location(lc);

                cout << *location << endl;

                if ((*location == *driver->getLocation())) {
                    driver->setAvailable(true);
                    center.push(driver);
                    cout << "KOKO" << endl;
                }

                driver->setLocation(location);


                delete lc;

                //lc = con.receive<LocationContainer>();
                //location = new Location(lc);
                //cout << clock << " : " << *location << endl;

                break;

            case Operation::EXIT:
                //cout << *command << endl;
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


    delete tripCommand;
    delete ndc;

    return NULL;
}
