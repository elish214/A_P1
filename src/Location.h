//
// Created by elish on 16/11/16.
//

#ifndef A_P1_LOCATION_H
#define A_P1_LOCATION_H


#include "Point.h"
#include "Grid.h"
#include "Node.h"

using namespace std;

class Location: public Node {
private:
    Point p;
    Grid grid;

};


#endif //A_P1_LOCATION_H
