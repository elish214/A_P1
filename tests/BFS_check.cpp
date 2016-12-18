//
// Created by elish on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/navigation/Grid.h"
#include "../src/navigation/BFS.h"

//using testing::Eq;

namespace {
    class BFSTests : public testing::Test {
    public:
        Grid *g;
        BFS *bfs;
        Location *l1;
        Location *l2;
        Location *l3;
        Location *l4;

        BFSTests() {}

        virtual ~BFSTests() {

        }

        virtual void SetUp() {
            g = new Grid(3, 3);
            bfs = new BFS();
            l1 = g->get(0, 0);
            l2 = g->get(0, 1);
            l3 = g->get(0, 2);
            l4 = g->get(1, 2);
        }

        virtual void TearDown() {
            delete g;
            delete bfs;
        } 
    };

}

/**
 * testing BFS algorithm.
 */
TEST_F(BFSTests, testRun) {

    vector<Node*> s;

    s.push_back(l1);
    s.push_back(l2);
    s.push_back(l3);
    s.push_back(l4);

    vector<Node *> actual = bfs->run(l1, l4);

    for (int i = 0; i < actual.size(); ++i) {
        EXPECT_TRUE(*(actual.at(i)) == *(s.at(i)));
    }
}
