#pragma once

#include <vector>

class CocktailSort {
    int a = 0;
    int b = 0;
    int c = size - 1;

public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
};

