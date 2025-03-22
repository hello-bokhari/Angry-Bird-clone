#ifndef PHYSICS_H
#define PHYSICS_H

#include "raylib.h"

struct Physics {
    static Vector2 ApplyGravity(Vector2 velocity, float gravity, float deltaTime);
    static Vector2 ApplyDrag(Vector2 velocity, float dragFactor);
};

bool CheckCollisionCircleRect(Vector2 circlePos, float radius, Rectangle rect);
#endif
