//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Passenger.h"

using testing::Eq;

namespace {
    class MyPassengerTests : public testing::Test {
    public:
        MyPassengerTests() {}
        Point p1 = Point(3,8);
        Point p2 = Point(2,6);
        Location l1 = Location(p1);
        Location l2 = Location(p2);
        Passenger avi = Passenger(l1, l2);

    };
}


TEST_F(MyPassengerTests, testGetters) {
    ASSERT_EQ(avi.getSource(), l1);

}

TEST_F(MyPassengerTests, testRate) {
    int r = avi.rate();
    ASSERT_TRUE(r<=5 && r>=1);
}
