#ifndef SLINGSHOT_H
#define SLINGSHOT_H

#include "raylib.h"

class Slingshot {
private:
    Vector2 anchorPoint;
    Vector2 stretchedPosition;
    float maxStretch; // Maximum stretch distance
    bool isAiming;

public:
    Slingshot(Vector2 anchor, float maxStretch);
    void Update(Vector2 mousePosition);
    void Draw();
    Vector2 GetLaunchVelocity();
    bool IsAiming() const;
};

#endif
