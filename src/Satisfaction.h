//
// Created by raz on 29/11/16.
//

#ifndef A_P1_SATISFACTION_H
#define A_P1_SATISFACTION_H


class Satisfaction {
private:
    int rating;
    int amount;
public:
    Satisfaction(int rating, int amount);

    int getRating() const;

    void rate(int newRating);
};


#endif //A_P1_SATISFACTION_H
