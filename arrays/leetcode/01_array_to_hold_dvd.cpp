/*
 *  01_array_to_hold_dvd.cpp
 *  In C++, we use the following code to create an Array to hold up to 15 DVDs. Note that
 *  we've also include a simple definition of a DVD for clarity.
 *  Jose Alvarado
 *  02-04-2026
*/

#include <iostream>
#include "dvd.h"



int main() 
{
    const unsigned int CAPACITY = 15;
    DVD dvd_collection[CAPACITY];

    DVD dvd1("dvd1", 2006, "spencer");
    DVD dvd2("dvd2", 2012, "monica");
    DVD dvd3("dvd3", 2014, "smill");
    dvd_collection[9] = dvd1;
    dvd_collection[2] = dvd2;
    dvd_collection[14] = dvd3;

    std::cout << "\n[";
    for (size_t i = 0; i < CAPACITY; i++) {
        dvd_collection[i].show_dvd_info();
    }
    std::cout << "]" << std::endl;

    return 0;
}