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
        Point obj;

        ClassDeclaration() {
            obj = Point(5, 6);
        }
    };
}

TEST_F(ClassDeclaration, testX) {
    ASSERT_EQ(obj.getX(), 5);
}

TEST_F(ClassDeclaration, testY) {
    ASSERT_EQ(obj.getY(), 6);
}