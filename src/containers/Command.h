//
// Created by raz on 30/12/16.
//

#ifndef A_P1_COMMAND_H
#define A_P1_COMMAND_H


#include <boost/serialization/access.hpp>
#include <ostream>
#include "../enums/Operation.h"

using namespace boost::archive;

/**
 * command represent class.
 * command is the way to tell the client what data it's about to receive.
 */
class Command {
private:
    Operation op;
public:
    Command(Operation op);

    Command();

    Operation getOp() const;

    void setOp(Operation op);

    friend std::ostream &operator<<(std::ostream &os, const Command &command);

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
        ar & op;
    }
};


#endif //A_P1_COMMAND_H
