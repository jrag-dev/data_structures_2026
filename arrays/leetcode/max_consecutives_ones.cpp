/*
 * max_consecutives_ones.cpp
 * Purpose: Given a binary array nums, return the maximum number of consecutive 1's in the arrai
 * Jose Alvarado
 * 02-04-2026
*/

#include <iostream>
#include <algorithm>
#include <vector>


template <class T, unsigned int N>
int max_consecutives_ones_fn(const T (&A)[N])
{
    int max_ones = 0;
    int current = 0;

    for (size_t i = 0; i < N; i++) {
        if (A[i] == 1) 
        {
            current++;
            max_ones = std::max(max_ones, current);
        } else 
        {
            current = 0;
        }
    }
    return max_ones;
}

template <class T>
int max_consecutives_ones_vector(const std::vector<T>& B) {
    int max_ones = 0;
    int current = 0;

    for (int bi : B) {
        if (bi == 1) {
            current++;
            max_ones = std::max(max_ones, current);
        } else {
            current = 0;
        }
    }
    return max_ones;
} 


int main()
{
    // Initial arrays
    const unsigned int CAPACITY = 6;
    int nums1[CAPACITY] = {1, 1, 0, 1, 1, 1};
    int nums2[CAPACITY] = {1, 0, 1, 1, 0, 1};
    int nums3[CAPACITY+6] = {1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1};

    std::cout << "\n****** Usando arreglos estáticos ******" << std::endl;
    // Call to max_consecutives_ones_fn
    int max_ones_nums1 = max_consecutives_ones_fn(nums1);
    std::cout << "\nMaximum consecutives ones: " << max_ones_nums1 << std::endl;

    int max_ones_nums2 = max_consecutives_ones_fn(nums2);
    std::cout << "\nMaximum consecutives ones: " << max_ones_nums2 << std::endl;

    int max_ones_nums3 = max_consecutives_ones_fn(nums3);
    std::cout << "\nMaximum consecutives ones: " << max_ones_nums3 << std::endl;

        std::cout << "\n****** Usando arreglos dinámicos (vector) ******" << std::endl;
    // Call to max_consecutives_ones_fn
    int max_ones_nums4 = max_consecutives_ones_fn(nums1);
    std::cout << "\nMaximum consecutives ones: " << max_ones_nums4 << std::endl;

    int max_ones_nums5 = max_consecutives_ones_fn(nums2);
    std::cout << "\nMaximum consecutives ones: " << max_ones_nums5 << std::endl;

    int max_ones_nums6 = max_consecutives_ones_fn(nums3);
    std::cout << "\nMaximum consecutives ones: " << max_ones_nums6 << std::endl;

    return 0;
}
