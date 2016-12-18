//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TaxiCenter.h"
#include "../src/taxi/StandardTaxi.h"

using testing::Eq;

namespace {
    class TaxiCenterTests : public testing::Test {
    public:
        TaxiCenter *TC;
        Driver *bob;
        StandardTaxi *taxi;
        Location *l1;
        //Location *l2;

        TaxiCenterTests() {}

        virtual ~TaxiCenterTests() {

        }

        virtual void SetUp() {
            TC = new TaxiCenter();
            bob = new Driver(123, 36, MaritalStatus::MARRIED,123);
            taxi = new StandardTaxi(123, CarManufacturer::SUBARU, Color::RED);
            l1 = new Location(0, 2);
            //l2 = new Location(1, 4);

            bob->setLocation(l1);

            TC->addTaxi(taxi);
            TC->addDriver(bob);
        }

        virtual void TearDown() {
            delete TC;
            delete l1;
            //delete l2;
        }    
    };
}

/**
 * testing adding a driver.
 */
TEST_F(TaxiCenterTests, testAddDriver) {

    unsigned long size = TC->getEmployees().size();

    ASSERT_TRUE(size > 0); // not empty.
}

/**
 * testing adding a taxi.
 */
TEST_F(TaxiCenterTests, testAddTaxi) {

    unsigned long size = TC->getCabs().size();
    ASSERT_TRUE(size > 0); // not empty.
}

/**
 * testing answer function.
 */
TEST_F(TaxiCenterTests, testAnswer) {
   /*
    currently isn't implemented.
    Passenger kobi = Passenger(l1, l2);
    Passenger other = TC->getFirstTrip().getPassenger();

    TC->answer(kobi);

    ASSERT_TRUE(other == kobi);
    */
}
