// staticdata.cpp
// static class data
#include <iostream>


class Foo {
    private:
        static int count;

    public:
        Foo() {
            count++;
        }
        int getCount() {
            return count;
        }
};

int Foo::count = 0;

int main() {
    Foo f1, f2;

    std::cout << "\nCount is " << f1.getCount() << std::endl;
    std::cout << "\nCount is " << f2.getCount() << std::endl;

    Foo f3;

    std::cout << "\nCount is " << f3.getCount() << std::endl;
}