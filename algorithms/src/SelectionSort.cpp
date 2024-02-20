#include "../include/SelectionSort.hpp"

void SelectionSort::reset() {
    a = 0;
    b = a + 1;
    c = a;
}


std::vector<int> SelectionSort::sort(std::vector<int>& arr) {
    int size = arr.size();

    if(b >= size) {
        if(c != a) {
            std::swap(arr[c], arr[a]);
        }
        a++;
        c = a;
        b = 1 + a;
    }

    if(a < size - 1) {
        if(arr[c] > arr[b]) {
            c = b;
        }
        b++;
    } 

    return {b, c};

}
