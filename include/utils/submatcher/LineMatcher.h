#include <utility>
#include <vector>

#ifndef SLOTS_INCLUDE_UTILS_SUBMATCHER_LINEMATCHER_H
#define SLOTS_INCLUDE_UTILS_SUBMATCHER_LINEMATCHER_H

namespace slots {

class LineMatcher {
public:
    int width;
    std::vector<int> symbols;
    std::vector<int> patternSlice;

    LineMatcher(const std::vector<int>& symbols_, const std::vector<int>& patternSlice_);
    ~LineMatcher();

    bool isinSymbols(int testSymbol);
    std::pair<int, int> matchLine(const std::vector<int>& line);
};

}

#endif // SLOTS_INCLUDE_UTILS_SUBMATCHER_LINEMATCHER_H