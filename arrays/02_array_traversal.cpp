/*
 * 02_recorrido.cpp
 * Recorrer el arreglo, visitando cada elemento del arreglo.
 *
 * Algoritmo iterativo:
 *
 * FUNCIÓN recorrer(arr, tamaño):
 *  PARA i DESDE 0 HASTA tamaño-1:
 *    // Procesar arr[i] (ej: imprimir, acumular, etc.)
 *    imprimir(arr[i])
 *  FIN PARA
 * FIN FUNCIÓN
 *
 * Jose Alvarado
 * 30-03-2026
*/

#include <iostream>
using namespace std;


template<class T, size_t N>
void traversal_array(const T (&arr)[N]) {
  cout << "N: " << N << endl;
  cout << "[ ";
  for (size_t i = 0; i < N; i++) {
    cout << arr[i] << " | ";
  }
  cout << " ]\n";
}


int main(int argc, char *argv[])
{
  // declaring and initialization an array of 5 elements
  int arr[10] = {2, 4, 6, 8, 10, 12, 13, 17, 21, 29};

  // call to traversal_array function
  traversal_array(arr);

  cout << "\n" << "FIN!" << endl;

  return 0;
}
