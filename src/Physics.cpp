#include "Physics.h"


void Physics::ApplyGravity(Vector2 &velocity, float gravity) {
    velocity.y += gravity;
}

void Physics::ApplyAirResistance(Vector2 &velocity, float airResistance) {
    velocity.x *= (1.0f - airResistance);
    velocity.y *= (1.0f - airResistance);
}

void Physics::ApplyGroundCollision(Vector2 &position, Vector2 &velocity, float groundLevel, float bounceFactor) {
    if (position.y >= groundLevel) {
        position.y = groundLevel;
        velocity.y *= -bounceFactor;

        if (fabs(velocity.y) < 1.5f) { 
            velocity.y = 0; 
        }
    }
}

void Physics::ApplyFriction(Vector2 &velocity, float groundFriction) {
    if (velocity.y == 0) {
        velocity.x *= (1.0f - groundFriction);
        if (fabs(velocity.x) < 0.1f) {
            velocity.x = 0;
        }
    }
}
