//
// Created by elish on 01/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Satisfaction.h"


using testing::Eq;

namespace {
    class MyTests : public testing::Test {
    public:
        Satisfaction st = Satisfaction(0,0);

        MyTests() {
        }
    };
}


TEST_F(MyTests, testGetter) {
    int r = st.getRating();
    ASSERT_TRUE(r >= 0);
}


TEST_F(MyTests, testRate) {
    st.rate(3);
    st.rate(5);

    ASSERT_EQ(st.getRating(), 4);
}
