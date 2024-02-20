#include "../include/CycleSort.hpp"


void CycleSort::reset() {
    a = 0;
    b = a;
    c = a + 1;
    swaps = 0;
}

std::vector<int> CycleSort::sort(std::vector<int>& arr) {

    int size = arr.size();

    if(a < size) {
        
        if(c < size) {
            
            if(arr[c] < arr[a]) {
                b++;
            }
            c++;
        }
        else {
            if(a == b) {
                a++;
                b = a;
            }

            while(arr[a] == arr[b]) {
                b++;
            }

            std::swap(arr[a], arr[b]);
            b = a;
            c = a + 1;
        }

    }
    return {a, b};
}