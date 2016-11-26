//
// Created by elish on 15/11/16.
//

#include <map>
#include <queue>
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
stack<Node *> BFS::run(Node *start, Node *end) {
    map<Node *, Node *> parents;
    map<Node *, int> dist;
    Node **neighbors;
    queue<Node *> q;
    Node *current;
    stack<Node *> route;
    Node *p;

    parents.insert(make_pair(start, (Node *) NULL));
    dist.insert(make_pair(start, 0));
    q.push(start);

    while (!q.empty()) {
        current = q.front();
        q.pop();
        map<Node *, int>::iterator itCurrent = dist.find(current);
        neighbors = itCurrent->first->neighbors();

        for (int i = 0; i < 4; i++) {
            if (neighbors[i] == NULL) {// no neighbor.
                continue;
            }
            map<Node *, int>::iterator itN = dist.find(current->neighbors()[i]);

            if (itN == dist.end() ||
                itN->second > itCurrent->second + 1) {
                dist.insert(make_pair(current->neighbors()[i],
                                      itCurrent->second + 1));
                parents.insert(make_pair(current->neighbors()[i], current));
                q.push(current->neighbors()[i]);
            }
        }

        delete[] neighbors;
    }

    route.push(end);
    p = parents.find(end)->second;

    while (p != NULL) {
        route.push(p);
        p = parents.find(p)->second;
    }

    delete p;

    return route;
}