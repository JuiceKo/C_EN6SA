#include <iostream>
#include <vector>

#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main()
{
    std::vector<int> data = {1, 3, 5, 7, 9, 11, 13, 15};

    int target1 = 7;
    int target2 = 4;

    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;

    int res;

    // Linear
    res = linear.search(data, target1);
    linear.displaySearchResults(std::cout, res, target1);

    res = linear.search(data, target2);
    linear.displaySearchResults(std::cout, res, target2);

    // Jump
    res = jump.search(data, target1);
    jump.displaySearchResults(std::cout, res, target1);

    res = jump.search(data, target2);
    jump.displaySearchResults(std::cout, res, target2);

    // Binary
    res = binary.search(data, target1);
    binary.displaySearchResults(std::cout, res, target1);

    res = binary.search(data, target2);
    binary.displaySearchResults(std::cout, res, target2);

    return 0;
}
    