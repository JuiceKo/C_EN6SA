#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <vector>
#include <ostream>

class SearchingAlgorithm {
protected:
    unsigned int numberComparisons;           

    static unsigned int totalComparisons;
    static unsigned int totalSearches;
    static double       averageComparisons;

public:
    SearchingAlgorithm();

    virtual int search(const std::vector<int>& data, int target) = 0;

    void displaySearchResults(std::ostream& os,
                              int resultIndex,
                              int target);

    static unsigned int getTotalComparisons() { return totalComparisons; }
    static unsigned int getTotalSearches()    { return totalSearches; }
    static double       getAverageComparisons(){ return averageComparisons; }

    virtual ~SearchingAlgorithm() = default;
};

#endif
