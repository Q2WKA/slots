#include <utility>
#include <vector>

#include "utils/Glass.h"

namespace nlohmann {
class json;
}

#ifndef SLOTS_INCLUDE_SLOTPARTS_GLASSMATCHER_H
#define SLOTS_INCLUDE_SLOTPARTS_GLASSMATCHER_H

namespace slots {

class GlassMatcher {
public:
    GlassMatcher() = default;
    virtual ~GlassMatcher() = default;
    virtual int calculatePayout() = 0;
};

class LinesGlassMatcher final : virtual public GlassMatcher {
private:
    const int width;
    const int symbolsAmount;
    int *powers;

    int *payouts;
    int *lengths;
    int *combos;

public:
    LinesGlassMatcher(nlohmann::json patterns, nlohmann::json symbols, std::vector<std::vector<int>> lines);
    ~LinesGlassMatcher();

    void initRewards();
    void initRecursion(std::vector<int> currentLine);
    void estimateLine(std::vector<int> finalLine);

    int calculatePayout(const Glass& glass);
};

}

#endif // SLOTS_INCLUDE_SLOTPARTS_GLASSMATCHER_H