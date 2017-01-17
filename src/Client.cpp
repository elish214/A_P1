//
// Created by raz on 24/12/16.
//

#include "sockets/Udp.h"
#include "sockets/Tcp.h"
#include "sockets/Connection.h"
#include "taxi/StandardTaxi.h"
#include "Driver.h"
#include "enums/Operation.h"
#include "containers/Command.h"

using namespace std;

int main(int argc, char *argv[]) {
    int sock = atoi(argv[2]);

    //Socket *socket = new Udp(0, sock);
    Socket *socket = new Tcp(0, sock);
    Connection con(socket);
    //Driver *d = new Driver(0, 30, MaritalStatus::MARRIED, 1, 0);
    Driver *d = new Driver();
    DriverContainer *dc;// = d->getContainer();
    Taxi *taxi;
    vector<Node*> route;
    TripInfo *trip = new TripInfo(route);
    TripContainer *tc;
    Operation op;
    LocationContainer *lc;
    //const Node *l;
    Command *c;
    bool isRunning = true;
    bool locationFlag = true;
    cin >> *d;
    dc = d->getContainer();

    con.initialize();

    con.send(dc);

    taxi = con.receive<Taxi>();
    cout << *taxi << endl;
    d->setTaxi(taxi);
    con.sendString("OK");

    do {
        //operation
        cout << "im here" <<endl;
        c = con.receive<Command>();
        op = c->getOp();
        cout << *c << endl;

        delete c;

        switch (op) {
            case Operation::NEW_RIDE:
                if (locationFlag) {
                    d->deleteLocation();
                    locationFlag = false;
                }

                trip->deleteRoute();
                delete trip;
                con.sendString("OK");

                tc = con.receive<TripContainer>();
                con.sendString("OK");
                trip = new TripInfo(tc);

                d->setRoute(trip->getRoute());

                d->moveOneStep(1);
                //d->moveTaxiStep();
                //cout << "step: " << *d->getLocation() << endl;

                delete tc;
                break;
            case Operation::ADVANCE:
                cout << "i'm moving!" << endl;

                d->moveTaxiStep();

                //con.sendString("OK");
                //cout << "step: " << *d->getLocation() << endl;
                //break;
            case Operation::DRIVER_LOCATION:
                //l = d->getLocation();
                lc = d->getLocation()->getContainer();
                cout << *lc << endl;
                con.send(lc);
                cout << "again" << *lc << endl;
                delete lc;
                break;
            case Operation::EXIT:
                isRunning = false;
                break;
            default:
                break;
        }

        cout << *d->getLocation() << endl;
    } while (isRunning);

    trip->deleteRoute();
    delete trip;
    if (locationFlag) {
        d->deleteLocation();
        //locationFlag = false;
    }
    delete taxi;
    delete d;
    delete dc;
    return 0;
}