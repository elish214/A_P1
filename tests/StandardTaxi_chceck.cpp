//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/StandardTaxi.h"

using testing::Eq;

namespace {
    class MySTaxiTests : public testing::Test {
    public:
        StandardTaxi staxi = StandardTaxi(12345, CarManufacturer::FIAT, Color::PINK);

        MySTaxiTests() {
        }
    };
}

TEST_F(MySTaxiTests, testSTaarif) {
    int t = staxi.getTaarif();
    ASSERT_TRUE(t >= 0);
}

TEST_F(MySTaxiTests, testSSpeed) {
    int t = staxi.getSpeed();
    ASSERT_TRUE(t >= 0);
}