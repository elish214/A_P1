//
// Created by raz on 06/12/16.
//

#include "Flow.h"
#include "TaxiCenter.h"

using namespace std;

int Flow::run() {
    TaxiCenter center = TaxiCenter();
    Driver driver;
    bool isRunning = true;
    int i;
    Operation op;

    do {
        cin >> i;
        op = static_cast<Operation>(i);

        switch (op) {
            case Operation::NEW_DRIVER:
                cin >> driver;
                center.addDriver(driver);
                break;
            case Operation::NEW_RIDE:
                cout << "new ride" << endl;
                break;
            case Operation::NEW_VEHICLE:
                cout << "new vehicle" << endl;
                break;
            case Operation::DRIVER_LOCATION:
                cout << "driver location" << endl;
                break;
            case Operation::START:
                cout << "start" << endl;
                break;
            case Operation::EXIT:
                isRunning = false;
                break;
        }

        cout << center << endl;

    } while (isRunning);


    return 0;
}
