//
// Created by elish on 15/11/16.
//

#ifndef A_P1_BFS_H
#define A_P1_BFS_H

#include <vector>
#include <list>
#include <boost/archive/basic_archive.hpp>
#include "Node.h"

using namespace std;
using namespace boost::archive;

/**
 * BFS represent Breadth-first search.
 * is an algorithm for traversing or searching tree or graph.
 * Node class keeps as generic as possible.
 */
class BFS {
public:
    BFS();

    virtual ~BFS();

    vector<Node *> run(Node *start, Node *end);

//    friend class boost::serialization::access;

    /**
     * serialization implement.
     *
     * @tparam Archive a template.
     * @param ar an archive.
     * @param version an unsigned int.
     */
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) { }

};


#endif //A_P1_BFS_H
