#include "UI.h"
#include <string>

UI::UI() {
    score = 0;
}

void UI::IncreaseScore(int points) {
    score += points;
}

void UI::Draw() {
    DrawText(("Score: " + std::to_string(score)).c_str(), 20, 20, 30, BLACK);
}

int UI::GetScore() const {
    return score;
}
