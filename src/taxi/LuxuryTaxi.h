//
// Created by raz on 29/11/16.
//

#ifndef A_P1_LUXURYTAXI_H
#define A_P1_LUXURYTAXI_H


#include <ostream>
#include "Taxi.h"

class LuxuryTaxi : public Taxi {
protected:
    string getType() const;

public:
    LuxuryTaxi(int id, CarManufacturer manufacturer, Color color);

    int getTaarif() override;

    int getSpeed() override;

    friend ostream &operator<<(ostream &os, const LuxuryTaxi &taxi);
};


#endif //A_P1_LUXURYTAXI_H
