//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"

//using testing::Eq;

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
    Location l = Location(1,1);
    vector<Node *> neighbors;

    Location l1 = Location(0,1);
    Location l2 = Location(1,2);
    Location l3 = Location(2,1);
    Location l4 = Location(1,0);

    l.setGrid(g);
    l1.setGrid(g);
    l2.setGrid(g);
    l3.setGrid(g);
    l4.setGrid(g);

    neighbors.push_back(&l1);
    neighbors.push_back(&l2);
    neighbors.push_back(&l3);
    neighbors.push_back(&l4);

    vector<Node *> actual = l.neighbors();

    for (int i = 0; i < actual.size(); ++i) {
        EXPECT_TRUE(*(actual.at(i)) == *(neighbors.at(i)));
    }
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
    Location l1 = Location(0, 1);
    Location l2 = Location(1, 2);

    l1.setGrid(g);
    l2.setGrid(g);

    ASSERT_FALSE(l1 == l2);
}

/**
 * testing non-equality operator.
 */
TEST_F(LocationTests, testLOperatorNE) {
    Location l1 = Location(0, 1);
    Location l2 = Location(1, 2);

    l1.setGrid(g);
    l2.setGrid(g);

    ASSERT_TRUE(l1 != l2);
}
