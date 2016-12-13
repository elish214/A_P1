//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Driver.h"

//using testing::Eq;

namespace {
    class DriverTests : public testing::Test {
    public:
        Driver *driver;

        DriverTests() {}

        virtual ~DriverTests() {

        }

    protected:
        virtual void SetUp() {
            driver = new Driver(123456, 32, MaritalStatus::MARRIED);
        }

        virtual void TearDown() {
            delete driver;
        }

    };
}

/**
 * driver get starting location and need to go there.
 */
TEST_F(DriverTests, testStart) {
    Point p1 = Point(0, 0);
    Point p3 = Point(1, 1);
    Location l1 = Location(p1);
    Location l3 = Location(p3);
    Passenger yossi = Passenger(l1, l3);
    TripInfo trip = TripInfo(333, 2, yossi);

    driver->start(trip);
    ASSERT_EQ(*driver->getLocation(), l1);
}

/**
 * driver get final location and need to go there.
 */
TEST_F(DriverTests, testDrive) {
    vector<Location*> v;
    Point p1 = Point(0, 0);
    Point p2 = Point(0, 1);
    Point p3 = Point(1, 1);
    Location l1 = Location(p1);
    Location l2 = Location(p2);
    Location l3 = Location(p3);

    v.push_back(&l1);
    v.push_back(&l2);
    v.push_back(&l3);
    driver->setLocation(l1);
    driver->drive(v);
    ASSERT_EQ(*driver->getLocation(), l3);
}

