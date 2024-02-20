#pragma once

#include <vector>
#include <algorithm>
#include "../maths/Random.hpp"

class BogoSort {
    int a = 0;
    int b = 0;
    int swaps = 0;
    
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};

