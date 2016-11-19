//
// Created by elish on 16/11/16.
//

#include "Grid.h"

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
    Location** matrix = new Location*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new Location[cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j].setGrid(this);
            matrix[i][j].setPoint(Point(i, j));
        }
    }
}

Grid::~Grid() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete &getMatrix()[i][j];
        }
        delete getMatrix()[i];
    }
    delete getMatrix();
}

Location **Grid::getMatrix() const {
    return matrix;
}

void Grid::setMatrix(Location **matrix) {
    Grid::matrix = matrix;
}

int Grid::getRows() const {
    return rows;
}

int Grid::getCols() const {
    return cols;
}

Location& Grid::get(int x, int y) {
    return getMatrix()[y][x];
}

Location& Grid::get(Point p) {
    return get(p.getX(), p.getY());
}

istream &operator>>(istream &is, Grid &grid) {
    Point point;

    is >> point;
    grid = Grid(point);

    return is;
}
