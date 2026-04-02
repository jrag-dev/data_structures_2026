
/*-----------------------------------------------------------------------*\
 * 04_busqueda_linear.cpp
 * Propósito: Encontrar la primera ocurrencia de un valor en el arreglo.
 * Complejidad: O(n)
 * Jose Alvarado
 * 30-03-2026
 *-----------------------------------------------------------------------*\
*/

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <class T, size_t N>
T get_element(const T (&arr)[N], size_t index) {
  if (index >= N) {
    throw std::out_of_range("Indice fuera de rango.");
  }
  return arr[index];
}

template <class T, size_t N>
ptrdiff_t search_linear(const T (&B)[N], T value_search) {
  for (size_t i = 0; i < N; i++) {
    if (B[i] == value_search) {
      return static_cast<ptrdiff_t>(i);
    }
  }
  return -1;
}

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


int main(int argc, char *argv[])
{
  double A[10] = {1.0, 2.0, 4.0, 5.0, 7.0, 9.0, 12.0, 15.0, 21.0, 25.0};

  std::cout << "\nTraversal array: ";
  traversal_array(A);

  try {
    const size_t index1 = 5;
    double value_in_index = get_element(A, index1);
    std::cout << "\nIndex: " << index1 << "\nValue: " << value_in_index << std::endl;
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  const double v_to_search = 21.0;
  size_t value_found = search_linear(A, v_to_search);

  std::string result = (value_found != -1) 
    ? "Value: " + std::to_string(v_to_search) + " found in index: " + std::to_string(value_found) + " \n" 
    : "Value: " + std::to_string(v_to_search) + " Not Found\n" ;

  std::cout << result << std::endl;
  std::cout << "\nTraversal array: ";
  traversal_array(A);

  return 0;
}
