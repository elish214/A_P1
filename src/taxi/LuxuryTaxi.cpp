//
// Created by raz on 29/11/16.
//

#include "LuxuryTaxi.h"


LuxuryTaxi::LuxuryTaxi(int id, CarManufacturer manufacturer, Color color) : Taxi(id, manufacturer,
                                                                                 color)  {}

int LuxuryTaxi::getTaarif() {
    return 0;
}

int LuxuryTaxi::getSpeed() {
    return 0;
}

ostream &operator<<(ostream &os, const LuxuryTaxi &taxi) {
    os << static_cast<const Taxi &>(taxi) << " Type: Luxury";
    return os;
}

