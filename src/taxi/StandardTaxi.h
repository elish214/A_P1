//
// Created by raz on 29/11/16.
//

#ifndef A_P1_STANDARDTAXI_H
#define A_P1_STANDARDTAXI_H


#include "Taxi.h"

/**
 * a standard taxi class.
 */
class StandardTaxi : public Taxi {
public:
    StandardTaxi(int id, CarManufacturer manufacturer, Color color);

    int getTaarif();

    int getSpeed();
};


#endif //A_P1_STANDARDTAXI_H
