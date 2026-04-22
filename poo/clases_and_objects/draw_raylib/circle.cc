#include "circle.h"
#include <raylib.h>
#include <iostream>

Circle::Circle(int x, int y, float r, Color c) : x_cord(x), y_cord(y), radius(r), color(c) {}

Circle::~Circle() {
    std::cout << "\nObject Destroyet" << std::endl;
}

void Circle::draw() const {
    DrawCircle(x_cord, y_cord, radius, color);
}