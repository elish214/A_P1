//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TripInfo.h"

//using testing::Eq;

namespace {
    class TripInfoTests : public testing::Test {
    public:
        TripInfo *ti;
        Passenger *passenger;
        Location *source;
        Location *dest;

        TripInfoTests() {}

        virtual ~TripInfoTests() {

        }

        virtual void SetUp() {
            Point p1 = Point(0, 2);
            Point p2 = Point(0, 4);
            source = new Location(p1);
            dest = new Location(p2);
            passenger = new Passenger(source, dest);
            ti = new TripInfo(222, 3, *passenger);
        }

        virtual void TearDown() {
            delete ti;
            delete passenger;
            delete source;
            delete dest;
        }    
    };
}

TEST_F(TripInfoTests, testTotalMeters) {
    ASSERT_TRUE(ti->getTotalMeters() >= 0);
}


TEST_F(TripInfoTests, testNumOfPass) {
    ASSERT_TRUE(ti->getNumOfPassengers() >= 0);
}


TEST_F(TripInfoTests, testGetTaarif) {
    ASSERT_TRUE(ti->getTaarif() >= 0);
}
