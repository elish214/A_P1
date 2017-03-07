//
// Created by raz on 06/12/16.
//

#include "TaxiFactory.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"
#include "../validation/Checker.h"
#include "../validation/Validator.h"
#include "../validation/PositiveNumericChecker.h"
#include "../validation/RangeNumericChecker.h"
#include "../validation/CarManufacturerChecker.h"
#include "../validation/ColorChecker.h"

#define ERROR -1

/**
 * returns a taxi.
 *
 * @return a taxi.
 */
Taxi *TaxiFactory::getTaxi() const {
    return taxi;
}

/**
 * method overloading for operator '>>'.
 *
 * @param is input stream.
 * @param factory a factory.
 * @return input stream.
 */
istream &operator>>(istream &is, TaxiFactory &factory) {
    string s;
    bool valid;
    vector<Checker *> checkers;
    Validator v;

    checkers.emplace_back(new PositiveNumericChecker());
    checkers.emplace_back(new RangeNumericChecker(1, 2));
    checkers.emplace_back(new CarManufacturerChecker());
    checkers.emplace_back(new ColorChecker());

    is >> s;

    valid = v.validate(s, checkers, ',');

    for (unsigned int k = 0; k < checkers.size(); k++) {
        delete checkers[k];
    }

    checkers.clear();

    if (!valid) {
        factory.taxi = new StandardTaxi(ERROR, CarManufacturer::FIAT, Color::BLUE);
        return is;
    }

    istringstream ss(s);

    int id, type;
    CarManufacturer m;
    Color color;

    getline(ss, s, ',');
    id = stoi(s.c_str());
    //cout << id << endl;

    getline(ss, s, ',');
    type = stoi(s.c_str());

    getline(ss, s, ',');
    m = static_cast<CarManufacturer>(s[0]);

    getline(ss, s, '\n');
    color = static_cast<Color>(s[0]);


    switch (type) {
        case 1:
            factory.taxi = new StandardTaxi(id, m, color);
            break;
        case 2:
            factory.taxi = new LuxuryTaxi(id, m, color);
            break;
        default:;
    }

    return is;
}
