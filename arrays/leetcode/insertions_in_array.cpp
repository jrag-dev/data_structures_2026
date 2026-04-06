/*
 * insertions_in_array.cpp
 * Purpose: Inserting at the End of an Array
 * Jose Alvarado
 * 06-04-2026
*/

#include <cstddef>
#include <exception>
#include <iostream>
#include <string>

class ArrayFullException : public std::exception {
    private:
        std::string message;
    public:
        ArrayFullException(const std::string& msg) : message(msg) {}

        virtual const char* what() const noexcept override {
            return message.c_str();
        }
};

template <class T, size_t N>
void inserting_at_end(T (&arr)[N], size_t &current_size, T value) {
    if (current_size >= N) {
        throw ArrayFullException("Array full: Physical array bounds exceeded at N=" + std::to_string(N));
    }

    arr[current_size] = value;
    std::cout << "success!" << std::endl;
    current_size++;
}

template <class T, size_t N>
void show_array_elements(const T (&arr)[N], size_t current_size) {
    std::cout << "[";
    for (size_t i = 0; i < N; i++) {
        if (i < current_size) {
            std::cout << arr[i] << " ";
        } else {
            std::cout << "_";
        }
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

int main()
{
    // Initial arrays
    const size_t CAPACITY = 6;
    int nums1[CAPACITY] = {5,2,4,6};
    size_t current_size = 4;

    show_array_elements(nums1, current_size);

    try {
        std::cout << "\nInserting in position: " << current_size << " the value: 21... ";
        inserting_at_end(nums1, current_size, 21);
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        std::cout << "\nInserting in position: " << current_size << " the value: 75... ";
        inserting_at_end(nums1, current_size, 75);
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nInserting in position: " << current_size << " the value: 95... ";
        inserting_at_end(nums1, current_size, 95);
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cout << "error!" << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}