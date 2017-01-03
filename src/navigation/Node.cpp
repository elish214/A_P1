//
// Created by raz on 30/12/16.
//

#include <boost/serialization/assume_abstract.hpp>
#include "Node.h"

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Node)

/**
 * constructor.
 */
Node::Node() : obstacle(false) {}

/**
 * method overloading for operator '=='.
 *
 * @param rhs another node.
 * @return whether it equals to current node or not.
 */
bool Node::operator!=(const Node &rhs) const {
    return *this != rhs;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param node a node.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const Node &node) {
    return node.toString(os);
}

/**
 * returns whether is obstacle or not.
 *
 * @return whether is obstacle or not.
 */
bool Node::isObstacle() const {
    return obstacle;
}

/**
 * setting node's obstacle status.
 *
 * @param obstacle a status.
 */
void Node::setObstacle(bool obstacle) {
    Node::obstacle = obstacle;
}
