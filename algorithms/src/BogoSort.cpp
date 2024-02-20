#include "../include/BogoSort.hpp"

static Random random;


void BogoSort::reset() {
    a = 0;
    b = 0;
    swaps = 0;
}


std::vector<int> BogoSort::sort(std::vector<int>& arr) {
    int size = arr.size();

    bool isSorted = std::is_sorted(arr.begin(), arr.end());

    if(!isSorted) {
        std::swap(arr[a], arr[b]);
        swaps++;
    }

    a = random.randint(0, size);
    b = random.randint(0, size);

    return {a, b};

}

int BogoSort::getSwaps() {
    return swaps;
}

