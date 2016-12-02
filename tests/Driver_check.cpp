//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Driver.h"
#include "../src/navigation/BFS.h"

using testing::Eq;

namespace {
    class MyDriverTests : public testing::Test {
    public:
        MyDriverTests() {}

        BFS bfs = BFS();
        vector<Location> v;
        Point p1 = Point(0,0);
        Point p2 = Point(0,1);
        Point p3 = Point(1,1);
        Location l1 = Location(p1);
        Location l2 = Location(p2);
        Location l3 = Location(p3);
        Driver Asher = Driver(123456,32,MaritalStatus::MARRIED);
        Passenger yossi = Passenger(l1,l3);
        TripInfo trip = TripInfo(333,2,yossi);
    };
}


TEST_F(MyDriverTests, testStart) {
    Asher.start(trip);
    ASSERT_EQ(Asher.getLocation(), l1);
}

TEST_F(MyDriverTests, testDrive){
    v.push_back(l1);
    v.push_back(l2);
    v.push_back(l3);
    Asher.setLocation(l1);
    Asher.drive(v);
    ASSERT_EQ(Asher.getLocation(),l3);
}

//add listeners tests?...

