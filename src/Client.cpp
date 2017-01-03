//
// Created by raz on 24/12/16.
//

#include "sockets/Udp.h"
#include "sockets/Connection.h"
#include "taxi/StandardTaxi.h"
#include "Driver.h"
#include "enums/Operation.h"
#include "containers/Command.h"

using namespace std;

int main(int argc, char *argv[]) {
    int sock = atoi(argv[2]);
    Socket *udp = new Udp(0, sock);
    Connection con(udp);
    //Driver *d = new Driver(0, 30, MaritalStatus::MARRIED, 1, 0);
    Driver *d = new Driver();
    d->setAvailability(true);
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
    d->setTaxi(taxi);

    do {
        //operation
        c = con.receive<Command>();
        op = c->getOp();
        delete c;

        switch (op) {
            case Operation::NEW_RIDE:
                if (locationFlag) {
                    d->deleteLocation();
                    locationFlag = false;
                }

                trip->deleteRoute();
                delete trip;
                tc = con.receive<TripContainer>();
                trip = new TripInfo(tc);

                d->setRoute(trip->getRoute());

                d->moveOneStep(1);
                d->moveTaxiStep();
                //cout << "step: " << *d->getLocation() << endl;

                delete tc;
                break;
            case Operation::ADVANCE:
                d->moveTaxiStep();
                //cout << "step: " << *d->getLocation() << endl;
                break;
            case Operation::DRIVER_LOCATION:
                //l = d->getLocation();
                lc = d->getLocation()->getContainer();
                con.send(lc);
                delete lc;
                break;
            case Operation::EXIT:
                isRunning = false;
                break;
            default:
                break;
        }
    } while (isRunning);

    //close sockets!!
    //free stuff
    //delete con;
    //delete c;
    trip->deleteRoute();
    delete trip;
    if (locationFlag) {
        d->deleteLocation();
        //locationFlag = false;
    }
    delete taxi;
    delete d;
    delete dc;
    close(sock);
    return 0;
}