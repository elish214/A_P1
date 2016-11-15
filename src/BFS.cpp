//
// Created by elish on 15/11/16.
//

#include <map>
#include <queue>
#include <list>
#include <stack>
#include "BFS.h"
#include "Node.h"

using namespace std;

stack<Node> BFS::run(Node start, Node end) {
    map<Node,Node> parents;
    map<Node,int> dist;
    queue<Node> q;
    Node current;
    stack<Node> route;
    Node p;

    parents.insert({start, nullptr});
    dist.insert({start, 0});
    q.push(start);


    while(!q.empty()){
        current = q.front();
        q.pop();
        for(Node n : current.neighbors()){
            if(dist.find(n) == nullptr || dist.find(n)->second > dist.find(current)->second + 1){
                dist.insert({n, (dist.find((current))->second) + 1});
                parents.insert({n,current});
                q.push(n);
            }
        }
    }

    route.push(end);
    p = parents.find(end)->second;
    while(&p != nullptr){
        route.push(p);
        p = parents.find(p)->second;
    }

    return route;
}