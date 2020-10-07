#include "merge.h"

#include "iostream"

using std::swap;

void merge_sort_rec(int* array, unsigned int left, unsigned int right) {
    if(right <= left) {
        return;
    } else if(right - left == 1) {
        if(array[left] > array[right]) {
            swap(array[left], array[right]);
        }
    } else {
        merge_sort_rec(array, left, left + (right - left) / 2);
        merge_sort_rec(array, left + (right - left) / 2 + 1, right);
    }
}

void merge_sort(int* array, unsigned int length) {
    length--;
    merge_sort_rec(array, 0, length / 2);
    merge_sort_rec(array, length / 2 + 1, length);
}
