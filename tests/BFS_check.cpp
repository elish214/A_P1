//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stack>
#include "../src/navigation/Grid.h"
#include "../src/navigation/BFS.h"

using testing::Eq;

namespace {
    class BFSTests : public testing::Test {
    protected:

    public:
        BFSTests() {}
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

/**
 * testing BFS algorithem.
 */
TEST_F(BFSTests, testRun) {
    vector<Node*> s;

    l1.setGrid(&g);
    l2.setGrid(&g);
    l3.setGrid(&g);
    l4.setGrid(&g);

    s.push_back(&l4);
    s.push_back(&l3);
    s.push_back(&l2);
    s.push_back(&l1);

    vector<Node*> actual = bfs.run(&l1, &l4);

    EXPECT_THAT(actual, ::testing::ContainerEq(s));

  /*  //ASSERT_THAT(bfs.run(&l1, &l4), s);

    for(int i = 0; i < actual.size(); ++i) {
        EXPECT_EQ(actual.top(), s.top());

    }*/
}