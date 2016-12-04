//
// Created by raz on 29/11/16.
//

#include "Taxi.h"

/**
 * constructor.
 *
 * @param id an integer.
 * @param manufacturer an enum.
 * @param color an enum.
 */
Taxi::Taxi(int id, CarManufacturer manufacturer, Color color) : id(id), KmPassed(0),
                                                                manufacturer(manufacturer),
                                                                color(color) {}
/**
 * add meters to taxi's kilometers.
 *
 * @param meters a double.
 */
void Taxi::addMeters(double meters) {

}

/**
 * returns cab's kilometers.
 *
 * @return cab's kilometers.
 */
double Taxi::getKmPassed() const {
    return KmPassed;
}


