#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main() {
    // TODO: Initialize a 3-story building with 3 units per floor using multidimensional vector.
    std::vector<std::vector<std::pair<std::string, std::string>>> building = {
        {std::make_pair("101", "Occupied"), std::make_pair("102", "Occupied"), std::make_pair("103", "Occupied")},
        {std::make_pair("201", "Occupied"), std::make_pair("202", "Occupied"), std::make_pair("203", "Occupied")},
        {std::make_pair("301", "Occupied"), std::make_pair("302", "Occupied"), std::make_pair("303", "Occupied")}
    };

    // TODO: Update the name of one of the apartments to "Vacant".
    building[0][2].second = "Vacant";

    // TODO: Traverse the building and print out the names of all units, one floor at a time.
    for (const auto& floor : building) {
        for (const auto& unit : floor) {
            std::cout << unit.first << "(" << unit.second << ")"<< " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}