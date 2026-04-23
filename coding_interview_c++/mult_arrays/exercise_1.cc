#include <iostream>
#include <string>
#include <vector>

int main() {
    // Define the building with 2 floors and 3 apartments on each
    // Pair consists of apartment number and occupancy status (true - occupied, false - unoccupied)
    std::vector<std::vector<std::pair<std::string, bool>>> building = {
        {std::make_pair("101", true), std::make_pair("102", false), std::make_pair("103", false)},
        {std::make_pair("201", true), std::make_pair("202", true), std::make_pair("203", false)}
    };
    // Traverse the building
    for (const auto &floor : building) {
        for (const auto &apt : floor) {
            if (!apt.second) { // Checking occupancy status
                std::cout << "Apartment " << apt.first << " is not occupied." << std::endl;
            }
        }
    }
    return 0;
}