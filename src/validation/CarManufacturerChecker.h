//
// Created by raz on 27/01/17.
//

#ifndef A_P1_MANUFACTURERCHECKER_H
#define A_P1_MANUFACTURERCHECKER_H


#include "Checker.h"

/**
 * Class checks the enum: CarManufacturer
 */
class CarManufacturerChecker: public Checker {
public:
    bool check(string input);
};


#endif //A_P1_MANUFACTURERCHECKER_H
