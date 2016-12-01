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
        Grid g = Grid(7,8);

        MyTests() {
        }
    };
}

TEST_F(MyTests, testGetR) {
    ASSERT_EQ(g.getRows(), 7);
}

TEST_F(MyTests, testGetC) {
    ASSERT_EQ(g.getCols(), 8);
}
