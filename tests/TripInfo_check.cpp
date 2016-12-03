//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TripInfo.h"

using testing::Eq;

namespace {
    class TripInfoTests : public testing::Test {
    public:
        TripInfoTests() {}
        Point p1 = Point(0,2);
        Point p2 = Point(0,4);
        Location source = Location(p1);
        Location dest = Location(p2);
        Passenger passenger = Passenger(source, dest);
        TripInfo ti = TripInfo(222,3,passenger);
    };
}

TEST_F(TripInfoTests, testTotalMeters) {
    ASSERT_TRUE(ti.getTotalMeters() >= 0);
}


TEST_F(TripInfoTests, testNumOfPass) {
    ASSERT_TRUE(ti.getNumOfPassengers() >= 0);
}


TEST_F(TripInfoTests, testGetTaarif) {
    ASSERT_TRUE(ti.getTaarif() >= 0);
}
