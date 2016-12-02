//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"

using testing::Eq;

namespace {
    class MyLocationTests : public testing::Test {
    public:
        MyLocationTests() {}
        Grid g = Grid(3,3);
        Point p = Point(1,1);
        Location l = Location(p);
        vector<Node *> neighbors;
        Point p1 = Point(0,1);
        Point p2 = Point(1,2);
        Point p3 = Point(2,1);
        Point p4 = Point(1,0);
        Location l1 = Location(p1);
        Location l2 = Location(p2);
        Location l3 = Location(p3);
        Location l4 = Location(p4);

    };
}

TEST_F(MyLocationTests, testNeighbors) {

    l1.setGrid(&g);
    l2.setGrid(&g);
    l3.setGrid(&g);
    l4.setGrid(&g);

    neighbors.push_back(&l1);
    neighbors.push_back(&l2);
    neighbors.push_back(&l3);
    neighbors.push_back(&l4);

    ASSERT_EQ(neighbors, l.neighbors());
}

TEST_F(MyLocationTests, testLOperatorOS) {
    //ostream test.
}

TEST_F(MyLocationTests, testLOperatorEQ) {

    ASSERT_FALSE(l1 == l2);
}

TEST_F(MyLocationTests, testLOperatorNE) {

    ASSERT_TRUE(l1 != l2);
}
