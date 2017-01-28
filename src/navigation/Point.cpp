//
// Created by raz on 14/11/16.
//
#include <iostream>
#include "Point.h"
#include "../validation/Checker.h"
#include "../validation/Validator.h"
#include "../validation/RangeNumericChecker.h"

#define  ERROR -1

using namespace std;

/**
 * constructor.
 *
 * @param x an integer.
 * @param y an integer.
 * @return a point.
 */
Point::Point(int x, int y) : x(x), y(y) {}

/**
 * constructor.
 *
 * @param p another point.
 */
Point::Point(const Point &p) {
    x = p.getX();
    y = p.getY();
}

/**
 * destructor.
 */
Point::~Point() {}

/**
 * getter.
 *
 * @return x axes value.
 */
int Point::getX() const {
    return x;
}

/**
 * setter.
 *
 * @param x an integer.
 */
void Point::setX(int x) {
    Point::x = x;
}

/**
 * getter.
 *
 * @return y axes value.
 */
int Point::getY() const {
    return y;
}

/**
 * setter.
 *
 * @param y an integer.
 */
void Point::setY(int y) {
    Point::y = y;
}

/**
 * method overloading for operator '+'.
 *
 * @param p another point.
 * @return new point.
 */
Point Point::operator+(const Point &p) const {
    return Point((x + p.getX()), (y + p.getY()));
}

/**
 * method overloading for operator '-'.
 *
 * @param p another point.
 * @return new point.
 */
Point Point::operator-(const Point &p) const {
    return Point((x - p.getX()), (y - p.getY()));
}

/**
 * method overloading for operator '=='.
 *
 * @param rhs another point.
 * @return whether it equals to current point or not.
 */
bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

/**
 * method overloading for operator '!='.
 *
 * @param rhs another point.
 * @return whether it isn't equals to current point or not.
 */
bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

/**
 * method overloading for operator '>>'.
 *
 * @param is input stream.
 * @param point a point.
 * @return input stream.
 */
istream &operator>>(istream &is, Point &point) {
    string s;
    bool valid;
    vector<Checker *> checkers;
    Validator v;

    checkers.emplace_back(new RangeNumericChecker(0, INT_MAX));
    checkers.emplace_back(new RangeNumericChecker(0, INT_MAX));

    is >> s;

    valid = v.validate(s, checkers, ',');

    for (unsigned int k = 0; k < checkers.size(); k++) {
        delete checkers[k];
    }

    checkers.clear();

    if (!valid) {
        point.x = ERROR;
        return is;
    }

    istringstream ss(s);

    getline(ss, s, ',');
    point.x = stoi(s.c_str());

    getline(ss, s, '\n');
    point.y = stoi(s.c_str());

    return is;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param point a point.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const Point &point) {
    os << "(" << point.x << "," << point.y << ")";
    return os;
}

/**
 * method overloading for operator '<'.
 *
 * @param rhs a point.
 * @return true if smaller. false otherwise.
 */
bool Point::operator<(const Point &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    return y < rhs.y;
}

/**
 * method overloading for operator '>'.
 *
 * @param rhs a point.
 * @return true if bigger. false otherwise.
 */
bool Point::operator>(const Point &rhs) const {
    return rhs < *this;
}

/**
 * method overloading for operator '<='.
 *
 * @param rhs a point.
 * @return true if smaller or equal. false otherwise.
 */
bool Point::operator<=(const Point &rhs) const {
    return !(rhs < *this);
}

/**
 * method overloading for operator '>='.
 *
 * @param rhs a point.
 * @return true if bigger or equal. false otherwise.
 */
bool Point::operator>=(const Point &rhs) const {
    return !(*this < rhs);
}

