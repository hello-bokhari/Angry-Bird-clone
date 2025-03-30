#ifndef BIRD_H
#define BIRD_H

#include "raylib.h"

class Bird {
private:
    Vector2 position;
    Vector2 initialPosition;
    Vector2 velocity;
    float radius;
    bool isLaunched;
    bool isDragging;
    float groundLevel;

    const float gravity = 9.8f;   
    const float maxDragDistance = 100.0f;
    const float launchMultiplier = 6.0f;
    const float bounceDamping = 0.2f;  
    const float friction = 0.98f;      
    const float wallBounceDamping = 0.8f;  // Energy lost when bouncing off walls/ceiling

    Vector2 slingAnchorA, slingAnchorB;
    int screenWidth, screenHeight;

public:
    Bird(Vector2 startPos, float r, float groundY, int screenW, int screenH);
    void Update();
    void Draw();
    void HandleInput();
    void Launch(Vector2 initialVelocity);
    bool IsMoving() const;
    void DrawSlingshot();
};

#endif
