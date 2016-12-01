//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/StandardTaxi.h"

using testing::Eq;

namespace {
    class MyTests : public testing::Test {
    public:
        StandardTaxi ltax = StandardTaxi(12345, CarManufacturer::TESLA, Color::RED);

        MyTests() {
        }
    };
}

TEST_F(MyTests, testSpeed) {
    int s = ltax.getSpeed();
    ASSERT_TRUE(s >= 0);
}