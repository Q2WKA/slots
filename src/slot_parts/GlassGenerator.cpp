#include "slot_parts/GlassGenerator.h"

slots::GlassGenerator::GlassGenerator() = default;

slots::GlassGenerator::~GlassGenerator() {};

slots::Glass slots::GlassGenerator::generateGlass() {return slots::Glass(0, 0);};

slots::ReelsGlassGenerator::ReelsGlassGenerator(
    std::vector<std::vector<std::vector<int>>> allRawReels, 
    std::vector<int> reelsetWeights, 
    std::shared_ptr<std::mt19937> rng_,
    int height_ = 3,
    int width_ = 5
) : GlassGenerator(GlassGenerator()), reelsetRandomizer(WeightsRandomGenerator(reelsetWeights, rng_))
{
    height = height_;
    width = width_;
    for (const auto& rawReels: allRawReels) {
        reelsets.emplace_back(Reelset(rawReels, rng_));
    }
};

slots::ReelsGlassGenerator::~ReelsGlassGenerator() = default;

slots::Glass slots::ReelsGlassGenerator::generateGlass() 
{
    slots::Glass resGlass(height, width);
    int currentReelset = reelsetRandomizer.generateValue();
    for (int j = 0; j < width; ++j) {
        reelsets[currentReelset].randomizePositions();
        for (int i = 0; i < height; ++i)
            resGlass.items[i * width + j] = reelsets[currentReelset].getItem(j, i);
    }
    return resGlass;
};