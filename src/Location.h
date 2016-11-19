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

class Location: public Node {
private:
    Point p;
    Grid* grid;

public:
    Location();

    virtual ~Location();

    const Point &getPoint() const;

    void setPoint(const Point &p);

    Grid *getGrid() const;

    void setGrid(Grid *grid);

    list<Node*> neighbors();

    friend ostream &operator<<(ostream &os, const Location &location);

};


#endif //A_P1_LOCATION_H
