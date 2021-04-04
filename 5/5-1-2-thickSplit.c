#include "../geek.h"

void thickSplit(int* arr, int l, int r) {
    int x = arr[r];
    if (r <= l) return;

    int i = l;
    int j = r - 1;
    int p = l - 1;
    int q = r;

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i >= j) break;
        swapInt(&arr[i], &arr[j]);

        if (arr[i] == x) {
            p++;
            swapInt(&arr[p], &arr[i]);
            i++;
        }
        if (arr[j] == x) {
            swapInt(&arr[--q], &arr[j--]);
        }
    }
    swapInt(&arr[i], &arr[r]);
    j = i - 1;
    i++;

    for (int k = l; k <= p; ++k, --j) {
        swapInt(&arr[k], &arr[j]);
    }
    for (int k = r - 1; k >= q; --k, ++i) {
        swapInt(&arr[k], &arr[i]);
    }
    thickSplit(arr, l, j);
    thickSplit(arr, i, r);
}


void thickTest() {
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    thickSplit(arr, 0, SZ - 1);
    printIntArray(arr, SZ, 3);
}
