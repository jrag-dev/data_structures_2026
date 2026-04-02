/*
 * 07_eliminacion_pos_especifica.cpp
 *
 * Propósito: Eliminar un elemento en una posición dada, desplazando elementos a la izquierda.
 *
 * Complejidad: O(n)
 *
 * Jose Alvarado
 * 30-03-2026
 */

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T, size_t N>
void traversal_array(const T (&arr)[N]) {
  cout << "[ ";
  for (size_t i = 0; i < N; i++) {
    cout << arr[i];
    if (i < N - 1) {
      cout << " | ";
    }
  }
  cout << " ]" << endl;
}


template <class T, size_t N>
T delete_at_position(T (&A)[N], size_t &current_size, size_t pos) {
  if (current_size < 0) {
    throw std::out_of_range("Error: Array is empty.");
  }
  if (current_size >= N) {
    throw std::out_of_range("Error: Array full");
  }
  if (pos < 0 || pos >= current_size) {
    throw std::out_of_range("Error: Invalid position.");
  }

  // guardar el valor eliminado
  T deleted_value = A[pos];

  // desplazar los elementos hacia la derecha
  for (size_t i = pos; i < current_size; i++) {
    A[i] = A[i+1];
  }

  // actualizando el tamaño actual del arreglo
  current_size--;

  return deleted_value;
}


int main(int argc, char *argv[])
{
  const size_t CAPACITY = 10;
  double A[CAPACITY] = {21, 6.0, 11.0, 55.0, 47.0, 3.0};
  size_t current_size = 6;

  cout << "Current size: " << current_size << endl;
  traversal_array(A);

  try {
    size_t deleted_value = delete_at_position<double>(A, current_size, 2);
    cout << "\nSe elimino el valor: " << deleted_value << endl;
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << endl;
  }
  
  traversal_array(A); 

  cout << "Current size: " << current_size << endl;
  
  return 0;
}


