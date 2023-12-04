#include <iostream>
#include <chrono>

#include "slot_parts/GlassGenerator.h"

int main() {
    std::random_device dev;
    std::shared_ptr<std::mt19937> rng = std::make_shared<std::mt19937>(dev());

    std::vector<std::vector<std::vector<int>>> allRawReels {
        {
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 }
        },
        {
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 2, 3, 4, 5, 6, 7, 8 }
        }
    };

    slots::ReelsGlassGenerator gg(allRawReels, std::vector<int>{3, 5}, rng, 3, 5);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000000; ++i) {
        gg.generateGlass();
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;



    return 0;
};