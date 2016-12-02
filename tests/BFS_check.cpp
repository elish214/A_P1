//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stack>
#include "../src/navigation/Grid.h"
#include "../src/navigation/BFS.h"
#include "../src/navigation/Location.h"
#include "../src/navigation/BFS.h"

using testing::Eq;

namespace {
    class MyBFSTests : public testing::Test {
    protected:

    public:
        MyBFSTests() {}
        Grid g = Grid(3,3);
        BFS bfs;
        Point p1 = Point(0,0);
        Location l1 = Location(p1);
        Point p2 = Point(0,1);
        Location l2 = Location(p2);
        Point p3 = Point(0,2);
        Location l3 = Location(p3);
        Point p4 = Point(1,2);
        Location l4 = Location(p4);
    };

}

TEST_F(MyBFSTests, testRun){
    stack<Node*> s;

    l1.setGrid(&g);
    l4.setGrid(&g);

    s.push(&l4);
    s.push(&l3);
    s.push(&l2);
    s.push(&l1);

    ASSERT_EQ(bfs.run(&l1,&l4), s);
}