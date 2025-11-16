#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "SearchingAlgorithm.h"

class JumpSearch : public SearchingAlgorithm {
public:
    JumpSearch() = default;
    int search(const std::vector<int>& data, int target) override;
};

#endif
