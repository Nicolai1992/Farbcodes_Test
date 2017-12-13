#include <string>
#include <sstream>
#include <cmath>


#include "farbcodes.h"

void Resistor::initReference() {
    reference["schwarz"] = 0;
    reference["braun"] = 1;
    reference["rot"] = 2;
    reference["orange"] = 3;
    reference["gelb"] = 4;
    reference["gruen"] = 5;
    reference["blau"] = 6;
    reference["violett"] = 7;
    reference["grau"] = 8;
    reference["weiss"] = 9;
}

void Resistor::tensDigit(const std::string& R) {
    for (auto& i : reference) {
        if (R == i.first) {
            value = i.second * 10;
        }
    }
}

void Resistor::onesDigit(const std::string& R) {
    for (auto& i : reference) {
        if (R == i.first) {
            value += i.second;
        }
    }
}

void Resistor::power(const std::string& R) {
    for (auto& i : reference) {
        if (R == i.first) {
            value *= pow(10, i.second);
        }
    }
}

void Resistor::stringToValue(const std::string& R1, const std::string& R2, const std::string& R3) {
    tensDigit(R1);
    onesDigit(R2);
    power(R3);
}

void Resistor::valueToStrings(float& value) {
    int value1 = 0, value2 = 0, value3 = 0;
    std::string colors[10] = { "schwarz", "braun", "rot", "orange", "gelb", "gruen", "blau", "violett", "grau", "weiss" };
    while (value > 100) {
        ++value3;
        value /= 10;
    }
    R3 = colors[value3];
    value /= 10;
    value1 = int(value);
    R1 = colors[value1];
    value2 = ((value - value1) * 10) + 1;
    R2 = colors[value2];
}

Resistor::Resistor() :R1(NULL), R2(NULL), R3(NULL), value(0) {
    initReference();
}

Resistor::~Resistor() {

}

Resistor::Resistor(std::string F1, std::string F2, std::string F3) {
    initReference();
    R1 = F1;
    R2 = F2;
    R3 = F3;
    Resistor::stringToValue(R1, R2, R3);
}

Resistor::Resistor(std::string farben) {
    initReference();
    auto p = farben.find(" ");
    R1 = farben.substr(0, p);
    farben = farben.substr(p + 1);
    p = farben.find(" ");
    R2 = farben.substr(0, p);
    farben = farben.substr(p + 1);
    R3 = farben.substr(0);
    Resistor::stringToValue(R1, R2, R3);
}

Resistor::Resistor(float value) {
    initReference();
    this->value = value;
    Resistor::valueToStrings(value);
}

Resistor::Resistor(float value, char unit) {
    initReference();
    if (unit == 'k')value *= 1000;
    else if (unit == 'M')value *= 1000000;
    this->value = value;
    Resistor::valueToStrings(value);
}

std::string Resistor::farbringe() {
    return R1 + " " + R2 + " " + R3;
}

std::string Resistor::farbringe(int i) {
    if (i == 1)return R1;
    else if (i == 2)return R2;
    else if (i == 3)return R3;
    else return "Farbring ungültig!";
}

float Resistor::ohm() {
    return value;
}

std::string Resistor::ohmK() {
    std::stringstream ss;
    ss << value / 1000 << " Kiloohm";
    std::string str = ss.str();
    return str;
}

std::string Resistor::ohmM() {
    std::stringstream ss;
    ss << value / 1000000 << " Megaohm";
    std::string str = ss.str();
    return str;
}