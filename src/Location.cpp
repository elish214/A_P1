//
// Created by elish on 16/11/16.
//

#include "Grid.h"

Location::Location() {}

const Point &Location::getPoint() const {
    return p;
}

Location::~Location() {
    delete p;
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
    int x = getPoint().getX();
    int y = getPoint().getY();
    int row = getGrid()->getRows();
    int cols = getGrid()->getCols();
    list <Node> neighbors;

    if (x > 0) //left
        neighbors.emplace_back(getGrid()->get(x - 1, y));
    if (y < getGrid()->getCols() - 1) //up
        neighbors.emplace_back(getGrid()->get(x, y + 1));
    if (x < getGrid()->getRows() - 1) //right
        neighbors.emplace_back(getGrid()->get(x + 1, y));
    if (y > 0) //down
        neighbors.emplace_back(getGrid()->get(x, y - 1));

    return neighbors;
}

