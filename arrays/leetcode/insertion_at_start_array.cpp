/*
 * insertion_at_start_array.cpp
 * Purpose: Inserting at the Start of an Array
 * Jose Alvarado
 * 06-04-2026
*/

#include <iostream>
#include <exception>
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
void insert_at_start(T (&arr)[N], size_t &current_size, T value) {
    if (current_size >= N) {
        throw ArrayFullException("Array full: Physical array bounds exceeded at N=" + std::to_string(N));
    }
    for (size_t i = current_size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
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
    std::cout << "]" << std::endl;
}

int main()
{
    const size_t CAPACITY = 6;
    int nums1[CAPACITY] = {5,2,4,6};
    size_t current_size = 4;

    std::cout << "\nInitial array: " << std::endl;
    show_array_elements(nums1, current_size);

    try {
        std::cout << "\nInserting at the start of the array... ";
        insert_at_start(nums1, current_size, 89);
        std::cout << "success!\n";
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cout << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nInserting at the start of the array... ";
        insert_at_start(nums1, current_size, 95);
        std::cout << "success!\n";
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cout << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }


    try {
        std::cout << "\nInserting at the start of the array... ";
        insert_at_start(nums1, current_size, 99);
        std::cout << "success!\n";
        show_array_elements(nums1, current_size);
    } catch (const ArrayFullException& e) {
        std::cout << "error!\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;
}