#include "utils/Reelset.h"
#include "utils/Glass.h"

#ifndef SLOTS_INCLUDE_SLOTPARTS_GLASSGENERATOR_H
#define SLOTS_INCLUDE_SLOTPARTS_GLASSGENERATOR_H

namespace slots {

class GlassGenerator {
public:
    GlassGenerator();
    virtual ~GlassGenerator();
    virtual Glass generateGlass();
};

class ReelsGlassGenerator final : virtual public GlassGenerator {
private:
    int height, width;
    std::vector<Reelset> reelsets;
    WeightsRandomGenerator reelsetRandomizer;

public:
    ReelsGlassGenerator(
        std::vector<std::vector<std::vector<int>>> allRawReels, 
        std::vector<int> reelsetWeights_, 
        std::shared_ptr<std::mt19937> rng_,
        int height_,
        int width_
    );
    ~ReelsGlassGenerator() final;
    Glass generateGlass() final;
};

}

#endif // SLOTS_INCLUDE_SLOTPARTS_GLASSGENERATOR_H