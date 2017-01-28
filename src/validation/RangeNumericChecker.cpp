//
// Created by raz on 27/01/17.
//

#include "RangeNumericChecker.h"
#include "PositiveNumericChecker.h"

/**
 * Ctor
 * @param min min value
 * @param max max value
 */
RangeNumericChecker::RangeNumericChecker(int min, int max) : min(min), max(max) {}

/**
 * Checks if the input is between min and max (positive)
 * @param input string to check
 * @return true - valid/false - not valid
 */
bool RangeNumericChecker::check(string input) {
    PositiveNumericChecker nc;
    int n;

    if(!nc.check(input)) {
        return false;
    }

    n = stoi(input);

    return min <= n && n <= max;
}
