//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TaxiCenter.h"
#include "../src/taxi/StandardTaxi.h"

using testing::Eq;

namespace {
    class MyTaxiCTests : public testing::Test {
    public:
        MyTaxiCTests() {}
        TaxiCenter TC = TaxiCenter();
        Driver bob = Driver(123456,36,MaritalStatus::MARRIED);
        StandardTaxi taxi = StandardTaxi(123, CarManufacturer::SUBARU, Color::RED);
        Point p1 = Point(0,2);
        Point p2 = Point(1,4);
        Location l1 = Location(p1);
        Location l2 = Location(p2);
        Passenger kobi = Passenger(l1,l2);
    };
}

TEST_F(MyTaxiCTests, testAddDriver) {

    TC.addDriver(bob);

    //ASSERT_TRUE(TC.getEmployees() != NULL); // not empty.
}


TEST_F(MyTaxiCTests, testAddTaxi) {

    TC.addTaxi(&taxi);

    //ASSERT_TRUE(TC.getCabs() != NULL); // not empty.
}


TEST_F(MyTaxiCTests, testConnect) {
    TC.connect(bob, &taxi);

    //ASSERT_TRUE(bob.getTaxi() != NULL);
}


TEST_F(MyTaxiCTests, testAnswer) {
    TC.answer(kobi);
    //ASSERT_TRUE(TC.getTrips().back().getPassenger == kobi);
}
