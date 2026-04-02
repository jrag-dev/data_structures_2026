/*
 * 03_acceder_por_indice.cpp
 *
 * Propósito: Obtener o modificar el valor en una posición específica.
 *
 * Complejidad: O(1)
 *
 * Jose Alvarado
 * 30-03-2026
*/

#include <iostream>
#include <stdexcept>
using namespace std;


template <class T, size_t N>
T get_element(const T (&arr)[N], size_t index) {
  if (index < 0 || index >= N) {
    throw std::runtime_error("Indice fuera de rango.");
  }
  return arr[index];
}

template <class T, size_t N>
bool set_element_in_pos(T (&arr)[N], const size_t index, T new_value) {
  if (index < 0 || index >= N) {
    throw std::runtime_error("Indice fuera de rango.");
  }
  arr[index] = new_value;
  return true;
}

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


int main(int argc, char *argv[])
{
  double A[10] = {1.0, 2.0, 4.0, 5.0, 7.0, 9.0, 12.0, 15.0, 21.0, 25.0};

  // traversal initial
  traversal_array(A);

  try {
    const size_t index1 = 5;
    double value_in_index = get_element(A, index1);
    cout << "\nIndex: " << index1 << "\nValue: " << value_in_index << endl;
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << endl;
  }

  
  try {
    const size_t index2 = 5;
    bool is_set = set_element_in_pos(A, index2, 0.0);
    string result = (is_set == true) ? "successfull" : "failed";
    cout << result << endl;
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << endl;
  }

  traversal_array(A);

  try {
    const size_t index3 = 10;
    double value_in_index = get_element(A, index3);
    cout << "\nIndex: " << index3 << "\nValue: " << value_in_index << endl;
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
