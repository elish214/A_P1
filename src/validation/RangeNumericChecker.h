//
// Created by raz on 27/01/17.
//

#ifndef A_P1_RANGENUMERICCHECKER_H
#define A_P1_RANGENUMERICCHECKER_H


#include "Checker.h"

/**
 * Class checks if the input is a positive number and is between min and max
 */
class RangeNumericChecker: public Checker {
private:
    int min;
    int max;
public:
    RangeNumericChecker(int min, int max);

    bool check(string input);
};


#endif //A_P1_RANGENUMERICCHECKER_H
