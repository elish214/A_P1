//
// Created by elish on 16/11/16.
//

#include "Grid.h"

/**
 * constructor.
 *
 * @param rows matrix's rows.
 * @param cols matrix's collumns.
 * @return a grid.
 */
Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
    matrix = new Location **[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new Location *[cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = new Location();
            matrix[i][j]->setGrid(this);
            matrix[i][j]->setPoint(new Point(j, i));
        }
    }
}

/**
 * destructor.
 */
Grid::~Grid() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * getter.
 *
 * @return grid's matrix.
 */
Location ***Grid::getMatrix() const {
    return matrix;
}

/**
 * setter.
 *
 * @param matrix a location's matrix.
 */
void Grid::setMatrix(Location ***matrix) {
    Grid::matrix = matrix;
}

/**
 * getter.
 *
 * @return grid's rows.
 */
int Grid::getRows() const {
    return rows;
}

/**
 * getter.
 *
 * @return grid's collumns.
 */
int Grid::getCols() const {
    return cols;
}

/**
 * getter.
 *
 * @param x an integer.
 * @param y an integer.
 * @return specific location on grid.
 */
Location *Grid::get(int x, int y) {
    return matrix[y][x];
}

/**
 * getter.
 *
 * @param p a point.
 * @return specific location on grid.
 */
Location *Grid::get(Point p) {
    return get(p.getX(), p.getY());
}

/**
 * method overloading for operator '>>'.
 *
 * @param is input stream.
 * @param grid a grid.
 * @return input stream.
 */
istream &operator>>(istream &is, Grid &grid) {
    Point point;

    is >> point;
    grid = Grid(point);

    return is;
}
