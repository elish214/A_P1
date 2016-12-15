//
// Created by raz on 06/12/16.
//

#include "TaxiFactory.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"

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
    //char c;
    int id, type;
    CarManufacturer m;
    Color color;

    getline(is, s, ',');
    id = atoi(s.c_str());

    getline(is, s, ',');
    type = atoi(s.c_str());

    getline(is, s, ',');
    m = static_cast<CarManufacturer>(s[0]);

    getline(is, s, '\n');
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