//
// Created by raz on 30/12/16.
//

#ifndef A_P1_COMMAND_H
#define A_P1_COMMAND_H


#include <boost/serialization/access.hpp>
#include "../enums/Operation.h"

using namespace boost::archive;

class Command {
private:
    Operation op;
public:
    Command(Operation op);

    Command();

    Operation getOp() const;

    void setOp(Operation op);

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
