//
// Created by raz on 29/11/16.
//

#include "Taxi.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"

Taxi::Taxi(int id, CarManufacturer manufacturer, Color color) : id(id), KmPassed(0),
                                                                manufacturer(manufacturer),
                                                                color(color) {}

Taxi::Taxi() {}

void Taxi::addMeters(double meters) {

}

double Taxi::getKmPassed() const {
    return KmPassed;
}

istream &operator>>(istream &is, Taxi &taxi) {
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
            taxi = StandardTaxi(id, m, color);
            break;
        case 2:
            taxi = LuxuryTaxi(id, m, color);
            break;
        default:;
    }

    return is;
}

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
        default:;
    }
}

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
        default:;
    }
}

ostream &operator<<(ostream &os, const Taxi &taxi) {
    os << "id: " << taxi.id << " manufacturer: "
       << cmToString(taxi.manufacturer)
       << " color: " << colorToString(taxi.color);
    return os;
}


