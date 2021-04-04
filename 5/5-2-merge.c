#include "../geek.h"

void merge(int* arr, int first, int mid, int last) {
    int l = first;
    int r = mid + 1;
    int* tmp = (int*) malloc(last * sizeof(int));
    int step = 0;
    while (l <= mid && r <= last) {
        if (arr[l] < arr[r]) {
            tmp[step++] = arr[l++];
        } else {
            tmp[step++] = arr[r++];
        }
    }
    while (r <= last) {
        tmp[step++] = arr[r++];
    }
    while (l <= mid) {
        tmp[step++] = arr[l++];
    }
    for (int k = 0; k < last - first + 1; ++k) {
        arr[first + k] = tmp[k];
    }
}

void mergeSort(int* arr, int first, int last) {
    int split;
    if (first < last) {
        split = (first + last) / 2;
        mergeSort(arr, first, split);
        mergeSort(arr, split + 1, last);
        merge(arr, first, split, last);
    }
}

void mergeTest() {
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    mergeSort(arr, 0, SZ);
    printIntArray(arr, SZ, 3);

}
