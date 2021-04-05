#include "../geek.h"

void buildTree(int* arr, int new, int size) {
    int maxIdx = new;
    int newElem = arr[new];

    while (true) {
        int child = new * 2 + 1; //left child
        if ((child < size) && (arr[child] > newElem)) {
            maxIdx = child;
        }
        child = new * 2 + 2; //right child
        if ((child < size) && (arr[child] > arr[maxIdx])) {
            maxIdx = child;
        }
        if (maxIdx == new)
            break;
        arr[new] = arr[maxIdx];
        arr[maxIdx] = newElem;
        new = maxIdx;
    }
}

void heapSort(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        buildTree(arr, i, size);
    }
    while (size > 1) {
        --size;
        int firstElem = arr[0];
        arr[0] = arr[size];
        arr[size] = firstElem;
        buildTree(arr, 0, size);
    }
}

void heapsortTest() {
    const int SZ = 10;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    heapSort(arr, SZ);
    printIntArray(arr, SZ, 3);
}
