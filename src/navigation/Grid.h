//
// Created by elish on 16/11/16.
//

#ifndef A_P1_GRID_H
#define A_P1_GRID_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

/**
 * Grid represent the 'map' on which the BFS search for the best route.
 * in our case it's a matrix of locations.
 */
class Grid {
private:
    Location ***matrix;
    int rows;
    int cols;
public:
    Grid(int rows, int cols);

    Grid(Point p) { Grid(p.getY(), p.getX()); }

    virtual ~Grid();

    Location ***getMatrix() const;

    void setMatrix(Location ***matrix);

    int getRows() const;

    int getCols() const;

    Location *get(int x, int y);

    Location *get(Point p);

    friend istream &operator>>(istream &is, Grid &grid);
};


#endif //A_P1_GRID_H