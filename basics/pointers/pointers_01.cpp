/*
 * A computer’s memory is a sequence of bytes. We can number the bytes from 0 to the last one. 
 * Each number, known as an address, represents a location in the memory.
*/

#include <iostream>


int main()
{
    int songqiao = 999;
    int &sonny = songqiao;
    int* sonnyp = &songqiao;

    std::cout << "\nSongqiao -> " << " Address: " << &songqiao << "\tValue: " << songqiao << std::endl;
    std::cout << "\nSonny -> " << " Address: " << &sonny << "\tValue: " << sonny << std::endl;
    std::cout << "\nSonnyp -> " << " Address: " << &sonnyp << "\tPointer to: " << sonnyp << "\tValue: " << *sonnyp << std::endl;

    songqiao += 1;

    std::cout << "\nSongqiao -> " << " Address: " << &songqiao << "\tValue: " << songqiao << std::endl;
    std::cout << "\nSonny -> " << " Address: " << &sonny << "\tValue: " << sonny << std::endl;
    std::cout << "\nSonnyp -> " << " Address: " << &sonnyp << "\tPointer to: " << sonnyp << "\tValue: " << *sonnyp << std::endl;

    return 0;
}