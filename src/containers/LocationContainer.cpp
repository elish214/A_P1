//
// Created by raz on 30/12/16.
//

#include "LocationContainer.h"

LocationContainer::LocationContainer() {}

LocationContainer::LocationContainer(Point *p) : p(p) {}

Point *LocationContainer::getPoint() const {
    return p;
}

ostream &operator<<(ostream &os, const LocationContainer &container) {
    os << *(container.p);
    return os;
}
