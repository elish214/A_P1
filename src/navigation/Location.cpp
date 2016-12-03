//
// Created by elish on 16/11/16.
//

#include <vector>
#include "Grid.h"

using namespace std;

/**
 * constructor.
 *
 * @return a location.
 */
Location::Location() {}

Location::Location(Point &point) {
    Location::p = &point;
}

/**
 * getter.
 *
 * @return a constant point.
 */
Point *Location::getPoint() {
    return p;
}

/**
 * destructor.
 */
Location::~Location() {
    //delete p;

}

/**
 * setter.
 *
 * @param p a constant point.
 */
void Location::setPoint(Point *p) {
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
vector<Node *> Location::neighbors() {
    int x = getPoint()->getX();
    int y = getPoint()->getY();

    vector<Node *> neighbors;

    if (x > 0) //left
        neighbors.push_back(getGrid()->get(x - 1, y));
    if (y < getGrid()->getRows() - 1) //up
        neighbors.push_back(getGrid()->get(x, y + 1));
    if (x < getGrid()->getCols() - 1) //right
        neighbors.push_back(getGrid()->get(x + 1, y));
    if (y > 0) //down
        neighbors.push_back(getGrid()->get(x, y - 1));

    return neighbors;
}


/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param location a constant location.
 * @return output stream.
 */
ostream &operator<<(ostream &os, Location &location) {
    os << location.getPoint();
    return os;
}

/**
 * == operator
 * @param rhs to compare
 * @return true/false
 */
bool Location::operator==(const Location &rhs) const {
    return this == &rhs &&
           p == rhs.p &&
           grid == rhs.grid;
}

/**
 * != operator
 * @param rhs to compare
 * @return true/false
 */
bool Location::operator!=(const Location &rhs) const {
    return !(rhs == *this);
}

/**
 * << for sub class.
 * @param os ostream
 * @return ostream with location
 */
ostream &Location::toString(ostream &os) const {
    os << *p;
    return os;
}

