//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"

using testing::Eq;

namespace {
    class MyTests : public testing::Test {
    public:

        MyTests() {
        }
    };
}

TEST(MyTests, testNeighbors) {
    Grid g = Grid(3,3);
    Point p = Point(1,1);
    Location l = Location(p);

    vector<Node *> neighbors;
    Point p1 = Point(0,1);
    Point p2 = Point(1,2);
    Point p3 = Point(2,1);
    Point p4 = Point(1,0);
    neighbors.emplace_back(Location(p1));
    neighbors.emplace_back(Location(p2));
    neighbors.emplace_back(Location(p3));
    neighbors.emplace_back(Location(p4));

    ASSERT_EQ(neighbors, l.neighbors());
}

TEST(MyTests, testOperatorEQ) {
    Grid g = Grid(3,3);
    Point p1 = Point(1,1);
    Location l1 = Location(p1);
    l1.setGrid(&g);
    Location l2 = Location(p1);
    l2.setGrid(&g);

    ASSERT_TRUE(l1 == l2);
}

TEST(MyTests, testOperatorNE) {
    Grid g = Grid(3,3);
    Point p1 = Point(1,1);
    Point p2 = Point(1,7);
    Location l1 = Location(p1);
    l1.setGrid(&g);
    Location l2 = Location(p2);
    l2.setGrid(&g);

    ASSERT_TRUE(l1 != l2);
}
