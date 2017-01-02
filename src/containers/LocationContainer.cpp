//
// Created by raz on 30/12/16.
//

#include "LocationContainer.h"

/**
 * constructor.
 */
LocationContainer::LocationContainer() {}

/**
 * constructor.
 *
 * @param p a point.
 */
LocationContainer::LocationContainer(Point *p) : p(p) {}


/**
 * destructor.
 */
LocationContainer::~LocationContainer() {
    //delete p;
}

/**
 * returns container's point.
 *
 * @return  container's point.
 */
Point *LocationContainer::getPoint() const {
    return p;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param container a container.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const LocationContainer &container) {
    os << *(container.p);
    return os;
}

