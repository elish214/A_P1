//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Passenger.h"

//using testing::Eq;

namespace {
    class PassengerTests : public testing::Test {
    public:
        Passenger *avi;
        Location *l1;
        Location *l2;

        PassengerTests() {}

        virtual ~PassengerTests() {

        }

        virtual void SetUp() {
            l1 = new Location(3,8);
            l2 = new Location(2,6);
            avi = new Passenger(l1, l2);
        }

        virtual void TearDown() {
            delete avi;
            delete l1;
            delete l2;
        }  
    };
}

/**
 * testing getter.
 */
TEST_F(PassengerTests, testGetters) {
    ASSERT_EQ(*avi->getSource(), *l1);

}

/**
 * testing rate function.
 */
TEST_F(PassengerTests, testRate) {
    int r = avi->rate();
    ASSERT_TRUE(r<=5 && r>=1);
}
