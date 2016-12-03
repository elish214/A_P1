//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/StandardTaxi.h"

using testing::Eq;

namespace {
    class STaxiTests : public testing::Test {
    public:
        StandardTaxi staxi = StandardTaxi(12345, CarManufacturer::FIAT, Color::PINK);

        STaxiTests() {
        }
    };
}

TEST_F(STaxiTests, testSTaarif) {
    int t = staxi.getTaarif();
    ASSERT_TRUE(t >= 0);
}

TEST_F(STaxiTests, testSSpeed) {
    int t = staxi.getSpeed();
    ASSERT_TRUE(t >= 0);
}