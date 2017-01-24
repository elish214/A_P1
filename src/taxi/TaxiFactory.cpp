//
// Created by raz on 06/12/16.
//

#include "TaxiFactory.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"

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
    //char c;
    int id, type;
    CarManufacturer m;
    Color color;

    try {
        getline(is, s, ',');
        id = stoi(s.c_str());
        if (id < 0) {
            factory.taxi = new StandardTaxi(ERROR, CarManufacturer::FIAT, Color::BLUE);
            return  is;
        }
    } catch (exception e) {

        factory.taxi = new StandardTaxi(ERROR, CarManufacturer::FIAT, Color::BLUE);
        return  is;
    }

    try {
        getline(is, s, ',');
        type = stoi(s.c_str());
        if (type != 1 && type != 2) {

            factory.taxi = new StandardTaxi(ERROR, CarManufacturer::FIAT, Color::BLUE);
            return  is;
        }
    } catch (exception e) {

        factory.taxi = new StandardTaxi(ERROR, CarManufacturer::FIAT, Color::BLUE);
        return  is;
    }

    getline(is, s, ',');
    m = static_cast<CarManufacturer>(s[0]);
    if (m != CarManufacturer::FIAT &&
        m != CarManufacturer::HONDA &&
        m != CarManufacturer::SUBARU &&
        m != CarManufacturer::TESLA) {
        factory.taxi = new StandardTaxi(ERROR, CarManufacturer::FIAT, Color::BLUE);
        return  is;
    }

    getline(is, s, '\n');
    //cout << s << endl;
    //cout << s[0] << " " << s[1] << endl;
    color = static_cast<Color>(s[0]);
    if (color != Color::BLUE &&
        color != Color::GREEN &&
        color != Color::PINK &&
        color != Color::RED &&
        color != Color::WHITE) {
        factory.taxi = new StandardTaxi(ERROR, CarManufacturer::FIAT, Color::BLUE);
        return  is;
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
