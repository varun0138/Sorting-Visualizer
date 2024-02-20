#pragma once

#include <vector>

class InsertionSort {
    int a = 0;
    int b = a;
    
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};

