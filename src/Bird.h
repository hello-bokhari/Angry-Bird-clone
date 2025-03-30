#ifndef BIRD_H
#define BIRD_H

#include "raylib.h"
#include "Physics.h"

class Bird {
private:
    Vector2 position;
    Vector2 initialPosition;
    Vector2 velocity;
    float radius;
    bool isLaunched;
    bool isDragging;
    float launchTime;
    float groundLevel;
    
    const float gravity = 1.0f;
    const float maxDragDistance = 75.0f;

    Vector2 slingAnchorA, slingAnchorB;

public:
    Bird(Vector2 startPos, float r, float groundY);
    void Update();
    void Draw();
    void HandleInput();
    void Launch(Vector2 initialVelocity);
    bool IsMoving() const;
    void DrawSlingshot();
};

#endif
