//
// Created by raz on 06/12/16.
//

#ifndef A_P1_TAXIFACTORY_H
#define A_P1_TAXIFACTORY_H


#include "Taxi.h"

/**
 * taxi factory representation class.
 */
class TaxiFactory {
private:
    Taxi *taxi;

public:
    friend istream &operator>>(istream &is, TaxiFactory &factory);

    Taxi *getTaxi() const;
};


#endif //A_P1_TAXIFACTORY_H
