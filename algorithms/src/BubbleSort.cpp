#include <vector>
#include "../include/BubbleSort.hpp"

int BubbleSort::getSwaps() {
    return swaps;
}

std::vector<int> BubbleSort::sort(std::vector<int>& arr) {
    int size = arr.size();

    if(a < size) {
        if(b >= size - a) {
            a++;
            b = 1;
        }

        if(arr[b]< arr[b-1]) {
            std::swap(arr[b], arr[b-1]);
            swaps++;
        }
        b++;
    }

    return {b, b-1};
}


void BubbleSort::reset() {
    a = 0;
    b = 1;
    swaps = 0;
}

