//
// Created by elish on 16/11/16.
//

#ifndef A_P1_LOCATION_H
#define A_P1_LOCATION_H


#include <iostream>
#include <string>
#include "Point.h"
#include "Node.h"

using namespace std;

class Grid;

/**
 * Location represent a node on the grid.
 * in our case, location is a coordinate in the matrix.
 */
class Location: public Node {
private:
    Point *p;
    Grid *grid;

protected:
    ostream &toString(ostream &os) const;

public:

    Location();

    Location(Point &point);

    virtual ~Location();

    Point *getPoint() ;

    void setPoint(Point *p);

    Grid *getGrid() const;

    void setGrid(Grid *grid);

    vector<Node *> neighbors();

    friend ostream &operator<<(ostream &os, Location &location);

    bool operator==(const Location &rhs) const;

    bool operator!=(const Location &rhs) const;
};


#endif //A_P1_LOCATION_H
