//
// Created by raz on 30/12/16.
//

#include "PassengerContainer.h"

/**
 * constructor.
 *
 * @param source a loction.
 * @param destination another location.
 */
PassengerContainer::PassengerContainer(LocationContainer *source,
                                       LocationContainer *destination) :
        source(source), destination(destination) {}

/**
 * constructor.
 */
PassengerContainer::PassengerContainer() {}

/**
 * returns passenger's source.
 *
 * @return passenger's source.
 */
LocationContainer *PassengerContainer::getSource() const {
    return source;
}

/**
 * returns passenger's destination.
 *
 * @return passenger's destination.
 */
LocationContainer *PassengerContainer::getDestination() const {
    return destination;
}
