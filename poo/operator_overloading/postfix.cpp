// postfix.cpp
// overloaded ++ operator in both prefix and postfix
#include <iostream>


class Counter {
    private:
        unsigned int count;
    public:
        Counter() : count(0) {}
        Counter(int n) : count(n) {}

        ~Counter() {}

        unsigned int get_count() const {
            return count;
        }
        Counter operator ++ () {
            ++count;
            return Counter(count);
        }
        Counter operator ++ (int) {
            return Counter(count++);
        }
        Counter operator -- () {
            --count;
            return Counter(count);
        }
        Counter operator -- (int) {
            return Counter(count--);
        }
};

int main() {
    Counter c1;
    Counter c2(5);

    std::cout << "\n\033[35mCount for c1: " << c1.get_count() << std::endl;
    std::cout << "\n\033[35mCount for c2: " << c2.get_count() << std::endl;

    ++c2;
    ++c2;
    c1 = c2++;

    std::cout << "\n\033[35mCount for c1: " << c1.get_count() << std::endl;
    std::cout << "\n\033[35mCount for c2: " << c2.get_count() << std::endl;

    --c1;
    --c1;
    --c1;
    --c2;

    std::cout << "\n\033[35mCount for c1: " << c1.get_count() << std::endl;
    std::cout << "\n\033[35mCount for c2: " << c2.get_count() << std::endl;

    c1--;
    c2--;

    std::cout << "\n\033[35mCount for c1: " << c1.get_count() << std::endl;
    std::cout << "\n\033[35mCount for c2: " << c2.get_count() << std::endl;


    return 0;
}