#ifndef BIRD_H
#define BIRD_H

#include "raylib.h"

class Bird {
private:
    Vector2 position;
    Vector2 velocity;
    bool isFlying;

public:
    Bird(Vector2 startPosition);
    void Launch(Vector2 launchVelocity);
    void Update(float dt);
    void Draw();
    bool IsFlying() const;
};

#endif
