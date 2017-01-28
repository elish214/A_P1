//
// Created by raz on 27/01/17.
//

#include "MaritalStatusChecker.h"

/**
 * Checks if the input is a valid MaritalStatus
 * @param input string to check
 * @return true - valid/false - not valid
 */
bool MaritalStatusChecker::check(string input) {
    return input.size() == 1 && (input.at(0) == 'S' || input.at(0) == 'M' || input.at(0) == 'D' || input.at(0) == 'W');
}
