//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/StandardTaxi.h"
#include "../src/taxi/LuxuryTaxi.h"

using testing::Eq;

namespace {
    class LTaxiTests : public testing::Test {
    public:
        LuxuryTaxi ltaxi = LuxuryTaxi(12345, CarManufacturer::TESLA, Color::RED);

        LTaxiTests() {
        }
    };
}

/**
 * test taarif getter.
 */
TEST_F(LTaxiTests, testLTaarif) {
    int s = ltaxi.getTaarif();
    ASSERT_TRUE(s >= 0);
}

/**
 * test speed getter.
 */
TEST_F(LTaxiTests, testLSpeed) {
    int s = ltaxi.getSpeed();
    ASSERT_TRUE(s >= 0);
}