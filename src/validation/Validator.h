//
// Created by raz on 27/01/17.
//

#ifndef A_P1_VALIDATOR_H
#define A_P1_VALIDATOR_H

#include <string>
#include <vector>
#include "Checker.h"

using namespace std;

/**
 * Validator is responsible of validating inputs using checkers.
 */
class Validator {
public:
    bool validate(string input, vector<Checker *> checkers, char separator);
};


#endif //A_P1_VALIDATOR_H
