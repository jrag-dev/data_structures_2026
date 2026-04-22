//////////////////////////////////////////////////////////////
// englobj.cpp
// objects using English measurements
//////////////////////////////////////////////////////////////
#include "englobj.h"
#include <iostream>



Distance::Distance() : feet(0), inches(0) {}
Distance::Distance(int ft, float in) : feet(ft), inches(in) {}

void Distance::getDistance() {
    std::cout << "\nEnter feet: "; std::cin >> feet;
    std::cout << "Enter inches: "; std::cin >> inches;
}

void Distance::showDistance() const {
    std::cout << feet << "\'-" << inches << '\"';
}