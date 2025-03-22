#ifndef UI_H
#define UI_H

#include "raylib.h"

class UI {
private:
    int score;

public:
    UI();
    void IncreaseScore(int points);
    void Draw();
    int GetScore() const;
};

#endif
