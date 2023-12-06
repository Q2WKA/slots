#include "utils/submatcher/LineMatcher.h"

slots::LineMatcher::LineMatcher(
    const std::vector<int>& symbols_, 
    const std::vector<int>& patternSlice_
) : symbols(symbols_), patternSlice(patternSlice_), width(patternSlice_.size())
{};

slots::LineMatcher::~LineMatcher() = default;

bool slots::LineMatcher::isinSymbols(int testSymbol)
{
    for (int symbol: symbols)
        if (testSymbol == symbol)
            return true;
    return false;
};

std::pair<int, int> slots::LineMatcher::matchLine(const std::vector<int>& line)
{
    int matchedLength = 0;
    for (int lineSymbol: line)
        if (isinSymbols(lineSymbol))
            matchedLength++;
    return std::pair<int, int>(matchedLength, patternSlice[matchedLength - 1]);
};