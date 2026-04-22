#ifndef CIRCLE_H
#define CIRCLE_H

#include "raylib.h"

class Circle {
    private:
        int x_cord, y_cord;
        float radius;
        Color color;
    
    public:
        Circle(int x, int y, float r, Color c);
        ~Circle();
        void draw() const;
};

#endif