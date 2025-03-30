/* #include "Pig.h"
#include "Physics.h"

Pig::Pig(Vector2 position) {
    this->hitbox = { position.x, position.y, 30, 30 };
    this->isDestroyed = false;
}

void Pig::Update(Vector2 birdPos) {
    if (CheckCollisionCircleRect(birdPos, 10, hitbox)) {
        isDestroyed = true;
    }
}

void Pig::Draw() {
    if (!isDestroyed) {
        DrawRectangleRec(hitbox, GREEN);
    }
}

bool Pig::IsDestroyed() const {
    return isDestroyed;
}
 */