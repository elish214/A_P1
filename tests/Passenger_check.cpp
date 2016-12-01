//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Passenger.h"

using testing::Eq;

namespace {
    class MyTests : public testing::Test {
    public:
        Location l1 = Location();
        Location l2 = Location();
        Passenger a = Passenger(l1, l2);

        MyTests() {
        }
    };
}

TEST_F(MyTests, testRate) {
    int r = a.rate();
    ASSERT_TRUE(r<=5 && r>=1);
}
