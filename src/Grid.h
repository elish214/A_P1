//
// Created by elish on 16/11/16.
//

#ifndef A_P1_GRID_H
#define A_P1_GRID_H

#include <array>
#include "Location.h" // call location header...

using namespace std;

class Grid {
private:
    Location** matrix;
    int rows;
    int cols;
public:
    Grid(int rows, int cols);

    Location **getMatrix() const;

    void setMatrix(Location **matrix);

};


#endif //A_P1_GRID_H
