//
// Created by raz on 06/12/16.
//

#include "TaxiFactory.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"

Taxi *TaxiFactory::getTaxi() const {
    return taxi;
}

istream &operator>>(istream &is, TaxiFactory &factory) {
    string s;
    char c;
    int id, type;
    CarManufacturer m;
    Color color;

    getline(is, s, ',');
    id = atoi(s.c_str());

    getline(is, s, ',');
    type = atoi(s.c_str());

    getline(is, s, ',');
    c = s[0];

    switch (c) {
        case 'H':
            m = CarManufacturer::HONDA;
            break;
        case 'S':
            m = CarManufacturer::SUBARU;
            break;
        case 'T':
            m = CarManufacturer::TESLA;
            break;
        case 'F':
            m = CarManufacturer::FIAT;
            break;
        default:;
    }

    getline(is, s, '\n');
    c = s[0];

    switch (c) {
        case 'R':
            color = Color::RED;
            break;
        case 'B':
            color = Color::BLUE;
            break;
        case 'G':
            color = Color::GREEN;
            break;
        case 'P':
            color = Color::PINK;
            break;
        case 'W':
            color = Color::WHITE;
            break;
        default:;
    }

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
