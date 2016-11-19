//
// Created by raz on 14/11/16.
//
#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(int x, int y) : x(x), y(y) {}

Point::~Point() {}

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

Point Point::operator+(const Point &p) const {
    return Point((x + p.getX()), (y + p.getY()));
}

Point Point::operator-(const Point &p) const {
    return Point((x - p.getX()), (y - p.getY()));
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

istream &operator>>(istream &is, Point &point) {
    string s;

    getline(is, s, '_');
    point.x = stoi(s);
    getline(is, s, '\n');
    point.y = stoi(s);

    return is;
}

ostream &operator<<(ostream &os, const Point &point) {
    os << "(" << point.x << "," << point.y << ")";
    return os;
}
