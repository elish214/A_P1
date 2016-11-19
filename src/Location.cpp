//
// Created by elish on 16/11/16.
//

#include <list>
#include "Grid.h"

using namespace std;

Location::Location() {}

const Point &Location::getPoint() const {
    return p;
}

Location::~Location() {
    delete &p;
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

list<Node*> Location::neighbors(){
    int x = getPoint().getX();
    int y = getPoint().getY();
    int row = getGrid()->getRows();
    int cols = getGrid()->getCols();
    std::list<Node*> neighbor;

    if (x > 0) //left
        neighbor.emplace_back(getGrid()->get(x - 1, y));
    if (y < getGrid()->getCols() - 1) //up
        neighbor.emplace_back(getGrid()->get(x, y + 1));
    if (x < getGrid()->getRows() - 1) //right
        neighbor.emplace_back(getGrid()->get(x + 1, y));
    if (y > 0) //down
        neighbor.emplace_back(getGrid()->get(x, y - 1));

    return neighbor;
}

ostream &operator<<(ostream &os, const Location &location) {
    os << location.p;
    return os;
}

