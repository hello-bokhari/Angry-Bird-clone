#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Pig.h"
#include "Block.h"
#include "Slingshot.h"

class Level {
public:
    Slingshot slingshot;
    std::vector<Pig> pigs;
    std::vector<Block> blocks;

    Level(const Vector2 &slingshotPos, std::vector<Pig> pigs, std::vector<Block> blocks)
        : slingshot(slingshotPos, 100), pigs(pigs), blocks(blocks) {}

    void Draw() {
        slingshot.Draw();
        for (auto &pig : pigs) pig.Draw();
        for (auto &block : blocks) block.Draw();
    }
};

#endif
