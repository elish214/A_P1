//
// Created by raz on 29/11/16.
//

#ifndef A_P1_LUXURYTAXI_H
#define A_P1_LUXURYTAXI_H


#include "Taxi.h"

/**
 * a luxury taxi class.
 */
class LuxuryTaxi : public Taxi {
public:
    LuxuryTaxi(int id, CarManufacturer manufacturer, Color color);

    int getTaarif();

    int getSpeed();
};


#endif //A_P1_LUXURYTAXI_H
