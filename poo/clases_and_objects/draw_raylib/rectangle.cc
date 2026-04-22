#include "rectangle.h"
#include "raylib.h"

RectangleCreator::RectangleCreator(int x, int y, int w, int h, Color c) : x_cord(x), y_cord(y), width(w), height(h), color(c) {}
        
void RectangleCreator::draw() const {        
    DrawRectangle(x_cord, y_cord, width, height, color);
}