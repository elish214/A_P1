//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/taxi/StandardTaxi.h"

//using testing::Eq;

namespace {
    class STaxiTests : public testing::Test {
    public:
        StandardTaxi *staxi;

        STaxiTests() {
        }

        virtual ~STaxiTests() {

        }

        virtual void SetUp() {
            staxi = new StandardTaxi(12345, CarManufacturer::FIAT, Color::PINK);
        }

        virtual void TearDown() {
            delete staxi;
        }  
    };
}

/**
 * testing taarif getter.
 */
TEST_F(STaxiTests, testSTaarif) {
    int t = staxi->getTaarif();
    ASSERT_TRUE(t >= 0);
}

/**
 * testing speed getter.
 */
TEST_F(STaxiTests, testSSpeed) {
    int t = staxi->getSpeed();
    ASSERT_TRUE(t >= 0);
}
