/*
 * squares_of_sorted_array.cpp
 * Purpose: Given an integer array nums sorted in non-decreasing order, return an array of the 
 * squares of each number sorted in non-decreasing order.
 * In this version, I used static arrays
 * Jose Alvarado
 * 03-04-2026
*/

#include <iostream>

template <class T, unsigned int N>
void sort_for_insertion(T (&A)[N])
{
    for (int i = 1; i < N; i++) {
        T key = A[i];
        int j = i-1;
        while (j >= 0 & A[j] > key) {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
}

template <class T, unsigned int N>
void array_of_square_elements(const T (&A)[N], T (&squares)[N])
{
    for (int i = 0; i < N; i++) {
        squares[i] = A[i]*A[i];
    }
    sort_for_insertion(squares);
}

template <class T, unsigned int N>
void show_array_elements(const T (&A)[N]) {
    std::cout << "[";
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "]" << std::endl;
}


int main()
{
    // Initial arrays
    const unsigned int CAPACITY = 6;
    int nums1[CAPACITY] = {5,2,4,6,1,3};
    int nums2[CAPACITY-1] = {-4,-1,0,3,10};
    int nums3[CAPACITY-1] = {-7,-3,2,3,11};
    int squares1[CAPACITY];
    int squares2[CAPACITY-1];
    int squares3[CAPACITY-1];

    // show arrays
    show_array_elements(nums1);
    show_array_elements(nums2);
    show_array_elements(nums3);

    // sorting arrays
    sort_for_insertion(nums1);
    sort_for_insertion(nums2);
    sort_for_insertion(nums3);

    // show arrays
    show_array_elements(nums1);
    show_array_elements(nums2);
    show_array_elements(nums3);

    // show squares array
    array_of_square_elements(nums1, squares1);
    array_of_square_elements(nums2, squares2);
    array_of_square_elements(nums3, squares3);

    show_array_elements(squares1);
    show_array_elements(squares2);
    show_array_elements(squares3);

    return 0;
}
