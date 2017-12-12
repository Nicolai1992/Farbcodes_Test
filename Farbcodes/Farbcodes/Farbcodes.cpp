#include <string>
#include <sstream>
#include <cmath>

#include "farbcodes.h"

void Resistor::stringtovalue(std::string R1, std::string R2, std::string R3) {
    //Zehnerstelle
    if (R1 == "schwarz")value = 0 * 10;
    if (R1 == "braun")value = 1 * 10;
    if (R1 == "rot")value = 2 * 10;
    if (R1 == "orange")value = 3 * 10;
    if (R1 == "gelb")value = 4 * 10;
    if (R1 == "gruen")value = 5 * 10;
    if (R1 == "blau")value = 6 * 10;
    if (R1 == "violett")value = 7 * 10;
    if (R1 == "grau")value = 8 * 10;
    if (R1 == "weiss")value = 9 * 10;
    //else std::cerr << "Farbe nicht vorhanden!" << std::endl;

    //Einerstelle
    if (R2 == "schwarz")value += 0;
    if (R2 == "braun")value += 1;
    if (R2 == "rot")value += 2;
    if (R2 == "orange")value += 3;
    if (R2 == "gelb")value += 4;
    if (R2 == "gruen")value += 5;
    if (R2 == "blau")value += 6;
    if (R2 == "violett")value += 7;
    if (R2 == "grau")value += 8;
    if (R2 == "weiss")value += 9;

    //Potenz
    if (R3 == "schwarz")value *= pow(10, 0);
    if (R3 == "braun")value *= pow(10, 1);
    if (R3 == "rot")value *= pow(10, 2);
    if (R3 == "orange")value *= pow(10, 3);
    if (R3 == "gelb")value *= pow(10, 4);
    if (R3 == "gruen")value *= pow(10, 5);
    if (R3 == "blau")value *= pow(10, 6);
    if (R3 == "violett")value *= pow(10, 7);
    if (R3 == "grau")value *= pow(10, 8);
    if (R3 == "weiss")value *= pow(10, 9);
}

void Resistor::valuetostrings(float value) {
    int wert1 = 0, wert2 = 0, wert3 = 0;
    std::string colors[10] = { "schwarz", "braun", "rot", "orange", "gelb", "gruen", "blau", "violett", "grau", "weiss" };
    while (value > 100) {
        ++wert3;
        value /= 10;
    }
    R3 = colors[wert3];
    value /= 10;
    wert1 = int(value);
    R1 = colors[wert1];
    wert2 = ((value - wert1) * 10) + 1;
    R2 = colors[wert2];
}

Resistor::Resistor(std::string F1, std::string F2, std::string F3) {
    R1 = F1;
    R2 = F2;
    R3 = F3;
    Resistor::stringtovalue(R1, R2, R3);
}

Resistor::Resistor(std::string farben) {
    size_t p = farben.find(" ");
    R1 = farben.substr(0, p);
    farben = farben.substr(p + 1);
    p = farben.find(" ");
    R2 = farben.substr(0, p);
    farben = farben.substr(p + 1);
    R3 = farben.substr(0);
    Resistor::stringtovalue(R1, R2, R3);
}

Resistor::Resistor(float value) {
    this->value = value;
    Resistor::valuetostrings(value);
}

Resistor::Resistor(float value, char unit) {
    if (unit == 'k')value *= 1000;
    else if (unit == 'M')value *= 1000000;
    this->value = value;
    Resistor::valuetostrings(value);
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