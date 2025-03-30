#include "raylib.h"
#include "Bird.h"

int main() {
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Angry Birds Clone");
    SetTargetFPS(60);

    float groundY = 700;  // Adjust ground position for bigger screen
    Bird bird({200, groundY - 30}, 20.0f, groundY, screenWidth, screenHeight);

    while (!WindowShouldClose()) {
        bird.HandleInput();
        bird.Update();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawLine(0, groundY, screenWidth, groundY, DARKGRAY); // Draw ground
        bird.Draw();

        DrawText("Drag and release to launch!", 20, 20, 24, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
