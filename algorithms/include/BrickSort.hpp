#pragma once

#include <vector>

class BrickSort {
    int a = 0;
    int b = 0;
    
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};
