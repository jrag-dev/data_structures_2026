/*
 * Pass-By-Reference
 * Pass-by-reference refers to passing parameters to a function by using references
 * Preview: Docs A reference variable is an alias for another object.
.* When called, the function can modify the value of the arguments by using the reference passed in.
 *
 * This allows us to:
    Modify the value of the function arguments.
    Avoid making copies of a variable/object for performance reasons.
 *
*/

#include <iostream>

void swap_num(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

int main() {
    int a = 100;
    int b = 200;

    swap_num(a, b);

    std::cout << "A is " << a << "\n";
    std::cout << "B is " << b << "\n";
}