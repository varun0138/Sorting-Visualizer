#include "../include/BrickSort.hpp"

std::vector<int> BrickSort::sort(std::vector<int>& arr) {
    int size = arr.size();

    if(b >= size - 1) {
        a++;
        if(a % 2 == 0) {
            b = 0;
        }
        else {
            b = 1;
        }
    }

    if(a < size) {
        if(a % 2 == 0) {
            if(arr[b] > arr[b+1]) {
                std::swap(arr[b], arr[b+1]);
            }
        }
        else {
            if(arr[b] > arr[b+1]) {
                std::swap(arr[b], arr[b+1]);
            }
        }
        b += 2;
    }
    
    return {b, b+1};
}

void BrickSort::reset() {
    a = 0;
    b = 0;
}








