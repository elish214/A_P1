//
// Created by elish on 16/11/16.
//

#include "Location.h"

Location::Location() {}

const Point &Location::getP() const {
    return p;
}

void Location::setPoint(const Point &p) {
    Location::p = p;
}

Grid *Location::getGrid() const {
    return grid;
}

void Location::setGrid(Grid *grid) {
    Location::grid = grid;
}

list<Node> Location::neighbors(){

}

