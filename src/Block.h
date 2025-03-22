#ifndef BLOCK_H
#define BLOCK_H

#include "raylib.h"

class Block {
private:
    Rectangle hitbox;
    float durability;  // Block strength
    bool isDestroyed;

public:
    Block(Vector2 position, float width, float height, float durability);
    void Update(Vector2 birdPos, Vector2 birdVelocity);
    void Draw();
    bool IsDestroyed() const;
};

#endif
