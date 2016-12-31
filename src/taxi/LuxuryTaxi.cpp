//
// Created by raz on 29/11/16.
//

#include "LuxuryTaxi.h"
BOOST_CLASS_EXPORT(LuxuryTaxi)

/**
 * constructor.
 *
 * @param id an integer.
 * @param manufacturer an enum.
 * @param color an enum.
 */
LuxuryTaxi::LuxuryTaxi(int id, CarManufacturer manufacturer, Color color) : Taxi(id, manufacturer,
                                                                                 color)  {}

LuxuryTaxi::LuxuryTaxi() {}

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

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param taxi a luxury taxi.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const LuxuryTaxi &taxi) {
    os << static_cast<const Taxi &>(taxi) << " Type: Luxury";
    return os;
}

/**
 * returns taxi's type.
 *
 * @return taxi's type.
 */
string LuxuryTaxi::getType() const {
    return "LUXURY";
}

