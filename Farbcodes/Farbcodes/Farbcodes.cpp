#include <string>
#include <sstream>
#include <cmath>

#include "farbcodes.h"

void Resistor::tensDigit(const std::string& R, float& value) {
    if (R == "schwarz")value = 0 * 10;
    if (R == "braun")value = 1 * 10;
    if (R == "rot")value = 2 * 10;
    if (R == "orange")value = 3 * 10;
    if (R == "gelb")value = 4 * 10;
    if (R == "gruen")value = 5 * 10;
    if (R == "blau")value = 6 * 10;
    if (R == "violett")value = 7 * 10;
    if (R == "grau")value = 8 * 10;
    if (R == "weiss")value = 9 * 10;
}

void Resistor::onesDigit(const std::string& R, float& value) {
    if (R == "schwarz")value += 0;
    if (R == "braun")value += 1;
    if (R == "rot")value += 2;
    if (R == "orange")value += 3;
    if (R == "gelb")value += 4;
    if (R == "gruen")value += 5;
    if (R == "blau")value += 6;
    if (R == "violett")value += 7;
    if (R == "grau")value += 8;
    if (R == "weiss")value += 9;
}

void Resistor::power(const std::string& R, float& value) {
    if (R == "schwarz")value *= pow(10, 0);
    if (R == "braun")value *= pow(10, 1);
    if (R == "rot")value *= pow(10, 2);
    if (R == "orange")value *= pow(10, 3);
    if (R == "gelb")value *= pow(10, 4);
    if (R == "gruen")value *= pow(10, 5);
    if (R == "blau")value *= pow(10, 6);
    if (R == "violett")value *= pow(10, 7);
    if (R == "grau")value *= pow(10, 8);
    if (R == "weiss")value *= pow(10, 9);
}

void Resistor::stringToValue(const std::string& R1, const std::string& R2, const std::string& R3) {
    tensDigit(R1, value);
    onesDigit(R2, value);
    power(R3, value);
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

}

Resistor::~Resistor() {

}

Resistor::Resistor(std::string F1, std::string F2, std::string F3) {
    R1 = F1;
    R2 = F2;
    R3 = F3;
    Resistor::stringToValue(R1, R2, R3);
}

Resistor::Resistor(std::string farben) {
    size_t p = farben.find(" ");
    R1 = farben.substr(0, p);
    farben = farben.substr(p + 1);
    p = farben.find(" ");
    R2 = farben.substr(0, p);
    farben = farben.substr(p + 1);
    R3 = farben.substr(0);
    Resistor::stringToValue(R1, R2, R3);
}

Resistor::Resistor(float value) {
    this->value = value;
    Resistor::valueToStrings(value);
}

Resistor::Resistor(float value, char unit) {
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