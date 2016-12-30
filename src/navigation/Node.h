//
// Created by elish on 15/11/16.
//

#ifndef A_P1_NODE_H
#define A_P1_NODE_H

#include <vector>
#include <iostream>
#include <string>
#include <boost/serialization/base_object.hpp>

using namespace std;
//using namespace boost::archive;

/**
 * Node represent an abstract class.
 * node is a coordinate in the space on which the BFS algorithem run.
 * keeps it generic as possible.
 */
class Node {
private:
    bool obstacle; //obstacle flag

protected:
    /**
     * returns an output stream.
     *
     * @param os an output stream.
     * @return output stream.
     */
    virtual ostream &toString(ostream &os) const = 0;

public:
    /**
     * constructor.
     */
    Node() : obstacle(false) {}

    /**
    * distructor
    */
    virtual ~Node() {}

    /**
     * returns node's neighbors.
     *
     * @return node's neighbors.
     */
    virtual vector<Node *> neighbors() = 0;

    /**
    * method overloading for operator '=='.
    *
    * @param rhs another node.
    * @return whether it equals to current node or not.
    */
    virtual bool operator==(const Node &rhs) const = 0;

    /**
    * method overloading for operator '!='.
    *
    * @param rhs another node.
    * @return whether it isn't equals to current node or not.
    */
    bool operator!=(const Node &rhs) const {
        return *this != rhs;
    }

    /**
     * method overloading for operator '<<'.
    *
    * @param os output stream.
    * @param point a node.
    * @return output stream.
    */
    friend ostream &operator<<(ostream &os, const Node &node) {
        return node.toString(os);
    }

    bool isObstacle() const {
        return obstacle;
    }

    void setObstacle(bool obstacle) {
        Node::obstacle = obstacle;
    }

    //friend class boost::serialization::access;

    /**
     * serialization implement.
     *
     * @tparam Archive a template.
     * @param ar an archive.
     * @param version an unsigned int.
     */
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & obstacle;
    }

};

//BOOST_SERIALIZATION_ASSUME_ABSTRACT(Node);

#endif //A_P1_NODE_H
