//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/TaxiCenter.h"

using testing::Eq;

namespace {
    class MyTests : public testing::Test {
    public:
        TaxiCenter TC = TaxiCenter();
        Driver bob = Driver(123456,36,MaritalStatus::MARRIED);
        Taxi taxi = Taxi(123, CarManufacturer::SUBARU, Color::RED);

        MyTests() {
        }
    };
}

TEST_F(MyTests, testAddDriver) {

    TC.addDriver(bob);

    ASSERT_TRUE(TC.getEmployees().front() != NULL); // not empty.
}


TEST_F(MyTests, testAddTaxi) {

    TC.addTaxi(&taxi);

    ASSERT_TRUE(TC.getCabs().front() != NULL); // not empty.
}


TEST_F(MyTests, testConnect) {
    TC.connect(bob, &taxi);

    ASSERT_TRUE(bob.getTaxi() != NULL);
}


TEST_F(MyTests, testAnswer) {

}
