//
// Created by raz on 14/11/16.
//

#include <iostream>
#include "navigation/Grid.h"
#include "Driver.h"
#include "sockets/Udp.h"
#include "sockets/Connection.h"
#include "enums/Operation.h"
#include "containers/Command.h"
#include "TaxiCenter.h"
#include "taxi/TaxiFactory.h"
#include "sockets/Tcp.h"
#include "Thread.h"
#include "ThreadPool.h"

#define ERROR_MESSAGE -1
#define ERROR -1

using namespace std;

// global variants:
int timeClock = 0;
int sock;
TaxiCenter center;
Command *command;
int threadsCounter = 0;

vector<Command *> commands;
Grid *grid;

// mutex.
pthread_mutex_t trip_locker;

static void *threadRun(void *element);

/**
 * entry point.
 *
 * @return 0.
 */
int main(int argc, char *argv[]) {
    sock = atoi(argv[1]);
    char buffer[1024];
    unsigned int i;

    ThreadPool tp(5);

    pthread_mutex_init(&trip_locker, 0);

    center = TaxiCenter();
    Driver *driver;
    DriverContainer *dc;
    TripInfo *trip;
    Point point = Point(-1, -1);
    TaxiFactory factory;
    Taxi *taxi;
    bool isRunning = true;
    int opNum, id, numOfDrivers, descriptor;
    Operation op;
    command = new Command();

    //LocationContainer *lc;
    //TripContainer *tc;
    //Location *location;
    int rows, cols;
    int numOfObstacles;
    bool valid = false;
    bool gridValid = true;
    //Socket *socket = new Udp(1, sock);
    Socket *socket = new Tcp(1, sock);
    Connection con = Connection(socket);
    con.initialize();

    Thread *thread;
    vector<Thread *> threads;

    while (!valid) {
        cin >> rows >> cols;
        if (rows < 1 || cols < 1 || !cin.good()) {
            cout << ERROR_MESSAGE << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin >> numOfObstacles;
        if (numOfObstacles < 0 || !cin.good()) {
            cout << ERROR_MESSAGE << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        grid = new Grid(rows, cols);

        for (int j = 0; j < numOfObstacles; ++j) {
            //cout << "point number: " << j << endl;
            cin >> point;
            if (point.getX() == ERROR || !cin.good() ||
                point.getX() >= grid->getCols() ||
                point.getY() >= grid->getRows()) {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                gridValid = false;
                delete grid;
                j = numOfObstacles;
                continue;
            }
            gridValid = true;
            grid->get(point)->setObstacle(true);
        }
        if (gridValid) {
            valid = true;
        }
    }
    //cout << "alive" << endl;
    /*
    cout << "-----------------------" << endl
         << "GRID: " << *grid << endl
         << "-----------------------" << endl;
    */

    do {
        //operation
        //cout << cin.get() << endl;
        //cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> opNum;
        //cout<< "im dead" << endl;
        op = static_cast<Operation>(opNum);
        command->setOp(op);
        //cout << *command << endl;

        switch (op) {
            case Operation::NEW_DRIVER:
                cin >> numOfDrivers;
                if (numOfDrivers < 0 || !cin.good()) {
                    cout << ERROR_MESSAGE << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                //cout << "waiting for drivers" << endl;
                for (int j = 0; j < numOfDrivers; ++j) {
                    descriptor = con.accept();
                    dc = con.receive<DriverContainer>();
                    if (dc->getId() == ERROR) { // terminate all.
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        commands.push_back(new Command(Operation::EXIT));
                        timeClock++;
                        isRunning = false;
                        delete dc;
                        break;
                    }

                    driver = new Driver(*dc);
                    driver->setLocation(grid->get(0, 0));
                    driver->setDescriptor(descriptor);
                    center.addDriver(driver);

                    delete dc;
                    //assign a taxi and send it back.
                    taxi = center.getTaxi(driver->getTaxiID());
                    driver->setTaxi(taxi);

                    con.send(taxi);
                    con.receiveString(buffer);

                    thread = new Thread(driver, descriptor);
                    threads.emplace_back(thread);

                    pthread_create(thread->getThread(), NULL, threadRun, (void *) thread);

                    threadsCounter++;
                }

                break;
            case Operation::NEW_RIDE:
                trip = new TripInfo();
                trip->setGrid(grid);
                cin >> *trip;
                //cout << trip->getId() << endl;
                if (trip->getId() == ERROR) {
                    cout << ERROR_MESSAGE << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    //delete trip;
                    break;
                }
                //cout << *trip << endl;
                //trip->calcPath();
                tp.addTrip(trip);
                center.addTrip(trip);
                break;
            case Operation::NEW_VEHICLE:
                cin >> factory;

                if (factory.getTaxi()->getId() == ERROR) {
                    cout << ERROR_MESSAGE << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    delete factory.getTaxi();
                    break;
                }

                //cout << *factory.getTaxi() << endl;
                center.addTaxi(factory.getTaxi());
                break;
            case Operation::DRIVER_LOCATION:
                //   cout << "driver location" << endl;

                cin >> id;
                if (!center.isDriverIn(id)) {
                    cout << ERROR_MESSAGE << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                i = 0;

                while (id != threads.at(i)->getDriver()->getId()) {
                    i++;
                }

                while (timeClock != threads.at(i)->getLocalClock()) {
                    usleep(50);
                }

                cout << *center.getDriver(id)->getLocation() << endl;

                //delete lc;
                //delete location;
                break;

            case Operation::ADVANCE:
                //center.advanceAllDrivers();
                //cout << "advance" << endl;
                commands.push_back(new Command(Operation::ADVANCE));
                timeClock++;

                break;

            case Operation::EXIT:
                commands.push_back(new Command(Operation::EXIT));
                timeClock++;
                isRunning = false;
                break;
            default:
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    for (unsigned int c = 0; c < commands.size(); c++) {
        delete commands[c];
    }

    commands.clear();

    for (unsigned int t = 0; t < threads.size(); t++) {
        delete threads[t];
    }

    threads.clear();
    //pthread_mutex_destroy(&trip_locker);

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
    Thread *thread = (Thread *) element;

    bool isRunning = true;
    bool isTripRun;
    Driver *driver = thread->getDriver();
    Command *tripCommand = new Command(Operation::NEW_RIDE);
    Command *localCommand;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    int trys;

    map<Point, deque<Driver *>>::iterator it;

    LocationContainer *lc;
    Location *location;
    TripContainer *tc;
    TripInfo *trip = NULL;

    Socket *socket = new Tcp(1, sock);
    Connection con = Connection(socket);
    con.setDescriptor(thread->getDescriptor());

    do {
        while (thread->getLocalClock() == timeClock) {
            //cout << localClock << " : " << timeClock << endl;
            usleep(50);
        }

        localCommand = commands.at((unsigned int) thread->getLocalClock());
        //cout << *localCommand << endl;
        //cout << "localClock: " << thread->getLocalClock() + 1 << " of " << driver->getId() << endl;

        switch (localCommand->getOp()) {
            case Operation::ADVANCE:
                //center.advanceAllDrivers();
                //cout << "advance" << endl;
                if (driver->isAvailable()) {
                    isTripRun = true;

                    pthread_mutex_lock(&trip_locker);

                    trys = 0;

                    do { //looking for calculated valid trips
                        trys++;
                        trip = center.getTripAt(thread->getLocalClock(), driver);
                        //if (trip != NULL) {
                        //    center.eraseDriver(driver);
                        //}

                        if (trip != NULL) {
                            //cout << *trip << endl;

                            while (!trip->isCalced()) {
                                usleep(50);
                            }

                            if (!trip->isValid()) {
                                continue;
                            }

                            /*
                            for (int i = 0; i < trip->getRoute().size(); ++i) {
                                cout << *trip->getRoute().at(i);
                            }
                            cout << endl;
                            */

                            center.eraseDriver(driver);

                            con.send(tripCommand);

                            tc = trip->getContainer();

                            con.receiveString(buffer);

                            usleep(300);
                            con.send(tc);

                            delete tc;
                            //~~~~~~~~~~~~~~~~~~~~~~delete trip;

                            con.receiveString(buffer);
                            driver->setAvailable(false);

                        }

                        isTripRun = false;

                    } while (isTripRun);


                    pthread_mutex_unlock(&trip_locker);
                }

                //cout << *localCommand << endl;
                con.send(localCommand);
                lc = con.receive<LocationContainer>();
                //delete location;
                location = new Location(lc);

                //cout << *location << endl;

                if ((*location == *driver->getLocation())) {
                    driver->setAvailable(true);
                    center.push(driver);
                }

                driver->setLocation(grid->get(*location->getPoint()));

                delete lc;
                delete location;
                break;

            case Operation::EXIT:
                con.send(localCommand);
                isRunning = false;
                break;

            default:
                break;
        }

        thread->incClock();

        /*
        cout << "-----------------------" << endl
             << "CENTER:" << endl << center << endl
             << "-----------------------" << endl;
        */

    } while (isRunning);

//delete location;
    delete
            tripCommand;

    return NULL;
}
