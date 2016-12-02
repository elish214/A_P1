//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/Taxi.h"
#include "../src/taxi/StandardTaxi.h"

using testing::Eq;


namespace {
    class MyTaxiTests : public testing::Test {
    public:
    StandardTaxi taxi = StandardTaxi(12345, CarManufacturer::HONDA, Color::BLUE);
        MyTaxiTests() {
        }
    };
}


TEST_F(MyTaxiTests, testMeter) {
    taxi.addMeters(18.7);
    taxi.addMeters(6.5);

    ASSERT_EQ(taxi.getKmPassed(), 25.2);
}
