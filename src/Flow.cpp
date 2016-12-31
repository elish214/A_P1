//
// Created by raz on 06/12/16.
//

#include "Flow.h"
#include "TaxiCenter.h"
#include "navigation/Grid.h"
#include "taxi/TaxiFactory.h"
#include "sockets/Udp.h"
#include "sockets/Connection.h"
#include "enums/Operation.h"
#include "containers/Command.h"

using namespace std;

/**
 * returns 0 if everything runs well.
 *
 * @return 0 if everything runs well.
 */
int Flow::run(int port) {
    Grid *grid;
    TaxiCenter center = TaxiCenter();
    Driver *driver;
    //DriverContainer *dc;
    TripInfo *trip;
    Point point = Point(-1, -1);
    TaxiFactory factory;
    Taxi *taxi;
    bool isRunning = true;
    int opNum, numOfObstacles, id, numOfDrivers;
    Operation op;
    int clock = 0;
    Command *command = new Command();
    Node *node;
    //LocationContainer *lc;
    //TripContainer *tc;
    Location *location;

    int rows, cols;

    Connection con(new Udp(1, port));
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

        switch (op) {
            case Operation::NEW_DRIVER:
                cin >> numOfDrivers;
                cout << "waiting for drivers" << endl;
                for (int j = 0; j < numOfDrivers; ++j) {
                    //dc = con.receive<DriverContainer>();
                    driver = new Driver(*con.receive<DriverContainer>());
                    driver->setLocation(grid->get(0, 0));
                    center.addDriver(driver);
                    //assign a taxi and send it back.
                    taxi = center.getTaxi(driver->getTaxiID());
                    driver->setTaxi(taxi);
                    con.send(taxi);

                    cout << "got driver: " << *driver << endl;
                    cout << "sent taxi: " << *taxi << endl;
                }
                cout << "finished waiting for drivers" << endl;
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
                //trip->getStart()->setGrid(grid);
                //trip->getEnd()->setGrid(grid);
                trip->initPassenger();
                trip->calcMeters();
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
                con.send(command);
                //lc = con.receive<LocationContainer>();
                location = new Location(*con.receive<LocationContainer>());

                cout << *location << endl;

                break;
            case Operation::START:
                //   cout << "start" << endl;

                //center.start();
                break;

            case Operation::ADVANCE:
                //center.advanceAllDrivers();

                if (center.numOfTripsAt(clock)) {
                    command->setOp(Operation::NEW_RIDE);
                    con.send(command);

                    trip = center.getTripAt(clock);
                    //tc = trip->getContainer();
                    con.send(trip->getContainer());

                    cout << "sent trip: " << *trip << endl;

                    command->setOp(Operation::ADVANCE);
                }

                clock++;
                con.send(command);

                //lc = con.receive<LocationContainer>();
                location = new Location(*con.receive<LocationContainer>());
                cout << *location << endl;

                break;

            case Operation::EXIT:
                con.send(command);

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
    //delete trip;
    //close socket.

    return 0;
}
