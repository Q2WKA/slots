#include <iostream>
#include <algorithm>

#include "utils/Glass.h"

slots::Glass::Glass(int height_, int width_) :
    height(height_), width(width_), items(new int[width * height])
{};

slots::Glass::Glass(slots::Glass&& other) 
    : height(other.height), width(other.width), items(nullptr)
{
    std::swap(items, other.items);
};

slots::Glass::~Glass()
{
    if (items) {
        delete[] items;
        items = nullptr;
    }
};

void slots::Glass::print()
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            std::cout << items[i * width + j] << " ";
        std::cout << std::endl;
    }
};