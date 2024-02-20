#pragma once

#include <vector>

class SelectionSort {
    int a = 0;
    int b = a + 1;
    int c = a;
  
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};
