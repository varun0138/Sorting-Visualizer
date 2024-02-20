#pragma once

#include <vector>

class GnomeSort {
    int a = 0;
    
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};
