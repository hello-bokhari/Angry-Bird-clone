#ifndef PHYSICS_H
#define PHYSICS_H

#include "raylib.h"

class Physics {
public:
    static Vector2 ComputePosition(Vector2 initialPos, Vector2 initialVel, float time, float gravity);
    static Vector2 ComputeVelocity(Vector2 initialVel, float time, float gravity);
};

#endif
