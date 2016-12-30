//
// Created by elish on 16/11/16.
//

#ifndef A_P1_LOCATION_H
#define A_P1_LOCATION_H


#include <iostream>
#include <string>
#include "Point.h"
#include "Node.h"
BOOST_SERIALIZATION_ASSUME_ABSTRACT(Node)

#include <boost/serialization/export.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost::archive;

class Grid;

/**
 * Location represent a node on the grid.
 * in our case, location is a coordinate in the matrix.
 */
class Location: public Node {
private:
    Point *p;
    Grid *grid;

protected:
    ostream &toString(ostream &os) const;

public:

    Location();

    Location(Point *point);

    Location(int x, int y);

    virtual ~Location();

    Point *getPoint() const;

    void setPoint(Point *p);

    Grid *getGrid() const;

    void setGrid(Grid *grid);

    vector<Node *> neighbors();

    friend ostream &operator<<(ostream &os, Location &location);

    bool operator==(const Location &rhs) const;

    bool operator!=(const Location &rhs) const;

    bool operator==(const Node &rhs) const;

    friend class boost::serialization::access;

    /**
     * serialization implement.
     *
     * @tparam Archive a template.
     * @param ar an archive.
     * @param version an unsigned int.
     */
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & boost::serialization::base_object<Node>(*this);
        ar & p;
        ar & grid;
    }

};

#endif //A_P1_LOCATION_H
