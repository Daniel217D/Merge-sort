#include <iostream>
#include <ctime>

#include "libraries/merge.h"

using std::cout;

int main() {
    srand(time(0));

    unsigned int length = 10;
    int* array = new int[length];
    for (unsigned int i = 0; i < length; ++i) {
        array[i] = rand() % 50;
        cout << array[i] << " ";
    }
    cout << "\n";

    merge_sort(array, length);

    for (unsigned int i = 0; i < length; ++i) {
        cout << array[i] << " ";
    }

    delete[] array;
    return 0;
}
