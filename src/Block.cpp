/* #include "Block.h"
#include "Physics.h"
#include <cmath>

Block::Block(Vector2 position, float width, float height, float durability) {
    this->hitbox = { position.x, position.y, width, height };
    this->durability = durability;
    this->isDestroyed = false;
}

void Block::Update(Vector2 birdPos, Vector2 birdVelocity) {
    float impactForce = std::sqrt(birdVelocity.x * birdVelocity.x + birdVelocity.y * birdVelocity.y);

    if (CheckCollisionCircleRect(birdPos, 10, hitbox)) {
        if (impactForce > durability) {
            isDestroyed = true;
        }
    }
}

void Block::Draw() {
    if (!isDestroyed) {
        DrawRectangleRec(hitbox, BROWN);
    }
}

bool Block::IsDestroyed() const {
    return isDestroyed;
}
 */