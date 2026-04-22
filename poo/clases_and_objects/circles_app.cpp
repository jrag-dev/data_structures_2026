///////////////////////////////////////////////
// circles.cpp
// circles as graphics objects
///////////////////////////////////////////////

#include "raylib.h"

class Circle {
    protected:
        int x_cord, y_cord;
        float radius;
        Color color;
    
    public:
        Circle(int x, int y, float r, Color c) 
            : x_cord(x), y_cord(y), radius(r), color(c) {}
        void draw() {
            DrawCircle(x_cord, y_cord, radius, color);
        }

};


int main() {
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Drawing with Raylib and Clases");

    Circle c1(screenWidth/5, screenHeight/10, 20, DARKBLUE);


    float rotation = 0.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        rotation += 0.2f;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        c1.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}