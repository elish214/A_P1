//
// Created by raz on 29/11/16.
//

#include "StandardTaxi.h"

/**
 * constructor.
 * @param id an integer.
 * @param manufacturer an enum.
 * @param color an enum.
 */
StandardTaxi::StandardTaxi(int id, CarManufacturer manufacturer, Color color) : Taxi(id,
                                                                                     manufacturer,
                                                                                     color) {}

/**
 * returns cabs' taarif.
 *
 * @return cabs' taarif.
 */
int StandardTaxi::getTaarif() {
    return 0;
}

/**
 * returns cab's speed.
 *
 * @return cab's speed.
 */
int StandardTaxi::getSpeed() {
    return 0;
}

ostream &operator<<(ostream &os, const StandardTaxi &taxi) {
    os << static_cast<const Taxi &>(taxi) << " Type: Standard";
    return os;
}

