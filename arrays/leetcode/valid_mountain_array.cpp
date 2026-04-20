/* LeetCode Problems
 * valid_mountain_array.cpp
 * Valid Mountain Array: Given an array of integers arr, return true if and only if it is a valid mountain array.
 * José Alvarado
 * 15-04-2026
*/

#include <iostream>
#include <vector>


template <class T>
bool valid_mountain_array(const std::vector<T>& arr) {
    if (arr.size() < 3) {
        return false;
    }
    
    int i = 0;
    size_t n = arr.size();
    while ((i + 1 < n) && arr[i] < arr[i+1]) {
        //std::cout << "arr[" << i << "]: " << arr[i] << "\tarr[" << (i + 1) << "]: " << arr[i+1] << std::endl;
        i++;
    }

    if (i == 0 || i == n - 1) {
        return false;
    }
   
    while (i + 1 < n && arr[i] > arr[i+1]) {
        //std::cout << "arr[" << i << "]: " << arr[i] << "\tarr[" << (i + 1) << "]: " << arr[i+1] << std::endl;
        i++;
    }

    return i == n - 1;
}


int main()
{
    std::vector<int> A = {0, 2, 3, 4, 5, 2, 1, 0};
    std::vector<int> B = {2, 1};
    std::vector<int> C = {3, 5, 5};
    std::vector<int> D = {0, 3, 2, 1};
    std::vector<int> E = {1, 2, 3, 4, 5};     // Solo subida
    std::vector<int> F = {5, 4, 3, 2, 1};     // Solo bajada
    std::vector<int> G = {1, 2, 2, 3, 2, 1};  // Meseta

    std::cout << "For A: " << std::endl;
    bool is_valid_mountain1 = valid_mountain_array(A);
    std::cout << (is_valid_mountain1 == true ? "TRUE" : "FALSE") << std::endl;

    std::cout << "\nFor B: " << std::endl;
    bool is_valid_mountain2 = valid_mountain_array(B);
    std::cout << (is_valid_mountain2 == true ? "TRUE" : "FALSE") << std::endl;

    std::cout << "\nFor C: " << std::endl;
    bool is_valid_mountain3 = valid_mountain_array(C);
    std::cout << (is_valid_mountain3 == true ? "TRUE" : "FALSE") << std::endl;

    std::cout << "\nFor D: " << std::endl;
    bool is_valid_mountain4 = valid_mountain_array(D);
    std::cout << (is_valid_mountain4 == true ? "TRUE" : "FALSE") << std::endl;

    std::cout << "\nFor E: " << std::endl;
    bool is_valid_mountain5 = valid_mountain_array(E);
    std::cout << (is_valid_mountain5 == true ? "TRUE" : "FALSE") << std::endl;

    std::cout << "\nFor F: " << std::endl;
    bool is_valid_mountain6 = valid_mountain_array(F);
    std::cout << (is_valid_mountain6 == true ? "TRUE" : "FALSE") << std::endl;

    std::cout << "\nFor G: " << std::endl;
    bool is_valid_mountain7 = valid_mountain_array(G);
    std::cout << (is_valid_mountain7 == true ? "TRUE" : "FALSE") << std::endl;

    auto test = [](const std::vector<int>& arr, bool expected) {
        bool result = valid_mountain_array(arr);
        std::cout << "Array: ";
        for (int x : arr) std::cout << x << " ";
        std::cout << "-> " << (result ? "TRUE" : "FALSE");
        std::cout << (result == expected ? " ✓" : " ✗") << std::endl;
    };

    test(A, true);
    test(B, false);
    test(C, false);
    test(D, true);
    test(E, false);
    test(F, false);
    test(G, false);

    return 0;
}