#include "Bird.h"
#include "raylib.h"
#include <vector>

class RedBird : public Bird {
public:
    RedBird(Vector2 pos) : Bird(pos) {}
    void ActivateAbility() override {} // No special ability
};

class BlueBird : public Bird {
public:
    BlueBird(Vector2 pos) : Bird(pos) {}
    void ActivateAbility() override {
        // Splitting mechanic (spawn 2 extra birds)
    }
};

class YellowBird : public Bird {
public:
    YellowBird(Vector2 pos) : Bird(pos) {}
    void ActivateAbility() override {
        velocity.x *= 1.5f; // Speed boost
    }
};

class BlackBird : public Bird {
public:
    BlackBird(Vector2 pos) : Bird(pos) {}
    void ActivateAbility() override {
        // Explosion mechanic
    }
};

class WhiteBird : public Bird {
public:
    WhiteBird(Vector2 pos) : Bird(pos) {}
    void ActivateAbility() override {
        // Drop an explosive egg
    }
};

class Game {
private:
    std::vector<Bird*> birds;
    int currentBirdIndex;
public:
    void LoadLevel(int levelNumber) {
        birds.clear();
        if (levelNumber == 1) {
            birds.push_back(new RedBird({100, 500}));
            birds.push_back(new BlueBird({150, 500}));
        } else if (levelNumber == 2) {
            birds.push_back(new YellowBird({100, 500}));
            birds.push_back(new BlackBird({150, 500}));
        }
        currentBirdIndex = 0;
    }
    void Update() {
        if (birds[currentBirdIndex] && IsKeyPressed(KEY_SPACE)) {
            birds[currentBirdIndex]->ActivateAbility();
        }
    }
};

