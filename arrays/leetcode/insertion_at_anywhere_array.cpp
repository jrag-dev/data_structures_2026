/*
 * insertion_at_anywhere_array.cpp
 * Purpose: Inserting Anywhere in the Array
 * Jose Alvarado
 * 06-04-2026
*/

#include <cstddef>
#include <iostream>
#include <exception>
#include <stdexcept>
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
void insert_at_anywhere(T (&arr)[N], size_t &current_size, size_t position, T value) {
    if (current_size >= N) {
        throw ArrayFullException("Array full: Physical array bounds exceeded at N=" + std::to_string(N));
    }
    if (position > current_size) {
        throw std::out_of_range("Position out of range. The position must be between 0 and N: " + std::to_string(current_size));
    }
    if (position < current_size) {
        for (size_t i = current_size; i > position; i--) {
            arr[i] = arr[i-1];
        }
    } 
    arr[position] = value;
    current_size++;
}

template <class T, size_t N>
void show_array_elements(const T (&arr)[N], const size_t &current_size) {
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
    std::cout << "] (size=" << current_size << "/" << N << ")" << std::endl;
}

int main()
{
    const size_t CAPACITY = 9;
    int nums1[CAPACITY] = {5,2,4,6};
    size_t current_size = 4;

    std::cout << "\nInitial array: " << std::endl;
    show_array_elements(nums1, current_size);

    try {
        std::cout << "\nInserting at the position: " << 2 << " of the array... ";
        insert_at_anywhere(nums1, current_size, 2, 89);
        std::cout << "success!\n";
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nInserting at the position: " << 1 << " of the array... ";
        insert_at_anywhere(nums1, current_size, 1, 95);
        std::cout << "success!\n";
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }


    try {
        std::cout << "\nInserting at the position: " << 0 << " of the array... ";
        insert_at_anywhere(nums1, current_size, 0, 99);
        std::cout << "success!\n";
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nInserting at the position: " << 10 << " of the array... ";
        insert_at_anywhere(nums1, current_size, 10, 99);
        std::cout << "success!\n";
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}