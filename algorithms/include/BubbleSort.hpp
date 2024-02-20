#pragma once

#include <vector>

class BubbleSort {
    int a = 0;
    int b = 1;
    int swaps = 0;
      
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};


