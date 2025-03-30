#include "Bird.h"
#include "raymath.h"

Bird::Bird(Vector2 startPos, float r, float groundY) {
    initialPosition = startPos;
    position = startPos;
    velocity = {0, 0};
    radius = r;
    isLaunched = false;
    isDragging = false;
    groundLevel = groundY - r;

    slingAnchorA = {startPos.x - 15, groundY - 50};
    slingAnchorB = {startPos.x + 15, groundY - 50};
}

void Bird::HandleInput() {
    Vector2 mousePos = GetMousePosition();

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !isLaunched) {
        float distance = Vector2Distance(mousePos, initialPosition);
        if (distance < radius * 2) {
            isDragging = true;
        }
    }

    if (isDragging) {
        Vector2 dragVector = Vector2Subtract(mousePos, initialPosition);
        float dragDistance = Vector2Length(dragVector);

        if (dragDistance > maxDragDistance) {
            dragVector = Vector2Scale(Vector2Normalize(dragVector), maxDragDistance);
        }

        position = Vector2Add(initialPosition, dragVector);
    }

    if (isDragging && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 launchVelocity = Vector2Scale(Vector2Subtract(initialPosition, position), 0.35f);
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
        Physics::ApplyGravity(velocity, gravity);
        Physics::ApplyAirResistance(velocity, airResistance);

        position.x += velocity.x;
        position.y += velocity.y;

        Physics::ApplyGroundCollision(position, velocity, groundLevel, bounceFactor);
        Physics::ApplyFriction(velocity, groundFriction);
    }
}

void Bird::Draw() {
    DrawSlingshot();

    if (isDragging) {
        DrawLineEx(position, slingAnchorA, 5, DARKBROWN);
        DrawLineEx(position, slingAnchorB, 5, DARKBROWN);
    }

    DrawCircleV(position, radius, RED);
    DrawText(TextFormat("Velocity: (%.2f, %.2f)", velocity.x, velocity.y), 10, 40, 20, BLUE);
}

void Bird::DrawSlingshot() {
    DrawLineEx(slingAnchorA, initialPosition, 8, BROWN);
    DrawLineEx(slingAnchorB, initialPosition, 8, BROWN);
    DrawCircleV(slingAnchorA, 6, DARKBROWN);
    DrawCircleV(slingAnchorB, 6, DARKBROWN);
}

bool Bird::IsMoving() const {
    return isLaunched && (velocity.x != 0 || velocity.y != 0);
}
