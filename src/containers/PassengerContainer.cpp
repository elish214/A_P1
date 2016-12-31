//
// Created by raz on 30/12/16.
//

#include "PassengerContainer.h"

PassengerContainer::PassengerContainer(LocationContainer *source,
                                       LocationContainer *destination) : source(
        source), destination(destination) {}

PassengerContainer::PassengerContainer() {}

LocationContainer *PassengerContainer::getSource() const {
    return source;
}

LocationContainer *PassengerContainer::getDestination() const {
    return destination;
}
