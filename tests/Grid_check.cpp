//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"

using testing::Eq;

namespace {
    class GridTests : public testing::Test {
    public:
        GridTests() {}
        Grid g = Grid(7,8);
    };
}

TEST_F(GridTests, testGetR) {
    ASSERT_EQ(g.getRows(), 7);
}

TEST_F(GridTests, testGetC) {
    ASSERT_EQ(g.getCols(), 8);
}

TEST_F(GridTests, testGOperatorIS) {
    //istream test.
}
