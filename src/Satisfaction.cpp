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
    rating = (getRating()*amount++ + newRating)/amount;
}


