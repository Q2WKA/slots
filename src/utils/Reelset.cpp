#include "utils/Reelset.h"

slots::Reelset::Reelset(
    std::vector<std::vector<int>> rawReels, 
    std::shared_ptr<std::mt19937> rng_
)
{
    reels = rawReels;
    width = rawReels.size();

    for (int i = 0; i < width; ++i) {
        lengths.push_back(rawReels[i].size());
        positions.push_back(0);
        reelRandomizers.emplace_back(UniformRandomGenerator(lengths[i], rng_));
    }
};

slots::Reelset::~Reelset() = default;

void slots::Reelset::randomizePositions() 
{
    for (int i = 0; i < width; ++i)
        positions[i] = reelRandomizers[i].generateValue();
};

void slots::Reelset::shiftPosition(int reelIndex, int shift)
{
    positions[reelIndex] = (positions[reelIndex] - shift) % lengths[reelIndex];
};

int slots::Reelset::getItem(int reelIndex, int shift)
{
    return (positions[reelIndex] + shift) % lengths[reelIndex];
};