#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm {
public:
    BinarySearch() = default;
    int search(const std::vector<int>& data, int target) override;
};

#endif
