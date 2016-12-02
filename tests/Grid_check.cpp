//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"

using testing::Eq;

namespace {
    class MyGridTests : public testing::Test {
    public:
        MyGridTests() {}
        Grid g = Grid(7,8);
    };
}

TEST_F(MyGridTests, testGetR) {
    ASSERT_EQ(g.getRows(), 7);
}

TEST_F(MyGridTests, testGetC) {
    ASSERT_EQ(g.getCols(), 8);
}

TEST_F(MyGridTests, testGOperatorIS) {
    //istream test.
}
