//
// Created by raz on 14/11/16.
//

#ifndef PROJECT_POINT_H
#define PROJECT_POINT_H

#include <iostream>

using namespace std;

/**
 * Point represent a 2-dimensional point.
 * it has x axes and a y axes integer values.
 */
class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0);

    virtual ~Point();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    Point operator+(const Point &p) const;

    Point operator-(const Point &p) const;

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    friend istream &operator>>(istream &os, Point &point);

    friend ostream &operator<<(ostream &os, const Point &point);
};


#endif //PROJECT_POINT_H
