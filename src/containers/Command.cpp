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
