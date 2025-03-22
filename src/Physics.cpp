#include "Physics.h"

Vector2 Physics::ApplyGravity(Vector2 velocity, float gravity, float deltaTime) {
    velocity.y += gravity * deltaTime; 
    return velocity;
}

Vector2 Physics::ApplyDrag(Vector2 velocity, float dragFactor) {
    velocity.x *= dragFactor;
    velocity.y *= dragFactor;
    return velocity;
}
// Circle-Rectangle Collision (Bird vs Blocks/Pigs)
bool CheckCollisionCircleRect(Vector2 circlePos, float radius, Rectangle rect) {
    float closestX = fmaxf(rect.x, fminf(circlePos.x, rect.x + rect.width));
    float closestY = fmaxf(rect.y, fminf(circlePos.y, rect.y + rect.height));

    float distanceX = circlePos.x - closestX;
    float distanceY = circlePos.y - closestY;

    return (distanceX * distanceX + distanceY * distanceY) <= (radius * radius);
}