//
// Created by raz on 30/12/16.
//

#include "DriverContainer.h"

/**
 * constructor.
 *
 * @param id an integer.
 * @param age an integer.
 * @param status an enum.
 * @param taxiID an integer.
 * @param experience an integer.
 */
DriverContainer::DriverContainer(int id, int age, MaritalStatus status,
                                 int taxiID, int experience)
        : id(id), age(age), status(status), taxiID(taxiID),
          experience(experience) {}

/**
 * constructor.
 */
DriverContainer::DriverContainer() {
}

/**
 * returns driver's id.
 *
 * @return driver's id.
 */
int DriverContainer::getId() const {
    return id;
}

/**
 * returns driver's age.
 *
 * @return driver's age.
 */
int DriverContainer::getAge() const {
    return age;
}

/**
 * returns driver's status.
 *
 * @return driver's status.
 */
MaritalStatus DriverContainer::getStatus() const {
    return status;
}

/**
 * returns driver's taxi's id.
 *
 * @return driver's taxi's id.
 */
int DriverContainer::getTaxiID() const {
    return taxiID;
}

/**
 * returns driver's experience.
 *
 * @return driver's experience.
 */
int DriverContainer::getExperience() const {
    return experience;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param container a container.
 * @return output stream.
 */
std::ostream &operator<<(std::ostream &os, const DriverContainer &container) {
    os << "id: " << container.id << " age: " << container.age << " taxiID: "
       << container.taxiID << " experience: " << container.experience;
    return os;
}