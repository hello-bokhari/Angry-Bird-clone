#include "Bird.h"

Bird::Bird(Vector2 startPos, float r, float groundY) {
    position = startPos;
    velocity = {0, 0};
    radius = r;
    isLaunched = false;
    groundLevel = groundY - r; // Adjust ground level for bird's radius
}

void Bird::Launch(Vector2 initialVelocity) {
    velocity = initialVelocity;
    isLaunched = true;
}

void Bird::Update() {
    if (isLaunched) {
        // Apply gravity
        velocity.y += gravity;
        position.x += velocity.x;
        position.y += velocity.y;

        // Ground Collision & Bouncing
        if (position.y >= groundLevel) {
            position.y = groundLevel; // Keep bird on the ground
            velocity.y *= -bounceFactor; // Reverse Y velocity (bounce)

            // Stop bouncing if too small
            if (velocity.y < 1.0f && velocity.y > -1.0f) {
                velocity.y = 0;
            }

            // Apply friction when on the ground
            if (velocity.y == 0) {
                velocity.x *= (1.0f - groundFriction);
                if (velocity.x < 0.1f && velocity.x > -0.1f) {
                    velocity.x = 0; // Stop completely if very slow
                }
            }
        }
    }
}

void Bird::Draw() {
    DrawCircleV(position, radius, RED);
}

bool Bird::IsMoving() const {
    return isLaunched && (velocity.x != 0 || velocity.y != 0);
}