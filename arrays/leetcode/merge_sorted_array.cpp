/*
 * merge_sorted_array.cpp
 * Purpose: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 *
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
void merge(std::vector<T>& nums1, int m, std::vector<T>& nums2, int n) {
    std::vector<T> result;
    result.reserve(m+n);

    int i = 0, j = 0;

    // Mezclar
    while(i < m && j < n) {
        std::cout << "i: " << i << "\t, j: " << j << "\t, nums[" << i << "]: " << nums1[i] << std::endl;
        if (nums1[i] <= nums2[j]) {
            result.push_back(nums1[i++]);
        } else {
            result.push_back(nums2[j++]);
        }
    }

    // Agregar elementos restantes
    while (i < m) result.push_back(nums1[i++]);
    while (j < n) result.push_back(nums2[j++]);

    // cpoiar de vuelta a nums1
    nums1 = result;
}

template <class T>
void merge_in_place(std::vector<T>& nums1, int m, std::vector<T>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    // fusionar desde atrás (in place) - Es el óptimo
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            i--;
            k--;
        } else {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}


int main()
{
    const int C1 = 6, C2 = 3, C3 = 1;
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 5, 6};
    std::vector<int> nums3 = {0};
    std::vector<int> nums4 = {};
    nums1.resize(C1);

    /*
    std::cout << "\n*** Usando Fusión con arreglo auxiliar ***" << std::endl;
    merge(nums1, 3, nums2, 3);
    std::cout << nums1.size() <<  std::endl;
    show_array_elements(nums1);

    merge(nums3, 0, nums4, 0);
    std::cout << nums3.size() <<  std::endl;
    show_array_elements(nums3);
    */

    std::cout << "\n*** Usando Fusión desde atrás (In-Place) ***" << std::endl;
    merge_in_place(nums1, 3, nums2, 3);
    std::cout << nums1.size() <<  std::endl;
    show_array_elements(nums1);

    merge_in_place(nums3, 0, nums4, 0);
    std::cout << nums3.size() <<  std::endl;
    show_array_elements(nums3);

    return 0;
}