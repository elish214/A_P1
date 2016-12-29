//
// Created by raz on 29/11/16.
//

#ifndef A_P1_STANDARDTAXI_H
#define A_P1_STANDARDTAXI_H


#include <ostream>
#include "Taxi.h"

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
