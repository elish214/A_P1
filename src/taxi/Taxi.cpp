//
// Created by raz on 29/11/16.
//

#include "Taxi.h"

Taxi::Taxi(int id, CarManufacturer manufacturer, Color color) : id(id), KmPassed(0),
                                                                manufacturer(manufacturer),
                                                                color(color) {}

void Taxi::addMeters(double meters) {

}

double Taxi::getKmPassed() const {
    return KmPassed;
}


