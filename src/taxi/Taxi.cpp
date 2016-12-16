//
// Created by raz on 29/11/16.
//

#include "Taxi.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"

Taxi::Taxi(int id, CarManufacturer manufacturer, Color color) : id(id),
                                                                KmPassed(0),
                                                                manufacturer(
                                                                        manufacturer),
                                                                color(color) {}

Taxi::Taxi() {}

int Taxi::getId() const {
    return id;
}

void Taxi::addMeters(double meters) {
    KmPassed += meters / 1000;
}

double Taxi::getKmPassed() const {
    return KmPassed;
}

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

ostream &operator<<(ostream &os, const Taxi &taxi) {
    os << "id: " << taxi.id
       << " manufacturer: " << cmToString(taxi.manufacturer)
       << " color: " << colorToString(taxi.color)
       << " type: " << taxi.getType();
    return os;
}


