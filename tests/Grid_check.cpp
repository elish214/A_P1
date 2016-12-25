//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"

//using testing::Eq;

namespace {
    class GridTests : public testing::Test {
    public:
        Grid *g;

        GridTests() {}

        virtual ~GridTests() {

        }

        virtual void SetUp() {
            g = new Grid(7, 7);
        }

        virtual void TearDown() {
            delete g;
        }
        
    };
}

/**
 * testing rows getter.
 */
TEST_F(GridTests, testGetR) {

    ASSERT_EQ(g->getRows(), 7);
}

/**
 * testing columns getter.
 */
TEST_F(GridTests, testGetC) {

    ASSERT_EQ(g->getCols(), 7);
}

/**
 * testing istream operator.
 */
TEST_F(GridTests, testGOperatorIS) {
    //istream test.
}
