//
// Created by raz on 27/01/17.
//

#include "ColorChecker.h"

/**
 * Checks if the input is a valid Color
 * @param input string to check
 * @return true - valid/false - not valid
 */
bool ColorChecker::check(string input) {
    return input.size() == 1 && (input.at(0) == 'R' || input.at(0) == 'B' || input.at(0) == 'G' || input.at(0) == 'P'
                                 || input.at(0) == 'W');
}
