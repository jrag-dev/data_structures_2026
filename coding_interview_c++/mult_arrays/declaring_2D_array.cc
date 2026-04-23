/*
 * declaring_2D_array.cc
*/

#include <iostream>
#include <vector>


void printing_array_elements(const std::vector<std::vector<int>>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        for (size_t j = 0; j < array.size(); j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Creating a 2D vector
    std::vector<std::vector<int>> array = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Called to printing the array
    printing_array_elements(array);

    // Accessing an element
    std::cout << array[1][0] << std::endl;

    // Updating an element
    array[0][1] = 10;
    printing_array_elements(array);

    // Finding the number of rows
    int num_floors = array.size();
    std::cout << num_floors << std::endl;

    // Finding the number of colums
    int num_units = array[0].size();
    std::cout << num_units << std::endl;

    // Adding a new row to our array
    array.push_back({10, 11, 12});
    for (const auto& floor : array) {
        for (size_t unit : floor) {
            std::cout << unit << " ";
        }
        std::cout << std::endl;
    }

    // Removing the second element of the second row
    std::cout << "\nRemoving the second element of the second row:: " << std::endl;
    array[1].erase(array[1].begin() + 1);
    for (const auto& floor : array) {
        for (size_t unit : floor) {
            std::cout << unit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}