#include "Bird.h"
#include "raymath.h"

// Constructor: Initializes bird properties and screen size
Bird::Bird(Vector2 startPos, float r, float groundY, int screenW, int screenH) {
    initialPosition = startPos; 
    position = startPos;       
    velocity = {0, 0};         
    radius = r;                
    isLaunched = false;        
    isDragging = false;        
    groundLevel = groundY - r;
    
    screenWidth = screenW;
    screenHeight = screenH;

    // Slingshot anchor points
    slingAnchorA = {startPos.x - 15, groundY - 50};
    slingAnchorB = {startPos.x + 15, groundY - 50};
}

// Handles user input for dragging and launching the bird
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
        Vector2 launchVelocity = Vector2Scale(Vector2Subtract(initialPosition, position), launchMultiplier);

        // Cap velocity to prevent excessive launch power
        float maxSpeed = 900.0f;
        if (Vector2Length(launchVelocity) > maxSpeed) {
            launchVelocity = Vector2Scale(Vector2Normalize(launchVelocity), maxSpeed);
        }

        position = initialPosition;
        Launch(launchVelocity);
        isDragging = false;
    }
}

// Launches the bird with an initial velocity
void Bird::Launch(Vector2 initialVelocity) {
    velocity = initialVelocity;
    isLaunched = true;
}

// Updates the bird's physics
void Bird::Update() {
    if (isLaunched) {
        float dt = GetFrameTime();

        // Apply gravity
        velocity.y += gravity * dt;

        // Update position
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;

        // Bounce off ground
        if (position.y >= groundLevel && velocity.y > 0) {
            position.y = groundLevel;
            velocity.y *= -bounceDamping;  
            velocity.x *= friction;        

            if (fabs(velocity.y) < 2.0f) {
                velocity.y = 0;
                velocity.x = 0;
                isLaunched = false;
            }
        }

        // Bounce off left wall
        if (position.x - radius <= 0 && velocity.x < 0) {
            position.x = radius;  
            velocity.x *= -wallBounceDamping;  
        }

        // Bounce off right wall
        if (position.x + radius >= screenWidth && velocity.x > 0) {
            position.x = screenWidth - radius;
            velocity.x *= -wallBounceDamping;
        }

        // Bounce off ceiling
        if (position.y - radius <= 0 && velocity.y < 0) {
            position.y = radius;
            velocity.y *= -wallBounceDamping;  
        }
    }
}

// Draws the bird and UI elements
void Bird::Draw() {
    DrawSlingshot();

    if (isDragging) {
        DrawLineEx(position, slingAnchorA, 5, DARKBROWN);
        DrawLineEx(position, slingAnchorB, 5, DARKBROWN);
    }

    DrawCircleV(position, radius, RED);
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
