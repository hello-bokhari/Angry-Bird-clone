#include "Physics.h"

Vector2 Physics::ComputePosition(Vector2 initialPos, Vector2 initialVel, float time, float gravity) {
    return {
        initialPos.x + initialVel.x * time, 
        initialPos.y + initialVel.y * time + 0.5f * gravity * time * time
    };
}

Vector2 Physics::ComputeVelocity(Vector2 initialVel, float time, float gravity) {
    return { 
        initialVel.x, 
        initialVel.y + gravity * time 
    };
}
