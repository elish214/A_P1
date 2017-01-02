//
// Created by raz on 30/12/16.
//

#ifndef A_P1_LOCATIONCONTAINER_H
#define A_P1_LOCATIONCONTAINER_H


#include <ostream>
#include "../navigation/Point.h"

using namespace boost::archive;

/**
 * a location's container in order to send it to client.
 */
class LocationContainer {
private:
    Point *p;
public:
    LocationContainer();

    LocationContainer(Point *p);

    virtual ~LocationContainer();

    Point *getPoint() const;

    friend ostream &operator<<(ostream &os, const LocationContainer &container);

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
        ar & p;
    }
};


#endif //A_P1_LOCATIONCONTAINER_H
