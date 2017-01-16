//
// Created by elish on 15/11/16.
//

#include <map>
#include <queue>
#include "BFS.h"

using namespace std;

/**
 * constructor.
 */
BFS::BFS() {}

/**
 * destructor.
 */
BFS::~BFS() {}

/**
 * runs the algorithm.
 *
 * @param start a starting point.
 * @param end an ending point.
 * @return a stack of nodes which is the optimal route.
 */
vector<Node *> BFS::run(Node *start, Node *end) {
    map<Node *, Node *> parents;
    map<Node *, int> dist;
    vector<Node *> nei;
    queue<Node *> q;
    Node *current;
    vector<Node *> route;
    Node *p;

    parents.insert(make_pair(start, (Node *) NULL));
    dist.insert(make_pair(start, 0));
    q.push(start);

    while (!q.empty()) {
        current = q.front();
        q.pop();
        map<Node *, int>::iterator itCurrent = dist.find(current);
        nei = itCurrent->first->neighbors();

        //cout << *itCurrent->first << endl;

        for (unsigned long i = 0; i < nei.size(); ++i) {
            std::map<Node *, int>::iterator itN = dist.find(nei.at(i));

            if (itN == dist.end() ||
                itN->second > itCurrent->second + 1) {
                dist.insert(make_pair(nei.at(i), itCurrent->second + 1));
                parents.insert(make_pair(nei.at(i), current));
                q.push(nei.at(i));

                if (*(nei.at(i)) == *end) {
                    p = nei.at(i);
                }
            }
        }
    }

    route.emplace_back(end);
    p = parents.find(p)->second;

    while (p != NULL) {
        route.insert(route.begin(), p);
        p = parents.find(p)->second;
    }

    delete p;

    return route;
}
