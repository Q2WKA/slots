#include "utils/RandomGenerator.h"

slots::IntRandomGenerator::IntRandomGenerator(std::shared_ptr<std::mt19937> rng_) :
    rngSource(rng_)
{};

slots::IntRandomGenerator::~IntRandomGenerator() {};

slots::UniformRandomGenerator::UniformRandomGenerator(
    int maxValue, std::shared_ptr<std::mt19937> rng_
) :
    dist(std::uniform_int_distribution<std::mt19937::result_type>(0, maxValue - 1)),
    IntRandomGenerator(rng_)
{};

slots::UniformRandomGenerator::~UniformRandomGenerator() = default;

int slots::UniformRandomGenerator::generateValue()
{
    return dist(*rngSource);
};

slots::WeightsRandomGenerator::WeightsRandomGenerator(
    const std::vector<int>& weights,
    std::shared_ptr<std::mt19937> rng_
) :
    IntRandomGenerator(rng_)
{
    int currentSum = 0;
    for (int weight : weights) {
        currentSum += weight;
        binBorders.push_back(currentSum);
    }
    dist = std::uniform_int_distribution<std::mt19937::result_type>(0, currentSum - 1);
};

slots::WeightsRandomGenerator::~WeightsRandomGenerator() {};

int slots::WeightsRandomGenerator::generateValue()
{
    int randomSample = dist(*rngSource);
    for (int i = 0; i <= binBorders.size(); ++i) {
        if (randomSample < binBorders[i])
            return i;
    }
    
    return -1;
};