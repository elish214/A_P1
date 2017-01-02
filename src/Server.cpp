//
// Created by raz on 14/11/16.
//

#include <iostream>
#include <stack>
#include "navigation/Grid.h"
#include "Driver.h"
#include "sockets/Udp.h"
#include "sockets/Connection.h"
#include "taxi/StandardTaxi.h"
#include "enums/Operation.h"
#include "containers/Command.h"
#include "TaxiCenter.h"
#include "taxi/TaxiFactory.h"
#include "navigation/Node.h"

using namespace std;
//using namespace boost::archive;
//std::stringstream ss;

void parser(string s, int &a, int &c);

void printRoute(stack<Node *> route);

/**
 * entry point.
 *
 * @return 0.
 */
int main(int argc, char *argv[]) {
    cout << "Hello, from server" << endl;

    int sock = atoi(argv[1]);

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
    //Node *node;
    LocationContainer *lc;
    //TripContainer *tc;
    Location *location;

    int rows, cols;

    Connection con(new Udp(1, sock));
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
    //            cout << "waiting for drivers" << endl;
                for (int j = 0; j < numOfDrivers; ++j) {
                    //dc = con.receive<DriverContainer>();
                    driver = new Driver(*con.receive<DriverContainer>());
                    driver->setLocation(grid->get(0, 0));
                    center.addDriver(driver);
                    //assign a taxi and send it back.
                    taxi = center.getTaxi(driver->getTaxiID());
                    driver->setTaxi(taxi);
                    con.send(taxi);

      //              cout << "got driver: " << *driver << endl;
      //              cout << "sent taxi: " << *taxi << endl;
                }
      //          cout << "finished waiting for drivers" << endl;
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

                    command->setOp(Operation::ADVANCE);
                }

                clock++;
                con.send(command);

                lc = con.receive<LocationContainer>();
                location = new Location(*lc);
                //cout << clock << " : " << *location << endl;

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
    close(sock);
    return 0;
}



    /*
    Command *op = new Command(Operation::ADVANCE);

    Connection con(new Udp(1, atoi(argv[1])));
    con.initialize();

    while (1) {
        char buffer[1024];

        con.receiveString(buffer);
        cout << buffer << endl;

        con.send(op);
    }

    return 0;
    */


  //  Flow flow = Flow();

//    return flow.run(atoi(argv[1]));


/**
 * parsing a string into two integers.
 *
 * @param s a string.
 * @param a first integer.
 * @param b second integer.
 */
void parser(string s, int &a, int &b) {
    unsigned long i = s.find('_');

    a = atoi(s.substr(0, i).c_str());
    b = atoi(s.substr(i + 1, s.size() - i - 1).c_str());
}

/**
 * printing a route.
 *
 * @param route a stuck of nodes.
 */
void printRoute(stack<Node *> route) {
    while (!route.empty()) {
        cout << *(route.top()) << endl;
        route.pop();
    }
}