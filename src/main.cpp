#include "raylib.h"
#include "Bird.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Angry Birds Clone");
    SetTargetFPS(60);

    float groundY = 500; // Position of the ground
    Bird bird({100, groundY - 15}, 15.0f, groundY); // Bird starts above ground

    while (!WindowShouldClose()) {
        // Launch the bird when the player clicks
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            bird.Launch({5.0f, -8.0f}); // Launch with velocity
        }

        bird.Update();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawLine(0, groundY, screenWidth, groundY, DARKGRAY); // Draw ground
        bird.Draw();

        DrawText("Click to launch the bird!", 10, 10, 20, DARKGRAY);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
