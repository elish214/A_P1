//
// Created by raz on 30/12/16.
//

#include "DriverContainer.h"


DriverContainer::DriverContainer(int id, int age, MaritalStatus status,
                                 int taxiID, int experience)
        : id(id), age(age), status(status), taxiID(taxiID),
          experience(experience) {}

DriverContainer::DriverContainer() {
}

int DriverContainer::getId() const {
    return id;
}

int DriverContainer::getAge() const {
    return age;
}

MaritalStatus DriverContainer::getStatus() const {
    return status;
}

int DriverContainer::getTaxiID() const {
    return taxiID;
}

int DriverContainer::getExperience() const {
    return experience;
}

std::ostream &operator<<(std::ostream &os, const DriverContainer &container) {
    os << "id: " << container.id << " age: " << container.age << " taxiID: "
       << container.taxiID << " experience: " << container.experience;
    return os;
}
