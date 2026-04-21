/* Leetcode problems solutions
 * replace_elements_with_greatest.cpp
 * Given an array arr, replace every element in that array with the greatest element among the 
 * elements to its right, and replace the last element with -1.
 * Jose Alvarado
 * 20-04-2026
*/
#include <vector>
#include <iostream>

template <class T>
void show_vector(const std::vector<T>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        if (i == v.size() - 1)
            std::cout << v[i];
        else
            std::cout << v[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
void replace_with_greatest(std::vector<T>& v) {
    if (v.empty()) {
        return;
    }

    for (size_t i = 0; i < v.size()-1; i++) {
        T greatest = v[i+1];
        for (size_t j = i; j < v.size()-1; j++) {
            std::cout << "(" << i << ", " << j << ")" << std::endl;
            if (v[j+1] > greatest)
                greatest = v[j+1];
        }
        v[i] = greatest;
    }
    v[v.size()-1] = static_cast<T>(-1);
}

template <class T>
void replace_with_greatest_optim(std::vector<T>& v) {
    if (v.empty()) {
        return;
    }
    
    T max_from_right = -1;
    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << "(" << i << ")" << std::endl;
        T current = v[i];
        v[i] = max_from_right;
        if (current > max_from_right) {
            max_from_right = current;
        }
    }
}


int main() {
    std::vector<int> a1 = {17, 18, 5, 4, 6, 1};
    std::vector<int> a2 = {400};
    std::vector<int> v1 = {17, 18, 5, 4, 6, 1};
    std::vector<int> v2 = {400};

    std::cout << "\n\033[34mWorking with a1: " << std::endl;
    show_vector(a1);
    replace_with_greatest(a1);
    show_vector(a1);

    std::cout << "\n\033[35mWorking with a2: " << std::endl;
    show_vector(a2);
    replace_with_greatest(a2);
    show_vector(a2);

    std::cout << "\n\033[34mWorking with a1, scale[O(n)]: " << std::endl;
    show_vector(v1);
    replace_with_greatest_optim(v1);
    show_vector(v1);

    std::cout << "\n\033[35mWorking with a2, scale[O(n)]: " << std::endl;
    show_vector(v2);
    replace_with_greatest_optim(v2);
    show_vector(v2);


    return 0;
}