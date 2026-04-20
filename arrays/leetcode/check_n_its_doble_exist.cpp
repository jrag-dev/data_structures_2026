/* LeetCode Problems
 * check_n_its_double_exist.cpp
 * Check If N and Its Double Exist
 * José Alvarado
 * 15-04-2026
*/

#include <cstddef>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>


template <class T>
std::tuple<bool, int, int> check_n_its_double_exist(const std::vector<T>& V) {

    for (size_t i = 0; i < V.size(); i++) {
        for (size_t j = i + 1; j < V.size(); j++) {
            std::cout << "\ni: " << i << " | j: " << j << std::endl;
            std::cout << "V[" << i << "]: " << V[i] << "V[" << j << "]: " << 2*V[j] <<std::endl; 
            if (V[i] == 2* V[j] || V[j] == 2 * V[i]) {
                return {true, i, j};
            }
        }
    }
    return {false, -1, -1};
}


int main()
{
    std::vector<int> A = {10, 2, 5, 3};
    std::vector<int> B = {3, 1, 7, 11};

    // call to ccheck_n_its_double_exist
    std::cout << "\nFor A: " << std::endl; 
    auto [exist1, i1, j1] = check_n_its_double_exist(A);
    std::cout << (exist1 == true ? "TRUE -> (" + std::to_string(i1) + "," + std::to_string(j1) + ")": "FALSE") << std::endl;
    
    std::cout << "\nFor B: " << std::endl;    
    auto [exist2, i2, j2] = check_n_its_double_exist(B);
    std::cout << (exist2 == true ? "TRUE -> (" + std::to_string(i2) + "," + std::to_string(j2) + ")": "FALSE") << std::endl;

    return 0;
}