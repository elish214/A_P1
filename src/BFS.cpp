//
// Created by elish on 15/11/16.
//

#include <map>
#include <queue>
#include <list>
#include <stack>
#include "BFS.h"

using namespace std;

/**
 * runs the algorithem.
 *
 * @param start a starting point.
 * @param end an ending point.
 * @return a stack of nodes which is the optimal route.
 */
stack<Node*> BFS::run(Node &start, Node &end) {
    map<Node*,Node*> parents;
    map<Node*,int> dist;
    queue<Node*> q;
    Node *current;
    stack<Node*> route;
    Node *p;

    parents.insert({&start, NULL});
    dist.insert({&start, 0});
    q.push(&start);

    while(!q.empty()){
        current = q.front();
        q.pop();
        std::map<Node *, int>::iterator itCurrent = dist.find(current);

        for (int i = 0; i < 4; i++) {
            if(current->neighbors()[i] == NULL){// no neighbor.
                continue;
            }
            std::map<Node *, int>::iterator itN = dist.find(current->neighbors()[i]);

            if (itN == dist.end() ||
                itN->second > itCurrent->second + 1) {
                dist.insert({current->neighbors()[i], itCurrent->second + 1});
                parents.insert({current->neighbors()[i],current});
                q.push(current->neighbors()[i]);
            }
        }
    }

    route.push(&end);
    p = parents.find(&end)->second;

    while (p != NULL) {
        route.push(p);
        p = parents.find(p)->second;
    }

    return route;
}