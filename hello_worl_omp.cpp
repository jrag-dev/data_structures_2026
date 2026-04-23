#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        std::cout << "Hola desde el hilo " << ID << std::endl;
    }

    return 0;
}