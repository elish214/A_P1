//
// Created by elish on 16/11/16.
//

#ifndef A_P1_GRID_H
#define A_P1_GRID_H

#include <array>
#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Grid {
private:
    Location **matrix;
    int rows;
    int cols;
public:
    Grid(int rows, int cols);

    Grid(Point p) : Grid(p.getY(), p.getX()) {}

    virtual ~Grid();

    Location **getMatrix() const;

    void setMatrix(Location **matrix);

    int getRows() const;

    int getCols() const;

    Location& get(int x, int y);

    Location& get(Point p);

    friend istream &operator>>(istream &is, Grid &grid);
};


#endif //A_P1_GRID_H
