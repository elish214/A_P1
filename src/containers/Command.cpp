//
// Created by raz on 30/12/16.
//

#include "Command.h"

Command::Command(Operation op) : op(op) {}

Command::Command() {}

Operation Command::getOp() const {
    return op;
}

void Command::setOp(Operation op) {
    Command::op = op;
}
