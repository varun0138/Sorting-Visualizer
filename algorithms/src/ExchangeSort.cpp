#include "../include/ExchangeSort.hpp"


void ExchangeSort::reset() {
    a = 0;
    b = a+1;
}


std::vector<int> ExchangeSort::sort(std::vector<int>& arr) {
    int size = arr.size();

    if(b >= size) {
        a++;
        b = a+1;
    }

    if(a < size - 1) {
        if(arr[a] > arr[b]) {
            std::swap(arr[a], arr[b]);
        }
        b++;
    }

    return {a, b};
}
