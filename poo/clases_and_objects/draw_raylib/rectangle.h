#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "raylib.h"

class RectangleCreator {
    protected:
        int x_cord, y_cord;
        int width, height;
        Color color;
      
    public:
    RectangleCreator(int x_cord, int y_cord, int width, int height, Color color);
        
        void draw() const;

};

#endif