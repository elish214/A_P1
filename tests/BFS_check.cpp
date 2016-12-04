//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
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
        Location l1 = *g.get(0, 0);
        Location l2 = *g.get(0, 1);
        Location l3 = *g.get(0, 2);
        Location l4 = *g.get(1, 2);
    };

}

/**
 * testing BFS algorithem.
 */
TEST_F(BFSTests, testRun) {
    vector<Node*> s;

    s.push_back(&l1);
    s.push_back(&l2);
    s.push_back(&l3);
    s.push_back(&l4);

    vector<Node*> actual = bfs.run(&l1, &l4);

    for (int i = 0; i < actual.size(); ++i) {
        EXPECT_TRUE(*(actual.at(i)) == *(s.at(i)));
    }
}