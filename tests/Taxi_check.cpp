//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/Taxi.h"

using testing::Eq;


namespace {
    class MyTests : public testing::Test {
    public:
    Taxi taxi = Taxi(12345, CarManufacturer::HONDA, Color::BLUE);
        MyTests() {
        }
    };
}


TEST_F(MyTests, testMeter) {
    taxi.addMeters(18.7);
    taxi.addMeters(6.5);

    ASSERT_EQ(taxi.getKmPassed(), 25.2);
}
