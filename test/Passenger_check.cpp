//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Passenger.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Passenger a = Passenger(Location(), Location());

        ClassDeclaration() {
        }
    };
}

TEST_F(ClassDeclaration, testRate) {
    int r = a.rate();
    ASSERT_TRUE(r<=5 && r>=1);
}