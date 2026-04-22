// engconst.cpp
// const member functions and const arguments to member functions
#include <iostream>


class Distance {
    private:
        int feet;
        float inches;
    public:
        Distance() : feet(0), inches(0) {}
        Distance(int ft, float in) : feet(ft), inches(in) {}
        
        ~Distance() {}

        void getDistance() {
            std::cout << "\n\033[35mEnter feet: "; std::cin >> feet;
            std::cout << "\n\033[35mEnter inches: "; std::cin >> inches;
        }
        void showDistance() const {
            std::cout << "\n\033[31mFeet: " << feet << "\'-" << " Inches: " << inches << '\"' << std::endl;
        }

        Distance addDistance(const Distance&) const;
};

Distance Distance::addDistance(const Distance& d2) const {
    Distance temp;

    temp.inches = inches + d2.inches;
    if (temp.inches >= 12.0) {
        temp.inches -= 12.0;
        temp.feet = 1;
    }
    temp.feet += feet + d2.feet;
    return temp;
}

int main() {
    Distance d1, d3;
    Distance d2(11, 6.25);

    d1.getDistance();
    d3 = d1.addDistance(d2);

    std::cout << "\n\033[33mDistance 1 = "; d1.showDistance();
    std::cout << "\n\033[34mDistance 2 = "; d2.showDistance();
    std::cout << "\n\033[35mDistance 3 = "; d3.showDistance();

    return 0;
}