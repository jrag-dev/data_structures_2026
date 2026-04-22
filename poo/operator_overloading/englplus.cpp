// englplus.cpp
// overloaded '+' operator adds two Distances

#include <iostream>


class Distance {
    private:
        int feet;
        float inches;
    public:
        Distance() : feet(0), inches(0.0) {}
        Distance(int ft, float in) : feet(ft), inches(in) {}

        void get_distance() {
            std::cout << "\nEnter feet: "; std::cin >> feet;
            std::cout << "\nEnter inches: "; std::cin >> inches;
        }
        void show_distance() const {
            std::cout << feet << "\'-" << inches << '\"' << std::endl;
        }

        Distance operator + (Distance) const;
};

int main () {


    return 0;
}