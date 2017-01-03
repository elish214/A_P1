//
// Created by raz on 29/11/16.
//

#include "Taxi.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Taxi)

/**
 * constructor.
 *
 * @param id an integer.
 * @param manufacturer an enum.
 * @param color an enum.
 */
Taxi::Taxi(int id, CarManufacturer manufacturer, Color color) : id(id),
                                                                KmPassed(0),
                                                                manufacturer(
                                                                        manufacturer),
                                                                color(color) {}

/**
 * constructor.
 */
Taxi::Taxi() {}

/**
 * destructor.
 */
Taxi::~Taxi() {}

/**
 * returns taxi's id.
 *
 * @return taxi's id.
 */
int Taxi::getId() const {
    return id;
}

/**
 * adding meters to taxi's total meters.
 *
 * @param meters meters to add.
 */
void Taxi::addMeters(double meters) {
    KmPassed += meters / 1000;
}

/**
 * returns km passed.
 *
 * @return km passed.
 */
double Taxi::getKmPassed() const {
    return KmPassed;
}

/**
 * method overloading for operator '>>'.
 *
 * @param is input stream.
 * @param taxi a taxi.
 * @return input stream.
 */
istream &operator>>(istream &is, Taxi &taxi) {
    string s;
    int id, type;
    CarManufacturer manufacturer;
    Color color;

    getline(is, s, ',');
    id = atoi(s.c_str());

    getline(is, s, ',');
    type = atoi(s.c_str());

    getline(is, s, ',');
    manufacturer = static_cast<CarManufacturer>(s[0]);

    getline(is, s, '\n');
    color = static_cast<Color>(s[0]);

    switch (type) {
        case 1:
            taxi = StandardTaxi(id, manufacturer, color);
            break;
        case 2:
            taxi = LuxuryTaxi(id, manufacturer, color);
            break;
        default:;
    }

    return is;
}

/**
 * returns enum as a string.
 *
 * @param c a color.
 * @return enum as a string.
 */
string colorToString(Color c) {
    switch (c) {
        case Color::RED:
            return "RED";
        case Color::BLUE:
            return "BLUE";
        case Color::GREEN:
            return "GREEN";
        case Color::PINK:
            return "PINK";
        case Color::WHITE:
            return "WHITE";
        default:
            return "NONE";
    }
}

/**
 * returns enum as a string.
 *
 * @param cm a car manufacturer.
 * @return enum as a string.
 */
string cmToString(CarManufacturer cm) {
    switch (cm) {
        case CarManufacturer::HONDA:
            return "HONDA";
        case CarManufacturer::SUBARU:
            return "SUBARU";
        case CarManufacturer::TESLA:
            return "TESLA";
        case CarManufacturer::FIAT:
            return "FIAT";
        default:
            return "NONE";
    }
}

/**
 * method overloading for operator '<<'.
 *
 * @param os output stream.
 * @param taxi a taxi.
 * @return output stream.
 */
ostream &operator<<(ostream &os, const Taxi &taxi) {
    os << "id: " << taxi.id
       << " manufacturer: " << cmToString(taxi.manufacturer)
       << " color: " << colorToString(taxi.color)
       << " type: " << taxi.getType();
    return os;
}
