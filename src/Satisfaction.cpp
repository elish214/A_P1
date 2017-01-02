//
// Created by raz on 29/11/16.
//

#include "Satisfaction.h"

/**
 * constructor.
 *
 * @param rating an integer.
 * @param amount an integer.
 */
Satisfaction::Satisfaction(int rating, int amount) : rating(rating), amount(amount) {}

/**
 * constructor.
 */
Satisfaction::Satisfaction() {
    rating = 0;
    amount = 0;
}

/**
 * returns rating.
 *
 * @return rating.
 */
double Satisfaction::getRating() {
    return rating;
}

/**
 * add new rating to current rating.
 *
 * @param newRating an integer.
 */
void Satisfaction::rate(int newRating) {
    double current = getRating()*amount;
    amount++;
    rating = (current + newRating)/amount;
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param satisfction a satisfaction..
 * @return output stream.
 */
std::ostream &operator<<(std::ostream &os, const Satisfaction &satisfaction) {
    os << "rating: " << satisfaction.rating << " amount: "
       << satisfaction.amount;
    return os;
}
