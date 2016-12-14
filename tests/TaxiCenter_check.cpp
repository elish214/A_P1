//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TaxiCenter.h"
#include "../src/taxi/StandardTaxi.h"

//using testing::Eq;

namespace {
    class TaxiCenterTests : public testing::Test {
    public:
        TaxiCenter *TC;
        Driver *bob;
        StandardTaxi *taxi;
        Location *l1;
        Location *l2;

        TaxiCenterTests() {}

        virtual ~TaxiCenterTests() {

        }

        virtual void SetUp() {
            TC = new TaxiCenter();
            bob = new Driver(123456, 36, MaritalStatus::MARRIED);
            taxi = new StandardTaxi(123, CarManufacturer::SUBARU, Color::RED);
            Point p1 = Point(0, 2);
            Point p2 = Point(1, 4);
            l1 = new Location(p1);
            l2 = new Location(p2);
        }

        virtual void TearDown() {
            delete TC;
            delete bob;
            delete taxi;
            delete l1;
            delete l2;
        }    
    };
}

/**
 * testing adding a driver.
 */
TEST_F(TaxiCenterTests, testAddDriver) {

    TC->addDriver(bob);

    ASSERT_TRUE(TC->getEmployees().size() > 0); // not empty.
}

/**
 * testing adding a taxi.
 */
TEST_F(TaxiCenterTests, testAddTaxi) {

    TC->addTaxi(taxi);

    ASSERT_TRUE(TC->getCabs().size() > 0); // not empty.
}

/**
 * testing connecting between taxi and a driver.
 */
TEST_F(TaxiCenterTests, testConnect) {
    TC->connect(*bob, taxi);

    ASSERT_TRUE(bob->getTaxi() != NULL);
}

/**
 * testing anser function.
 */
TEST_F(TaxiCenterTests, testAnswer) {
    Passenger kobi = Passenger(l1, l2);
    Passenger other = TC->getFirstTrip().getPassenger();

    TC->answer(kobi);

    ASSERT_TRUE(other == kobi);
}
