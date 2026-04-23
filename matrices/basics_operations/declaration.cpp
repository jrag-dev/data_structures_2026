/*
 * declaration.cpp
 * Purpose: Declaring and show the elements of a matrix
 *          Also, I implemented the addtion, scalar_matrix multiplication
 *          and matrix-matrix multiplication of two matrices A and B
 *
 * Jose Alvarado
 * 13-04-2026
*/

#include <iostream>


template <class T, unsigned int M, unsigned int N>
void show_matrix_elements(const T (&A)[M][N]) {
    for (unsigned int i = 0; i < M; i++) {
        for (unsigned int j = 0; j < N; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <class T, unsigned int M, unsigned int N>
void transposition(const T (&A)[M][N], T (&AT)[N][M]) {
    for (unsigned int i = 0; i < N; i++) {
        for (unsigned int j = 0; j < M; j++) {
            AT[i][j] = A[j][i];
        }
    }
}

template <class T, unsigned int M, unsigned int N>
void sum_matrices_a_b(const T (&A)[M][N], const T (&B)[M][N], T (&C)[M][N]) {
    for (unsigned int i = 0; i < M; i++) {
        for (unsigned int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

template <class T, unsigned int M, unsigned int N>
void scalar_matrix_multiplication(T (&A)[M][N], T alpha) {
    for (unsigned int i = 0; i < M; i++) {
        for (unsigned int j = 0; j < N; j++) {
            A[i][j] *= alpha;
        }
    }
}

template <class T, unsigned int Q, unsigned int P, unsigned int R>
void matrix_matrix_multiplication(const T (&A)[Q][P], const T (&B)[P][R], T (&C)[Q][R]) {
    for (unsigned int i = 0; i < Q; i++) {
        for (unsigned int j = 0; j < R; j++) {
            C[i][j] = 0;  // CONDICIÓN CRÍTICA: Asegura que empezamos en cero
            for (unsigned int k = 0; k < P; k++) {
                C[i][j] += (A[i][k]*B[k][j]);
            }
        }
    }
}

template <class T, unsigned int Q, unsigned int P, unsigned int R>
void matrix_matrix_mult_row_major(const T (&A)[Q][P], const T (&B)[P][R], T (&C)[Q][R]) {
    for (unsigned int i = 0; i < Q; i++) {
        for (unsigned int k = 0; k < P; k++) {
            T aik = A[i][k];
            for (unsigned int j = 0; j < R; j++) {
                C[i][j] += (aik * B[k][j]);
            }
        }
    }
}

int main()
{
    const unsigned int N = 4, M = 3;
    const unsigned int Q = 2, P=3, R = 2;
    int m1[M][N] = {
        {1, 2, 3, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 0}
    };
    int m2[M][N] = {
        {1, 2, 3, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 0}
    };
    int a[Q][P] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int b[P][R] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    int sum_m1_m2[M][N];
    int m1t[N][M] = {};
    int c[Q][R];
    int d[Q][R] = {};
    const int ALPHA = 2;

    std::cout << "\nM1: " << std::endl;
    show_matrix_elements(m1);

    std::cout << "\nM2: " << std::endl;
    show_matrix_elements(m2);
    
    std::cout << "\nTranspose to M1: " << std::endl;
    transposition(m1, m1t);
    show_matrix_elements(m1t);

    std::cout << "\nScalar-Matrix Multiplication for M1T: " << std::endl;
    scalar_matrix_multiplication(m1t, ALPHA);
    show_matrix_elements(m1t);

    std::cout << "\nScalar-Matrix Multiplication for M1: " << std::endl;
    scalar_matrix_multiplication(m1, ALPHA);
    show_matrix_elements(m1);

    std::cout << "\nAddition of M1 + M2: " << std::endl;
    sum_matrices_a_b(m1, m2, sum_m1_m2);
    show_matrix_elements(sum_m1_m2);

    std::cout << "\nMAtrix-Matrix Multiplication of A * B: " << std::endl;
    matrix_matrix_multiplication(a, b, c);
    show_matrix_elements(c);

    std::cout << "\nMAtrix-Matrix Mult Row MAjor of A * B: " << std::endl;
    matrix_matrix_mult_row_major(a, b, d);
    show_matrix_elements(d);

    return 0;
}