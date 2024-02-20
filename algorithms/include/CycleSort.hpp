#pragma once

#include <vector>

class CycleSort {
    int a = 0;
    int b = a;
    int c = a + 1;
    int swaps = 0;
      
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};
