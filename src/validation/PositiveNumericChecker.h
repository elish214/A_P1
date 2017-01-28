//
// Created by raz on 27/01/17.
//

#ifndef A_P1_NUMERICCHECKER_H
#define A_P1_NUMERICCHECKER_H


#include "Checker.h"

/**
 * Class checks if the input is a positive number
 */
class PositiveNumericChecker: public Checker {
public:
    bool check(string input);
};


#endif //A_P1_NUMERICCHECKER_H
