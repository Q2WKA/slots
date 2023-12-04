#include <random>
#include <memory>
#include <vector>

#ifndef SLOTS_INCLUDE_UTILS_RANDOMGENERATOR_H
#define SLOTS_INCLUDE_UTILS_RANDOMGENERATOR_H

namespace slots {

class IntRandomGenerator {
public:
    std::shared_ptr<std::mt19937> rngSource;

    IntRandomGenerator(std::shared_ptr<std::mt19937> rng_);
    virtual ~IntRandomGenerator();
    virtual int generateValue() = 0;
};

class UniformRandomGenerator final : virtual public IntRandomGenerator {
public:
    std::uniform_int_distribution<std::mt19937::result_type> dist;

    UniformRandomGenerator(int maxValue, std::shared_ptr<std::mt19937> rng_);
    ~UniformRandomGenerator();
    int generateValue() final;
};

class WeightsRandomGenerator final : virtual public IntRandomGenerator {
public:
    std::vector<int> binBorders;
    std::uniform_int_distribution<std::mt19937::result_type> dist;

    WeightsRandomGenerator(const std::vector<int>& weights, std::shared_ptr<std::mt19937> rng_);
    ~WeightsRandomGenerator() final;
    int generateValue() final;
};

}

#endif // SLOTS_INCLUDE_UTILS_RANDOMGENERATOR_H