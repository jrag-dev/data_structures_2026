/*
 * deletion_from_array.cpp
 * Purpose: It's look how deletion works, and their three differents cases:
 * 1. Deleting the last element of the Array
 * 2. Deleting the first element of the Array
 * 3. Deletion at any given index
 *
 * Jose Alvarado
 * 09-04-2026
*/

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>


template <class T, size_t N>
void show_array_elements(T (&V)[N], size_t current) {
    std::cout << "\n[";
    size_t i = 0;
    while (i < current) {
        std::cout << V[i++] << " ";
    }

    while (i++ < N) std::cout << " _ ";

    std::cout << "]" << std::endl;
}

template <class T, size_t N>
void remove_last_element(T (&V)[N], size_t &current) {
    if (current <= 0) {
        throw std::out_of_range("Array is empty. Cannot delete.");
    }
    current--;
}

template <class T, size_t N>
void remove_first_element(T (&V)[N], size_t &current) {
    if (current <= 0) {
        throw std::out_of_range("The array is empty. Cannot delete.");
    }

    size_t i = 0;
    while (i < current) {
        V[i] = V[i+1];
        i++;
    }
    current--;
}

template <class T, size_t N>
void remove_at_position(T (&V)[N], size_t &current, const size_t position) {
    if (current <= 0) {
        throw std::out_of_range("Array is empty. Cannot delete.");
    }
    if (position < 0 || position >= current) {
        throw std::out_of_range("Position out of range. Valid positions 0 to " + std::to_string(current - 1));
    }

    size_t i = position;
    while (i < current) {
        V[i] = V[i+1];
        i++;
    }
    current--;
}


int main()
{
    const size_t C1 = 10, C2 = 6;
    int nums1[C1] = {11, 12, 13, 14, 15, 16, 17};
    int nums2[C2] = {1, 2, 3, 4, 5};
    size_t current_1 = 7, current_2 = 5;

    // show arrays
    show_array_elements(nums1, current_1);
    show_array_elements(nums2, current_2);

    std::cout << "\n***** Working with deleting at end *****\n";
    try {
        remove_last_element(nums2, current_1 );
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        remove_last_element(nums1, current_1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        remove_last_element(nums2, current_2);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        remove_last_element(nums1, current_1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // show arrays
    show_array_elements(nums1, current_1);
    show_array_elements(nums2, current_2);

    std::cout << "\n***** Working with deleting at beginner *****\n";

    try {
        remove_first_element(nums1, current_1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        remove_first_element(nums1, current_1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    show_array_elements(nums1, current_1);

    std::cout << "\n***** Working with deleting at anywhere *****\n";

    try {
        remove_at_position(nums1, current_1, 2);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        remove_at_position(nums1, current_1, 1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    show_array_elements(nums1, current_1);

    return 0;
}