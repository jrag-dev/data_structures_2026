/*
 * 08_invertir_array.cpp
 * Propósito: Invertir el orden de los elementos.
 * Complejidad: O(n)
 * Jose Alvarado
 * 31-03-2026
*/

#include <iostream>

template <class T, size_t N>
void traversal(const T (&A)[N]) {
    std::cout << "\n[";
    for (size_t i = 0; i < N; i++) {
        std::cout << A[i];
        if (i < N-1) {
            std::cout << " | ";
        }
    }
    std::cout << "]" << std::endl;
}

template <class T, size_t N>
void reverse_array(T (&A)[N]) {
    if (N <= 1) return; // Proteccción contra arrays vacíos o de 1 elemento.

    size_t left = 0;
    size_t right = N-1;

    while (left < right) {
        T temp = A[left];
        A[left] = A[right];
        A[right] = temp;

        left++;
        right--;
    }
}

int main() {
    const size_t CAPACITY = 10;
    double A[CAPACITY] = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 0};
    
    std::cout << "\nOriginal array: ";
    traversal(A);

    std::cout << "\nAfter reverse the array: ";
    reverse_array(A);
    traversal(A);

    std::cout << std::endl;

    return 0;
}
