#ifndef _FARBCODES_H
#define _FARBCODES_H

#include <iostream>
#include <string>

class Resistor {
    std::string R1;
    std::string R2;
    std::string R3;
    float value;
    void tensDigit(const std::string& R, float& value);
    void onesDigit(const std::string& R, float& value);
    void power(const std::string& R, float& value);
    void stringToValue(const std::string& R1, const std::string& R2, const std::string& R3);
    void valueToStrings(float& value);
public:
    Resistor();
    ~Resistor();
    Resistor(std::string F1, std::string F2, std::string F3);
    Resistor(std::string Farben);
    Resistor(float value);
    Resistor(float value, char unit);
    std::string farbringe();
    std::string farbringe(int i);
    float ohm();
    std::string ohmK();
    std::string ohmM();
};

#endif
