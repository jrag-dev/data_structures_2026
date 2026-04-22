// englobj_main.cpp

#include "englobj.h"
#include <iostream>

int main() {
    Distance d1(11, 6.25);
    Distance d2;

    d2.getDistance();

    std::cout << "\033[31mThis is a red text";
    std::cout << "\n\033[35mDistance 1: "; d1.showDistance();
    std::cout << "\nDistance 2: "; d2.showDistance();
    std::cout << std::endl;
    
    return 0;
}