/*
 * squares_of_sorted_array.cpp
 * Purpose: Given an integer array nums sorted in non-decreasing order, return an array of the 
 * squares of each number sorted in non-decreasing order.
 * In this version, I used static arrays
 * Jose Alvarado
 * 03-04-2026
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>


template <class T>
void sort_for_insertion(std::vector<T>& V)
{
    for (int i = 1; i < V.size(); i++) {
        T key = V[i];
        int j = i-1;
        while (j >= 0 & V[j] > key) {
            V[j+1] = V[j];
            j = j-1;
        }
        V[j+1] = key;
    }
}

template <class T>
void array_of_square_elements(const std::vector<T>& V, std::vector<T>& squares)
{
    for (T vi : V) {
        squares.push_back(vi*vi);
    }
    //sort_for_insertion(squares);
    std::sort(squares.begin(), squares.end());
}

template <class T>
void show_array_elements(const std::vector<T>& V) {
    std::cout << "[";
    for (T vi : V) {
        std::cout << vi << " ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
std::vector<T> sorted_squares(std::vector<T>& nums) {
    std::vector<T> res(nums.size());
    int l = 0, r = nums.size() - 1;
    
    for (int k = nums.size() - 1; k >= 0; k--) {
        if (std::abs(nums[k]) > std::abs(nums[l])) res[k] = nums[r] * nums[r--];
        else res[k] = nums[l]*nums[l++];
    }
    return res;
}


int main()
{
    // Initial arrays
    std::vector<int> nums1 = {5,2,4,6,1,3};
    std::vector<int> nums2 = {-4,-1,0,3,10};
    std::vector<int> nums3 = {-7,-3,2,3,11};
    std::vector<int> squares1;
    std::vector<int> squares2;
    std::vector<int> squares3;

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
