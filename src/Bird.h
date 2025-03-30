#ifndef BIRD_H
#define BIRD_H


#include "raylib.h"

class Bird {
protected:
    Vector2 position;
    Vector2 initialPosition; // Original position before launch
    Vector2 velocity;
    float radius;
    bool isLaunched;
    bool isDragging; // To track if the bird is being dragged

    const float gravity = 0.3f;
    const float bounceFactor = 0.8f;
    const float groundFriction = 0.05f;

    float groundLevel;
    float maxDragDistance = 75.0f; // Max distance to pull back the slingshot

public:
    Bird(Vector2 startPos, float r, float groundY);

    void Update();
    void Draw();
    bool IsMoving() const;
    void HandleInput(); // Handles dragging and releasing
    void Launch(Vector2 initialVelocity);

    Vector2 GetPosition() const { return position; }
};

#endif
