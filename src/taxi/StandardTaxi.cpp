//
// Created by raz on 29/11/16.
//

#include "StandardTaxi.h"


StandardTaxi::StandardTaxi(int id, CarManufacturer manufacturer, Color color) : Taxi(id,
                                                                                     manufacturer,
                                                                                     color) {}

int StandardTaxi::getTaarif() {
    return 0;
}

int StandardTaxi::getSpeed() {
    return 0;
}

ostream &operator<<(ostream &os, const StandardTaxi &taxi) {
    os << static_cast<const Taxi &>(taxi) << " Type: Standard";
    return os;
}

