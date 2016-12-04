//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"

using testing::Eq;

namespace {
    class LocationTests : public testing::Test {
    public:
        Grid *g;

        LocationTests() {}

        virtual ~LocationTests() {

        }

    protected:
        virtual void SetUp() {
            g = new Grid(3, 3);
        }

        virtual void TearDown() {
            delete g;
        }
    };
}

/**
 * get location's neibghours.
 */
TEST_F(LocationTests, testNeighbors) {
    Point p = Point(1, 1);
    Location l = Location(p);
    vector<Node *> neighbors;

    Point p1 = Point(0, 1);
    Point p2 = Point(1, 2);
    Point p3 = Point(2, 1);
    Point p4 = Point(1, 0);

    Location l1 = Location(p1);
    Location l2 = Location(p2);
    Location l3 = Location(p3);
    Location l4 = Location(p4);

    l.setGrid(g);
    l1.setGrid(g);
    l2.setGrid(g);
    l3.setGrid(g);
    l4.setGrid(g);

    neighbors.push_back(&l1);
    neighbors.push_back(&l2);
    neighbors.push_back(&l3);
    neighbors.push_back(&l4);

    ASSERT_THAT(neighbors, l.neighbors());
}

/**
 * testing ostream operator.
 */
TEST_F(LocationTests, testLOperatorOS) {
    //ostream test.
}

/**
 * testing equality operator.
 */
TEST_F(LocationTests, testLOperatorEQ) {
    Point p1 = Point(0, 1);
    Point p2 = Point(1, 2);

    Location l1 = Location(p1);
    Location l2 = Location(p2);

    l1.setGrid(g);
    l2.setGrid(g);

    ASSERT_FALSE(l1 == l2);
}

/**
 * testing non-equality operator.
 */
TEST_F(LocationTests, testLOperatorNE) {
    Point p1 = Point(0, 1);
    Point p2 = Point(1, 2);

    Location l1 = Location(p1);
    Location l2 = Location(p2);

    l1.setGrid(g);
    l2.setGrid(g);

    ASSERT_TRUE(l1 != l2);
}
