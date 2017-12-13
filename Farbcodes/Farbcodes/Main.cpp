#include <iostream>
#include "farbcodes.h"

int main() {
    Resistor R1("gelb violett rot");
    Resistor R2(4.7, 'k');
    std::cout << "R1: " << R1.ohm() << std::endl;
    std::cout << "R2 Farbringe: " << R2.farbringe() << std::endl;
    std::cout << "R1 Farbringe(3): " << R1.farbringe(3) << std::endl;
    std::cout << "R2: " << R2.ohm() << std::endl;
    std::cin.get();
    return 0;
}