#include "LinearSearch.h"

int LinearSearch::search(const std::vector<int>& data, int target)
{
    numberComparisons = 0;

    for (size_t i = 0; i < data.size(); ++i) {
        ++numberComparisons;
        if (data[i] == target)
            return i;
    }
    return -1;
}
