#include "Bird.h"

Bird::Bird(Vector2 startPosition) {
    this->position = startPosition;
    this->velocity = {0, 0};
    this->isFlying = false;
}

void Bird::Launch(Vector2 launchVelocity) {
    this->velocity = launchVelocity;
    this->isFlying = true;
}

void Bird::Update(float dt) {
    if (isFlying) {
        velocity.y += 9.8f * dt;  // Gravity effect
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
    }
}

void Bird::Draw() {
    DrawCircleV(position, 10, RED);
}

bool Bird::IsFlying() const {
    return isFlying;
}
