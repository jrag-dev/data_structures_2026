/*
 * numbers_with_even_digits.cpp
 * Purpose: Given an array nums of integers, return how many of them contain an even number of digits.
 * Jose Alvarado
 * 03-04-2026
*/

#include <iostream>
#include <algorithm>
#include <vector>


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

template <class T>
int find_number_of_digits(const T &num) {
    T n = num;
    int count = 0;
    while (n > 0) {
        int digito = n % 10;
        std::cout << digito << " ";
        count++;
        n /= 10;
    }
    return count;
}

template <class T>
int count_even_numbers(const std::vector<T>& nums) {
    int count_even = 0;
    for (int num : nums) {
        int n = find_number_of_digits(num);
        std::cout << "n: " << n << std::endl;
        if (n % 2 == 0) {
            count_even++;
        }
    }
    return count_even;
}

int main()
{
    std::vector<int> v1 = {12,345,2,6,7896};
    std::vector<int> v2 = {555, 901, 482, 1771};
    std::vector<int> v3 = {04155600,17, 9, 125, 6533, 478965, 45879,2,688,45};

    std::cout << "\n*** Test 1: v1 ***" << std::endl;
    int number_of_even1 = count_even_numbers(v1);
    std::cout << "\nNumber of numbers with even number of digits: " << number_of_even1 << std::endl;

    std::cout << "\n*** Test 2: v2 ***" << std::endl;
    int number_of_even2 = count_even_numbers(v2);
    std::cout << "\nNumber of numbers with even number of digits: " << number_of_even2 << std::endl;

    std::cout << "\n*** Test 3: v3 ***" << std::endl;
    int number_of_even3 = count_even_numbers(v3);
    std::cout << "\nNumber of numbers with even number of digits: " << number_of_even3 << std::endl;
    return 0;
}
