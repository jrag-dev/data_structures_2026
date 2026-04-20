/*
 * linear_and_binary_search.cpp
 * Pupose: Search to value in an array and return the index if it's found.
 * I implemented lineal and binary methods
 *
 * Jose Alvarado
 * 11-04-2026
*/


#include <cmath>
#include <cstddef>
#include <iostream>
#include <optional>
#include <vector>


template <class T>
void show_array_elements(const std::vector<T>& V) {
    std::cout << "[";
    for (T vi : V) {
        std::cout << vi << " ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
std::optional<size_t> linear_search(const std::vector<T> &V, T value) {
    for (size_t i = 0; i < V.size(); i++) {
        if (V[i] == value) {
            return i;
        }
    }
    return std::nullopt;
}

template <class T>
std::optional<size_t> binary_search(const std::vector<T> &V, T target) {
    // Caso de borde: array vacio
    if (V.empty()) {
        return std::nullopt;
    }

    size_t low = 0;
    size_t high = V.size()-1;

    while (low <= high) {
        size_t middle = low + (high - low)/2;
        std::cout << low << ", " << middle << ", " << high << std::endl;
        
        if (V[middle] < target) {
            low = middle+1;
        } else if (V[middle] > target) {
            high = middle - 1;
        } else {
            return middle;
        }
    }
    return std::nullopt;
}

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
    
    
    std::cout << "\n----- Linear Search ------" << std::endl;
    auto found_value = linear_search(v1, 8);
    
    if (found_value.has_value()) {
        std::cout << "Value was  found, her index is: " << found_value.value() << std::endl;
    } else {
        std::cout << "Value doesn't found" << std::endl;
    }

    // Test with empty array
    std::vector<int> empty;
    if (auto idx = linear_search(empty, 42)) {
        std::cout << "Found at index: " << *idx << std::endl;
    } else {
        std::cout << "42 not found" << std::endl;
    }

    std::cout << "\n----- Binary Search ------" << std::endl;

    int n = 2;
    if (auto idx1 = binary_search(v1, n)) {
        std::cout << "Found at index: " << *idx1 << std::endl;
    } else {
        std::cout << n << " not found" << std::endl;
    }


    show_array_elements(v1);

    return 0;
}