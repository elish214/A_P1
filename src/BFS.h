//
// Created by elish on 15/11/16.
//

#ifndef A_P1_BFS_H
#define A_P1_BFS_H

#include <stack>
#include "Node.h"

using namespace std;

/**
 * BFS represent Breadth-first search.
 * is an algorithm for traversing or searching tree or graph.
 * Node class keeps as generic as possible.
 */
class BFS {
public:
    stack<Node*> run(Node &start, Node &end);
};


#endif //A_P1_BFS_H
