/*
 * remove_element.cpp
 * Purpose: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
 * such that each unique element appears only once. The relative order of the elements should be kept the same.
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
int remove_duplicates_elements(std::vector<T>& V) {
    if (V.empty()) return 0;
    
    int slow = 0;
    int fast = 1;
    while (fast < V.size()) {
        if (V[fast] != V[slow]) {
            slow++;
            V[slow] = V[fast];
        }
        fast++;
    }
    V.resize(++slow);
    return slow;
}


int main()
{
    std::vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> nums2 = {1, 1, 2};


    show_array_elements(nums1);
    int k_values1 = remove_duplicates_elements(nums1);
    show_array_elements(nums1);

    show_array_elements(nums2);
    int k_values2 = remove_duplicates_elements(nums2);
    show_array_elements(nums2);

    std::cout << "k1: " << k_values1 << std::endl;
    std::cout << "k2: " << k_values2 << std::endl;

    return 0;
}