///////////////////////////////////////////////
// circles.cpp
// circles as graphics objects
///////////////////////////////////////////////

#include "circle.h"
#include "raylib.h"
#include "rectangle.h"


int main() {
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Drawing with Raylib and Clases");

    Circle c1(screenWidth/2, screenHeight/2, 50, DARKBLUE);
    RectangleCreator r1(screenWidth/2, screenHeight/2, 150, 200, DARKPURPLE);


    float rotation = 0.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        rotation += 0.2f;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        c1.draw();
        r1.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}