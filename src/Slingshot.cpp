#include "Slingshot.h"
#include <math.h>


Slingshot::Slingshot(Vector2 anchor, float maxStretch) {
    this->anchorPoint = anchor;
    this->stretchedPosition = anchor;
    this->maxStretch = maxStretch;
    this->isAiming = false;
}

void Slingshot::Update(Vector2 mousePosition) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        isAiming = true;
        Vector2 direction = {mousePosition.x - anchorPoint.x, mousePosition.y - anchorPoint.y};
        float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance > maxStretch) {
            float scale = maxStretch / distance;
            stretchedPosition.x = anchorPoint.x + direction.x * scale;
            stretchedPosition.y = anchorPoint.y + direction.y * scale;
        } else {
            stretchedPosition = mousePosition;
        }
    } else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && isAiming) {
        isAiming = false;
    }
}

void Slingshot::Draw() {
    DrawLineV(anchorPoint, stretchedPosition, DARKGRAY);
    DrawCircleV(anchorPoint, 5, BLACK);
    DrawCircleV(stretchedPosition, 8, BLUE);
}

Vector2 Slingshot::GetLaunchVelocity() {
    return {anchorPoint.x - stretchedPosition.x, anchorPoint.y - stretchedPosition.y};
}

bool Slingshot::IsAiming() const {
    return isAiming;
}
