//
// Created by raz on 29/11/16.
//

#include "StandardTaxi.h"

BOOST_CLASS_EXPORT(StandardTaxi)
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
 * constructor.
 */
StandardTaxi::StandardTaxi() {}

/**
 * returns cabs' taarif.
 *
 * @return cabs' taarif.
 */
int StandardTaxi::getTaarif() {
    return 1;
}

/**
 * returns cab's speed.
 *
 * @return cab's speed.
 */
int StandardTaxi::getSpeed() {
    return 1;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param taxi a standard.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const StandardTaxi &taxi) {
    os << static_cast<const Taxi &>(taxi) << " Type: Standard";
    return os;
}

/**
 * returns taxi's type.
 *
 * @return taxi's type.
 */
string StandardTaxi::getType() const {
    return "STANDARD";
}
