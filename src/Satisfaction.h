//
// Created by raz on 29/11/16.
//

#ifndef A_P1_SATISFACTION_H
#define A_P1_SATISFACTION_H


class Satisfaction {
private:
    double rating;
    int amount;
public:
    Satisfaction(int rating, int amount);

    double getRating();

    void rate(int newRating);
};


#endif //A_P1_SATISFACTION_H
