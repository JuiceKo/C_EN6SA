#include "JumpSearch.h"
#include <cmath>

int JumpSearch::search(const std::vector<int>& data, int target)
{
    numberComparisons = 0;

    int n = data.size();
    if (n == 0) return -1;

    int step = std::sqrt(n);
    int prev = 0;

    while (prev < n) {
        ++numberComparisons;
        int idx = std::min(step, n) - 1;

        if (data[idx] >= target)
            break;

        prev = step;
        step += std::sqrt(n);

        if (prev >= n)
            return -1;
    }

    while (prev < std::min(step, n)) {
        ++numberComparisons;
        if (data[prev] == target)
            return prev;

        if (data[prev] > target)
            return -1;

        prev++;
    }
    return -1;
}
