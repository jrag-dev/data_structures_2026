/*
 * Definir un arreglo en c++
 *
 * Jose Alvarado
 * 30-03-2026
*/


#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  // declaring and initialization an array of size 5
  int arr[5] = {2, 4, 8, 12, 16};

  // calculate the array size
  int l = sizeof(arr)/sizeof(arr[0]);

  cout << "\nl: " << l << endl;

  // printing array elements
  for (size_t i = 0; i < l; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  return 0;
}
