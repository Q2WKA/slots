#include <vector>
#include <memory>

#include "RandomGenerator.h"

#ifndef SLOTS_INCLUDE_UTILS_REELSET_H
#define SLOTS_INCLUDE_UTILS_REELSET_H

namespace slots {

class Reelset {
private:
    int width;
    std::vector<int> lengths;
    std::vector<int> positions;
    std::vector<std::vector<int>> reels;
    std::vector<slots::UniformRandomGenerator> reelRandomizers;

public:
    Reelset(std::vector<std::vector<int>> rawReels, std::shared_ptr<std::mt19937> rng_);
    ~Reelset();

    void randomizePositions();
    void shiftPosition(int reelIndex, int shift);
    int getItem(int reelIndex, int shift);
};

}

#endif // SLOTS_INCLUDE_UTILS_REELSET_H