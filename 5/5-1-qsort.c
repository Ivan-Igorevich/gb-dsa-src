#include "../geek.h"

void qs(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

void qsL(int* arr, int first, int last) {
    if (first < last) {
        int x = arr[last];
        int i = first;
        int j;
        for (j = first; j <= last - 1; j++) {
            if (arr[j] <= x) {
                swapInt(&arr[i], &arr[j]);
                i++;
            }
        }
        swapInt(&arr[i], &arr[last]);
        qsL(arr, first, i - 1);
        qsL(arr, i + 1, last);
    }
}

void qSortTest() {
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    qsL(arr, 0, SZ - 1);
    printIntArray(arr, SZ, 3);
}