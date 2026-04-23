#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

const int N = 1000;  // Matriz 1000x1000
std::vector<double> A(N*N), B(N*N), C(N*N);

void benchmark_matmul(int num_threads) {
    omp_set_num_threads(num_threads);
    
    auto start = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i*N + k] * B[k*N + j];
            }
            C[i*N + j] = sum;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Hilos: " << num_threads << " -> Tiempo: " << duration.count() << " ms" << std::endl;
}

int main() {
    // Inicializar matrices
    for (int i = 0; i < N*N; i++) {
        A[i] = 1.0;
        B[i] = 1.0;
    }
    
    benchmark_matmul(1);  // Serial
    benchmark_matmul(4);  // Núcleos físicos
    benchmark_matmul(8);  // Con hyperthreading
    
    return 0;
}