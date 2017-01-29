//
// Created by raz on 27/01/17.
//

#include <algorithm>
#include <sstream>
#include "Validator.h"

using namespace std;

/**
 * validates the input using checkers.
 * 
 * @param input input to validate
 * @param checkers criteria to check
 * @param separator to separate to input
 * @return true - valid/false - not valid
 */
bool Validator::validate(string input, vector<Checker *> checkers, char separator) {
    istringstream ss(input);
    string s;

    if (count(input.begin(), input.end(), separator) != checkers.size() - 1) {
        return false;
    }

    for (unsigned long i = 0; i < checkers.size(); ++i) {
        getline(ss, s, separator);

        if (!checkers.at(i)->check(s)) {
            return false;
        }
    }

    return true;
}
