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
        StandardTaxi stax = StandardTaxi(12345, CarManufacturer::FIAT, Color::PINK);

        MyTests() {
        }
    };
}

TEST_F(MyTests, testTaarif) {
    int t = stax.getTaarif();
    ASSERT_TRUE(t >= 0);
}
