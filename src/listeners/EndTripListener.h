//
// Created by raz on 29/11/16.
//

#ifndef A_P1_ENDTRIPLISTENER_H
#define A_P1_ENDTRIPLISTENER_H


#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>

//using namespace std;
using namespace boost::archive;

/**
 * a listener for end of trips.
 */
class EndTripListener {
public:
    virtual void endEvent() = 0;

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
        // nothing to serialize.
    }
};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(EndTripListener)

#endif //A_P1_ENDTRIPLISTENER_H
