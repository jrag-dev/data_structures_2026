#include <iostream>
#include <vector>

int main() {
    // Creating a 2D vector representing an apartment building
    std::vector<std::vector<std::string>> building = {
        {"1A", "1B", "1C"},
        {"2A", "2B", "2C"},
        {"3A", "3B", "3C"}
    };

    // TODO: Complete the code to print the apartment codes of the ground floor only.
    for (size_t i = 0; i < building.size(); i++) {
        for (size_t j = 0; j < building[0].size(); j++) {
            if (i >= 1) continue;
            else std::cout << building[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}