//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Satisfaction.h"

//using testing::Eq;

namespace {
    class SatisfactionTests : public testing::Test {
    public:
        Satisfaction *st;

        SatisfactionTests() {
        }

        virtual ~SatisfactionTests() {

        }

        virtual void SetUp() {
            st = new Satisfaction(0, 0);
        }

        virtual void TearDown() {
            delete st;
        }  
    };
}

/**
 * testing getter.
 */
TEST_F(SatisfactionTests, testGetter) {
    double r = st->getRating();
    ASSERT_TRUE(r >= 0);
}

/**
 * testing rating function.
 */
TEST_F(SatisfactionTests, testRating) {
    st->rate(3);
    st->rate(5);

    ASSERT_EQ(st->getRating(), 4);
}
