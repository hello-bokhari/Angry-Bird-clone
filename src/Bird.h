#ifndef BIRD_H
#define BIRD_H

#include "raylib.h"
#include "Physics.h"

class Bird {
protected:
    Vector2 position;
    Vector2 initialPosition;
    Vector2 velocity;
    float radius;
    bool isLaunched;
    bool isDragging;

   // Physics parameters (Tuned for realism)
    const float gravity = 0.5f;        // Stronger gravity for natural arc
    const float bounceFactor = 0.4f;   // Less bounce for better realism
    const float groundFriction = 0.08f; // More friction for quicker stop
    const float airResistance = 0.01f; // Less air resistance for smoother flight
    const float maxDragDistance = 75.0f; // Reduce max pullback distance

    
    float groundLevel;
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
