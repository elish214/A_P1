//
// Created by elish on 15/11/16.
//

#ifndef A_P1_BFS_H
#define A_P1_BFS_H

#include <stack>
#include "Node.h"

using namespace std;

class BFS {
public:
    stack<Node*> run(Node &start, Node &end);
};


#endif //A_P1_BFS_H
