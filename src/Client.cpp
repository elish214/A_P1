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
    Connection con(new Udp(0, atoi(argv[2])));
    Driver *d = new Driver(0, 30, MaritalStatus::MARRIED, 1, 0);
    d->setAvailability(true);
    DriverContainer *dc = d->getContainer();
    Taxi *taxi;
    TripInfo *trip;
    TripContainer *tc;
    Operation op;
    LocationContainer *lc;
    const Node *l;
    Command *c;
    bool isRunning = true;
    int x, y, size;


    con.initialize();


    con.send(dc);
    taxi = con.receive<Taxi>();

    cout << "got taxi: " << *taxi << endl;

    d->setTaxi(taxi);

    do {
        //operation
        c = con.receive<Command>();
        op = c->getOp();

        switch (op) {
            case Operation::NEW_RIDE:
                tc = con.receive<TripContainer>();
                trip = new TripInfo(*tc);

                //bug fix
                size = (int) trip->getRoute().size();
                x = trip->getRoute().at(size - 1)->getPoint()->getX();
                y = trip->getRoute().at(size - 1)->getPoint()->getY();
                trip->getRoute().at(size - 1)->setPoint(new Point(x, y));

                cout << "got trip: " << *trip << endl;

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

    return 0;
}