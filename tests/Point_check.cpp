//
// Created by raz on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/navigation/Point.h"

using testing::Eq;

namespace {
    class MyPointTests : public testing::Test {

    public:
        //Point p1, p2;
        Point p1 = Point(5, 6);
        Point p2 = Point(2, 4);

        MyPointTests() {

        }
    };
}

TEST_F(MyPointTests, testX) {
    ASSERT_EQ(p1.getX(), 5);
}

TEST_F(MyPointTests, testY) {
    ASSERT_EQ(p1.getY(), 6);
}


TEST_F(MyPointTests, testYOperatorPlus) {
    Point p3 = p1 + p2;
    ASSERT_EQ(p3, Point(7, 10));
}


TEST_F(MyPointTests, testYOperatorMinus) {
    Point p3 = p1 - p2;
    ASSERT_EQ(p3, Point(3, 2));
}

TEST_F(MyPointTests, testYOperatorEQ) {
    Point p3 = Point(5,6);
    ASSERT_TRUE(p1 == p3);
}

TEST_F(MyPointTests, testYOperatorNE) {
Point p3 = Point(5,9);
ASSERT_TRUE(p1 != p3);
}

