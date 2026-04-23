#include <iostream>
#include <vector>
#include <string>

int main() {
    // Initializing a 2D array that represents an apartment building
    std::vector<std::vector<std::string>> apartments = {
        {"Apt 101", "Apt 102"},
        {"Apt 201", "Apt 202"}
    };

    // TODO: Add a new floor with apartments to our 'apartment building' and then make a walk visiting each apartment on every floor.
    apartments.push_back({"Apt 301", "Apt 302"});
    for (const auto& floor : apartments) {
        for (const auto& unit : floor) {
            std::cout << unit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}