//
// Created by raz on 29/11/16.
//

#ifndef A_P1_TAXI_H
#define A_P1_TAXI_H

#include <ostream>
#include <boost/archive/basic_archive.hpp>
#include <boost/archive/archive_exception.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>
#include "../enums/CarManufacturer.h"
#include "../enums/Color.h"

using namespace std;
using namespace boost::archive;

/**
 * taxi representation.
 * this is an abstract class.
 */
class Taxi {
private:
    int id;
    double KmPassed;
    CarManufacturer manufacturer;
    Color color;
protected:
    virtual string getType() const = 0;
public:
    Taxi(int id, CarManufacturer manufacturer, Color color);

    Taxi();

    virtual ~Taxi();

    int getId() const;

    void addMeters(double meters);

    double getKmPassed() const;

    virtual int getTaarif() = 0;

    virtual int getSpeed() = 0;

    friend istream &operator>>(istream &is, Taxi &taxi);

    friend ostream &operator<<(ostream &os, const Taxi &taxi);

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
        ar & id;
        ar & KmPassed;
        ar & manufacturer;
        ar & color;
    }

};

//BOOST_SERIALIZATION_ASSUME_ABSTRACT(Taxi)


#endif //A_P1_TAXI_H
