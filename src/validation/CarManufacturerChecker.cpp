//
// Created by raz on 27/01/17.
//

#include "CarManufacturerChecker.h"

/**
 * Checks if the input is a valid CarManufacturer
 * @param input string to check
 * @return true - valid/false - not valid
 */
bool CarManufacturerChecker::check(string input) {
    return input.size() == 1 && (input.at(0) == 'H' || input.at(0) == 'S' || input.at(0) == 'T' || input.at(0) == 'F');
}
