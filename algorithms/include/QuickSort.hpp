#pragma once

#include <vector>
#include <utility>

class QuickSort {
    int swaps = 0;
    std::vector<std::pair<int, int>> sortRange;

    int pivot = -1;
    int pIndex = -1;
    int rIndex = -1;
    int start = -1;
    int end = -1;

      
public:
    void reset();
    std::vector<int> sort(std::vector<int>& arr);
    int getSwaps();
    int partition(std::vector<int>& arr, int start, int end);
    void quicksort(std::vector<int> arr, int start, int end);
};

