#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
public:
    LinearSearch() = default;
    int search(const std::vector<int>& data, int target) override;
};

#endif
