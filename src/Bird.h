#ifndef BIRD_H
#define BIRD_H

#include "raylib.h"

class Bird {
    protected:
        Vector2 position;
        Vector2 velocity;
        float radius;
        bool isLaunched;
    
        const float gravity = 0.3f;      // Gravity acceleration
        const float bounceFactor = 0.5f; // Energy loss on bounce (0.5 means 50% velocity retained)
        const float groundFriction = 0.05f; // Slow down rolling bird
    
        float groundLevel; // Y position of the ground
    
    public:
        Bird(Vector2 startPos, float r, float groundY);
        
        void Launch(Vector2 initialVelocity);
        void Update();
        void Draw();
        bool IsMoving() const;
    
        Vector2 GetPosition() const { return position; }
    };
    
    #endif
