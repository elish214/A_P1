//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Driver.h"
#include "../src/navigation/BFS.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Driver d = Driver(123456,32,MaritalStatus::MARRIED);

        ClassDeclaration() {
        }
    };
}

TEST_F(ClassDeclaration, testStart){
    Point p1 = Point(0,0);
    Point p2 = Point(2,2);
    TripInfo ti = TripInfo(123,2, Passenger(Location(p1),Location(p2)));
    d.start(ti);
    ASSERT_TRUE();//not sure what to check?!
}

TEST_F(ClassDeclaration, testDrive){
    Point p1 = Point(0,0);
    Point p2 = Point(2,2);
    BFS bfs = BFS();
    //vector<Location> v = bfs.run(Location(p1), Location(p2));
    //d.drive();
}