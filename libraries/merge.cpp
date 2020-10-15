#include "merge.h"

#include "iostream"

using std::swap;

void merge_sort_rec(int *array, unsigned int left, unsigned int right) {
    if (right <= left) {
        return;
    } else if (right - left == 1) {
        if (array[left] > array[right]) {
            swap(array[left], array[right]);
        }
    } else {
        unsigned int middle = left + (right - left) / 2;
        merge_sort_rec(array, left, middle);
        merge_sort_rec(array, middle + 1, right);

        int *buffer = new int[right - left + 1];
        for (unsigned int i = left; i <= right; ++i) {
            buffer[i - left] = array[i];
        }

        unsigned int i1 = 0, i2 = middle - left + 1, i = left;

        while (i1 < middle - left + 1 && i2 < right - left + 1) {
            if (buffer[i1] < buffer[i2]) {
                array[i++] = buffer[i1++];
            } else {
                array[i++] = buffer[i2++];
            }
        }

        for (unsigned int j = i1; j < middle - left + 1; ++j) {
            array[i++] = buffer[i1++];
        }

        for (unsigned int j = i2; j < right - left + 1; ++j) {
            array[i++] = buffer[i2++];
        }
    }
}

void merge_sort(int *array, unsigned int length) {
    merge_sort_rec(array, 0, --length);
}
