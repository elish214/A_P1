//
// Created by raz on 27/01/17.
//

#ifndef A_P1_CHECKER_H
#define A_P1_CHECKER_H

#include <string>

using namespace std;

/**
 * Checker is a pure virtual class with the ability to preform a check on a single input
 */
class Checker {
public:
    virtual bool check(string input) = 0;
};


#endif //A_P1_CHECKER_H
