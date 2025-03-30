#include "Physics.h"

Vector2 Physics::ComputePosition(Vector2 currentPos, Vector2 velocity, float time, float gravity) {
    return {
        currentPos.x + velocity.x * time, 
        currentPos.y + velocity.y * time + 0.5f * gravity * time * time
    };
}

Vector2 Physics::ComputeVelocity(Vector2 initialVel, float time, float gravity) {
    return { 
        initialVel.x, 
        initialVel.y + gravity * time 
    };
}
