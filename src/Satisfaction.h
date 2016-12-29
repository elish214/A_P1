//
// Created by raz on 29/11/16.
//

#ifndef A_P1_SATISFACTION_H
#define A_P1_SATISFACTION_H

#include <boost/serialization/access.hpp>

using namespace std;
using namespace boost::archive;

/**
 * satisfaction class.
 */
class Satisfaction {
private:
    double rating;
    int amount;
public:
    Satisfaction(int rating, int amount);

    double getRating();

    void rate(int newRating);

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
        ar & rating;
        ar & amount;
    }
};


#endif //A_P1_SATISFACTION_H
