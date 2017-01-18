//
// Created by raz on 30/12/16.
//

#include "Command.h"

/**
 * constructor.
 *
 * @param op an operation.
 */
Command::Command(Operation op) : op(op) {}

/**
 * constructor.
 */
Command::Command() {}

/**
 * returns the operation.
 *
 * @return the operation.
 */
Operation Command::getOp() const {
    return op;
}

/**
 * setting an operation.
 *
 * @param op an operation.
 */
void Command::setOp(Operation op) {
    Command::op = op;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param command a command.
 * @return output stream.
 */
std::ostream &operator<<(std::ostream &os, const Command &command) {
    std::string s;
    os << "op: ";

    switch (command.getOp()) {
        case Operation::NEW_DRIVER:
            os << "NEW_DRIVER";
            break;
        case Operation::NEW_RIDE:
            os << "NEW_RIDE";
            break;
        case Operation::NEW_VEHICLE:
            os << "NEW_VEHICLE";
            break;
        case Operation::DRIVER_LOCATION:
            os << "DRIVER_LOCATION";
            break;
        case Operation::START:
            os << "START";
            break;
        case Operation::EXIT:
            os << "EXIT";
            break;
        case Operation::ADVANCE:
            os << "ADVANCE";
            break;
        default:
            break;
    }

    return os;
}
