//
// Created by elish on 16/11/16.
//

#ifndef A_P1_LOCATION_H
#define A_P1_LOCATION_H


#include "Point.h"
#include "Node.h"
#include "Grid.h"
// doesnt call grid header cause already defined, so doesnt recognize it's constructor.....

using namespace std;

class Location: public Node {
private:
    Point p;
    Grid* grid;

public:
    Location();

    const Point &getP() const;

    void setPoint(const Point &p);

    Grid *getGrid() const;

    void setGrid(Grid *grid);

    list<Node> neighbors();

};


#endif //A_P1_LOCATION_H
