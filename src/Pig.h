#ifndef PIG_H
#define PIG_H

#include "raylib.h"

class Pig {
private:
    Rectangle hitbox;
    bool isDestroyed;

public:
    Pig(Vector2 position);
    void Update(Vector2 birdPos);
    void Draw();
    bool IsDestroyed() const;
};

#endif
