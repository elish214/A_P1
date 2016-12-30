//
// Created by raz on 29/11/16.
//

#ifndef A_P1_STANDARDTAXI_H
#define A_P1_STANDARDTAXI_H

#include <ostream>
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
#include "Taxi.h"
BOOST_SERIALIZATION_ASSUME_ABSTRACT(Taxi)

using namespace std;
using namespace boost::archive;

/**
 * standard taxi class.
 */
class StandardTaxi : public Taxi {
protected:
    string getType() const;

public:
    StandardTaxi(int id, CarManufacturer manufacturer, Color color);

    int getTaarif();

    int getSpeed();

    friend ostream &operator<<(ostream &os, const StandardTaxi &taxi);

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
        ar & boost::serialization::base_object<Taxi>(*this);
    }
};


#endif //A_P1_STANDARDTAXI_H
