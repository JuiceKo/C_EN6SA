#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int>& data, int target)
{
    numberComparisons = 0;

    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        ++numberComparisons;
        if (data[mid] == target)
            return mid;

        ++numberComparisons;
        if (target < data[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}
