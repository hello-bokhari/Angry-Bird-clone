#include "Bird.h"
#include "raymath.h"

// Constructor: Initializes bird properties
Bird::Bird(Vector2 startPos, float r, float groundY) {
    // Initial positions
    initialPosition = startPos;
    position = startPos;

    // Zero initial velocity
    velocity = {0, 0};

    // Bird size
    radius = r;

    // Flags
    isLaunched = false;
    isDragging = false;

    // Ground level correction
    groundLevel = groundY - r;

    // Launch time initialization
    launchTime = 0;

    // Define slingshot anchor points
    slingAnchorA = {startPos.x - 15, groundY - 50};
    slingAnchorB = {startPos.x + 15, groundY - 50};
}

// Handles user input for dragging and launching the bird
void Bird::HandleInput() {
    Vector2 mousePos = GetMousePosition(); // Get current mouse position

    // Start dragging if the mouse is close enough to the bird and it's not launched
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !isLaunched) {
        float distance = Vector2Distance(mousePos, initialPosition);
        if (distance < radius * 2) { // Allow drag if within reach
            isDragging = true;
        }
    }

    // If dragging, update the bird's position relative to the mouse
    if (isDragging) {
        Vector2 dragVector = Vector2Subtract(mousePos, initialPosition);
        float dragDistance = Vector2Length(dragVector);

        // Limit drag distance to prevent unrealistic stretching
        if (dragDistance > maxDragDistance) {
            dragVector = Vector2Scale(Vector2Normalize(dragVector), maxDragDistance);
        }

        position = Vector2Add(initialPosition, dragVector);
    }

    // If mouse is released, launch the bird
    if (isDragging && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        // Calculate launch velocity (increase scale factor to make it faster)
        Vector2 launchVelocity = Vector2Scale(Vector2Subtract(initialPosition, position), 5.0f);

        // **Reset position to the slingshot before launch**
        position = initialPosition;
        
        // Launch with computed velocity
        Launch(launchVelocity);
        isDragging = false;
    }
}

// Launches the bird with an initial velocity
void Bird::Launch(Vector2 initialVelocity) {
    velocity = initialVelocity; // Set velocity
    isLaunched = true;          // Mark as launched
    launchTime = GetTime();     // Record launch time
}

// Updates the bird's motion based on physics
void Bird::Update() {
    if (isLaunched) {
        float t = GetTime() - launchTime; // Elapsed time

        // **Apply projectile motion equations**
        position = Physics::ComputePosition(initialPosition, velocity, t, gravity);
        velocity = Physics::ComputeVelocity(velocity, t, gravity);

        // **Stop movement if the bird hits the ground**
        if (position.y >= groundLevel) {
            position.y = groundLevel;
            isLaunched = false; // Stop movement
        }
    }
}

// Draws the bird and UI elements
void Bird::Draw() {
    DrawSlingshot(); // Draw slingshot base

    // Draw slingshot bands if dragging
    if (isDragging) {
        DrawLineEx(position, slingAnchorA, 5, DARKBROWN);
        DrawLineEx(position, slingAnchorB, 5, DARKBROWN);
    }

    // Draw the bird
    DrawCircleV(position, radius, RED);

    // Display velocity for debugging
    DrawText(TextFormat("Velocity: (%.2f, %.2f)", velocity.x, velocity.y), 10, 40, 20, BLUE);
}

// Draws the slingshot structure
void Bird::DrawSlingshot() {
    DrawLineEx(slingAnchorA, initialPosition, 8, BROWN);
    DrawLineEx(slingAnchorB, initialPosition, 8, BROWN);
    DrawCircleV(slingAnchorA, 6, DARKBROWN);
    DrawCircleV(slingAnchorB, 6, DARKBROWN);
}

// Checks if the bird is still moving
bool Bird::IsMoving() const {
    return isLaunched && (velocity.x != 0 || velocity.y != 0);
}
