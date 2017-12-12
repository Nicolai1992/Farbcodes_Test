#include <iostream>
#include "farbcodes.h"

enum values
{
    black = 0,
    brown = 1,
    red = 2,
    orange = 3,
    yellow = 4,
    green = 5,
    blue = 6,
    violet = 7,
    gray = 8,
    white = 9
};

int main() {
    Resistor R1("gelb violett rot");
    Resistor R2(4.7, 'k');
    std::cout << R1.ohm() << std::endl;
    std::cout << R2.farbringe() << std::endl;
    std::cout << R1.farbringe(3) << std::endl;
    std::cout << R2.ohm() << std::endl;
    return 0;
}