/* Leetcode problems solutions
 * in_place_operations.cpp
 * Given an Array of integers, return an Array where every element at an even-indexed position is squared.
 * Jose Alvarado
 * 20-04-2026
*/
#include <vector>
#include <iostream>

template <class T>
void show_vector(const std::vector<T>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
void square_even(std::vector<T>& v) {
    if (v.empty()) {
        return;
    }
    for (size_t i = 0; i < v.size(); i += 2) {
        v[i] = v[i] * v[i];
    }
}

int main() {
    std::vector<int> a1 = {9, -2, -9, 11, 56, -12, -3};

    show_vector(a1);
    square_even(a1);
    show_vector(a1);

    return 0;
}