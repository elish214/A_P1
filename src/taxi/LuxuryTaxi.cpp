//
// Created by raz on 29/11/16.
//

#include "LuxuryTaxi.h"

/**
 * constructor.
 *
 * @param id an integer.
 * @param manufacturer an enum.
 * @param color an enum.
 */
LuxuryTaxi::LuxuryTaxi(int id, CarManufacturer manufacturer, Color color) : Taxi(id, manufacturer,
                                                                                 color)  {}
/**
 * returns cabs' taarif.
 *
 * @return cabs' taarif.
 */
int LuxuryTaxi::getTaarif() {
    return 2;
}

/**
 * returns cab's speed.
 *
 * @return cab's speed.
 */
int LuxuryTaxi::getSpeed() {
    return 2;
}

ostream &operator<<(ostream &os, const LuxuryTaxi &taxi) {
    os << static_cast<const Taxi &>(taxi) << " Type: Luxury";
    return os;
}

string LuxuryTaxi::getType() const {
    return "LUXURY";
}

