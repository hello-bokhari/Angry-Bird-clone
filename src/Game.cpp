/* #include "raylib.h"
#include "Level.h"
#include "Bird.h"
#include "UI.h"
#include <vector>

int main() {
    InitWindow(800, 600, "Angry Birds Clone");

    // Define multiple levels
    std::vector<Level> levels = {
        Level({200, 300}, 
              {Pig({500, 350}), Pig({600, 350})}, 
              {Block({550, 400}, 60, 30, 5.0f)}
        ),
        Level({150, 300}, 
              {Pig({550, 350}), Pig({700, 350}), Pig({750, 350})}, 
              {Block({600, 400}, 60, 30, 5.0f), Block({650, 400}, 60, 30, 5.0f)}
        )
    };

    int currentLevel = 0;
    Bird bird(levels[currentLevel].slingshot.GetPosition());
    UI ui;
    bool gameWon = false;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        if (!bird.IsFlying()) {
            levels[currentLevel].slingshot.Update(GetMousePosition());

            if (!IsMouseButtonDown(MOUSE_LEFT_BUTTON) && levels[currentLevel].slingshot.IsAiming()) {
                bird.Launch(levels[currentLevel].slingshot.GetLaunchVelocity());
            }
        }

        bird.Update(deltaTime);

        // Update pigs and blocks for the current level
        for (auto &pig : levels[currentLevel].pigs) {
            pig.Update(bird.GetPosition());
        }

        for (auto &block : levels[currentLevel].blocks) {
            block.Update(bird.GetPosition(), bird.GetVelocity());
        }

        // Check if all pigs are destroyed
        bool allPigsDestroyed = true;
        for (const auto &pig : levels[currentLevel].pigs) {
            if (!pig.IsDestroyed()) {
                allPigsDestroyed = false;
                break;
            }
        }

        if (allPigsDestroyed && !gameWon) {
            ui.IncreaseScore(300);
            gameWon = true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        levels[currentLevel].Draw();
        bird.Draw();
        ui.Draw();

        if (gameWon) {
            DrawText("You Win! Press SPACE for next level", 200, 250, 20, GREEN);
            if (IsKeyPressed(KEY_SPACE) && currentLevel + 1 < levels.size()) {
                currentLevel++;
                bird.Reset(levels[currentLevel].slingshot.GetPosition());
                gameWon = false;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
 */