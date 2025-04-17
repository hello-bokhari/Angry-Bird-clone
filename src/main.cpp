#include "raylib.h"

int main() {
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Angry Birds Clone");
    SetTargetFPS(60);

    float groundY = 700;  // Adjust ground position for bigger screen

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawLine(0, groundY, screenWidth, groundY, DARKGRAY); // Draw ground

        DrawText("Drag and release to launch!", 20, 20, 24, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
