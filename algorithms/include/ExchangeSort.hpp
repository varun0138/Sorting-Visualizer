#pragma once

#include <vector>

class ExchangeSort {
    int a = 0;
    int b = a+1;
    
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};
