//
// Created by raz on 29/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/navigation/Point.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Point p1, p2;

        ClassDeclaration() {
            p1 = Point(5, 6);
            p2 = Point(2, 4);
        }
    };
}

TEST_F(ClassDeclaration, testX) {
    ASSERT_EQ(p1.getX(), 5);
}

TEST_F(ClassDeclaration, testY) {
    ASSERT_EQ(p1.getY(), 6);
}


TEST_F(ClassDeclaration, testYOperatorPlus) {
    Point p3 = p1 + p2;
    ASSERT_EQ(p3, Point(7, 10));
}


TEST_F(ClassDeclaration, testYOperatorMinus) {
    Point p3 = p1 - p2;
    ASSERT_EQ(p3, Point(3, 2));
}

TEST_F(ClassDeclaration, testYOperatorEQ) {
    Point p3 = Point(5,6);
    ASSERT_TRUE(p1 == p3);
}

TEST_F(ClassDeclaration, testYOperatorNE) {
Point p3 = Point(5,9);
ASSERT_TRUE(p1 != p3);
}