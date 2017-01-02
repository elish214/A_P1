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
    Connection con(new Udp(0, sock));
    //Driver *d = new Driver(0, 30, MaritalStatus::MARRIED, 1, 0);
    Driver *d = new Driver();
    d->setAvailability(true);
    DriverContainer *dc;// = d->getContainer();
    Taxi *taxi;
    TripInfo *trip;
    TripContainer *tc;
    Operation op;
    LocationContainer *lc;
    const Node *l;
    Command *c;
    bool isRunning = true;
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

        switch (op) {
            case Operation::NEW_RIDE:
                tc = con.receive<TripContainer>();
                trip = new TripInfo(*tc);

                d->setRoute(trip->getRoute());
                d->moveOneStep();
                break;
            case Operation::ADVANCE:
                d->moveOneStep();
                //break;
            case Operation::DRIVER_LOCATION:
                l = d->getLocation();
                lc = d->getLocation()->getContainer();
                con.send(lc);
                break;
            case Operation::EXIT:
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

    //close sockets!!
    //free stuff
    close(sock);
    return 0;
}