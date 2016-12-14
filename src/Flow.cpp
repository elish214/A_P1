//
// Created by raz on 06/12/16.
//

#include "Flow.h"
#include "TaxiCenter.h"
#include "navigation/Grid.h"
#include "taxi/TaxiFactory.h"

using namespace std;

int Flow::run() {
    Grid *grid;
    TaxiCenter center = TaxiCenter();
    Driver *driver = new Driver();
    TripInfo *trip = new TripInfo();
    Point point = Point(-1, -1);
    TaxiFactory factory;
    bool isRunning = true;
    int opNum, numOfObstacles, id;
    Operation op;

    //cin >> (*grid); not working!

    int rows, cols;

    cin >> rows >> cols;
    grid = new Grid(rows, cols);

    cin >> numOfObstacles;

    for (int j = 0; j < numOfObstacles; ++j) {
        cin >> point;
        grid->get(point)->setObstacle(true);
    }

    cout << "-----------------------" << endl
         << "GRID: " << *grid << endl
         << "-----------------------" << endl;

    do {
        //operation
        cin >> opNum;
        op = static_cast<Operation>(opNum);

        switch (op) {
            case Operation::NEW_DRIVER:
                cout << "new driver" << endl;

                cin >> *driver;
                center.addDriver(driver);
                break;
            case Operation::NEW_RIDE:
                cout << "new ride" << endl;

                cin >> *trip;
                trip->setGrid(grid);
                trip->getStart()->setGrid(grid);
                trip->getEnd()->setGrid(grid);

                center.addTrip(*trip);
                break;
            case Operation::NEW_VEHICLE:
                cout << "new vehicle" << endl;

                cin >> factory;
                center.addTaxi(factory.getTaxi());
                break;
            case Operation::DRIVER_LOCATION:
                cout << "driver location" << endl;

                cin >> id;
                cout << *(center.getDriver(id)->getLocation()) << endl;
                break;
            case Operation::START:
                cout << "start" << endl;

                center.start();
                break;
            case Operation::EXIT:
                isRunning = false;
                //delete allllllll...
                break;
        }

        cout << "-----------------------" << endl
             << "CENTER:" << endl << center << endl
             << "-----------------------" << endl;

    } while (isRunning);


    return 0;
}
