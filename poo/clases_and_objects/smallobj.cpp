// smallobj.cpp
// demostrates a small, simple object
#include <iostream>


class SmallObj
{
    private:
        int somedata;
    
    public:
        void set_data(int d) {
            somedata = d;
        }
        void show_data() {
            std::cout << "Data is " << somedata << std::endl;
        }
};


int main() {
    SmallObj s1, s2;

    s1.set_data(1066);
    s2.set_data(1778);

    s1.show_data();
    s2.show_data();

    return 0;
}