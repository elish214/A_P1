//
// Created by raz on 27/01/17.
//

#include <iostream>
#include "PositiveNumericChecker.h"


/**
 * Checks if the input is positive
 * @param input string to check
 * @return true - valid/false - not valid
 */
bool PositiveNumericChecker::check(string input) {
    for (unsigned long i = 0; i < input.size(); ++i) {
        if(!isdigit(input.at(i))) {
            return false;
        }
    }

    return input.size() > 0;
}
