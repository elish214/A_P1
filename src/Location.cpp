//
// Created by elish on 16/11/16.
//

#include <list>
#include "Grid.h"

using namespace std;
/**
 * constructor.
 *
 * @return a location.
 */
Location::Location() {}

/**
 * getter.
 *
 * @return a constant point.
 */
const Point &Location::getPoint() const {
    return p;
}

/**
 * destructor.
 */
Location::~Location() {
    delete &p;
}

/**
 * setter.
 *
 * @param p a constant point.
 */
void Location::setPoint(const Point &p) {
    Location::p = p;
}

/**
 * getter.
 *
 * @return the grid.
 */
Grid *Location::getGrid() const {
    return grid;
}

/**
 * setter.
 *
 * @param grid a grid.
 */
void Location::setGrid(Grid *grid) {
    Location::grid = grid;
}

/**
 * returns location's neighbors.
 *
 * @return location's neighbors.
 */
list<Node*> Location::neighbors(){
    int x = getPoint().getX();
    int y = getPoint().getY();

    std::list<Node*> neighbor;

    if (x > 0) //left
        neighbor.emplace_back(&getGrid()->get(x - 1, y));
    if (y < getGrid()->getCols() - 1) //up
        neighbor.emplace_back(&getGrid()->get(x, y + 1));
    if (x < getGrid()->getRows() - 1) //right
        neighbor.emplace_back(&getGrid()->get(x + 1, y));
    if (y > 0) //down
        neighbor.emplace_back(&getGrid()->get(x, y - 1));

    return neighbor;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param location a constant location.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const Location &location) {
    os << location.p;
    return os;
}

