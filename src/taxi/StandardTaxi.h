//
// Created by raz on 29/11/16.
//

#ifndef A_P1_STANDARDTAXI_H
#define A_P1_STANDARDTAXI_H


#include <ostream>
#include "Taxi.h"

class StandardTaxi : public Taxi {
public:
    StandardTaxi(int id, CarManufacturer manufacturer, Color color);

    int getTaarif() override;

    int getSpeed() override;

    friend ostream &operator<<(ostream &os, const StandardTaxi &taxi);
};


#endif //A_P1_STANDARDTAXI_H
