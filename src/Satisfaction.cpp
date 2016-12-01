//
// Created by raz on 29/11/16.
//

#include "Satisfaction.h"

Satisfaction::Satisfaction(int rating, int amount) : rating(rating), amount(amount) {}

double Satisfaction::getRating() {
    return rating;
}

void Satisfaction::rate(int newRating) {
    rating = (getRating()*amount++ + newRating)/amount;
}


