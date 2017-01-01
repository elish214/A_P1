//
// Created by raz on 30/12/16.
//

#ifndef A_P1_DRIVERCONTAINER_H
#define A_P1_DRIVERCONTAINER_H


#include <ostream>
#include "../enums/MaritalStatus.h"
#include "../Satisfaction.h"
#include "LocationContainer.h"

using namespace boost::archive;

class DriverContainer {
private:
    int id;
    int age;
    MaritalStatus status;
    int taxiID;
    int experience;
public:
    DriverContainer();

    DriverContainer(int id, int age, MaritalStatus status, int taxiID,
                    int experience);

    int getId() const;

    int getAge() const;

    MaritalStatus getStatus() const;

    int getTaxiID() const;

    int getExperience() const;

    friend std::ostream &
    operator<<(std::ostream &os, const DriverContainer &container);

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
        ar & age;
        ar & status;
        ar & taxiID;
        ar & experience;
    }
};


#endif //A_P1_DRIVERCONTAINER_H
