#include "Bird.h"
#include "raymath.h"

Bird::Bird(Vector2 startPos, float r, float groundY) {
    position = startPos;
    initialPosition = startPos;
    velocity = {0, 0};
    radius = r;
    isLaunched = false;
    isDragging = false;
    groundLevel = groundY - r;
}

void Bird::HandleInput() {
    Vector2 mousePos = GetMousePosition();

    // If mouse is clicked near the bird, start dragging
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !isLaunched) {
        float distance = Vector2Distance(mousePos, initialPosition);
        if (distance < radius * 2) {
            isDragging = true;
        }
    }

    // If dragging, move the bird within a max range
    if (isDragging) {
        Vector2 dragDirection = Vector2Subtract(mousePos, initialPosition);
        float dragDistance = Vector2Length(dragDirection);

        if (dragDistance > maxDragDistance) {
            dragDirection = Vector2Scale(Vector2Normalize(dragDirection), maxDragDistance);
        }

        position = Vector2Add(initialPosition, dragDirection);
    }

    // When the mouse is released, launch the bird
    if (isDragging && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 launchVelocity = Vector2Scale(Vector2Subtract(initialPosition, position), 0.2f); // Adjust speed multiplier
        Launch(launchVelocity);
        isDragging = false;
    }
}

void Bird::Launch(Vector2 initialVelocity) {
    velocity = initialVelocity;
    isLaunched = true;
}

void Bird::Update() {
    if (isLaunched) {
        velocity.y += gravity;
        position.x += velocity.x;
        position.y += velocity.y;

        if (position.y >= groundLevel) {
            position.y = groundLevel;
            velocity.y *= -bounceFactor;

            if (velocity.y < 1.0f && velocity.y > -1.0f) {
                velocity.y = 0;
            }

            if (velocity.y == 0) {
                velocity.x *= (1.0f - groundFriction);
                if (velocity.x < 0.1f && velocity.x > -0.1f) {
                    velocity.x = 0;
                }
            }
        }
    }
}

void Bird::Draw() {
    DrawCircleV(position, radius, RED);
    if (isDragging) {
        DrawLineEx(position, initialPosition, 3, BLACK); // Slingshot line
    }
    DrawText(TextFormat("Velocity: (%.2f, %.2f)", velocity.x, velocity.y), 10, 40, 20, BLUE); // to see velocity in real time
}

bool Bird::IsMoving() const {
    return isLaunched && (velocity.x != 0 || velocity.y != 0);
}