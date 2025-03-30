#include "raylib.h"
#include "Bird.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Angry Birds Clone");
    SetTargetFPS(60);

    float groundY = 500;
    Bird bird({150, groundY - 30}, 15.0f, groundY);

    while (!WindowShouldClose()) {
        bird.HandleInput();
        bird.Update();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawLine(0, groundY, screenWidth, groundY, DARKGRAY);
        bird.Draw();

        DrawText("Drag and release to launch!", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
