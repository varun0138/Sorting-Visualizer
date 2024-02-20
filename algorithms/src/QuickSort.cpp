#include <vector>
#include <utility>
#include "../include/QuickSort.hpp"

void QuickSort::reset() {
    swaps = 0;
    sortRange.clear();

    pivot = -1;
    pIndex = -1;
    rIndex = -1;
    start = -1;
    end = -1;
}

std::vector<int> QuickSort::sort(std::vector<int>& arr) {

    if(pivot == -1 && pIndex == -1) {
        quicksort(arr, 0, arr.size()-1);
        rIndex = 0;
        start = sortRange[rIndex].first;
        end = sortRange[rIndex].second;
        pivot = arr[end];
        pIndex = start;
    }
    
    if(rIndex < (int)sortRange.size()) {

        if(start >= end) {
            std::swap(arr[pIndex], arr[end]);
            rIndex++;
            start = sortRange[rIndex].first;
            end = sortRange[rIndex].second;
            pivot = arr[end];
            pIndex = start;
        }

        if(arr[start] <= pivot) {
            std::swap(arr[start], arr[pIndex]);
            pIndex++;
            swaps++;
        }

        start++;
    }
    
    return {start, pIndex};
}

int QuickSort::getSwaps() {
    return swaps;
}


int QuickSort::partition(std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];
	int pIndex = start;
	for(int i = start; i < end; i++) {
		if(arr[i] <= pivot) {
			std::swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	std::swap(arr[pIndex], arr[end]);
	return pIndex;
}

void QuickSort::quicksort(std::vector<int> arr, int start, int end) {

    if(start >= end) return;

	sortRange.push_back({start, end});

    int part = partition(arr, start, end);
    quicksort(arr, start, part-1);
    quicksort(arr, part+1, end);
	
}
