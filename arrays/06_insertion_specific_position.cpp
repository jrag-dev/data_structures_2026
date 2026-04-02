/*
 * 06_insercion-pos_especifica.cpp
 * Propósito: Insertar un elemento en una posición dada, desplazando elementos a la derecha.
 * Jose Alvarado
 * 30-03-2026
 */

#include <iostream>
#include <stdexcept>
#include <string>

template <class T, size_t N>
void traversal_array(const T (&arr)[N]) {
  std::cout << "[ ";
  for (size_t i = 0; i < N; i++) {
    std::cout << arr[i];
    if (i < N - 1) {
      std::cout << " | ";
    }
  }
  std::cout << " ]" << std::endl;
}


template <class T, size_t N>
void insertion_position(T (&A)[N], size_t &current_size, size_t pos, T new_value) {
  if (current_size >= N) {
    throw std::out_of_range("\t-> Error: Array full. Cannot insert new element!");
  }
  if (pos > current_size) {
    throw std::out_of_range("Error: Invalid position. Position must be between 0 and " + std::to_string(current_size));
  }

  // desplazar los elementos hacia la derecha
  for (size_t i = current_size; i > pos; i--) {
    A[i] = A[i-1];
  }

  // insertar el nuevo valor en la posicion
  A[pos] = new_value;

  // actualizando el tamaño actual del arreglo
  current_size++;
}


int main(int argc, char *argv[])
{
  const size_t CAPACITY = 10;
  double A[CAPACITY] = {21, 6.0, 11.0, 55.0, 47.0, 3.0};
  size_t current_size = 6;

  std::cout << "\nInitial array (size = " << current_size << "): ";
  traversal_array(A);

  // Prueba 1: Insertar en medio (posición = 2)
  try {
    std::cout << "\nInserting 99.0 at position 2...";
    insertion_position<double>(A, current_size, 2, 99.0);
    std::cout << "\tSuccess!" << std::endl;
    std::cout << "After insertion (size = " << current_size << "): ";
    traversal_array(A);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  // Prueba 2: Insertar al final (posición = current_size)
  try {
    std::cout << "\nInserting 101.0 at position ..." + std::to_string(current_size);
    insertion_position<double>(A, current_size, current_size, 101.0);
    std::cout << "\tSuccess!" << std::endl;
    std::cout << "After insertion (size = " << current_size << "): ";
    traversal_array(A);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
  
  // Prueba 3: Insertar al inicio (posición = 0)
  try {
    std::cout << "\nInserting 95.0 at the beginning (position 0)...";
    insertion_position<double>(A, current_size, 0, 95.0);
    std::cout << "\tSuccess!" << std::endl;
    std::cout << "After insertion (size = " << current_size << "): ";
    traversal_array(A);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

    // Prueba 4: Insertar al inicio (posición = 0)
  try {
    std::cout << "\nInserting 97.0 at the beginning (position 5)...";
    insertion_position<double>(A, current_size, 5, 97.0);
    std::cout << "\tSuccess!" << std::endl;
    std::cout << "After insertion (size = " << current_size << "): ";
    traversal_array(A);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  // Prueba 4: Insertar en un areglo lleno (posición = 8)
  try {
    std::cout << "\nInserting 98.0 at the beginning (position 8)...";
    insertion_position<double>(A, current_size, 8, 98.0);
    std::cout << "\tSuccess!" << std::endl;
    std::cout << "After insertion (size = " << current_size << "): ";
    traversal_array(A);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "Current size: " << current_size << std::endl;
  
  return 0;
}