//
// Created by raz on 30/12/16.
//

#include <boost/serialization/assume_abstract.hpp>
#include "Node.h"

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Node)

Node::Node() : obstacle(false) {}

bool Node::operator!=(const Node &rhs) const {
    return *this != rhs;
}

ostream &operator<<(ostream &os, const Node &node) {
    return node.toString(os);
}

bool Node::isObstacle() const {
    return obstacle;
}

void Node::setObstacle(bool obstacle) {
    Node::obstacle = obstacle;
}
