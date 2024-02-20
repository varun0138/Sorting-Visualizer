#include "../include/InsertionSort.hpp"


void InsertionSort::reset() {
    a = 0;
    b = a;
}

std::vector<int> InsertionSort::sort(std::vector<int>& arr) {
    int size = arr.size();
    
    if(a < size - 1 && b == 0) {
        a++;
        b = a;
    }

    if(b > 0 && arr[b] < arr[b-1]) {
        std::swap(arr[b], arr[b-1]);
    }
    b--;

    return {b, b-1};
}