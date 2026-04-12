/*
 * remove_element.cpp
 * Purpose: Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
 * The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
 * 
 * Jose Alvarado
 * 09-04-2026
*/

#include <iostream>
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
int remove_element(std::vector<T>& V, int val) {
    int left = 0;
    int right = static_cast<int>(V.size()-1);
    int k = 0;
    while (left <= right) {
        if (V[left] == val) {
            V[left] = V[right];
            right--;
        } else {
            left++;
        }
    }
    V.resize(left);
    return left;
}


int main()
{
    std::vector<int> nums1 = {0, 1, 2, 2, 3, 0, 4, 2};
    const int VAL = 2;

    show_array_elements(nums1);
    int k_values = remove_element(nums1, VAL);
    show_array_elements(nums1);
    std::cout << "\nThere are k: " << k_values << " values differents of val: " << VAL << std::endl;

    return 0;
}