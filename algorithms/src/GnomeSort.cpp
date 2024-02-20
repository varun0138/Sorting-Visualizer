#include "../include/GnomeSort.hpp"

void GnomeSort::reset() {
    a = 0;
}

std::vector<int> GnomeSort::sort(std::vector<int>& arr) {
    int size = arr.size();
    
    if(a == 0) {
        a++;
    }

    if(a < size) {
        if(arr[a] >= arr[a - 1]) {
            a++;
        }
        else {
            std::swap(arr[a], arr[a-1]);
            a--;
        }
    }

    return {a, a-1};
}

    

