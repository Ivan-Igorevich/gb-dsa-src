#include "../geek.h"

void sortShells(int* arr, int len) {
    int i;
    int j;
    int step;
    int temp;

    for (step = len / 2; step > 0; step /= 2) {
        for (i = step; i < len; ++i) {
            temp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (temp <arr[j - step]) {
                    arr[j] = arr[j - step];
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

void shellTest() {
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    sortShells(arr, SZ);
    printIntArray(arr, SZ, 3);
}
