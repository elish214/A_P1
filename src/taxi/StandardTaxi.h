//
// Created by raz on 29/11/16.
//

#ifndef A_P1_STANDARDTAXI_H
#define A_P1_STANDARDTAXI_H


#include "Taxi.h"

class StandardTaxi : public Taxi {
public:
    int getTaarif() override;

    int getSpeed() override;
};


#endif //A_P1_STANDARDTAXI_H