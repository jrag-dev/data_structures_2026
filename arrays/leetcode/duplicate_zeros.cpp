/*
 * duplicate_zeros.cpp
 * Purpose: Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining 
 * elements to the right.
 * Jose Alvarado
 * 07-04-2026
*/

#include <iostream>
#include <vector>

template <class T>
void show_array_elements(const std::vector<T>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
void displace_elements(std::vector<T>& arr, size_t index) {
    for (size_t i = arr.size()-1; i > index; i--) {
        arr[i] = arr[i-1];
    }
}

template <class T>
void duplicate_zeros_fn(std::vector<T>& arr) {
    size_t i = 0;
    while(i < arr.size()) {
        if (arr[i] == 0) {
            displace_elements(arr, i);
            i += 2;
        } else {
            i++;
        }
    }
}

int main()
{
    std::vector<int> arr1 = {1,0,2,3,0,4,5,0};
    std::vector<int> arr2 = {0, 0, 0, 1, 1, 2, 0, 0, 0, 2, 2, 2, 2};
    std::vector<int> arr3 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1};

    duplicate_zeros_fn(arr1);
    duplicate_zeros_fn(arr2);
    duplicate_zeros_fn(arr3);
    std::cout << std::endl;
    show_array_elements(arr1);
    show_array_elements(arr2);
    show_array_elements(arr3);

    return 0;
}