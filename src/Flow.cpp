//
// Created by raz on 06/12/16.
//

#include "Flow.h"
#include "TaxiCenter.h"
#include "navigation/Grid.h"

using namespace std;

int Flow::run() {
    Grid *grid = new Grid(3,3);
    TaxiCenter center = TaxiCenter();
    Driver *driver;
    TripInfo *trip;
    Taxi *taxi;
    bool isRunning = true;
    int i;
    Operation op;

    do {
        //cin >> *grid;

        cin >> i;
        op = static_cast<Operation>(i);

        //obstacles?

        switch (op) {
            case Operation::NEW_DRIVER:
                cout << "new driver" << endl;
                cin >> *driver;
                center.addDriver(*driver);
                break;
            case Operation::NEW_RIDE:
                cout << "new ride" << endl;
                trip = new TripInfo();
                cin >> *trip;
                trip->setGrid(grid);
                trip->getStart().setGrid(grid);
                trip->getEnd().setGrid(grid);

                center.addTrip(*trip);
                break;
            case Operation::NEW_VEHICLE:
                cout << "new vehicle" << endl;
                //not working.
                cin >> *taxi;
                center.addTaxi(taxi);
                break;
            case Operation::DRIVER_LOCATION:
                cout << "driver location" << endl;
                break;
            case Operation::START:
                cout << "start" << endl;
                break;
            case Operation::EXIT:
                isRunning = false;
                //delete allllllll...
                break;
        }

        cout << "-----------------------" << endl
             << center << endl
             << "-----------------------" << endl;

    } while (isRunning);


    return 0;
}
