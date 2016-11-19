//
// Created by elish on 15/11/16.
//

#ifndef A_P1_NODE_H
#define A_P1_NODE_H

#include <list>
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node(){}
    virtual ~Node(){}
    virtual list<Node*> neighbors() = 0;
    //virtual int distance(Node n) = 0;

    friend ostream &operator<<(ostream &os, const Node &node);
};


#endif //A_P1_NODE_H
