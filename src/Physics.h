#ifndef PHYSICS_H
#define PHYSICS_H

#include "raylib.h"
#include <math.h>

class Physics {
public:
    static void ApplyGravity(Vector2 &velocity, float gravity);
    static void ApplyAirResistance(Vector2 &velocity, float airResistance);
    static void ApplyGroundCollision(Vector2 &position, Vector2 &velocity, float groundLevel, float bounceFactor);
    static void ApplyFriction(Vector2 &velocity, float groundFriction);
};

#endif
