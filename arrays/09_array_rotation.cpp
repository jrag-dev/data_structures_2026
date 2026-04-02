/*
 * 09_rotacion_der_izq.cpp
 * Propósito: Rotar elementos k posiciones.
 * Complejidad: O(n*k)
 * Jose Alvarado
 * 01-04-2026
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
void rotate_left_one_position(T (&A)[N]) {
    T first_element = A[0];

    for (size_t i = 0; i < N-1; i++) {
        A[i] = A[i+1];
    }
    A[N-1] = first_element;
}

template <class T, size_t N>
void rotate_left_k_position(T (&A)[N], size_t k) {
    if (N == 0) return;
    k = k % N;

    if (k == 0) return;

    for (size_t i = 0; i < k; i++) {
        rotate_left_one_position(A);
    }
}

int main() {
    const size_t CAPACITY = 10;
    double A[CAPACITY] = {1, 2, 3, 4, 5, 6, 7 ,8, 9, 0};
    
    std::cout << "\nOriginal array: ";
    traversal(A);

    std::cout << "\nAfter 1 left rotation: ";
    rotate_left_one_position(A);
    traversal(A);

    std::cout << "\nAfter 3 more left rotations (total 4): ";
    rotate_left_k_position(A, 3);
    traversal(A);

    std::cout << std::endl;

    return 0;
}