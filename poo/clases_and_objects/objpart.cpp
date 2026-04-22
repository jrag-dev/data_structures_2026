// objpart.cpp
// Widget part as an object
#include <iostream>


class Part {
    private:
        int model_number;
        int part_number;
        float cost;
    
    public:
        void set_part(int mn, int pn, float c) {
            this->model_number = mn;
            this->part_number = pn;
            this->cost = c;
        }
        void show_part() {
            std::cout << "Model " << this->model_number;
            std::cout << ", part " << this->part_number;
            std::cout << ", costs $ " << this->cost << std::endl;
        }
};


int main() {
    Part part1;

    part1.set_part(6244, 373, 217.55F);
    part1.show_part();

    return 0;
}